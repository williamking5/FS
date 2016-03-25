# FS
轻量级文件传输工具
### 为什么要制作FS
原因十分简单，本来打算制作QQFK的，结果协作失败。某人又经常失踪，只好先写一个轻量级的传输工具以应对现在需求。
### 协议
还是利用七牛云存储来进行数据交换，文件名依然采取时间+发送人+收件人+文件名的方式。
配置文件依然是以userconf为后缀名，以时间为名字。请务必不要重名。
### 命令
1. 注册
``` sign 用户名 密码```
2. 登陆
``` login 用户名 密码```
3. 发送
``` send 文件名```
4. 接受
``` get ```
