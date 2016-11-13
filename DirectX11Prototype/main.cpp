#include <windows.h>    // include the basic windows header file


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//handle ID for the window
	HWND windowHandle;

	//holds information about the window
	WNDCLASSEX windowClassInfo;

	//whipe the windowClass info struct
	ZeroMemory(&windowClassInfo, sizeof(WNDCLASSEX));

	windowClassInfo.cbSize = sizeof(WNDCLASSEX);
	windowClassInfo.style = CS_HREDRAW | CS_VREDRAW;
	windowClassInfo.lpfnWndProc = WindowProc;
	windowClassInfo.hInstance = hInstance;
	windowClassInfo.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClassInfo.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowClassInfo.lpszClassName = L"DirectXPrototype";
//	windowClassInfo.lpszMenuName;
//	windowClassInfo.cbClsExtra;
//	windowClassInfo.cbWndExtra;
//	windowClassInfo.hIcon;
//	windowClassInfo.hIconSm;

	//register the window class
	RegisterClassEx(&windowClassInfo);

	//create the window
	windowHandle = CreateWindowEx(NULL, L"DirectXPrototype", L"DirectXPrototype", WS_OVERLAPPEDWINDOW, 300, 300, 500, 400, NULL, NULL, hInstance, NULL);

	//show window on the screen
	ShowWindow(windowHandle, nShowCmd);

	//Holds any event messages
	MSG eventMessageHolder;

	//wait for a message
	while (GetMessage(&eventMessageHolder, NULL, 0, 0))
	{
		TranslateMessage(&eventMessageHolder);
		DispatchMessage(&eventMessageHolder);
	}



	return 0;
}