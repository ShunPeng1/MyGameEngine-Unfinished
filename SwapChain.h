#pragma once
#include <d3d11.h>

class DeviceContext;

class SwapChain
{
private:
	IDXGISwapChain* m_swap_chain;
	ID3D11RenderTargetView* m_render_target_view;


	//DeviceContext is a friend class to pass the m_render_target_view of SwapChain 
	friend class DeviceContext;
public:

	SwapChain();
	~SwapChain();

	bool init(HWND hwnd , UINT width, UINT height);
	bool release();
	
	bool present(bool vsync);

	
};

