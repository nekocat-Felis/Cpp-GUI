/*
ウィンドウに対するユーザ操作の受け取り方に関する部分です。
*/

#include <windows.h>
#include <gdiplus.h>

#pragma comment (lib, "Gdiplus.lib")

LRESULT CALLBACK WndProc(
    HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static int x, y;
    HDC hdc;
    PAINTSTRUCT ps;

    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}