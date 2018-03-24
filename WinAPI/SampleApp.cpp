#include "stdafx.h"
#include "SampleApp.h"

SampleApp::SampleApp(HINSTANCE hInstance)
{
	m_pClass = new MyWndClass(hInstance);
	m_pMainWindow = new Window(m_pClass->GetName(), TEXT("SampleApp"), hInstance);
}

void SampleApp::Run(void)
{

	MSG msg = {};

	m_pMainWindow->Show(true);

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}