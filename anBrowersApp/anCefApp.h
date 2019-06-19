#pragma once
#include "include\cef_app.h"


class anCefApp :
	public CefApp, 
	public CefBrowserProcessHandler
{
public:
	anCefApp();
	~anCefApp();

	//
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override;

	// CefBrowserProcessHandler methods:
	virtual void OnContextInitialized() override;



private:
	// Include the default reference counting implementation.
	IMPLEMENT_REFCOUNTING(anCefApp);

private:

};

