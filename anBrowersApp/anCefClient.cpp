#include "anCefClient.h"

#include <sstream>
#include <string>

#include "include/base/cef_bind.h"
#include "include/cef_app.h"
#include "include/views/cef_browser_view.h"
#include "include/views/cef_window.h"
#include "include/wrapper/cef_closure_task.h"
#include "include/wrapper/cef_helpers.h"
#include "spdlog/fmt/fmt.h"


namespace {
	anCefClient * g_instance = nullptr; //static 
}

anCefClient::anCefClient(bool use_views) : use_views_(use_views), is_closing_(false)
{
	g_instance = this;
}


anCefClient::~anCefClient()
{
	g_instance = nullptr;
}

anCefClient * anCefClient::GetInstance() {
	return g_instance;
}

void anCefClient::OnBeforeContextMenu(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefContextMenuParams> params, CefRefPtr<CefMenuModel> model)
{
	//清除右击菜单
	if ((params->GetTypeFlags() & (CM_TYPEFLAG_PAGE | CM_TYPEFLAG_FRAME)) != 0) {
		if (model->GetCount() > 0)
		{
			model->Clear();
		}
	}
}

void anCefClient::OnTitleChange(CefRefPtr<CefBrowser> browser, const CefString & title)
{
	CEF_REQUIRE_UI_THREAD();

	if (use_views_) {
		// Set the title of the window using the Views framework.
		CefRefPtr<CefBrowserView> browser_view =
			CefBrowserView::GetForBrowser(browser);
		if (browser_view) {
			CefRefPtr<CefWindow> window = browser_view->GetWindow();
			if (window)
				window->SetTitle(title);
		}
	}
	else {
		// Set the title of the window using platform APIs.
		PlatformTitleChange(browser, title);
	}


}

void anCefClient::OnFullscreenModeChange(CefRefPtr<CefBrowser> browser, bool fullscreen)
{
	CefWindowHandle hwnd = browser->GetHost()->GetWindowHandle();
	if (fullscreen) {

	}
	else {

	}
}

void anCefClient::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
	CEF_REQUIRE_UI_THREAD();

	// Add to the list of existing browsers.
	browser_list_.push_back(browser);
}

bool anCefClient::DoClose(CefRefPtr<CefBrowser> browser)
{
	// Closing the main window requires special handling. See the DoClose()
	// documentation in the CEF header for a detailed destription of this
	// process.
	if (browser_list_.size() == 1) {
		// Set a flag to indicate that the window close should be allowed.
		is_closing_ = true;
	}

	// Allow the close. For windowed browsers this will result in the OS close
	// event being sent.
	return false;

}

void anCefClient::OnBeforeClose(CefRefPtr<CefBrowser> browser)
{
	CEF_REQUIRE_UI_THREAD();

	// Remove from the list of existing browsers.
	BrowserList::iterator bit = browser_list_.begin();
	for (; bit != browser_list_.end(); ++bit) {
		if ((*bit)->IsSame(browser)) {
			browser_list_.erase(bit);
			break;
		}
	}

	if (browser_list_.empty()) {
		// All browser windows have closed. Quit the application message loop.
		CefQuitMessageLoop();
	}
}

void anCefClient::OnLoadError(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, ErrorCode errorCode, const CefString & errorText, const CefString & failedUrl)
{
	CEF_REQUIRE_UI_THREAD();

	// Don't display an error for downloaded files.
	if (errorCode == ERR_ABORTED)
		return;

	// Display a load error message.
	std::stringstream ss;
	ss << "<html><body bgcolor=\"white\">"
		"<h2>Failed to load URL "
		<< std::string(failedUrl) << " with error " << std::string(errorText)
		<< " (" << errorCode << ").</h2></body></html>";
	frame->LoadString(ss.str(), failedUrl);

}

void anCefClient::OnLoadStart(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, TransitionType transition_type)
{
	CefWindowHandle handle = browser->GetHost()->GetWindowHandle();

}

void anCefClient::OnLoadEnd(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, int httpStatusCode)
{
	int r = httpStatusCode;

	CefString url = frame->GetURL();
	std::string strurl = url.ToString();
	

	size_t pos = strurl.find_last_of('//');
	strurl = strurl.substr(pos + 1);
	if (0==strurl.compare("index.html")) {

		//动态注入js 文件
		const CefString js = "var v = document.createElement('script');\
								v.src='file:///D:/MyTest/2019_C++/anCef1/anBrowersApp/html/msgutils2.js';\
								document.body.appendChild(v);";

		frame->ExecuteJavaScript(js, frame->GetURL(), 0);
	}
	else if (0 == strurl.compare("page2.html")) {
		//动态注入js 文件
		const CefString js = "var v = document.createElement('script');\
								v.src='file:///D:/MyTest/2019_C++/anCef1/anBrowersApp/html/page2.js';\
								document.body.appendChild(v);";

		frame->ExecuteJavaScript(js, frame->GetURL(), 0);
	}

	//向render进程发送 load_end 消息
	CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create(strurl);
	CefRefPtr<CefListValue> args = msg->GetArgumentList();
	args->SetString(0, url);
	args->SetInt(1, 9999);

	browser->SendProcessMessage(PID_RENDERER, msg);
	//frame->ExecuteJavaScript("mySet('9000');",frame->GetURL(), 0);
}

bool anCefClient::OnPreKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent & event, CefEventHandle os_event, bool * is_keyboard_shortcut)
{
	return false;
}

bool anCefClient::OnKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent & event, CefEventHandle os_event)
{
	return false;
}

void anCefClient::CloseAllBrowsers(bool force_close)
{
	if (!CefCurrentlyOn(TID_UI)) {
		// Execute on the UI thread.
		CefPostTask(TID_UI, base::Bind(&anCefClient::CloseAllBrowsers, this,
			force_close));
		return;
	}

	if (browser_list_.empty())
		return;

	BrowserList::const_iterator it = browser_list_.begin();
	for (; it != browser_list_.end(); ++it)
		(*it)->GetHost()->CloseBrowser(force_close);

}

bool anCefClient::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process, CefRefPtr<CefProcessMessage> message)
{
	int bid = browser->GetIdentifier();
	std::string log = fmt::format("anCefClient::OnProcessMessageReceived(browser id={}, CefProcessId={}), pid={}", bid, source_process, ::GetCurrentProcessId());
	CefString mname = message->GetName();
	CefString page = message->GetArgumentList()->GetString(0);

	//load page
	if (!page.empty()) {
		browser->GetMainFrame()->LoadURL(page);
	}

	log+= fmt::format(",message(name={}, arg[0]={})", mname.ToString(), page.ToString());

	OutputDebugStringA(log.c_str());

	return true;
}

void anCefClient::PlatformTitleChange(CefRefPtr<CefBrowser> browser, const CefString & title)
{
	CefWindowHandle hwnd = browser->GetHost()->GetWindowHandle();
	SetWindowText(hwnd, std::wstring(title).c_str());
}



