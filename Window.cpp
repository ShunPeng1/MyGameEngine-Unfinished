
#include "Window.h"

Window *window = nullptr;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam){
    switch (msg) {
    //WINDOW REACTION

        case WM_CREATE://Called when the window created
            window->setHWND(hwnd);
            window->onCreate();
            break;

        case WM_DESTROY://Called when the window destroyed
            window->onDestroy();
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wparam, lparam);
    }
    return NULL;
}


bool Window::init()
{
    
    //this is like a template that you can create multiple of window with the same type WNDCLASSEX wc 
    WNDCLASSEX wc;
    //There are WNDCLASS and WNDCLASSEX, EX means extra , means more function. Along with function have EX
    
    //register the window class of the window.h by storing informatoin on WNDCLASSEX object
    wc.cbClsExtra = NULL;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbWndExtra = NULL;
    wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = NULL;
    wc.lpfnWndProc = &WndProc;
    wc.lpszClassName = "ShunPengWindowClass";
    wc.lpszMenuName = "";
    wc.style = NULL;

    if (!RegisterClassEx(&wc)) {// If fail the registration of the class, return false
        return false;
    }

    if (!window) {
        window = this;
    }

    //create the window
    m_hwmd = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        "ShunPengWindowClass",//name of the window class, smae with wc.lpszClassName
        "DirectX Application",//title of the window
        WS_OVERLAPPEDWINDOW,//window style
        CW_USEDEFAULT, CW_USEDEFAULT,//x, y position respectively
        800, 450,//height , width window respectively
        NULL,//we have no parent
        NULL,//we aren't using menus
        NULL,//application handle
        NULL//used in multiple window
    );

    //check for window fail
    if(!m_hwmd){
        return false;
    }

    //marked the window is running
    m_is_run = true;

    //show up the window
    ShowWindow(m_hwmd, SW_SHOW);
    UpdateWindow(m_hwmd);

    //now enter the main loop

    return true;
}

bool Window::broadcast()
{
    MSG msg;
    //http://www.directxtutorial.com/Lessons/11/A1-Win32/3/3.gif

    //Receiving then Analyse message queue
    window->onUpdate();
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        // translate keystroke messages into the right format
        TranslateMessage(&msg);

        // send the message to the WindowProc function
        DispatchMessage(&msg);
    }

    
    Sleep(0);
    return true;
}

bool Window::release()
{
    //Destroy window on close
    if (!DestroyWindow(m_hwmd)) return false;
    return true;
}

bool Window::isRun()
{
    return m_is_run;
}

void Window::onCreate()
{
}

void Window::setHWND(HWND hwnd)
{
    this->m_hwmd = hwnd;
}

RECT Window::getClientWindowRect()
{
    RECT rect;
    ::GetClientRect(this->m_hwmd, &rect);
    return rect;
}
void Window::onUpdate()
{
}

void Window::onDestroy()
{
    m_is_run = false;
}

Window::Window() {

}

Window::~Window() {

}