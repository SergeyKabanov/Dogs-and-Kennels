// dog.cpp : Implementation of Cdog
#include "stdafx.h"
#include "DOGS_INNER.h"
#include "dog.h"
#include "standard.h"
/////////////////////////////////////////////////////////////////////////////
//......................................................
class CDogStruct : public CObject
{
public:
Idog* p_Idog;
};
typedef CTypedPtrArray<CObArray,CDogStruct*> CDogStructArray;
//.............................................................................
extern CDogStructArray m_DogStructArray;
extern int GlobalIndex;
//################################################################################################
// Cdog
//#################################################################################################
STDMETHODIMP Cdog::Run()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here

	return S_OK;
}
//###############################################################################################
STDMETHODIMP Cdog::Bark(LONG nTime)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here

	return S_OK;
}
//###############################################################################################
STDMETHODIMP Cdog::Sleep(LONG nTime)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here

	return S_OK;
}
//##################################################################################################
STDMETHODIMP Cdog::get_Breed(BSTR *pVal)
{
char* buf;
BSTR NameToGet;
//.................................................................................................
AFX_MANAGE_STATE(AfxGetStaticModuleState())
USES_CONVERSION;
buf=CurrentBreed.GetBuffer(CurrentBreed.GetLength());
NameToGet=A2BSTR(buf);
*pVal=NameToGet;
CurrentBreed.ReleaseBuffer();
return S_OK;
}
//###############################################################################################
STDMETHODIMP Cdog::put_Breed(BSTR newVal)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())
// TODO: Add your implementation code here
CurrentBreed=MakeStringFromWide(newVal); 
return S_OK;
}
//##################################################################################################
STDMETHODIMP Cdog::get_Name(BSTR *pVal)
{
char* buf;
BSTR NameToGet;
//.................................................................................................
AFX_MANAGE_STATE(AfxGetStaticModuleState())
USES_CONVERSION;
buf=CurrentName.GetBuffer(CurrentName.GetLength());
NameToGet=A2BSTR(buf);
*pVal=NameToGet;
CurrentName.ReleaseBuffer();
return S_OK;
}
//###################################################################################################
STDMETHODIMP Cdog::put_Name(BSTR newVal)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())
// TODO: Add your implementation code here
CurrentName=MakeStringFromWide(newVal); 
return S_OK;
}
//###################################################################################################
STDMETHODIMP Cdog::get_HairColor(BSTR *pVal)
{
char* buf;
BSTR NameToGet;
//.................................................................................................
AFX_MANAGE_STATE(AfxGetStaticModuleState())
USES_CONVERSION;
buf=CurrentHairColor.GetBuffer(CurrentHairColor.GetLength());
NameToGet=A2BSTR(buf);
*pVal=NameToGet;
CurrentHairColor.ReleaseBuffer();
return S_OK;
}
//####################################################################################################
STDMETHODIMP Cdog::put_HairColor(BSTR newVal)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())
// TODO: Add your implementation code here
CurrentHairColor=MakeStringFromWide(newVal); 
return S_OK;
}
//####################################################################################################
