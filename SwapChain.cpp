#include "SwapChain.h"
#include "GraphicsEngine.h"
SwapChain::SwapChain()
{
}

SwapChain::~SwapChain()
{
}

bool SwapChain::init(HWND hwnd, UINT width, UINT height)
{
    ID3D11Device* device = GraphicsEngine::get()->m_d3d_device;

    DXGI_SWAP_CHAIN_DESC desc;
    ZeroMemory(&desc, sizeof(desc));

    //We need to have 2 buffer : front and back, to swap between the 2
    //But the window screen is already the front buffer, so we need only 1 for back buffer
    desc.BufferCount = 1;
    desc.BufferDesc.Width = width;
    desc.BufferDesc.Height = height;
    desc.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    desc.BufferDesc.RefreshRate.Denominator = 1;
    desc.BufferDesc.RefreshRate.Numerator = 60;
    desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    desc.OutputWindow = hwnd;
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.Windowed = TRUE;

    //Create the swap chain for the window indicated by HWND parameter
    HRESULT hresult = GraphicsEngine::get()->m_dxgi_factory->CreateSwapChain(device, &desc, &m_swap_chain);
    
    if (FAILED(hresult)) {
        return false;
    }

    //To get the back buffer for device context to clearRenderTargetColor, changing &buffer
    ID3D11Texture2D* buffer = nullptr;
    hresult = m_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**) &buffer);

    if (FAILED(hresult)) {
            return false;
    }

    //After checking we can CreateRenderTargetView from the device ( ID3D11Device* device = GraphicsEngine::get()->m_d3d_device)
    hresult = device->CreateRenderTargetView(buffer, NULL, &m_render_target_view);
    buffer->Release();

    if (FAILED(hresult)) {
        return false;
    }

    return true;
}

bool SwapChain::release()
{
    m_swap_chain->Release();
    delete this;
    return false;
}

bool SwapChain::present(bool vsync)
{
    m_swap_chain->Present(vsync, NULL);
    return true;
}
