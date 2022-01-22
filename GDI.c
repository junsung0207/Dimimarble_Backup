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

	//�̹��������� �ֱ� ���� ������ 640*480���� �����.
	HBITMAP bitmap = CreateCompatibleBitmap(hdc, Pic_W, Pic_H);

	//�ش� �̹��� ������ �޸� ������ �����Ų��.
	SelectObject(memdc, bitmap);

	//image�� memdc�� ��ƿ����� �Ѵ�.
	GetBMP(hdc, memdc, image);

	// �ܼ�â�� memdc�� ��� �ִ� �̹����� 640*480���� �׷��ش�.
	StretchBlt(hdc, Pic_WP, Pic_HP, Pic_W, Pic_H, memdc, 0, 0, Pic_W, Pic_H, SRCCOPY);

	DeleteDC(memdc);
	DeleteObject(bitmap);
	ReleaseDC(hWnd, hdc);
}