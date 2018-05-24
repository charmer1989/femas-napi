#ifndef TRADER_H__
#define TRADER_H__

#include "Struct.h"
#include "USTPFtdcTraderApi.h"
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

class Trader : public Napi::ObjectWrap<Trader>, public CUstpFtdcTraderSpi {
public:
  Trader(const Napi::CallbackInfo &info);
  ~Trader(void);

  uv_async_t async_t;
  static std::map<std::string, int> eventMap;
  static std::map<int, Napi::Reference<Napi::Function> *> cbMap;

  static Napi::Reference<Napi::Function> constructor;
  static void Init(Napi::Env &env, Napi::Object &target);

  Napi::Value On(const Napi::CallbackInfo &info);
  Napi::Value Call(const Napi::CallbackInfo &info);
  static void InitEventMap();

  CUstpFtdcTraderApi *api;

  static void AsyncFn(uv_work_t *req);
  static void AsyncAfterFn(uv_work_t *req);

  static bool isDebug;

  virtual void OnFrontConnected();
  virtual void OnQryFrontConnected();
  virtual void OnFrontDisconnected(int nReason);
  virtual void OnQryFrontDisconnected(int nReason);
  virtual void OnHeartBeatWarning(int nTimeLapse);
  virtual void OnPackageStart(int nTopicID, int nSequenceNo);
  virtual void OnPackageEnd(int nTopicID, int nSequenceNo);
  virtual void OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspUserLogout(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspUserPasswordUpdate(CUstpFtdcUserPasswordUpdateField *pUserPasswordUpdate, CUstpFtdcRspInfoField *pRspInfo,
                                       int nRequestID, bool bIsLast);
  virtual void OnRspSettlementInfoConfirm(CUstpFtdcInputSettlementInfoConfirmField *pInputSettlementInfoConfirm,
                                          CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspQrySettlementInfoConfirm(CUstpFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CUstpFtdcRspInfoField *pRspInfo,
                                             int nRequestID, bool bIsLast);
  virtual void OnRspOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspQuoteAction(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspForQuote(CUstpFtdcReqForQuoteField *pReqForQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction, CUstpFtdcRspInfoField *pRspInfo,
                                     int nRequestID, bool bIsLast);
  virtual void OnRspUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                bool bIsLast);
  virtual void OnRspTransferMoney(CUstpFtdcstpTransferMoneyField *pstpTransferMoney, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                  bool bIsLast);
  virtual void OnRtnFlowMessageCancel(CUstpFtdcFlowMessageCancelField *pFlowMessageCancel);
  virtual void OnRtnTrade(CUstpFtdcTradeField *pTrade);
  virtual void OnRtnOrder(CUstpFtdcOrderField *pOrder);
  virtual void OnErrRtnOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo);
  virtual void OnErrRtnOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo);
  virtual void OnRtnInstrumentStatus(CUstpFtdcInstrumentStatusField *pInstrumentStatus);
  virtual void OnRtnInvestorAccountDeposit(CUstpFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes);
  virtual void OnRtnQuote(CUstpFtdcRtnQuoteField *pRtnQuote);
  virtual void OnErrRtnQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo);
  virtual void OnErrRtnQuoteAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo);
  virtual void OnRtnForQuote(CUstpFtdcReqForQuoteField *pReqForQuote);
  virtual void OnRtnMarginCombinationLeg(CUstpFtdcMarginCombinationLegField *pMarginCombinationLeg);
  virtual void OnRtnMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction);
  virtual void OnRtnUserDeposit(CUstpFtdcstpUserDepositField *pstpUserDeposit);
  virtual void OnRspQueryUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                   bool bIsLast);
  virtual void OnRspQryOrder(CUstpFtdcOrderField *pOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspQryTrade(CUstpFtdcTradeField *pTrade, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspQryUserInvestor(CUstpFtdcRspUserInvestorField *pRspUserInvestor, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast);
  virtual void OnRspQryTradingCode(CUstpFtdcRspTradingCodeField *pRspTradingCode, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                   bool bIsLast);
  virtual void OnRspQryInvestorAccount(CUstpFtdcRspInvestorAccountField *pRspInvestorAccount, CUstpFtdcRspInfoField *pRspInfo,
                                       int nRequestID, bool bIsLast);
  virtual void OnRspQryInstrument(CUstpFtdcRspInstrumentField *pRspInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                  bool bIsLast);
  virtual void OnRspQryExchange(CUstpFtdcRspExchangeField *pRspExchange, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspQryInvestorPosition(CUstpFtdcRspInvestorPositionField *pRspInvestorPosition, CUstpFtdcRspInfoField *pRspInfo,
                                        int nRequestID, bool bIsLast);
  virtual void OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                   bool bIsLast);
  virtual void OnRspQryComplianceParam(CUstpFtdcRspComplianceParamField *pRspComplianceParam, CUstpFtdcRspInfoField *pRspInfo,
                                       int nRequestID, bool bIsLast);
  virtual void OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspQryInvestorFee(CUstpFtdcInvestorFeeField *pInvestorFee, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspQryInvestorMargin(CUstpFtdcInvestorMarginField *pInvestorMargin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                      bool bIsLast);
  virtual void OnRspQryInvestorCombPosition(CUstpFtdcRspInvestorCombPositionField *pRspInvestorCombPosition,
                                            CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspQryInvestorLegPosition(CUstpFtdcRspInvestorLegPositionField *pRspInvestorLegPosition, CUstpFtdcRspInfoField *pRspInfo,
                                           int nRequestID, bool bIsLast);
  virtual void OnRspQryInstrumentGroup(CUstpFtdcRspInstrumentGroupField *pRspInstrumentGroup, CUstpFtdcRspInfoField *pRspInfo,
                                       int nRequestID, bool bIsLast);
  virtual void OnRspQryClientMarginCombType(CUstpFtdcRspClientMarginCombTypeField *pRspClientMarginCombType,
                                            CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspQrySystemTime(CUstpFtdcRspQrySystemTimeField *pRspQrySystemTime, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                  bool bIsLast);
  virtual void OnRspCFMMCTradingAccountKey(CUstpFtdcCFMMCTradingAccountKeyRspField *pCFMMCTradingAccountKeyRsp,
                                           CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspQrySettlementInfo(CUstpFtdcSettlementRspField *pSettlementRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                      bool bIsLast);
  virtual void OnRspTradingAccountPasswordUpdate(CUstpFtdcTradingAccountPasswordUpdateRspField *pTradingAccountPasswordUpdateRsp,
                                                 CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  virtual void OnRspQryTransferBank(CUstpFtdcTransferBankQryRspField *pTransferBankQryRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID,
                                    bool bIsLast);
  virtual void OnRspQryEWarrantOffset(CUstpFtdcEWarrantOffsetFieldRspField *pEWarrantOffsetFieldRsp, CUstpFtdcRspInfoField *pRspInfo,
                                      int nRequestID, bool bIsLast);
  virtual void OnRspQryTransferSeriaOffset(CUstpFtdcTransferSerialFieldRspField *pTransferSerialFieldRsp, CUstpFtdcRspInfoField *pRspInfo,
                                           int nRequestID, bool bIsLast);
  virtual void OnRspQryAccountregister(CUstpFtdcAccountregisterRspField *pAccountregisterRsp, CUstpFtdcRspInfoField *pRspInfo,
                                       int nRequestID, bool bIsLast);
  virtual void OnRspQryContractBank(CUstpFtdcContractBankFieldRspField *pContractBankFieldRsp, CUstpFtdcRspInfoField *pRspInfo,
                                    int nRequestID, bool bIsLast);
  virtual void OnRspFromBankToFutureByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo,
                                             int nRequestID, bool bIsLast);
  virtual void OnRtnFromBankToFutureByFuture(CUstpFtdcTransferFieldRtnField *pTransferFieldRtn);
  virtual void OnErrRtnFromBankToFutureByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo);
  virtual void OnRspFromFutureToBankByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo,
                                             int nRequestID, bool bIsLast);
  virtual void OnRtnFromFutureToBankByBank(CUstpFtdcTransferFieldRtnField *pTransferFieldRtn);
  virtual void OnErrRtnFromFutureToBankByBank(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo);
  virtual void OnRtnFromBankToFutureByBank(CUstpFtdcTransferFieldRtnField *pTransferFieldRtn);
  virtual void OnRspQueryBankAccountMoneyByFuture(CUstpFtdcAccountFieldReqField *pAccountFieldReq, CUstpFtdcRspInfoField *pRspInfo,
                                                  int nRequestID, bool bIsLast);
  virtual void OnRtnQueryBankBalanceByFuture(CUstpFtdcAccountFieldRtnField *pAccountFieldRtn);
  virtual void OnErrRtnQueryBankBalanceByFuture(CUstpFtdcAccountFieldReqField *pAccountFieldReq, CUstpFtdcRspInfoField *pRspInfo);
  virtual void OnRtnRepealFromBankToFutureByBank(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn);
  virtual void OnRtnRepealFromFutureToBankByBank(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn);
  virtual void OnRtnRepealFromBankToFutureByFutureManual(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn);
  virtual void OnErrRtnRepealBankToFutureByFutureManual(CUstpFtdcRepealFieldRspField *pRepealFieldRsp, CUstpFtdcRspInfoField *pRspInfo);
  virtual void OnRtnRepealFromFutureToBankByFutureManual(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn);
  virtual void OnErrRtnRepealFutureToBankByFutureManual(CUstpFtdcRepealFieldRspField *pRepealFieldRsp, CUstpFtdcRspInfoField *pRspInfo);
  virtual void OnRtnRepealFromBankToFutureByFuture(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn);
  virtual void OnRtnRepealFromFutureToBankByFuture(CUstpFtdcRepealFieldRtnField *pRepealFieldRtn);
  virtual void OnRtnOpenAccountByBank(CUstpFtdcAccountFieldField *pAccountField);
  virtual void OnRtnCancelAccountByBank(CUstpFtdcAccountFieldField *pAccountField);
  virtual void OnRtnChangeAccountByBank(CUstpFtdcChangeAccountFieldField *pChangeAccountField);
};

struct TdCbField {
  Trader *trader;
  int errCode;
  int eventId;
  void *data;
  void *rspInfo;
  int nRequestID;
};

#endif