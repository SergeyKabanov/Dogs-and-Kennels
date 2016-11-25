// DOGS_INNER.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f DOGS_INNERps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "DOGS_INNER.h"

#include "DOGS_INNER_i.c"
#include "dog.h"
#include "kennel.h"
#include "standard.h"
//......................................................
class CDogStruct : public CObject
{
public:
Idog* p_Idog;
};
typedef CTypedPtrArray<CObArray,CDogStruct*> CDogStructArray;
//.............................................................................
extern CDogStructArray m_DogStructArray;

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)                 
OBJECT_ENTRY(CLSID_dog, Cdog)
OBJECT_ENTRY(CLSID_kennel, Ckennel)              
END_OBJECT_MAP()

class CDOGS_INNERApp : public CWinApp
{
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDOGS_INNERApp)
	public:
    virtual BOOL InitInstance();
    virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CDOGS_INNERApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CDOGS_INNERApp, CWinApp)
	//{{AFX_MSG_MAP(CDOGS_INNERApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CDOGS_INNERApp theApp;
//###################################################################
BOOL CDOGS_INNERApp::InitInstance()
{
HRESULT hr;
//.................................................................................................
_Module.Init(ObjectMap, m_hInstance, &LIBID_DOGS_INNERLib);
hr=CoInitialize(NULL);
if(FAILED(hr)) AfxMessageBox("Cannot CoInitialize()");
return CWinApp::InitInstance();
}
//##################################################################
int CDOGS_INNERApp::ExitInstance()
{
int i;
//.................................................................................................
for(i=0;i<m_DogStructArray.GetSize();i++)
   {
   m_DogStructArray.GetAt(i)->p_Idog->Release();
   delete m_DogStructArray[i];
   }
m_DogStructArray.RemoveAll();
//.................................................................................................
CoUninitialize();
_Module.Term();
return CWinApp::ExitInstance();
}
//################################################################################################
/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return (AfxDllCanUnloadNow()==S_OK && _Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    return _Module.UnregisterServer(TRUE);
}


