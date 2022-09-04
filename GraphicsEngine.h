#pragma once

#include <d3d11.h>

class SwapChain;
class DeviceContext;

class GraphicsEngine
{
private:
	//Variable for D3D11 device
	ID3D11Device* m_d3d_device;
	D3D_FEATURE_LEVEL m_feather_level;
	

	//Variable for SwapChain
	IDXGIDevice*  m_dxgi_device;
	IDXGIAdapter* m_dxgi_adapter;
	IDXGIFactory* m_dxgi_factory;

	//Variable for DeviceContext
	DeviceContext* m_imm_device_context;

	friend class SwapChain;//allow SwapChain to access the above variable


public:

	static GraphicsEngine* get();

	SwapChain* createSwapChain();
	DeviceContext* getImmediateDeviceContext();
private:

public:

	GraphicsEngine();
	~GraphicsEngine();

	//initialize and release graphic engine
	bool init();
	bool release();

};

