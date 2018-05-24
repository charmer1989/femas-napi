const _ = require('lodash');
const fs = require('fs');

let str = `	virtual void SubscribeMarketDataTopic(int nTopicID, USTP_TE_RESUME_TYPE nResumeType) = 0;

	///订阅合约行情。
	///@param ppInstrumentID 合约ID  
	///@param nCount 要订阅/退订行情的合约个数
	///@remark 
	virtual int SubMarketData(char *ppInstrumentID[], int nCount)=0;

	///退订合约行情。
	///@param ppInstrumentID 合约ID  
	///@param nCount 要订阅/退订行情的合约个数
	///@remark 
	virtual int UnSubMarketData(char *ppInstrumentID[], int nCount)=0;

	///获取行情订阅号。
	///@param *ppExchangeID 合约ID  
	///@param nCount 要获取行情订阅号的交易所个数
	///@remark 
	virtual int GetMarketTopic(char *pExchangeID)=0;
		
	
	///设置心跳超时时间。
	///@param timeout 心跳超时时间(秒)  
	virtual void SetHeartbeatTimeout(unsigned int timeout) = 0;


	///风控前置系统用户登录请求
	virtual int ReqUserLogin(CUstpFtdcReqUserLoginField *pReqUserLogin, int nRequestID) = 0;

	///用户退出请求
	virtual int ReqUserLogout(CUstpFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///订阅主题请求
	virtual int ReqSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///主题查询请求
	virtual int ReqQryTopic(CUstpFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///订阅合约的相关信息
	virtual int ReqSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;

	///退订合约的相关信息
	virtual int ReqUnSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, int nRequestID) = 0;
  `;

let STRUCT = require('./femas-struct.json');
let DATA_TYPE = require('./femas-data-type.json');

let getParamsStr = (paramType) => {
  return STRUCT[paramType].map((field) => {
    if (DATA_TYPE[field.fieldType] === 'int' || DATA_TYPE[field.fieldType] === 'double') {
      return `  req.${field.fieldName} = getNumber(params, "${field.fieldName}");`;
    } else if (DATA_TYPE[field.fieldType]) {
      return `  strcpy(req.${field.fieldName}, getString(params, "${field.fieldName}").c_str());`;
    } else {
      return `  req.${field.fieldName} = getChar(params, "${field.fieldName}");`;
    }
  }).join("\n");
};

str.split("\n").forEach((line) => {
  let arr = line.match(/\s*virtual (int|void) ([a-zA-Z]*)\(([^\(\)]*)\)\s\=\s0;/);
  if (!arr) {
    return;
  }
  // console.log('[DEBUG]', arr);
  let funcName = arr[2];
  let paramStr = arr[3];
  let params = paramStr.split(",");
  let paramType;
  params.forEach(p => {
    if (p.match(/CUstpFtdc/)) {
      paramType = p.split(/\s/)[0];
    }
  });
  if (!paramType) {
    let res = `else if (funcName == "${_.camelCase(funcName)}") {
    MD_DEBUG_LOG("call function ${_.camelCase(funcName)}");
    ReqID++;
    int ret = this->api->${funcName}();
    return ret;
  }`;
    // console.log('[DEBUG]', res);
    fs.appendFileSync("./tmp-call.txt", res);
    return;
  }
  let res = `else if (funcName == "${_.camelCase(funcName)}") {
    MD_DEBUG_LOG("call function ${_.camelCase(funcName)}");
    ReqID++;
    ${paramType} req;
    memset(&req, 0, sizeof(${paramType}));
${getParamsStr(paramType)}
    int ret = this->api->${funcName}(&req, ReqID);
    return ret;
  }`;
    fs.appendFileSync("./tmp-call.txt", res);
  // console.log('[DEBUG]', res);
});