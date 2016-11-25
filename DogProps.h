#if !defined(AFX_DOGPROPS_H__07DBB115_3705_11D5_AEA3_00A0D2162638__INCLUDED_)
#define AFX_DOGPROPS_H__07DBB115_3705_11D5_AEA3_00A0D2162638__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DogProps.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDogProps dialog

class CDogProps : public CDialog
{
// Construction
public:
	CDogProps(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDogProps)
	enum { IDD = IDD_PROPERTIES_Dlg };
	CEdit	m_NameEdit;
	CEdit	m_HairEdit;
	CEdit	m_BreedEdit;
	CString	m_BreedString;
	CString	m_HairString;
	CString	m_NameString;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDogProps)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CBitmapButton buttonOK;

	// Generated message map functions
	//{{AFX_MSG(CDogProps)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOGPROPS_H__07DBB115_3705_11D5_AEA3_00A0D2162638__INCLUDED_)
