#pragma once

#include <Windows.h>

class Window
{
protected:
	HWND m_hwmd ;
	bool m_is_run;


public:
	Window();
	~Window();

	//initialize the window
	bool init();
	bool broadcast();

	//release the window
	bool release();
	bool isRun();

	//SwapChain 
	RECT getClientWindowRect();
	void setHWND(HWND hwnd);

	//EVENT
	virtual void onCreate()=0;
	virtual void onUpdate();
	virtual void onDestroy();

};

