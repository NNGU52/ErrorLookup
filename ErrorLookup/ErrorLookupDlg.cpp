
// ErrorLookupDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "ErrorLookup.h"
#include "ErrorLookupDlg.h"
#include "afxdialogex.h"

#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CErrorLookupDlg



CErrorLookupDlg::CErrorLookupDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CErrorLookupDlg::IDD, pParent)
	, errorText()
	, errorCode()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CErrorLookupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT_OUTPUT, errorText);
	DDX_Control(pDX, IDC_EDIT_INPUT, errorCode);

}

BEGIN_MESSAGE_MAP(CErrorLookupDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CErrorLookupDlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CErrorLookupDlg::OnBnClickedButtonSearch)
//	ON_EN_CHANGE(IDC_EDIT_INPUT, &CErrorLookupDlg::OnEnChangeEditInput)
END_MESSAGE_MAP()


// ����������� ��������� CErrorLookupDlg

BOOL CErrorLookupDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CErrorLookupDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CErrorLookupDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CErrorLookupDlg::OnBnClickedButtonExit()
{
	exit(0);
}


void CErrorLookupDlg::OnBnClickedButtonSearch()
{
	CString errorCodeText;										// ��� �������� ���������� ���� ������
	errorCode.GetWindowText(errorCodeText);						// ���������� ���� ������

	for (int i = 0; i < errorCodeText.GetLength(); i++)			// ������������ ������� ������
	{
		if (!strchr("1234567890abcdefABCDEFx", errorCodeText.GetAt(i)))							// ���� ������ �� ���������� � ������ ����������� ��������
		{
			MessageBox(L"��������� ������������ �����", L"��������!", MB_OK | MB_ICONWARNING);	// ����� ���������
			return;
		}

	}

	wchar_t textWCHAR[255];										// ���������� ���������� ���� ��� wcstoul
	wcscpy_s(textWCHAR, errorCodeText);							// �������������� (�����������) �� CString � wchar_t
	unsigned long code = wcstoul(textWCHAR, NULL, 0);			// ������� �� ����������� ������������� ������� ��������� 

	SetLastError(code);											// ��������� ���������������� ���� ������

	DWORD errorDW = GetLastError();								// ��������� ������
	wchar_t *text;												// ���������� ��� �������� �������� ������
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, NULL, errorDW, 0, (LPWSTR)&text, 0, NULL);	// ��������� ������ ������
	errorText.SetWindowText(text);								// ����� ������ � ��������������� ����
	LocalFree(text);											// ������������ ������, ���������� ��� ����������
}