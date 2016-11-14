#include <windows.h>    // include the basic windows header file
#include <windowsx.h>

// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam);

// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	// the handle for the window, filled by a function
	HWND windowHandler;
	// this struct holds information for the window class
	WNDCLASSEX windowClassInfo;

	// clear out the window class for use
	ZeroMemory(&windowClassInfo, sizeof(WNDCLASSEX));

	// fill in the struct with the needed information
	windowClassInfo.cbSize = sizeof(WNDCLASSEX);
	windowClassInfo.style = CS_HREDRAW | CS_VREDRAW;
	windowClassInfo.lpfnWndProc = WindowProc;
	windowClassInfo.hInstance = hInstance;
	windowClassInfo.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClassInfo.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowClassInfo.lpszClassName = L"WindowClass1";

	// register the window class
	RegisterClassEx(&windowClassInfo);

	// calculate the size of the client area
	RECT windowRect = { 0, 0, 500, 400 };    // set the size, but not the position
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);    // adjust the size

														  // create the window and use the result as the handle
	windowHandler = CreateWindowEx(NULL,
		L"WindowClass1",    // name of the window class
		L"Our First Windowed Program",   // title of the window
		WS_OVERLAPPEDWINDOW,    // window style
		300,    // x-position of the window
		300,    // y-position of the window
		windowRect.right - windowRect.left,    // width of the window
		windowRect.bottom - windowRect.top,    // height of the window
		NULL,    // we have no parent window, NULL
		NULL,    // we aren't using menus, NULL
		hInstance,    // application handle
		NULL);    // used with multiple windows, NULL

				  // display the window on the screen
	ShowWindow(windowHandler, nCmdShow);

	// enter the main loop:

	// this struct holds Windows event messages
	MSG eventMessage;

	// wait for the next message in the queue, store the result in 'msg'
	while (GetMessage(&eventMessage, NULL, 0, 0))
	{
		// translate keystroke messages into the right format
		TranslateMessage(&eventMessage);

		// send the message to the WindowProc function
		DispatchMessage(&eventMessage);
	}

	// return this part of the WM_QUIT message to Windows
	return eventMessage.wParam;
}

// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// sort through and find what code to run for the message given
	switch (message)
	{
		// this message is read when the window is closed
	case WM_DESTROY:
	{
		// close the application entirely
		PostQuitMessage(0);
		return 0;
	} break;
	}

	// Handle any messages the switch statement didn't
	return DefWindowProc(hWnd, message, wParam, lParam);
}