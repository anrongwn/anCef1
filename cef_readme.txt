http://opensource.spotify.com/cefbuilds/index.html
https://bitbucket.org/chromiumembedded/cef/downloads/?tab=branches


//content api �� cef cef3
https://blog.csdn.net/haojun186/article/details/50450429


//����˵��
https://blog.csdn.net/u011304970/article/details/77592775

//cmake
https://cmake.org/download/

//�̳�
https://github.com/fanfeilong/cefutil
https://github.com/fanfeilong/cefutil/tree/master/doc
https://bitbucket.org/chromiumembedded/cef/wiki/JavaScriptIntegration.md#markdown-header-js-function
https://www.cnblogs.com/dancheblog/p/4834345.html


//cef3 api doc
https://magpcss.org/ceforum/apidocs3/

//cef3 �������ļ�����Դ�ļ�˵��
https://blog.csdn.net/CButtonST/article/details/71683414


//vs2017 ����libcef_wrapp.dll
������ɽ�ѹ�󣬴�VS2017�����ε���˵��ġ��ļ������򿪡���CMake����ѡ���ѹ��Ŀ¼��CMakeLists.txt�ļ���VS�����Ŀ���غ��Ҽ�CMakeLists.txt��ѡ�񡰸���CMake���á����ڴ򿪵�CMakeSettings.json�ļ���޸�generator����Ϊ��Visual Studio 15 2017 Win64����buildCommandArgs����Ϊ��-m:8 -v:minimal -p:PreferredToolArchitecture=x64�������԰�buildRoot������ġ�${env.USERPROFILE}���ĳɡ�${workspaceRoot}�����������ɵ��ļ����ڵ�ǰĿ¼������C�̣�������ԣ���������ɺ󣬼��ɱ���ͨ�������С�
ԭ�ģ�https://blog.csdn.net/wei123456/article/details/86591927 

//cef �����ܽ�
https://blog.csdn.net/zhuhongshu/article/details/70159672

//cef ����ʵ��
https://www.jianshu.com/p/b57fd414bd1d


//cef ����web��Դ ��� ����
cef����򵥵Ĵ�ҳ�淽����ָ��һ��url���߱���·������ʹ��cef�����ͻ���ʱ�����������д����webҳ�棬��web��Դ�ŵ�������ʹ�á���js�ļ��кܿ��ܻᱩ¶һЩ�ӿڻ�����Ҫ���ݣ�Ϊ�˱�����Щ������Ҫ��web��Դ���ܡ���������������һ��Ŀͻ��˶�����������

���������ʵ������Դ�ض�������⣬��cef�������Դ�ض����Լ����ܳ��������ݴ�����Դ�ض�����Ҫ����cef�����OnBeforeResourceLoad��GetResourceHandler�ӿ�

���˷�cef2623��demo��������ʵcef�����Ѿ�������صĹ��ܡ���CefResourceManager������һ��CefResourceManager���󣬵���AddArchiveProvider�������������һ������zip�ĵ���Ϊ��Դ��Դ��Ȼ����OnBeforeResourceLoad��GetResourceHandler�ӿ��е���CefResourceManager�����Ӧ���ƵĽӿڣ��Ϳ���ֱ��ʹ�ü���zip�е���Դ�ˣ��ܼ�

ͬʱCefResourceManager�ṩ��AddDirectoryProvider��������ĳ��Ŀ¼��Ϊ��Դ��Դ��Ҳ���Ե���AddProvider���Զ���һ����Դ��Դ���ڵ�����Щ��ʽʱ����Ҫ�ṩһ�������ַ�����ͷ��URL������http://test/�����cef���ڴ򿪵�url����http://test/��ͷ�����Ӷ�Ӧ����Դ��Դ�ȥȡ��Դ�������ü���zip�ķ�ʽ��ͬʱ���Դ�http://test/demo.html������zip�����demo.html�ļ�����

CefResourceManager���ṩ��filter���ܣ��������ڹ���url�����ж���Щurl����Ҫ�ض���ģ�Ҳ���������ض����λ�á�

https://blog.csdn.net/zhuhongshu/article/details/81484159
https://blog.csdn.net/csdnyonghu123/article/details/92808278
https://bitbucket.org/chromiumembedded/cef-project/src/master/examples/resource_manager/?at=master



//CEF JS��browser���̼���첽ͨ��
https://blog.csdn.net/foruok/article/details/50780333
browser����
1������browser������һ���Message Router (CefMessageRouterConfig)
2������browser������һ���CefMessageRouterBrowserSide��ʵ��
3������CefMessageRouterBrowserSideԤ���巽��
4) ��browser������ʵ�ִ���JS��ѯ��handler
5����CefMessageRouterBrowserSide��ʵ�����handler
renderer����
1������renderer������һ���Message Router(CefMessageRouterConfig)
2������CefMessageRouterRendererSide��ʵ��

Cef Generic Message Router��ʵ��
Generic Message Router�ڲ�ʵ���������ؼ��㣺


CefMessageRouterRendererSide��renderer�����ڣ���OnContextCreated����JS������cefQuery��cefQueryCancel���������������cef_message_router.cc
renderer��browser���̼�ʹ��SendProcessMessageͨ�ţ���OnProcessMessageReceived�д�����Ϣ
--------------------- 
���ߣ�foruok 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/foruok/article/details/50780333 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