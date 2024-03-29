#include "anCefApp.h"
#include "anCefClient.h"


#include "include/base/cef_bind.h"
#include "include/views/cef_browser_view.h"
#include "include/views/cef_window.h"
#include "include/wrapper/cef_closure_task.h"
#include "include/wrapper/cef_helpers.h"


namespace {

	// When using the Views framework this object provides the delegate
	// implementation for the CefWindow that hosts the Views-based browser.
	class SimpleWindowDelegate : public CefWindowDelegate {
	public:
		explicit SimpleWindowDelegate(CefRefPtr<CefBrowserView> browser_view)
			: browser_view_(browser_view) {}

		void OnWindowCreated(CefRefPtr<CefWindow> window) override {
			// Add the browser view and show the window.
			window->AddChildView(browser_view_);
			window->Show();

			// Give keyboard focus to the browser view.
			browser_view_->RequestFocus();
		}

		void OnWindowDestroyed(CefRefPtr<CefWindow> window) override {
			browser_view_ = nullptr;
		}

		bool CanClose(CefRefPtr<CefWindow> window) override {
			// Allow the window to close if the browser says it's OK.
			CefRefPtr<CefBrowser> browser = browser_view_->GetBrowser();
			if (browser)
				return browser->GetHost()->TryCloseBrowser();
			return true;
		}

	private:
		CefRefPtr<CefBrowserView> browser_view_;

		IMPLEMENT_REFCOUNTING(SimpleWindowDelegate);
		DISALLOW_COPY_AND_ASSIGN(SimpleWindowDelegate);
	};

}  // namespace


anCefApp::anCefApp()
{
}


anCefApp::~anCefApp()
{
}

CefRefPtr<CefBrowserProcessHandler> anCefApp::GetBrowserProcessHandler()
{
	return this;
}


void anCefApp::OnContextInitialized()
{
	CEF_REQUIRE_UI_THREAD();

	CefRefPtr<CefCommandLine> command_line =
		CefCommandLine::GetGlobalCommandLine();

#if defined(OS_WIN) || defined(OS_LINUX)
	// Create the browser using the Views framework if "--use-views" is specified
	// via the command-line. Otherwise, create the browser using the native
	// platform framework. The Views framework is currently only supported on
	// Windows and Linux.
	const bool use_views = command_line->HasSwitch("use-views");
#else
	const bool use_views = false;
#endif

	// anCefClient implements browser-level callbacks.
	CefRefPtr<anCefClient> handler(new anCefClient(use_views));

	// Specify CEF browser settings here.
	CefBrowserSettings browser_settings;

	std::string url;

	// Check if a "--url=" value was provided via the command-line. If so, use
	// that instead of the default URL.
	url = command_line->GetSwitchValue("url");
	if (url.empty())
	{
		//url = "http://www.baidu.com";
		url = R"(file:///D:/MyTest/2019_C++/anCef1/anBrowersApp/html/index.html)";
	}
		

	if (use_views) {
		// Create the BrowserView.
		CefRefPtr<CefBrowserView> browser_view = CefBrowserView::CreateBrowserView(
			handler, url, browser_settings, NULL, NULL);

		// Create the Window. It will show itself after creation.
		CefWindow::CreateTopLevelWindow(new SimpleWindowDelegate(browser_view));
	}
	else {
		// Information used when creating the native window.
		CefWindowInfo window_info;
		

#if defined(OS_WIN)
		// On Windows we need to specify certain flags that will be passed to
		// CreateWindowEx().
		window_info.SetAsPopup(NULL, "anBrowersApp");
		
#endif

		//1�� Create the first browser window.
		CefBrowserHost::CreateBrowser(window_info, handler, url, browser_settings,
			NULL);
		/*
		//2�� Create the second browser window.
		CefBrowserHost::CreateBrowser(window_info, handler, url, browser_settings,
			NULL);
		*/

	}
}

void anCefApp::OnRenderProcessThreadCreated(CefRefPtr<CefListValue> extra_info)
{
	extra_info->SetString(0, "id=1000");
	extra_info->SetInt(1, 1000);
}
