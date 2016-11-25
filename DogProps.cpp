// DogProps.cpp : implementation file
//

#include "stdafx.h"
#include "DOGS_OUTER.h"
#include "DogProps.h"
#include "dibapi.h"
#include "smartbmp.h"
#include "standard.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//################################################################################################
extern CString NameToShow;
extern CString BreedToShow;
extern CString HairToShow;
/////////////////////////////////////////////////////////////////////////////
// CDogProps dialog
CDogProps::CDogProps(CWnd* pParent /*=NULL*/)
	: CDialog(CDogProps::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDogProps)
	m_BreedString = _T("");
	m_HairString = _T("");
	m_NameString = _T("");
	//}}AFX_DATA_INIT
if(!buttonOK.LoadBitmaps(IDB_OK_UP,IDB_OK_DN))
	{
	TRACE0("Failed to load bitmaps for buttons\n");
	AfxThrowResourceException();
	}
}


void CDogProps::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDogProps)
	DDX_Control(pDX, IDC_EDIT_NAME, m_NameEdit);
	DDX_Control(pDX, IDC_EDIT_HAIR, m_HairEdit);
	DDX_Control(pDX, IDC_EDIT_BREED, m_BreedEdit);
	DDX_Text(pDX, IDC_EDIT_BREED, m_BreedString);
	DDX_Text(pDX, IDC_EDIT_HAIR, m_HairString);
	DDX_Text(pDX, IDC_EDIT_NAME, m_NameString);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDogProps, CDialog)
	//{{AFX_MSG_MAP(CDogProps)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDogProps message handlers
//###################################################################################################
BOOL CDogProps::OnInitDialog() 
{
CString OurString;
//.................................................................................................
CDialog::OnInitDialog();
//..................................................................................
VERIFY(buttonOK.SubclassDlgItem(IDOK, this));
buttonOK.SizeToContent();
//..................................................................................	
// TODO: Add extra initialization here
OurString.Format("Information about %s:",NameToShow);
SetWindowText(OurString);
SetDlgItemText(IDC_EDIT_BREED,BreedToShow);
SetDlgItemText(IDC_EDIT_HAIR,HairToShow);
SetDlgItemText(IDC_EDIT_NAME,NameToShow);
//................................................................................................	
return TRUE;  // return TRUE unless you set the focus to a control
// EXCEPTION: OCX Property Pages should return FALSE
}
//####################################################################################################
void CDogProps::OnOK() 
{
// TODO: Add extra validation here
GetDlgItemText(IDC_EDIT_HAIR,HairToShow);
HairToShow.Remove(',');	
if(HairToShow.GetLength()==0)
{
AfxMessageBox("You cannot enter an empty string!!!");
return;
}
CDialog::OnOK();
}
//####################################################################################################
void CDogProps::OnPaint() 
{
CPaintDC dc(this); // device context for painting
Textura(this,dc,IDB_MOROZ);
}
//####################################################################################################
