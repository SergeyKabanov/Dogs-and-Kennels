// dog.h : Declaration of the Cdog

#ifndef __DOG_H_
#define __DOG_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Cdog
//long g_cComponents=0;
//...............................................................................................
class ATL_NO_VTABLE Cdog : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<Cdog, &CLSID_dog>,
	public IDispatchImpl<Idog, &IID_Idog, &LIBID_DOGS_INNERLib>
{
public:

	Cdog() 
	{
	}        
~Cdog()
{
//AfxMessageBox("Dog Deleted");
}

DECLARE_REGISTRY_RESOURCEID(IDR_DOG)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(Cdog)
	COM_INTERFACE_ENTRY(Idog)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// Idog
public:

CString CurrentBreed;
CString CurrentName;
CString CurrentHairColor;

	STDMETHOD(get_HairColor)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_HairColor)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Name)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Name)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_Breed)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Breed)(/*[in]*/ BSTR newVal);
	STDMETHOD(Sleep)(/*[in]*/ LONG nTime);
	STDMETHOD(Bark)(/*[in]*/ LONG nTime);
	STDMETHOD(Run)();
private:
ULONG m_cRef;
};

#endif //__DOG_H_
