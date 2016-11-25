// DOGS_OUTERDlg.cpp : implementation file
//
#include "stdafx.h"
#include "DOGS_OUTER.h"
#include "DOGS_OUTERDlg.h"
#include "DlgProxy.h"
#include "dibapi.h"
#include "smartbmp.h"
#include "standard.h"
#include "dogprops.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//...............................................................................................
#import "DOGS_INNER.tlb" 
using namespace DOGS_INNERLib;
const IID IID_Ikennel = {0xF77A0781,0x369E,0x11D5,{0xAE,0xA3,0x00,0xA0,0xD2,0x16,0x26,0x38}};
const CLSID CLSID_kennel = {0xF77A0782,0x369E,0x11D5,{0xAE,0xA3,0x00,0xA0,0xD2,0x16,0x26,0x38}};
//...............................................................................................
class CDogStruct : public CObject
{
public:
Idog* p_Idog;
};
typedef CTypedPtrArray<CObArray,CDogStruct*> CDogStructArray;
//.............................................................................
CDogStructArray m_DogStructArray;
//...............................................................................................
TCHAR DebugString[300];
long DogsCounter=0L;
CString NameToShow;
CString BreedToShow;
CString HairToShow;
CString KennelFileName;
Ikennel* p_Kennel;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDOGS_OUTERDlg dialog

IMPLEMENT_DYNAMIC(CDOGS_OUTERDlg, CDialog);

CDOGS_OUTERDlg::CDOGS_OUTERDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDOGS_OUTERDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDOGS_OUTERDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
if(!buttonOK.LoadBitmaps(IDB_OK_UP,IDB_OK_DN))
	{
	TRACE0("Failed to load bitmaps for buttons\n");
	AfxThrowResourceException();
	}
}

CDOGS_OUTERDlg::~CDOGS_OUTERDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CDOGS_OUTERDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDOGS_OUTERDlg)
	DDX_Control(pDX, IDC_DOGS_LIST, m_DogsList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDOGS_OUTERDlg, CDialog)
	//{{AFX_MSG_MAP(CDOGS_OUTERDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_LBN_DBLCLK(IDC_DOGS_LIST, OnDblclkDogsList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDOGS_OUTERDlg message handlers
//#################################################################################################
BOOL CDOGS_OUTERDlg::OnInitDialog()
{
int i;
CString ExePath;
CString DogName;
char* namebuf;
FILE *OurFile;
BSTR WideDogName;
HRESULT hr;
IUnknown* pUnknown;
Idog* p_Dog1;
//................................................................................................
CDialog::OnInitDialog();
//..................................................................................
VERIFY(buttonOK.SubclassDlgItem(IDOK, this));
buttonOK.SizeToContent();
//..................................................................................	
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
//................................................................................................	
// TODO: Add extra initialization here
ExePath=((CDOGS_OUTERApp*)AfxGetApp())->GetAppPathName();
KennelFileName.Format("%s\\kennel.txt",ExePath);
OurFile=fopen(KennelFileName,"r");
if(OurFile==NULL)
  {
  AfxMessageBox("We cannot open the Kennel file!!!");
  return FALSE;
  }
//.................................................................................................
AFX_MANAGE_STATE(AfxGetStaticModuleState());
CoInitialize(NULL);
hr=CoCreateInstance(CLSID_kennel,NULL,CLSCTX_INPROC_SERVER,IID_IUnknown,(void**)&pUnknown);
if(FAILED(hr)) AfxMessageBox("Cannot create Kennel object!!!");
hr=pUnknown->QueryInterface(IID_Ikennel,(void**)&p_Kennel);

namebuf=KennelFileName.GetBuffer(KennelFileName.GetLength());
MAKE_WIDEPTR_FROMTSTR(KennelFile,namebuf);    
p_Kennel->Load(KennelFile);
KennelFileName.ReleaseBuffer();
while(DogsCounter==0L) DogsCounter=p_Kennel->GetCount(); // wait until we fill the array of dogs on COM side...
                 //sprintf(DebugString,"DogsCounter=%ld", DogsCounter);
                 //AfxMessageBox(DebugString);    
for(i=0;i<DogsCounter;i++)
   {
   p_Dog1=p_Kennel->GetAt((long)i);
   WideDogName=p_Dog1->GetName();              
   DogName=MakeStringFromWide(WideDogName); 
//AfxMessageBox(DogName);    
//p_Dog->PutHairColor(WideDogName);
   m_DogsList.AddString(DogName);
   CDogStruct* p_DogStruct = new CDogStruct;
   p_DogStruct->p_Idog=p_Dog1; // we collect interface pointers
   m_DogStructArray.Add(p_DogStruct);
   }
//................................................................................................
return TRUE;  // return TRUE  unless you set the focus to a control
}
//################################################################################################
void CDOGS_OUTERDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
//###############################################################################################
void CDOGS_OUTERDlg::OnPaint() 
{
	if (IsIconic())
	{
	CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
	CPaintDC dc(this); // device context for painting
    Textura(this,dc,IDB_BLUEMRAM);
	CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDOGS_OUTERDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CDOGS_OUTERDlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}
//###############################################################################################
void CDOGS_OUTERDlg::OnOK() 
{
int i;
char* namebuf;
//...............................................................................................
//AFX_MANAGE_STATE(AfxGetStaticModuleState());
namebuf=KennelFileName.GetBuffer(KennelFileName.GetLength());
MAKE_WIDEPTR_FROMTSTR(KennelFile,namebuf);    
p_Kennel->Save(KennelFile);
KennelFileName.ReleaseBuffer();
//................................................................................................
for(i=0;i<m_DogStructArray.GetSize();i++)
delete m_DogStructArray[i];
m_DogStructArray.RemoveAll();
//.................................................................................................
p_Kennel->Release();
CoUninitialize();
//................................................................................................
if(CanExit()) CDialog::OnOK();
}
//###############################################################################################
void CDOGS_OUTERDlg::OnCancel() 
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CDOGS_OUTERDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}
//#################################################################################
void CDOGS_OUTERDlg::OnDblclkDogsList() 
{
BSTR WideDogProperty;
char* namebuf;
Idog* p_Dog1;
//................................................................................................
// TODO: Add your control notification handler code here
//AFX_MANAGE_STATE(AfxGetStaticModuleState());
   p_Dog1=m_DogStructArray.GetAt(m_DogsList.GetCurSel())->p_Idog;  
   WideDogProperty=p_Dog1->GetName();              
   NameToShow=MakeStringFromWide(WideDogProperty);
//AfxMessageBox(NameToShow); 
   WideDogProperty=p_Dog1->GetBreed();              
   BreedToShow=MakeStringFromWide(WideDogProperty); 
   WideDogProperty=p_Dog1->GetHairColor();              
   HairToShow=MakeStringFromWide(WideDogProperty); 
//................................................................................................
CDogProps dlg;
if(dlg.DoModal()==IDOK)
  {
  namebuf=HairToShow.GetBuffer(HairToShow.GetLength());
  MAKE_WIDEPTR_FROMTSTR(HairWide,namebuf);    
  p_Dog1->PutHairColor(HairWide);
  HairToShow.ReleaseBuffer();
  }	
//...............................................................................................
}
//#################################################################################################
