#include "anV8Handler.h"



anV8Handler::anV8Handler()
{
}


anV8Handler::~anV8Handler()
{
}

bool anV8Handler::Execute(const CefString & name, CefRefPtr<CefV8Value> object, const CefV8ValueList & arguments, CefRefPtr<CefV8Value>& retval, CefString & exception)
{
	if (name == "withdraw1") {
		if (arguments.size() == 1) {
			int amount = arguments.at(0)->GetIntValue();

			amount = 0;

			retval = CefV8Value::CreateInt(amount);
		}

		return true;
	}
	return false;
}
