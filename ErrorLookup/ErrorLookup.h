
// ErrorLookup.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CErrorLookupApp:
// О реализации данного класса см. ErrorLookup.cpp
//

class CErrorLookupApp : public CWinApp
{
public:
	CErrorLookupApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CErrorLookupApp theApp;