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
