
// labiryntDlg.h : header file
//

#pragma once
#include "Plansza.h"
#include "LabiryntGen.h"
#include "Obiekt.h"
#include "UkladSterowania.h"
#include "Bohater.h"
#include "Krysztal.h"
#include "ZapiszDlg.h"
// ClabiryntDlg dialog
class ClabiryntDlg : public CDialogEx
{
// Construction
public:
	ClabiryntDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LABIRYNT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	ZapiszDlg Okno;
	afx_msg HCURSOR OnQueryDragIcon();
	Plansza *plansza;
	LabiryntGen *generator;
	UkladSterowania *sterowanie;
	Obiekt *bohater;
	Bohater *boh;
	CString m_Text;
	RECT *rct;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	BOOL ClabiryntDlg::PreTranslateMessage(MSG* pMSG);
	afx_msg void OnBnClickedCancel();
};


