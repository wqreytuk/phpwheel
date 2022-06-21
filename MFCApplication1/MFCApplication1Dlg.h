
// MFCApplication1Dlg.h: 头文件
//
#include <winsvc.h>
#include<afxcoll.h>
#include "Thread.h"
#include "Share.h"
#pragma once


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedOk3();
	afx_msg void OnBnClickedOk4();
	afx_msg void OnEnChangeEdit2();
	BOOL restart_apache_server();
	void blink();
	void blink2();
	void startservice(CString servicename);
	void blink4();
	BOOL __stdcall CMFCApplication1Dlg::StopDependentServices(SC_HANDLE schService, SC_HANDLE schSCManager);
	void stop_db_server();
	void config_my_ini();
	void restart_db_server();
	void CMFCApplication1Dlg::deleteaservie(CString servicename);
	BOOL checkIfDelte(CString servicename);// {
	bool IsProcessRunning(const wchar_t *processName);
	void GetAllFilesNames();
	LRESULT paomadeng(WPARAM wp, LPARAM lp);
	LRESULT stoppaomadeng(WPARAM wp, LPARAM lp);
private:
	CString m_statusname;
	CString random();
	void ErrorExit(LPTSTR lpszFunction) ;
	CString m_path;
	CStringArray m_csa;
	BOOL m_paomadeng;
	CString m_current_db_server;
	CString m_mariadb_path;
	CString m_apache_listen_port;
	CString m_mysql_listen_port;
	CString m_mariadb_listen_port;
	CString m_current_select_php;

	BOOL m_is_apache_listen_port_conf;
	BOOL m_is_mysql_listen_port_conf;
	BOOL m_is_mariadb_listen_port_conf;
	BOOL m_is_mariadb_path_conf;
	BOOL m_is_current_dbserver_conf;
	BOOL m_is_current_select_php_conf;

	BOOL m_is_apache_running;
	BOOL m_is_mysql_running;
	BOOL m_is_mariadb_running;

	DWORD m_apache_process_id;
	DWORD m_mysql_process_id;
	DWORD m_mariadb_process_id;

	BOOL m_is_php_7_1_13_conf;
	BOOL m_is_php_7_4_23_conf;
public:
	afx_msg void OnBnClickedOk8();
	afx_msg void OnBnClickedOk9();
	afx_msg void OnBnClickedOk5();
	afx_msg void OnBnClickedOk7();
	afx_msg void OnBnClickedOk6(); CShare cshare;
	afx_msg void OnBnClickedOk10();
	afx_msg void OnBnClickedOk11();
	afx_msg void OnBnClickedOk12();
	// php下拉列表
	CComboBox m_phplist;
	void CMFCApplication1Dlg::installmariadb();
	void CMFCApplication1Dlg::installmysql();
	afx_msg void OnBnClickedOk13();
	afx_msg void OnBnClickedOk14();
	afx_msg void OnBnClickedOk15();
	afx_msg void OnBnClickedOk16();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk2();
	afx_msg void OnBnClickedCancel2();
	afx_msg void OnBnClickedOk18();
	BOOL is_custom_php(CString phpversion);
	CComboBox m_domalist;
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedOk19();
	afx_msg void OnBnClickedOk20();
	afx_msg void OnBnClickedOk21();
	afx_msg void OnBnClickedOk22();
	afx_msg void OnEnChangeEdit9();
	afx_msg void OnBnClickedOk23();
	afx_msg void OnBnClickedOk25();
	afx_msg void OnBnClickedOk24();
	DWORD create_process(CString cmd);
	void read_user_ini();
	void get_apache_listen_port();
	void write_apache_listen_port_to_user_ini();
	void get_current_exe_path();
	void get_mysql_listen_port();
	void write_mysql_listen_port_to_user_ini();
	void get_mariadb_listen_port();
	void write_mariadb_listen_port_to_user_ini();

	void stop_process(DWORD process_id);
	afx_msg void OnBnClickedOk26();
	afx_msg void OnBnClickedOk27();
	afx_msg void OnBnClickedOk28();
	afx_msg void OnBnClickedOk29();

	BOOL is_mariadb_port_listening();
	void write_db_conf_to_user_ini();
	afx_msg void OnBnClickedOk30();
};
