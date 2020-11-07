// KokhovDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Kokhov.h"
#include "KokhovDlg.h"
#include "math.h"
#include "stdlib.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

int i,j,n,A,B;
CString Stroka,Stroka1[20][20], Stroka2[20], Stroka3[20], Stroka4[20];
float data[20][20], Dohod[20], Sebest[20], Okup[20],Renta[20], dat[20];

const COLORREF CLOUDBLUE = RGB(128, 184, 223);
const COLORREF WHITE = RGB(255, 255, 255);
const COLORREF BLACK = RGB(1, 1, 1);
const COLORREF DKGRAY = RGB(128, 128, 128);
const COLORREF LTGRAY = RGB(192, 192, 192);
const COLORREF YELLOW = RGB(255, 255, 0);
const COLORREF DKYELLOW = RGB(128, 128, 0);
const COLORREF RED = RGB(255, 0, 0);
const COLORREF DKRED = RGB(128, 0, 0);
const COLORREF BLUE = RGB(0, 0, 255);
const COLORREF DKBLUE = RGB(0, 0, 128);
const COLORREF CYAN = RGB(0, 255, 255);
const COLORREF DKCYAN = RGB(0, 128, 128);
const COLORREF GREEN = RGB(0, 255, 0);
const COLORREF DKGREEN = RGB(0, 128, 0);
const COLORREF MAGENTA = RGB(255, 0, 255);
const COLORREF DKMAGENTA = RGB(128, 0, 128);

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKokhovDlg dialog

CKokhovDlg::CKokhovDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKokhovDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKokhovDlg)
	m_edit1 = 0.0f;
	m_edit2 = 0.0f;
	m_edit3 = 0;
	m_edit4 = 0.0f;
	m_edit5 = 0.0f;
	m_edit6 = 0.0f;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKokhovDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKokhovDlg)
	DDX_Control(pDX, IDC_MSFLEXGRID1, m_FG1);
	DDX_Control(pDX, IDC_MSFLEXGRID2, m_FG2);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDX_Text(pDX, IDC_EDIT4, m_edit4);
	DDX_Text(pDX, IDC_EDIT5, m_edit5);
	DDX_Text(pDX, IDC_EDIT6, m_edit6);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CKokhovDlg, CDialog)
	//{{AFX_MSG_MAP(CKokhovDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKokhovDlg message handlers

BOOL CKokhovDlg::OnInitDialog()
{ 
	CDialog::OnInitDialog();
	// Set the icon for this dialog. The framework does this automatically
	// when the application›s main window is not a dialog
	SetIcon(m_hIcon, TRUE); // Set big icon
	SetIcon(m_hIcon, FALSE); // Set small icon

	// TODO: Add extra initialization here
	// делаем невидимыми таблицы, текст и кнопку
	GetDlgItem(IDC_MSFLEXGRID1)->ShowWindow(false);
	GetDlgItem(IDC_TEXT1)->ShowWindow(false);
	GetDlgItem(IDC_STATIC4)->ShowWindow(false);
	GetDlgItem(IDC_STATIC5)->ShowWindow(false);
	GetDlgItem(IDC_STATIC6)->ShowWindow(false);
	GetDlgItem(IDC_EDIT4)->ShowWindow(false);
	GetDlgItem(IDC_EDIT5)->ShowWindow(false);
	GetDlgItem(IDC_EDIT6)->ShowWindow(false);
	GetDlgItem(IDC_MSFLEXGRID2)->ShowWindow(false);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(false);
	// установка параметров шрифта
//	m_Font.CreateFont(25, 0, 0, 0, FW_NORMAL, FALSE,FALSE,0,0,0,0,0,0,"Tahoma");
//	GetDlgItem(IDC_TEXT)->SetFont(&m_Font);
//	GetDlgItem(IDC_TEXT2)->SetFont(&m_Font);
	// установить текст
	SetDlgItemText(IDC_TEXT, "Вводим высоты двух твердых пунктов (марок) и количество измерений");
	SetDlgItemText(IDC_TEXT2, "Схема одиночного нивилирного хода");
	SetDlgItemText(IDC_STATIC1, "Высота начального пункта");
	SetDlgItemText(IDC_STATIC2, "Высота конечного пункта");
	SetDlgItemText(IDC_STATIC3, "Количиство промежуточных точек");
	SetDlgItemText(IDC_BUTTON1, "Вывести таблицу для ввода измеренных превышений");
	SetDlgItemText(IDC_BUTTON2, "Рассчетать параметры");


	return TRUE; // return TRUE unless you set the focus to a control
}

void CKokhovDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKokhovDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKokhovDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CKokhovDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CKokhovDlg)
	ON_EVENT(CKokhovDlg, IDC_MSFLEXGRID1, -600 /* Click */, OnClickMsFlexgrid1, VTS_NONE)
	ON_EVENT(CKokhovDlg, IDC_MSFLEXGRID1, -603 /* KeyPress */, OnKeyPressMsFlexgrid1, VTS_PI2)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CKokhovDlg::OnClickMsFlexgrid1() 
{
//Обработка клика мышкой
Stroka="";
int h=m_FG1.GetCol();
int b=m_FG1.GetRow();
A=h; B=b;
for(i=1; i<n+1; i++)
for(j=1; j<4; j++)
{
m_FG1.SetCol(j);
m_FG1.SetRow(i);
m_FG1.SetCellBackColor(RGB(255,255,255));
}

m_FG1.SetCol(A);
m_FG1.SetRow(B);
m_FG1.SetCellBackColor(RGB(200,255,200));
m_FG1.SetCellFontBold(true);
m_FG1.SetCellFontSize(12);
}
void CKokhovDlg::OnKeyPressMsFlexgrid1(short FAR* KeyAscii) 
{
//Запись из буфера клавиатуры в ячейку таблицы
Stroka+=FAR * KeyAscii;
m_FG1.SetTextMatrix(B,A,Stroka);
}


void CKokhovDlg::OnButton1() 
{
// TODO: Add your control notification handler code here
//SetDlgItemText(IDC_ST_TEXT, «Ввести значения превышений»);
	char s[10]; int l;
//m_Font.CreateFont(25, 0, 0, 0, FW_NORMAL, FALSE,FALSE,0,0,0,0,0,0, "Tahoma");
	GetDlgItem(IDC_TEXT)->ShowWindow(false);
	GetDlgItem(IDC_TEXT1)->ShowWindow(true);
//GetDlgItem(IDC_TEXT1)->SetFont(&m_Font);
	SetDlgItemText(IDC_TEXT1, "Вводим измеренные превышения");
//SetDlgItemText(IDC_TEXT, «Вводим измеренные значения превышений прямые и обратные и длины участков");
	GetDlgItem(IDC_MSFLEXGRID1)->ShowWindow(true);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(true);
	UpdateData(true);

	n=m_edit3;
	//размеры таблицы
	m_FG1.SetCols(4);
	m_FG1.SetRows(n+1);
	//высота ячеек
	m_FG1.SetRowHeight(0,800);
	for(l=1; l<n+1; l++)
	m_FG1.SetRowHeight(l,350);
	//размер шрифта и толщина символов
	m_FG1.SetRow(0);
	for(l=0; l<4; l++)
	{
		m_FG1.SetCol(l);
		m_FG1.SetCellFontSize(9);
		m_FG1.SetCellFontBold(true);
	}
	//размеры шапки таблицы
	m_FG1.SetColWidth(0,400);
	m_FG1.SetColWidth(1,1300);
	m_FG1.SetColWidth(2,1300);
	m_FG1.SetColWidth(3,900);
	m_FG1.SetWordWrap(true);
	m_FG1.SetTextMatrix(0,0,"№\n п/п");
	m_FG1.SetTextMatrix(0,1,"Превышение\nпрямое,\nм");
	m_FG1.SetTextMatrix(0,2,"Превышение\nобратное,\nм");
	m_FG1.SetTextMatrix(0,3,"Длина\nсекции,\nкм");
	//нумерация строк
	j=0;
	for(i=0; i<n; i++)
	{
	itoa(i+1,s,10);
	m_FG1.SetTextMatrix(i+1,j,s);
	}



}

