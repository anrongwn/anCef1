#include "anCefApp2.h"
#include "anV8Handler.h"
#include "spdlog/fmt/fmt.h"
#include <string>

anCefApp2::anCefApp2()
{
	jsHandler_ = new anV8Handler();
}


anCefApp2::~anCefApp2()
{
}

CefRefPtr<CefRenderProcessHandler> anCefApp2::GetRenderProcessHandler()
{
	return this;
}

void anCefApp2::OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context)
{
	CefRefPtr<CefV8Value> window = context->GetGlobal();

	/*//
	CefRefPtr< CefV8Value> strValue = CefV8Value::CreateString("5000");
	window->SetValue("in1", strValue, V8_PROPERTY_ATTRIBUTE_NONE);
	*/

	//js 关联 c++ 方法 
	CefRefPtr< CefV8Value> f_withdrawl = CefV8Value::CreateFunction("withdraw1", jsHandler_);
	window->SetValue("withdraw1", f_withdrawl, V8_PROPERTY_ATTRIBUTE_NONE);

	CefRefPtr< CefV8Value> f_mainpage = CefV8Value::CreateFunction("mainpage", jsHandler_);
	window->SetValue("mainpage", f_mainpage, V8_PROPERTY_ATTRIBUTE_NONE);
}

void anCefApp2::OnRenderThreadCreated(CefRefPtr<CefListValue> extra_info)
{
	CefString id = extra_info->GetString(0);
	int value = extra_info->GetInt(1);

	//std::string log = fmt::format("anCefApp2::OnRenderThreadCreated(extra_info={}, {}), pid={:#08x}", id.ToString(), value, ::GetCurrentProcessId());
	std::string log = fmt::format("anCefApp2::OnRenderThreadCreated(extra_info={}, {}), pid={}", id.ToString(), value, ::GetCurrentProcessId());
	

	OutputDebugStringA(log.c_str());

}

bool anCefApp2::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process, CefRefPtr<CefProcessMessage> message)
{
	//收到browser 进程发来的load_end消息
	int bid = browser->GetIdentifier();
	std::string log = fmt::format("anCefApp2::OnProcessMessageReceived(browser id={}, CefProcessId={}), pid={}", bid, source_process, ::GetCurrentProcessId());
	CefString mname = message->GetName();
	CefString page = message->GetArgumentList()->GetString(0);
	int status = message->GetArgumentList()->GetInt(1);

	

	log += fmt::format(",message(name={}, arg[0]={}, arg[1]={})", mname.ToString(), page.ToString(), status);

	OutputDebugStringA(log.c_str());

	return true;
}

