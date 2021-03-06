#include "Trader.h"

int TdReqID = 0;

Napi::Value Trader::Call(const Napi::CallbackInfo &info) {
  if (Trader::isDebug) {
    std::cout << "[DEBUG in C++]: "
              << "Trader::Call called" << std::endl;
  }

  if (!info[0].IsString()) {
    throw Napi::Error::New(info.Env(), "参数错误");
  }
  if (!info[1].IsObject()) {
    throw Napi::Error::New(info.Env(), "参数错误");
  }
  std::string funcName = info[0].As<Napi::String>();
  Napi::Object params  = info[1].As<Napi::Object>();

  if (funcName == "connect") {
    TD_DEBUG_LOG("call function connect begin");
    this->api = CUstpFtdcTraderApi::CreateFtdcTraderApi("");
    char address[50];
    strcpy(address, getString(params, "IP").c_str());
    this->api->RegisterFront(address);
    this->api->RegisterSpi(this);
    this->api->Init();
    TD_DEBUG_LOG("call function connect done!!!");

  } else if (funcName == "reqUserLogin") {
    TD_DEBUG_LOG("call function reqUserLogin");
    TdReqID++;
    CUstpFtdcReqUserLoginField req;
    memset(&req, 0, sizeof(CUstpFtdcReqUserLoginField));
    strcpy(req.TradingDay, getString(params, "TradingDay").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.Password, getString(params, "Password").c_str());
    strcpy(req.UserProductInfo, getString(params, "UserProductInfo").c_str());
    strcpy(req.InterfaceProductInfo, getString(params, "InterfaceProductInfo").c_str());
    strcpy(req.ProtocolInfo, getString(params, "ProtocolInfo").c_str());
    strcpy(req.IPAddress, getString(params, "IPAddress").c_str());
    strcpy(req.MacAddress, getString(params, "MacAddress").c_str());
    req.DataCenterID        = getNumber(params, "DataCenterID");
    req.UserProductFileSize = getNumber(params, "UserProductFileSize");
    int ret                 = this->api->ReqUserLogin(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "subscribePrivateTopic") {
    TD_DEBUG_LOG("call function subscribePrivateTopic");
    TdReqID++;
    // int ret = this->api->SubscribePrivateTopic(USTP_TERT_RESTART);
    return Napi::Number::New(info.Env(), 0);
  } else if (funcName == "subscribePublicTopic") {
    TD_DEBUG_LOG("call function subscribePublicTopic");
    TdReqID++;
    // int ret = this->api->SubscribePublicTopic(USTP_TERT_RESTART);
    return Napi::Number::New(info.Env(), 0);
  } else if (funcName == "subscribeUserTopic") {
    TD_DEBUG_LOG("call function subscribeUserTopic");
    TdReqID++;
    // int ret = this->api->SubscribeUserTopic(USTP_TERT_RESTART);
    return Napi::Number::New(info.Env(), 0);
  } else if (funcName == "subscribeForQuote") {
    TD_DEBUG_LOG("call function subscribeForQuote");
    TdReqID++;
    // int ret = this->api->SubscribeForQuote(USTP_TERT_RESTART);
    return Napi::Number::New(info.Env(), 0);
  } else if (funcName == "setHeartbeatTimeout") {
    TD_DEBUG_LOG("call function setHeartbeatTimeout");
    TdReqID++;
    // int ret = this->api->SetHeartbeatTimeout(USTP_TERT_RESTART);
    return Napi::Number::New(info.Env(), 0);
  } else if (funcName == "openRequestLog") {
    TD_DEBUG_LOG("call function openRequestLog");
    TdReqID++;
    int ret = this->api->OpenRequestLog("");
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "openResponseLog") {
    TD_DEBUG_LOG("call function openResponseLog");
    TdReqID++;
    int ret = this->api->OpenResponseLog("");
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqUserLogout") {
    TD_DEBUG_LOG("call function reqUserLogout");
    TdReqID++;
    CUstpFtdcReqUserLogoutField req;
    memset(&req, 0, sizeof(CUstpFtdcReqUserLogoutField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    int ret = this->api->ReqUserLogout(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqUserPasswordUpdate") {
    TD_DEBUG_LOG("call function reqUserPasswordUpdate");
    TdReqID++;
    CUstpFtdcUserPasswordUpdateField req;
    memset(&req, 0, sizeof(CUstpFtdcUserPasswordUpdateField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.OldPassword, getString(params, "OldPassword").c_str());
    strcpy(req.NewPassword, getString(params, "NewPassword").c_str());
    int ret = this->api->ReqUserPasswordUpdate(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqSettlementInfoConfirm") {
    TD_DEBUG_LOG("call function reqSettlementInfoConfirm");
    TdReqID++;
    CUstpFtdcInputSettlementInfoConfirmField req;
    memset(&req, 0, sizeof(CUstpFtdcInputSettlementInfoConfirmField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.ConfirmDate, getString(params, "ConfirmDate").c_str());
    strcpy(req.ConfirmTime, getString(params, "ConfirmTime").c_str());
    int ret = this->api->ReqSettlementInfoConfirm(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQrySettlementInfoConfirm") {
    TD_DEBUG_LOG("call function reqQrySettlementInfoConfirm");
    TdReqID++;
    CUstpFtdcQrySettlementInfoConfirmField req;
    memset(&req, 0, sizeof(CUstpFtdcQrySettlementInfoConfirmField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    int ret = this->api->ReqQrySettlementInfoConfirm(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqOrderInsert") {
    TD_DEBUG_LOG("call function reqOrderInsert");
    TdReqID++;
    CUstpFtdcInputOrderField req;
    memset(&req, 0, sizeof(CUstpFtdcInputOrderField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.OrderSysID, getString(params, "OrderSysID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    req.SeatNo = getNumber(params, "SeatNo");
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    strcpy(req.UserOrderLocalID, getString(params, "UserOrderLocalID").c_str());
    req.OrderPriceType = getChar(params, "OrderPriceType");
    req.Direction      = getChar(params, "Direction");
    req.OffsetFlag     = getChar(params, "OffsetFlag");
    req.HedgeFlag      = getChar(params, "HedgeFlag");
    req.LimitPrice     = getNumber(params, "LimitPrice");
    req.Volume         = getNumber(params, "Volume");
    req.TimeCondition  = getChar(params, "TimeCondition");
    strcpy(req.GTDDate, getString(params, "GTDDate").c_str());
    req.VolumeCondition  = getChar(params, "VolumeCondition");
    req.MinVolume        = getNumber(params, "MinVolume");
    req.StopPrice        = getNumber(params, "StopPrice");
    req.ForceCloseReason = getChar(params, "ForceCloseReason");
    req.IsAutoSuspend    = getNumber(params, "IsAutoSuspend");
    strcpy(req.BusinessUnit, getString(params, "BusinessUnit").c_str());
    strcpy(req.UserCustom, getString(params, "UserCustom").c_str());
    req.BusinessLocalID = getNumber(params, "BusinessLocalID");
    strcpy(req.ActionDay, getString(params, "ActionDay").c_str());
    req.ArbiType = getChar(params, "ArbiType");
    int ret      = this->api->ReqOrderInsert(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqOrderAction") {
    TD_DEBUG_LOG("call function reqOrderAction");
    TdReqID++;
    CUstpFtdcOrderActionField req;
    memset(&req, 0, sizeof(CUstpFtdcOrderActionField));
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.OrderSysID, getString(params, "OrderSysID").c_str());
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.UserOrderActionLocalID, getString(params, "UserOrderActionLocalID").c_str());
    strcpy(req.UserOrderLocalID, getString(params, "UserOrderLocalID").c_str());
    req.ActionFlag      = getChar(params, "ActionFlag");
    req.LimitPrice      = getNumber(params, "LimitPrice");
    req.VolumeChange    = getNumber(params, "VolumeChange");
    req.BusinessLocalID = getNumber(params, "BusinessLocalID");
    int ret             = this->api->ReqOrderAction(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQuoteInsert") {
    TD_DEBUG_LOG("call function reqQuoteInsert");
    TdReqID++;
    CUstpFtdcInputQuoteField req;
    memset(&req, 0, sizeof(CUstpFtdcInputQuoteField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    strcpy(req.QuoteSysID, getString(params, "QuoteSysID").c_str());
    strcpy(req.UserQuoteLocalID, getString(params, "UserQuoteLocalID").c_str());
    strcpy(req.QuoteLocalID, getString(params, "QuoteLocalID").c_str());
    req.BidVolume     = getNumber(params, "BidVolume");
    req.BidOffsetFlag = getChar(params, "BidOffsetFlag");
    req.BidHedgeFlag  = getChar(params, "BidHedgeFlag");
    req.BidPrice      = getNumber(params, "BidPrice");
    req.AskVolume     = getNumber(params, "AskVolume");
    req.AskOffsetFlag = getChar(params, "AskOffsetFlag");
    req.AskHedgeFlag  = getChar(params, "AskHedgeFlag");
    req.AskPrice      = getNumber(params, "AskPrice");
    strcpy(req.BusinessUnit, getString(params, "BusinessUnit").c_str());
    strcpy(req.UserCustom, getString(params, "UserCustom").c_str());
    strcpy(req.BidUserOrderLocalID, getString(params, "BidUserOrderLocalID").c_str());
    strcpy(req.AskUserOrderLocalID, getString(params, "AskUserOrderLocalID").c_str());
    int ret = this->api->ReqQuoteInsert(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQuoteAction") {
    TD_DEBUG_LOG("call function reqQuoteAction");
    TdReqID++;
    CUstpFtdcQuoteActionField req;
    memset(&req, 0, sizeof(CUstpFtdcQuoteActionField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.QuoteSysID, getString(params, "QuoteSysID").c_str());
    strcpy(req.UserQuoteLocalID, getString(params, "UserQuoteLocalID").c_str());
    strcpy(req.UserQuoteActionLocalID, getString(params, "UserQuoteActionLocalID").c_str());
    req.ActionFlag = getChar(params, "ActionFlag");
    strcpy(req.BusinessUnit, getString(params, "BusinessUnit").c_str());
    strcpy(req.UserCustom, getString(params, "UserCustom").c_str());
    int ret = this->api->ReqQuoteAction(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqForQuote") {
    TD_DEBUG_LOG("call function reqForQuote");
    TdReqID++;
    CUstpFtdcReqForQuoteField req;
    memset(&req, 0, sizeof(CUstpFtdcReqForQuoteField));
    strcpy(req.ReqForQuoteID, getString(params, "ReqForQuoteID").c_str());
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    strcpy(req.TradingDay, getString(params, "TradingDay").c_str());
    strcpy(req.ReqForQuoteTime, getString(params, "ReqForQuoteTime").c_str());
    int ret = this->api->ReqForQuote(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqMarginCombAction") {
    TD_DEBUG_LOG("call function reqMarginCombAction");
    TdReqID++;
    CUstpFtdcInputMarginCombActionField req;
    memset(&req, 0, sizeof(CUstpFtdcInputMarginCombActionField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    req.HedgeFlag = getChar(params, "HedgeFlag");
    strcpy(req.UserActionLocalID, getString(params, "UserActionLocalID").c_str());
    strcpy(req.CombInstrumentID, getString(params, "CombInstrumentID").c_str());
    req.CombVolume    = getNumber(params, "CombVolume");
    req.CombDirection = getChar(params, "CombDirection");
    strcpy(req.ActionLocalID, getString(params, "ActionLocalID").c_str());
    int ret = this->api->ReqMarginCombAction(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqUserDeposit") {
    TD_DEBUG_LOG("call function reqUserDeposit");
    TdReqID++;
    CUstpFtdcstpUserDepositField req;
    memset(&req, 0, sizeof(CUstpFtdcstpUserDepositField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    req.Amount          = getNumber(params, "Amount");
    req.AmountDirection = getChar(params, "AmountDirection");
    strcpy(req.UserOrderLocalID, getString(params, "UserOrderLocalID").c_str());
    int ret = this->api->ReqUserDeposit(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqTransferMoney") {
    TD_DEBUG_LOG("call function reqTransferMoney");
    TdReqID++;
    CUstpFtdcstpTransferMoneyField req;
    memset(&req, 0, sizeof(CUstpFtdcstpTransferMoneyField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    req.Amount          = getNumber(params, "Amount");
    req.AmountDirection = getChar(params, "AmountDirection");
    strcpy(req.UserOrderLocalID, getString(params, "UserOrderLocalID").c_str());
    strcpy(req.BankID, getString(params, "BankID").c_str());
    strcpy(req.BankPasswd, getString(params, "BankPasswd").c_str());
    strcpy(req.AccountPasswd, getString(params, "AccountPasswd").c_str());
    int ret = this->api->ReqTransferMoney(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryOrder") {
    TD_DEBUG_LOG("call function reqQryOrder");
    TdReqID++;
    CUstpFtdcQryOrderField req;
    memset(&req, 0, sizeof(CUstpFtdcQryOrderField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.OrderSysID, getString(params, "OrderSysID").c_str());
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    req.OrderStatus = getChar(params, "OrderStatus");
    int ret         = this->api->ReqQryOrder(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryTrade") {
    TD_DEBUG_LOG("call function reqQryTrade");
    TdReqID++;
    CUstpFtdcQryTradeField req;
    memset(&req, 0, sizeof(CUstpFtdcQryTradeField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.TradeID, getString(params, "TradeID").c_str());
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    int ret = this->api->ReqQryTrade(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryUserInvestor") {
    TD_DEBUG_LOG("call function reqQryUserInvestor");
    TdReqID++;
    CUstpFtdcQryUserInvestorField req;
    memset(&req, 0, sizeof(CUstpFtdcQryUserInvestorField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    int ret = this->api->ReqQryUserInvestor(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryTradingCode") {
    TD_DEBUG_LOG("call function reqQryTradingCode");
    TdReqID++;
    CUstpFtdcQryTradingCodeField req;
    memset(&req, 0, sizeof(CUstpFtdcQryTradingCodeField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    int ret = this->api->ReqQryTradingCode(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryInvestorAccount") {
    TD_DEBUG_LOG("call function reqQryInvestorAccount");
    TdReqID++;
    CUstpFtdcQryInvestorAccountField req;
    memset(&req, 0, sizeof(CUstpFtdcQryInvestorAccountField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    int ret = this->api->ReqQryInvestorAccount(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryInstrument") {
    TD_DEBUG_LOG("call function reqQryInstrument");
    TdReqID++;
    CUstpFtdcQryInstrumentField req;
    memset(&req, 0, sizeof(CUstpFtdcQryInstrumentField));
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.ProductID, getString(params, "ProductID").c_str());
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    int ret = this->api->ReqQryInstrument(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryExchange") {
    TD_DEBUG_LOG("call function reqQryExchange");
    TdReqID++;
    CUstpFtdcQryExchangeField req;
    memset(&req, 0, sizeof(CUstpFtdcQryExchangeField));
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    int ret = this->api->ReqQryExchange(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryInvestorPosition") {
    TD_DEBUG_LOG("call function reqQryInvestorPosition");
    TdReqID++;
    CUstpFtdcQryInvestorPositionField req;
    memset(&req, 0, sizeof(CUstpFtdcQryInvestorPositionField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    int ret = this->api->ReqQryInvestorPosition(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqSubscribeTopic") {
    TD_DEBUG_LOG("call function reqSubscribeTopic");
    TdReqID++;
    CUstpFtdcDisseminationField req;
    memset(&req, 0, sizeof(CUstpFtdcDisseminationField));
    req.SequenceSeries = getNumber(params, "SequenceSeries");
    req.SequenceNo     = getNumber(params, "SequenceNo");
    int ret            = this->api->ReqSubscribeTopic(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryComplianceParam") {
    TD_DEBUG_LOG("call function reqQryComplianceParam");
    TdReqID++;
    CUstpFtdcQryComplianceParamField req;
    memset(&req, 0, sizeof(CUstpFtdcQryComplianceParamField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    int ret = this->api->ReqQryComplianceParam(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryTopic") {
    TD_DEBUG_LOG("call function reqQryTopic");
    TdReqID++;
    CUstpFtdcDisseminationField req;
    memset(&req, 0, sizeof(CUstpFtdcDisseminationField));
    req.SequenceSeries = getNumber(params, "SequenceSeries");
    req.SequenceNo     = getNumber(params, "SequenceNo");
    int ret            = this->api->ReqQryTopic(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryInvestorFee") {
    TD_DEBUG_LOG("call function reqQryInvestorFee");
    TdReqID++;
    CUstpFtdcQryInvestorFeeField req;
    memset(&req, 0, sizeof(CUstpFtdcQryInvestorFeeField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    int ret = this->api->ReqQryInvestorFee(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryInvestorMargin") {
    TD_DEBUG_LOG("call function reqQryInvestorMargin");
    TdReqID++;
    CUstpFtdcQryInvestorMarginField req;
    memset(&req, 0, sizeof(CUstpFtdcQryInvestorMarginField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    int ret = this->api->ReqQryInvestorMargin(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryInvestorCombPosition") {
    TD_DEBUG_LOG("call function reqQryInvestorCombPosition");
    TdReqID++;
    CUstpFtdcQryInvestorCombPositionField req;
    memset(&req, 0, sizeof(CUstpFtdcQryInvestorCombPositionField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    req.HedgeFlag = getChar(params, "HedgeFlag");
    strcpy(req.CombInstrumentID, getString(params, "CombInstrumentID").c_str());
    int ret = this->api->ReqQryInvestorCombPosition(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryInvestorLegPosition") {
    TD_DEBUG_LOG("call function reqQryInvestorLegPosition");
    TdReqID++;
    CUstpFtdcQryInvestorLegPositionField req;
    memset(&req, 0, sizeof(CUstpFtdcQryInvestorLegPositionField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    req.HedgeFlag = getChar(params, "HedgeFlag");
    strcpy(req.LegInstrumentID, getString(params, "LegInstrumentID").c_str());
    int ret = this->api->ReqQryInvestorLegPosition(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryInstrumentGroup") {
    TD_DEBUG_LOG("call function reqQryInstrumentGroup");
    TdReqID++;
    CUstpFtdcQryUstpInstrumentGroupField req;
    memset(&req, 0, sizeof(CUstpFtdcQryUstpInstrumentGroupField));
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    int ret = this->api->ReqQryInstrumentGroup(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryClientMarginCombType") {
    TD_DEBUG_LOG("call function reqQryClientMarginCombType");
    TdReqID++;
    CUstpFtdcQryClientMarginCombTypeField req;
    memset(&req, 0, sizeof(CUstpFtdcQryClientMarginCombTypeField));
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    req.HedgeFlag = getChar(params, "HedgeFlag");
    strcpy(req.InstrumentGroupID, getString(params, "InstrumentGroupID").c_str());
    int ret = this->api->ReqQryClientMarginCombType(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQrySystemTime") {
    TD_DEBUG_LOG("call function reqQrySystemTime");
    TdReqID++;
    CUstpFtdcReqQrySystemTimeField req;
    memset(&req, 0, sizeof(CUstpFtdcReqQrySystemTimeField));
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    int ret = this->api->ReqQrySystemTime(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqCfmmcTradingAccountKey") {
    TD_DEBUG_LOG("call function reqCfmmcTradingAccountKey");
    TdReqID++;
    CUstpFtdcCFMMCTradingAccountKeyReqField req;
    memset(&req, 0, sizeof(CUstpFtdcCFMMCTradingAccountKeyReqField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    int ret = this->api->ReqCFMMCTradingAccountKey(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQrySettlementInfo") {
    TD_DEBUG_LOG("call function reqQrySettlementInfo");
    TdReqID++;
    CUstpFtdcSettlementQryReqField req;
    memset(&req, 0, sizeof(CUstpFtdcSettlementQryReqField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.TradingDay, getString(params, "TradingDay").c_str());
    int ret = this->api->ReqQrySettlementInfo(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqTradingAccountPasswordUpdate") {
    TD_DEBUG_LOG("call function reqTradingAccountPasswordUpdate");
    TdReqID++;
    CUstpFtdcTradingAccountPasswordUpdateReqField req;
    memset(&req, 0, sizeof(CUstpFtdcTradingAccountPasswordUpdateReqField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.OldPassword, getString(params, "OldPassword").c_str());
    strcpy(req.NewPassword, getString(params, "NewPassword").c_str());
    int ret = this->api->ReqTradingAccountPasswordUpdate(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryTransferBank") {
    TD_DEBUG_LOG("call function reqQryTransferBank");
    TdReqID++;
    CUstpFtdcTransferBankQryReqField req;
    memset(&req, 0, sizeof(CUstpFtdcTransferBankQryReqField));
    strcpy(req.BankID, getString(params, "BankID").c_str());
    strcpy(req.BankBrchID, getString(params, "BankBrchID").c_str());
    int ret = this->api->ReqQryTransferBank(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryEWarrantOffset") {
    TD_DEBUG_LOG("call function reqQryEWarrantOffset");
    TdReqID++;
    CUstpFtdcEWarrantOffsetFieldReqField req;
    memset(&req, 0, sizeof(CUstpFtdcEWarrantOffsetFieldReqField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.InvestorID, getString(params, "InvestorID").c_str());
    strcpy(req.ExchangeID, getString(params, "ExchangeID").c_str());
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    int ret = this->api->ReqQryEWarrantOffset(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryTransferSeria") {
    TD_DEBUG_LOG("call function reqQryTransferSeria");
    TdReqID++;
    CUstpFtdcTransferSerialFieldReqField req;
    memset(&req, 0, sizeof(CUstpFtdcTransferSerialFieldReqField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.AccountID, getString(params, "AccountID").c_str());
    strcpy(req.BankID, getString(params, "BankID").c_str());
    int ret = this->api->ReqQryTransferSeria(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryAccountregister") {
    TD_DEBUG_LOG("call function reqQryAccountregister");
    TdReqID++;
    CUstpFtdcAccountregisterReqField req;
    memset(&req, 0, sizeof(CUstpFtdcAccountregisterReqField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.AccountID, getString(params, "AccountID").c_str());
    strcpy(req.BankID, getString(params, "BankID").c_str());
    int ret = this->api->ReqQryAccountregister(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQryContractBank") {
    TD_DEBUG_LOG("call function reqQryContractBank");
    TdReqID++;
    CUstpFtdcContractBankFieldReqField req;
    memset(&req, 0, sizeof(CUstpFtdcContractBankFieldReqField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.BankID, getString(params, "BankID").c_str());
    strcpy(req.BankBrchID, getString(params, "BankBrchID").c_str());
    int ret = this->api->ReqQryContractBank(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqFromBankToFutureByFuture") {
    TD_DEBUG_LOG("call function reqFromBankToFutureByFuture");
    TdReqID++;
    CUstpFtdcTransferFieldReqField req;
    memset(&req, 0, sizeof(CUstpFtdcTransferFieldReqField));
    strcpy(req.TradeCode, getString(params, "TradeCode").c_str());
    strcpy(req.BankID, getString(params, "BankID").c_str());
    strcpy(req.BankBrchID, getString(params, "BankBrchID").c_str());
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.BrokerBranchID, getString(params, "BrokerBranchID").c_str());
    strcpy(req.TradeDate, getString(params, "TradeDate").c_str());
    strcpy(req.TradeTime, getString(params, "TradeTime").c_str());
    strcpy(req.BankSerial, getString(params, "BankSerial").c_str());
    strcpy(req.TradingDay, getString(params, "TradingDay").c_str());
    req.PlateSerial  = getNumber(params, "PlateSerial");
    req.LastFragment = getNumber(params, "LastFragment");
    req.SessionID    = getNumber(params, "SessionID");
    strcpy(req.CustomerName, getString(params, "CustomerName").c_str());
    req.IdCardType = getChar(params, "IdCardType");
    strcpy(req.IdentifiedCardNo, getString(params, "IdentifiedCardNo").c_str());
    req.CustType = getChar(params, "CustType");
    strcpy(req.BankAccount, getString(params, "BankAccount").c_str());
    strcpy(req.BankPassWord, getString(params, "BankPassWord").c_str());
    strcpy(req.AccountID, getString(params, "AccountID").c_str());
    strcpy(req.Password, getString(params, "Password").c_str());
    req.InstallID    = getNumber(params, "InstallID");
    req.FutureSerial = getNumber(params, "FutureSerial");
    strcpy(req.UserID, getString(params, "UserID").c_str());
    req.VerifyCertNoFlag = getNumber(params, "VerifyCertNoFlag");
    strcpy(req.CurrencyID, getString(params, "CurrencyID").c_str());
    req.TradeAmount       = getNumber(params, "TradeAmount");
    req.FutureFetchAmount = getNumber(params, "FutureFetchAmount");
    req.FeePayFlag        = getChar(params, "FeePayFlag");
    req.CustFee           = getNumber(params, "CustFee");
    req.BrokerFee         = getNumber(params, "BrokerFee");
    strcpy(req.Message, getString(params, "Message").c_str());
    strcpy(req.Digest, getString(params, "Digest").c_str());
    req.BankAccType = getChar(params, "BankAccType");
    strcpy(req.DeviceID, getString(params, "DeviceID").c_str());
    req.BankSecuAccType = getChar(params, "BankSecuAccType");
    strcpy(req.BrokerIDByBank, getString(params, "BrokerIDByBank").c_str());
    strcpy(req.BankSecuAcc, getString(params, "BankSecuAcc").c_str());
    req.BankPwdFlag = getChar(params, "BankPwdFlag");
    req.SecuPwdFlag = getChar(params, "SecuPwdFlag");
    strcpy(req.OperNo, getString(params, "OperNo").c_str());
    req.RequestID      = getNumber(params, "RequestID");
    req.TID            = getNumber(params, "TID");
    req.TransferStatus = getChar(params, "TransferStatus");
    int ret            = this->api->ReqFromBankToFutureByFuture(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqFromFutureToBankByFuture") {
    TD_DEBUG_LOG("call function reqFromFutureToBankByFuture");
    TdReqID++;
    CUstpFtdcTransferFieldReqField req;
    memset(&req, 0, sizeof(CUstpFtdcTransferFieldReqField));
    strcpy(req.TradeCode, getString(params, "TradeCode").c_str());
    strcpy(req.BankID, getString(params, "BankID").c_str());
    strcpy(req.BankBrchID, getString(params, "BankBrchID").c_str());
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.BrokerBranchID, getString(params, "BrokerBranchID").c_str());
    strcpy(req.TradeDate, getString(params, "TradeDate").c_str());
    strcpy(req.TradeTime, getString(params, "TradeTime").c_str());
    strcpy(req.BankSerial, getString(params, "BankSerial").c_str());
    strcpy(req.TradingDay, getString(params, "TradingDay").c_str());
    req.PlateSerial  = getNumber(params, "PlateSerial");
    req.LastFragment = getNumber(params, "LastFragment");
    req.SessionID    = getNumber(params, "SessionID");
    strcpy(req.CustomerName, getString(params, "CustomerName").c_str());
    req.IdCardType = getChar(params, "IdCardType");
    strcpy(req.IdentifiedCardNo, getString(params, "IdentifiedCardNo").c_str());
    req.CustType = getChar(params, "CustType");
    strcpy(req.BankAccount, getString(params, "BankAccount").c_str());
    strcpy(req.BankPassWord, getString(params, "BankPassWord").c_str());
    strcpy(req.AccountID, getString(params, "AccountID").c_str());
    strcpy(req.Password, getString(params, "Password").c_str());
    req.InstallID    = getNumber(params, "InstallID");
    req.FutureSerial = getNumber(params, "FutureSerial");
    strcpy(req.UserID, getString(params, "UserID").c_str());
    req.VerifyCertNoFlag = getNumber(params, "VerifyCertNoFlag");
    strcpy(req.CurrencyID, getString(params, "CurrencyID").c_str());
    req.TradeAmount       = getNumber(params, "TradeAmount");
    req.FutureFetchAmount = getNumber(params, "FutureFetchAmount");
    req.FeePayFlag        = getChar(params, "FeePayFlag");
    req.CustFee           = getNumber(params, "CustFee");
    req.BrokerFee         = getNumber(params, "BrokerFee");
    strcpy(req.Message, getString(params, "Message").c_str());
    strcpy(req.Digest, getString(params, "Digest").c_str());
    req.BankAccType = getChar(params, "BankAccType");
    strcpy(req.DeviceID, getString(params, "DeviceID").c_str());
    req.BankSecuAccType = getChar(params, "BankSecuAccType");
    strcpy(req.BrokerIDByBank, getString(params, "BrokerIDByBank").c_str());
    strcpy(req.BankSecuAcc, getString(params, "BankSecuAcc").c_str());
    req.BankPwdFlag = getChar(params, "BankPwdFlag");
    req.SecuPwdFlag = getChar(params, "SecuPwdFlag");
    strcpy(req.OperNo, getString(params, "OperNo").c_str());
    req.RequestID      = getNumber(params, "RequestID");
    req.TID            = getNumber(params, "TID");
    req.TransferStatus = getChar(params, "TransferStatus");
    int ret            = this->api->ReqFromFutureToBankByFuture(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else if (funcName == "reqQueryBankAccountMoneyByFuture") {
    TD_DEBUG_LOG("call function reqQueryBankAccountMoneyByFuture");
    TdReqID++;
    CUstpFtdcAccountFieldReqField req;
    memset(&req, 0, sizeof(CUstpFtdcAccountFieldReqField));
    strcpy(req.TradeCode, getString(params, "TradeCode").c_str());
    strcpy(req.BankID, getString(params, "BankID").c_str());
    strcpy(req.BankBrchID, getString(params, "BankBrchID").c_str());
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.BrokerBranchID, getString(params, "BrokerBranchID").c_str());
    strcpy(req.TradeDate, getString(params, "TradeDate").c_str());
    strcpy(req.TradeTime, getString(params, "TradeTime").c_str());
    strcpy(req.BankSerial, getString(params, "BankSerial").c_str());
    strcpy(req.TradingDay, getString(params, "TradingDay").c_str());
    req.PlateSerial  = getNumber(params, "PlateSerial");
    req.LastFragment = getNumber(params, "LastFragment");
    req.SessionID    = getNumber(params, "SessionID");
    strcpy(req.CustomerName, getString(params, "CustomerName").c_str());
    req.IdCardType = getChar(params, "IdCardType");
    strcpy(req.IdentifiedCardNo, getString(params, "IdentifiedCardNo").c_str());
    req.CustType = getChar(params, "CustType");
    strcpy(req.BankAccount, getString(params, "BankAccount").c_str());
    strcpy(req.BankPassWord, getString(params, "BankPassWord").c_str());
    strcpy(req.AccountID, getString(params, "AccountID").c_str());
    strcpy(req.Password, getString(params, "Password").c_str());
    req.InstallID    = getNumber(params, "InstallID");
    req.FutureSerial = getNumber(params, "FutureSerial");
    strcpy(req.UserID, getString(params, "UserID").c_str());
    req.VerifyCertNoFlag = getNumber(params, "VerifyCertNoFlag");
    strcpy(req.CurrencyID, getString(params, "CurrencyID").c_str());
    strcpy(req.Digest, getString(params, "Digest").c_str());
    req.BankAccType = getChar(params, "BankAccType");
    strcpy(req.DeviceID, getString(params, "DeviceID").c_str());
    req.BankSecuAccType = getChar(params, "BankSecuAccType");
    strcpy(req.BrokerIDByBank, getString(params, "BrokerIDByBank").c_str());
    strcpy(req.BankSecuAcc, getString(params, "BankSecuAcc").c_str());
    req.BankPwdFlag = getChar(params, "BankPwdFlag");
    req.SecuPwdFlag = getChar(params, "SecuPwdFlag");
    strcpy(req.OperNo, getString(params, "OperNo").c_str());
    req.RequestID = getNumber(params, "RequestID");
    req.TID       = getNumber(params, "TID");
    int ret       = this->api->ReqQueryBankAccountMoneyByFuture(&req, TdReqID);
    return Napi::Number::New(info.Env(), ret);
  } else {
    return Napi::Number::New(info.Env(), NONE_TRADER_API_FUNC);
  }

  return Napi::Number::New(info.Env(), STATUS_SUCCESS);
}