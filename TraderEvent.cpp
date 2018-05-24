#include "Trader.h"

void Trader::OnFrontConnected() { TD_EVENT_FUNC("OnFrontConnected", ON_FRONT_CONNECTED, 0); };
void Trader::OnQryFrontConnected() { TD_EVENT_FUNC("OnQryFrontConnected", ON_QRY_FRONT_CONNECTED, 0); };
void Trader::OnFrontDisconnected(int nReason) { TD_EVENT_FUNC("OnFrontDisconnected", ON_FRONT_DISCONNECTED, nReason); };
void Trader::OnQryFrontDisconnected(int nReason) { TD_EVENT_FUNC("OnQryFrontDisconnected", ON_QRY_FRONT_DISCONNECTED, nReason); };
void Trader::OnHeartBeatWarning(int nTimeLapse) { TD_EVENT_FUNC("OnHeartBeatWarning", ON_HEART_BEAT_WARNING, nTimeLapse); };
void Trader::OnPackageStart(int nTopicID, int nSequenceNo) { TD_EVENT_FUNC("OnPackageStart", ON_PACKAGE_START, nSequenceNo); };
void Trader::OnPackageEnd(int nTopicID, int nSequenceNo) { TD_EVENT_FUNC("OnPackageEnd", ON_PACKAGE_END, nSequenceNo); };
void Trader::OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspError called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
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
  TD_EVENT_CALL(field, ON_RSP_ERROR, 0);
};
void Trader::OnRspUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspUserLogin called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
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
  TD_EVENT_CALL(field, ON_RSP_USER_LOGIN, 0);
};
void Trader::OnRspUserLogout(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspUserLogout called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
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
  TD_EVENT_CALL(field, ON_RSP_USER_LOGOUT, 0);
};
void Trader::OnRspUserPasswordUpdate(CUstpFtdcUserPasswordUpdateField *pUserPasswordUpdate, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast) {
  TD_DEBUG_LOG("OnRspUserPasswordUpdate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pUserPasswordUpdate) {
    CUstpFtdcUserPasswordUpdateField *_info = new CUstpFtdcUserPasswordUpdateField();
    memcpy(_info, pUserPasswordUpdate, sizeof(CUstpFtdcUserPasswordUpdateField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_USER_PASSWORD_UPDATE, 0);
};
void Trader::OnRspSettlementInfoConfirm(CUstpFtdcInputSettlementInfoConfirmField *pInputSettlementInfoConfirm,
                                       CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspSettlementInfoConfirm called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputSettlementInfoConfirm) {
    CUstpFtdcInputSettlementInfoConfirmField *_info = new CUstpFtdcInputSettlementInfoConfirmField();
    memcpy(_info, pInputSettlementInfoConfirm, sizeof(CUstpFtdcInputSettlementInfoConfirmField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_SETTLEMENT_INFO_CONFIRM, 0);
};
void Trader::OnRspQrySettlementInfoConfirm(CUstpFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CUstpFtdcRspInfoField *pRspInfo,
                                          int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQrySettlementInfoConfirm called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pSettlementInfoConfirm) {
    CUstpFtdcSettlementInfoConfirmField *_info = new CUstpFtdcSettlementInfoConfirmField();
    memcpy(_info, pSettlementInfoConfirm, sizeof(CUstpFtdcSettlementInfoConfirmField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_SETTLEMENT_INFO_CONFIRM, 0);
};
void Trader::OnRspOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspOrderInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputOrder) {
    CUstpFtdcInputOrderField *_info = new CUstpFtdcInputOrderField();
    memcpy(_info, pInputOrder, sizeof(CUstpFtdcInputOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_ORDER_INSERT, 0);
};
void Trader::OnRspOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspOrderAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pOrderAction) {
    CUstpFtdcOrderActionField *_info = new CUstpFtdcOrderActionField();
    memcpy(_info, pOrderAction, sizeof(CUstpFtdcOrderActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_ORDER_ACTION, 0);
};
void Trader::OnRspQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQuoteInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputQuote) {
    CUstpFtdcInputQuoteField *_info = new CUstpFtdcInputQuoteField();
    memcpy(_info, pInputQuote, sizeof(CUstpFtdcInputQuoteField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QUOTE_INSERT, 0);
};
void Trader::OnRspQuoteAction(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQuoteAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pQuoteAction) {
    CUstpFtdcQuoteActionField *_info = new CUstpFtdcQuoteActionField();
    memcpy(_info, pQuoteAction, sizeof(CUstpFtdcQuoteActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QUOTE_ACTION, 0);
};
void Trader::OnRspForQuote(CUstpFtdcReqForQuoteField *pReqForQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspForQuote called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pReqForQuote) {
    CUstpFtdcReqForQuoteField *_info = new CUstpFtdcReqForQuoteField();
    memcpy(_info, pReqForQuote, sizeof(CUstpFtdcReqForQuoteField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_FOR_QUOTE, 0);
};
void Trader::OnRspMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction, CUstpFtdcRspInfoField *pRspInfo,
                                  int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspMarginCombAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInputMarginCombAction) {
    CUstpFtdcInputMarginCombActionField *_info = new CUstpFtdcInputMarginCombActionField();
    memcpy(_info, pInputMarginCombAction, sizeof(CUstpFtdcInputMarginCombActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_MARGIN_COMB_ACTION, 0);
};
void Trader::OnRspUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspUserDeposit called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pstpUserDeposit) {
    CUstpFtdcstpUserDepositField *_info = new CUstpFtdcstpUserDepositField();
    memcpy(_info, pstpUserDeposit, sizeof(CUstpFtdcstpUserDepositField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_USER_DEPOSIT, 0);
};
void Trader::OnRspTransferMoney(CUstpFtdcstpTransferMoneyField *pstpTransferMoney, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                               bool bIsLast) {
  TD_DEBUG_LOG("OnRspTransferMoney called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pstpTransferMoney) {
    CUstpFtdcstpTransferMoneyField *_info = new CUstpFtdcstpTransferMoneyField();
    memcpy(_info, pstpTransferMoney, sizeof(CUstpFtdcstpTransferMoneyField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_TRANSFER_MONEY, 0);
};
void Trader::OnRtnFlowMessageCancel(CUstpFtdcFlowMessageCancelField *pFlowMessageCancel) {
  TD_DEBUG_LOG("OnRtnFlowMessageCancel called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pFlowMessageCancel) {
    CUstpFtdcFlowMessageCancelField *_info = new CUstpFtdcFlowMessageCancelField();
    memcpy(_info, pFlowMessageCancel, sizeof(CUstpFtdcFlowMessageCancelField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_FLOW_MESSAGE_CANCEL, 0);
};
void Trader::OnRtnTrade(CUstpFtdcTradeField *pTrade) {
  TD_DEBUG_LOG("OnRtnTrade called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pTrade) {
    CUstpFtdcTradeField *_info = new CUstpFtdcTradeField();
    memcpy(_info, pTrade, sizeof(CUstpFtdcTradeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_TRADE, 0);
};
void Trader::OnRtnOrder(CUstpFtdcOrderField *pOrder) {
  TD_DEBUG_LOG("OnRtnOrder called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pOrder) {
    CUstpFtdcOrderField *_info = new CUstpFtdcOrderField();
    memcpy(_info, pOrder, sizeof(CUstpFtdcOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_ORDER, 0);
};
void Trader::OnErrRtnOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnOrderInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pInputOrder) {
    CUstpFtdcInputOrderField *_info = new CUstpFtdcInputOrderField();
    memcpy(_info, pInputOrder, sizeof(CUstpFtdcInputOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_ORDER_INSERT, 0);
};
void Trader::OnErrRtnOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnOrderAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pOrderAction) {
    CUstpFtdcOrderActionField *_info = new CUstpFtdcOrderActionField();
    memcpy(_info, pOrderAction, sizeof(CUstpFtdcOrderActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_ORDER_ACTION, 0);
};
void Trader::OnRtnInstrumentStatus(CUstpFtdcInstrumentStatusField *pInstrumentStatus) {
  TD_DEBUG_LOG("OnRtnInstrumentStatus called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pInstrumentStatus) {
    CUstpFtdcInstrumentStatusField *_info = new CUstpFtdcInstrumentStatusField();
    memcpy(_info, pInstrumentStatus, sizeof(CUstpFtdcInstrumentStatusField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_INSTRUMENT_STATUS, 0);
};
void Trader::OnRtnInvestorAccountDeposit(CUstpFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) {
  TD_DEBUG_LOG("OnRtnInvestorAccountDeposit called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pInvestorAccountDepositRes) {
    CUstpFtdcInvestorAccountDepositResField *_info = new CUstpFtdcInvestorAccountDepositResField();
    memcpy(_info, pInvestorAccountDepositRes, sizeof(CUstpFtdcInvestorAccountDepositResField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_INVESTOR_ACCOUNT_DEPOSIT, 0);
};
void Trader::OnRtnQuote(CUstpFtdcRtnQuoteField *pRtnQuote) {
  TD_DEBUG_LOG("OnRtnQuote called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRtnQuote) {
    CUstpFtdcRtnQuoteField *_info = new CUstpFtdcRtnQuoteField();
    memcpy(_info, pRtnQuote, sizeof(CUstpFtdcRtnQuoteField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_QUOTE, 0);
};
void Trader::OnErrRtnQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnQuoteInsert called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pInputQuote) {
    CUstpFtdcInputQuoteField *_info = new CUstpFtdcInputQuoteField();
    memcpy(_info, pInputQuote, sizeof(CUstpFtdcInputQuoteField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_QUOTE_INSERT, 0);
};
void Trader::OnErrRtnQuoteAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnQuoteAction called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pOrderAction) {
    CUstpFtdcOrderActionField *_info = new CUstpFtdcOrderActionField();
    memcpy(_info, pOrderAction, sizeof(CUstpFtdcOrderActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_QUOTE_ACTION, 0);
};
void Trader::OnRtnForQuote(CUstpFtdcReqForQuoteField *pReqForQuote) {
  TD_DEBUG_LOG("OnRtnForQuote called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pReqForQuote) {
    CUstpFtdcReqForQuoteField *_info = new CUstpFtdcReqForQuoteField();
    memcpy(_info, pReqForQuote, sizeof(CUstpFtdcReqForQuoteField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_FOR_QUOTE, 0);
};
void Trader::OnRtnMarginCombinationLeg(CUstpFtdcMarginCombinationLegField *pMarginCombinationLeg) {
  TD_DEBUG_LOG("OnRtnMarginCombinationLeg called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pMarginCombinationLeg) {
    CUstpFtdcMarginCombinationLegField *_info = new CUstpFtdcMarginCombinationLegField();
    memcpy(_info, pMarginCombinationLeg, sizeof(CUstpFtdcMarginCombinationLegField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_MARGIN_COMBINATION_LEG, 0);
};
void Trader::OnRtnMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction) {
  TD_DEBUG_LOG("OnRtnMarginCombAction called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pInputMarginCombAction) {
    CUstpFtdcInputMarginCombActionField *_info = new CUstpFtdcInputMarginCombActionField();
    memcpy(_info, pInputMarginCombAction, sizeof(CUstpFtdcInputMarginCombActionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_MARGIN_COMB_ACTION, 0);
};
void Trader::OnRtnUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit) {
  TD_DEBUG_LOG("OnRtnUserDeposit called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pstpUserDeposit) {
    CUstpFtdcstpUserDepositField *_info = new CUstpFtdcstpUserDepositField();
    memcpy(_info, pstpUserDeposit, sizeof(CUstpFtdcstpUserDepositField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_USER_DEPOSIT, 0);
};
void Trader::OnRspQueryUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQueryUserLogin called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
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
  TD_EVENT_CALL(field, ON_RSP_QUERY_USER_LOGIN, 0);
};
void Trader::OnRspQryOrder(CUstpFtdcOrderField *pOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryOrder called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pOrder) {
    CUstpFtdcOrderField *_info = new CUstpFtdcOrderField();
    memcpy(_info, pOrder, sizeof(CUstpFtdcOrderField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_ORDER, 0);
};
void Trader::OnRspQryTrade(CUstpFtdcTradeField *pTrade, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryTrade called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTrade) {
    CUstpFtdcTradeField *_info = new CUstpFtdcTradeField();
    memcpy(_info, pTrade, sizeof(CUstpFtdcTradeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_TRADE, 0);
};
void Trader::OnRspQryUserInvestor(CUstpFtdcRspUserInvestorField *pRspUserInvestor, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                 bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryUserInvestor called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspUserInvestor) {
    CUstpFtdcRspUserInvestorField *_info = new CUstpFtdcRspUserInvestorField();
    memcpy(_info, pRspUserInvestor, sizeof(CUstpFtdcRspUserInvestorField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_USER_INVESTOR, 0);
};
void Trader::OnRspQryTradingCode(CUstpFtdcRspTradingCodeField *pRspTradingCode, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryTradingCode called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspTradingCode) {
    CUstpFtdcRspTradingCodeField *_info = new CUstpFtdcRspTradingCodeField();
    memcpy(_info, pRspTradingCode, sizeof(CUstpFtdcRspTradingCodeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_TRADING_CODE, 0);
};
void Trader::OnRspQryInvestorAccount(CUstpFtdcRspInvestorAccountField *pRspInvestorAccount, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInvestorAccount called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspInvestorAccount) {
    CUstpFtdcRspInvestorAccountField *_info = new CUstpFtdcRspInvestorAccountField();
    memcpy(_info, pRspInvestorAccount, sizeof(CUstpFtdcRspInvestorAccountField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INVESTOR_ACCOUNT, 0);
};
void Trader::OnRspQryInstrument(CUstpFtdcRspInstrumentField *pRspInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInstrument called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspInstrument) {
    CUstpFtdcRspInstrumentField *_info = new CUstpFtdcRspInstrumentField();
    memcpy(_info, pRspInstrument, sizeof(CUstpFtdcRspInstrumentField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INSTRUMENT, 0);
};
void Trader::OnRspQryExchange(CUstpFtdcRspExchangeField *pRspExchange, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryExchange called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspExchange) {
    CUstpFtdcRspExchangeField *_info = new CUstpFtdcRspExchangeField();
    memcpy(_info, pRspExchange, sizeof(CUstpFtdcRspExchangeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_EXCHANGE, 0);
};
void Trader::OnRspQryInvestorPosition(CUstpFtdcRspInvestorPositionField *pRspInvestorPosition, CUstpFtdcRspInfoField *pRspInfo,
                                     int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInvestorPosition called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspInvestorPosition) {
    CUstpFtdcRspInvestorPositionField *_info = new CUstpFtdcRspInvestorPositionField();
    memcpy(_info, pRspInvestorPosition, sizeof(CUstpFtdcRspInvestorPositionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INVESTOR_POSITION, 0);
};
void Trader::OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                bool bIsLast) {
  TD_DEBUG_LOG("OnRspSubscribeTopic called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
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
  TD_EVENT_CALL(field, ON_RSP_SUBSCRIBE_TOPIC, 0);
};
void Trader::OnRspQryComplianceParam(CUstpFtdcRspComplianceParamField *pRspComplianceParam, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryComplianceParam called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspComplianceParam) {
    CUstpFtdcRspComplianceParamField *_info = new CUstpFtdcRspComplianceParamField();
    memcpy(_info, pRspComplianceParam, sizeof(CUstpFtdcRspComplianceParamField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_COMPLIANCE_PARAM, 0);
};
void Trader::OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryTopic called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
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
  TD_EVENT_CALL(field, ON_RSP_QRY_TOPIC, 0);
};
void Trader::OnRspQryInvestorFee(CUstpFtdcInvestorFeeField *pInvestorFee, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInvestorFee called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInvestorFee) {
    CUstpFtdcInvestorFeeField *_info = new CUstpFtdcInvestorFeeField();
    memcpy(_info, pInvestorFee, sizeof(CUstpFtdcInvestorFeeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INVESTOR_FEE, 0);
};
void Trader::OnRspQryInvestorMargin(CUstpFtdcInvestorMarginField *pInvestorMargin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                   bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInvestorMargin called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pInvestorMargin) {
    CUstpFtdcInvestorMarginField *_info = new CUstpFtdcInvestorMarginField();
    memcpy(_info, pInvestorMargin, sizeof(CUstpFtdcInvestorMarginField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INVESTOR_MARGIN, 0);
};
void Trader::OnRspQryInvestorCombPosition(CUstpFtdcRspInvestorCombPositionField *pRspInvestorCombPosition, CUstpFtdcRspInfoField *pRspInfo,
                                         int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInvestorCombPosition called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspInvestorCombPosition) {
    CUstpFtdcRspInvestorCombPositionField *_info = new CUstpFtdcRspInvestorCombPositionField();
    memcpy(_info, pRspInvestorCombPosition, sizeof(CUstpFtdcRspInvestorCombPositionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INVESTOR_COMB_POSITION, 0);
};
void Trader::OnRspQryInvestorLegPosition(CUstpFtdcRspInvestorLegPositionField *pRspInvestorLegPosition, CUstpFtdcRspInfoField *pRspInfo,
                                        int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInvestorLegPosition called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspInvestorLegPosition) {
    CUstpFtdcRspInvestorLegPositionField *_info = new CUstpFtdcRspInvestorLegPositionField();
    memcpy(_info, pRspInvestorLegPosition, sizeof(CUstpFtdcRspInvestorLegPositionField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INVESTOR_LEG_POSITION, 0);
};
void Trader::OnRspQryInstrumentGroup(CUstpFtdcRspInstrumentGroupField *pRspInstrumentGroup, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryInstrumentGroup called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspInstrumentGroup) {
    CUstpFtdcRspInstrumentGroupField *_info = new CUstpFtdcRspInstrumentGroupField();
    memcpy(_info, pRspInstrumentGroup, sizeof(CUstpFtdcRspInstrumentGroupField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_INSTRUMENT_GROUP, 0);
};
void Trader::OnRspQryClientMarginCombType(CUstpFtdcRspClientMarginCombTypeField *pRspClientMarginCombType, CUstpFtdcRspInfoField *pRspInfo,
                                         int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryClientMarginCombType called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspClientMarginCombType) {
    CUstpFtdcRspClientMarginCombTypeField *_info = new CUstpFtdcRspClientMarginCombTypeField();
    memcpy(_info, pRspClientMarginCombType, sizeof(CUstpFtdcRspClientMarginCombTypeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_CLIENT_MARGIN_COMB_TYPE, 0);
};
void Trader::OnRspQrySystemTime(CUstpFtdcRspQrySystemTimeField *pRspQrySystemTime, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                               bool bIsLast) {
  TD_DEBUG_LOG("OnRspQrySystemTime called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pRspQrySystemTime) {
    CUstpFtdcRspQrySystemTimeField *_info = new CUstpFtdcRspQrySystemTimeField();
    memcpy(_info, pRspQrySystemTime, sizeof(CUstpFtdcRspQrySystemTimeField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_SYSTEM_TIME, 0);
};
void Trader::OnRspCFMMCTradingAccountKey(CUstpFtdcCFMMCTradingAccountKeyRspField *pCFMMCTradingAccountKeyRsp,
                                        CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspCFMMCTradingAccountKey called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pCFMMCTradingAccountKeyRsp) {
    CUstpFtdcCFMMCTradingAccountKeyRspField *_info = new CUstpFtdcCFMMCTradingAccountKeyRspField();
    memcpy(_info, pCFMMCTradingAccountKeyRsp, sizeof(CUstpFtdcCFMMCTradingAccountKeyRspField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_CFMMC_TRADING_ACCOUNT_KEY, 0);
};
void Trader::OnRspQrySettlementInfo(CUstpFtdcSettlementRspField *pSettlementRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                   bool bIsLast) {
  TD_DEBUG_LOG("OnRspQrySettlementInfo called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pSettlementRsp) {
    CUstpFtdcSettlementRspField *_info = new CUstpFtdcSettlementRspField();
    memcpy(_info, pSettlementRsp, sizeof(CUstpFtdcSettlementRspField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_SETTLEMENT_INFO, 0);
};
void Trader::OnRspTradingAccountPasswordUpdate(CUstpFtdcTradingAccountPasswordUpdateRspField *pTradingAccountPasswordUpdateRsp,
                                              CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspTradingAccountPasswordUpdate called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTradingAccountPasswordUpdateRsp) {
    CUstpFtdcTradingAccountPasswordUpdateRspField *_info = new CUstpFtdcTradingAccountPasswordUpdateRspField();
    memcpy(_info, pTradingAccountPasswordUpdateRsp, sizeof(CUstpFtdcTradingAccountPasswordUpdateRspField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_TRADING_ACCOUNT_PASSWORD_UPDATE, 0);
};
void Trader::OnRspQryTransferBank(CUstpFtdcTransferBankQryRspField *pTransferBankQryRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                 bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryTransferBank called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTransferBankQryRsp) {
    CUstpFtdcTransferBankQryRspField *_info = new CUstpFtdcTransferBankQryRspField();
    memcpy(_info, pTransferBankQryRsp, sizeof(CUstpFtdcTransferBankQryRspField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_TRANSFER_BANK, 0);
};
void Trader::OnRspQryEWarrantOffset(CUstpFtdcEWarrantOffsetFieldRspField *pEWarrantOffsetFieldRsp, CUstpFtdcRspInfoField *pRspInfo,
                                   int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryEWarrantOffset called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pEWarrantOffsetFieldRsp) {
    CUstpFtdcEWarrantOffsetFieldRspField *_info = new CUstpFtdcEWarrantOffsetFieldRspField();
    memcpy(_info, pEWarrantOffsetFieldRsp, sizeof(CUstpFtdcEWarrantOffsetFieldRspField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_E_WARRANT_OFFSET, 0);
};
void Trader::OnRspQryTransferSeriaOffset(CUstpFtdcTransferSerialFieldRspField *pTransferSerialFieldRsp, CUstpFtdcRspInfoField *pRspInfo,
                                        int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryTransferSeriaOffset called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTransferSerialFieldRsp) {
    CUstpFtdcTransferSerialFieldRspField *_info = new CUstpFtdcTransferSerialFieldRspField();
    memcpy(_info, pTransferSerialFieldRsp, sizeof(CUstpFtdcTransferSerialFieldRspField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_TRANSFER_SERIA_OFFSET, 0);
};
void Trader::OnRspQryAccountregister(CUstpFtdcAccountregisterRspField *pAccountregisterRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryAccountregister called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pAccountregisterRsp) {
    CUstpFtdcAccountregisterRspField *_info = new CUstpFtdcAccountregisterRspField();
    memcpy(_info, pAccountregisterRsp, sizeof(CUstpFtdcAccountregisterRspField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_ACCOUNTREGISTER, 0);
};
void Trader::OnRspQryContractBank(CUstpFtdcContractBankFieldRspField *pContractBankFieldRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                 bool bIsLast) {
  TD_DEBUG_LOG("OnRspQryContractBank called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pContractBankFieldRsp) {
    CUstpFtdcContractBankFieldRspField *_info = new CUstpFtdcContractBankFieldRspField();
    memcpy(_info, pContractBankFieldRsp, sizeof(CUstpFtdcContractBankFieldRspField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QRY_CONTRACT_BANK, 0);
};
void Trader::OnRspFromBankToFutureByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo,
                                          int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspFromBankToFutureByFuture called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTransferFieldReq) {
    CUstpFtdcTransferFieldReqField *_info = new CUstpFtdcTransferFieldReqField();
    memcpy(_info, pTransferFieldReq, sizeof(CUstpFtdcTransferFieldReqField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_FROM_BANK_TO_FUTURE_BY_FUTURE, 0);
};
void Trader::OnRtnFromBankToFutureByFuture(CUstpFtdcTransferFieldRtnField *pTransferFieldRtn) {
  TD_DEBUG_LOG("OnRtnFromBankToFutureByFuture called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pTransferFieldRtn) {
    CUstpFtdcTransferFieldRtnField *_info = new CUstpFtdcTransferFieldRtnField();
    memcpy(_info, pTransferFieldRtn, sizeof(CUstpFtdcTransferFieldRtnField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE, 0);
};
void Trader::OnErrRtnFromBankToFutureByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnFromBankToFutureByFuture called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pTransferFieldReq) {
    CUstpFtdcTransferFieldReqField *_info = new CUstpFtdcTransferFieldReqField();
    memcpy(_info, pTransferFieldReq, sizeof(CUstpFtdcTransferFieldReqField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE, 0);
};
void Trader::OnRspFromFutureToBankByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo,
                                          int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspFromFutureToBankByFuture called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pTransferFieldReq) {
    CUstpFtdcTransferFieldReqField *_info = new CUstpFtdcTransferFieldReqField();
    memcpy(_info, pTransferFieldReq, sizeof(CUstpFtdcTransferFieldReqField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_FROM_FUTURE_TO_BANK_BY_FUTURE, 0);
};
void Trader::OnRtnFromFutureToBankByBank(CUstpFtdcTransferFieldRtnField *pTransferFieldRtn) {
  TD_DEBUG_LOG("OnRtnFromFutureToBankByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pTransferFieldRtn) {
    CUstpFtdcTransferFieldRtnField *_info = new CUstpFtdcTransferFieldRtnField();
    memcpy(_info, pTransferFieldRtn, sizeof(CUstpFtdcTransferFieldRtnField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_FROM_FUTURE_TO_BANK_BY_BANK, 0);
};
void Trader::OnErrRtnFromFutureToBankByBank(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnFromFutureToBankByBank called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pTransferFieldReq) {
    CUstpFtdcTransferFieldReqField *_info = new CUstpFtdcTransferFieldReqField();
    memcpy(_info, pTransferFieldReq, sizeof(CUstpFtdcTransferFieldReqField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_FROM_FUTURE_TO_BANK_BY_BANK, 0);
};
void Trader::OnRtnFromBankToFutureByBank(CUstpFtdcTransferFieldRtnField *pTransferFieldRtn) {
  TD_DEBUG_LOG("OnRtnFromBankToFutureByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pTransferFieldRtn) {
    CUstpFtdcTransferFieldRtnField *_info = new CUstpFtdcTransferFieldRtnField();
    memcpy(_info, pTransferFieldRtn, sizeof(CUstpFtdcTransferFieldRtnField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_FROM_BANK_TO_FUTURE_BY_BANK, 0);
};
void Trader::OnRspQueryBankAccountMoneyByFuture(CUstpFtdcAccountFieldReqField *pAccountFieldReq, CUstpFtdcRspInfoField *pRspInfo,
                                               int nRequestID, bool bIsLast) {
  TD_DEBUG_LOG("OnRspQueryBankAccountMoneyByFuture called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = nRequestID;
  if (pAccountFieldReq) {
    CUstpFtdcAccountFieldReqField *_info = new CUstpFtdcAccountFieldReqField();
    memcpy(_info, pAccountFieldReq, sizeof(CUstpFtdcAccountFieldReqField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RSP_QUERY_BANK_ACCOUNT_MONEY_BY_FUTURE, 0);
};
void Trader::OnRtnQueryBankBalanceByFuture(CUstpFtdcAccountFieldRtnField *pAccountFieldRtn) {
  TD_DEBUG_LOG("OnRtnQueryBankBalanceByFuture called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pAccountFieldRtn) {
    CUstpFtdcAccountFieldRtnField *_info = new CUstpFtdcAccountFieldRtnField();
    memcpy(_info, pAccountFieldRtn, sizeof(CUstpFtdcAccountFieldRtnField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_QUERY_BANK_BALANCE_BY_FUTURE, 0);
};
void Trader::OnErrRtnQueryBankBalanceByFuture(CUstpFtdcAccountFieldReqField *pAccountFieldReq, CUstpFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnQueryBankBalanceByFuture called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pAccountFieldReq) {
    CUstpFtdcAccountFieldReqField *_info = new CUstpFtdcAccountFieldReqField();
    memcpy(_info, pAccountFieldReq, sizeof(CUstpFtdcAccountFieldReqField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_QUERY_BANK_BALANCE_BY_FUTURE, 0);
};
void Trader::OnRtnRepealFromBankToFutureByBank(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn) {
  TD_DEBUG_LOG("OnRtnRepealFromBankToFutureByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRepealFieldRtn) {
    CUstpFtdcRepealFieldRtnField *_info = new CUstpFtdcRepealFieldRtnField();
    memcpy(_info, pRepealFieldRtn, sizeof(CUstpFtdcRepealFieldRtnField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_BANK, 0);
};
void Trader::OnRtnRepealFromFutureToBankByBank(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn) {
  TD_DEBUG_LOG("OnRtnRepealFromFutureToBankByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRepealFieldRtn) {
    CUstpFtdcRepealFieldRtnField *_info = new CUstpFtdcRepealFieldRtnField();
    memcpy(_info, pRepealFieldRtn, sizeof(CUstpFtdcRepealFieldRtnField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_BANK, 0);
};
void Trader::OnRtnRepealFromBankToFutureByFutureManual(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn) {
  TD_DEBUG_LOG("OnRtnRepealFromBankToFutureByFutureManual called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRepealFieldRtn) {
    CUstpFtdcRepealFieldRtnField *_info = new CUstpFtdcRepealFieldRtnField();
    memcpy(_info, pRepealFieldRtn, sizeof(CUstpFtdcRepealFieldRtnField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE_MANUAL, 0);
};
void Trader::OnErrRtnRepealBankToFutureByFutureManual(CUstpFtdcRepealFieldRspField *pRepealFieldRsp, CUstpFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnRepealBankToFutureByFutureManual called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pRepealFieldRsp) {
    CUstpFtdcRepealFieldRspField *_info = new CUstpFtdcRepealFieldRspField();
    memcpy(_info, pRepealFieldRsp, sizeof(CUstpFtdcRepealFieldRspField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_REPEAL_BANK_TO_FUTURE_BY_FUTURE_MANUAL, 0);
};
void Trader::OnRtnRepealFromFutureToBankByFutureManual(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn) {
  TD_DEBUG_LOG("OnRtnRepealFromFutureToBankByFutureManual called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRepealFieldRtn) {
    CUstpFtdcRepealFieldRtnField *_info = new CUstpFtdcRepealFieldRtnField();
    memcpy(_info, pRepealFieldRtn, sizeof(CUstpFtdcRepealFieldRtnField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE_MANUAL, 0);
};
void Trader::OnErrRtnRepealFutureToBankByFutureManual(CUstpFtdcRepealFieldRspField *pRepealFieldRsp, CUstpFtdcRspInfoField *pRspInfo) {
  TD_DEBUG_LOG("OnErrRtnRepealFutureToBankByFutureManual called.");
  TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req   = new uv_work_t;
  if (pRspInfo) {
    CUstpFtdcRspInfoField *_pRspInfo = new CUstpFtdcRspInfoField();
    memcpy(_pRspInfo, pRspInfo, sizeof(CUstpFtdcRspInfoField));
    field->rspInfo = _pRspInfo;
  } else {
    field->rspInfo = nullptr;
  }
  field->nRequestID = -1;
  if (pRepealFieldRsp) {
    CUstpFtdcRepealFieldRspField *_info = new CUstpFtdcRepealFieldRspField();
    memcpy(_info, pRepealFieldRsp, sizeof(CUstpFtdcRepealFieldRspField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_ERR_RTN_REPEAL_FUTURE_TO_BANK_BY_FUTURE_MANUAL, 0);
};
void Trader::OnRtnRepealFromBankToFutureByFuture(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn) {
  TD_DEBUG_LOG("OnRtnRepealFromBankToFutureByFuture called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRepealFieldRtn) {
    CUstpFtdcRepealFieldRtnField *_info = new CUstpFtdcRepealFieldRtnField();
    memcpy(_info, pRepealFieldRtn, sizeof(CUstpFtdcRepealFieldRtnField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE, 0);
};
void Trader::OnRtnRepealFromFutureToBankByFuture(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn) {
  TD_DEBUG_LOG("OnRtnRepealFromFutureToBankByFuture called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pRepealFieldRtn) {
    CUstpFtdcRepealFieldRtnField *_info = new CUstpFtdcRepealFieldRtnField();
    memcpy(_info, pRepealFieldRtn, sizeof(CUstpFtdcRepealFieldRtnField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE, 0);
};
void Trader::OnRtnOpenAccountByBank(CUstpFtdcAccountFieldField *pAccountField) {
  TD_DEBUG_LOG("OnRtnOpenAccountByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pAccountField) {
    CUstpFtdcAccountFieldField *_info = new CUstpFtdcAccountFieldField();
    memcpy(_info, pAccountField, sizeof(CUstpFtdcAccountFieldField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_OPEN_ACCOUNT_BY_BANK, 0);
};
void Trader::OnRtnCancelAccountByBank(CUstpFtdcAccountFieldField *pAccountField) {
  TD_DEBUG_LOG("OnRtnCancelAccountByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pAccountField) {
    CUstpFtdcAccountFieldField *_info = new CUstpFtdcAccountFieldField();
    memcpy(_info, pAccountField, sizeof(CUstpFtdcAccountFieldField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_CANCEL_ACCOUNT_BY_BANK, 0);
};
void Trader::OnRtnChangeAccountByBank(CUstpFtdcChangeAccountFieldField *pChangeAccountField) {
  TD_DEBUG_LOG("OnRtnChangeAccountByBank called.");
  TdCbField *field  = (TdCbField *)malloc(sizeof(TdCbField));
  uv_work_t *req    = new uv_work_t;
  field->rspInfo    = nullptr;
  field->nRequestID = -1;
  if (pChangeAccountField) {
    CUstpFtdcChangeAccountFieldField *_info = new CUstpFtdcChangeAccountFieldField();
    memcpy(_info, pChangeAccountField, sizeof(CUstpFtdcChangeAccountFieldField));
    field->data = _info;
  } else {
    field->data = nullptr;
  }
  TD_EVENT_CALL(field, ON_RTN_CHANGE_ACCOUNT_BY_BANK, 0);
};
