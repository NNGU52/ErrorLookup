
// ErrorLookupDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CErrorLookupDlg
class CErrorLookupDlg : public CDialogEx
{
// ��������
public:
	CErrorLookupDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_ERRORLOOKUP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonSearch();
	// ��� �������� ������ ������
	CEdit errorText;
	// �������� ��� ������
	CEdit errorCode;
//	afx_msg void OnEnChangeEditInput();
};
