// App.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "App.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                        // current instance
static WCHAR szTitle[MAX_LOADSTRING] = _T("ChessApp");  // the title bar text
WCHAR szWindowClass[MAX_LOADSTRING];                    // the main window class name
static WCHAR greeting[] = _T("Hello, Windows Desktop!");// greeting message

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK       EnumChildProc(HWND hwndChild, LPARAM lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDC_APP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_APP));

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

    return (int)msg.wParam;
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

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_APP);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    // create two child windows

    // CreateWindowW is just a macro for calling CreateWindowEx;
    // refer to https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindoww
    CreateWindowW(0, (LPCTSTR) NULL, WS_CHILD | WS_BORDER, 0, 0, 0, 0, hWnd, (HMENU)(int)(ID_GAME),
        hInstance, NULL);

    CreateWindowW(0, (LPCTSTR)NULL, WS_CHILD | WS_BORDER, 0, 0, 0, 0, hWnd, (HMENU)(int)(ID_MESSAGEBOX),
        hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
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
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: Add any drawing code that uses hdc here...
        TextOut(hdc, 5, 5, greeting, (int) _tcslen(greeting));
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_SIZE:   // main window changed size 

            // Get the dimensions of the main window's client 
            // area, and enumerate the child windows. Pass the 
            // dimensions to the child windows during enumeration. 
        RECT rcClient;
        GetClientRect(hWnd, &rcClient);
        EnumChildWindows(hWnd, EnumChildProc, (LPARAM)&rcClient);
        return 0;
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

BOOL CALLBACK EnumChildProc(HWND hwndChild, LPARAM lParam)
{
    LPRECT rcParent;
    int i;

    // Retrieve the child-window identifier. Use it to set the 
    // position of the child window. 

    // i = 0 for ID_GAME, 1 for ID_MESSAGEBOX
    i = (GetWindowLong(hwndChild, GWL_ID) == ID_GAME) ? 0 : 1;

    // Size and position the child window.  

    rcParent = (LPRECT)lParam;
    MoveWindow(hwndChild,
        (rcParent->right / 2) * i,
        0,
        rcParent->right / 2,
        rcParent->bottom,
        TRUE);

    // Make sure the child window is visible. 

    ShowWindow(hwndChild, SW_SHOW);

    return TRUE;
}