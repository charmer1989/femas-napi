#include "Mduser.h"

void Mduser::AsyncFn(uv_work_t *req){};

void Mduser::AsyncAfterFn(uv_work_t *req) {
  if (Mduser::isDebug) {
    std::cout << "[DEBUG in C++]: "
              << "AsyncAfterFn called." << std::endl;
  }
  MdCbField *field = (MdCbField *)req->data;
  int eventId      = field->eventId;
  Napi::Env env    = field->mduser->Env();
  Napi::HandleScope scope(env);
  Napi::Object obj = Napi::Object::New(env);

  if (eventId == ON_FRONT_CONNECTED) {
  } else if (eventId == ON_FRONT_DISCONNECTED) {
    SET_PROPERTY_NUMBER(env, obj, "ErrorCode", field->errCode);
  } else if (eventId == ON_HEART_BEAT_WARNING) {
    SET_PROPERTY_NUMBER(env, obj, "ErrorCode", field->errCode);
  } else if (eventId == ON_PACKAGE_START) {
    SET_PROPERTY_NUMBER(env, obj, "nSequenceNo", field->errCode);
  } else if (eventId == ON_PACKAGE_END) {
    SET_PROPERTY_NUMBER(env, obj, "nSequenceNo", field->errCode);
  } else if (eventId == ON_RSP_ERROR) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_USER_LOGIN) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspUserLoginField *info = static_cast<CUstpFtdcRspUserLoginField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
      SET_PROPERTY_STRING(env, obj, "LoginTime", info->LoginTime);
      SET_PROPERTY_STRING(env, obj, "ExchangeTime", info->ExchangeTime);
      SET_PROPERTY_STRING(env, obj, "MaxOrderLocalID", info->MaxOrderLocalID);
      SET_PROPERTY_BUFFER(env, obj, "TradingSystemName", info->TradingSystemName);
      SET_PROPERTY_NUMBER(env, obj, "DataCenterID", info->DataCenterID);
      SET_PROPERTY_NUMBER(env, obj, "PrivateFlowSize", info->PrivateFlowSize);
      SET_PROPERTY_NUMBER(env, obj, "UserFlowSize", info->UserFlowSize);
      SET_PROPERTY_STRING(env, obj, "ActionDay", info->ActionDay);
      SET_PROPERTY_STRING(env, obj, "FemasVersion", info->FemasVersion);
      SET_PROPERTY_NUMBER(env, obj, "FemasLifeCycle", info->FemasLifeCycle);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_USER_LOGOUT) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspUserLogoutField *info = static_cast<CUstpFtdcRspUserLogoutField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "BrokerID", info->BrokerID);
      SET_PROPERTY_STRING(env, obj, "UserID", info->UserID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_SUBSCRIBE_TOPIC) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcDisseminationField *info = static_cast<CUstpFtdcDisseminationField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "SequenceSeries", info->SequenceSeries);
      SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_QRY_TOPIC) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcDisseminationField *info = static_cast<CUstpFtdcDisseminationField *>(field->data);
      SET_PROPERTY_NUMBER(env, obj, "SequenceSeries", info->SequenceSeries);
      SET_PROPERTY_NUMBER(env, obj, "SequenceNo", info->SequenceNo);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RTN_DEPTH_MARKET_DATA) {
    if (!!field->data) {
      CUstpFtdcDepthMarketDataField *info = static_cast<CUstpFtdcDepthMarketDataField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "TradingDay", info->TradingDay);
      SET_PROPERTY_STRING(env, obj, "SettlementGroupID", info->SettlementGroupID);
      SET_PROPERTY_NUMBER(env, obj, "SettlementID", info->SettlementID);
      SET_PROPERTY_NUMBER(env, obj, "PreSettlementPrice", info->PreSettlementPrice);
      SET_PROPERTY_NUMBER(env, obj, "PreClosePrice", info->PreClosePrice);
      SET_PROPERTY_NUMBER(env, obj, "PreOpenInterest", info->PreOpenInterest);
      SET_PROPERTY_NUMBER(env, obj, "PreDelta", info->PreDelta);
      SET_PROPERTY_NUMBER(env, obj, "OpenPrice", info->OpenPrice);
      SET_PROPERTY_NUMBER(env, obj, "HighestPrice", info->HighestPrice);
      SET_PROPERTY_NUMBER(env, obj, "LowestPrice", info->LowestPrice);
      SET_PROPERTY_NUMBER(env, obj, "ClosePrice", info->ClosePrice);
      SET_PROPERTY_NUMBER(env, obj, "UpperLimitPrice", info->UpperLimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "LowerLimitPrice", info->LowerLimitPrice);
      SET_PROPERTY_NUMBER(env, obj, "SettlementPrice", info->SettlementPrice);
      SET_PROPERTY_NUMBER(env, obj, "CurrDelta", info->CurrDelta);
      SET_PROPERTY_NUMBER(env, obj, "LastPrice", info->LastPrice);
      SET_PROPERTY_NUMBER(env, obj, "Volume", info->Volume);
      SET_PROPERTY_NUMBER(env, obj, "Turnover", info->Turnover);
      SET_PROPERTY_NUMBER(env, obj, "OpenInterest", info->OpenInterest);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
      SET_PROPERTY_STRING(env, obj, "UpdateTime", info->UpdateTime);
      SET_PROPERTY_NUMBER(env, obj, "UpdateMillisec", info->UpdateMillisec);
      SET_PROPERTY_STRING(env, obj, "ActionDay", info->ActionDay);
      SET_PROPERTY_NUMBER(env, obj, "HisHighestPrice", info->HisHighestPrice);
      SET_PROPERTY_NUMBER(env, obj, "HisLowestPrice", info->HisLowestPrice);
      SET_PROPERTY_NUMBER(env, obj, "LatestVolume", info->LatestVolume);
      SET_PROPERTY_NUMBER(env, obj, "InitVolume", info->InitVolume);
      SET_PROPERTY_NUMBER(env, obj, "ChangeVolume", info->ChangeVolume);
      SET_PROPERTY_NUMBER(env, obj, "BidImplyVolume", info->BidImplyVolume);
      SET_PROPERTY_NUMBER(env, obj, "AskImplyVolume", info->AskImplyVolume);
      SET_PROPERTY_NUMBER(env, obj, "AvgPrice", info->AvgPrice);
      SET_PROPERTY_BUFFER(env, obj, "InstrumentName", info->InstrumentName);
      SET_PROPERTY_NUMBER(env, obj, "TotalBidVolume", info->TotalBidVolume);
      SET_PROPERTY_NUMBER(env, obj, "TotalAskVolume", info->TotalAskVolume);
    };
  } else if (eventId == ON_RSP_SUB_MARKET_DATA) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcSpecificInstrumentField *info = static_cast<CUstpFtdcSpecificInstrumentField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_UN_SUB_MARKET_DATA) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcSpecificInstrumentField *info = static_cast<CUstpFtdcSpecificInstrumentField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "InstrumentID", info->InstrumentID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  } else if (eventId == ON_RSP_GET_MARKET_TOPIC) {
    if (!!field->rspInfo) {
      CUstpFtdcRspInfoField *rspInfo = static_cast<CUstpFtdcRspInfoField *>(field->rspInfo);
      SET_PROPERTY_BUFFER(env, obj, "ErrorMsg", rspInfo->ErrorMsg);
      SET_PROPERTY_NUMBER(env, obj, "ErrorID", rspInfo->ErrorID);
    }
    if (!!field->data) {
      CUstpFtdcRspMarketTopicField *info = static_cast<CUstpFtdcRspMarketTopicField *>(field->data);
      SET_PROPERTY_STRING(env, obj, "ExchangeID", info->ExchangeID);
      SET_PROPERTY_NUMBER(env, obj, "TopicID", info->TopicID);
    };
    SET_PROPERTY_NUMBER(env, obj, "nRequestID", field->nRequestID);
  }

  if (cbMap.find(eventId) != cbMap.end()) {
    cbMap.find(eventId)->second->Value().Call({env.Null(), obj});
  }

  // delete req->data;
  delete req;
};