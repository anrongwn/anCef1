#pragma once
#include "include/cef_v8.h"

class anV8Handler :
	public CefV8Handler
{
public:
	anV8Handler();
	~anV8Handler();

	///
  // Handle execution of the function identified by |name|. |object| is the
  // receiver ('this' object) of the function. |arguments| is the list of
  // arguments passed to the function. If execution succeeds set |retval| to the
  // function return value. If execution fails set |exception| to the exception
  // that will be thrown. Return true if execution was handled.
  ///
  /*--cef()--*/
	virtual bool Execute(const CefString& name,
		CefRefPtr<CefV8Value> object,
		const CefV8ValueList& arguments,
		CefRefPtr<CefV8Value>& retval,
		CefString& exception) override;

private:
	IMPLEMENT_REFCOUNTING(anV8Handler);
};

