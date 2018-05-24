const _ = require('lodash');
const fs = require('fs');

let str = `	///错误应答
	virtual void OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///风控前置系统用户登录应答
	virtual void OnRspUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户退出应答
	virtual void OnRspUserLogout(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户密码修改应答
	virtual void OnRspUserPasswordUpdate(CUstpFtdcUserPasswordUpdateField *pUserPasswordUpdate, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求对账单确认响应
	virtual void OnRspSettlementInfoConfirm(CUstpFtdcInputSettlementInfoConfirmField *pInputSettlementInfoConfirm, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询对账单确认响应
	virtual void OnRspQrySettlementInfoConfirm(CUstpFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单录入应答
	virtual void OnRspOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单操作应答
	virtual void OnRspOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报价录入应答
	virtual void OnRspQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报价操作应答
	virtual void OnRspQuoteAction(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///询价请求应答
	virtual void OnRspForQuote(CUstpFtdcReqForQuoteField *pReqForQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///客户申请组合应答
	virtual void OnRspMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户请求出入金应答
	virtual void OnRspUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户主次席出入金应答
	virtual void OnRspTransferMoney(CUstpFtdcstpTransferMoneyField *pstpTransferMoney, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///数据流回退通知
	virtual void OnRtnFlowMessageCancel(CUstpFtdcFlowMessageCancelField *pFlowMessageCancel) {};

	///成交回报
	virtual void OnRtnTrade(CUstpFtdcTradeField *pTrade) {};

	///报单回报
	virtual void OnRtnOrder(CUstpFtdcOrderField *pOrder) {};

	///报单录入错误回报
	virtual void OnErrRtnOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo) {};

	///报单操作错误回报
	virtual void OnErrRtnOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo) {};

	///合约交易状态通知
	virtual void OnRtnInstrumentStatus(CUstpFtdcInstrumentStatusField *pInstrumentStatus) {};

	///账户出入金回报
	virtual void OnRtnInvestorAccountDeposit(CUstpFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) {};

	///报价回报
	virtual void OnRtnQuote(CUstpFtdcRtnQuoteField *pRtnQuote) {};

	///报价录入错误回报
	virtual void OnErrRtnQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo) {};

	///报价撤单错误回报
	virtual void OnErrRtnQuoteAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo) {};

	///询价回报
	virtual void OnRtnForQuote(CUstpFtdcReqForQuoteField *pReqForQuote) {};

	///增加组合规则通知
	virtual void OnRtnMarginCombinationLeg(CUstpFtdcMarginCombinationLegField *pMarginCombinationLeg) {};

	///客户申请组合确认
	virtual void OnRtnMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction) {};

	///用户请求出入金
	virtual void OnRtnUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit) {};

	///查询前置系统用户登录应答
	virtual void OnRspQueryUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单查询应答
	virtual void OnRspQryOrder(CUstpFtdcOrderField *pOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///成交单查询应答
	virtual void OnRspQryTrade(CUstpFtdcTradeField *pTrade, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///可用投资者账户查询应答
	virtual void OnRspQryUserInvestor(CUstpFtdcRspUserInvestorField *pRspUserInvestor, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易编码查询应答
	virtual void OnRspQryTradingCode(CUstpFtdcRspTradingCodeField *pRspTradingCode, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者资金账户查询应答
	virtual void OnRspQryInvestorAccount(CUstpFtdcRspInvestorAccountField *pRspInvestorAccount, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约查询应答
	virtual void OnRspQryInstrument(CUstpFtdcRspInstrumentField *pRspInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易所查询应答
	virtual void OnRspQryExchange(CUstpFtdcRspExchangeField *pRspExchange, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者持仓查询应答
	virtual void OnRspQryInvestorPosition(CUstpFtdcRspInvestorPositionField *pRspInvestorPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅主题应答
	virtual void OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合规参数查询应答
	virtual void OnRspQryComplianceParam(CUstpFtdcRspComplianceParamField *pRspComplianceParam, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///主题查询应答
	virtual void OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者手续费率查询应答
	virtual void OnRspQryInvestorFee(CUstpFtdcInvestorFeeField *pInvestorFee, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者保证金率查询应答
	virtual void OnRspQryInvestorMargin(CUstpFtdcInvestorMarginField *pInvestorMargin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易编码组合持仓查询应答
	virtual void OnRspQryInvestorCombPosition(CUstpFtdcRspInvestorCombPositionField *pRspInvestorCombPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易编码单腿持仓查询应答
	virtual void OnRspQryInvestorLegPosition(CUstpFtdcRspInvestorLegPositionField *pRspInvestorLegPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约组信息查询应答
	virtual void OnRspQryInstrumentGroup(CUstpFtdcRspInstrumentGroupField *pRspInstrumentGroup, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///组合保证金类型查询应答
	virtual void OnRspQryClientMarginCombType(CUstpFtdcRspClientMarginCombTypeField *pRspClientMarginCombType, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///系统时间查询应答
	virtual void OnRspQrySystemTime(CUstpFtdcRspQrySystemTimeField *pRspQrySystemTime, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询保证金监管系统经纪公司资金账户密钥响应
	virtual void OnRspCFMMCTradingAccountKey(CUstpFtdcCFMMCTradingAccountKeyRspField *pCFMMCTradingAccountKeyRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询投资者结算结果响应
	virtual void OnRspQrySettlementInfo(CUstpFtdcSettlementRspField *pSettlementRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///资金账户口令更新请求响应
	virtual void OnRspTradingAccountPasswordUpdate(CUstpFtdcTradingAccountPasswordUpdateRspField *pTradingAccountPasswordUpdateRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询转帐银行响应
	virtual void OnRspQryTransferBank(CUstpFtdcTransferBankQryRspField *pTransferBankQryRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询仓单折抵信息响应
	virtual void OnRspQryEWarrantOffset(CUstpFtdcEWarrantOffsetFieldRspField *pEWarrantOffsetFieldRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询转帐流水响应
	virtual void OnRspQryTransferSeriaOffset(CUstpFtdcTransferSerialFieldRspField *pTransferSerialFieldRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询银期签约关系响应
	virtual void OnRspQryAccountregister(CUstpFtdcAccountregisterRspField *pAccountregisterRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///请求查询签约银行
	virtual void OnRspQryContractBank(CUstpFtdcContractBankFieldRspField *pContractBankFieldRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///期货发起银行资金转期货应答
	virtual void OnRspFromBankToFutureByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///期货发起银行资金转期货通知
	virtual void OnRtnFromBankToFutureByFuture(CUstpFtdcTransferFieldRtnField *pTransferFieldRtn) {};

	///期货发起银行资金转期货错误回报
	virtual void OnErrRtnFromBankToFutureByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo) {};

	///期货发起期货资金转银行应答
	virtual void OnRspFromFutureToBankByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///期货发起期货资金转银行通知
	virtual void OnRtnFromFutureToBankByBank(CUstpFtdcTransferFieldRtnField *pTransferFieldRtn) {};

	///期货发起期货资金转银行错误回报
	virtual void OnErrRtnFromFutureToBankByBank(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo) {};

	///银行发起银行资金转期货通知
	virtual void OnRtnFromBankToFutureByBank(CUstpFtdcTransferFieldRtnField *pTransferFieldRtn) {};

	///期货发起查询银行余额应答
	virtual void OnRspQueryBankAccountMoneyByFuture(CUstpFtdcAccountFieldReqField *pAccountFieldReq, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///期货发起查询银行余额通知
	virtual void OnRtnQueryBankBalanceByFuture(CUstpFtdcAccountFieldRtnField *pAccountFieldRtn) {};

	///期货发起查询银行余额错误回报
	virtual void OnErrRtnQueryBankBalanceByFuture(CUstpFtdcAccountFieldReqField *pAccountFieldReq, CUstpFtdcRspInfoField *pRspInfo) {};

	///银行发起冲正银行转期货通知
	virtual void OnRtnRepealFromBankToFutureByBank(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn) {};

	///银行发起冲正期货转银行通知
	virtual void OnRtnRepealFromFutureToBankByBank(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn) {};

	///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromBankToFutureByFutureManual(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn) {};

	///系统运行时期货端手工发起冲正银行转期货错误回报
	virtual void OnErrRtnRepealBankToFutureByFutureManual(CUstpFtdcRepealFieldRspField *pRepealFieldRsp, CUstpFtdcRspInfoField *pRspInfo) {};

	///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromFutureToBankByFutureManual(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn) {};

	///系统运行时期货端手工发起冲正期货转银行错误回报
	virtual void OnErrRtnRepealFutureToBankByFutureManual(CUstpFtdcRepealFieldRspField *pRepealFieldRsp, CUstpFtdcRspInfoField *pRspInfo) {};

	///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromBankToFutureByFuture(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn) {};

	///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromFutureToBankByFuture(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn) {};

	///银行发起银期开户通知
	virtual void OnRtnOpenAccountByBank(CUstpFtdcAccountFieldField *pAccountField) {};

	///银行发起银期销户通知
	virtual void OnRtnCancelAccountByBank(CUstpFtdcAccountFieldField *pAccountField) {};

	///银行发起变更银行账号通知
	virtual void OnRtnChangeAccountByBank(CUstpFtdcChangeAccountFieldField *pChangeAccountField) {};`;

