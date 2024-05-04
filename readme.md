[toc]



## 项目说明

- 简单的c/c++程序集合
- 存放的源代码编译出来都是控制台程序Console apps
- OJ,Leetcode和一些试验C++语言的特性小程序

## c/c++编辑器或IDE

### vscode

- 项目是在vscode下编写代码和运行的,这是考虑轻量和插件生态丰富,对各种AI插件的接入让编写代码变得舒服
- 经过一段时间的探索和试验,结合官方文档的指南,生成了`.vscode`目录下的3个配置文件
  - 配置详情参看:[Vscode配置C/C++编程环境@配置C和CPP的运行和调试环境@配置过程的相关问题@中文文件名乱码@build和debug方案组合配置](https://blog.csdn.net/xuchaoxin1375/article/details/138172679)

- 特别是安装Msys2,可以用国内镜像,安装包下载完后可以断网安装(中途可能试图更新一些数据,但这个速度可能很慢),离线安装的话可能更快
  - 安装完了msys2后默认是没有ucrt组件,所以如果像官网那样使用的路径,需要我们进一步安装ucrt
  - 如果是老windows可能装不了ucrt,那么用MinGw也是可以的
- 详情命令参考上述博客或者vscode官方文档

## 其他C/C++开发环境



## 项目目录解释

- 01目录是北京大学 郭炜 编著的 新标准C++程序设计
  - [清华大学出版社-图书详情-《新标准C++程序设计教程》 (tsinghua.edu.cn)](http://www.tup.tsinghua.edu.cn/bookscenter/book_04562004.html)
  - 这里所谓的新标准已经不是什么新标准了,仅是相对于C++98而言较新的C++11

- 02目录是国外的JumpIntoCpp的源码
  - [Jumping into C++, by Alex Allain - Cprogramming.com](https://www.cprogramming.com/c++book/?inl=bg1)
  - 虽然是收费的,但是有资源





