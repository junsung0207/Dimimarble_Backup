#include "dimimarble.h"

HWND getConsoleWindowHandle() {

	WCHAR title[2048] = { 0 };
	GetConsoleTitle(title, 2048);
	HWND hWnd = FindWindow(NULL, title);
	SetConsoleTitle(title);
	return hWnd;
}

int GetDPI(HWND hWnd) {
	HANDLE user32 = GetModuleHandle(TEXT("user32"));
	FARPROC func = GetProcAddress(user32, "GetDpiForWindow");
	if (func == NULL)
		return 96;
	return ((UINT(__stdcall *)(HWND))func)(hWnd);
}

void GetBMP(HDC hdc, HDC memdc, HBITMAP image) {
	BITMAP bitmap;
	HDC bitmapDC = CreateCompatibleDC(hdc);

	GetObject(image, sizeof(bitmap), &bitmap);
	SelectObject(bitmapDC, image);
	BitBlt(memdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, bitmapDC, 0, 0, SRCCOPY);

	DeleteDC(bitmapDC);
}

void paint(HWND hWnd, int dpi, HBITMAP image) {

	HDC hdc = GetDC(hWnd);
	HDC memdc = CreateCompatibleDC(hdc);

	//이미지정보를 넣기 위한 공간을 640*480으로 만든다.
	HBITMAP bitmap = CreateCompatibleBitmap(hdc, Pic_W, Pic_H);

	//해당 이미지 정보와 메모리 공간을 연결시킨다.
	SelectObject(memdc, bitmap);

	//image를 memdc에 담아오도록 한다.
	GetBMP(hdc, memdc, image);

	// 콘솔창에 memdc에 들어 있는 이미지를 640*480으로 그려준다.
	StretchBlt(hdc, Pic_WP, Pic_HP, Pic_W, Pic_H, memdc, 0, 0, Pic_W, Pic_H, SRCCOPY);

	DeleteDC(memdc);
	DeleteObject(bitmap);
	ReleaseDC(hWnd, hdc);
}