let STRUCT = require('./femas-struct.json');
let DATA_TYPE = require('./femas-data-type.json');

let rspInfo = (params) => {
  let res = "";
  if (params.some(p => p.match(/CUstpFtdcRspInfoField/))) {
    res =
      `\n  if (!!field->rspInfo) {
    CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
    SET_PROPERTY_STRING(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
    SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
  }`;
  }
  return res;
};

let info = (params) => {
  let res = "";
  params.forEach(p => {
    if (p.match(/CUstpFtdc/) && !p.match(/CUstpFtdcRspInfoField/)) {
      let arr = p.match(/\s*([a-zA-Z]*)\s*\*([a-zA-Z]*)/);
      let paramType = arr[1];
      let paramName = arr[2];
      // console.log('[DEBUG]', arr);
      res += `\n    if (!!field->data) {
    ${paramType} *info = static_cast<${paramType} *>(field->data);`;
      if (!STRUCT[paramType]) {
        console.log('[WARN]', 'no STRUCT:', paramType);
      }
      STRUCT[paramType].forEach(field => {
        if (DATA_TYPE[field.fieldType] === "int" || DATA_TYPE[field.fieldType] === "double") {
          res += `\n    SET_PROPERTY_NUMBER(env, obj, "${field.fieldName}", info->${field.fieldName});`;
        } else if (DATA_TYPE[field.fieldType] === "char") {
          if (field.fieldName === "ErrorMsg" || field.fieldName.indexOf("Name") > -1) {
            res += `\n    SET_PROPERTY_BUFFER(env, obj, "${field.fieldName}", info->${field.fieldName});`;
          } else {
            res += `\n    SET_PROPERTY_STRING(env, obj, "${field.fieldName}", info->${field.fieldName});`;
          }
        }
      });
      res += `\n  };`
    }
  });
  return res;
};

let errCode = (params) => {
  return "";
};

let requestId = (params) => {
  let res = "";
  params.forEach((p) => {
    if (p.match(/nRequestID/)) {
      res = `\n    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);`
    }
  });
  return res;
};

str.split("\n").forEach((line) => {
  let arr = line.match(/\s*virtual\svoid\s([a-zA-Z]*)\(([^\(\)]*)\)\s*\{\};/);
  // console.log('[DEBUG]', arr);
  if (!arr || !arr.length) return;
  let funcName = arr[1];
  let paramsStr = arr[2];
  let params = paramsStr.split(",").map(s => s.trim());
  // console.log('[DEBUG]', params);
  let res =
    `  else if (eventId == ${_.replace(_.upperCase(_.snakeCase(funcName)), /\s/g, "_")}) {${rspInfo(params)}${info(params)}${errCode(params)}${requestId(params)}
  }`;
  // console.log(res);
  fs.appendFileSync("./tmp-callback.txt", res);
});