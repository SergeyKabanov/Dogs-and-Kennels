// kennel.cpp : Implementation of Ckennel
#include "stdafx.h"
#include "DOGS_INNER.h"
#include "kennel.h"
#include "dog.h"
#include "standard.h"
TCHAR DebugString[300];
/////////////////////////////////////////////////////////////////////////////
// Ckennel
class CDogStruct : public CObject
{
public:
Idog* p_Idog;
};
typedef CTypedPtrArray<CObArray,CDogStruct*> CDogStructArray;
//.............................................................................
int ArrayCounter=0;
CDogStructArray m_DogStructArray;
CString CurrentBreed;
CString CurrentName;
CString CurrentHairColor;
Idog* p_GlobalIdog;
int GlobalIndex;
//................................................................................................
STDMETHODIMP Ckennel::Save(BSTR bstrFilename)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())

// TODO: Add your implementation code here
CString KennelFileName;
CString BreedToWrite;
CString NameToWrite;
CString HairToWrite;
BSTR WideString;
int i;
FILE *OurFile;
//.................................................................................................
// TODO: Add your implementation code here
// Convert BSTR to String:
KennelFileName=MakeStringFromWide(bstrFilename);
//.................................................................................................
OurFile=fopen(KennelFileName,"w"); 
for(i=0;i<m_DogStructArray.GetSize();i++)
   {
   m_DogStructArray.GetAt(i)->p_Idog->get_Breed(&WideString);
   BreedToWrite=MakeStringFromWide(WideString);
   m_DogStructArray.GetAt(i)->p_Idog->get_Name(&WideString);
   NameToWrite=MakeStringFromWide(WideString);
   m_DogStructArray.GetAt(i)->p_Idog->get_HairColor(&WideString);
   HairToWrite=MakeStringFromWide(WideString);
   fprintf(OurFile,"%s,%s,%s\n",BreedToWrite,NameToWrite,HairToWrite);
   }
fclose(OurFile);

return S_OK;
}
//################################################################################################
STDMETHODIMP Ckennel::Load(BSTR bstrFilename)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())
CString KennelFileName;
int i;
FILE *OurFile;
TCHAR LocalString[256];
char divider[]=",";
char *token;
HRESULT hr;
IUnknown* pUnknown;
Idog* p_Dog;
//.................................................................................................
USES_CONVERSION;
// TODO: Add your implementation code here
// Convert BSTR to String:
KennelFileName=MakeStringFromWide(bstrFilename);
//.................................................................................................
OurFile=fopen(KennelFileName,"r"); 
if(OurFile==NULL)
  {
  AfxMessageBox("The Kennel File does not exist!!!");
  return S_OK; //S_FAILURE?
  }
else
   {
   while(fgets(LocalString,sizeof(LocalString),OurFile) != NULL)
        {
        for(i=0;i<sizeof(LocalString);i++) 
        if((LocalString[i]==012) || (LocalString[i]==015)) LocalString[i]=NULL;
        hr=CoCreateInstance(CLSID_dog,NULL,CLSCTX_INPROC_SERVER,IID_IUnknown,(void**)&pUnknown);
        if(FAILED(hr)) AfxMessageBox("Cannot create Dog object!!!");
        hr=pUnknown->QueryInterface(IID_Idog,(void**)&p_Dog);
        CDogStruct* p_DogStruct = new CDogStruct;
        p_DogStruct->p_Idog=p_Dog; // we collect interface pointers
        token=strtok(LocalString,divider);
        p_Dog->put_Breed(A2BSTR(token));
        token=strtok(NULL,divider);
        p_Dog->put_Name(A2BSTR(token));
        token=strtok(NULL,divider);
        p_Dog->put_HairColor(A2BSTR(token));
        m_DogStructArray.Add(p_DogStruct);
        }
   }
fclose(OurFile);
ArrayCounter=m_DogStructArray.GetSize();
return S_OK;
}
//#################################################################################################
STDMETHODIMP Ckennel::GetCount(LONG *nNumDogs)
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())
// TODO: Add your implementation code here
*nNumDogs=(long)ArrayCounter;
return S_OK;
}
//#################################################################################################
STDMETHODIMP Ckennel::GetAt(LONG nIndex, Idog **pDog)
{
//................................................................................................
AFX_MANAGE_STATE(AfxGetStaticModuleState())
//.................................................................................................
if(m_DogStructArray.GetSize()<(int)nIndex)
  {
  AfxMessageBox("We have lost our array!!!");
  return S_OK; 
  }
//...............................................................................................
*pDog=m_DogStructArray.GetAt((int)nIndex)->p_Idog;
return S_OK;
}
//##################################################################################################
Ckennel::~Ckennel()
{
//AfxMessageBox("Kennel Deleted");
}
//##################################################################################################
