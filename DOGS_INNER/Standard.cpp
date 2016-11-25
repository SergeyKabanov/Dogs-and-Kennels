#include "stdafx.h"
//#include "afximpl.h"
#include "standard.h"
//#include "DOGS_INNER.h"
//#include "DOGS_INNER_i.c"
//#include "dog.h"
//########################################################################################################################
CString MakeStringFromWide(wchar_t* widestr) 
{
AFX_MANAGE_STATE(AfxGetStaticModuleState())
CString RezultString;
char* Rezult;         
long l_ptrname = (wcslen(widestr) + 1) * 2 * sizeof(TCHAR); 
Rezult=(char*)malloc(l_ptrname);
WideCharToMultiByte(CP_ACP,0,widestr,-1,Rezult,l_ptrname,NULL,NULL); 
RezultString=Rezult;
free(Rezult);
return RezultString;
}
//########################################################################################################################
