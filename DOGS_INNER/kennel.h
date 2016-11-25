// kennel.h : Declaration of the Ckennel

#ifndef __KENNEL_H_
#define __KENNEL_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Ckennel
class ATL_NO_VTABLE Ckennel : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<Ckennel, &CLSID_kennel>,
	public IDispatchImpl<Ikennel, &IID_Ikennel, &LIBID_DOGS_INNERLib>
{
public:
	Ckennel()
	{
	}

~Ckennel();

DECLARE_REGISTRY_RESOURCEID(IDR_KENNEL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(Ckennel)
	COM_INTERFACE_ENTRY(Ikennel)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// Ikennel
public:
	STDMETHOD(GetAt)(/*[in]*/ LONG nIndex, /*[out,retval]*/ Idog **pDog);
	STDMETHOD(GetCount)(/*[out,retval]*/ LONG *nNumDogs);
	STDMETHOD(Load)(/*[in]*/ BSTR bstrFilename);
	STDMETHOD(Save)(/*[in]*/ BSTR bstrFilename);
};

#endif //__KENNEL_H_
