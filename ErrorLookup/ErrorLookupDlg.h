
// ErrorLookupDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CErrorLookupDlg
class CErrorLookupDlg : public CDialogEx
{
// Создание
public:
	CErrorLookupDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_ERRORLOOKUP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonSearch();
	// Для хранения текста ошибки
	CEdit errorText;
	// Вводимый код ошибки
	CEdit errorCode;
//	afx_msg void OnEnChangeEditInput();
};
