/*
ウィンドウに対するユーザ操作の受け取り方に関する部分です。
*/

#include <windows.h>
#include <gdiplus.h>

LRESULT CALLBACK WndProc(
    HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static int x, y;
    HDC hdc;
    PAINTSTRUCT ps;

    switch (uMsg) {
    case WM_LBUTTONDOWN:
        y = HIWORD(lParam);
        x = LOWORD(lParam);
        InvalidateRect(hwnd, NULL, TRUE);  // 領域無効化
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        Rectangle(hdc, x - 10, y - 10, x + 10, y + 10);
        EndPaint(hwnd, &ps);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}