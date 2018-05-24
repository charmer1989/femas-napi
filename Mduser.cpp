#include "Mduser.h"

Napi::Reference<Napi::Function> Mduser::constructor;
std::map<std::string, int> Mduser::eventMap;
std::map<int, Napi::Reference<Napi::Function> *> Mduser::cbMap;
bool Mduser::isDebug = false;

// std::string getString(Napi::Object params, std::string key) {
//   if (params.Get(key).IsUndefined()) {
//     std::string space("");
//     return space;
//   }
//   return params.Get(key).As<Napi::String>().Utf8Value();
// };

// double getNumber(Napi::Object params, std::string key) {
//   if (params.Get(key).IsUndefined()) {
//     return 0;
//   }
//   return (double)(params.Get(key).As<Napi::Number>());
// };

// char getChar(Napi::Object params, std::string key) {
//   if (params.Get(key).IsUndefined()) {
//     return '\0';
//   }
//   std::string str = params.Get(key).As<Napi::String>().Utf8Value();
//   return str.c_str()[0];
// };

// double roundFunc(double x, int n) { return round(x * pow(10, n)) / pow(10, n); };

Mduser::Mduser(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Mduser>(info) {
  if (info[0].IsObject()) {
    Napi::Object obj = info[0].As<Napi::Object>();
    bool _isDebug    = obj.Get("debug").ToBoolean();
    Mduser::isDebug  = _isDebug;
  } else {
    Mduser::isDebug = false;
  }
  Mduser::InitEventMap();
  uv_async_init(uv_default_loop(), &async_t, NULL);
}
Mduser::~Mduser(void){};

void Mduser::InitEventMap() {
  eventMap["frontConnected"]     = ON_FRONT_CONNECTED;
  eventMap["frontDisconnected"]  = ON_FRONT_DISCONNECTED;
  eventMap["heartBeatWarning"]   = ON_HEART_BEAT_WARNING;
  eventMap["packageStart"]       = ON_PACKAGE_START;
  eventMap["packageEnd"]         = ON_PACKAGE_END;
  eventMap["rspError"]           = ON_RSP_ERROR;
  eventMap["rspUserLogin"]       = ON_RSP_USER_LOGIN;
  eventMap["rspUserLogout"]      = ON_RSP_USER_LOGOUT;
  eventMap["rspSubscribeTopic"]  = ON_RSP_SUBSCRIBE_TOPIC;
  eventMap["rspQryTopic"]        = ON_RSP_QRY_TOPIC;
  eventMap["rtnDepthMarketData"] = ON_RTN_DEPTH_MARKET_DATA;
  eventMap["rspSubMarketData"]   = ON_RSP_SUB_MARKET_DATA;
  eventMap["rspUnSubMarketData"] = ON_RSP_UN_SUB_MARKET_DATA;
  eventMap["rspGetMarketTopic"]  = ON_RSP_GET_MARKET_TOPIC;
};
void Mduser::Init(Napi::Env &env, Napi::Object &target) {
  Napi::HandleScope scope(env);
  Napi::Function ctor = DefineClass(env, "Mduser",
                                    {
                                        InstanceMethod("on", &Mduser::On), InstanceMethod("call", &Mduser::Call),
                                    });

  constructor = Persistent(ctor);
  constructor.SuppressDestruct();
  target.Set("Mduser", ctor);
};

Napi::Value Mduser::On(const Napi::CallbackInfo &info) {
  if (Mduser::isDebug) {
    std::cout << "[DEBUG in C++]: "
              << "Mduser::On called" << std::endl;
  }
  if (!info[0].IsString()) {
    throw Napi::Error::New(info.Env(), "参数错误");
  }
  if (!info[1].IsFunction()) {
    throw Napi::Error::New(info.Env(), "参数错误");
  }
  std::string eventName = info[0].As<Napi::String>();
  std::map<std::string, int>::iterator eIt = Mduser::eventMap.find(eventName);
  if (eIt == Mduser::eventMap.end()) {
    throw Napi::Error::New(info.Env(), "没有被注册的事件类型");
  }
  int eventId = eIt->second;
  std::map<int, Napi::Reference<Napi::Function> *>::iterator cIt = Mduser::cbMap.find(eIt->second);
  if (cIt != Mduser::cbMap.end()) {
    throw Napi::Error::New(info.Env(), "此事件已经被绑定过");
  }
  Mduser::cbMap[eventId] = new Napi::Reference<Napi::Function>();
  Mduser::cbMap[eventId]->Reset(info[1].As<Napi::Function>(), 1);

  return info.Env().Null();
};
