
// ErrorLookup.cpp : ���������� ��������� ������� ��� ����������.
//

#include "stdafx.h"
#include "ErrorLookup.h"
#include "ErrorLookupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CErrorLookupApp

BEGIN_MESSAGE_MAP(CErrorLookupApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// �������� CErrorLookupApp

CErrorLookupApp::CErrorLookupApp()
{
	// TODO: �������� ��� ��������,
	// ��������� ���� ������ ��� ������������� � InitInstance
}


// ������������ ������ CErrorLookupApp

CErrorLookupApp theApp;


// ������������� CErrorLookupApp

BOOL CErrorLookupApp::InitInstance()
{
	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ������� ��������� ��������, � ������, ���� ���������� ���� ��������
	// ������������� ������ �������� ��� �����-���� ��� �������� ����������.
	CShellManager *pShellManager = new CShellManager;

	// ��������� ����������� ���������� "������������ Windows" ��� ��������� ��������� ���������� MFC
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ����������� �������������
	// ���� ��� ����������� �� ������������ � ���������� ��������� ������
	// ��������� ������������ �����, ���������� ������� �� ���������
	// ���������� �������� �������������, ������� �� ���������
	// �������� ������ �������, � ������� �������� ���������
	// TODO: ������� �������� ��� ������ �� ���-������ ����������,
	// �������� �� �������� �����������
	SetRegistryKey(_T("��������� ����������, ��������� � ������� ������� ����������"));

	CErrorLookupDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ������� ��� ��� ��������� �������� ����������� ����
		//  � ������� ������ "��"
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ������� ��� ��� ��������� �������� ����������� ����
		//  � ������� ������ "������"
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "��������������. �� ������� ������� ���������� ����, ������� ������ ���������� ���������� ���������.\n");
		TRACE(traceAppMsg, 0, "��������������. ��� ������������� ��������� ���������� MFC ��� ����������� ���� ���������� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// ������� ��������� ��������, ��������� ����.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ��������� ���������� ���� �������, ���������� �������� FALSE, ����� ����� ���� ����� ��
	//  ���������� ������ ������� ���������� ��������� ����������.
	return FALSE;
}

