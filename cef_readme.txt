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
