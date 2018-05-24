#include "Mduser.h"
#include "Trader.h"
#include <napi.h>

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  Mduser::Init(env, exports);
  Trader::Init(env, exports);
  return exports;
}

NODE_API_MODULE(femas, Init)