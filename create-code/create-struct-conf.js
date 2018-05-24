const fs = require('fs');
const path = require('path');
const _ = require('lodash');

let str = `
  virtual void SubscribePrivateTopic(USTP_TE_RESUME_TYPE nResumeType) = 0;
	
	///订阅公共流。
	///@param nResumeType 公共流重传方式  
	///        USTP_TERT_RESTART:从本交易日开始重传
	///        USTP_TERT_RESUME:从上次收到的续传
	///        USTP_TERT_QUICK:只传送登录后公共流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
	virtual void SubscribePublicTopic(USTP_TE_RESUME_TYPE nResumeType) = 0;

	///订阅交易员流。
	///@param nResumeType 交易员流重传方式  
	///        USTP_TERT_RESTART:从本交易日开始重传
	///        USTP_TERT_RESUME:从上次收到的续传
	///        USTP_TERT_QUICK:只传送登录后交易员流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到交易员流的数据。
	virtual void SubscribeUserTopic(USTP_TE_RESUME_TYPE nResumeType) = 0;

	///订阅询价流。
	///@param nResumeType 交易员流重传方式  
	///        USTP_TERT_RESTART:从本交易日开始重传
	///        USTP_TERT_RESUME:从上次收到的续传
	///        USTP_TERT_QUICK:只传送登录后交易员流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到交易员流的数据。
	virtual void SubscribeForQuote(USTP_TE_RESUME_TYPE nResumeType) = 0;
	
	///设置心跳超时时间。
	///@param timeout 心跳超时时间(秒)  
	virtual void SetHeartbeatTimeout(unsigned int timeout) = 0;
	
	///打开请求日志文件
	///@param pszReqLogFileName 请求日志文件名  
	///@return 0 操作成功
	///@return -1 打开日志文件失败
	virtual int OpenRequestLog(const char *pszReqLogFileName) = 0;

	///打开应答日志文件
	///@param pszRspLogFileName 应答日志文件名  
	///@return 0 操作成功
	///@return -1 打开日志文件失败
	virtual int OpenResponseLog(const char *pszRspLogFileName) = 0;


	///风控前置系统用户登录请求
	virtual int ReqUserLogin(CUstpFtdcReqUserLoginField *pReqUserLogin, int nRequestID) = 0;

	///用户退出请求
	virtual int ReqUserLogout(CUstpFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///用户密码修改请求
	virtual int ReqUserPasswordUpdate(CUstpFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///请求对账单确认
	virtual int ReqSettlementInfoConfirm(CUstpFtdcInputSettlementInfoConfirmField *pInputSettlementInfoConfirm, int nRequestID) = 0;

	///请求查询对账单确认
	virtual int ReqQrySettlementInfoConfirm(CUstpFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID) = 0;

	///报单录入请求
	virtual int ReqOrderInsert(CUstpFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///报单操作请求
	virtual int ReqOrderAction(CUstpFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///请求报价录入
	virtual int ReqQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, int nRequestID) = 0;

	///报价操作请求
	virtual int ReqQuoteAction(CUstpFtdcQuoteActionField *pQuoteAction, int nRequestID) = 0;

	///客户询价请求
	virtual int ReqForQuote(CUstpFtdcReqForQuoteField *pReqForQuote, int nRequestID) = 0;

	///客户申请组合请求
	virtual int ReqMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction, int nRequestID) = 0;

	///用户请求出入金
	virtual int ReqUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit, int nRequestID) = 0;

	///用户主次席出入金
	virtual int ReqTransferMoney(CUstpFtdcstpTransferMoneyField *pstpTransferMoney, int nRequestID) = 0;

	///报单查询请求
	virtual int ReqQryOrder(CUstpFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///成交单查询请求
	virtual int ReqQryTrade(CUstpFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///可用投资者账户查询请求
	virtual int ReqQryUserInvestor(CUstpFtdcQryUserInvestorField *pQryUserInvestor, int nRequestID) = 0;

	///交易编码查询请求
	virtual int ReqQryTradingCode(CUstpFtdcQryTradingCodeField *pQryTradingCode, int nRequestID) = 0;

	///投资者资金账户查询请求
	virtual int ReqQryInvestorAccount(CUstpFtdcQryInvestorAccountField *pQryInvestorAccount, int nRequestID) = 0;

	///合约查询请求
	virtual int ReqQryInstrument(CUstpFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///交易所查询请求
	virtual int ReqQryExchange(CUstpFtdcQryExchangeField *pQryExchange, int nRequestID) = 0;

	///投资者持仓查询请求
	virtual int ReqQryInvestorPosition(CUstpFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///订阅主题请求
	virtual int ReqSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///合规参数查询请求
	virtual int ReqQryComplianceParam(CUstpFtdcQryComplianceParamField *pQryComplianceParam, int nRequestID) = 0;

	///主题查询请求
	virtual int ReqQryTopic(CUstpFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///投资者手续费率查询请求
	virtual int ReqQryInvestorFee(CUstpFtdcQryInvestorFeeField *pQryInvestorFee, int nRequestID) = 0;

	///投资者保证金率查询请求
	virtual int ReqQryInvestorMargin(CUstpFtdcQryInvestorMarginField *pQryInvestorMargin, int nRequestID) = 0;

	///交易编码组合持仓查询请求
	virtual int ReqQryInvestorCombPosition(CUstpFtdcQryInvestorCombPositionField *pQryInvestorCombPosition, int nRequestID) = 0;

	///交易编码单腿持仓查询请求
	virtual int ReqQryInvestorLegPosition(CUstpFtdcQryInvestorLegPositionField *pQryInvestorLegPosition, int nRequestID) = 0;

	///查询合约组信息
	virtual int ReqQryInstrumentGroup(CUstpFtdcQryUstpInstrumentGroupField *pQryUstpInstrumentGroup, int nRequestID) = 0;

	///查询组合保证金类型
	virtual int ReqQryClientMarginCombType(CUstpFtdcQryClientMarginCombTypeField *pQryClientMarginCombType, int nRequestID) = 0;

	///查询系统时间
	virtual int ReqQrySystemTime(CUstpFtdcReqQrySystemTimeField *pReqQrySystemTime, int nRequestID) = 0;

	///请求查询保证金监管系统经纪公司资金账户密钥
	virtual int ReqCFMMCTradingAccountKey(CUstpFtdcCFMMCTradingAccountKeyReqField *pCFMMCTradingAccountKeyReq, int nRequestID) = 0;

	///请求查询投资者结算结果
	virtual int ReqQrySettlementInfo(CUstpFtdcSettlementQryReqField *pSettlementQryReq, int nRequestID) = 0;

	///资金账户口令更新请求
	virtual int ReqTradingAccountPasswordUpdate(CUstpFtdcTradingAccountPasswordUpdateReqField *pTradingAccountPasswordUpdateReq, int nRequestID) = 0;

	///请求查询转帐银行
	virtual int ReqQryTransferBank(CUstpFtdcTransferBankQryReqField *pTransferBankQryReq, int nRequestID) = 0;

	///请求查询仓单折抵信息
	virtual int ReqQryEWarrantOffset(CUstpFtdcEWarrantOffsetFieldReqField *pEWarrantOffsetFieldReq, int nRequestID) = 0;

	///请求查询转帐流水
	virtual int ReqQryTransferSeria(CUstpFtdcTransferSerialFieldReqField *pTransferSerialFieldReq, int nRequestID) = 0;

	///请求查询银期签约关系
	virtual int ReqQryAccountregister(CUstpFtdcAccountregisterReqField *pAccountregisterReq, int nRequestID) = 0;

	///请求查询签约银行
	virtual int ReqQryContractBank(CUstpFtdcContractBankFieldReqField *pContractBankFieldReq, int nRequestID) = 0;

	///期货发起银行资金转期货请求
	virtual int ReqFromBankToFutureByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, int nRequestID) = 0;

	///期货发起期货资金转银行请求
	virtual int ReqFromFutureToBankByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, int nRequestID) = 0;

	///期货发起查询银行余额请求
	virtual int ReqQueryBankAccountMoneyByFuture(CUstpFtdcAccountFieldReqField *pAccountFieldReq, int nRequestID) = 0;`;

