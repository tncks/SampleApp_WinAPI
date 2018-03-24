#pragma once

#include <Windows.h>
#include "WndClass.h"
#include "Window.h"

class SampleApp {
private:
	MyWndClass *m_pClass = nullptr;
	Window *m_pMainWindow = nullptr;

public:
	SampleApp(HINSTANCE hInstance);
	virtual ~SampleApp(void) {
		delete m_pClass;
		delete m_pMainWindow;
	}

	void Run(void);
};