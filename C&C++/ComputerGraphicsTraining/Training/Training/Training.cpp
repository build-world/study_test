// Training.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Training.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
//custom def
int from_x = 0, from_y = 0, to_x = 0, to_y = 0;


// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
//custom def
BOOL CALLBACK ProcDigProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
	AllocConsole();
	
    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TRAINING, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TRAINING));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
	FreeConsole();
    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TRAINING));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TRAINING);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
			case ID_FILE_PROCESS:
			{
				HWND hProcDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, ProcDigProc);
				if (hProcDlg) ShowWindow(hProcDlg, SW_SHOW);
			}
				break;
            case IDM_EXIT:
                //DestroyWindow(hWnd);
				PostMessage(hWnd, WM_CLOSE, NULL, NULL);
				break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_CREATE:
	{

	}
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_CLOSE:
	{
		int ret = MessageBox(hWnd, L"Are you sure to exit?", L"Caution!", MB_YESNO);
		if (ret == IDYES) PostMessage(hWnd, WM_DESTROY, NULL, NULL);
	}
		break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

BOOL CALLBACK ProcDigProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	//PAINTSTRUCT ps;
	//HDC hdc;
	//static HPEN hPen;
	switch (message)
	{
	case WM_COMMAND:
		{
			int wmId = LOWORD(wParam);
			switch (wmId)
			{
			case IDC_BUTTON1:
				{
				
				}
				break;
			case IDC_BUTTON2:
				{
					from_x = (int)GetDlgItemInt(hDlg, IDC_EDIT1, NULL, TRUE);
					from_y = (int)GetDlgItemInt(hDlg, IDC_EDIT2, NULL, TRUE);
					to_x = (int)GetDlgItemInt(hDlg, IDC_EDIT3, NULL, TRUE);
					to_y = (int)GetDlgItemInt(hDlg, IDC_EDIT4, NULL, TRUE);
					/*
					from_x = 0;
					from_y = 0;
					to_x = 100;
					to_y = 100;
					*/
					PAINTSTRUCT ps;
					HDC hdc = GetDC(hDlg);
					//SelectObject(hdc, hPen);
					MoveToEx(hdc, from_x, from_y, NULL);
					LineTo(hdc, to_x, to_y);
					EndPaint(hDlg, &ps);
					ReleaseDC(hDlg, hdc);
					//PostMessage(hDlg, WM_PAINT, 0, 233);
				}
				break;
			}
		}
		break;
	case WM_CREATE:
		//hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 255));
		break;
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc;
			WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), TEXT("WM_PAIN\n"), 10, NULL, NULL);
			hdc = BeginPaint(hDlg, &ps);
			EndPaint(hDlg, &ps);
		}
		break;
	case WM_CLOSE:
		PostMessage(hDlg, WM_DESTROY, NULL, NULL);
		break;
	case WM_DESTROY:
		//DeleteObject(hPen);
		DestroyWindow(hDlg);
		break;
	default:
		return FALSE;
	}
	return TRUE;
}

//void DrawLine()
