#pragma once
#include <process.h>
#include <Windows.h>
#define WM_USER_MSG WM_USER + 1901
#define WM_USER_FIN WM_USER + 1902

class CThread
{
public:
	static void Run(void *);
public:
	CThread(void);
	~CThread(void);
};