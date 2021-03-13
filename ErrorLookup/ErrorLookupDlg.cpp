
// ErrorLookupDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "ErrorLookup.h"
#include "ErrorLookupDlg.h"
#include "afxdialogex.h"

#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CErrorLookupDlg



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


// обработчики сообщений CErrorLookupDlg

BOOL CErrorLookupDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CErrorLookupDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
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
	CString errorCodeText;										// для хранения считанного кода ошибки
	errorCode.GetWindowText(errorCodeText);						// считывание кода ошибки

	for (int i = 0; i < errorCodeText.GetLength(); i++)			// перебирается входная строка
	{
		if (!strchr("1234567890abcdefABCDEFx", errorCodeText.GetAt(i)))							// если символ не встретился в строке разрешённых символов
		{
			MessageBox(L"Проверьте правильность ввода", L"Внимание!", MB_OK | MB_ICONWARNING);	// вывод сообщения
			return;
		}

	}

	wchar_t textWCHAR[255];										// переменная требуемого типа для wcstoul
	wcscpy_s(textWCHAR, errorCodeText);							// преобразование (копирование) из CString в wchar_t
	unsigned long code = wcstoul(textWCHAR, NULL, 0);			// перевод из определённой автоматически системы счисления 

	SetLastError(code);											// установка соответствующего кода ошибки

	DWORD errorDW = GetLastError();								// получение ошибки
	wchar_t *text;												// переменная для хранения описания ошибки
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, NULL, errorDW, 0, (LPWSTR)&text, 0, NULL);	// получение текста ошибки
	errorText.SetWindowText(text);								// вывод текста в соответствующее поле
	LocalFree(text);											// освобождение памяти, выделенной под переменную
}