#include "stdafx.h"
#include "WinAPI.h"
#include <tchar.h>
#include <Windows.h>
#include <string>
#include <list>

void SetRandomPixel(HDC hDC, UINT iBeginX, UINT iBeginY, UINT iEndX, UINT iEndY) {

	COLORREF value = 0;

	for (UINT i = iBeginX; i < iEndX; i++)
	{
		for (UINT j = iBeginY; j < iEndY; j++)
		{
			value = RGB(rand() % 256, rand() % 256, rand() % 256);
			SetPixel(hDC, i, j, value);
		}
	}
}

/*void SetRandomPixel(HDC hDC, UINT iWidth, UINT iHeight) {

	COLORREF value = 0;

	for (UINT i = 0; i < iWidth; i++)
	{
		for (UINT j = 0; j < iHeight; j++)
		{
			value = RGB(rand() % 256, rand() % 256, rand() % 256);

			SetPixel(hDC, i, j, value);
		}
	}
}*/



LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {

	static bool bMouseDown = false;
	static std::list<POINT> draw;

	switch (iMsg)
	{

	case WM_MOUSEMOVE:
	{
		if (bMouseDown) {

			RECT rc = {};

			rc.left = LOWORD(lParam) - 10;
			rc.top = HIWORD(lParam) - 10;

			rc.right = rc.left + 20;
			rc.bottom = rc.top + 20;

			//draw.push_back(POINT{ LOWORD(lParam), HIWORD(lParam) });

			InvalidateRect(hWnd, &rc, false);

			/*HDC hDC = GetDC(hWnd);

			LineTo(hDC, LOWORD(lParam), HIWORD(lParam));

			ReleaseDC(hWnd, hDC);*/
		}

		break;
	}
		
	case WM_LBUTTONDOWN:
	{
		HDC hDC = GetDC(hWnd);
		
		bMouseDown = true;

		//MoveToEx(hDC, LOWORD(lParam), HIWORD(lParam), nullptr);

		draw.push_back(POINT{ LOWORD(lParam), HIWORD(lParam) });

		//ReleaseDC(hWnd, hDC);

		break;
	}

	case WM_LBUTTONUP:
	{
		bMouseDown = false;
		break;
	}

	case WM_PAINT:
	{
		//HDC hDC = GetDC(hWnd);

		PAINTSTRUCT ps = {};
		HDC hDC = BeginPaint(hWnd, &ps);

		SetRandomPixel(hDC,
			ps.rcPaint.left,
			ps.rcPaint.top,
			ps.rcPaint.right,
			ps.rcPaint.bottom
			);

		EndPaint(hWnd, &ps);

		/*if (draw.size() > 1) {
			MoveToEx(hDC, draw.front().x, draw.front().y, nullptr);

			for (auto i = ++draw.begin(); i != draw.end(); i++) {
				LineTo(hDC, i->x, i->y);
			}
		}*/

		//ReleaseDC(hWnd, hDC);

		break;
	}

	case WM_CHAR:
	{
		HDC hDC = GetDC(hWnd);
		static std::basic_string<TCHAR> tstr;

		if (wParam == VK_BACK) {
			if (tstr.length() > 0) {
				tstr.erase(tstr.end() - 1, tstr.end());
			}
		} else{
			tstr += static_cast<TCHAR>(wParam);
		}
		
		TextOut(hDC, 10, 10, tstr.c_str(), tstr.length());
		

		ReleaseDC(hWnd, hDC);
		break;
	}
		

	case WM_DESTROY:
		
		PostQuitMessage(0);
		break;
	}


	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}



INT APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, TCHAR *pszLine, INT nShow)
{
	HWND hWnd;
	WNDCLASS wc;
	MSG msg;

	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDC_ICON);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wc.hbrBackground = CreateSolidBrush(RGB(255, 0, 0));
	wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("MyApp");

	RegisterClass(&wc);

	hWnd = CreateWindow(TEXT("MyApp"), TEXT("Sample Application"),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, SW_SHOW);

	while(GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 0;
}


