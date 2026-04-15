#pragma once
#include <d3d11.h>
#include <dxgi.h>

namespace Hooks {
    void Setup();
    void Destroy();

    inline HRESULT(__stdcall* oPresent)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) = nullptr;
    HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);

    inline WNDPROC oWndProc = nullptr;
    LRESULT __stdcall hkWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    // Signalled at the END of every hkPresent frame.
    // Destroy() waits on this so it never tears mid-frame.
    inline HANDLE g_FrameEvent = nullptr;
}
