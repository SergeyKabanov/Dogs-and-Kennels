// DOGS_OUTER.h : main header file for the DOGS_OUTER application
//

#if !defined(AFX_DOGS_OUTER_H__85DAC6A8_3662_11D5_AEA3_00A0D2162638__INCLUDED_)
#define AFX_DOGS_OUTER_H__85DAC6A8_3662_11D5_AEA3_00A0D2162638__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDOGS_OUTERApp:
// See DOGS_OUTER.cpp for the implementation of this class
//

class CDOGS_OUTERApp : public CWinApp
{
public:
	CDOGS_OUTERApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDOGS_OUTERApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

CString GetAppPathName();

	//{{AFX_MSG(CDOGS_OUTERApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOGS_OUTER_H__85DAC6A8_3662_11D5_AEA3_00A0D2162638__INCLUDED_)
