#include "anCefApp2.h"
#include "anV8Handler.h"


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

