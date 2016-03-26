# FS
轻量级文件传输工具
### 为什么要制作FS
原因十分简单，本来打算制作QQFK的，结果协作失败。某人又经常失踪，只好先写一个轻量级的传输工具以应对现在需求。
### 协议
还是利用七牛云存储来进行数据交换，文件名依然采取时间+发送人+收件人+文件名的方式。
配置文件依然是以userconf为后缀名，以时间为名字。请务必不要重名。
### 命令
1. 注册
``` sign ```
2. 登陆
``` login ```
3. 发送
``` send ```
4. 接受
``` get ```
5. 锁定
``` lock ```
6. 退出
``` exit ```

### 如何编译软件

打开链接[源文件库](https://github.com/williamking5/FS/tree/master/src)

1. 下载所有头文件(.h)和主函数文件(.cpp)

2. 下载网络传输工具qshell

在本地同一目录下编译。
### 附带所有源文件及网络传输工具的链接
- [主文件](https://github.com/williamking5/FS/blob/master/src/main.cpp)
- [download.h](https://github.com/williamking5/FS/blob/master/src/download.h)
- [get.h](https://github.com/williamking5/FS/blob/master/src/get.h)
- [gettime.h](https://github.com/williamking5/FS/blob/master/src/gettime.h)
- [login.h](https://github.com/williamking5/FS/blob/master/src/login.h)
- [send.h](https://github.com/williamking5/FS/blob/master/src/send.h)
- [sign.h](https://github.com/williamking5/FS/blob/master/src/sign.h)
- [网络传输工具](https://github.com/williamking5/FS/blob/master/src/qshell)
