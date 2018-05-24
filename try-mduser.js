const Femas = require('./build/Release/femas-bridge.node');
const iconv = require('iconv-lite');

console.log('[DEBUG in js]', 'typeof femas:', typeof Femas);
console.log('[DEBUG in js]', 'typeof femas.Mduser:', typeof Femas.Mduser);

let mduser = new Femas.Mduser({ debug: true });
console.log('[DEBUG in js]', 'typeof mduser:', typeof mduser);

mduser.on("frontConnected", function (err, rsp) {
  console.log('[DEBUG in js]', 'on frontConnected', { err, rsp: convert(rsp) });
  let ret = mduser.call("reqUserLogin", {
    UserID: "UserID",
    BrokerID: "BrokerID",
    Password: "Password",
    UserProductInfo: "XZ_TX",
    TradingDay: "20181212"
  });
  console.log('[DEBUG in js]', 'call req user login:', ret);
});
mduser.on("rspError", function (err, rsp) {
  console.log('[DEBUG in js]', 'on rspError', { err, rsp: convert(rsp) });
});

mduser.on("rspUserLogin", function (err, rsp) {
  console.log('[DEBUG in js]', 'on rspUserLogin', { err, rsp: convert(rsp) });
  mduser.call("subMarketData", {
    InstrumentID: "IC1805"
  });
  // mduser.call("reqSubMarketData", {
  //   InstrumentID: "IC1708"
  // });
});
mduser.on("rspSubMarketData", function (err, rsp) {
  console.log('[DEBUG in js]', 'on rspSubMarketData', { err, rsp: convert(rsp) });
});
mduser.on("rtnDepthMarketData", function (err, rsp) {
  console.log('[DEBUG in js]', 'on rtnDepthMarketData', { err, rsp: rsp.InstrumentID });
});

mduser.call("connect", {
  IP: "tcp://180.166.103.35:28005",
  RESUME_TYPE: "QUICK"
});

function convert(obj) {
  if (!obj) return obj;
  for (var k in obj) {
    if (Buffer.isBuffer(obj[k])) {
      obj[k] = iconv.decode(obj[k], "GB2312")
    }
  }
  return obj;
}