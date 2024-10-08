﻿
// LimCalcDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "LimCalc.h"
#include "LimCalcDlg.h"
#include "afxdialogex.h"
#include "iostream"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString sVvod;
CString sNum1;
CString sNum2;

bool bTochka = 0;
bool bdeistvie = 0;
bool bPodschet = 0;

double num1 = 0;
double num2 = 0;

int iDeistvie = 0;

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CLimCalcDlg



CLimCalcDlg::CLimCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIMCALC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLimCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, _Edit);
	DDX_Control(pDX, IDC_LIST1, _List);
}

BEGIN_MESSAGE_MAP(CLimCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLimCalcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON7, &CLimCalcDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &CLimCalcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CLimCalcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CLimCalcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CLimCalcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CLimCalcDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CLimCalcDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CLimCalcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CLimCalcDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON13, &CLimCalcDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON17, &CLimCalcDlg::Plus)
	ON_BN_CLICKED(IDC_BUTTON16, &CLimCalcDlg::Minus)
	ON_BN_CLICKED(IDC_BUTTON15, &CLimCalcDlg::multiplication)
	ON_BN_CLICKED(IDC_BUTTON14, &CLimCalcDlg::Division)
	ON_BN_CLICKED(IDC_BUTTON18, &CLimCalcDlg::Equal)
	ON_BN_CLICKED(IDC_BUTTON19, &CLimCalcDlg::Clear)
	ON_BN_CLICKED(IDC_BUTTON20, &CLimCalcDlg::Clean)
END_MESSAGE_MAP()


// Обработчики сообщений CLimCalcDlg

BOOL CLimCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CLimCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CLimCalcDlg::OnPaint()
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
HCURSOR CLimCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLimCalcDlg::OnBnClickedButton1()
{
	if (sVvod == L"0" || bdeistvie == 1)
	{
		sVvod = L"1";
		bdeistvie = 0;
	}
	else {
		sVvod.Append(L"1");
	}
	_Edit.SetWindowTextW(sVvod);
}


void CLimCalcDlg::OnBnClickedButton2()
{
	if (sVvod == L"0" || bdeistvie == 1)
	{
		sVvod = L"2";
		bdeistvie = 0;
	}
	else {
		sVvod.Append(L"2");
	}
	_Edit.SetWindowTextW(sVvod);
}


void CLimCalcDlg::OnBnClickedButton3()
{
	if (sVvod == L"0" || bdeistvie == 1)
	{
		sVvod = L"3";
		bdeistvie = 0;
	}
	else {
		sVvod.Append(L"3");
	}
	_Edit.SetWindowTextW(sVvod);
}


void CLimCalcDlg::OnBnClickedButton4()
{
	if (sVvod == L"0" || bdeistvie == 1)
	{
		sVvod = L"4";
		bdeistvie = 0;
	}
	else {
		sVvod.Append(L"4");
	}
	_Edit.SetWindowTextW(sVvod);
}


void CLimCalcDlg::OnBnClickedButton5()
{
	if (sVvod == L"0" || bdeistvie == 1)
	{
		sVvod = L"5";
		bdeistvie = 0;
	}
	else {
		sVvod.Append(L"5");
	}
	_Edit.SetWindowTextW(sVvod);
}


void CLimCalcDlg::OnBnClickedButton6()
{
	if (sVvod == L"0" || bdeistvie == 1)
	{
		sVvod = L"6";
		bdeistvie = 0;
	}
	else {
		sVvod.Append(L"6");
	}
	_Edit.SetWindowTextW(sVvod);
}


void CLimCalcDlg::OnBnClickedButton7()
{
	if (sVvod == L"0" || bdeistvie == 1)
	{
		sVvod = L"7";
		bdeistvie = 0;
	}
	else {
		sVvod.Append(L"7");
	}
	_Edit.SetWindowTextW(sVvod);
}

