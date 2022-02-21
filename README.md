# Bypass Anti-Virus

**我也是一个小白，很喜欢免杀技术，自己琢磨、研究、复现了几种绕过杀软的姿势，分享给大家。**

**郑重声明：文中所涉及的技术、思路和工具仅供以安全为目的的学习交流使用，任何人不得将其用于非法用途以及盈利等目的，否则后果自行承担！**



## 上手指南

通过下表选择你感兴趣的免杀方式

| 序号 | 免杀方式                                                     | VT查杀率(avg) | 时间       | 火绒 | 360  | 腾讯 | 代码实现 |
| ---- | ------------------------------------------------------------ | ------------- | ---------- | ---- | ---- | ---- | -------- |
| 1    | [回调函数（及改进）](https://github.com/midisec/BypassAnti-Virus/tree/main/callback) | 2/68          | 2022-02-18 | √    | √    | √    | c++      |
| 2    |                                                              |               |            |      |      |      |          |
| 3    |                                                              |               |            |      |      |      |          |





## 更新消息

2022-02-18

* 通过[回调函数](https://github.com/midisec/BypassAnti-Virus/tree/main/callback)加载恶意shellcode（c++）
* 新增UUID方式，通过回调函数加载shellcode（c++）
* 新增BASE64编码+UUID方式，通过回调函数加载shellcode（c++）

2022-02-21

* 新增[IPV6方式](https://github.com/midisec/BypassAnti-Virus/tree/main/callback/v0.3)，通过回调函数加载shellcode（c++）
* 新增[MAC方式](https://github.com/midisec/BypassAnti-Virus/tree/main/callback/v0.4)，通过回调函数加载shellcode（c++）



## 贡献者

<a href="https://github.com/midisec/BypassAnti-Virus/graphs/contributors"><img src="./images/contributors.svg" /></a>

