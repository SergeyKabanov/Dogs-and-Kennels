// DOGS_OUTERDlg.h : header file
//

#if !defined(AFX_DOGS_OUTERDLG_H__85DAC6AA_3662_11D5_AEA3_00A0D2162638__INCLUDED_)
#define AFX_DOGS_OUTERDLG_H__85DAC6AA_3662_11D5_AEA3_00A0D2162638__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDOGS_OUTERDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CDOGS_OUTERDlg dialog

class CDOGS_OUTERDlg : public CDialog
{
	DECLARE_DYNAMIC(CDOGS_OUTERDlg);
	friend class CDOGS_OUTERDlgAutoProxy;

// Construction
public:
	CDOGS_OUTERDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CDOGS_OUTERDlg();

// Dialog Data
	//{{AFX_DATA(CDOGS_OUTERDlg)
	enum { IDD = ID_DOGS_OUTER_DLG };
	CListBox	m_DogsList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDOGS_OUTERDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CBitmapButton buttonOK;

	CDOGS_OUTERDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CDOGS_OUTERDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDblclkDogsList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOGS_OUTERDLG_H__85DAC6AA_3662_11D5_AEA3_00A0D2162638__INCLUDED_)
