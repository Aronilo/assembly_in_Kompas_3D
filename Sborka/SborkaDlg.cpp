
// SborkaDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Sborka.h"
#include "SborkaDlg.h"
#include "afxdialogex.h"
#include "math.h"
#include "C:\Program Files\ASCON\KOMPAS-3D v21 Study\SDK\Include\ksConstants.h"
#include "C:\Program Files\ASCON\KOMPAS-3D v21 Study\SDK\Include\ksConstants3D.h"
#include <atlsafe.h>
#include <comutil.h>
#include <string>

#define PI 4*atan(1)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#pragma once


#import "C:\Program Files\ASCON\KOMPAS-3D v21 Study\SDK\lib\kAPI5.tlb"



using namespace Kompas6API5;
//using namespace KompasAPI5;


KompasObjectPtr pKompasApp5;
//KompasObjectPtr pKompasApp5;

ksPartPtr pPart;// = PartDoc->GetTopPart();
ksDocument3DPtr pDoc;


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


// Диалоговое окно CSborkaDlg



CSborkaDlg::CSborkaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SBORKA_DIALOG, pParent)
	, m_Dvnut(9)
	, m_Dvnesh(16)
	, m_dlinna(35)
	, m_l(8)
	, m_d1(4)
	, m_C(0.6)
	, m_b(5)
	, m_h(10.4)
	, m_R(0.1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSborkaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_Dvnut);
	DDV_MinMaxDouble(pDX, m_Dvnut, 0, 10000);
	DDX_Text(pDX, IDC_EDIT4, m_Dvnesh);
	DDV_MinMaxDouble(pDX, m_Dvnesh, 0, 10000);
	DDX_Text(pDX, IDC_EDIT2, m_dlinna);
	DDV_MinMaxDouble(pDX, m_dlinna, 0, 10000);
	DDX_Text(pDX, IDC_EDIT1, m_l);
	DDX_Text(pDX, IDC_EDIT5, m_d1);
	DDX_Text(pDX, IDC_EDIT6, m_C);
	DDX_Text(pDX, IDC_EDIT7, m_b);
	DDX_Text(pDX, IDC_EDIT8, m_h);
	DDX_Text(pDX, IDC_EDIT9, m_R);
}

