#pragma once
#include "include\cef_app.h"

class anCefApp2 :
	public CefApp,
	public CefRenderProcessHandler
{
public:
	anCefApp2();
	~anCefApp2();

	virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override;

	// Called immediately after the V8 context for a frame has been created. To
  // retrieve the JavaScript 'window' object use the CefV8Context::GetGlobal()
  // method. V8 handles can only be accessed from the thread on which they are
  // created. A task runner for posting tasks on the associated thread can be
  // retrieved via the CefV8Context::GetTaskRunner() method.
  ///
  /*--cef()--*/
	virtual void OnContextCreated(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context) override;

	virtual void OnRenderThreadCreated(CefRefPtr<CefListValue> extra_info) override;

	IMPLEMENT_REFCOUNTING(anCefApp2);

private:
	CefRefPtr<class anV8Handler> jsHandler_ = { nullptr };
};

