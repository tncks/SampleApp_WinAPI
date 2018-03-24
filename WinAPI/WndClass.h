#pragma once

#include <Windows.h>
#include <string>

class MyWndClass : private WNDCLASS {
private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

public :
	MyWndClass(HINSTANCE hInstance);
	virtual ~MyWndClass(void) {}

	std::basic_string<TCHAR> GetName(void) const {
		return TEXT("MyWndClass");
	};
};