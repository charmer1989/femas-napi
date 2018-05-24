const Femas = require('./build/Release/femas-bridge.node');
const iconv = require('iconv-lite');

console.log('[DEBUG in js]', 'typeof femas:', typeof Femas);
console.log('[DEBUG in js]', 'typeof femas.Trader:', typeof Femas.Trader);

let trader = new Femas.Trader({ debug: true });
console.log('[DEBUG in js]', 'typeof trader:', typeof trader);

trader.on("frontConnected", function (err, rsp) {
  console.log('[DEBUG in js]', 'on frontConnected', { err, rsp: convert(rsp) });
  let ret = trader.call("reqUserLogin", {
    UserID: "UserID",
    BrokerID: "BrokerID",
    Password: "Password",
    UserProductInfo: "XZ_TX"
  });
  console.log('[DEBUG in js]', 'call req user login:', ret);
});

trader.on("rspError", function (err, rsp) {
  console.log('[DEBUG in js]', 'on rspError', { err, rsp: convert(rsp) });
});
trader.on("rspQryExchange", function (err, rsp) {
  console.log('[DEBUG in js]', 'on rspQryExchange', { err, rsp: convert(rsp) });
});

trader.on("rspUserLogin", function (err, rsp) {
  console.log('[DEBUG in js]', 'on rspUserLogin', { err, rsp: convert(rsp) });
  trader.call("reqQryExchange", {
    ExchangeID: "DCE"
  });
});

trader.call("connect", {
  IP: "tcp://180.166.103.35:28002"
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