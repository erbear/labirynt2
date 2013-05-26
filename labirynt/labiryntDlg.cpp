
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
	ON_BN_CLICKED(IDCANCEL, &ClabiryntDlg::OnBnClickedCancel)
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
	CDC *dc = GetDC();
	
	sterowanie = new UkladSterowania(dc);
	
	sterowanie->stworzPlansze();

	CFont *font;
	font = new CFont;
	font->CreateFontA(40,0,0,0,0,0,0,0,0,0,0,0,0,0);
	((CWnd*)GetDlgItem(IDC_STATIC))->SetFont(font,1);

	delete font;
	font = new CFont;
	font->CreateFontA(25,0,0,0,0,0,0,0,0,0,0,0,0,0);

	((CWnd*)GetDlgItem(IDC_STATIC3))->SetFont(font,1);
	((CWnd*)GetDlgItem(IDC_STATIC4))->SetFont(font,1);
	((CWnd*)GetDlgItem(IDC_STATIC5))->SetFont(font,1);
	
	delete font;
	font = new CFont;
	font->CreateFontA(17,0,0,0,0,0,0,0,0,0,0,0,0,0);

	((CWnd*)GetDlgItem(IDC_STATIC1))->SetFont(font,1);
	
	delete font;
	font = new CFont;
	font->CreateFontA(35,0,0,0,0,0,0,0,0,0,0,0,0,0);

	((CWnd*)GetDlgItem(IDOK))->SetFont(font,1);
	((CWnd*)GetDlgItem(IDC_EDIT1))->SetFont(font,1);
	((CWnd*)GetDlgItem(IDC_EDIT2))->SetFont(font,1);
	((CWnd*)GetDlgItem(IDC_EDIT3))->SetFont(font,1);

	m_Text.Format("0");
	((CEdit*)GetDlgItem(IDC_EDIT1))->SetWindowText(m_Text);
	((CEdit*)GetDlgItem(IDC_EDIT2))->SetWindowText(m_Text);

	
	sterowanie->wczytajWyniki();
	m_Text.Format("1. %s (%d)", sterowanie->m_pierwsze().c_str(), sterowanie->m_lvl1());
	((CEdit*)GetDlgItem(IDC_STATIC6))->SetWindowText(m_Text);
	m_Text.Format("2. %s (%d)", sterowanie->m_drugie().c_str(),sterowanie->m_lvl2());
	((CEdit*)GetDlgItem(IDC_STATIC7))->SetWindowText(m_Text);
	m_Text.Format("3. %s (%d)", sterowanie->m_trzecie().c_str(),sterowanie->m_lvl3());
	((CEdit*)GetDlgItem(IDC_STATIC8))->SetWindowText(m_Text);

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
	
	boh = new Bohater();
	sterowanie->dodajBohatera(boh);
	sterowanie->Start();
	
}

BOOL ClabiryntDlg::PreTranslateMessage(MSG* pMSG)
{   
	if(pMSG->message == WM_KEYDOWN)
	{
        if ( pMSG->wParam == VK_RIGHT ) 
        {
			sterowanie->wPrawo();
			m_Text.Format("%d",boh->ilePkt());
			((CEdit*)GetDlgItem(IDC_EDIT1))->SetWindowText(m_Text);
			m_Text.Format("%d",boh->ileRuchow());
			((CEdit*)GetDlgItem(IDC_EDIT2))->SetWindowText(m_Text);
			m_Text.Format("%d",sterowanie->ktoryLvl());
			((CEdit*)GetDlgItem(IDC_EDIT3))->SetWindowText(m_Text);
		}
		if ( pMSG->wParam == VK_LEFT )
		{
			sterowanie->wLewo(); 
			m_Text.Format("%d",boh->ilePkt());
			((CEdit*)GetDlgItem(IDC_EDIT1))->SetWindowText(m_Text);
			m_Text.Format("%d",boh->ileRuchow());
			((CEdit*)GetDlgItem(IDC_EDIT2))->SetWindowText(m_Text);
			m_Text.Format("%d",sterowanie->ktoryLvl());
			((CEdit*)GetDlgItem(IDC_EDIT3))->SetWindowText(m_Text);
		}
		if ( pMSG->wParam == VK_UP )
		{
			sterowanie->wGore(); 
			m_Text.Format("%d",boh->ilePkt());
			((CEdit*)GetDlgItem(IDC_EDIT1))->SetWindowText(m_Text);
			m_Text.Format("%d",boh->ileRuchow());
			((CEdit*)GetDlgItem(IDC_EDIT2))->SetWindowText(m_Text);
			m_Text.Format("%d",sterowanie->ktoryLvl());
			((CEdit*)GetDlgItem(IDC_EDIT3))->SetWindowText(m_Text);
		}
		if ( pMSG->wParam == VK_DOWN )
		{
			sterowanie->wDol(); 
			m_Text.Format("%d",boh->ilePkt());
			((CEdit*)GetDlgItem(IDC_EDIT1))->SetWindowText(m_Text);
			m_Text.Format("%d",boh->ileRuchow());
			((CEdit*)GetDlgItem(IDC_EDIT2))->SetWindowText(m_Text);
			m_Text.Format("%d",sterowanie->ktoryLvl());
			((CEdit*)GetDlgItem(IDC_EDIT3))->SetWindowText(m_Text);
		}
		
	}
		return CDialog::PreTranslateMessage(pMSG);
}


void ClabiryntDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	if (sterowanie->czyRekord())
	{
		int nRet = Okno.DoModal();

		if ( nRet == IDOK )
		{
			string tmp;
			m_Text = Okno.getm_Text();
			tmp = m_Text;
			sterowanie->zapiszWyniki(tmp);
			CDialogEx::OnCancel();
		}
	}else
	CDialogEx::OnCancel();
}
