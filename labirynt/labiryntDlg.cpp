
// labiryntDlg.cpp : implementation file
//

#include "stdafx.h"
#include "labirynt.h"
#include "labiryntDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ClabiryntDlg dialog




ClabiryntDlg::ClabiryntDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ClabiryntDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ClabiryntDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(ClabiryntDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &ClabiryntDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &ClabiryntDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ClabiryntDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ClabiryntDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &ClabiryntDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// ClabiryntDlg message handlers

BOOL ClabiryntDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void ClabiryntDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void ClabiryntDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR ClabiryntDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ClabiryntDlg::OnBnClickedOk()
{
	CDC *dc = GetDC();
	plansza = new Plansza;
	generator = new LabiryntGen(plansza);
	generator->Generuj(plansza);
	plansza->Buduj(dc);
	sterowanie = new UkladSterowania(plansza, dc);
	bohater = new Krysztal(20,20,380,380);
	sterowanie->dodajBohatera(bohater);
	sterowanie->naStart();


}


void ClabiryntDlg::OnBnClickedButton1()
{
	sterowanie->wPrawo();
}


void ClabiryntDlg::OnBnClickedButton2()
{
	sterowanie->wLewo();
}


void ClabiryntDlg::OnBnClickedButton3()
{
	sterowanie->wGore();
}


void ClabiryntDlg::OnBnClickedButton4()
{
	sterowanie->wDol();
}
