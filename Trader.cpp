#include "Trader.h"

Napi::Reference<Napi::Function> Trader::constructor;
std::map<std::string, int> Trader::eventMap;
std::map<int, Napi::Reference<Napi::Function> *> Trader::cbMap;
bool Trader::isDebug = false;

std::string getString(Napi::Object params, std::string key) {
  if (params.Get(key).IsUndefined()) {
    std::string space("");
    return space;
  }
  return params.Get(key).As<Napi::String>().Utf8Value();
};

double getNumber(Napi::Object params, std::string key) {
  if (params.Get(key).IsUndefined()) {
    return 0;
  }
  return (double)(params.Get(key).As<Napi::Number>());
};

char getChar(Napi::Object params, std::string key) {
  if (params.Get(key).IsUndefined()) {
    return '\0';
  }
  std::string str = params.Get(key).As<Napi::String>().Utf8Value();
  return str.c_str()[0];
};

double roundFunc(double x, int n) { return round(x * pow(10, n)) / pow(10, n); };

Trader::Trader(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Trader>(info) {
  if (info[0].IsObject()) {
    Napi::Object obj = info[0].As<Napi::Object>();
    bool _isDebug    = obj.Get("debug").ToBoolean();
    Trader::isDebug  = _isDebug;
  } else {
    Trader::isDebug = false;
  }
  Trader::InitEventMap();
  uv_async_init(uv_default_loop(), &async_t, NULL);
}
Trader::~Trader(void){};

void Trader::InitEventMap() {
  eventMap["frontConnected"]                          = ON_FRONT_CONNECTED;
  eventMap["qryFrontConnected"]                       = ON_QRY_FRONT_CONNECTED;
  eventMap["frontDisconnected"]                       = ON_FRONT_DISCONNECTED;
  eventMap["qryFrontDisconnected"]                    = ON_QRY_FRONT_DISCONNECTED;
  eventMap["heartBeatWarning"]                        = ON_HEART_BEAT_WARNING;
  eventMap["packageStart"]                            = ON_PACKAGE_START;
  eventMap["packageEnd"]                              = ON_PACKAGE_END;
  eventMap["rspError"]                                = ON_RSP_ERROR;
  eventMap["rspUserLogin"]                            = ON_RSP_USER_LOGIN;
  eventMap["rspUserLogout"]                           = ON_RSP_USER_LOGOUT;
  eventMap["rspUserPasswordUpdate"]                   = ON_RSP_USER_PASSWORD_UPDATE;
  eventMap["rspSettlementInfoConfirm"]                = ON_RSP_SETTLEMENT_INFO_CONFIRM;
  eventMap["rspQrySettlementInfoConfirm"]             = ON_RSP_QRY_SETTLEMENT_INFO_CONFIRM;
  eventMap["rspOrderInsert"]                          = ON_RSP_ORDER_INSERT;
  eventMap["rspOrderAction"]                          = ON_RSP_ORDER_ACTION;
  eventMap["rspQuoteInsert"]                          = ON_RSP_QUOTE_INSERT;
  eventMap["rspQuoteAction"]                          = ON_RSP_QUOTE_ACTION;
  eventMap["rspForQuote"]                             = ON_RSP_FOR_QUOTE;
  eventMap["rspMarginCombAction"]                     = ON_RSP_MARGIN_COMB_ACTION;
  eventMap["rspUserDeposit"]                          = ON_RSP_USER_DEPOSIT;
  eventMap["rspTransferMoney"]                        = ON_RSP_TRANSFER_MONEY;
  eventMap["rtnFlowMessageCancel"]                    = ON_RTN_FLOW_MESSAGE_CANCEL;
  eventMap["rtnTrade"]                                = ON_RTN_TRADE;
  eventMap["rtnOrder"]                                = ON_RTN_ORDER;
  eventMap["errRtnOrderInsert"]                       = ON_ERR_RTN_ORDER_INSERT;
  eventMap["errRtnOrderAction"]                       = ON_ERR_RTN_ORDER_ACTION;
  eventMap["rtnInstrumentStatus"]                     = ON_RTN_INSTRUMENT_STATUS;
  eventMap["rtnInvestorAccountDeposit"]               = ON_RTN_INVESTOR_ACCOUNT_DEPOSIT;
  eventMap["rtnQuote"]                                = ON_RTN_QUOTE;
  eventMap["errRtnQuoteInsert"]                       = ON_ERR_RTN_QUOTE_INSERT;
  eventMap["errRtnQuoteAction"]                       = ON_ERR_RTN_QUOTE_ACTION;
  eventMap["rtnForQuote"]                             = ON_RTN_FOR_QUOTE;
  eventMap["rtnMarginCombinationLeg"]                 = ON_RTN_MARGIN_COMBINATION_LEG;
  eventMap["rtnMarginCombAction"]                     = ON_RTN_MARGIN_COMB_ACTION;
  eventMap["rtnUserDeposit"]                          = ON_RTN_USER_DEPOSIT;
  eventMap["rspQueryUserLogin"]                       = ON_RSP_QUERY_USER_LOGIN;
  eventMap["rspQryOrder"]                             = ON_RSP_QRY_ORDER;
  eventMap["rspQryTrade"]                             = ON_RSP_QRY_TRADE;
  eventMap["rspQryUserInvestor"]                      = ON_RSP_QRY_USER_INVESTOR;
  eventMap["rspQryTradingCode"]                       = ON_RSP_QRY_TRADING_CODE;
  eventMap["rspQryInvestorAccount"]                   = ON_RSP_QRY_INVESTOR_ACCOUNT;
  eventMap["rspQryInstrument"]                        = ON_RSP_QRY_INSTRUMENT;
  eventMap["rspQryExchange"]                          = ON_RSP_QRY_EXCHANGE;
  eventMap["rspQryInvestorPosition"]                  = ON_RSP_QRY_INVESTOR_POSITION;
  eventMap["rspSubscribeTopic"]                       = ON_RSP_SUBSCRIBE_TOPIC;
  eventMap["rspQryComplianceParam"]                   = ON_RSP_QRY_COMPLIANCE_PARAM;
  eventMap["rspQryTopic"]                             = ON_RSP_QRY_TOPIC;
  eventMap["rspQryInvestorFee"]                       = ON_RSP_QRY_INVESTOR_FEE;
  eventMap["rspQryInvestorMargin"]                    = ON_RSP_QRY_INVESTOR_MARGIN;
  eventMap["rspQryInvestorCombPosition"]              = ON_RSP_QRY_INVESTOR_COMB_POSITION;
  eventMap["rspQryInvestorLegPosition"]               = ON_RSP_QRY_INVESTOR_LEG_POSITION;
  eventMap["rspQryInstrumentGroup"]                   = ON_RSP_QRY_INSTRUMENT_GROUP;
  eventMap["rspQryClientMarginCombType"]              = ON_RSP_QRY_CLIENT_MARGIN_COMB_TYPE;
  eventMap["rspQrySystemTime"]                        = ON_RSP_QRY_SYSTEM_TIME;
  eventMap["rspCfmmcTradingAccountKey"]               = ON_RSP_CFMMC_TRADING_ACCOUNT_KEY;
  eventMap["rspQrySettlementInfo"]                    = ON_RSP_QRY_SETTLEMENT_INFO;
  eventMap["rspTradingAccountPasswordUpdate"]         = ON_RSP_TRADING_ACCOUNT_PASSWORD_UPDATE;
  eventMap["rspQryTransferBank"]                      = ON_RSP_QRY_TRANSFER_BANK;
  eventMap["rspQryEWarrantOffset"]                    = ON_RSP_QRY_E_WARRANT_OFFSET;
  eventMap["rspQryTransferSeriaOffset"]               = ON_RSP_QRY_TRANSFER_SERIA_OFFSET;
  eventMap["rspQryAccountregister"]                   = ON_RSP_QRY_ACCOUNTREGISTER;
  eventMap["rspQryContractBank"]                      = ON_RSP_QRY_CONTRACT_BANK;
  eventMap["rspFromBankToFutureByFuture"]             = ON_RSP_FROM_BANK_TO_FUTURE_BY_FUTURE;
  eventMap["rtnFromBankToFutureByFuture"]             = ON_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE;
  eventMap["errRtnFromBankToFutureByFuture"]          = ON_ERR_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE;
  eventMap["rspFromFutureToBankByFuture"]             = ON_RSP_FROM_FUTURE_TO_BANK_BY_FUTURE;
  eventMap["rtnFromFutureToBankByBank"]               = ON_RTN_FROM_FUTURE_TO_BANK_BY_BANK;
  eventMap["errRtnFromFutureToBankByBank"]            = ON_ERR_RTN_FROM_FUTURE_TO_BANK_BY_BANK;
  eventMap["rtnFromBankToFutureByBank"]               = ON_RTN_FROM_BANK_TO_FUTURE_BY_BANK;
  eventMap["rspQueryBankAccountMoneyByFuture"]        = ON_RSP_QUERY_BANK_ACCOUNT_MONEY_BY_FUTURE;
  eventMap["rtnQueryBankBalanceByFuture"]             = ON_RTN_QUERY_BANK_BALANCE_BY_FUTURE;
  eventMap["errRtnQueryBankBalanceByFuture"]          = ON_ERR_RTN_QUERY_BANK_BALANCE_BY_FUTURE;
  eventMap["rtnRepealFromBankToFutureByBank"]         = ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_BANK;
  eventMap["rtnRepealFromFutureToBankByBank"]         = ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_BANK;
  eventMap["rtnRepealFromBankToFutureByFutureManual"] = ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE_MANUAL;
  eventMap["errRtnRepealBankToFutureByFutureManual"]  = ON_ERR_RTN_REPEAL_BANK_TO_FUTURE_BY_FUTURE_MANUAL;
  eventMap["rtnRepealFromFutureToBankByFutureManual"] = ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE_MANUAL;
  eventMap["errRtnRepealFutureToBankByFutureManual"]  = ON_ERR_RTN_REPEAL_FUTURE_TO_BANK_BY_FUTURE_MANUAL;
  eventMap["rtnRepealFromBankToFutureByFuture"]       = ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE;
  eventMap["rtnRepealFromFutureToBankByFuture"]       = ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE;
  eventMap["rtnOpenAccountByBank"]                    = ON_RTN_OPEN_ACCOUNT_BY_BANK;
  eventMap["rtnCancelAccountByBank"]                  = ON_RTN_CANCEL_ACCOUNT_BY_BANK;
  eventMap["rtnChangeAccountByBank"]                  = ON_RTN_CHANGE_ACCOUNT_BY_BANK;
};
void Trader::Init(Napi::Env &env, Napi::Object &target) {
  Napi::HandleScope scope(env);
  Napi::Function ctor = DefineClass(env, "Trader",
                                    {
                                        InstanceMethod("on", &Trader::On), InstanceMethod("call", &Trader::Call),
                                    });

  constructor = Persistent(ctor);
  constructor.SuppressDestruct();
  target.Set("Trader", ctor);
};

Napi::Value Trader::On(const Napi::CallbackInfo &info) {
  if (Trader::isDebug) {
    std::cout << "[DEBUG in C++]: "
              << "Trader::On called" << std::endl;
  }
  if (!info[0].IsString()) {
    throw Napi::Error::New(info.Env(), "参数错误");
  }
  if (!info[1].IsFunction()) {
    throw Napi::Error::New(info.Env(), "参数错误");
  }
  std::string eventName = info[0].As<Napi::String>();
  std::map<std::string, int>::iterator eIt = Trader::eventMap.find(eventName);
  if (eIt == Trader::eventMap.end()) {
    throw Napi::Error::New(info.Env(), "没有被注册的事件类型");
  }
  int eventId = eIt->second;
  std::map<int, Napi::Reference<Napi::Function> *>::iterator cIt = Trader::cbMap.find(eIt->second);
  if (cIt != Trader::cbMap.end()) {
    throw Napi::Error::New(info.Env(), "此事件已经被绑定过");
  }
  Trader::cbMap[eventId] = new Napi::Reference<Napi::Function>();
  Trader::cbMap[eventId]->Reset(info[1].As<Napi::Function>(), 1);

  return info.Env().Null();
};