http://opensource.spotify.com/cefbuilds/index.html
https://bitbucket.org/chromiumembedded/cef/downloads/?tab=branches


//content api 与 cef cef3
https://blog.csdn.net/haojun186/article/details/50450429


//编译说明
https://blog.csdn.net/u011304970/article/details/77592775

//cmake
https://cmake.org/download/

//教程
https://github.com/fanfeilong/cefutil
https://github.com/fanfeilong/cefutil/tree/master/doc
https://bitbucket.org/chromiumembedded/cef/wiki/JavaScriptIntegration.md#markdown-header-js-function
https://www.cnblogs.com/dancheblog/p/4834345.html


//cef3 api doc
https://magpcss.org/ceforum/apidocs3/

//cef3 二进制文件及资源文件说明
https://blog.csdn.net/CButtonST/article/details/71683414


//vs2017 编译libcef_wrapp.dll
下载完成解压后，打开VS2017，依次点击菜单的“文件”“打开”“CMake”，选择解压后目录的CMakeLists.txt文件，VS完成项目加载后，右键CMakeLists.txt，选择“更改CMake设置”，在打开的CMakeSettings.json文件里，修改generator参数为“Visual Studio 15 2017 Win64”，buildCommandArgs参数为“-m:8 -v:minimal -p:PreferredToolArchitecture=x64”（可以把buildRoot参数里的“${env.USERPROFILE}”改成“${workspaceRoot}”，这样生成的文件会在当前目录而不是C盘，方便调试），保存完成后，即可编译通过并运行。
原文：https://blog.csdn.net/wei123456/article/details/86591927 

//cef 开发总结
https://blog.csdn.net/zhuhongshu/article/details/70159672

//cef 开发实例
https://www.jianshu.com/p/b57fd414bd1d


//cef 本地web资源 打包 加密
cef中最简单的打开页面方法是指定一个url或者本地路径。在使用cef开发客户端时，多数情况是写好了web页面，把web资源放到本地来使用。而js文件中很可能会暴露一些接口或者重要数据，为了保护这些数据需要把web资源加密。例如网易云音乐一类的客户端都是这样做的

这个问题其实就是资源重定向的问题，把cef请求的资源重定向到自己解密出来的数据处。资源重定向需要处理cef里面的OnBeforeResourceLoad、GetResourceHandler接口

翻了翻cef2623的demo，发现其实cef自身已经有了相关的功能。即CefResourceManager，创建一个CefResourceManager对象，调用AddArchiveProvider方法，可以添加一个加密zip文档作为资源来源。然后在OnBeforeResourceLoad、GetResourceHandler接口中调用CefResourceManager对象对应名称的接口，就可以直接使用加密zip中的资源了，很简单

同时CefResourceManager提供了AddDirectoryProvider方法来把某个目录作为资源来源，也可以调用AddProvider来自定义一个资源来源。在调用这些方式时，需要提供一个特征字符串开头的URL。比如http://test/，如果cef正在打开的url是以http://test/开头，则会从对应的资源来源里，去取资源。比如用加密zip的方式，同时尝试打开http://test/demo.html，则会从zip里查找demo.html文件并打开

CefResourceManager还提供了filter功能，可以用于过滤url，来判断那些url是需要重定向的，也可以设置重定向的位置。

https://blog.csdn.net/zhuhongshu/article/details/81484159
https://blog.csdn.net/csdnyonghu123/article/details/92808278
https://bitbucket.org/chromiumembedded/cef-project/src/master/examples/resource_manager/?at=master



//CEF JS与browser进程间的异步通信
https://blog.csdn.net/foruok/article/details/50780333
browser进程
1）配置browser进程这一侧的Message Router (CefMessageRouterConfig)
2）创建browser进程这一侧的CefMessageRouterBrowserSide的实例
3）调用CefMessageRouterBrowserSide预定义方法
4) 在browser进程里实现处理JS查询的handler
5）给CefMessageRouterBrowserSide的实例添加handler
renderer进程
1）配置renderer进程这一侧的Message Router(CefMessageRouterConfig)
2）创建CefMessageRouterRendererSide的实例

Cef Generic Message Router的实现
Generic Message Router内部实现有两个关键点：


CefMessageRouterRendererSide在renderer进程内，在OnContextCreated中向JS导出了cefQuery和cefQueryCancel两个方法，具体见cef_message_router.cc
renderer和browser进程间使用SendProcessMessage通信，在OnProcessMessageReceived中处理消息
--------------------- 
作者：foruok 
来源：CSDN 
原文：https://blog.csdn.net/foruok/article/details/50780333 
版权声明：本文为博主原创文章，转载请附上博文链接！