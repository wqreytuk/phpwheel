
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include<regex>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <tchar.h>
#include <Windows.h> 
#include <winsvc.h>
#include <strsafe.h>
#include <winuser.h>
#include <synchapi.h>

#include<tlhelp32.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <tchar.h>
#include <stdio.h>

// Need to link with Iphlpapi.lib and Ws2_32.lib
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <vector>


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedOk17();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK17, &CAboutDlg::OnBnClickedOk17)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
	
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_phplist);
	DDX_Control(pDX, IDC_COMBO2, m_domalist);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_MESSAGE(WM_USER_MSG, &CMFCApplication1Dlg::paomadeng)
	ON_MESSAGE(WM_USER_FIN, &CMFCApplication1Dlg::stoppaomadeng)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK3, &CMFCApplication1Dlg::OnBnClickedOk3)
	ON_BN_CLICKED(IDOK4, &CMFCApplication1Dlg::OnBnClickedOk4)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication1Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK8, &CMFCApplication1Dlg::OnBnClickedOk8)
	ON_BN_CLICKED(IDOK9, &CMFCApplication1Dlg::OnBnClickedOk9)
	ON_BN_CLICKED(IDOK5, &CMFCApplication1Dlg::OnBnClickedOk5)
	ON_BN_CLICKED(IDOK7, &CMFCApplication1Dlg::OnBnClickedOk7)
	ON_BN_CLICKED(IDOK6, &CMFCApplication1Dlg::OnBnClickedOk6)
	ON_BN_CLICKED(IDOK10, &CMFCApplication1Dlg::OnBnClickedOk10)
	ON_BN_CLICKED(IDOK11, &CMFCApplication1Dlg::OnBnClickedOk11)
	ON_BN_CLICKED(IDOK12, &CMFCApplication1Dlg::OnBnClickedOk12)
	ON_BN_CLICKED(IDOK13, &CMFCApplication1Dlg::OnBnClickedOk13)
	ON_BN_CLICKED(IDOK14, &CMFCApplication1Dlg::OnBnClickedOk14)
	ON_BN_CLICKED(IDOK15, &CMFCApplication1Dlg::OnBnClickedOk15)
	ON_BN_CLICKED(IDOK16, &CMFCApplication1Dlg::OnBnClickedOk16)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication1Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK2, &CMFCApplication1Dlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDCANCEL2, &CMFCApplication1Dlg::OnBnClickedCancel2)
	ON_BN_CLICKED(IDOK18, &CMFCApplication1Dlg::OnBnClickedOk18)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCApplication1Dlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDOK19, &CMFCApplication1Dlg::OnBnClickedOk19)
	ON_BN_CLICKED(IDOK20, &CMFCApplication1Dlg::OnBnClickedOk20)
	ON_BN_CLICKED(IDOK21, &CMFCApplication1Dlg::OnBnClickedOk21)
	ON_BN_CLICKED(IDOK22, &CMFCApplication1Dlg::OnBnClickedOk22)
	ON_EN_CHANGE(IDC_EDIT9, &CMFCApplication1Dlg::OnEnChangeEdit9)
	ON_BN_CLICKED(IDOK23, &CMFCApplication1Dlg::OnBnClickedOk23)
	ON_BN_CLICKED(IDOK25, &CMFCApplication1Dlg::OnBnClickedOk25)
	ON_BN_CLICKED(IDOK24, &CMFCApplication1Dlg::OnBnClickedOk24)
	ON_BN_CLICKED(IDOK26, &CMFCApplication1Dlg::OnBnClickedOk26)
	ON_BN_CLICKED(IDOK27, &CMFCApplication1Dlg::OnBnClickedOk27)
	ON_BN_CLICKED(IDOK28, &CMFCApplication1Dlg::OnBnClickedOk28)
	ON_BN_CLICKED(IDOK29, &CMFCApplication1Dlg::OnBnClickedOk29)
	ON_BN_CLICKED(IDOK30, &CMFCApplication1Dlg::OnBnClickedOk30)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//获取本程序的绝对路径
	get_current_exe_path();

	//从用户配置文件中读取一系列配置信息
	read_user_ini();

	m_is_apache_running = false;
	m_is_mysql_running = false;
	m_is_mariadb_running = false;

	m_apache_process_id = 0;
	m_mysql_process_id = 0;
	m_mariadb_process_id = 0;

	//将apache坚挺的端口显示到IDE_EDIT10控件上
	//初始化apache监听端口
	if (!m_is_apache_listen_port_conf)
	{
		get_apache_listen_port();
		write_apache_listen_port_to_user_ini();
	}
	GetDlgItem(IDC_EDIT10)->SetWindowText(m_apache_listen_port);

	//初始化mysql和mariadb监听端口
	//判断用户是否有mariadb，根据配置文件中有无mariadb_path来进行判断
	if (m_is_mariadb_path_conf) 
	{
		if (!m_is_mariadb_listen_port_conf)
		{
			get_mariadb_listen_port();
			write_mariadb_listen_port_to_user_ini();
		}
	}
	if (!m_is_mysql_listen_port_conf) {
		get_mysql_listen_port();
		write_mysql_listen_port_to_user_ini();
	}

	//将mariadb_path的绝对路径显示到文本框中
	if (m_is_mariadb_path_conf)
		GetDlgItem(IDC_EDIT9)->SetWindowText(m_mariadb_path);
	//用户配置文件中没有mariadb_path，说明之前没有使用过，在文本框中显示提示信息
	else 
	{
		CString mariadb_tips = L"输入mariadbd.exe绝对路径";
		GetDlgItem(IDC_EDIT9)->SetWindowText(mariadb_tips);
	}

	if (!m_is_current_dbserver_conf)
	{
		m_current_db_server = L"mysql";

		CString strLine = L"";
		CString arrLines = L"";
		TRY
		{
			CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
				{
					continue;
				}
				strLine = strLine + L"\n";
				arrLines = arrLines + strLine;
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL

		CFile::Remove(m_path + L"\\user.ini");
		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines + L"currentdb=" + m_current_db_server);
		cfile.Close();
	}

	if (m_current_db_server == L"mysql")
	{
		GetDlgItem(IDOK22)->SetWindowText(L"mysql---->mariadb");
		GetDlgItem(IDC_EDIT8)->SetWindowText(L"当前数据库为mysql");
	}
	else if (m_current_db_server == L"mariadb") 
	{
		GetDlgItem(IDOK22)->SetWindowText(L"mariadb---->mysql");
		GetDlgItem(IDC_EDIT8)->SetWindowText(L"当前数据库为mariadb");
	}

	//填充php下拉列表框
	m_phplist.AddString(L"php-5.2.17");
	m_phplist.AddString(L"php-5.3.29-nts");
	m_phplist.AddString(L"php-5.4.45");
	m_phplist.AddString(L"php-5.4.45-nts");
	m_phplist.AddString(L"php-5.5.38");
	m_phplist.AddString(L"php-5.6.27-nts");
	m_phplist.AddString(L"php-7.0.12-nts");
	m_phplist.AddString(L"php-7.1.13-nts");
	m_phplist.AddString(L"php-7.2.1-nts");
	m_phplist.AddString(L"php-7.4.23-nts");

	m_phplist.SetCurSel(m_phplist.FindString(-1, m_current_select_php));

	//根据m_current_select_php进行apache服务器的配置
	OnBnClickedOk13();

	//给添加php配置的两个editcontrol设置默认值
	GetDlgItem(IDC_EDIT4)->SetWindowText(L"php.exe路径（不要有中文件字符串和空格）");
	GetDlgItem(IDC_EDIT5)->SetWindowText(L"名称（不要有中文件字符串和空格）");

	GetDlgItem(IDC_EDIT6)->SetWindowText(L"域名");
	GetDlgItem(IDC_EDIT7)->SetWindowText(L"根目录路径");

	SetTimer(1, 100, NULL);

	return TRUE;
}

void CMFCApplication1Dlg::get_current_exe_path()
{
	GetModuleFileName(NULL, m_path.GetBuffer(MAX_PATH), MAX_PATH);
	m_path.ReleaseBuffer();

	//m_paomadeng = true;
	char temp_string[MAX_PATH];
	strcpy_s(temp_string, CStringA(m_path).GetString());

	int end_pos = 0;
	for (int i = 0; i <= MAX_PATH; i++) {
		//正着数，如果读取到\0，则说明此处为字符串结尾
		if (temp_string[i] != '\0')
			continue;
		//end_pos记录下结尾的位置
		end_pos = i;
		break;
	}

	//slash_start_pos记录最后一个\出现的位置
	int slash_start_pos = 0;
	for (int i = end_pos - 1; i >= 0; i--) {
		//倒着数，找到第一个\的位置，那么在这之前，就是本程序的程序名
		if (temp_string[i] != '\\')
			continue;
		else
		{
			slash_start_pos = i;
			break;
		}
	}

	//遍历到最后一个\出现的前一个位置，将所有字符累加起来，获得本程序的路径（不包含文件名）m_path
	m_path = L"";
	for (int i = 0; i < slash_start_pos; i++) {
		CString temp = CString(temp_string[i]);
		m_path += temp;
	}
}

void CMFCApplication1Dlg::get_apache_listen_port()
{
	if (GetFileAttributes(m_path + L"\\apache\\conf\\httpd.conf") != INVALID_FILE_ATTRIBUTES) {
		CString arrLines = L"";
		CString strLine = L"";
		TRY
		{
		   CStdioFile file(m_path + L"\\apache\\conf\\httpd.conf", CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
				{
					
					continue;
				}
				if (strLine.Find(L"Listen") != -1) {
					strLine.Replace(L"Listen ", L"");
					GetDlgItem(IDC_EDIT10)->SetWindowText(strLine);
					m_apache_listen_port = strLine;
					
					break;
				}
				
			}
			file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
	}
	else
	{
		MessageBox(L"你他妈把apache主配置文件弄到哪里去了！！！");
		ExitProcess(GetLastError());
	}
}

void CMFCApplication1Dlg::write_apache_listen_port_to_user_ini()
{
	//将监听端口写入用户配置文件
	if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES) {
		CString arrLines = L"";
		CString strLine = L"";
		TRY
		{
			CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n' || strLine.Find(L"apache_listen_port=") != -1)
				{
					continue;
				}
				strLine = strLine + L"\n";
				arrLines = arrLines + strLine;
				
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL

		CFile::Remove(m_path + L"\\user.ini");
		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines + L"apache_listen_port=" + m_apache_listen_port);
		cfile.Close();
	}
	else
	{
		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(L"apache_listen_port=" + m_apache_listen_port);
		cfile.Close();
	}
}

void CMFCApplication1Dlg::get_mysql_listen_port()
{
	if (GetFileAttributes(m_path + L"\\mysql\\my.ini") != INVALID_FILE_ATTRIBUTES) {
		CString arrLines = L"";
		CString strLine = L"";
		TRY
		{
		   CStdioFile file(m_path + L"\\mysql\\my.ini", CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
				{
					
					continue;
				}
				if (strLine.Find(L"port=") != -1) {
					strLine.Replace(L"port=", L"");
					m_mysql_listen_port = strLine;
					m_is_mysql_listen_port_conf = true;
					
					continue;
				}
				
			}
			file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
	}
	else
	{
		MessageBox(L"你他妈把mysql配置文件弄到哪里去了！！！");
		ExitProcess(GetLastError());
	}
}

void CMFCApplication1Dlg::write_mysql_listen_port_to_user_ini()
{
	//将监听端口写入用户配置文件
	if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES) {
		CString arrLines = L"";
		CString strLine = L"";
		TRY
		{
			CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n' || strLine.Find(L"mysql_listen_port=") != -1)
				{
					
					continue;
				}
				strLine = strLine + L"\n";
				arrLines = arrLines + strLine;
				
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			arrLines = arrLines + L"mysql_listen_port=" + m_mysql_listen_port;
		CFile::Remove(m_path + L"\\user.ini");
		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
	}
}

void CMFCApplication1Dlg::get_mariadb_listen_port()
{
	CString temp_mariadb_folder = m_mariadb_path;
	temp_mariadb_folder.Replace(L"bin\\mariadbd.exe", L"data\\");
	if (GetFileAttributes(temp_mariadb_folder + L"my.ini") != INVALID_FILE_ATTRIBUTES) {
		CString arrLines = L"";
		CString strLine = L"";
		TRY
		{
			CStdioFile file(temp_mariadb_folder + L"my.ini", CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
				{
					continue;
				}
				if (strLine.Find(L"port=") != -1) {
					strLine.Replace(L"port=", L"");
					m_mariadb_listen_port = strLine;
					m_is_mariadb_listen_port_conf = true;
					
					break;
				}
				
			}
			file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
	}
	else
	{
		MessageBox(L"你他妈把mariadb配置文件弄到哪里去了！！！");
		ExitProcess(GetLastError());
	}
}

void CMFCApplication1Dlg::write_mariadb_listen_port_to_user_ini()
{
	//将监听端口写入用户配置文件
	if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES) {
		CString arrLines = L"";
		CString strLine = L"";
		TRY
		{
			CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n' || strLine.Find(L"mariadb_listen_port=") != -1)
				{
					
					continue;
				}
				strLine = strLine + L"\n";
				arrLines = arrLines + strLine;
				
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			arrLines = arrLines + L"mariadb_listen_port=" + m_mariadb_listen_port;
		CFile::Remove(m_path + L"\\user.ini");
		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
	}
}

//读取用户配置，初始化一系列成员变量
void CMFCApplication1Dlg::read_user_ini()
{
	m_apache_listen_port = L"";
	m_mysql_listen_port = L"";
	m_mariadb_listen_port = L"";
	m_mariadb_path = L"";
	m_current_db_server = L"mysql";
	m_current_select_php = L"php-7.2.1-nts";

	m_is_apache_listen_port_conf = false;
	m_is_mysql_listen_port_conf = false;
	m_is_mariadb_listen_port_conf = false;
	m_is_mariadb_path_conf = false;
	m_is_current_dbserver_conf = false;
	m_is_current_select_php_conf = false;

	//由于我们的php.ini配置是从模板中复制过去的
	//所以我们需要判断一下用户是否已经配置过该版本的php
	//以免覆盖掉用户的配置
	m_is_php_7_1_13_conf = false;
	m_is_php_7_4_23_conf = false;

	if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES) {
		CString arrLines = L"";
		CString strLine = L"";
		TRY
		{
			CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
					continue; 
				if (strLine.Find(L"apache_listen_port=") != -1)
				{
					strLine.Replace(L"apache_listen_port=", L"");
					m_apache_listen_port = strLine;
					m_is_apache_listen_port_conf = true;
					
					continue;
				}
				if (strLine.Find(L"mysql_listen_port=") != -1)
				{
					strLine.Replace(L"mysql_listen_port=", L"");
					m_mysql_listen_port = strLine;
					m_is_mysql_listen_port_conf = true;
					
					continue;
				}
				if (strLine.Find(L"mariadb_listen_port=") != -1)
				{
					strLine.Replace(L"mariadb_listen_port=", L"");
					m_mariadb_listen_port = strLine;
					m_is_mariadb_listen_port_conf = true;
					
					continue;
				}
				if (strLine.Find(L"mariadb_path=") != -1)
				{
					strLine.Replace(L"mariadb_path=", L"");
					m_mariadb_path = strLine;
					m_is_mariadb_path_conf = true;
					
					continue;
				}
				if (strLine.Find(L"currentdb=") != -1)
				{
					strLine.Replace(L"currentdb=", L"");
					m_current_db_server = strLine;
					m_is_current_dbserver_conf = true;
					
					continue;
				}
				if (strLine.Find(L"currentslect=") != -1) 
				{
					strLine.Replace(L"currentslect=", L"");
					m_current_select_php = strLine;
					m_is_current_select_php_conf = true;
					
					continue;
				}
				if (strLine.Find(L"domainconfig=") != -1) {
					strLine.Replace(L"domainconfig=", L"");
					m_domalist.AddString(strLine);
				}
				if (strLine.Find(L"m_is_php_7_1_13_conf") != -1) {
					m_is_php_7_1_13_conf = true;
				}
				if (strLine.Find(L"m_is_php_7_4_23_conf") != -1) {
					m_is_php_7_4_23_conf = true;
				}
			}
			file.Close();
		}
		CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
	}
}

