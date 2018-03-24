#pragma once

#include <Windows.h>
#include <string>

class Window {
private:
	HWND m_hWnd = nullptr;

public :
	Window(const std::basic_string<TCHAR> &ClassName, const std::basic_string<TCHAR> &WindowName,
		int nX, int nY, int nWidth, int nHeight, HINSTANCE hInstacne, void *pData = nullptr);

	Window(const std::basic_string<TCHAR> &ClassName, const std::basic_string<TCHAR> &WindowName,
		HINSTANCE hInstance, void *pDAta = nullptr);

	inline virtual ~Window(void) { if (IsWindow(m_hWnd)) DestroyWindow(m_hWnd); }

	inline void Show(bool bShow) { ShowWindow(m_hWnd, bShow ? SW_SHOW : SW_HIDE); }

	inline HWND GetHwnd(void) const { return m_hWnd; }
};