/*// 制作 femas-struct.json
let dataStruct = fs.readFileSync(path.join(__dirname, '../tradeapi/USTPFtdcUserApiStruct.h')).toString();
let structReg = /struct\s([a-zA-Z]*)\s*\n\{([^\}]*)\};/g;
let arr = dataStruct.match(structReg);
console.log('[DEBUG]', arr[107]);
let structObj = {};
arr.forEach((s) => {
  let a = s.match(/struct\s([a-zA-Z]*)\s*\n\{([^\}]*)\};/);
  if (!a) return;
  let structName = a[1];
  let structFields = [];
  a[2].split("\n").forEach((one) => {
    let oneArr = one.match(/([a-zA-Z]*)\s*([a-zA-Z]*);/);
    if (oneArr && oneArr.length) {
      structFields.push({ fieldType: oneArr[1], fieldName: oneArr[2] });
    }
  });
  structObj[structName] = structFields;
});
console.log('[DEBUG]', structObj);
fs.writeFileSync("./femas-struct.json", JSON.stringify(structObj));
*/

/* // 制作 femas-data-type.json
  let dataTypeStr = `typedef double TUstpFtdcPriceTickType;

typedef double TUstpFtdcPriceType;

typedef double TUstpFtdcRatioType;

typedef double TUstpFtdcMoneyType;

typedef double TUstpFtdcLargeVolumeType;

typedef int TUstpFtdcDataCenterIDType;

typedef int TUstpFtdcSequenceNoType;

typedef int TUstpFtdcMillisecType;

typedef int TUstpFtdcVolumeType;

typedef int TUstpFtdcUnderlyingMultipleType;

typedef int TUstpFtdcVolumeMultipleType;

typedef int TUstpFtdcSequenceSeriesType;

typedef int TUstpFtdcSessionIDType;

typedef int TUstpFtdcErrorIDType;

typedef int TUstpFtdcDataCenterIDType;

typedef int TUstpFtdcSettlementIDType;

typedef int TUstpFtdcBusinessLocalIDType;

typedef int TUstpFtdcMeasureSecType;

typedef int TUstpFtdcSeatNoType;

typedef int TUstpFtdcFileSizeType;

typedef int TUstpFtdcSequenceNoTypeType;

typedef int TUstpFtdcPlateSerialType;

typedef int TUstpFtdcFutureSerialType;

typedef int TUstpFtdcTIDType;

typedef int TUstpFtdcInstallIDType;

typedef int TUstpFtdcRequestIDType;

typedef int TUstpFtdcRepealTimeIntervalType;

typedef int TUstpFtdcRepealedTimesType;

typedef int TUstpFtdcFemasLifeCycleType;

typedef int TUstpFtdcMonthType;

typedef int TUstpFtdcBoolType;

typedef int TUstpFtdcYearType;

typedef int TUstpFtdcPriorityType;

typedef char TUstpFtdcMemTableNameType[61];

typedef char TUstpFtdcOrderSysIDType[31];

typedef char TUstpFtdcTradeIDType[21];

typedef char TUstpFtdcUserIDType[16];

typedef char TUstpFtdcParticipantIDType[11];

typedef char TUstpFtdcIPAddressType[21];

typedef char TUstpFtdcMacAddressType[21];

typedef char TUstpFtdcInstrumentNameType[21];

typedef char TUstpFtdcInstrumentIDType[31];

typedef char TUstpFtdcIdentifiedCardNoType[51];

typedef char TUstpFtdcExchangeNameType[31];

typedef char TUstpFtdcExchangeIDType[11];

typedef char TUstpFtdcDateType[9];

typedef char TUstpFtdcTimeType[9];

typedef char TUstpFtdcClientIDType[19];

typedef char TUstpFtdcAccountIDType[13];

typedef char TUstpFtdcSeatIDType[13];

typedef char TUstpFtdcProductNameType[41];

typedef char TUstpFtdcUserOrderLocalIDType[21];

typedef char TUstpFtdcOrderLocalIDType[13];

typedef char TUstpFtdcInvestorIDType[19];

typedef char TUstpFtdcUserNameType[31];

typedef char TUstpFtdcPasswordType[41];

typedef char TUstpFtdcProductInfoType[41];

typedef char TUstpFtdcProtocolInfoType[41];

typedef char TUstpFtdcBusinessUnitType[21];

typedef char TUstpFtdcTradingSystemNameType[61];

typedef char TUstpFtdcBrokerIDType[11];

typedef char TUstpFtdcCustomType[65];

typedef char TUstpFtdcTradingDayType[9];

typedef char TUstpFtdcDepartmentType[41];

typedef char TUstpFtdcProductIDType[13];

typedef char TUstpFtdcAccountSeqNoType[21];

typedef char TUstpFtdcSettlementGroupIDType[9];

typedef char TUstpFtdcFemasVersionType[21];

typedef char TUstpFtdcBankIDType[11];

typedef char TUstpFtdcBankPasswdType[36];

typedef char TUstpFtdcAccountPasswdType[36];

typedef char TUstpFtdcRiskIDType[16];

typedef char TUstpFtdcRiskWarningNoType[16];

typedef char TUstpFtdcRiskWarningAbstractType[101];

typedef char TUstpFtdcRiskWarningContentType[501];

typedef char TUstpFtdcLogStrType[501];

typedef char TUstpFtdcCFMMCKeyType[22];

typedef char TUstpFtdcBankNameType[102];

typedef char TUstpFtdcBankSerialType[14];

typedef char TUstpFtdcTradeCodeType[8];

typedef char TUstpFtdcBankAccountType[42];

typedef char TUstpFtdcFutureBranchIDType[32];

typedef char TUstpFtdcOperatorCodeType[18];

typedef char TUstpFtdcIndividualNameType[52];

typedef char TUstpFtdcMessageType[129];

typedef char TUstpFtdcDeviceIdType[4];

typedef char TUstpFtdcBankCodingForFutureType[34];

typedef char TUstpFtdcOperNoType[18];

typedef char TUstpFtdcCountryCodeType[22];

typedef char TUstpFtdcAddressType[102];

typedef char TUstpFtdcZipCodeType[102];

typedef char TUstpFtdcTelephoneType[42];

typedef char TUstpFtdcFaxType[42];

typedef char TUstpFtdcMobilePhoneType[42];

typedef char TUstpFtdcEMailType[42];

typedef char TUstpFtdcErrorMsgType[81];
typedef char TUstpFtdcInstrumentGroupIDType[31];

typedef char TUstpFtdcQuoteSysIDType[31];

typedef char TUstpFtdcUserQuoteLocalIDType[21];

typedef char TUstpFtdcQuoteLocalIDType[13];
typedef char TUstpFtdcInstrumentGroupIDType[31];
typedef char TUstpFtdcCurrencyIDType[5];`

  let dataType = {};
  dataTypeStr.split('\n').forEach((line) => {
    if (line.match(/typedef\s([a-z]*)\s([a-zA-Z]*)/)) {
      let arr = line.match(/typedef\s([a-z]*)\s([a-zA-Z]*)/);
      dataType[arr[2]] = arr[1];
    }
  });

  console.log('[DEBUG]', dataType);
  fs.writeFileSync("./femas-data-type.json", JSON.stringify(dataType));
*/