//void CMFCApplication1Dlg::installmysql()
//{
//	stop_db_server(L"mariadb");
//	//deleteaservie(L"mariadb");
//
//	SHELLEXECUTEINFO ShExecInfo = { 0 };
//ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
//ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
//ShExecInfo.hwnd = NULL;
//ShExecInfo.lpVerb = L"runas";
//ShExecInfo.lpFile = L"cmd";
////需要先安装成服务之后才能使用-k start、restart等命令
//CString trmpFiolsdsdename = random();
//CString papsarasras = L"/c  " + m_path + L"\\mysql\\bin\\mysqld.exe --install > " + m_path + L"\\errourd\\mysql_install_log_" + trmpFiolsdsdename + L".txt 2>" + m_path + L"\\errourd\\mysql_install_error_log_" + trmpFiolsdsdename + L".txt";
//ShExecInfo.lpParameters = papsarasras;// L"/c start /b " + m_path + L"\\mysql\\bin\\mysqld.exe --install";
////ShExecInfo.lpParameters = L"/c echo 123 > 1.txt";
//ShExecInfo.lpDirectory = NULL;
//ShExecInfo.nShow = SW_HIDE;
//ShExecInfo.hInstApp = NULL;
//ShellExecuteEx(&ShExecInfo);
//WaitForSingleObject(ShExecInfo.hProcess, INFINITE); }

//安装mariadb服务WaitForSingleObject(ShExecInfo.hProcess, INFINITE)}
//void CMFCApplication1Dlg::installmariadb()
//{//要想使用mariadb，需要先卸载mysql服务
//	//既然两个服务得名称不一样，就没必要删除服务了
//	stop_db_server(L"mysql");
////deleteaservie(L"mysql");
//
//SHELLEXECUTEINFO ShExecInfo = { 0 };
//ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
//ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
//ShExecInfo.hwnd = NULL;
//ShExecInfo.lpVerb = L"runas";
//ShExecInfo.lpFile = L"cmd";
////需要先安装成服务之后才能使用-k start、restart等命令
//CString trmpFiolsdsdename = random();
//CString papsarasras = L"/c \"" + m_mariadb_path + L"\"  --install mariadb > " + m_path + L"\\errourd\\mariadb_install_log_" + trmpFiolsdsdename + L".txt 2>" + m_path + L"\\errourd\\mariadb_install_error_log_" + trmpFiolsdsdename + L".txt";
//ShExecInfo.lpParameters = papsarasras;
////ShExecInfo.lpParameters = L"/c echo 123 > 1.txt";
//ShExecInfo.lpDirectory = NULL;
//ShExecInfo.nShow = SW_HIDE;
//ShExecInfo.hInstApp = NULL;
//ShellExecuteEx(&ShExecInfo);
//WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
//}
void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication1Dlg::OnBnClickedOk()
{
	restart_apache_server();
}


void CAboutDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);
}


void CMFCApplication1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	switch (nIDEvent)   //定时器分支,根据生在的定时器编号进行操作
	{
	case 1:
		//判断服务是否开启，是根据端口是否监听来进行判断的
		WSADATA wsaData;
		int iResult = 0;

		SOCKET ListenSocket = INVALID_SOCKET;
		sockaddr_in service;

		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != NO_ERROR) {
			MessageBox(L"socket初始化失败！");
			return;
		}

		ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (ListenSocket == INVALID_SOCKET) 
		{
			MessageBox(L"socket初始化失败！");
			WSACleanup();
			return;
		}

		//测试apache端口是否监听
		service.sin_family = AF_INET;
		InetPton(AF_INET, _T("0.0.0.0"), &service.sin_addr.s_addr);
		service.sin_port = htons(_wtoi(m_apache_listen_port));

		iResult = bind(ListenSocket, (SOCKADDR *)& service, sizeof(service));
		if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR)
		{
			m_is_apache_running = true;
			closesocket(ListenSocket);
		} 
		else 
		{
			m_is_apache_running = false;
			closesocket(ListenSocket);
		}

		if (m_is_apache_running)
		{
			CString temp_cstring = L"apache服务运行";
			GetDlgItem(IDC_EDIT2)->SetWindowText(temp_cstring);
				
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_BITMAP1);
			CStatic* p = (CStatic*)GetDlgItem(IDC_JIZHUOMI_STATIC);
			HBITMAP hBmp = (HBITMAP)bitmap.GetSafeHandle();
			p->SetBitmap(hBmp);
		}
		else
		{
			CString temp_cstring = L"apache没有启动";
			GetDlgItem(IDC_EDIT2)->SetWindowText(temp_cstring);

			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_BITMAP2);
			CStatic* p = (CStatic*)GetDlgItem(IDC_JIZHUOMI_STATIC);
			HBITMAP hBmp = (HBITMAP)bitmap.GetSafeHandle();
			p->SetBitmap(hBmp);
		}


		//测试mysql端口是否监听
		if (m_current_db_server == L"mysql")
		{
			ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (ListenSocket == INVALID_SOCKET)
			{
				MessageBox(L"socket初始化失败！");
				WSACleanup();
				return;
			}

			service.sin_family = AF_INET;
			InetPton(AF_INET, _T("0.0.0.0"), &service.sin_addr.s_addr);
			service.sin_port = htons(_wtoi(m_mysql_listen_port));

			iResult = bind(ListenSocket, (SOCKADDR *)& service, sizeof(service));
			if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR)
			{
				m_is_mysql_running = true;
				closesocket(ListenSocket);
			}
			else
			{
				m_is_mysql_running = false;
				closesocket(ListenSocket);
			}

			if (m_is_mysql_running)
			{
				CString temp_cstring = m_current_db_server + L"服务运行";
				GetDlgItem(IDC_EDIT1)->SetWindowText(temp_cstring);

				CBitmap bitmap;
				bitmap.LoadBitmap(IDB_BITMAP5);
				CStatic* p = (CStatic*)GetDlgItem(IDC_JIZHUOMI_STATIC3);
				HBITMAP hBmp = (HBITMAP)bitmap.GetSafeHandle();
				p->SetBitmap(hBmp);
			}
			else
			{
				CString temp_cstring = m_current_db_server + L"没有运行";
				GetDlgItem(IDC_EDIT1)->SetWindowText(temp_cstring);

				CBitmap bitmap;
				bitmap.LoadBitmap(IDB_BITMAP6);
				CStatic* p = (CStatic*)GetDlgItem(IDC_JIZHUOMI_STATIC3);
				HBITMAP hBmp = (HBITMAP)bitmap.GetSafeHandle();
				p->SetBitmap(hBmp);
			}
		}
		if (m_current_db_server == L"mariadb")
		{
			//测试mariadb端口是否监听
			//mariadb不能通过监听端口是否成功来判断，因为在测试过程中，我发现他的端口是可以复用的，所以再listen到3306还是可以成功
			m_is_mariadb_running = is_mariadb_port_listening();

			if (m_is_mariadb_running)
			{
				CString temp_cstring = m_current_db_server + L"服务运行";
				GetDlgItem(IDC_EDIT1)->SetWindowText(temp_cstring);

				CBitmap bitmap;
				bitmap.LoadBitmap(IDB_BITMAP5);
				CStatic* p = (CStatic*)GetDlgItem(IDC_JIZHUOMI_STATIC3);
				HBITMAP hBmp = (HBITMAP)bitmap.GetSafeHandle();
				p->SetBitmap(hBmp);
			}
			else
			{
				CString temp_cstring = m_current_db_server + L"没有运行";
				GetDlgItem(IDC_EDIT1)->SetWindowText(temp_cstring);

				CBitmap bitmap;
				bitmap.LoadBitmap(IDB_BITMAP6);
				CStatic* p = (CStatic*)GetDlgItem(IDC_JIZHUOMI_STATIC3);
				HBITMAP hBmp = (HBITMAP)bitmap.GetSafeHandle();
				p->SetBitmap(hBmp);
			}
		}
		WSACleanup();

		UpdateData(FALSE);
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}

void CMFCApplication1Dlg::OnBnClickedOk3()
{
	stop_process(m_apache_process_id);
}

BOOL CMFCApplication1Dlg::is_mariadb_port_listening()
{
	PMIB_TCPTABLE pTcpTable;
	DWORD dwSize = 0;
	DWORD dwRetVal = 0; 

	pTcpTable = (MIB_TCPTABLE *)MALLOC(sizeof(MIB_TCPTABLE));
	if (pTcpTable == NULL) {
		MessageBox(L"Error allocating memory");
		return false;
	}

	dwSize = sizeof(MIB_TCPTABLE);
	if ((dwRetVal = GetTcpTable(pTcpTable, &dwSize, TRUE)) == ERROR_INSUFFICIENT_BUFFER)
	{
		FREE(pTcpTable);
		pTcpTable = (MIB_TCPTABLE *)MALLOC(dwSize);
		if (pTcpTable == NULL) 
		{
			MessageBox(L"Error allocating memory\n");
			return false;
		}
	}
	if ((dwRetVal = GetTcpTable(pTcpTable, &dwSize, TRUE)) == NO_ERROR)
	{
		for (int i = 0; i < (int)pTcpTable->dwNumEntries; i++) 
		{
			if (ntohs((u_short)pTcpTable->table[i].dwLocalPort) == _wtoi(m_mariadb_listen_port))
			{
				return true;
			}
		}
	}
	else {
		MessageBox(L"GetTcpTable failed");
		FREE(pTcpTable);
		return false;
	}

	if (pTcpTable != NULL) {
		FREE(pTcpTable);
		pTcpTable = NULL;
	}

	return false;
}

void CMFCApplication1Dlg::OnBnClickedOk4()
{
	restart_apache_server();
}

BOOL CMFCApplication1Dlg::restart_apache_server() {
	//然后杀死apache进程，再创建
	stop_process(m_apache_process_id);
	m_apache_process_id = create_process(m_path + L"\\Apache\\bin\\httpd.exe");
	return true;
}


void CMFCApplication1Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
CString CMFCApplication1Dlg::random() {
	CString strTemp;
	const char CCH[] = "0123456789";
	CString strRet;
	for (int i = 0; i < 9; ++i)
	{
		srand((unsigned)time(NULL) + i);
		int x = rand() % 10;
		strTemp = CString(CCH[x]);
		strRet = strRet + strTemp;

	}return strRet;
}

//格式化错误消息
void CMFCApplication1Dlg::ErrorExit(LPTSTR lpszFunction) 
{ 
    // Retrieve the system error message for the last-error code

    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError(); 

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );

    // Display the error message and exit the process

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, 
        (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR)); 
    StringCchPrintf((LPTSTR)lpDisplayBuf, 
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"), 
        lpszFunction, dw, lpMsgBuf); 
        //MessageBox((LPCTSTR)lpDisplayBuf); 
	CString arrLines = L"";
	CString strLine = L"";
	//CStdioFile cfvvile(m_path + L"\\application.log", CFile::modeCreate |
	//	CFile::modeReadWrite);
	//CString cszMyString((LPCTSTR)lpDisplayBuf);
	//cfvvile.WriteString(cszMyString +L"\n");
	//cfvvile.Close();
	wprintf(L"%s\n", (LPCWSTR)lpDisplayBuf);
	CString temo = (LPCWSTR)lpDisplayBuf;

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
    ExitProcess(dw); 
}LRESULT CMFCApplication1Dlg::stoppaomadeng(WPARAM wp, LPARAM lp) {
	
	return 1L;
}
LRESULT CMFCApplication1Dlg::paomadeng(WPARAM wp, LPARAM lp){
	
		blink();
		return 1L;
}