void CKokhovDlg::OnButton2() 
{
	GetDlgItem(IDC_STATIC4)->ShowWindow(true);
	GetDlgItem(IDC_STATIC5)->ShowWindow(false);
	GetDlgItem(IDC_STATIC6)->ShowWindow(false);
	GetDlgItem(IDC_EDIT4)->ShowWindow(true);
	GetDlgItem(IDC_EDIT5)->ShowWindow(false);
	GetDlgItem(IDC_EDIT6)->ShowWindow(false);
	// TODO: Add your control notification handler code here
	float SummaPrev,PrevTeor,SummaDlin, sredn[10], MaxDelta; char a[20],b[20]="";
	int l,len,k1,k2,k5, d1,pd,d22;

	CString z;
	float d,d2, d2L, L, V, Vi, PredDi, fh;
	char s[10];
	GetDlgItem(IDC_TEXT1)->ShowWindow(false);
	SetDlgItemText(IDC_STATIC4, "Длина хода");
	SetDlgItemText(IDC_STATIC5, "Длина хода");
	SetDlgItemText(IDC_STATIC6, "Длина хода");
	// контроль заполненности таблицы исходных данных
	k2=0;
	for(i=1; i<n+1; i++)
	{
	k1=0;
	for(j=1; j<4; j++)
	{
	Stroka1[i][j]=m_FG1.GetTextMatrix(i,j);
	len=strlen(Stroka1[i][j]);
	if(len==0) k1++;
	}
	if(k1==4) k2++;
	}
	// чтение исходных данных из первой таблицы
	for(i=1; i<n+1; i++)
	for(j=1; j<4; j++)
	{
	Stroka1[i][j]=m_FG1.GetTextMatrix(i,j);
	data[i][j]=atof(Stroka1[i][j]);
	}
	//таблица результатов
	m_FG2.SetCols(8);
	m_FG2.SetRows(n+1-k2);
	m_FG2.SetRowHeight(0,350);
	for(l=1; l<n+1-k2; l++)
	m_FG2.SetRowHeight(l,350);
	m_FG2.SetRow(0);
	//размер шрифта и толщина символов
	m_FG2.SetRow(0);
	for(l=0; l<8; l++)
	{
	m_FG2.SetCol(l);
	m_FG2.SetCellFontSize(9);

	m_FG2.SetCellFontBold(true);
	}
	m_FG2.SetRowHeight(0,800);
	m_FG2.ShowWindow(true);
	m_FG2.SetColWidth(0,400);
	m_FG2.SetColWidth(1,1250);
	m_FG2.SetColWidth(2,1250);
	m_FG2.SetColWidth(3,1250);
	m_FG2.SetColWidth(4,1250);
	m_FG2.SetColWidth(5,1250);
	m_FG2.SetColWidth(6,1250);
	m_FG2.SetColWidth(7,1250);
	m_FG2.SetCellFontBold(true);
	m_FG2.SetCellFontSize(9);
	m_FG2.SetTextMatrix(0,0,"№\n п/п");
	m_FG2.SetTextMatrix(0,1,"Среднее превышение\nм");
	m_FG2.SetTextMatrix(0,2,"d,\nм");
	m_FG2.SetTextMatrix(0,3,"доп.превыш,\nм");
	m_FG2.SetTextMatrix(0,4,"d2,\nкв.м");
	m_FG2.SetTextMatrix(0,5,"d2/L,\nкв.м/км");
	m_FG2.SetTextMatrix(0,6,"Поправка V,\nм");
	m_FG2.SetTextMatrix(0,7,"Исправл.прев. V,\nм");
	m_FG2.SetWordWrap(true);
	//нумерация строк таблицы результатов
	j=0;
	for(i=0; i<n-k2; i++)
	{
	itoa(i+1,s,10);
	m_FG2.SetTextMatrix(i+1,j,s);
	}
	/*
	CString W=»Сумма средних превышений практических=», W1=» Теоретическая разница высот=»,
	W2=» Допустимая невязка в мм=»,W3=» Предельная невязка=»,W4;
	//char buf[50];
	gcvt (SummaPrev,5,buf);
	W=W+buf;
	//MessageBox(W);
	PrevTeor=m_edit2-m_edit1;
	gcvt(PrevTeor,5,buf);
	W1=W1+buf;
	//MessageBox(W1);
	DopNevaz=(SummaPrev-PrevTeor);//*1000;
	gcvt(abs(DopNevaz),5,buf);
	W2=W2+buf;
	//MessageBox(W2);
	SummaDlin=10*pow(SummaDlin,.5);
	gcvt(SummaDlin,5,buf);
	W3=W3+buf;
	W4=W+W1+W2+W3;
	MessageBox(W4);
	//if(DopNevaz<SummaDlin)// проверка корректности исходных данных
	//MessageBox»Б у д е м у р а в н и в а т ь»);
	//else MessageBox(«Н а д о в с е п е р е м е р и т ь»);
	*/
	SummaPrev=SummaDlin=MaxDelta=k5=0;
	for(i=1; i<n+1; i++)
	{
	sredn[i]=(fabs(data[i][1])+fabs(data[i][2]))/2;//ошибка в расчете нет дробных
	if(data[i][1]<0) 
	sredn[i]=sredn[i]*(-1);
	SummaPrev+=sredn[i];
	SummaDlin+=data[i][3];
	}
	PrevTeor=m_edit2-m_edit1;
	fh=SummaPrev-PrevTeor;//значение невязки
	for(i=1; i<n+1; i++)
	{
	gcvt(sredn[i],5,a);
	m_FG2.SetCol(1);
	m_FG2.SetRow(i);
	m_FG2.SetCellFontBold(true);
	m_FG2.SetCellFontSize(9);
	m_FG2.SetTextMatrix(i,1,a);
	d=data[i][1]+data[i][2];
	d1=d*1000;
	gcvt(d1,5,a);
	m_FG2.SetCol(2);
	m_FG2.SetRow(i);
	m_FG2.SetCellFontBold(true);
	m_FG2.SetCellFontSize(9);
	m_FG2.SetTextMatrix(i,2,a);
	PredDi=10*pow(data[i][3],.5); pd=PredDi;
	gcvt(pd,5,a);
	m_FG2.SetCol(3);
	m_FG2.SetRow(i);
	
	m_FG2.SetCellFontBold(true);
	m_FG2.SetCellFontSize(9);
	m_FG2.SetTextMatrix(i,3,a);
	d2=d*d; d22=d2*1000000;
	gcvt(d22,5,a);
	m_FG2.SetCol(4);
	m_FG2.SetRow(i);
	m_FG2.SetCellFontBold(true);
	m_FG2.SetCellFontSize(9);
	m_FG2.SetTextMatrix(i,4,a);
	d2L=d2/data[i][3];
	gcvt(d2L*1000000,5,a);
	m_FG2.SetCol(5);
	m_FG2.SetRow(i);
	m_FG2.SetCellFontBold(true);
	m_FG2.SetCellFontSize(9);
	m_FG2.SetTextMatrix(i,5,a);
	L=0; L=L+data[i][3];
	// расчет поправки
	V=-fh*data[i][3]/SummaDlin;
	//V=-DopNevaz*data[i][3]/SummaDlin;
	gcvt(V*1000,5,a);
	m_FG2.SetCol(6);
	m_FG2.SetRow(i);
	m_FG2.SetCellFontBold(true);
	m_FG2.SetCellFontSize(9);
	m_FG2.SetTextMatrix(i,6,a);
	// расчет исправленного превышения
	Vi=sredn[i]+V;
	gcvt(Vi,5,a);
	m_FG2.SetCol(7);
	m_FG2.SetRow(i);
	m_FG2.SetCellFontBold(true);
	m_FG2.SetCellFontSize(9);
	m_FG2.SetTextMatrix(i,7,a);
	if((d==PredDi)||(d>PredDi)) k5+=1;
	}
	if(k5>0) MessageBox("Нельзя!!!");
	m_edit4=SummaDlin;
	m_edit5=SummaPrev;
	m_edit6=fh;
	UpdateData(false);
}
