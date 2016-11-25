#include "stdafx.h"
//#include "afximpl.h"
#include "dibapi.h"
#include "smartbmp.h"
#include "standard.h"
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
//###########################################################################
void Textura(CWnd* wndToPaint,CPaintDC& dc, UINT nRes)
{
CSmartBitmap* TexturaBitmap;
RECT OurRect;
int xWay,yWay;
//..........................................................................
TexturaBitmap=new CSmartBitmap(nRes);
wndToPaint->GetClientRect(&OurRect);
xWay=0;
yWay=0;
//...........................................................................
do{
     do{
       TexturaBitmap->DrawPictureSlowWithoutStretch(dc,xWay,yWay);
//       TexturaBitmap->DrawPictureFast(dc,xWay,yWay);
       xWay=xWay+TexturaBitmap->dxBitmap-1;
       }while(xWay<=OurRect.right);
xWay=0;
yWay=yWay+TexturaBitmap->dyBitmap-1;
}while(yWay<=OurRect.bottom);
//...........................................................................
delete TexturaBitmap;
}
//######################################################################################
void Textura(CWnd* wndToPaint,CPaintDC& dc, CString BitmapToPaint)
{
CSmartBitmap* TexturaBitmap;
RECT OurRect;
int xWay,yWay;
//..........................................................................
TexturaBitmap=new CSmartBitmap((LPCTSTR)BitmapToPaint);
wndToPaint->GetClientRect(&OurRect);
xWay=0;
yWay=0;
//...........................................................................
do{
     do{
       TexturaBitmap->DrawPictureSlowWithoutStretch(dc,xWay,yWay);
//       TexturaBitmap->DrawPictureFast(dc,xWay,yWay);
       xWay=xWay+TexturaBitmap->dxBitmap-1;
       }while(xWay<=OurRect.right);
xWay=0;
yWay=yWay+TexturaBitmap->dyBitmap-1;
}while(yWay<=OurRect.bottom);
//...........................................................................
delete TexturaBitmap;
}
//######################################################################################
