#include "pch.h"
#include "Thread.h"
#include "Share.h"
#include<TCHAr.h>

void CThread::Run(void* lpVoid)
{
	HWND hWnd = ((CShare*)lpVoid)->hWnd;


	
		while (((CShare*)lpVoid)->mflg) {
		//	::PostMessage(hWnd, WM_USER_MSG, WPARAM(0	), LPARAM(0));
			MessageBox(hWnd, L"test", L"test", MB_ABORTRETRYIGNORE);
			HWND hWnsd = FindWindow(NULL,L"test");
			if (hWnsd)
			{
				::PostMessage(hWnsd, WM_CLOSE, 0, 0);

			}
			Sleep(10);
		}
	

	::PostMessage(hWnd, WM_USER_FIN, WPARAM(0), LPARAM(0));
	_endthread();
}

CThread::CThread(void)
{
}

CThread::~CThread(void)
{
}