#include "Mduser.h"

int MdReqID = 1;

Napi::Value Mduser::Call(const Napi::CallbackInfo &info) {
  if (Mduser::isDebug) {
    std::cout << "[DEBUG in C++]: "
              << "Mduser::Call called" << std::endl;
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
    MD_DEBUG_LOG("call function connect begin");
    this->api = CUstpFtdcMduserApi::CreateFtdcMduserApi("");
    char address[50];
    strcpy(address, getString(params, "IP").c_str());
    this->api->RegisterSpi(this);
    if (getString(params, "RESUME_TYPE") == "RESTART") {
      this->api->SubscribeMarketDataTopic(100, USTP_TERT_RESTART);
    } else if (getString(params, "RESUME_TYPE") == "QUICK") {
      this->api->SubscribeMarketDataTopic(100, USTP_TERT_QUICK);
    } else {
      this->api->SubscribeMarketDataTopic(100, USTP_TERT_RESUME);
    }
    this->api->RegisterFront(address);
    this->api->Init();
    MD_DEBUG_LOG("call function connect done!!!");

  } else if (funcName == "subMarketData") {
    MD_DEBUG_LOG("call function subMarketData!");
    char param[50];
    strcpy(param, getString(params, "InstrumentID").c_str());
    char *args[1] = {param};
    int ret       = this->api->SubMarketData(args, 1);
    return Napi::Number::New(info.Env(), ret);

  } else if (funcName == "unSubMarketData") {
    MD_DEBUG_LOG("call function unSubMarketData!");
    char param[50];
    strcpy(param, getString(params, "InstrumentID").c_str());
    char *args[1] = {param};
    int ret       = this->api->UnSubMarketData(args, 1);
    return Napi::Number::New(info.Env(), ret);

  } else if (funcName == "getMarketTopic") {
    MD_DEBUG_LOG("call function getMarketTopic!");
    char *param;
    strcpy(param, getString(params, "ExchangeID").c_str());
    int ret = this->api->GetMarketTopic(param);
    return Napi::Number::New(info.Env(), ret);

  } else if (funcName == "subscribeMarketDataTopic") {
    MD_DEBUG_LOG("call function subscribeMarketDataTopic");
    MdReqID++;
    // int ret = this->api->SubscribeMarketDataTopic();
    return Napi::Number::New(info.Env(), 0);
  } else if (funcName == "setHeartbeatTimeout") {
    MD_DEBUG_LOG("call function setHeartbeatTimeout");
    MdReqID++;
    // int ret = this->api->SetHeartbeatTimeout();
    return Napi::Number::New(info.Env(), 0);
  } else if (funcName == "reqUserLogin") {
    MD_DEBUG_LOG("call function reqUserLogin");
    MdReqID++;
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
    int ret                 = this->api->ReqUserLogin(&req, MdReqID);
    return Napi::Number::New(info.Env(), 0);
  } else if (funcName == "reqUserLogout") {
    MD_DEBUG_LOG("call function reqUserLogout");
    MdReqID++;
    CUstpFtdcReqUserLogoutField req;
    memset(&req, 0, sizeof(CUstpFtdcReqUserLogoutField));
    strcpy(req.BrokerID, getString(params, "BrokerID").c_str());
    strcpy(req.UserID, getString(params, "UserID").c_str());
    int ret = this->api->ReqUserLogout(&req, MdReqID);
    return Napi::Number::New(info.Env(), 0);
  } else if (funcName == "reqSubscribeTopic") {
    MD_DEBUG_LOG("call function reqSubscribeTopic");
    MdReqID++;
    CUstpFtdcDisseminationField req;
    memset(&req, 0, sizeof(CUstpFtdcDisseminationField));
    req.SequenceSeries = getNumber(params, "SequenceSeries");
    req.SequenceNo     = getNumber(params, "SequenceNo");
    int ret            = this->api->ReqSubscribeTopic(&req, MdReqID);
    return Napi::Number::New(info.Env(), 0);
  } else if (funcName == "reqQryTopic") {
    MD_DEBUG_LOG("call function reqQryTopic");
    MdReqID++;
    CUstpFtdcDisseminationField req;
    memset(&req, 0, sizeof(CUstpFtdcDisseminationField));
    req.SequenceSeries = getNumber(params, "SequenceSeries");
    req.SequenceNo     = getNumber(params, "SequenceNo");
    int ret            = this->api->ReqQryTopic(&req, MdReqID);
    return Napi::Number::New(info.Env(), 0);
  } else if (funcName == "reqSubMarketData") {
    MD_DEBUG_LOG("call function reqSubMarketData");
    MdReqID++;
    CUstpFtdcSpecificInstrumentField req;
    memset(&req, 0, sizeof(CUstpFtdcSpecificInstrumentField));
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    int ret = this->api->ReqSubMarketData(&req, MdReqID);
    return Napi::Number::New(info.Env(), 0);
  } else if (funcName == "reqUnSubMarketData") {
    MD_DEBUG_LOG("call function reqUnSubMarketData");
    MdReqID++;
    CUstpFtdcSpecificInstrumentField req;
    memset(&req, 0, sizeof(CUstpFtdcSpecificInstrumentField));
    strcpy(req.InstrumentID, getString(params, "InstrumentID").c_str());
    int ret = this->api->ReqUnSubMarketData(&req, MdReqID);
    return Napi::Number::New(info.Env(), 0);
  } else {
    return Napi::Number::New(info.Env(), NONE_TRADER_API_FUNC);
  }

  return Napi::Number::New(info.Env(), STATUS_SUCCESS);
}