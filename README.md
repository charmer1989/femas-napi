# femas-napi
基于N-api写的 node 扩展, 用于期货femas的交易和行情.

`$ git clone git@github.com:charmer1989/femas-napi.git && cd femas-napi`

`$ npm i`

`$ node-gyp rebuild`

`$ cp lib* ../`
##### 先修改测试脚本中的账户密码等参数, 然后
`$ node try-mduser.js`

##### 说明1: 注意依赖目录的关系, 运行前, 需要把动态链接库需要复制到上层目录
##### 说明2: 大量订阅行情可能会出现崩溃, 可以将行情的通知机制改成抓取, 参考我的另一个项目ctp-napi.
