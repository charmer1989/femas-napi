#ifndef MDUSER_H__
#define MDUSER_H__

#include "Struct.h"
#include "USTPFtdcMduserApi.h"
#include "USTPFtdcUserApiDataType.h"
#include "USTPFtdcUserApiStruct.h"
#include "napi.h"
#include <iostream>
#include <map>
#include <string.h>
#include <uv.h>

std::string getString(Napi::Object params, std::string key);
double getNumber(Napi::Object params, std::string key);
char getChar(Napi::Object params, std::string key);

class Mduser : public Napi::ObjectWrap<Mduser>, public CUstpFtdcMduserSpi {
public:
  Mduser(const Napi::CallbackInfo &info);
  ~Mduser(void);

  uv_async_t async_t;
  static std::map<std::string, int> eventMap;
  static std::map<int, Napi::Reference<Napi::Function> *> cbMap;

  static Napi::Reference<Napi::Function> constructor;
  static void Init(Napi::Env &env, Napi::Object &target);

  Napi::Value On(const Napi::CallbackInfo &info);
  Napi::Value Call(const Napi::CallbackInfo &info);
  static void InitEventMap();

  CUstpFtdcMduserApi *api;

  static void AsyncFn(uv_work_t *req);
  static void AsyncAfterFn(uv_work_t *req);

  static bool isDebug;

  ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
  virtual void OnFrontConnected();
  ///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
  virtual void OnFrontDisconnected(int nReason);
  ///心跳超时警告。当长时间未收到报文时，该方法被调用。
  ///@param nTimeLapse 距离上次接收报文的时间
  virtual void OnHeartBeatWarning(int nTimeLapse);
  ///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
  virtual void OnPackageStart(int nTopicID, int nSequenceNo);
  ///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
  virtual void OnPackageEnd(int nTopicID, int nSequenceNo);
  ///错误应答
  virtual void OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  ///风控前置系统用户登录应答
  virtual void OnRspUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  ///用户退出应答
  virtual void OnRspUserLogout(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  ///订阅主题应答
  virtual void OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                   bool bIsLast);
  ///主题查询应答
  virtual void OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  ///深度行情通知
  virtual void OnRtnDepthMarketData(CUstpFtdcDepthMarketDataField *pDepthMarketData);
  ///订阅合约的相关信息
  virtual void OnRspSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                  bool bIsLast);
  ///退订合约的相关信息
  virtual void OnRspUnSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast);
	///获取行情主题信息应答
	virtual void OnRspGetMarketTopic(CUstpFtdcRspMarketTopicField *pRspMarketTopic, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
};

struct MdCbField {
  Mduser *mduser;
  int errCode;
  int eventId;
  void *data;
  void *rspInfo;
  int nRequestID;
};

#endif