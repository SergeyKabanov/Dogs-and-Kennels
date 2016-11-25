// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "DOGS_OUTER.h"
#include "DlgProxy.h"
#include "DOGS_OUTERDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDOGS_OUTERDlgAutoProxy

IMPLEMENT_DYNCREATE(CDOGS_OUTERDlgAutoProxy, CCmdTarget)

CDOGS_OUTERDlgAutoProxy::CDOGS_OUTERDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CDOGS_OUTERDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CDOGS_OUTERDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CDOGS_OUTERDlgAutoProxy::~CDOGS_OUTERDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CDOGS_OUTERDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CDOGS_OUTERDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CDOGS_OUTERDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDOGS_OUTERDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CDOGS_OUTERDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IDOGS_OUTER to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {85DAC6A5-3662-11D5-AEA3-00A0D2162638}
static const IID IID_IDOGS_OUTER =
{ 0x85dac6a5, 0x3662, 0x11d5, { 0xae, 0xa3, 0x0, 0xa0, 0xd2, 0x16, 0x26, 0x38 } };

BEGIN_INTERFACE_MAP(CDOGS_OUTERDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CDOGS_OUTERDlgAutoProxy, IID_IDOGS_OUTER, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {85DAC6A3-3662-11D5-AEA3-00A0D2162638}
IMPLEMENT_OLECREATE2(CDOGS_OUTERDlgAutoProxy, "DOGS_OUTER.Application", 0x85dac6a3, 0x3662, 0x11d5, 0xae, 0xa3, 0x0, 0xa0, 0xd2, 0x16, 0x26, 0x38)

/////////////////////////////////////////////////////////////////////////////
// CDOGS_OUTERDlgAutoProxy message handlers