BEGIN_MESSAGE_MAP(CSborkaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSborkaDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений CSborkaDlg

BOOL CSborkaDlg::OnInitDialog()
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

void CSborkaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSborkaDlg::OnPaint()
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
HCURSOR CSborkaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSborkaDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	BeginWaitCursor();
	
	CComPtr<IUnknown> pKompasAppUnk = nullptr;
	if (!pKompasApp5)
	{
		// Получаем CLSID для Компас
		CLSID InvAppClsid;
		HRESULT hRes = CLSIDFromProgID(L"Kompas.Application.5", &InvAppClsid);
		if (FAILED(hRes)) {
			pKompasApp5 = nullptr;
			return;
		}

		// Проверяем есть ли запущенный экземпляр Компас
		//если есть получаем IUnknown
		hRes = ::GetActiveObject(InvAppClsid, NULL, &pKompasAppUnk);
		if (FAILED(hRes)) {
			// Приходится запускать Компас самим так как работающего нет
			// Также получаем IUnknown для только что запущенного приложения Компас
			TRACE(L"Could not get hold of an active Inventor, will start a new session\n");
			hRes = CoCreateInstance(InvAppClsid, NULL, CLSCTX_LOCAL_SERVER, __uuidof(IUnknown), (void**)&pKompasAppUnk);
			if (FAILED(hRes)) {
				pKompasApp5 = nullptr;
				return;
			}
		}

		// Получаем интерфейс приложения Компас
		hRes = pKompasAppUnk->QueryInterface(__uuidof(KompasObject), (void**)&pKompasApp5);
		if (FAILED(hRes)) {
			return;
		}
	}

	CString str;
	GetDlgItemText(IDC_EDIT3, str);
	m_Dvnut = _wtof(str);
	GetDlgItemText(IDC_EDIT4, str);
	m_Dvnesh = _wtof(str);
	GetDlgItemText(IDC_EDIT2, str);
	m_dlinna = _wtof(str);
	GetDlgItemText(IDC_EDIT1, str);
	m_l = _wtof(str);
	GetDlgItemText(IDC_EDIT5, str);
	m_d1 = _wtof(str);
	GetDlgItemText(IDC_EDIT6, str);
	m_C = _wtof(str);
	GetDlgItemText(IDC_EDIT7, str);
	m_b = _wtof(str);
	GetDlgItemText(IDC_EDIT8, str);
	m_h = _wtof(str);
	GetDlgItemText(IDC_EDIT9, str);
	m_R = _wtof(str);
	

	pKompasApp5->Visible = true;

	pDoc = pKompasApp5->Document3D();

	pDoc->Create(false, true);

	pPart = pDoc->GetPart(pTop_Part);

	//создаем первый эскиз
	
	ksEntityPtr pSketch = pPart->NewEntity(o3d_sketch);

	ksSketchDefinitionPtr pSketchDef = pSketch->GetDefinition();

	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));

	pSketch->Create();

	ksDocument2DPtr p2DDoc = pSketchDef->BeginEdit();

	double point[4][2];
	point[0][0] = -0;
	point[0][1] = -m_Dvnut / 2.f;
	point[1][0] = -0;
	point[1][1] = -m_Dvnesh / 2.f;
	point[2][0] = -m_dlinna;
	point[2][1] = -m_Dvnesh / 2.f;
	point[3][0] = -m_dlinna;
	point[3][1] = -m_Dvnut / 2.f;

	p2DDoc->ksLineSeg(point[0][0], point[0][1], point[1][0], point[1][1], 1);
	p2DDoc->ksLineSeg(point[1][0], point[1][1], point[2][0], point[2][1], 1);
	p2DDoc->ksLineSeg(point[2][0], point[2][1], point[3][0], point[3][1], 1);
	p2DDoc->ksLineSeg(point[3][0], point[3][1], point[0][0], point[0][1], 1);

	p2DDoc->ksLineSeg(-10, 0, 10, 0, 3);

	pSketchDef->EndEdit();
	
	//прокручиваем его

	ksEntityPtr pRotate = pPart->NewEntity(o3d_bossRotated);

	ksBossRotatedDefinitionPtr pRotDef = pRotate->GetDefinition();
	pRotDef->SetSketch(pSketch);
	pRotDef->SetSideParam(TRUE, 360);


	pRotate->Create();

	//метка на вал
	
	ksEntityCollectionPtr fledges = pPart->EntityCollection(o3d_edge);

	for (int i = 0; i < fledges->GetCount(); i++) {
		ksEntityPtr pEdge = fledges->GetByIndex(i);
		ksEdgeDefinitionPtr pEdgeDef = pEdge->GetDefinition();

		if (pEdgeDef->GetOwnerEntity() == pRotate) {
			if (pEdgeDef->IsCircle()) {
				ksVertexDefinitionPtr pVertexDef1 = pEdgeDef->GetVertex(true);
				double x1, y1, z1;
				pVertexDef1->GetPoint(&x1, &y1, &z1);

				if (x1 == 0 && y1 != 0 && z1 <= m_Dvnut / 2)
				{
					ksFaceDefinitionPtr pFaceDef = pEdgeDef->GetAdjacentFace(true);
					ksEntityPtr pFace = pFaceDef->GetEntity();

					pFace->Putname("face-mufta");
					pFace->Update();
				}
			}
		}
	}
	//создание фаски
	fledges = pPart->EntityCollection(o3d_edge);
	ksEntityPtr pFillet = pPart->NewEntity(o3d_fillet);

	ksFilletDefinitionPtr pFilletDef = pFillet->GetDefinition();
	pFilletDef->radius = m_C;
	ksEntityCollectionPtr fl = pFilletDef->array();
	fl->Clear();
	ksEntityPtr pChamfer = pPart->NewEntity(o3d_chamfer);

	ksChamferDefinitionPtr pChamferDef = pChamfer->GetDefinition();
	pChamferDef->SetChamferParam(true, sqrt(m_C/2), sqrt(m_C / 2));

	fl = pChamferDef->array();
	fl->Clear();

	for (int i = 0; i < fledges->GetCount(); i++) {
		ksEntityPtr ed = fledges->GetByIndex(i);
		ksEdgeDefinitionPtr def = ed->GetDefinition();
		if (def->GetOwnerEntity() == pRotate) {
			if (def->IsCircle()) {
				ksVertexDefinitionPtr p1 = def->GetVertex(true);
				ksVertexDefinitionPtr p2 = def->GetVertex(false);
				double x1, y1, z1;

				p1->GetPoint(&x1, &y1, &z1);

				if (x1 == 0) {

					fl->Add(ed);
				}
				if (x1 != 0) {

					fl->Add(ed);
				}
			}
		}
	}
	pChamfer->Create();


	ksEntityPtr pSketch1 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch1->GetDefinition();

	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeYOZ));

	pSketch1->Create();

	p2DDoc = pSketchDef->BeginEdit();

	double point1[4][2];
	point1[0][0] = m_h - m_Dvnut / 2.f;
	point1[0][1] = -m_b / 2.f;
	point1[1][0] = m_h - m_Dvnut / 2.f;
	point1[1][1] = m_b / 2.f;
	point1[2][0] = 0;
	point1[2][1] = m_b / 2.f;
	point1[3][0] = 0;
	point1[3][1] = -m_b / 2.f;

	p2DDoc->ksLineSeg(point1[0][0], point1[0][1], point1[1][0], point1[1][1], 1);
	p2DDoc->ksLineSeg(point1[1][0], point1[1][1], point1[2][0], point1[2][1], 1);
	p2DDoc->ksLineSeg(point1[2][0], point1[2][1], point1[3][0], point1[3][1], 1);
	p2DDoc->ksLineSeg(point1[3][0], point1[3][1], point1[0][0], point1[0][1], 1);

	pSketchDef->EndEdit();

	ksEntityPtr pExtrude = pPart->NewEntity(o3d_cutExtrusion);

	ksCutExtrusionDefinitionPtr pExDef = pExtrude->GetDefinition();
	pExDef->directionType = dtReverse;

	pExDef->SetSketch(pSketch1);
	pExDef->SetSideParam(false, etThroughAll, 0, 0, false);

	pExtrude->Create();
	
	//метка для выреза 
	
	ksEntityCollectionPtr fledges1 = pPart->EntityCollection(o3d_edge);
	

	for (int i = 0; i < fledges1->GetCount(); i++) {
		ksEntityPtr pEdge = fledges1->GetByIndex(i);
		ksEdgeDefinitionPtr pEdgeDef = pEdge->GetDefinition();
		if (pEdgeDef->GetOwnerEntity() == pExtrude) {
				ksVertexDefinitionPtr pVertexDef1 = pEdgeDef->GetVertex(true);
				ksVertexDefinitionPtr pVertexDef2 = pEdgeDef->GetVertex(false);
				double x1, y1, z1;
				double x2, y2, z2;
				pVertexDef1->GetPoint(&x1, &y1, &z1);
				pVertexDef2->GetPoint(&x2, &y2, &z2);
				//(z1 < (m_h - m_Dvnut / 2.f) && y1 < 0 && x1 == 0)
				if (z1 < 0 && y1 < 0 && x1 == -m_dlinna && z1 == z2 && y1 == -y2) {
					ksFaceDefinitionPtr pFaceDef = pEdgeDef->GetAdjacentFace(false);
					ksEntityPtr pFace = pFaceDef->GetEntity();
					pFace->Putname("lower-bound");
					pFace->Update();
				}

				//if (z1 < 0 && y1 < 0) {
				//	ksFaceDefinitionPtr pFaceDef = pEdgeDef->GetAdjacentFace(true);
				//	ksEntityPtr pFace = pFaceDef->GetEntity();

				//	pFace->Putname("vnut1");
				//	pFace->Update();
				//}
				//if (z1 < 0 && y1 > 0 && z1 > -(m_h - m_Dvnut / 2.f)) {
				//	ksFaceDefinitionPtr pFaceDef = pEdgeDef->GetAdjacentFace(false);
				//	ksEntityPtr pFace = pFaceDef->GetEntity();

				//	pFace->Putname("vnut2");
				//	pFace->Update();
				//}
		}
	}
	
	//создаем скругление
	ksEntityCollectionPtr edges = pPart->EntityCollection(o3d_edge);
	ksEntityPtr pFillet1 = pPart->NewEntity(o3d_fillet);
	
	ksFilletDefinitionPtr pFilletDef1 = pFillet1->GetDefinition();
	pFilletDef1->radius = m_R;
	ksEntityCollectionPtr fl1 = pFilletDef1->array();
	fl1->Clear();
	
	for (int i = 0; i < edges->GetCount(); i++) {
		ksEntityPtr ed = edges->GetByIndex(i);
		ksEdgeDefinitionPtr def = ed->GetDefinition();
		if (def->GetOwnerEntity() == pExtrude) {
			ksVertexDefinitionPtr p1 = def->GetVertex(true);
			ksVertexDefinitionPtr p2 = def->GetVertex(false);
			double x1, y1, z1, x2, y2, z2;
			p1->GetPoint(&x1, &y1, &z1);
			p2->GetPoint(&x2, &y2, &z2);

			if (z1 < -m_Dvnut / 2.f && abs(x1 - x2) != 0 && abs(y1 - y2) == 0) {
				fl1->Add(ed);
			}
		}
	}
	pFillet1->Create();

	//создадим отверстие
	ksEntityPtr pSketch2 = pPart->NewEntity(o3d_sketch);
	
	pSketchDef = pSketch2->GetDefinition();
	
	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));
	
	pSketch2->Create();
	
	p2DDoc = pSketchDef->BeginEdit();
	
	p2DDoc->ksCircle(-m_l, 0, m_d1 / 2.f, 1);
	
	pSketchDef->EndEdit();
	
	ksEntityPtr pExtrude2 = pPart->NewEntity(o3d_cutExtrusion);
	
	ksCutExtrusionDefinitionPtr pCutDef = pExtrude2->GetDefinition();
	pCutDef->directionType = dtReverse;
	
	pCutDef->SetSketch(pSketch2);
	pCutDef->SetSideParam(false, etThroughAll, 0, 0, false);
	
	pExtrude2->Create();
	
	//зададим имя для внутренней грани
	
	ksEntityCollectionPtr flFaces = pPart->EntityCollection(o3d_face);
	for (int i = 0; i < flFaces->GetCount(); i++)
	{
		ksEntityPtr face = flFaces->GetByIndex(i);
		ksFaceDefinitionPtr def = face->GetDefinition();
		if (def->GetOwnerEntity() == pRotate)
		{
			if (def->IsCylinder()) {
				double h, r;
				def->GetCylinderParam(&h, &r);
				if (r == m_Dvnut / 2.f)
				{
					face->Putname("CylinderAssembly");
					face->Update();
				}

			}

		}

	}

	//сохрани
	pDoc->SaveAs("I:\\учеба\\2 курс\\прога\\Sborka2\\Sborka\\myfta.k3d");
	
	//создадим новый документ
	pDoc = pKompasApp5->Document3D();
	pDoc->Create(false, true);
	pPart = pDoc->GetPart(pTop_Part);
	
	//создадим эскиз

	ksEntityPtr pSketch3 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch3->GetDefinition();

	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOZ));

	pSketch3->Create();

	p2DDoc = pSketchDef->BeginEdit();

	double point2[4][2];
	point2[0][0] = 0;
	point2[0][1] = 0;
	point2[1][0] = 0;
	point2[1][1] = m_Dvnut / 2.f;
	point2[2][0] = m_dlinna;
	point2[2][1] = m_Dvnut / 2.f;
	point2[3][0] = m_dlinna;
	point2[3][1] = 0;

	p2DDoc->ksLineSeg(point2[0][0], point2[0][1], point2[1][0], point2[1][1], 1);
	p2DDoc->ksLineSeg(point2[1][0], point2[1][1], point2[2][0], point2[2][1], 1);
	p2DDoc->ksLineSeg(point2[2][0], point2[2][1], point2[3][0], point2[3][1], 1);
	p2DDoc->ksLineSeg(point2[3][0], point2[3][1], point2[0][0], point2[0][1], 1);
	
	p2DDoc->ksLineSeg(-10, 0, 10, 0, 3);

	pSketchDef->EndEdit();
	
	//прокручиваем

	ksEntityPtr pRotate2 = pPart->NewEntity(o3d_bossRotated);

	pRotDef = pRotate2->GetDefinition();
	pRotDef->SetSketch(pSketch3);
	pRotDef->SetSideParam(TRUE, 360);

	pRotate2->Create();

	//сделаем метку на вал 
	
	fledges1 = pPart->EntityCollection(o3d_edge);

	for (int i = 0; i < fledges1->GetCount(); i++) {
		ksEntityPtr pEdge = fledges1->GetByIndex(i);
		ksEdgeDefinitionPtr pEdgeDef = pEdge->GetDefinition();
		
		if (pEdgeDef->GetOwnerEntity() == pRotate2) {
			if (pEdgeDef->IsCircle()) {
				ksVertexDefinitionPtr pVertexDef1 = pEdgeDef->GetVertex(true);
				double x1, y1, z1;
				pVertexDef1->GetPoint(&x1, &y1, &z1);

				if (x1 == 0) {
					ksFaceDefinitionPtr pFaceDef = pEdgeDef->GetAdjacentFace(true);
					ksEntityPtr pFace = pFaceDef->GetEntity();

					pFace->Putname("shaft");
					pFace->Update();
				}
			}
		}
	}
	
	//создаем фаску

	fledges = pPart->EntityCollection(o3d_edge);
	pFillet = pPart->NewEntity(o3d_fillet);

	pFilletDef = pFillet->GetDefinition();
	pFilletDef->radius = m_C;
	fl = pFilletDef->array();
	fl->Clear();
	pChamfer = pPart->NewEntity(o3d_chamfer);

	pChamferDef = pChamfer->GetDefinition();
	pChamferDef->SetChamferParam(true, sqrt(m_C / 2), sqrt(m_C / 2));

	fl = pChamferDef->array();
	fl->Clear();

	for (int i = 0; i < fledges->GetCount(); i++) {
		ksEntityPtr ed = fledges->GetByIndex(i);
		ksEdgeDefinitionPtr def = ed->GetDefinition();
		if (def->GetOwnerEntity() == pRotate2) {
			if (def->IsCircle()) {
				ksVertexDefinitionPtr p1 = def->GetVertex(true);
				ksVertexDefinitionPtr p2 = def->GetVertex(false);
				double x1, y1, z1;

				p1->GetPoint(&x1, &y1, &z1);

				if (x1 == 0) {

					fl->Add(ed);
					ksFaceDefinitionPtr pFaceDef = def->GetAdjacentFace(false);
					ksEntityPtr pFace = pFaceDef->GetEntity();

					pFace->Putname("face2");
					pFace->Update();
				}
				if (x1 != 0) {

					fl->Add(ed);
					ksFaceDefinitionPtr pFaceDef = def->GetAdjacentFace(true);
					ksEntityPtr pFace = pFaceDef->GetEntity();

					pFace->Putname("edge-next-to-the-key");
					pFace->Update();
				}
			}
		}
	}
	pChamfer->Create();
	
	
	
	//создаем шпонку, делаем эскиз
	
	ksEntityPtr pSketch4 = pPart->NewEntity(o3d_sketch);

	pSketchDef = pSketch4->GetDefinition();

	pSketchDef->SetPlane(pPart->GetDefaultEntity(o3d_planeXOY));

	pSketch4->Create();
	
	p2DDoc = pSketchDef->BeginEdit();

	double point4[6][2];
	point4[0][0] = m_dlinna - 1.0 - m_b / 2.f;
	point4[0][1] = m_b / 2.f;

	point4[1][0] = m_dlinna - 1.0;
	point4[1][1] = 0;

	point4[2][0] = m_dlinna - 1.0 - m_b / 2.f;
	point4[2][1] = -m_b / 2.f;

	point4[3][0] = m_dlinna - 1.0 - 10.0 + m_b / 2.f;
	point4[3][1] = m_b / 2.f;

	point4[4][0] = m_dlinna - 1.0 - 10.0;
	point4[4][1] = 0;

	point4[5][0] = m_dlinna - 1.0 - 10.0 + m_b / 2.f;
	point4[5][1] = -m_b / 2.f;

	p2DDoc->ksLineSeg(point4[0][0], point4[0][1], point4[3][0], point4[3][1], 1);
	p2DDoc->ksLineSeg(point4[2][0], point4[2][1], point4[5][0], point4[5][1], 1);

	p2DDoc->ksArcBy3Points(point4[0][0], point4[0][1], point4[1][0], point4[1][1], point4[2][0], point4[2][1], 1);
	p2DDoc->ksArcBy3Points(point4[3][0], point4[3][1], point4[4][0], point4[4][1], point4[5][0], point4[5][1], 1);

	pSketchDef->EndEdit();

	//выдавливаем 

	ksEntityPtr pExtrudeDowel = pPart->NewEntity(o3d_baseExtrusion);
	ksBaseExtrusionDefinitionPtr pBaseDef = pExtrudeDowel->GetDefinition();
	pBaseDef->directionType = dtReverse;
	pBaseDef->SetSketch(pSketch4);
	pBaseDef->SetSideParam(false, etBlind, m_h - m_Dvnut / 2.f, 0, false);
	pExtrudeDowel->Create();

	//делаем метку выдавливание
	
	ksEntityCollectionPtr fledges3 = pPart->EntityCollection(o3d_edge);
	bool flag = false;
	for (int i = 0; i < fledges3->GetCount(); i++) {
		ksEntityPtr pEdge = fledges3->GetByIndex(i);
		ksEdgeDefinitionPtr pEdgeDef = pEdge->GetDefinition();

		ksVertexDefinitionPtr pVertexDef1 = pEdgeDef->GetVertex(false);
		double x1, y1, z1;
		try {
			pVertexDef1->GetPoint(&x1, &y1, &z1);
		}
		catch (...) {
			x1 = 0.f;
			y1 = 0.f;
			z1 = 0.f;
		}
		if (z1 == -(m_h - m_Dvnut / 2.f) && y1 == m_b / 2.f) {
			ksFaceDefinitionPtr pFaceDef = pEdgeDef->GetAdjacentFace(false);
			ksEntityPtr pFace = pFaceDef->GetEntity();

			pFace->Putname("shponka");
			pFace->Update();
		}
		
		
		/*if (z1 == -(m_h - m_Dvnut / 2.f) && y1 == m_b / 2.f && x1 == m_dlinna - 1.0 - m_b / 2.f && flag) {
			flag = true;
			ksFaceDefinitionPtr pFaceDef = pEdgeDef->GetAdjacentFace(true);
			ksEntityPtr pFace = pFaceDef->GetEntity();

			pFace->Putname("shponka");
			pFace->Update();
		}
		if (z1 == -(m_h - m_Dvnut / 2.f) && y1 == m_b / 2.f && x1 == m_dlinna - 1.0 - m_b / 2.f) {
			flag = true;
		}*/
	}
	//сохрани
	pDoc->SaveAs("I:\\учеба\\2 курс\\прога\\Sborka2\\Sborka\\val.k3d");

	//собираем
	
	pDoc = pKompasApp5->Document3D();
	pDoc->Create(false, false);
	pPart = pDoc->GetPart(pTop_Part);
	
	ksPartPtr pDeatial[3];
	pDoc->SetPartFromFile("I:\\учеба\\2 курс\\прога\\Sborka2\\Sborka\\myfta.k3d", pPart, true);
	pDoc->SetPartFromFile("I:\\учеба\\2 курс\\прога\\Sborka2\\Sborka\\val.k3d", pPart, true);
	pDoc->SetPartFromFile("I:\\учеба\\2 курс\\прога\\Sborka2\\Sborka\\val.k3d", pPart, true);
	
	pDeatial[0] = pDoc->GetPart(0);
	pDeatial[1] = pDoc->GetPart(1);
	pDeatial[2] = pDoc->GetPart(2);
	
	ksEntityPtr CylinderAssembly;
	ksEntityPtr shaft[2];
	ksEntityPtr face2[2];
	ksEntityPtr enttk[2];
	ksEntityPtr shponka[2];
	ksEntityPtr lowerbound;
	ksEntityPtr face_mufta;
	
	ksEntityCollectionPtr pDeatialFaces = pDeatial[0]->EntityCollection(o3d_face);
	CylinderAssembly = pDeatialFaces->GetByName("CylinderAssembly", true, true);
	lowerbound = pDeatialFaces->GetByName("lower-bound", true, true);
	face_mufta = pDeatialFaces->GetByName("face-mufta", true, true);
	
	for (int i = 1; i < 3; i++)
	{
		ksEntityCollectionPtr pDeatialFaces = pDeatial[i]->EntityCollection(o3d_face);

		shaft[i-1] = pDeatialFaces->GetByName("shaft", true, true);
		face2[i-1] = pDeatialFaces->GetByName("face2", true, true);
		enttk[i-1] = pDeatialFaces->GetByName("edge-next-to-the-key", true, true);
		shponka[i - 1] = pDeatialFaces->GetByName("shponka", true, true);
	}
	
	
	//pDoc->AddMateConstraint(mc_Concentric, CylinderAssembly,face[0], -1, 1, 0);
	pDoc->AddMateConstraint(mc_Concentric, CylinderAssembly, shaft[0], 1, 1, 0);
	pDoc->AddMateConstraint(mc_Concentric, CylinderAssembly, shaft[1], -1, 1, 0);
	pDoc->AddMateConstraint(mc_Coincidence, shponka[0], lowerbound, -1, 1, 0);
	pDoc->AddMateConstraint(mc_Coincidence, lowerbound, shponka[1], -1, 1, 0);
	//pDoc->AddMateConstraint(mc_Coincidence, face_mufta, enttk[1], -1, 1, 0);
	pDoc->AddMateConstraint(mc_Distance, face_mufta, enttk[1], -1, 1, -m_dlinna / 2.f + 1.f);
	pDoc->AddMateConstraint(mc_Distance, face_mufta, enttk[0], 1, 1, -m_dlinna / 2.f - 1.f);
	
	//pDoc->AddMateConstraint(mc_Coincidence, shponka[0], vnut2[0], 1, 1, 0);
	//pDoc->AddMateConstraint(mc_Coincidence, enttk[0], enttk[1], 1, 1, 0);
	pDoc->RebuildDocument();
	////perpendicular between face and ZOY plane 
	////pDoc->AddMateConstraint(mc_Perpendicular, face2[1], face[0], -1, 1, 0);
	//
	//
	//
	
	
	//сделаем метку на грань
	
	//ksEntityCollectionPtr fledges2 = pPart->EntityCollection(o3d_edge);
	//
	//for (int i = 0; i < fledges2->GetCount(); i++) {
	//	ksEntityPtr pEdge = fledges2->GetByIndex(i);
	//	ksEdgeDefinitionPtr pEdgeDef = pEdge->GetDefinition();

	//	if (pEdgeDef->GetOwnerEntity() == pRotate2) {
	//		if (pEdgeDef->IsCircle()) {
	//			ksVertexDefinitionPtr pVertexDef1 = pEdgeDef->GetVertex(true);
	//			double x1, y1, z1;
	//			pVertexDef1->GetPoint(&x1, &y1, &z1);

	//			if (y1 == 0) {
	//				ksFaceDefinitionPtr pFaceDef = pEdgeDef->GetAdjacentFace(true);
	//				ksEntityPtr pFace = pFaceDef->GetEntity();

	//				pFace->Putname("face2");
	//				pFace->Update();
	//			}
	//		}
	//	}
	//}

	
	//скругление на шпонке
	/*pFilletDef = pFillet->GetDefinition();*/
	//pFilletDef->radius = m_R;
	//fl->Clear();
	//

	//for (int i = 0; i < fledges->GetCount(); i++)
	//{
	//	ksEntityPtr ed = fledges->GetByIndex(i);
	//	ksEdgeDefinitionPtr def = ed->GetDefinition();
	//	
	//	if (def->IsStraight() && def->GetLength() == m_dlinna)
	//	{
	//		ksVertexDefinitionPtr p1 = def->GetVertex(true);
	//		ksVertexDefinitionPtr p2 = def->GetVertex(false);
	//		double x1, y1, z1, x2, y2, z2;
	//		p1->GetPoint(&x1, &y1, &z1);
	//		p2->GetPoint(&x2, &y2, &z2);
	//		/*fl->Add(ed);*/

	//		if (z1 < -m_Dvnut / 2.f && abs(x1-x2) != 0 && abs(y1-y2) == 0) {

	//			fl->Add(ed);
	//		}
	//	}
	//}
	//pFillet->Create();
}
