#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"

GraphicsEngine* GraphicsEngine::get()
{
	//Singleton the graphic engine, create at runtime
	static GraphicsEngine engine;
	return &engine;
}

SwapChain* GraphicsEngine::createSwapChain()
{
	return new SwapChain();
}

DeviceContext* GraphicsEngine::getImmediateDeviceContext()
{
	return this->m_imm_device_context;
}

GraphicsEngine::GraphicsEngine()
{
}

GraphicsEngine::~GraphicsEngine()
{
}

bool GraphicsEngine::init()
{
	//Go to Project -> Properties -> Linker -> Input -> (AdditionalDependencies) -> Add the: d3d11.lib

	
	D3D_DRIVER_TYPE driver_types[] = {//To list all device draw on the screen
		D3D_DRIVER_TYPE_HARDWARE,	// Execute performance on device GPU (best)
		D3D_DRIVER_TYPE_WARP,		// Execute performance on device CPU (second)
		D3D_DRIVER_TYPE_REFERENCE	// Execute performance on rock		 (slow)
	};
	int driver_types_size = ARRAYSIZE(driver_types);

	D3D_FEATURE_LEVEL feature_levels[] = {//the directX version we are using
		D3D_FEATURE_LEVEL_11_0
	};
	int feature_level_sizes = ARRAYSIZE(feature_levels);


	HRESULT result = 0;
	ID3D11DeviceContext* m_imm_context;

	for (int i_driver_types =0 ; i_driver_types < driver_types_size; i_driver_types++ ) {
		result = D3D11CreateDevice(NULL, driver_types[i_driver_types], NULL, NULL,
			feature_levels, feature_level_sizes, D3D11_SDK_VERSION,
			&m_d3d_device, &m_feather_level, &m_imm_context //these are & variable that got change in the fuction
		);

		//if the device (GPU, CPU, ...) is on computer , we use that device then break
		// else we not use that we use the next one
		if (SUCCEEDED(result)) break;
	}

	//no device for directX
	if (FAILED(result)) return false;

	//Create a DeviceContext
	m_imm_device_context = new DeviceContext(m_imm_context);

	//Reject the XGI factory to create method SwapChain
	//these function return the instance of the class
	//m_d3d_device is child of m_dxgi_device is child of m_dxgi_adapter is child of m_dxgi_factory
	m_d3d_device->QueryInterface(__uuidof(IDXGIDevice), (void**) &m_dxgi_device);
	m_dxgi_device->GetParent(__uuidof(IDXGIAdapter), (void**) &m_dxgi_adapter);
	m_dxgi_adapter->GetParent(__uuidof(IDXGIFactory), (void**)&m_dxgi_factory);
	return true;
}

bool GraphicsEngine::release()
{
	//delete all the pointer
	m_dxgi_factory->Release();
	m_dxgi_adapter->Release();
	m_dxgi_device->Release();
	m_d3d_device->Release();

	m_imm_device_context->release();

	return true;
}