//最终输出
let STRUCT = require('./femas-struct.json');
let DATA_TYPE = require('./femas-data-type.json');
let n = 0;

let getParamsStr = (paramsType) => {
  return STRUCT[paramsType].map((field) => {
    if (DATA_TYPE[field.fieldType] === 'int' || DATA_TYPE[field.fieldType] === 'double') {
      return `  req.${field.fieldName} = getNumber(env, params, "${field.fieldName}");`;
    } else if (DATA_TYPE[field.fieldType]) {
      return `  strcpy(req.${field.fieldName}, getChar(env, params, "${field.fieldName}"));`;
    } else {
      return `  req.${field.fieldName} = getCharOne(env, params, "${field.fieldName}");`;
    }
  }).join("\n");
};

str.split("\n").forEach((line) => {
  let arr = line.match(/virtual\s([a-z]*)\s([a-zA-Z]*)\(([a-zA-Z]*)\s\*?([a-zA-Z]*),\s([a-zA-Z]*)\s\*?([a-zA-Z]*)\)/);
  if (arr) {
    let returnValueType = arr[1];
    let funcName = arr[2];
    let paramsType = arr[3];
    let paramsName = arr[4];
    console.log(`//${funcName} ////////////////////////////////////////////////////////////////
else if (funcName == "${_.camelCase(funcName)}") {
  int reqId = getNumber(env, params, "reqId");
  ${paramsType} req;
  memset(&req, 0, sizeof(${paramsType}));
${getParamsStr(paramsType)}
  std::cout << "{DEBUG in c++}"
            << "call trader api ${_.camelCase(funcName)}! reqId:" << reqId << std::endl;

  int ret = api->${funcName}(&req, reqId);
  return ret;
}`);
  }
});