void CMFCApplication1Dlg::OnBnClickedOk8()
{
	//创建webroot
	if (GetFileAttributes(L"C:\\fuck\\root") == INVALID_FILE_ATTRIBUTES)
	{
		SHCreateDirectoryEx(NULL,L"C:\\fuck\\root", NULL);
	}
	//打开httpd.conf配置文件，对serveroot进行配置
	CString temp_cstring = m_path + L"\\Apache\\";
	temp_cstring.Replace(L"\\", L"/");
	CString arrLines = L"";
	CString strLine = L"";
	TRY
	{
		CStdioFile file(m_path + L"\\apache\\conf\\httpd.conf", CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#' || temp_string[0] == '\n')
			{ 
				continue; 
			}
			strLine.Replace(L"ServerRoot", L"ServerRoot \"" + temp_cstring + L"\"\n#");
			if (strLine.Find(L"Apache/cgi-bin") != -1 && strLine.Find(L"<Directory") != -1)
			{
				strLine = L"<Directory \"" + temp_cstring + L"Apache/cgi-bin\">";
			}
			strLine.Replace(L"DocumentRoot", L"DocumentRoot \"C:\\fuck\\root\"\n#");
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();
	}
		CATCH_ALL(e)
	{
		e->ReportError();
	}
	END_CATCH_ALL	
	CFile::Remove(m_path + L"\\apache\\conf\\httpd.conf");
	CStdioFile cfile(m_path +L"\\apache\\conf\\httpd.conf", CFile::modeCreate | CFile::modeReadWrite);
	cfile.WriteString(arrLines);
	cfile.Close();

	//对vhosts.conf文件也需要进行设置
	strLine = L""; 
	arrLines = L"";
	TRY
	{
		CStdioFile file(m_path + L"\\apache\\conf\\vhosts.conf", CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#' || temp_string[0] == '\n')
			{
				continue;
			}
			if (strLine.Find(L"<VirtualHost _default_:80>") != -1) {
				arrLines += strLine;
				arrLines += L"\n"; 
				file.ReadString(strLine);
				strLine = L"DocumentRoot \"C:\\fuck\\root\""; 
				arrLines += strLine;
				arrLines += L"\n";
				file.ReadString(strLine);
				strLine = L"<Directory \"C:\\fuck\\root\">"; 
				arrLines += strLine;
				arrLines += L"\n";
				continue;
			}
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();
	}
		CATCH_ALL(e)
	{
		e->ReportError();
	}
	END_CATCH_ALL
	CFile::Remove(m_path + L"\\apache\\conf\\vhosts.conf");
	CStdioFile cfvvile(m_path + L"\\apache\\conf\\vhosts.conf", CFile::modeCreate | CFile::modeReadWrite);
	cfvvile.WriteString(arrLines);
	cfvvile.Close();

	//默认php版本7.2.1-nts
	CString php_path = m_path + L"\\php\\php-7.2.1-nts\\";
	php_path.Replace(L"\\", L"/");
	strLine = L"";
	arrLines = L"";
	TRY
	{
		CStdioFile file(m_path +L"\\Apache\\conf\\extra\\httpd-php.conf", CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#' || temp_string[0] == '\n')
			{
				continue; 
			}
			strLine.Replace(L"FcgidInitialEnv", L"FcgidInitialEnv PHPRC \"" + php_path + L"\"\n#");
			strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + php_path + L"php-cgi.exe\" .php\n#");
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();
	}
		CATCH_ALL(e)
	{
		e->ReportError();
	}
	END_CATCH_ALL
	CFile::Remove(m_path +L"\\Apache\\conf\\extra\\httpd-php.conf");
	CStdioFile sscfile(m_path +L"\\Apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate | CFile::modeReadWrite);
	sscfile.WriteString(arrLines);
	sscfile.Close();
	//设置完默认php版本之后，应当将下拉框设置为对应的php版本
	m_phplist.SetCurSel(8);
	restart_apache_server();


	config_my_ini();
	restart_db_server();
	
	MessageBox(L"配置完成");
}


void CMFCApplication1Dlg::OnBnClickedOk9()
{
	CString sWindowText;
	// TODO: Add your control notification handler code here
	
	HWND hWnd = NULL;
	GetDlgItem(IDC_EDIT3, &hWnd);
	int lenthfff = GetWindowTextLengthA(hWnd);
	GetDlgItem(IDD_MFCAPPLICATION1_DIALOG, &hWnd);
	TCHAR buffrt[1000];
	if (lenthfff == 0) { blink(); return; }
	GetDlgItemTextW(IDC_EDIT3, buffrt, lenthfff);
	CString fuckstring = buffrt;
	//fuckstring += L" ";
	int i = 1;

	CString mariadbpasssssth = L"";
	GetDlgItem(IDC_EDIT3)->GetWindowText(mariadbpasssssth);
	fuckstring = mariadbpasssssth;
	//将字符串复制到黏贴班中
	if (OpenClipboard())
	{
		HGLOBAL hgClipBuffer = nullptr;
		std::wstring hi2(fuckstring);
		std::size_t sizeInWords = hi2.size() + 1;
		std::size_t sizeInBytes = sizeInWords * sizeof(wchar_t);
		hgClipBuffer = GlobalAlloc(GHND | GMEM_SHARE, sizeInBytes);
		if (!hgClipBuffer)
		{
			CloseClipboard();
			return;
		}
		wchar_t *wgClipBoardBuffer = static_cast<wchar_t*>(GlobalLock(hgClipBuffer));
		wcscpy_s(wgClipBoardBuffer, sizeInWords, hi2.c_str());
		GlobalUnlock(hgClipBuffer);
		EmptyClipboard();
		SetClipboardData(CF_UNICODETEXT, hgClipBuffer);
		CloseClipboard();
	}

	blink();

}

void CMFCApplication1Dlg::blink() {
	//闪烁一下以提示复制成功
	CBitmap bitmap;
	//加载指定位图资源 Bmp图片ID
	bitmap.LoadBitmap(IDB_BITMAP4);
	//获取对话框上的句柄 图片控件ID
	CStatic* p = (CStatic*)GetDlgItem(IDC_JIZHUOMI_STATIC2);
	//设置静态控件窗口风格为位图居中显示
	//p->ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
	//将图片设置到Picture控件上
	HBITMAP hBmp = (HBITMAP)bitmap.GetSafeHandle();
	p->SetBitmap(hBmp);
	Sleep(100);
	blink2();
//	//加载指定位图资源 Bmp图片ID
//	bitmap.LoadBitmap(IDB_BITMAP4);
//	//获取对话框上的句柄 图片控件ID
////	p = (CStatic*)GetDlgItem(IDC_JIZHUOMI_STATIC2);
//	//设置静态控件窗口风格为位图居中显示
//	//p->ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
//	//将图片设置到Picture控件上
//	hBmp = (HBITMAP)bitmap.GetSafeHandle();
//	p->SetBitmap(hBmp);
//	Sleep(50);
//	//加载指定位图资源 Bmp图片ID
//	bitmap.LoadBitmap(IDB_BITMAP3);
//	//获取对话框上的句柄 图片控件ID
//	//p = (CStatic*)GetDlgItem(IDC_JIZHUOMI_STATIC2);
//	//设置静态控件窗口风格为位图居中显示
//	//p->ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
//	//将图片设置到Picture控件上
//	hBmp = (HBITMAP)bitmap.GetSafeHandle();
//	p->SetBitmap(hBmp);
}

void CMFCApplication1Dlg::blink2() {
	//闪烁一下以提示复制成功
	CBitmap bitmap;
	//加载指定位图资源 Bmp图片ID
	bitmap.LoadBitmap(IDB_BITMAP3);
	//获取对话框上的句柄 图片控件ID
	CStatic* p = (CStatic*)GetDlgItem(IDC_JIZHUOMI_STATIC2);
	//设置静态控件窗口风格为位图居中显示
	//p->ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
	//将图片设置到Picture控件上
	HBITMAP hBmp = (HBITMAP)bitmap.GetSafeHandle();
	p->SetBitmap(hBmp);
	//(25);
	//blink4();
}
void CMFCApplication1Dlg::blink4() {
	//闪烁一下以提示复制成功
	CBitmap bitmap;
	//加载指定位图资源 Bmp图片ID
	bitmap.LoadBitmap(IDB_BITMAP4);
	//获取对话框上的句柄 图片控件ID
	CStatic* p = (CStatic*)GetDlgItem(IDC_JIZHUOMI_STATIC2);
	//设置静态控件窗口风格为位图居中显示
	//p->ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
	//将图片设置到Picture控件上
	HBITMAP hBmp = (HBITMAP)bitmap.GetSafeHandle();
	p->SetBitmap(hBmp);
	Sleep(5);
}

void CMFCApplication1Dlg::OnBnClickedOk5()
{
	restart_db_server();
}

//主要对mysql配置问价中的basedir和datadir路径进行修改
void CMFCApplication1Dlg::config_my_ini() {
	CString temp_cstring = m_path + L"\\MySQL";
	temp_cstring.Replace(L"\\", L"/");

	CString strLine = L"";
	CString arrLines = L"";
	TRY
	{
	   CStdioFile file(m_path +L"\\MySQL\\my.ini", CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#' || temp_string[0] == '\n') 
			{ 
				continue;
			}
			strLine.Replace(L"basedir", L"basedir=\"" + temp_cstring + L"/\"\n#");
			strLine.Replace(L"datadir", L"datadir=\"" + temp_cstring + L"/data/\"\n#");
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();
	}
		CATCH_ALL(e)
	{
		e->ReportError();
	}
	END_CATCH_ALL
	CFile::Remove(m_path + L"\\MySQL\\my.ini");
	CStdioFile cfile(m_path+L"\\MySQL\\my.ini", CFile::modeCreate | CFile::modeReadWrite);
	cfile.WriteString(arrLines);
	cfile.Close();
}
//BOOL CMFCApplication1Dlg::mysqlapache_syntax_check(CString *arrlines) {
//	SHELLEXECUTEINFO ShExecInfo = { 0 };
//	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
//	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
//	ShExecInfo.hwnd = NULL;
//	ShExecInfo.lpVerb = L"runas";
//	ShExecInfo.lpFile = L"cmd";
//	CString trmpFiosdsdssdslsdsdename = random(); CString aetgrfssd = L"";
//	if(m_current_db_server==L"mysql")
//	 aetgrfssd = L"/c start /b " + m_path + L"\\MySQL\\bin\\mysqld.exe /? > "+m_path+L"\\errourd\\mysql_syntax_log_"+ trmpFiosdsdssdslsdsdename+L".txt 2>" + m_path +L"\\errourd\\mysql_syntax_error_log_"+ trmpFiosdsdssdslsdsdename+L".txt";
//	if (m_current_db_server == L"mariadb")
//		 aetgrfssd = L"/c start /b \"" + m_mariadb_path + L"\" /? > " + m_path + L"\\errourd\\mysql_syntax_log_" + trmpFiosdsdssdslsdsdename + L".txt 2>" + m_path + L"\\errourd\\mysql_syntax_error_log_" + trmpFiosdsdssdslsdsdename + L".txt";
//	ShExecInfo.lpParameters = aetgrfssd;
//	ShExecInfo.lpDirectory = NULL;
//	ShExecInfo.nShow = SW_HIDE;
//	ShExecInfo.hInstApp = NULL;
//	ShellExecuteEx(&ShExecInfo); bool isOkk = true;
//	WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
////	TRY{
////	CString strLine;
////	//由于总是发生冲突，我直接复制文件
//// CopyFile(m_path + L"\\errourd\\mysql_syntax_error_log_" + trmpFiosdsdssdslsdsdename + L".txt",
////	 m_path + L"\\errourd\\mysql_syntax_error_log_" + trmpFiosdsdssdslsdsdename + L".txt"+ trmpFiosdsdssdslsdsdename, FALSE);
////	
////
////	CStdioFile file(m_path + L"\\errourd\\mysql_syntax_error_log_" + trmpFiosdsdssdslsdsdename + L".txt" + trmpFiosdsdssdslsdsdename, CFile::modeRead);
////	while (file.ReadString(strLine)) {
////		if (strLine.Find(L"[ERROR]") != -1) {
////			isOkk = false;
////		}
////		*arrlines += strLine;
////		*arrlines += L"\n";
////	}
////	file.Close();
////}
////CATCH_ALL(e)
////{
////	e->ReportError();
////}
////END_CATCH_ALL
//
//TRY{ CString strLine; CopyFile(m_path + L"\\errourd\\mysql_syntax_error_log_" + trmpFiosdsdssdslsdsdename + L".txt",
//	 m_path + L"\\errourd\\mysql_syntax_error_log_" + trmpFiosdsdssdslsdsdename + L".txt" + trmpFiosdsdssdslsdsdename, FALSE);
//
//
///**************************************************************************/
//   //还是需要循环判断一下errorlog文件是否为空
//HANDLE hFile = CreateFile(m_path + L"\\errourd\\mysql_syntax_error_log_" + trmpFiosdsdssdslsdsdename + L".txt" + trmpFiosdsdssdslsdsdename, GENERIC_READ,
//	FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING,
//	FILE_ATTRIBUTE_NORMAL, NULL);
//if (hFile == INVALID_HANDLE_VALUE)
//return -1; // error condition, could call GetLastError to find out more
//
//LARGE_INTEGER size;
//if (!GetFileSizeEx(hFile, &size))
//{
//	CloseHandle(hFile);
//	return -1; // error condition, could call GetLastError to find out more
//}
//
//CloseHandle(hFile);
//while (size.QuadPart == 0) {
//	CopyFile(m_path + L"\\errourd\\mysql_syntax_error_log_" + trmpFiosdsdssdslsdsdename + L".txt",
//		m_path + L"\\errourd\\mysql_syntax_error_log_" + trmpFiosdsdssdslsdsdename + L".txt" + trmpFiosdsdssdslsdsdename, FALSE);
//	hFile = CreateFile(m_path + L"\\errourd\\mysql_syntax_error_log_" + trmpFiosdsdssdslsdsdename + L".txt" + trmpFiosdsdssdslsdsdename, GENERIC_READ,
//		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING,
//		FILE_ATTRIBUTE_NORMAL, NULL);
//	if (hFile == INVALID_HANDLE_VALUE)
//		return -1; // error condition, could call GetLastError to find out more
//
//	if (!GetFileSizeEx(hFile, &size))
//	{
//		CloseHandle(hFile);
//		return -1; // error condition, could call GetLastError to find out more
//	}
//	CloseHandle(hFile);
//	Sleep(10);
//}
//
///**************************************************************************/
//
//
//	CStdioFile ficle(m_path + L"\\errourd\\mysql_syntax_error_log_" + trmpFiosdsdssdslsdsdename + L".txt" + trmpFiosdsdssdslsdsdename, CFile::modeRead);
//	//bool isOkk = false;
//	while (ficle.ReadString(strLine)) {
//		if (strLine.Find(L"[ERROR]") != -1) {
//			isOkk = false;
//		}
//		*arrlines += strLine;
//		*arrlines += L"\n";
//	}
//	ficle.Close();
//}
//CATCH_ALL(e)
//{
//	e->ReportError();
//}
//END_CATCH_ALL
//
//	return isOkk;
//		
//}
//启动服务
void CMFCApplication1Dlg::startservice(CString servicename) {
	//
	// Purpose: 
	//   Starts the service if possible.
	//
	// Parameters:
	//   None
	// 
	// Return value:
	//   None
	//
		SERVICE_STATUS_PROCESS ssStatus;
		DWORD dwOldCheckPoint;
		DWORD dwStartTickCount;
		DWORD dwWaitTime;
		DWORD dwBytesNeeded;

		// Get a handle to the SCM database. 

		SC_HANDLE schSCManager = OpenSCManager(
			NULL,                    // local computer
			NULL,                    // servicesActive database 
			SC_MANAGER_ALL_ACCESS);  // full access rights 

		if (NULL == schSCManager)
		{
			ErrorExit(TEXT("打开服务管理器"));
			return;
		}

		// Get a handle to the service.

		SC_HANDLE schService = OpenService(
			schSCManager,         // SCM database 
			servicename,            // name of service 
			SERVICE_ALL_ACCESS);  // full access 

		if (schService == NULL)
		{
			//printf("OpenService failed (%d)\n", GetLastError());
			ErrorExit(TEXT("获取服务句柄"));
			CloseServiceHandle(schSCManager);
			return;
		}

		// Check the status in case the service is not stopped. 

		if (!QueryServiceStatusEx(
			schService,                     // handle to service 
			SC_STATUS_PROCESS_INFO,         // information level
			(LPBYTE)&ssStatus,             // address of structure
			sizeof(SERVICE_STATUS_PROCESS), // size of structure
			&dwBytesNeeded))              // size needed if buffer is too small
		{
			//printf("QueryServiceStatusEx failed (%d)\n", GetLastError());
			ErrorExit(TEXT("查询服务状态"));
			CloseServiceHandle(schService);
			CloseServiceHandle(schSCManager);
			return;
		}

		// Check if the service is already running. It would be possible 
		// to stop the service here, but for simplicity this example just returns. 

		if (ssStatus.dwCurrentState != SERVICE_STOPPED && ssStatus.dwCurrentState != SERVICE_STOP_PENDING)
		{
			//printf("Cannot start the service because it is already running\n");
			CloseServiceHandle(schService);
			CloseServiceHandle(schSCManager);
			return;
		}

		// Save the tick count and initial checkpoint.

		dwStartTickCount = GetTickCount();
		dwOldCheckPoint = ssStatus.dwCheckPoint;

		// Wait for the service to stop before attempting to start it.

		while (ssStatus.dwCurrentState == SERVICE_STOP_PENDING)
		{
			// Do not wait longer than the wait hint. A good interval is 
			// one-tenth of the wait hint but not less than 1 second  
			// and not more than 10 seconds. 

			dwWaitTime = ssStatus.dwWaitHint / 10;

			if (dwWaitTime < 1000)
				dwWaitTime = 1000;
			else if (dwWaitTime > 10000)
				dwWaitTime = 10000;

			Sleep(100);

			// Check the status until the service is no longer stop pending. 

			if (!QueryServiceStatusEx(
				schService,                     // handle to service 
				SC_STATUS_PROCESS_INFO,         // information level
				(LPBYTE)&ssStatus,             // address of structure
				sizeof(SERVICE_STATUS_PROCESS), // size of structure
				&dwBytesNeeded))              // size needed if buffer is too small
			{
				printf("QueryServiceStatusEx failed (%d)\n", GetLastError());
				CloseServiceHandle(schService);
				CloseServiceHandle(schSCManager);
				return;
			}

			if (ssStatus.dwCheckPoint > dwOldCheckPoint)
			{
				// Continue to wait and check.

				dwStartTickCount = GetTickCount();
				dwOldCheckPoint = ssStatus.dwCheckPoint;
			}
			else
			{
				if (GetTickCount() - dwStartTickCount > ssStatus.dwWaitHint)
				{
					printf("Timeout waiting for service to stop\n");
					CloseServiceHandle(schService);
					CloseServiceHandle(schSCManager);
					return;
				}
			}
		}

		// Attempt to start the service.

		//启动服务
		if (!StartService(
			schService,  // handle to service 
			0,           // number of arguments 
			NULL))      // no arguments 
		{
			//printf("StartService failed (%d)\n", GetLastError());
			ErrorExit(L"启动服务");
			CloseServiceHandle(schService);
			CloseServiceHandle(schSCManager);
			return;
		}
		//else printf("Service start pending...\n");

		// Check the status until the service is no longer start pending. 

		if (!QueryServiceStatusEx(
			schService,                     // handle to service 
			SC_STATUS_PROCESS_INFO,         // info level
			(LPBYTE)&ssStatus,             // address of structure
			sizeof(SERVICE_STATUS_PROCESS), // size of structure
			&dwBytesNeeded))              // if buffer too small
		{
			//printf("QueryServiceStatusEx failed (%d)\n", GetLastError());
			ErrorExit(L"查询服务状态");
			CloseServiceHandle(schService);
			CloseServiceHandle(schSCManager);
			return;
		}

		// Save the tick count and initial checkpoint.

		dwStartTickCount = GetTickCount();
		dwOldCheckPoint = ssStatus.dwCheckPoint;

		while (ssStatus.dwCurrentState == SERVICE_START_PENDING)
		{
			// Do not wait longer than the wait hint. A good interval is 
			// one-tenth the wait hint, but no less than 1 second and no 
			// more than 10 seconds. 
			
			dwWaitTime = ssStatus.dwWaitHint / 10;

			if (dwWaitTime < 1000)
				dwWaitTime = 1000;
			else if (dwWaitTime > 10000)
				dwWaitTime = 10000;

			Sleep(100);

			// Check the status again. 

			if (!QueryServiceStatusEx(
				schService,             // handle to service 
				SC_STATUS_PROCESS_INFO, // info level
				(LPBYTE)&ssStatus,             // address of structure
				sizeof(SERVICE_STATUS_PROCESS), // size of structure
				&dwBytesNeeded))              // if buffer too small
			{
				printf("QueryServiceStatusEx failed (%d)\n", GetLastError());
				break;
			}

			if (ssStatus.dwCheckPoint > dwOldCheckPoint)
			{
				// Continue to wait and check.

				dwStartTickCount = GetTickCount();
				dwOldCheckPoint = ssStatus.dwCheckPoint;
			}
			else
			{
				if (GetTickCount() - dwStartTickCount > ssStatus.dwWaitHint)
				{
					// No progress made within the wait hint.
					break;
				}
			}
		}

		// Determine whether the service is running.

		if (ssStatus.dwCurrentState == SERVICE_RUNNING)
		{
			//printf("Service started successfully.\n");
		}
		else
		{
			/*printf("Service not started. \n");
			printf("  Current State: %d\n", ssStatus.dwCurrentState);
			printf("  Exit Code: %d\n", ssStatus.dwWin32ExitCode);
			printf("  Check Point: %d\n", ssStatus.dwCheckPoint);
			printf("  Wait Hint: %d\n", ssStatus.dwWaitHint);*/
		}

		CloseServiceHandle(schService);
		CloseServiceHandle(schSCManager);
	}


void CMFCApplication1Dlg::stop_db_server()
{
	if (m_current_db_server == L"mysql")
	{
		stop_process(m_mysql_process_id);
		m_is_mysql_running = false;
	}
	else
	{
		stop_process(m_mariadb_process_id);
		m_is_mariadb_running = false;
	}
}


	BOOL __stdcall CMFCApplication1Dlg::StopDependentServices(SC_HANDLE schService, SC_HANDLE schSCManager)
	{
		DWORD i;
		DWORD dwBytesNeeded;
		DWORD dwCount;

		LPENUM_SERVICE_STATUS   lpDependencies = NULL;
		ENUM_SERVICE_STATUS     ess;
		SC_HANDLE               hDepService;
		SERVICE_STATUS_PROCESS  ssp;

		DWORD dwStartTime = GetTickCount();
		DWORD dwTimeout = 30000; // 30-second time-out

		// Pass a zero-length buffer to get the required buffer size.
		if (EnumDependentServices(schService, SERVICE_ACTIVE,
			lpDependencies, 0, &dwBytesNeeded, &dwCount))
		{
			// If the Enum call succeeds, then there are no dependent
			// services, so do nothing.
			return TRUE;
		}
		else
		{
			if (GetLastError() != ERROR_MORE_DATA)
				return FALSE; // Unexpected error

			// Allocate a buffer for the dependencies.
			lpDependencies = (LPENUM_SERVICE_STATUS)HeapAlloc(
				GetProcessHeap(), HEAP_ZERO_MEMORY, dwBytesNeeded);

			if (!lpDependencies)
				return FALSE;

			__try {
				// Enumerate the dependencies.
				if (!EnumDependentServices(schService, SERVICE_ACTIVE,
					lpDependencies, dwBytesNeeded, &dwBytesNeeded,
					&dwCount))
					return FALSE;

				for (i = 0; i < dwCount; i++)
				{
					ess = *(lpDependencies + i);
					// Open the service.
					hDepService = OpenService(schSCManager,
						ess.lpServiceName,
						SERVICE_STOP | SERVICE_QUERY_STATUS);

					if (!hDepService)
						return FALSE;

					__try {
						// Send a stop code.
						if (!ControlService(hDepService,
							SERVICE_CONTROL_STOP,
							(LPSERVICE_STATUS)&ssp))
							return FALSE;

						// Wait for the service to stop.
						while (ssp.dwCurrentState != SERVICE_STOPPED)
						{
							Sleep(500);
							if (!QueryServiceStatusEx(
								hDepService,
								SC_STATUS_PROCESS_INFO,
								(LPBYTE)&ssp,
								sizeof(SERVICE_STATUS_PROCESS),
								&dwBytesNeeded))
								return FALSE;

							if (ssp.dwCurrentState == SERVICE_STOPPED)
								break;

							if (GetTickCount() - dwStartTime > dwTimeout)
								return FALSE;
						}
					}
					__finally
					{
						// Always release the service handle.
						CloseServiceHandle(hDepService);
					}
				}
			}
			__finally
			{
				// Always free the enumeration buffer.
				HeapFree(GetProcessHeap(), 0, lpDependencies);
			}
		}
		return TRUE;
	}


void CMFCApplication1Dlg::restart_db_server()
{
	//通过检查m_current_db_server变量来确认当前数据库
	if (m_current_db_server == L"mysql")
	{
		stop_process(m_mysql_process_id);
		m_mysql_process_id = create_process(m_path + L"\\mysql\\bin\\mysqld.exe");
	}
	else if (m_current_db_server == L"mariadb")
	{
		stop_process(m_mariadb_process_id);
		//删除mariadb的multi-master.info文件，在测试过程中，发现该文件有几率引起mariadb无法正常启动
		//https://stackoverflow.com/questions/59600540/xampp-mysql-failed-to-initialize-multi-master-structures
		CString multi_master_info_path = m_mariadb_path;
		multi_master_info_path.Replace(L"bin\\mariadbd.exe", L"data\\multi-master.info");
		if (GetFileAttributes(multi_master_info_path) != INVALID_FILE_ATTRIBUTES)
		{
			CFile::Remove(multi_master_info_path);
		}
		m_mariadb_process_id = create_process(m_mariadb_path);
	}
}

void CMFCApplication1Dlg::OnBnClickedOk7()
{
	restart_db_server();
}


void CMFCApplication1Dlg::OnBnClickedOk6()
{
	stop_db_server();
}
	 

void CMFCApplication1Dlg::GetAllFilesNames()
{
	WIN32_FIND_DATA fileData;
	memset(&fileData, 0, sizeof(WIN32_FIND_DATA));
	HANDLE handle = FindFirstFile(m_path+L"\\errourd\\*", &fileData);


	if (handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (_tcscmp(fileData.cFileName, _T(".")) != 0 && // ignore "." and ".."
				_tcscmp(fileData.cFileName, _T("..")) != 0)
			{
				m_csa.Add(fileData.cFileName);
			}
		} while (FindNextFile(handle, &fileData));

		FindClose(handle);
	}

}

//配置my.ini跳过认证
void CMFCApplication1Dlg::OnBnClickedOk10()
{
	stop_db_server();

	CString ini_path = L"";

	if (m_current_db_server == L"mysql") {
		ini_path = m_path + L"\\mysql\\my.ini";
	}
	else if (m_current_db_server == L"mariadb") {
		CString temp_cstring = m_mariadb_path;
		temp_cstring.Replace(L"\\bin\\mariadbd.exe", L"");
		ini_path = temp_cstring + L"\\data\\my.ini";
	}
		
	CString strLine = L"";
	CString arrLines = L"";
	TRY
	{
		CStdioFile file(ini_path, CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#' || temp_string[0] == '\n') 
			{
				continue; 
			}
			strLine.Replace(L"skip-grant-tables", L"");
			strLine.Replace(L"[mysqld]", L"[mysqld]\nskip-grant-tables");
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();

	}
		CATCH_ALL(e)
	{
		e->ReportError();
	}
	END_CATCH_ALL

	CFile::Remove(ini_path);
	CStdioFile cfile(ini_path, CFile::modeCreate | CFile::modeReadWrite);
	cfile.WriteString(arrLines);
	cfile.Close();

	restart_db_server();
}

void CMFCApplication1Dlg::OnBnClickedOk11()
{
	// TODO: Add your control notification handler code here
	SHELLEXECUTEINFO ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = L"runas";
	CString cmdopen = m_path + L"\\NavicatforMySQL\navicat\\navicat.exe";
	ShExecInfo.lpFile = L"cmd";
	//需要先安装成服务之后才能使用-k start、restart等命令
	//CString trmpFiolename = random();// C:\Users\x\Pictures\1\phpstudywheel - master\x64\Debug\
	
	CString paras = L"/c start /b " +m_path + L"\\NavicatforMySQL\\\"Navicat for MySQL\"\\navicat.exe";
	ShExecInfo.lpParameters = paras;
	//ShExecInfo.lpParameters = L"/c echo 123 > 1.txt";
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL;
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
}


void CMFCApplication1Dlg::OnBnClickedOk12()
{
	// TODO: Add your control notification handler code here
	if (!IsProcessRunning(L"navicat.exe"))
		OnBnClickedOk11();
	CString fuckstring = L"打开navicat >> 帮助 >> 注册\n\n名称和组织不用填写\n\n注册码在右下角日至框";
	MessageBox(fuckstring);	GetDlgItem(IDC_EDIT3)->SetWindowText(L"NAVH-WK6A-DMVK-DKW3");
}


bool CMFCApplication1Dlg::IsProcessRunning(const wchar_t *processName)
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
		while (Process32Next(snapshot, &entry))
			if (!_wcsicmp(entry.szExeFile, processName))
				exists = true;

	CloseHandle(snapshot);
	return exists;
}

BOOL CMFCApplication1Dlg::checkIfDelte(CString servicename) {
	SERVICE_STATUS_PROCESS ssp;
	DWORD dwStartTime = GetTickCount();
	DWORD dwBytesNeeded;
	DWORD dwTimeout = 30000; // 30-second time-out
	DWORD dwWaitTime;

	// Get a handle to the SCM database. 

	SC_HANDLE schSCManager = OpenSCManager(
		NULL,                    // local computer
		NULL,                    // ServicesActive database 
		SC_MANAGER_ALL_ACCESS);  // full access rights 

	if (NULL == schSCManager)
	{
		//printf("OpenSCManager failed (%d)\n", GetLastError());
		ErrorExit(L"打开服务管理器");
		return false;
	}

	// Get a handle to the service.

	SC_HANDLE schService = OpenService(
		schSCManager,         // SCM database 
		servicename,            // name of service 
		SERVICE_STOP |
		SERVICE_QUERY_STATUS |
		SERVICE_ENUMERATE_DEPENDENTS);

	if (schService == NULL)
	{
		//printf("OpenService failed (%d)\n", GetLastError());
		//ErrorExit(L"获取服务句柄");
		CloseServiceHandle(schSCManager);
		return true;	}
	return false;
}

void CMFCApplication1Dlg::deleteaservie(CString servicename){
	//
	// Purpose: 
	//   Deletes a service from the SCM database
	//
	// Parameters:
	//   None
	// 
	// Return value:
	//   None
	//
	
		SC_HANDLE schSCManager;
		SC_HANDLE schService;
		SERVICE_STATUS ssStatus;

		// Get a handle to the SCM database. 

		 schSCManager = OpenSCManager(
			NULL,                    // local computer
			NULL,                    // ServicesActive database 
			SC_MANAGER_ALL_ACCESS);  // full access rights 

		if (NULL == schSCManager)
		{
			printf("OpenSCManager failed (%d)\n", GetLastError());
			return;
		}

		// Get a handle to the service.

		 schService = OpenService(
			schSCManager,       // SCM database 
			servicename,          // name of service 
			DELETE);            // need delete access 

		if (schService == NULL)
		{
			//printf("OpenService failed (%d)\n", GetLastError());
			CloseServiceHandle(schSCManager);
			return;
		}

		// Delete the service.

		if (!DeleteService(schService))
		{
			//printf("DeleteService failed (%d)\n", GetLastError());
		}
		//else printf("Service deleted successfully\n");

		CloseServiceHandle(schService);
		CloseServiceHandle(schSCManager);
	
}

void CMFCApplication1Dlg::stop_process(DWORD process_id) 
{
	if (process_id == 0)
	{
		return;
	}
	const auto explorer = OpenProcess(PROCESS_TERMINATE, false, process_id);
	TerminateProcess(explorer, 1);
	CloseHandle(explorer);
}

//根据用户选择的php版本，进行apache的配置
void CMFCApplication1Dlg::OnBnClickedOk13()
{
	stop_process(m_apache_process_id);
	//我已经忘了这个变量是用来干啥的了
	//看明白了，这个变量是用来记录用户是否已经使用过这个版本的php了
	//因为第一次使用的时候会使用模板配置文件直接覆盖掉真正的配置文件，如果在用户使用过该版本的php之后，又切换到了其他的php版本
	//然后又切换了回来，继续覆盖的话会造成用户自己的配置丢失，因此需要记录一下，以判断是否还需要进行模板配置文件初始化
	CString php_version_note = L"";

	//获取当前下拉框的php版本
	CString current_php_version = L"";
	m_phplist.GetLBText(m_phplist.GetCurSel(), current_php_version);

	if (current_php_version == L"php-7.4.23-nts")
	{
		php_version_note = L"m_is_php_7_4_23_conf";
		CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\php-7.2.1-nts.ini";
		CString cs = m_path + L"\\php\\php-7.4.23-nts\\";
		cs.Replace(L"\\", L"/");
		CString strLine;
		CString arrLines;
		TRY
		{
			CStdioFile file(httpd_php_template_path, CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
				strLine.Replace(L"FcgidInitialEnv", L"FcgidInitialEnv PHPRC \"" + cs + L"\"\n#");
				strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + cs + L"php-cgi.exe\" .php\n#");
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			//MessageBox(arrLines);
			CFile::Remove(m_path + L"\\apache\\conf\\extra\\httpd-php.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate |
			CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
		
		//更改php.ini配置
		//如果不是第一次配置，就没必要拷贝模板了
		if (!m_is_php_7_4_23_conf)
		{
			CString php_ini_template_path = m_path + L"\\phpconfitemplate\\php-7.4.23-nts.ini.template";
			CString php_ini_path = m_path + L"\\php\\php-7.4.23-nts\\php.ini";
			arrLines = L"";
			strLine = L"";
			TRY
			{
				CStdioFile file(php_ini_template_path, CFile::modeRead);
				while (file.ReadString(strLine)) {
					char temp_string[256];
					strcpy_s(temp_string, CStringA(strLine).GetString());
					if (temp_string[0] == '#' || temp_string[0] == '\n')
					{
						continue;
					}
					strLine.Replace(L"path_placeholder", m_path);
					arrLines += strLine;
					arrLines += L"\n";
				}
				file.Close();
			}
				CATCH_ALL(e)
			{
				e->ReportError();
			}
			END_CATCH_ALL

				CFile::Remove(php_ini_path);
			CStdioFile vcfile(php_ini_path, CFile::modeCreate | CFile::modeReadWrite);
			vcfile.WriteString(arrLines);
			vcfile.Close();
		}
		restart_apache_server();
	}
	if (current_php_version == L"php-7.2.1-nts")
	{
		CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\php-7.2.1-nts.ini";
		CString php_path = m_path + L"\\php\\php-7.2.1-nts\\";
		php_path.Replace(L"\\", L"/");

		//更改httpd-php.conf配置
		CString arrLines = L"";
		CString strLine = L"";
		TRY
		{
			CStdioFile file(httpd_php_template_path, CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n') 
				{ 
					continue; 
				}
				strLine.Replace(L"FcgidInitialEnv", L"FcgidInitialEnv PHPRC \"" + php_path + L"\"\n#");
				strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + php_path + L"php-cgi.exe\" .php\n#");
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			
		CFile::Remove(m_path + L"\\apache\\conf\\extra\\httpd-php.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();

		//更改php.ini配置
		CString php_ini_template_path = m_path + L"\\phpconfitemplate\\php-7.2.1-nts-template.txt";
		CString php_ini_path = m_path + L"\\php\\php-7.2.1-nts\\php.ini";
		arrLines = L"";
		strLine = L"";
		TRY
		{
			CStdioFile file(php_ini_template_path, CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
				{
					continue;
				}
				strLine.Replace(L"C:\\phpStudy\\PHPTutorial", m_path);
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL

		CFile::Remove(php_ini_path);
		CStdioFile vcfile(php_ini_path, CFile::modeCreate | CFile::modeReadWrite);
		vcfile.WriteString(arrLines);
		vcfile.Close();

		restart_apache_server();
	}
	if (current_php_version == L"php-7.1.13-nts")
	{
		php_version_note = L"m_is_php_7_1_13_conf";

		CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\php-7.1.13-nts.ini";
		CString php_path = m_path + L"\\php\\php-7.1.13-nts\\";
		php_path.Replace(L"\\", L"/");
		CString strLine;
		CString arrLines;
		TRY
		{
			CStdioFile file(httpd_php_template_path, CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n') 
				{ 
					continue;
				}
				strLine.Replace(L"FcgidInitialEnv", L"FcgidInitialEnv PHPRC \"" + php_path + L"\"\n#");
				strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + php_path + L"php-cgi.exe\" .php\n#");
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			
		CFile::Remove(m_path + L"\\apache\\conf\\extra\\httpd-php.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();

		//更改php.ini配置
		//如果不是第一次配置，就没必要拷贝模板了
		if (!m_is_php_7_1_13_conf)
		{
			CString php_ini_template_path = m_path + L"\\phpconfitemplate\\php-7.1.13-nts-template.txt";
			CString php_ini_path = m_path + L"\\php\\php-7.1.13-nts\\php.ini";
			arrLines = L"";
			strLine = L"";
			TRY
			{
				CStdioFile file(php_ini_template_path, CFile::modeRead);
				while (file.ReadString(strLine)) {
					char temp_string[256];
					strcpy_s(temp_string, CStringA(strLine).GetString());
					if (temp_string[0] == '#' || temp_string[0] == '\n')
					{
						continue;
					}
					strLine.Replace(L"path_placeholder", m_path);
					arrLines += strLine;
					arrLines += L"\n";
				}
				file.Close();
			}
				CATCH_ALL(e)
			{
				e->ReportError();
			}
			END_CATCH_ALL

			CFile::Remove(php_ini_path);
			CStdioFile vcfile(php_ini_path, CFile::modeCreate | CFile::modeReadWrite);
			vcfile.WriteString(arrLines);
			vcfile.Close();
		}
		restart_apache_server();
	}
	if (current_php_version == L"php-7.0.12-nts")
	{//	case
		//
		CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\php-7.1.13-nts.ini";
		CString cs = m_path + L"\\php\\php-7.0.12-nts\\";
		cs.Replace(L"\\", L"/");
		CString strLine;
		CString arrLines;
		TRY
		{
		   CStdioFile file(httpd_php_template_path, CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
			strLine.Replace(L"FcgidInitialEnv", L"FcgidInitialEnv PHPRC \"" + cs + L"\"\n#");
			strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + cs + L"php-cgi.exe\" .php\n#");
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			CFile::Remove(m_path + L"\\apache\\conf\\extra\\httpd-php.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate |
			CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
		restart_apache_server();
	}
	if (current_php_version == L"php-5.6.27-nts")
	{//	case
		//
		CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\php-7.1.13-nts.ini";
		CString cs = m_path + L"\\php\\php-5.6.27-nts\\";
		cs.Replace(L"\\", L"/");
		CString strLine;
		CString arrLines;
		TRY
		{
		   CStdioFile file(httpd_php_template_path, CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
			strLine.Replace(L"FcgidInitialEnv", L"FcgidInitialEnv PHPRC \"" + cs + L"\"\n#");
			strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + cs + L"php-cgi.exe\" .php\n#");
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			CFile::Remove(m_path + L"\\apache\\conf\\extra\\httpd-php.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate |
			CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
		restart_apache_server();
	}
	if (current_php_version == L"php-5.5.38")
	{//	case
		//
		CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\php-5.5.38.ini";
		CString cs = m_path + L"\\php\\php-5.5.38\\";
		cs.Replace(L"\\", L"/");
		CString strLine;
		CString arrLines;
		CString bettrerres = m_path + L"\\";
		bettrerres.Replace(L"\\", L"/");
		TRY
		{
		   CStdioFile file(httpd_php_template_path, CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
			strLine.Replace(L"C:/phpStudy/PHPTutorial/", bettrerres);
			//#strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + cs + L"php-cgi.exe\" .php\n#");
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			CFile::Remove(m_path + L"\\apache\\conf\\extra\\httpd-php.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate |
			CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
		restart_apache_server();
	}
	if (current_php_version == L"php-5.4.45-nts")
	{//	case
		//
		CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\php-5.4.45-nts.ini";
		CString cs = m_path + L"\\php\\php-5.4.45-nts\\";
		cs.Replace(L"\\", L"/");
		CString strLine;
		CString arrLines;
		CString bettrerres = m_path + L"\\";
		bettrerres.Replace(L"\\", L"/");
		TRY
		{
		   CStdioFile file(httpd_php_template_path, CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
			strLine.Replace(L"C:/phpStudy/PHPTutorial/", bettrerres);
			//#strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + cs + L"php-cgi.exe\" .php\n#");
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			CFile::Remove(m_path + L"\\apache\\conf\\extra\\httpd-php.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate |
			CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
		
		//更改php.ini配置
		CString php_ini_template_path = m_path + L"\\phpconfitemplate\\php-5.4.45-nts-initemplate.ini.txt";
		CString php_ini_path = m_path + L"\\php\\php-5.4.45-nts\\php.ini";
		arrLines = L"";
		strLine = L"";
		TRY
		{
			CStdioFile file(php_ini_template_path, CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
				{
					continue;
				}
				strLine.Replace(L"C:\\phpStudy\\PHPTutorial", m_path);
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL

			CFile::Remove(php_ini_path);
		CStdioFile vcfile(php_ini_path, CFile::modeCreate | CFile::modeReadWrite);
		vcfile.WriteString(arrLines);
		vcfile.Close();

		restart_apache_server();
	}

	if (current_php_version == L"php-5.4.45")
	{//	case
		//
		CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\php-5.4.45.ini";
		CString cs = m_path + L"\\php\\php-5.4.45\\";
		cs.Replace(L"\\", L"/");
		CString strLine;
		CString arrLines;
		CString bettrerres = m_path + L"\\";
		bettrerres.Replace(L"\\", L"/");
		TRY
		{
		   CStdioFile file(httpd_php_template_path, CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
			strLine.Replace(L"C:/phpStudy/PHPTutorial/", bettrerres);
			//#strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + cs + L"php-cgi.exe\" .php\n#");
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			CFile::Remove(m_path + L"\\apache\\conf\\extra\\httpd-php.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate |
			CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
		
		//更改php.ini配置
		CString php_ini_template_path = m_path + L"\\phpconfitemplate\\php-5.4.45-initemplate.ini";
		CString php_ini_path = m_path + L"\\php\\php-5.4.45\\php.ini";
		arrLines = L"";
		strLine = L"";
		TRY
		{
			CStdioFile file(php_ini_template_path, CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
				{
					continue;
				}
				strLine.Replace(L"C:\\phpStudy\\PHPTutorial", m_path);
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL

			CFile::Remove(php_ini_path);
		CStdioFile vcfile(php_ini_path, CFile::modeCreate | CFile::modeReadWrite);
		vcfile.WriteString(arrLines);
		vcfile.Close();

		restart_apache_server();
	}
	if (current_php_version == L"php-5.3.29-nts")
	{//	case
		//
		CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\5.3.29.ini";
		CString cs = m_path + L"\\php\\php-5.3.29-nts\\";
		cs.Replace(L"\\", L"/");
		CString strLine;
		CString arrLines;
		CString bettrerres = m_path + L"\\";
		bettrerres.Replace(L"\\", L"/");
		TRY
		{
		   CStdioFile file(httpd_php_template_path, CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
			strLine.Replace(L"C:/phpStudy/PHPTutorial/", bettrerres);
			//#strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + cs + L"php-cgi.exe\" .php\n#");
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			CFile::Remove(m_path + L"\\apache\\conf\\extra\\httpd-php.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate |
			CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
		restart_apache_server();
	}

	if (current_php_version == L"php-5.3.29-nts")
	{//	case
		//
		CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\5.3.29.ini";
		CString cs = m_path + L"\\php\\php-5.3.29-nts\\";
		cs.Replace(L"\\", L"/");
		CString strLine;
		CString arrLines;
		CString bettrerres = m_path + L"\\";
		bettrerres.Replace(L"\\", L"/");
		TRY
		{
		   CStdioFile file(httpd_php_template_path, CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
			strLine.Replace(L"C:/phpStudy/PHPTutorial/", bettrerres);
			//#strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + cs + L"php-cgi.exe\" .php\n#");
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			CFile::Remove(m_path + L"\\apache\\conf\\extra\\httpd-php.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate |
			CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
		restart_apache_server();
	}
	if (current_php_version == L"php-5.2.17")
	{//	case
		//
		CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\php-5.2.17.ini";
		CString cs = m_path + L"\\php\\php-5.2.17\\";
		cs.Replace(L"\\", L"/");
		CString strLine;
		CString arrLines;
		CString bettrerres = m_path + L"\\";
		bettrerres.Replace(L"\\", L"/");
		TRY
		{
		   CStdioFile file(httpd_php_template_path, CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
			strLine.Replace(L"C:/phpStudy/PHPTutorial/", bettrerres);
			//#strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + cs + L"php-cgi.exe\" .php\n#");
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			CFile::Remove(m_path + L"\\apache\\conf\\extra\\httpd-php.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate |
			CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
		restart_apache_server();
	}
	//对httpd-php.conf配置文件进行修改
	//CString php_config_path = m_path + L"\\Apache\\conf\\extra\\httpd-php.conf";

	CString arrLines = L"";
	CString strLine = L""; 
	BOOL notempty = false;
	//在用户配置文件中增加当前选择的php版本，下次打开默认选择该版本
	if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES) {
		TRY
		{ 
			arrLines = L"";
			BOOL currentisset = false;
			CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
			while (file.ReadString(strLine))
			{
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n' )
				{
					continue; 
				}
				if (strLine.Find(L"currentslect=")!=-1)
					currentisset = true;
				strLine.Replace(L"currentslect=", L"currentslect=" + current_php_version + L"\n#");
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
			if (!currentisset)
			{ 
				arrLines += L"currentslect=" + current_php_version + L"\n#"; 
			}
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
		CFile::Remove(m_path + L"\\user.ini");
		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines + php_version_note);
		cfile.Close();
	}
	else {
		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(L"currentslect=" + current_php_version + L"\n");
		cfile.Close();
	}

	//如果当前选定的php版本是用户自己定义的，那么需要读取配置文件获取到php的路径
	if (is_custom_php(current_php_version)) {
		CString user_php_path = L"";
		if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES) {
			CString arrLines = L"";
			CString strLine = L"";
			TRY
			{
				CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
				while (file.ReadString(strLine)) {
					char temp_string[256];
					strcpy_s(temp_string, CStringA(strLine).GetString());
					if (temp_string[0] == '#' || temp_string[0] == '\n')
					{ 
						continue; 
					}
					if (strLine.Find(L"name=") != -1) {
						strLine.Replace(L"name=", L"");
						if (strLine == current_php_version) {
							file.ReadString(strLine);
							if (strLine.Find(L"path=") != -1) {
								strLine.Replace(L"path=", L"");
								user_php_path = strLine;
								break;
							}
						}
					}
				}
				file.Close();
			}
				CATCH_ALL(e)
			{
				e->ReportError();
			}
			END_CATCH_ALL

			user_php_path.Replace(L"\\", L"/"); 
			arrLines = L"";
			CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\php-7.1.13-nts.ini";
			TRY
			{
				CStdioFile file(httpd_php_template_path, CFile::modeRead);
				while (file.ReadString(strLine)) {
					char temp_string[256];
					strcpy_s(temp_string, CStringA(strLine).GetString());
					if (temp_string[0] == '#' || temp_string[0] == '\n') 
					{
						continue; 
					}
					strLine.Replace(L"FcgidInitialEnv PHPRC ", L"FcgidInitialEnv PHPRC "+ user_php_path + L"/"+L"\n#");
					strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + user_php_path + L"/php-cgi.exe\" .php\n#");
					arrLines += strLine;
					arrLines += L"\n";
				}
				file.Close();
			}
				CATCH_ALL(e)
			{
				e->ReportError();
			}
			END_CATCH_ALL
				
			CFile::Remove(m_path + L"\\apache\\conf\\extra\\httpd-php.conf");
			CStdioFile cfile(m_path + L"\\apache\\conf\\extra\\httpd-php.conf", CFile::modeCreate | CFile::modeReadWrite);
			cfile.WriteString(arrLines);
			cfile.Close();
			restart_apache_server();
		}
		else MessageBox(L"你他妈把用户配置文件弄到哪里去了？？？？？");
	}
}


void CMFCApplication1Dlg::OnBnClickedOk14()
{
	// TODO: 在此添加控件通知处理程序代码
	//打开浏览器，打开phpinfo页面
	CString httpd_php_template_path = m_path + L"\\phpconfitemplate\\phpinfo.ini.ini";
	//CString cs = m_path + L"\\php\\";
	//cs.Replace(L"\\", L"/");
	CString strLine=L"";
	CString arrLines =L"";
	TRY
	{
	   CStdioFile file(httpd_php_template_path, CFile::modeRead);
	while (file.ReadString(strLine)) {
		char temp_string[256];
		strcpy_s(temp_string, CStringA(strLine).GetString());
		//if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
	//	strLine.Replace(L"FcgidInitialEnv", L"FcgidInitialEnv PHPRC \"" + cs + L"\"\n#");
		//strLine.Replace(L"FcgidWrapper", L"FcgidWrapper " + cs + L"php-cgi.exe\" .php\n#");
		arrLines += strLine;
		arrLines += L"\n";
	}
	file.Close();

	}
		CATCH_ALL(e)
	{
		e->ReportError();
	}
	END_CATCH_ALL
		if (GetFileAttributes(L"C:\\fuck\\root\\infuckfuckfuckcumfo.php") != INVALID_FILE_ATTRIBUTES) {
			CFile::Remove(L"C:\\fuck\\root\\infuckfuckfuckcumfo.php");
		}
	CStdioFile cfile(L"C:\\fuck\\root\\infuckfuckfuckcumfo.php", CFile::modeCreate |
		CFile::modeReadWrite);
	cfile.WriteString(arrLines);
	cfile.Close();
	//打开phpinfo
	//获取当前监听的端口
	CString ashoashaiosport;
	if (GetFileAttributes(m_path + L"\\apache\\conf\\httpd.conf") != INVALID_FILE_ATTRIBUTES) {
		CString arrLines = L"";
		CString strLine = L"";
		TRY
		{
		   CStdioFile file(m_path + L"\\apache\\conf\\httpd.conf", CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
			//strLine.Replace(L"ServerRoot", L"ServerRoot \"" + cs + L"\"\n#");
			if (strLine.Find(L"Listen") != -1) {
				 ashoashaiosport = strLine;
				ashoashaiosport.Replace(L"Listen ", L"");

					GetDlgItem(IDC_EDIT10)->SetWindowText(ashoashaiosport);
					break;
			}
		}
		file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			//	CString php_executable_path = user_php_path + L"\\php.exe";


	}
	else { MessageBox(L"你他妈把apache主配置文件弄到哪里去了！！！"); }

	ShellExecute(0, NULL, L"http://localhost:"+ ashoashaiosport +L"/infuckfuckfuckcumfo.php", NULL, NULL, SW_SHOWDEFAULT);
	//restart_apache_server();
}


void CMFCApplication1Dlg::OnBnClickedOk15()
{
	// TODO: Add your control notification handler code here
	//获取php路径
	CString phppath;
		GetDlgItem(IDC_EDIT4)->GetWindowText(phppath);
	//CString conf_name = GetDlgItem(IDC_EDIT5)->GetWindowText();
	CString conf_name  ;
	GetDlgItem(IDC_EDIT5)->GetWindowText(conf_name);
	//放到配置文件中
	//std::wstring des(phppath.GetString());
	//std::string s((LPCTSTR)phppath);
	////std::string smail = (const char*)phppath;
	//const std::regex pattern("[^\x00-\x7f]");


	//正则测试哦
	//BOOL matchssss = std::regex_match(des, pattern);
	//LPCSTR szString = (LPCSTR)phppath;
	char temp_string[256];
	strcpy_s(temp_string, CStringA(phppath).GetString());
	for (int i = 0; i < 256; i++) {
		char temp = temp_string[i];
		if (temp == '\0')break;
		if (temp < 0 || temp == 32) {
			MessageBox(L"都他妈说了不要有中文歌空格了！！！！咋就不听呢！！！！"); return;
		}
	}

	//名称里面也不可以有中文，也不要带空格，虽然可以带空格，但是为甚么要带空呢
	strcpy_s(temp_string, CStringA(conf_name).GetString());
	for (int i = 0; i < 256; i++) {
		char temp = temp_string[i]; if (temp == '\0')break;
		if (temp < 0 || temp == 32) {
			MessageBox(L"都他妈说了不要有中文歌空格了！！！！咋就不听呢！！！！"); return;
		}
	}

	//通过字符检测之后，还要潘顿一下配名是否和系统已有的重复了
	if (conf_name == L"php-5.2.17" || conf_name == L"php-5.3.29-nts"
		|| conf_name == L"php-5.4.45" || conf_name == L"php-5.4.45-nts" ||
		conf_name == L"php-5.5.38" || conf_name == L"php-5.6.27-nts" || conf_name == L"php-7.0.12-nts"
		|| conf_name == L"php-7.1.13-nts" || conf_name == L"php-7.2.1-nts")
	{MessageBox(L"名称重复"); return; }

	//测试路径
	//检测一下文件是否存在
	if (phppath.Find(L"php.exe") != -1) {
		if (GetFileAttributes(phppath) == INVALID_FILE_ATTRIBUTES) { MessageBox(L"路径不存在"); return; }
		phppath.Replace(L"\\php.exe",L"");
	}
	else {
		phppath += L"phpmark";
		if (phppath.Find(L"\\phpmark") != -1) {
			phppath.Replace(L"mark", L"");
			phppath += L"php.exe"; if (GetFileAttributes(phppath) == INVALID_FILE_ATTRIBUTES) { MessageBox(L"路径不存在"); return; }
			phppath.Replace(L"\\php.exe", L"");
		}
		else {
			phppath.Replace(L"mark", L"");
			phppath += L"\\php.exe"; if (GetFileAttributes(phppath) == INVALID_FILE_ATTRIBUTES) { MessageBox(L"路径不存在"); return; }phppath.Replace(L"\\php.exe", L"");
		}
	}

	CString arrLines = L"";
	CString strLine = L"";
	

	if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES) {
		TRY
		{
	   CStdioFile file(m_path + L"\\user.ini", CFile::modeRead); while (file.ReadString(strLine)) {
		   char temp_string[256];
		   strcpy_s(temp_string, CStringA(strLine).GetString());
		   if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
		   //strLine.Replace(L"ServerRoot", L"ServerRoot \"" + m_path + L"\"\n#");
		   if (strLine.Find(conf_name) != -1) {
			   CString tempasdasd = strLine;
			   tempasdasd.Replace(L"domainconfig=", L"");
			   if (tempasdasd == conf_name) {
				   MessageBox(L"配置名重复");
				   file.Close();
				   return;
			   }
		   }
		   //#strLine.Replace(L"DocumentRoot", L"DocumentRoot \"C:\\fuck\\root\"\n#");
		   //strLine.Replace(L"C:/phpStudy/PHPTutorial/Apache/cgi-bin", cs + L"Apache/cgi-bin");
		   arrLines += strLine;
		   arrLines += L"\n";
	   }
	   file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}

		END_CATCH_ALL
			CFile::Remove(m_path + L"\\user.ini");

		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate |
			CFile::modeReadWrite);
		cfile.WriteString(arrLines+L"name=" + conf_name + L"\npath=" + phppath + L"\n");
		cfile.Close();
	}
	else{
	
		

	CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate |
		CFile::modeReadWrite);
	cfile.WriteString(L"name="+conf_name+L"\npath="+phppath+L"\n");
	cfile.Close();
	}
	m_phplist.AddString(conf_name);
}



void CMFCApplication1Dlg::OnBnClickedOk16()
{
	CString conf_name;
	m_phplist.GetLBText(m_phplist.GetCurSel(), conf_name);
	CString strLine = L"";
	CString arrLines = L"";

	if (!is_custom_php(conf_name))
	{
		MessageBox(L"删除失败，不存在该配置项（你只能删除自己的配置）"); 
		return;
	}

	BOOL is_delete = false;
	if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES)
	{
		TRY
		{
			CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
			while (file.ReadString(strLine)) 
			{
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n') 
				{
					continue; 
				}
				if (strLine.Find(conf_name) != -1) {
					strLine = L"";
			  
					file.ReadString(strLine); if (strLine.Find(L"path=") != -1) {
						strLine = L"";  is_delete = true;
					}break;
					/* file.Close();
					return;*/
		   }
		   //#strLine.Replace(L"DocumentRoot", L"DocumentRoot \"C:\\fuck\\root\"\n#");
		   //strLine.Replace(L"C:/phpStudy/PHPTutorial/Apache/cgi-bin", cs + L"Apache/cgi-bin");
		   arrLines += strLine;
		   arrLines += L"\n";
	   }
	   file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}

		END_CATCH_ALL
		CFile::Remove(m_path + L"\\user.ini");

			CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate |
				CFile::modeReadWrite);
			cfile.WriteString(arrLines);
			cfile.Close();
			
	}if (!is_delete) { MessageBox(L"删除失败，不存在该配置项（你只能删除自己的配置）"); return; }
		m_phplist.DeleteString(m_phplist.FindString(
			-1,
			conf_name));
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CAboutDlg::OnBnClickedOk17()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(0, NULL, L"https://144.one", NULL, NULL, SW_SHOWDEFAULT);
}

//关闭主程序，在关闭前对apache以及db_server进行关闭
void CMFCApplication1Dlg::OnBnClickedCancel()
{
	if (m_is_apache_running)
	{
		stop_process(m_apache_process_id);
	}

	if (m_is_mysql_running || m_is_mariadb_running)
	{
		stop_db_server();
	}

	CDialogEx::OnOK();
}


void CMFCApplication1Dlg::OnBnClickedOk2()
{
	ShellExecute(0, NULL, L"https://144.one", NULL, NULL, SW_SHOWDEFAULT);
}

BOOL CMFCApplication1Dlg::is_custom_php(CString current_php_version) {

if(current_php_version == L"php-5.2.17")return false;if( current_php_version == L"php-5.3.29-nts") return false;	if(current_php_version == L"php-5.4.45")return false; if( current_php_version== L"php-5.4.45-nts")return false; if(current_php_version==L"php-5.5.38")return false; if(current_php_version== L"php-5.6.27-nts")return false; if(current_php_version==L"php-7.0.12-nts") return false; if(current_php_version== L"php-7.1.13-nts")return false; if (current_php_version == L"php-7.2.1-nts") return false; if (current_php_version == L"php-7.4.23-nts") return false;
	return true;
}
void CMFCApplication1Dlg::OnBnClickedCancel2()
{
	ShellExecute(0, NULL, L"https://github.com/motherfucker12138/phpwheel/issues/new", NULL, NULL, SW_SHOWDEFAULT);
}

//将composer命令放到日志框中
void CMFCApplication1Dlg::OnBnClickedOk18()
{
	CString current_php_version = L"";
	m_phplist.GetLBText(m_phplist.GetCurSel(), current_php_version);
	
	//对于用户自定义的php版本，需要通过读取user.ini来获取到php的绝对路径
	if (is_custom_php(current_php_version)) 
	{
		CString user_php_path = L"";
		if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES)
		{
			CString strLine = L"";
			CString arrLines = L"";
			TRY
			{
				CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
				while (file.ReadString(strLine))
				{
					char temp_string[256];
					strcpy_s(temp_string, CStringA(strLine).GetString());
					if (temp_string[0] == '#' || temp_string[0] == '\n') 
					{
						continue; 
					}
					if (strLine.Find(L"name=") != -1) 
					{
						file.ReadString(strLine);
						if (strLine.Find(L"path=") != -1)
						{
							strLine.Replace(L"path=", L"");
							user_php_path = strLine;
							break;
						}
					}
				}
				file.Close();
			}
				CATCH_ALL(e)
			{
				e->ReportError();
			}
			END_CATCH_ALL
				
			CString php_executable_path = user_php_path + L"\\php.exe";
			GetDlgItem(IDC_EDIT3)->SetWindowText(php_executable_path + L" " + m_path + L"\\php\\" + L"composer.phar ");
		}
		else 
		{
			MessageBox(L"你他妈把用户配置文件弄到哪里去了？？？？？");
		}
	}
	else 
	{
		CString php_executable_path = m_path + L"\\php\\" + current_php_version + L"\\php.exe";
		GetDlgItem(IDC_EDIT3)->SetWindowText(php_executable_path + L" " + m_path + L"\\php\\" + L"composer.phar ");
	}
}


void CMFCApplication1Dlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	//下拉列表框发生变化时,就加载对应得虚拟主机域名路径
	CString domainmname = L"";
	CString domainpath = L"";
	m_domalist.GetLBText(m_domalist.GetCurSel(), domainmname);

	//读取用户配置文件，将路径加载上去
	CString user_php_path = L"";
	if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES) {
		CString arrLines = L"";
		CString strLine = L"";
		TRY
		{
		   CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
			//strLine.Replace(L"ServerRoot", L"ServerRoot \"" + cs + L"\"\n#");
			if (strLine.Find(L"domainconfig=") != -1) {
				strLine.Replace(L"domainconfig=", L"");
				if (strLine == domainmname) {
					file.ReadString(strLine);
					if (strLine.Find(L"domainpath=") != -1) {
						strLine.Replace(L"domainpath=", L"");
						domainpath = strLine;
						break;
					}
				}

			}
		}
		file.Close();

		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
		//	CString php_executable_path = user_php_path + L"\\php.exe";

			GetDlgItem(IDC_EDIT7)->SetWindowText(domainpath);// +L" " + m_path + L"\\php\\" + L"composer.phar ");
		GetDlgItem(IDC_EDIT6)->SetWindowText(domainmname);// +L" " + m_path + L"\\php\\" + L"composer.phar ");
	}
	else MessageBox(L"你他妈把用户配置文件弄到哪里去了？？？？？");; return;

}


//将用户输入的域名配置信息保存到用户配置文件，并添加到vhosts.conf
void CMFCApplication1Dlg::OnBnClickedOk19()
{
	stop_process(m_apache_process_id);

	//检查是否有中文和空格
	CString domain_name;
	GetDlgItem(IDC_EDIT6)->GetWindowText(domain_name);
	CString domain_path;
	GetDlgItem(IDC_EDIT7)->GetWindowText(domain_path);

	char temp_string[256];
	strcpy_s(temp_string, CStringA(domain_name).GetString());
	for (int i = 0; i < 256; i++) {
		char temp_char = temp_string[i];
		if (temp_char == '\0')
		{
			break;
		}
		if (temp_char < 0 || temp_char == 32)
		{
			MessageBox(L"都他妈说了不要有中文歌空格了！！！！咋就不听呢！！！！"); 
			return;
		}
	}

	strcpy_s(temp_string, CStringA(domain_path).GetString());
	for (int i = 0; i < 256; i++) {
		char temp_char = temp_string[i]; 
		if (temp_char == '\0')
		{
			break;
		}
		if (temp_char < 0 || temp_char == 32) 
		{
			MessageBox(L"都他妈说了不要有中文歌空格了！！！！咋就不听呢！！！！"); return;
		}
	}
	
	//这个步骤是为了删除路径最后面得\，不然会导致apache配置文件语法错误，将最后的"转义掉，从而导致报错
	domain_path += "mark";
	if (domain_path.Find(L"\\mark") != -1)
	{
		domain_path.Replace(L"\\mark", L"");
	}
	else 
	{
		domain_path.Replace(L"mark", L"");
	}

	//读取虚拟主机配置文件模板
	CString template_path = m_path + L"\\phpconfitemplate\\apachevhosttemplate.ini";
	CString strLine = L"";
	CString arrLines = L"";
	if (GetFileAttributes(template_path) != INVALID_FILE_ATTRIBUTES) {
		TRY
		{
			CStdioFile file(template_path, CFile::modeRead);
			while (file.ReadString(strLine)) 
			{
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n') 
				{ 
					continue; 
				}
				if (strLine.Find(L"placeholder_root_path") != -1) 
				{
					strLine.Replace(L"placeholder_root_path", domain_path);
				}
				if (strLine.Find(L"placeholder_domain_name") != -1)
				{
					strLine.Replace(L"placeholder_domain_name", domain_name);
				}
				if (strLine.Find(L"placeholder_port") != -1)
				{
					strLine.Replace(L"placeholder_port", m_apache_listen_port);
				}
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
	}
	else
	{
		MessageBox(L"我模板文件被你弄到那里去了？草泥马的！！！！");
		return;
	}

	CString vhosts_conf_path = m_path + L"\\apache\\conf\\vhosts.conf";
	if (GetFileAttributes(vhosts_conf_path) != INVALID_FILE_ATTRIBUTES) {
		strLine = L"";
		TRY
		{
			CStdioFile file(vhosts_conf_path, CFile::modeRead);
			while (file.ReadString(strLine)) 
			{
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n') 
				{
					continue; 
				}
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			
		CStdioFile cfvvile(vhosts_conf_path, CFile::modeCreate | CFile::modeReadWrite);
		cfvvile.WriteString(arrLines);
		cfvvile.Close();
	}
	else
	{
		MessageBox(L"你把虚拟主机配置文件弄到哪里去了？草泥马的！！！！"); return;
	}

	//将虚拟主机配置信息保存到用户配置文件
	if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES)
	{
		//检查配置信息是否重复
		arrLines = L"";
		strLine = L"";
		TRY
		{
			CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
			while (file.ReadString(strLine)) 
			{
			   char temp_string[256];
			   strcpy_s(temp_string, CStringA(strLine).GetString());
			   if (temp_string[0] == '#' || temp_string[0] == '\n')
			   {
				   continue;
			   }
			   if (strLine.Find(L"domainconfig=") != -1) {
				   CString temp_cstring = strLine;
				   temp_cstring.Replace(L"domainconfig=", L"");
				   if(temp_cstring == domain_name)
				   {
					   MessageBox(L"配置名重复");
					   file.Close();
					   return;
				   }
			   }
			   arrLines += strLine;
			   arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL

		CFile::Remove(m_path + L"\\user.ini");
		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines + L"domainconfig=" + domain_name + L"\ndomainpath=" + domain_path + L"\n");
		cfile.Close();
	}
	else 
	{
		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(L"domainconfig=" + domain_name + L"\ndomainpath=" + domain_path + L"\n");
		cfile.Close();
	}
	
	//加入下拉列表
	m_domalist.AddString(domain_name);

	//将新增的域名静态解析到127.0.0.1
	if (GetFileAttributes(L"C:\\windows\\system32\\drivers\\etc\\hosts") != INVALID_FILE_ATTRIBUTES) {
		arrLines = L"";
		strLine = L"";
		BOOL is_conf = false;
		TRY
		{
			CStdioFile file(L"C:\\windows\\system32\\drivers\\etc\\hosts", CFile::modeRead); 
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
				{
					continue; 
				}
				if (strLine.Find(domain_name) != -1)
				{
					is_conf = true;
					strLine = L"127.0.0.1 " + domain_name;
				}
				arrLines += strLine;
				arrLines += L"\n";
		   }
		   file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}

		END_CATCH_ALL
			
		CFile::Remove(L"C:\\windows\\system32\\drivers\\etc\\hosts");
		CStdioFile cfile(L"C:\\windows\\system32\\drivers\\etc\\hosts", CFile::modeCreate | CFile::modeReadWrite);
		if (is_conf)
		{
			cfile.WriteString(arrLines);
		}
		else
		{
			cfile.WriteString(arrLines + L"127.0.0.1 " + domain_name + L"\n");
		}
		cfile.Close();
	}
	else {
		MessageBox(L"windows的hosts文件被你吃了？");
		return;
	}

	restart_apache_server();
}


void CMFCApplication1Dlg::OnBnClickedOk20()
{
	if (m_domalist.GetCurSel() == CB_ERR) 
	{ 
		MessageBox(L"草泥马啥都没选你在这删尼玛呢？？？");
		return;
	}

	stop_process(m_apache_process_id);

	CString domain_name = L"";
	m_domalist.GetLBText(m_domalist.GetCurSel(), domain_name);

	//删除用户配置文件中的相应配置信息
	if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES)
	{
		CString strLine = L"";
		CString arrLines = L"";
		TRY
		{
			CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
				{
					continue;
				}
				if (strLine.Find(L"domainconfig=") != -1) {
					CString temp_cstring = strLine;
					temp_cstring.Replace(L"domainconfig=", L"");
					if (temp_cstring == domain_name) 
					{
						file.ReadString(strLine);
						continue;
					}
				}
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
			
		CFile::Remove(m_path + L"\\user.ini");
		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
	}
	else 
	{
		MessageBox(L"你他妈把用户配置文件弄到哪里去了????");
	}

	//删除vhosts.conf中的相关配置信息
	CString vhosts_conf_path = m_path + L"\\apache\\conf\\vhosts.conf";
	if (GetFileAttributes(vhosts_conf_path) != INVALID_FILE_ATTRIBUTES) {
		CString strLine = L"";
		CString arrLines = L"";
		TRY
		{
			CStdioFile file(vhosts_conf_path, CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
				{ 
					continue; 
				}
				if (strLine.Find(L"<VirtualHost *:") != -1) {
					CString temp_cstring = arrLines;
					arrLines += strLine;
					arrLines += L"\n";

					file.ReadString(strLine);
					arrLines += strLine;
					arrLines += L"\n"; 

					file.ReadString(strLine);
					CString temp_cstring_2 = strLine;
					temp_cstring_2.Replace(L"ServerName", L""); 
					CString temp_cstring_3 = temp_cstring_2.Trim();

					if (temp_cstring_3 == domain_name)
					{
						while (file.ReadString(strLine)) 
						{
							if (strLine.Find(L"</VirtualHost>") != -1) 
							{
								break;
							}
						}
						arrLines = temp_cstring;
						continue;
					}
				}
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL

		CStdioFile cfvvile(vhosts_conf_path, CFile::modeCreate | CFile::modeReadWrite);
		cfvvile.WriteString(arrLines);
		cfvvile.Close();
	}
	else 
	{
		MessageBox(L"你把虚拟主机配置文件弄到哪里去了？草泥马的！！！！");
		return;
	}

	//删除主机hosts文件中的相关配置信息
	if (GetFileAttributes(L"C:\\windows\\system32\\drivers\\etc\\hosts") != INVALID_FILE_ATTRIBUTES)
	{
		CString strLine = L"";
		CString arrLines = L"";
		TRY
		{
			CStdioFile file(L"C:\\windows\\system32\\drivers\\etc\\hosts", CFile::modeRead); 
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n') 
				{ 
					continue; 
				}
				CString temp_cstring = strLine;
				temp_cstring.Replace(L"127.0.0.1", L"");
				if (temp_cstring.Trim() == domain_name)
				{ 
					continue; 
				}
				arrLines += strLine;
				arrLines += L"\n";
		   }
		   file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL

		CFile::Remove(L"C:\\windows\\system32\\drivers\\etc\\hosts");
		CStdioFile cfile(L"C:\\windows\\system32\\drivers\\etc\\hosts", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();	
	}
	else 
	{
		MessageBox(L"windows的hosts文件被你吃了？");
		return;
	}

	m_domalist.DeleteString(m_domalist.FindString(-1, domain_name));
	m_domalist.SetCurSel(-1);

	restart_apache_server();
}


void CMFCApplication1Dlg::OnBnClickedOk21()
{
	// TODO: 在此添加控件通知处理程序代码https://archive.mariadb.org//mariadb-10.6.4/winx64-packages/mariadb-10.6.4-winx64.msi
	ShellExecute(0, NULL, L"https://archive.mariadb.org//mariadb-10.6.4/winx64-packages/mariadb-10.6.4-winx64.msi", NULL, NULL, SW_SHOWDEFAULT);
}


//mysql与mariadb的切换按钮
void CMFCApplication1Dlg::OnBnClickedOk22()
{
	//首先检查mariadb路径
	CString mariadb_path = L"";
	GetDlgItem(IDC_EDIT9)->GetWindowText(mariadb_path);
	if (mariadb_path == L"") 
	{ 
		MessageBox(L"此文本框内容不能为空");
		return; 
	}
	
	//检测mariadb路径是否正确
	if (mariadb_path.Find(L"mariadbd.exe") != -1) 
	{
		if (GetFileAttributes(mariadb_path) == INVALID_FILE_ATTRIBUTES) 
		{
			MessageBox(L"路径不存在");
			return;
		} 
		else
		{
			m_mariadb_path = mariadb_path;
		}
	}
	else 
	{
		mariadb_path += L"mark";
		if (mariadb_path.Find(L"\\mark") != -1) 
		{
			mariadb_path.Replace(L"mark",L"");
			mariadb_path += L"mariadbd.exe"; 
			if (GetFileAttributes(mariadb_path) == INVALID_FILE_ATTRIBUTES)
			{
				MessageBox(L"路径不存在"); 
				return;
			}
			else
			{
				m_mariadb_path = mariadb_path;
			}
		}
		else 
		{
			mariadb_path.Replace(L"mark", L"");
			mariadb_path += L"\\mariadbd.exe"; 
			if (GetFileAttributes(mariadb_path) == INVALID_FILE_ATTRIBUTES) 
			{
				MessageBox(L"路径不存在"); 
				return;
			}
			else
			{
				m_mariadb_path = mariadb_path;
			}
		}
	}

	m_mariadb_path = mariadb_path;

	stop_db_server();

	//检查m_current_db_server变量来确定转换后应为哪种数据库
	m_current_db_server = m_current_db_server == L"mysql" ? L"mariadb" : L"mysql";
	
	//将当前数据库类型写入用户配置文件
	write_db_conf_to_user_ini();

	//写入配置文件之后，需要将按钮改编为mariadb---->mysql
	CString buttontesxt = L"";
	GetDlgItem(IDOK22)->GetWindowText(buttontesxt);
	if (m_current_db_server == L"mysql")
	{
		GetDlgItem(IDOK22)->SetWindowText(L"mysql---->mariadb"); 
		GetDlgItem(IDC_EDIT8)->SetWindowText(L"当前数据库为mysql");
	}
	else if (m_current_db_server == L"mariadb")
	{
		GetDlgItem(IDOK22)->SetWindowText(L"mariadb---->mysql");
		GetDlgItem(IDC_EDIT8)->SetWindowText(L"当前数据库为mariadb");
	}

	get_mariadb_listen_port();
	write_mariadb_listen_port_to_user_ini();

	restart_db_server();
}

void CMFCApplication1Dlg::write_db_conf_to_user_ini()
{
	if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES) {
		CString arrLines = L"";
		CString strLine = L"";
		TRY
		{
			CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n' ||
					strLine.Find(L"currentdb=") != -1 || strLine.Find(L"mariadb_path=") != -1)
				{
					continue;
				}
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL
		
		CFile::Remove(m_path + L"\\user.ini");
		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines + L"currentdb=" + m_current_db_server + L"\nmariadb_path=" + m_mariadb_path + L"\n");
		cfile.Close();
	}
	else {
		CStdioFile cfile(m_path + L"\\user.ini", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(L"currentdb=" + m_current_db_server + L"\nmariadb_path=" + m_mariadb_path + L"\n");
		cfile.Close();
	}
}

void CMFCApplication1Dlg::OnEnChangeEdit9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication1Dlg::OnBnClickedOk23()
{
	CString apache_port;
	GetDlgItem(IDC_EDIT10)->GetWindowText(apache_port);

	m_apache_listen_port.Format(L"%d", _wtoi(apache_port));

	if (GetFileAttributes(m_path + L"\\apache\\conf\\httpd.conf") != INVALID_FILE_ATTRIBUTES)
	{
		CString strLine = L"";
		CString arrLines = L"";
		TRY
		{
			CStdioFile file(m_path + L"\\apache\\conf\\httpd.conf", CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
				{
					continue;
				}
				if (strLine.Find(L"Listen ") != -1)
				{
					strLine = L"Listen " + apache_port;
				}
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL

		CFile::Remove(m_path + L"\\apache\\conf\\httpd.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\httpd.conf", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
	}
	else
	{
		MessageBox(L"你他妈把apache主配置文件弄到哪里去了！！！");
	}

	if (GetFileAttributes(m_path + L"\\apache\\conf\\vhosts.conf") != INVALID_FILE_ATTRIBUTES)
	{
		CString strLine = L"";
		CString arrLines = L"";
		TRY
		{
			CStdioFile file(m_path + L"\\apache\\conf\\vhosts.conf", CFile::modeRead);
			while (file.ReadString(strLine)) {
				char temp_string[256];
				strcpy_s(temp_string, CStringA(strLine).GetString());
				if (temp_string[0] == '#' || temp_string[0] == '\n')
				{
					continue;
				}
				if (strLine.Find(L"<VirtualHost _default_:") != -1)
				{
					strLine = L"<VirtualHost _default_:" + apache_port + L">";
				}
				if (strLine.Find(L"<VirtualHost *:") != -1)
				{
					strLine = L"<VirtualHost *:" + m_apache_listen_port + L">";
				}
				arrLines += strLine;
				arrLines += L"\n";
			}
			file.Close();
		}
			CATCH_ALL(e)
		{
			e->ReportError();
		}
		END_CATCH_ALL

		CFile::Remove(m_path + L"\\apache\\conf\\vhosts.conf");
		CStdioFile cfile(m_path + L"\\apache\\conf\\vhosts.conf", CFile::modeCreate | CFile::modeReadWrite);
		cfile.WriteString(arrLines);
		cfile.Close();
	}
	else
	{
		MessageBox(L"你他妈把apache虚拟主机配置文件弄到哪里去了！！！");
	}

	write_apache_listen_port_to_user_ini();

	GetDlgItem(IDC_EDIT10)->SetWindowText(m_apache_listen_port);

	restart_apache_server();
}


void CMFCApplication1Dlg::OnBnClickedOk25()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(0, NULL, L"C:\\fuck\\root", NULL, NULL, SW_SHOWDEFAULT);
}


void CMFCApplication1Dlg::OnBnClickedOk24()
{
	// TODO: 在此添加控件通知处理程序代码
	CString domain_path;
	GetDlgItem(IDC_EDIT7)->GetWindowText(domain_path);
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(0, NULL, domain_path, NULL, NULL, SW_SHOWDEFAULT);

}


//根据传入的参数创建指定的进程并返回该进程ID
DWORD CMFCApplication1Dlg::create_process(CString cmd)
{
	BOOL create_success = FALSE;
	PROCESS_INFORMATION pi = { 0 };
	STARTUPINFO si = { 0 };
	si.cb = sizeof(si);

	create_success = CreateProcess(NULL, CT2W(cmd), NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

	if (create_success)
	{
		DWORD dwPid = GetProcessId(pi.hProcess);
		return dwPid;
	}
	else
	{
		if (m_apache_process_id == 0)
		{
			MessageBox(L"创建进程失败");
		}
		return 0;
	}
}


void CMFCApplication1Dlg::OnBnClickedOk26()
{
	//直接弹窗让用户自己看
	ShellExecute(m_hWnd, L"open", L"cmd.exe", L"/k" + m_path + L"\\Apache\\bin\\httpd.exe -t", NULL, SW_SHOWNORMAL);
}

//在浏览器中打开虚拟主机网站
void CMFCApplication1Dlg::OnBnClickedOk27()
{
	if (m_domalist.GetCurSel() == CB_ERR)
	{
		MessageBox(L"草泥马啥都没选你在这打开什么网站啊？？？");
		return;
	}

	CString domain_name;
	GetDlgItem(IDC_EDIT6)->GetWindowText(domain_name);
	CString url = L"http://" + domain_name + L":" + m_apache_listen_port;
	ShellExecute(0, NULL, url, NULL, NULL, SW_SHOWDEFAULT);
}


void CMFCApplication1Dlg::OnBnClickedOk28()
{
	ShellExecute(0, NULL, m_path, NULL, NULL, SW_SHOWDEFAULT);
}

//将php.ini绝对路径放到日志框中
void CMFCApplication1Dlg::OnBnClickedOk29()
{
	CString current_php_version = L"";
	m_phplist.GetLBText(m_phplist.GetCurSel(), current_php_version);

	//对于用户自定义的php版本，需要通过读取user.ini来获取到php的绝对路径
	if (is_custom_php(current_php_version))
	{
		CString user_php_path = L"";
		if (GetFileAttributes(m_path + L"\\user.ini") != INVALID_FILE_ATTRIBUTES)
		{
			CString strLine = L"";
			CString arrLines = L"";
			TRY
			{
				CStdioFile file(m_path + L"\\user.ini", CFile::modeRead);
				while (file.ReadString(strLine))
				{
					char temp_string[256];
					strcpy_s(temp_string, CStringA(strLine).GetString());
					if (temp_string[0] == '#' || temp_string[0] == '\n')
					{
						continue;
					}
					if (strLine.Find(L"name=") != -1)
					{
						file.ReadString(strLine);
						if (strLine.Find(L"path=") != -1)
						{
							strLine.Replace(L"path=", L"");
							user_php_path = strLine;
							break;
						}
					}
				}
				file.Close();
			}
				CATCH_ALL(e)
			{
				e->ReportError();
			}
			END_CATCH_ALL

			CString php_ini_path = user_php_path + L"\\php.ini";
			GetDlgItem(IDC_EDIT3)->SetWindowText(php_ini_path);
		}
		else
		{
			MessageBox(L"你他妈把用户配置文件弄到哪里去了？？？？？");
		}
	}
	else 
	{
		CString php_ini_path = m_path + L"\\php\\" + current_php_version + L"\\php.ini";
		GetDlgItem(IDC_EDIT3)->SetWindowText(php_ini_path);
	}
}


void CMFCApplication1Dlg::OnBnClickedOk30()
{
	// TODO: 在此添加控件通知处理程序代码
	//加一个基于IP的虚拟主机，好供外部访问
	//、、。/*葱末板中复制内容
	// : \Users\x\Downloads\tmp\phpwheel - master\x64\Debug\phpconfitemplate\ip_based_virtual_host.ini

//	从控件中获取IP和没目录
	CString vhost_ip;
	GetDlgItem(IDC_EDIT11)->GetWindowText(vhost_ip);
	CString vhost_dir;
	GetDlgItem(IDC_EDIT12)->GetWindowText(vhost_dir);

//	吧末班里面的内容读出来并进行相应的替换，最后加到vhost文件中
	CString ip_baae_vhost_httpd_php_template_path = m_path + L"\\phpconfitemplate\\ip_based_virtual_host.ini";
	//CString cs = m_path + L"\\php\\php-7.4.23-nts\\";
	//cs.Replace(L"\\", L"/");
	CString IP_ase_vhost_strLine;
	CString IP_ase_vhost_srrLines;
	TRY
	{
		CStdioFile file(ip_baae_vhost_httpd_php_template_path, CFile::modeRead);
		while (file.ReadString(IP_ase_vhost_strLine)) {
			char temp_string[256];

			if (IP_ase_vhost_strLine.Find(L"192.168.10.106") != -1) {
				IP_ase_vhost_strLine.Replace(L"192.168.10.106", vhost_ip);
			}
			if (IP_ase_vhost_strLine.Find(L"C:\\fuck\\root1") != -1) {
				IP_ase_vhost_strLine.Replace(L"C:\\fuck\\root1", vhost_dir);
			}
		
			/*strcpy_s(temp_string, CStringA(IP_ase_vhost_strLine).GetString());
			if (temp_string[0] == '#') { continue; }if (temp_string[0] == '\n') { continue; }
			IP_ase_vhost_strLine.Replace(L"FcgidInitialEnv", L"FcgidInitialEnv PHPRC \"" + cs + L"\"\n#");
			IP_ase_vhost_strLine.Replace(L"FcgidWrapper", L"FcgidWrapper \"" + cs + L"php-cgi.exe\" .php\n#");*/
			IP_ase_vhost_srrLines += IP_ase_vhost_strLine;
			IP_ase_vhost_srrLines += L"\n";
		}
		file.Close();
	}
		CATCH_ALL(e)
	{
		e->ReportError();
	}
	END_CATCH_ALL

	//对vhosts.conf文件也需要进行设置
	CString strLine = L"";
	CString arrLines = L"";
	TRY
	{
		CStdioFile file(m_path + L"\\apache\\conf\\vhosts.conf", CFile::modeRead);
		while (file.ReadString(strLine)) {
			char temp_string[256];
			strcpy_s(temp_string, CStringA(strLine).GetString());
			if (temp_string[0] == '#' || temp_string[0] == '\n')
			{
				continue;
			}
			if (strLine.Find(L"<VirtualHost "+ vhost_ip +L">") != -1) {
				while (file.ReadString(strLine)) {
					if (strLine.Find(L"</VirtualHost>") != -1) {
						break;
					}
				}
				continue;
			}
			arrLines += strLine;
			arrLines += L"\n";
		}
		file.Close();
	}
		CATCH_ALL(e)
	{
		e->ReportError();
	}
	END_CATCH_ALL
		arrLines += IP_ase_vhost_srrLines;
		CFile::Remove(m_path + L"\\apache\\conf\\vhosts.conf");
	CStdioFile cfvvile(m_path + L"\\apache\\conf\\vhosts.conf", CFile::modeCreate | CFile::modeReadWrite);
	cfvvile.WriteString(arrLines);
	cfvvile.Close();
	restart_apache_server();
}
