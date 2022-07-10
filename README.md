# Bypass Anti-Virus

**我也是一个小白，很喜欢免杀技术，自己琢磨、研究、复现了几种绕过杀软的姿势，分享给大家。**

**郑重声明：文中所涉及的技术、思路和工具仅供以安全为目的的学习交流使用，任何人不得将其用于非法用途以及盈利等目的，否则后果自行承担！**



## 上手指南

通过下表选择你感兴趣的免杀方式

| 序号 | 免杀方式                                                     | VT查杀率(avg) | 时间       | 火绒 | 360  | 腾讯 | 代码实现 |
| ---- | ------------------------------------------------------------ | ------------- | ---------- | ---- | ---- | ---- | -------- |
| 1    | [回调函数（及改进）](https://github.com/midisec/BypassAnti-Virus/tree/main/callback) | 2/68          | 2022-02-18 | √    | √    | √    | c++      |
| 2    | [隐藏导入表](https://github.com/midisec/BypassAnti-Virus/tree/main/hide_Import_tables) | 8/68          | 2022-07-10 | √    | √    | √    | c++      |
| 3    |                                                              |               |            |      |      |      |          |





## 更新消息

2022-02-18

* 通过[回调函数](https://github.com/midisec/BypassAnti-Virus/tree/main/callback)加载恶意shellcode（c++）
* 新增UUID方式，通过回调函数加载shellcode（c++）
* 新增BASE64编码+UUID方式，通过回调函数加载shellcode（c++）

2022-02-21

* 新增[IPV6方式](https://github.com/midisec/BypassAnti-Virus/tree/main/callback/v0.3)，通过回调函数加载shellcode（c++）
* 新增[MAC方式](https://github.com/midisec/BypassAnti-Virus/tree/main/callback/v0.4)，通过回调函数加载shellcode（c++）

2022-03-07
* 新增[IPV4方式](https://github.com/midisec/BypassAnti-Virus/tree/main/callback/v0.5)，通过回调函数加载shellcode（c++）

2022-03-08

* 新增13种[可利用的回调函数](https://github.com/midisec/BypassAnti-Virus/tree/main/callback#%E5%8F%AF%E5%88%A9%E7%94%A8%E7%9A%84%E5%9B%9E%E8%B0%83%E5%87%BD%E6%95%B0)加载shellcode（c++）

2022-07-10

* 通过[隐藏导入表的方式](https://github.com/midisec/BypassAnti-Virus/tree/main/hide_Import_tables)绕过部分敏感函数调用静态查杀（c++）



## 贡献者

<a href="https://github.com/midisec/BypassAnti-Virus/graphs/contributors"><img src="./images/contributors.svg" /></a>

