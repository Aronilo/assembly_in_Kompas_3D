
// SborkaDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CSborkaDlg
class CSborkaDlg : public CDialogEx
{
// Создание
public:
	CSborkaDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SBORKA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double m_Dvnut;
	double m_Dvnesh;
	double m_dlinna;
	afx_msg void OnBnClickedButton1();
	double m_l;
	double m_d1;
	double m_C;
	double m_b;
	double m_h;
	double m_R;
};
