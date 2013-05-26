#pragma once


// ZapiszDlg dialog

class ZapiszDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ZapiszDlg)

public:
	ZapiszDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ZapiszDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	CString m_Text;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	CString getm_Text();
};
