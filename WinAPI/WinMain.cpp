#include "stdafx.h"
#include <tchar.h>
#include "SampleApp.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, TCHAR *, int)
{
	SampleApp *pApp = nullptr;

	pApp = new SampleApp(hInstance);
	pApp->Run();

	delete pApp;

	return 0;
}