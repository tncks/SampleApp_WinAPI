#include "stdafx.h"
#include "Window.h"

Window::Window(const std::basic_string<TCHAR> &ClassName, const std::basic_string<TCHAR> &WindowName,
	int nX, int nY, int nWidth, int nHeight, HINSTANCE hInstance, void *pData)
{
	m_hWnd = CreateWindow(ClassName.c_str(), WindowName.c_str(),
		WS_OVERLAPPEDWINDOW, nX, nY, nWidth, nHeight, nullptr, nullptr, hInstance, pData);
}

Window::Window(const std::basic_string<TCHAR> &ClassName, const std::basic_string<TCHAR> &WindowName, HINSTANCE hInstance, void *pData)
{
	m_hWnd = CreateWindow(ClassName.c_str(), WindowName.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, hInstance, pData);
}