#ifndef _WRAPER_STRUCT_
#define _WRAPER_STRUCT_

#include <math.h>
double roundFunc(double x, int n);

///// 外部使用
#define ON_FRONT_CONNECTED 1001
#define ON_QRY_FRONT_CONNECTED 1002
#define ON_FRONT_DISCONNECTED 1003
#define ON_QRY_FRONT_DISCONNECTED 1004
#define ON_HEART_BEAT_WARNING 1005
#define ON_PACKAGE_START 1006
#define ON_PACKAGE_END 1007
#define ON_RSP_ERROR 1008
#define ON_RSP_USER_LOGIN 1009
#define ON_RSP_USER_LOGOUT 1010
#define ON_RSP_USER_PASSWORD_UPDATE 1011
#define ON_RSP_SETTLEMENT_INFO_CONFIRM 1012
#define ON_RSP_QRY_SETTLEMENT_INFO_CONFIRM 1013
#define ON_RSP_ORDER_INSERT 1014
#define ON_RSP_ORDER_ACTION 1015
#define ON_RSP_QUOTE_INSERT 1016
#define ON_RSP_QUOTE_ACTION 1017
#define ON_RSP_FOR_QUOTE 1018
#define ON_RSP_MARGIN_COMB_ACTION 1019
#define ON_RSP_USER_DEPOSIT 1020
#define ON_RSP_TRANSFER_MONEY 1021
#define ON_RTN_FLOW_MESSAGE_CANCEL 1022
#define ON_RTN_TRADE 1023
#define ON_RTN_ORDER 1024
#define ON_ERR_RTN_ORDER_INSERT 1025
#define ON_ERR_RTN_ORDER_ACTION 1026
#define ON_RTN_INSTRUMENT_STATUS 1027
#define ON_RTN_INVESTOR_ACCOUNT_DEPOSIT 1028
#define ON_RTN_QUOTE 1029
#define ON_ERR_RTN_QUOTE_INSERT 1030
#define ON_ERR_RTN_QUOTE_ACTION 1031
#define ON_RTN_FOR_QUOTE 1032
#define ON_RTN_MARGIN_COMBINATION_LEG 1033
#define ON_RTN_MARGIN_COMB_ACTION 1034
#define ON_RTN_USER_DEPOSIT 1035
#define ON_RSP_QUERY_USER_LOGIN 1036
#define ON_RSP_QRY_ORDER 1037
#define ON_RSP_QRY_TRADE 1038
#define ON_RSP_QRY_USER_INVESTOR 1039
#define ON_RSP_QRY_TRADING_CODE 1040
#define ON_RSP_QRY_INVESTOR_ACCOUNT 1041
#define ON_RSP_QRY_INSTRUMENT 1042
#define ON_RSP_QRY_EXCHANGE 1043
#define ON_RSP_QRY_INVESTOR_POSITION 1044
#define ON_RSP_SUBSCRIBE_TOPIC 1045
#define ON_RSP_QRY_COMPLIANCE_PARAM 1046
#define ON_RSP_QRY_TOPIC 1047
#define ON_RSP_QRY_INVESTOR_FEE 1048
#define ON_RSP_QRY_INVESTOR_MARGIN 1049
#define ON_RSP_QRY_INVESTOR_COMB_POSITION 1050
#define ON_RSP_QRY_INVESTOR_LEG_POSITION 1051
#define ON_RSP_QRY_INSTRUMENT_GROUP 1052
#define ON_RSP_QRY_CLIENT_MARGIN_COMB_TYPE 1053
#define ON_RSP_QRY_SYSTEM_TIME 1054
#define ON_RSP_CFMMC_TRADING_ACCOUNT_KEY 1055
#define ON_RSP_QRY_SETTLEMENT_INFO 1056
#define ON_RSP_TRADING_ACCOUNT_PASSWORD_UPDATE 1057
#define ON_RSP_QRY_TRANSFER_BANK 1058
#define ON_RSP_QRY_E_WARRANT_OFFSET 1059
#define ON_RSP_QRY_TRANSFER_SERIA_OFFSET 1060
#define ON_RSP_QRY_ACCOUNTREGISTER 1061
#define ON_RSP_QRY_CONTRACT_BANK 1062
#define ON_RSP_FROM_BANK_TO_FUTURE_BY_FUTURE 1063
#define ON_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE 1064
#define ON_ERR_RTN_FROM_BANK_TO_FUTURE_BY_FUTURE 1065
#define ON_RSP_FROM_FUTURE_TO_BANK_BY_FUTURE 1066
#define ON_RTN_FROM_FUTURE_TO_BANK_BY_BANK 1067
#define ON_ERR_RTN_FROM_FUTURE_TO_BANK_BY_BANK 1068
#define ON_RTN_FROM_BANK_TO_FUTURE_BY_BANK 1069
#define ON_RSP_QUERY_BANK_ACCOUNT_MONEY_BY_FUTURE 1070
#define ON_RTN_QUERY_BANK_BALANCE_BY_FUTURE 1071
#define ON_ERR_RTN_QUERY_BANK_BALANCE_BY_FUTURE 1072
#define ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_BANK 1073
#define ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_BANK 1074
#define ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE_MANUAL 1075
#define ON_ERR_RTN_REPEAL_BANK_TO_FUTURE_BY_FUTURE_MANUAL 1076
#define ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE_MANUAL 1077
#define ON_ERR_RTN_REPEAL_FUTURE_TO_BANK_BY_FUTURE_MANUAL 1078
#define ON_RTN_REPEAL_FROM_BANK_TO_FUTURE_BY_FUTURE 1079
#define ON_RTN_REPEAL_FROM_FUTURE_TO_BANK_BY_FUTURE 1080
#define ON_RTN_OPEN_ACCOUNT_BY_BANK 1081
#define ON_RTN_CANCEL_ACCOUNT_BY_BANK 1082
#define ON_RTN_CHANGE_ACCOUNT_BY_BANK 1083
#define ON_RTN_DEPTH_MARKET_DATA 1084
#define ON_RSP_SUB_MARKET_DATA 1085
#define ON_RSP_UN_SUB_MARKET_DATA 1086
#define ON_RSP_GET_MARKET_TOPIC 1087


