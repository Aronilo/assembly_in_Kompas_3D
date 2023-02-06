
// Sborka.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSborkaApp:
// Сведения о реализации этого класса: Sborka.cpp
//

class CSborkaApp : public CWinApp
{
public:
	CSborkaApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CSborkaApp theApp;
