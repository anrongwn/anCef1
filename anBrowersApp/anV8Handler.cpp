#include "anV8Handler.h"



anV8Handler::anV8Handler()
{
}


anV8Handler::~anV8Handler()
{
}

bool anV8Handler::Execute(const CefString & name, CefRefPtr<CefV8Value> object, \
	const CefV8ValueList & arguments, CefRefPtr<CefV8Value>& retval, CefString & exception)
{
	if (name == "withdraw1") {
		if (arguments.size() == 1) {
			int amount = arguments.at(0)->GetIntValue();

			amount = 0;

			retval = CefV8Value::CreateInt(amount);
			
			//
			CefRefPtr<CefV8Context> context = CefV8Context::GetCurrentContext();
			context->GetBrowser()->GetMainFrame()->LoadURL("file:///D:/MyTest/2019_C++/anCef1/anBrowersApp/html/page2.html");

			
		}

		return true;
	}
	if (name == "mainpage") {
		if (arguments.size() == 1) {
			int amount = arguments.at(0)->GetIntValue();

			amount = 0;

			retval = CefV8Value::CreateInt(amount);

			//
			CefRefPtr<CefV8Context> context = CefV8Context::GetCurrentContext();
			context->GetBrowser()->GetMainFrame()->LoadURL("file:///D:/MyTest/2019_C++/anCef1/anBrowersApp/html/index.html");


		}
	}
	return false;
}
