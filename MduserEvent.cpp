#include "Mduser.h"

void Mduser::OnFrontConnected() { MD_EVENT_FUNC("OnFrontConnected", ON_FRONT_CONNECTED, 0); };
void Mduser::OnFrontDisconnected(int nReason) { MD_EVENT_FUNC("OnFrontDisconnected", ON_FRONT_DISCONNECTED, nReason); };
void Mduser::OnHeartBeatWarning(int nTimeLapse) { MD_EVENT_FUNC("OnHeartBeatWarning", ON_HEART_BEAT_WARNING, nTimeLapse); };
void Mduser::OnPackageStart(int nTopicID, int nSequenceNo) { /*MD_EVENT_FUNC("OnPackageStart", ON_PACKAGE_START, nSequenceNo);*/ };
void Mduser::OnPackageEnd(int nTopicID, int nSequenceNo) { /*MD_EVENT_FUNC("OnPackageEnd", ON_PACKAGE_END, nSequenceNo);*/ };

void Mduser::OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  MD_DEBUG_LOG("OnRspError called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  field->data       = nullptr;
  MD_EVENT_CALL(field, ON_RSP_ERROR, 0);
};
void Mduser::OnRspUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  MD_DEBUG_LOG("OnRspUserLogin called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspUserLogin) {
    CUstpFtdcRspUserLoginField *_info = new CUstpFtdcRspUserLoginField();
    memcpy(_info, pRspUserLogin, sizeof(CUstpFtdcRspUserLoginField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_USER_LOGIN, 0);
};
void Mduser::OnRspUserLogout(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  MD_DEBUG_LOG("OnRspUserLogout called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspUserLogout) {
    CUstpFtdcRspUserLogoutField *_info = new CUstpFtdcRspUserLogoutField();
    memcpy(_info, pRspUserLogout, sizeof(CUstpFtdcRspUserLogoutField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_USER_LOGOUT, 0);
};
void Mduser::OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                 bool bIsLast) {
  MD_DEBUG_LOG("OnRspSubscribeTopic called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pDissemination) {
    CUstpFtdcDisseminationField *_info = new CUstpFtdcDisseminationField();
    memcpy(_info, pDissemination, sizeof(CUstpFtdcDisseminationField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_SUBSCRIBE_TOPIC, 0);
};
void Mduser::OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  MD_DEBUG_LOG("OnRspQryTopic called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pDissemination) {
    CUstpFtdcDisseminationField *_info = new CUstpFtdcDisseminationField();
    memcpy(_info, pDissemination, sizeof(CUstpFtdcDisseminationField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_QRY_TOPIC, 0);
};
void Mduser::OnRtnDepthMarketData(CUstpFtdcDepthMarketDataField *pDepthMarketData) {
  MD_DEBUG_LOG("OnRtnDepthMarketData called.");
  MdCbField *field  = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pDepthMarketData) {
    CUstpFtdcDepthMarketDataField *_info = new CUstpFtdcDepthMarketDataField();
    memcpy(_info, pDepthMarketData, sizeof(CUstpFtdcDepthMarketDataField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RTN_DEPTH_MARKET_DATA, 0);
};
void Mduser::OnRspSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                bool bIsLast) {
  MD_DEBUG_LOG("OnRspSubMarketData called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pSpecificInstrument) {
    CUstpFtdcSpecificInstrumentField *_info = new CUstpFtdcSpecificInstrumentField();
    memcpy(_info, pSpecificInstrument, sizeof(CUstpFtdcSpecificInstrumentField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_SUB_MARKET_DATA, 0);
};
void Mduser::OnRspUnSubMarketData(CUstpFtdcSpecificInstrumentField *pSpecificInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                  bool bIsLast) {
  MD_DEBUG_LOG("OnRspUnSubMarketData called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pSpecificInstrument) {
    CUstpFtdcSpecificInstrumentField *_info = new CUstpFtdcSpecificInstrumentField();
    memcpy(_info, pSpecificInstrument, sizeof(CUstpFtdcSpecificInstrumentField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_UN_SUB_MARKET_DATA, 0);
};
void Mduser::OnRspGetMarketTopic(CUstpFtdcRspMarketTopicField *pRspMarketTopic, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                 bool bIsLast) {
  MD_DEBUG_LOG("OnRspGetMarketTopic called.");
  MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspMarketTopic) {
    CUstpFtdcRspMarketTopicField *_info = new CUstpFtdcRspMarketTopicField();
    memcpy(_info, pRspMarketTopic, sizeof(CUstpFtdcRspMarketTopicField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  MD_EVENT_CALL(field, ON_RSP_GET_MARKET_TOPIC, 0);
};