///// 自定义状态
#define STATUS_SUCCESS 0
#define WRONG_VALUE_TYPE 10001 // 错误的数据类型
#define NONE_TRADER_API_FUNC 10002 // 没有对应的traderApi函数

#define round(x) (x - floor(x) >= 0.5 ? floor(x) + 1 : floor(x)) //四舍五入宏定义

#define TD_EVENT_CALL(FIELD, EVENT_ID, ERR_CODE) \
  do { \
    FIELD->trader    = this; \
    FIELD->errCode   = ERR_CODE; \
    FIELD->eventId   = EVENT_ID; \
    req->data        = FIELD; \
    uv_queue_work(uv_default_loop(), req, AsyncFn, (uv_after_work_cb)AsyncAfterFn); \
  } while (0);

#define MD_EVENT_CALL(FIELD, EVENT_ID, ERR_CODE) \
  do { \
    FIELD->mduser    = this; \
    FIELD->errCode   = ERR_CODE; \
    FIELD->eventId   = EVENT_ID; \
    req->data        = FIELD; \
    uv_queue_work(uv_default_loop(), req, AsyncFn, (uv_after_work_cb)AsyncAfterFn); \
  } while (0);

#define TD_DEBUG_LOG(LOG_STR) \
  if (Trader::isDebug) { \
    std::cout << "[DEBUG in C++]: " << LOG_STR << std::endl; \
  }

#define MD_DEBUG_LOG(LOG_STR) \
  if (Mduser::isDebug) { \
    std::cout << "[DEBUG in C++]: " << LOG_STR << std::endl; \
  }

#define TD_EVENT_FUNC(FUNC_NAME, EVENT_ID, ERR_CODE) \
  do { \
    if (Trader::isDebug) { \
      std::cout << "[DEBUG in C++]: " << FUNC_NAME << " called." << std::endl; \
    } \
    TdCbField *field = (TdCbField *)malloc(sizeof(TdCbField)); \
    uv_work_t *req   = new uv_work_t; \
    field->trader    = this; \
    field->errCode   = ERR_CODE; \
    field->eventId   = EVENT_ID; \
    req->data        = field; \
    uv_queue_work(uv_default_loop(), req, AsyncFn, (uv_after_work_cb)AsyncAfterFn); \
  } while (0);

#define MD_EVENT_FUNC(FUNC_NAME, EVENT_ID, ERR_CODE) \
  do { \
    if (Mduser::isDebug) { \
      std::cout << "[DEBUG in C++]: " << FUNC_NAME << " called." << std::endl; \
    } \
    MdCbField *field = (MdCbField *)malloc(sizeof(MdCbField)); \
    uv_work_t *req   = new uv_work_t; \
    field->mduser    = this; \
    field->errCode   = ERR_CODE; \
    field->eventId   = EVENT_ID; \
    req->data        = field; \
    uv_queue_work(uv_default_loop(), req, AsyncFn, (uv_after_work_cb)AsyncAfterFn); \
  } while (0);

#define SET_PROPERTY_STRING(ENV, OBJ, KEY, STR) \
  OBJ.Set(KEY, Napi::String::New(ENV, (const char *)STR));

#define SET_PROPERTY_NUMBER(ENV, OBJ, KEY, NUMBER) \
  OBJ.Set(KEY, Napi::Number::New(ENV, roundFunc((double) NUMBER, 2)));

#define SET_PROPERTY_BUFFER(ENV, OBJ, KEY, STR) \
  OBJ.Set(KEY, Napi::Buffer<char>::New(ENV, STR, strlen(STR)));

#endif