void CLimCalcDlg::OnBnClickedButton8()
{
	if (sVvod == L"0" || bdeistvie == 1)
	{
		sVvod = L"8";
		bdeistvie = 0;
	}
	else {
		sVvod.Append(L"8");
	}
	_Edit.SetWindowTextW(sVvod);
}


void CLimCalcDlg::OnBnClickedButton9()
{
	if (sVvod == L"0" || bdeistvie == 1)
	{
		sVvod = L"9";
		bdeistvie = 0;
	}
	else {
		sVvod.Append(L"9");
	}
	_Edit.SetWindowTextW(sVvod);
}


void CLimCalcDlg::OnBnClickedButton10()
{
	if (sVvod == L"0" || bdeistvie == 1)
	{
		sVvod = L"0";
		bdeistvie = 0;
	}
	else {
	sVvod.Append(L"0");
	}
	_Edit.SetWindowTextW(sVvod);
}


void CLimCalcDlg::OnBnClickedButton13()
{
	if (sVvod.GetLength() != 0 && bTochka == 0) 
	{
		sVvod.Append(L".");
		bTochka++;
		_Edit.SetWindowText(sVvod);
	}
}


void CLimCalcDlg::Plus()
{
	if (bPodschet == 1)
	{
		Equal();
	}
	else
	{
		num1 = _wtof(sVvod);
	}
	
	iDeistvie = 1;
	bdeistvie = 1;
	bTochka = 0;
	bPodschet = 1;

}


void CLimCalcDlg::Minus()
{
	if (bPodschet == 1)
	{
		Equal();
	}
	else
	{
		num1 = _wtof(sVvod);
	}
	iDeistvie = 2;
	bdeistvie = 1;
	bTochka = 0;
	bPodschet = 1;
}


void CLimCalcDlg::multiplication()
{
	if (bPodschet == 1)
	{
		Equal();
	}
	else
	{
		num1 = _wtof(sVvod);
	}
	
	iDeistvie = 3;
	bdeistvie = 1;
	bTochka = 0;
	bPodschet = 1;
}


void CLimCalcDlg::Division()
{
	if (bPodschet == 1)
	{
		Equal();
	}
	else
	{
		num1 = _wtof(sVvod);
	}
	iDeistvie = 4;
	bdeistvie = 1;
	bTochka = 0;
	bPodschet = 1;
}


void CLimCalcDlg::Equal()
{
	double ravno = 0;
	CString sList;
	num2 = _wtof(sVvod);

	if (iDeistvie == 1)
	{
		ravno = num1 + num2;
		sList.Format(L"%g + %g = %g", num1, num2, ravno);
	}
	if (iDeistvie == 2)
	{
		ravno = num1 - num2;
		sList.Format(L"%g - %g = %g", num1, num2, ravno);
	}
	if (iDeistvie == 3)
	{
		ravno = num1 * num2;
		sList.Format(L"%g * %g = %g", num1, num2, ravno);
	}
	if (iDeistvie == 4)
	{
		if (num2 == 0)
		{
			AfxMessageBox(L"Тупица на ноль не деится!");
			sList.Format(L"%g / %g = Ты тупой", num1, num2);
		}
		else
		{
			ravno = num1 / num2;
			sList.Format(L"%g / %g = %g", num1, num2, ravno);
		}
	}

	sVvod.Format(L"%g", ravno);
	_Edit.SetWindowTextW(sVvod);
	_List.AddString(sList);
	bPodschet = 0;
	bdeistvie = 1;
}


void CLimCalcDlg::Clear()
{
	iDeistvie = 0;
	sVvod = L"";
	num1 = 0;
	num2 = 0;
	_Edit.SetWindowTextW(L"0");
}


void CLimCalcDlg::Clean()
{
	sVvod.Delete(sVvod.GetLength() - 1, 1);
	if (sVvod.GetLength() == 0)
	{
		sVvod = L"0";
	}
	_Edit.SetWindowTextW(sVvod);
}


