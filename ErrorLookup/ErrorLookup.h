
// ErrorLookup.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CErrorLookupApp:
// � ���������� ������� ������ ��. ErrorLookup.cpp
//

class CErrorLookupApp : public CWinApp
{
public:
	CErrorLookupApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CErrorLookupApp theApp;