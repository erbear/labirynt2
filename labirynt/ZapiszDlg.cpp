// ZapiszDlg.cpp : implementation file
//

#include "stdafx.h"
#include "labirynt.h"
#include "ZapiszDlg.h"
#include "afxdialogex.h"


// ZapiszDlg dialog

IMPLEMENT_DYNAMIC(ZapiszDlg, CDialogEx)

ZapiszDlg::ZapiszDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ZapiszDlg::IDD, pParent)
{
}

ZapiszDlg::~ZapiszDlg()
{
}

void ZapiszDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	CFont *font;
	font = new CFont;
	font->CreateFontA(35,0,0,0,0,0,0,0,0,0,0,0,0,0);
	((CWnd*)GetDlgItem(IDC_STATIC))->SetFont(font,1);
	((CWnd*)GetDlgItem(IDC_EDIT1))->SetFont(font,1);
}


BEGIN_MESSAGE_MAP(ZapiszDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &ZapiszDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &ZapiszDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &ZapiszDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ZapiszDlg message handlers


void ZapiszDlg::OnBnClickedCancel()
{
}


void ZapiszDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void ZapiszDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowText(m_Text); 

	CDialogEx::OnOK();
}

CString ZapiszDlg::getm_Text()
{
	return m_Text;
}