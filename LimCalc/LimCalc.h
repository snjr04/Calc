
// LimCalc.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CLimCalcApp:
// Сведения о реализации этого класса: LimCalc.cpp
//

class CLimCalcApp : public CWinApp
{
public:
	CLimCalcApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CLimCalcApp theApp;
