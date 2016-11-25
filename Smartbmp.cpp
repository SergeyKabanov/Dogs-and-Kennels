//...........................................................................................
#include "stdafx.h"
//#include "repetit.ext"
#include "Dibapi.h"
#include "Smartbmp.h"
//..................................................................................
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//####################################################################################
// "Интеллектуальный" Bitmap:
//#######################################################################################
//IMPLEMENT_SERIAL(CSmartBitmap,CBitmap,0)
// construction/destruction
CSmartBitmap::CSmartBitmap(LPCTSTR FileString) // получаем непосредственно из file
{
LPSTR lpDIB;
//...........................................................................
IsPalette=TRUE;
CFile dibFile(FileString,CFile::modeRead);
h_dib=::ReadDIBFile(dibFile);
if(!h_dib)
	{
    AfxMessageBox("Ошибка чтения BITMAP из file !!!");
	return;
	}
//..............................................................................
// Получение палитры:
palette = new CPalette;
if(palette==NULL)
	{
    h_dib=NULL;
	AfxMessageBox("Не хватает памяти для создания палитры BITMAP'a!");
	}
//											AfxMessageBox("1");
if(h_dib != NULL)
{
if(::CreateDIBPalette(h_dib,palette)==NULL)
  {
//  AfxMessageBox("Нельзя создать палитру из DIB'a! : CSmartBitmap::CSmartBitmap(LPCTSTR FileString)");
  IsPalette=FALSE;
  }
}
else IsPalette=FALSE;
//...............................................................................
// Получаем размеры картинки:
//											AfxMessageBox("2");
lpDIB=(LPSTR)::GlobalLock((HGLOBAL)h_dib);
dxBitmap=(int)::DIBWidth(lpDIB);
dyBitmap=(int)::DIBHeight(lpDIB);
::GlobalUnlock((HGLOBAL)h_dib);
//::GlobalFree((HGLOBAL)h_dib);
}
//###############################################################################################
CSmartBitmap::CSmartBitmap(UINT nIDS)  // получение из ресурса:
{
LPSTR lpDIB;
BITMAP bm;
//...........................................................................
// Получаем "HDIB" из ресурса:
h_bitmap=LoadResourceBitmap(AfxGetInstanceHandle(),(LPCTSTR)MAKEINTRESOURCE(nIDS),&h_palette);
if(h_bitmap==NULL)
  {
/*
  h_palette=NULL;
  h_bitmap=::LoadBitmap(AfxGetInstanceHandle(),(LPCTSTR)MAKEINTRESOURCE(nIDS));
  if(h_bitmap==NULL) 
*/
  AfxMessageBox("h_bitmap==NULL!!!!!");
  AfxAbort(); // выходим аварийно!!!
  }
h_dib=(HDIB)DibFromBitmap(h_bitmap,BI_RGB,0,h_palette);
//..............................................................................

// Получение палитры:
palette = new CPalette;
if(palette==NULL)
	{
    ::GlobalFree((HGLOBAL)h_dib);
    h_dib=NULL;
	AfxMessageBox("Не хватает памяти для создания палитры BITMAP'a!");
	}
//											AfxMessageBox("1");
if(h_dib != NULL)
{
if(::CreateDIBPalette(h_dib,palette)==NULL)
  {
  IsPalette=FALSE;
//  AfxMessageBox("Нельзя создать палитру из DIB'a! : CSmartBitmap::CSmartBitmap(UINT nIDS)");
  }
}
else IsPalette=FALSE;
//palette->FromHandle(h_palette);
//...............................................................................
// Получаем размеры картинки:
//											AfxMessageBox("2");
if(h_dib != NULL)
   {
   lpDIB=(LPSTR)::GlobalLock((HGLOBAL)h_dib);
   //						sprintf(DebugString,"lpDIB=%s",lpDIB);
   //						AfxMessageBox(DebugString);
   dxBitmap=(int)::DIBWidth(lpDIB);
   dyBitmap=(int)::DIBHeight(lpDIB);
   ::GlobalUnlock((HGLOBAL)h_dib);
   //::GlobalFree((HGLOBAL)h_dib);
   }
else
   {
   ::GetObject(h_bitmap,sizeof(bm),(LPSTR)&bm);
   dxBitmap=bm.bmWidth;
   dyBitmap=bm.bmHeight;
   }
}
//############################################################################
CSmartBitmap::~CSmartBitmap()
{
delete palette;
if(h_bitmap!= NULL) ::DeleteObject(h_bitmap);
if(h_palette!= NULL) ::DeleteObject(h_palette);
if(h_dib != NULL) ::GlobalFree((HGLOBAL)h_dib);
h_dib=NULL;
}
//############################################################################
// рисование обычной картинки - 16 цветов:     
void CSmartBitmap::DrawPictureFast(CPaintDC& dc,int i,int j)
{
HDC DC,MemDC;
BITMAP bm;
HBITMAP hBmpOld;
//......................................................................
DC=dc.m_hDC;
//...................................................................................
MemDC=::CreateCompatibleDC(DC);
::GetObject(h_bitmap,sizeof(bm),(LPSTR)&bm);
hBmpOld=(HBITMAP)::SelectObject(MemDC,h_bitmap);
::BitBlt(DC,i,j,dxBitmap,dyBitmap,MemDC,0,0,SRCCOPY);
::SelectObject(MemDC,hBmpOld);
::DeleteObject(hBmpOld);
::DeleteDC(MemDC);
}
//###########################################################################
// Рисование картинки из 256 цветов (cо сжатием) :
void CSmartBitmap::DrawPictureSlow(CPaintDC& DC,int i,int j)
{
CRect outputRect,DIBRect;
RECT MaxRect;
//...........................................................................
DC.GetWindow()->GetClientRect(&MaxRect);
DIBRect.left=0;
DIBRect.top=0;
DIBRect.right=dxBitmap;
DIBRect.bottom=dyBitmap;
outputRect.left=i;
outputRect.top=j;
outputRect.right=i+dxBitmap;
outputRect.bottom=j+dyBitmap;
if(outputRect.right>MaxRect.right) outputRect.right=MaxRect.right;
if(outputRect.bottom>MaxRect.bottom) outputRect.bottom=MaxRect.bottom;
if(IsPalette==TRUE)
  {
  DC.SelectPalette(palette,FALSE);
  DC.RealizePalette();
  }
  if(::PaintDIB(DC.m_hDC,&outputRect,h_dib,&DIBRect,palette,SRCCOPY)==NULL)
  AfxMessageBox("Нельзя нарисовать DIB !!!");
}
//###########################################################################
// Рисование картинки из 256 цветов (cо сжатием и растяжением, на все окно) :
void CSmartBitmap::DrawPictureSlowWithStretch(CPaintDC& DC)
{
CRect outputRect,DIBRect;
RECT MaxRect;
//...........................................................................
DC.GetWindow()->GetClientRect(&MaxRect);
DIBRect.left=0;
DIBRect.top=0;
DIBRect.right=dxBitmap;
DIBRect.bottom=dyBitmap;
outputRect.left=0;
outputRect.top=0;
outputRect.right=MaxRect.right;
outputRect.bottom=MaxRect.bottom;
if(IsPalette==TRUE)
  {
  DC.SelectPalette(palette,FALSE);
  DC.RealizePalette();
  }
  if(::PaintDIB(DC.m_hDC,&outputRect,h_dib,&DIBRect,palette,SRCCOPY)==NULL)
  AfxMessageBox("Нельзя нарисовать DIB !!!");
}
//###########################################################################
// Рисование картинки из 256 цветов (без сжатия):
void CSmartBitmap::DrawPictureSlowWithoutStretch(CPaintDC& DC,int i,int j)
{
CRect outputRect,DIBRect;
RECT MaxRect;
//...........................................................................
DC.GetWindow()->GetClientRect(&MaxRect);
DIBRect.left=0;
DIBRect.top=0;
DIBRect.right=dxBitmap;
DIBRect.bottom=dyBitmap;
outputRect.left=i;
outputRect.top=j;
outputRect.right=i+dxBitmap;
outputRect.bottom=j+dyBitmap;
if(IsPalette==TRUE)
  {
  DC.SelectPalette(palette,FALSE);
  DC.RealizePalette();
  }
  if(::PaintDIB(DC.m_hDC,&outputRect,h_dib,&DIBRect,palette,SRCCOPY)==NULL)
  AfxMessageBox("Нельзя нарисовать DIB !!!");
}
//###########################################################################
/*
// рисование маски - 16 цветов:
void CSmartBitmap::DrawMask(CPaintDC& dc,int i,int j)
{
HDC DC,MemDC;
BITMAP bm;
HBITMAP hBmpOld;
//......................................................................
DC=dc.m_hDC;
//...................................................................................
MemDC=::CreateCompatibleDC(DC);
::GetObject(h_bitmap,sizeof(bm),(LPSTR)&bm);
hBmpOld=(HBITMAP)::SelectObject(MemDC,h_bitmap);
::BitBlt(DC,i,j,dxBitmap,dyBitmap,MemDC,0,0,SRCAND);
::SelectObject(MemDC,hBmpOld);
::DeleteObject(hBmpOld);
::DeleteDC(MemDC);
}
*/
//###########################################################################
// Рисование маски для sprite(без сжатия):
void CSmartBitmap::DrawMask(CPaintDC& DC,int i,int j)
{
CRect outputRect,DIBRect;
RECT MaxRect;
//...........................................................................
DC.GetWindow()->GetClientRect(&MaxRect);
DIBRect.left=0;
DIBRect.top=0;
DIBRect.right=dxBitmap;
DIBRect.bottom=dyBitmap;
outputRect.left=i;
outputRect.top=j;
outputRect.right=i+dxBitmap;
outputRect.bottom=j+dyBitmap;
if(IsPalette==TRUE)
  {
  DC.SelectPalette(palette,FALSE);
  DC.RealizePalette();
  }
  if(::PaintDIB(DC.m_hDC,&outputRect,h_dib,&DIBRect,palette,SRCAND)==NULL)
  AfxMessageBox("Нельзя нарисовать маску !!!");
}
//###########################################################################
// Наложение маски на sprite(без сжатия):
void CSmartBitmap::DrawSpriteOverMask(CPaintDC& DC,int i,int j)
{
CRect outputRect,DIBRect;
RECT MaxRect;
//...........................................................................
DC.GetWindow()->GetClientRect(&MaxRect);
DIBRect.left=0;
DIBRect.top=0;
DIBRect.right=dxBitmap;
DIBRect.bottom=dyBitmap;
outputRect.left=i;
outputRect.top=j;
outputRect.right=i+dxBitmap;
outputRect.bottom=j+dyBitmap;
if(IsPalette==TRUE)
  {
  DC.SelectPalette(palette,FALSE);
  DC.RealizePalette();
  }
  if(::PaintDIB(DC.m_hDC,&outputRect,h_dib,&DIBRect,palette,SRCPAINT)==NULL)
  AfxMessageBox("Нельзя нарисовать sprite поверх маски !!!");
}
//#########################################################################################
// Загрузка картинки с палитрой:
HBITMAP CSmartBitmap::LoadResourceBitmap(HINSTANCE hInstance, LPCTSTR lpString, HPALETTE FAR* lphPalette)
{
    HRSRC  hRsrc;
    HGLOBAL hGlobal, hTemp;
    DWORD dwSize;
    HBITMAP hBitmapFinal = NULL;
    LPBITMAPINFOHEADER  lpbi;
    LPSTR lpRes, lpNew;
    HDC hdc;
    int iNumColors;
//	BYTE* ppvBits;
//........................................................................................ 
    hRsrc = FindResource((HMODULE)hInstance, (LPCTSTR)lpString, RT_BITMAP);
	if(hRsrc != NULL)
    {
       hTemp = LoadResource(hInstance, hRsrc);
       dwSize = SizeofResource(hInstance, hRsrc);
       lpRes = (LPSTR)LockResource(hTemp);
 
       hGlobal = GlobalAlloc(GHND, dwSize);
       lpNew = (LPSTR)GlobalLock(hGlobal);
       memcpy(lpNew, lpRes, dwSize);
       UnlockResource(hTemp);
       FreeResource(hTemp);
 
       lpbi = (LPBITMAPINFOHEADER)lpNew;
//if(lpbi==NULL) AfxMessageBox("lpbi==NULL"); 
       hdc = ::GetDC(NULL);
       *lphPalette =  CreateOurDIBPalette((LPBITMAPINFO)lpbi, &iNumColors);
       if (*lphPalette)
       {
		   ::SelectPalette(hdc,*lphPalette,FALSE);
		   ::RealizePalette(hdc);
       }
//       else AfxMessageBox("*lphPalette==NULL"); 
 /*
       hBitmapFinal = CreateDIBSection(hdc,
                 (BITMAPINFO*)lpbi,
                 DIB_RGB_COLORS,
                 (VOID**)ppvBits,
                 NULL,0);
 */
	   hBitmapFinal = ::CreateDIBitmap(hdc,
                 (LPBITMAPINFOHEADER)lpbi,
                 (LONG)CBM_INIT,
                 (LPSTR)lpbi + lpbi->biSize + iNumColors * sizeof(RGBQUAD),
                 (LPBITMAPINFO)lpbi,
                 DIB_RGB_COLORS );
//if(hBitmapFinal==NULL) AfxMessageBox("hBitmapFinal==NULL");
//						sprintf(DebugString,"hBitmapFinal=%d",hBitmapFinal);
//						AfxMessageBox(DebugString);
    	::ReleaseDC(NULL,hdc);
       GlobalUnlock(hGlobal);
       GlobalFree(hGlobal);
    }
return (hBitmapFinal);
}
//##################################################################################
HPALETTE CSmartBitmap::CreateOurDIBPalette (LPBITMAPINFO lpbmi, LPINT lpiNumColors)
{
   LPBITMAPINFOHEADER  lpbi;
   LPLOGPALETTE     lpPal;
   HANDLE           hLogPal;
   HPALETTE hPal;
   int i;
//................................................................................. 
   hPal=NULL;
   lpbi = (LPBITMAPINFOHEADER)lpbmi;
   if (lpbi->biBitCount <= 8)
       *lpiNumColors = (1 << lpbi->biBitCount);
   else
       *lpiNumColors = 0;  // No palette needed for 24 BPP DIB
 
   if (*lpiNumColors)
      {
      hLogPal = GlobalAlloc (GHND, sizeof (LOGPALETTE) +
                             sizeof (PALETTEENTRY) * (*lpiNumColors));
      lpPal = (LPLOGPALETTE) GlobalLock (hLogPal);
      lpPal->palVersion    = 0x300;
      lpPal->palNumEntries = (USHORT)*lpiNumColors;
 
      for (i = 0;  i < *lpiNumColors;  i++)
         {
         lpPal->palPalEntry[i].peRed   = lpbmi->bmiColors[i].rgbRed;
         lpPal->palPalEntry[i].peGreen = lpbmi->bmiColors[i].rgbGreen;
         lpPal->palPalEntry[i].peBlue  = lpbmi->bmiColors[i].rgbBlue;
         lpPal->palPalEntry[i].peFlags = 0;
         }
      hPal = CreatePalette (lpPal);
      GlobalUnlock (hLogPal);
      GlobalFree   (hLogPal);
   }
   return hPal;
}
//##################################################################################### 
// *                                                                          *
// *  FUNCTION   : DibFromBitmap()                                            *
// *                                                                          *
// *  PURPOSE    : Will create a global memory block in DIB format that       *
// *               represents the Device-dependent bitmap (DDB) passed in.    *
// *                                                                          *
// *  RETURNS    : A handle to the DIB                                        *
// *                                                                          *
// ****************************************************************************/
HANDLE CSmartBitmap::DibFromBitmap(HBITMAP hbm, DWORD biStyle, WORD biBits, HPALETTE hpal)
{
    BITMAP               bm;
    BITMAPINFOHEADER     bi;
    BITMAPINFOHEADER FAR *lpbi;
    DWORD                dwLen;
    HANDLE               hdib;
    HANDLE               h;
    HDC                  hdc;
//..........................................................................................
    if (!hbm)
        {
        AfxMessageBox("hbm==0");
        return NULL;
        }

    if (hpal == NULL)
        hpal = (HPALETTE)::GetStockObject(DEFAULT_PALETTE);

    ::GetObject(hbm,sizeof(bm),(LPSTR)&bm);

    if (biBits == 0)
    biBits =  (WORD)(bm.bmPlanes * bm.bmBitsPixel);

    bi.biSize               = sizeof(BITMAPINFOHEADER);
    bi.biWidth              = bm.bmWidth;
    bi.biHeight             = bm.bmHeight;
    bi.biPlanes             = 1;
    bi.biBitCount           = biBits;
    bi.biCompression        = biStyle;
    bi.biSizeImage          = 0;
    bi.biXPelsPerMeter      = 0;
    bi.biYPelsPerMeter      = 0;
    bi.biClrUsed            = 0;
    bi.biClrImportant       = 0;

    dwLen  = bi.biSize + PaletteSize(&bi);

    hdc = ::GetDC(NULL);
    hpal = ::SelectPalette(hdc,hpal,FALSE);
	::RealizePalette(hdc);

    hdib = GlobalAlloc(GHND,dwLen);

    if (!hdib){
        ::SelectPalette(hdc,hpal,FALSE);
        ::ReleaseDC(NULL,hdc);
        AfxMessageBox("!hdib");
        return NULL;
    }

    lpbi = (BITMAPINFOHEADER FAR *)GlobalLock(hdib);

    *lpbi = bi;

    /*  call GetDIBits with a NULL lpBits param, so it will calculate the
     *  biSizeImage field for us
     */
    ::GetDIBits(hdc, hbm, 0L, (DWORD)bi.biHeight,
        (LPBYTE)NULL, (LPBITMAPINFO)lpbi, (DWORD)DIB_RGB_COLORS);

    bi = *lpbi;
    GlobalUnlock(hdib);

    /* If the driver did not fill in the biSizeImage field, make one up */
    if (bi.biSizeImage == 0){
        bi.biSizeImage = WIDTHBYTES((DWORD)bm.bmWidth * biBits) * bm.bmHeight;

        if (biStyle != BI_RGB)
            bi.biSizeImage = (bi.biSizeImage * 3) / 2;
    }

    /*  realloc the buffer big enough to hold all the bits */
    dwLen = bi.biSize + PaletteSize(&bi) + bi.biSizeImage;
    h = GlobalReAlloc(hdib,dwLen,0);
if(h != 0) hdib = h;
    else{
        GlobalFree(hdib);
        hdib = NULL;
        AfxMessageBox("return hdib");
		::SelectPalette(hdc,hpal,FALSE);
        ReleaseDC(NULL,hdc);
        return hdib;
        }

    /*  call GetDIBits with a NON-NULL lpBits param, and actualy get the
     *  bits this time
     */
    lpbi = (BITMAPINFOHEADER FAR *)GlobalLock(hdib);

    if (::GetDIBits( hdc,
                   hbm,
                   0L,
                   (DWORD)bi.biHeight,
                   (LPBYTE)lpbi + (WORD)lpbi->biSize + PaletteSize(lpbi),
                   (LPBITMAPINFO)lpbi, (DWORD)DIB_RGB_COLORS) == 0){
         GlobalUnlock(hdib);
         hdib = NULL;
         ::SelectPalette(hdc,hpal,FALSE);
         ::ReleaseDC(NULL,hdc);
         AfxMessageBox("GetDIBits==0");
         return NULL;
    }

    bi = *lpbi;
    GlobalUnlock(hdib);
//                                                    GlobalFree(hdib);
    ::SelectPalette(hdc,hpal,FALSE);
    ::ReleaseDC(NULL,hdc);
    return hdib;
}
//#############################################################################################
// *                                                                          *
// *  FUNCTION   :  PaletteSize(VOID FAR * pv)                                *
// *                                                                          *
// *  PURPOSE    :  Calculates the palette size in bytes. If the info. block  *
// *                is of the BITMAPCOREHEADER type, the number of colors is  *
// *                multiplied by 3 to give the palette size, otherwise the   *
// *                number of colors is multiplied by 4.                                                          *
// *                                                                          *
// *  RETURNS    :  Palette size in number of bytes.                          *
// *                                                                          *
// ****************************************************************************/
WORD CSmartBitmap::PaletteSize (VOID FAR * pv)
{
LPBITMAPINFOHEADER lpbi;
WORD NumColors;
//......................................................................
    lpbi      = (LPBITMAPINFOHEADER)pv;
    NumColors = DibNumColors(lpbi);

    if (lpbi->biSize == sizeof(BITMAPCOREHEADER))
        return (WORD)(NumColors * sizeof(RGBTRIPLE));
    else
        return (WORD)(NumColors * sizeof(RGBQUAD));
}
//##############################################################################
// *                                                                          *
// *  FUNCTION   : DibNumColors(VOID FAR * pv)                                *
// *                                                                          *
// *  PURPOSE    : Determines the number of colors in the DIB by looking at   *
// *               the BitCount filed in the info block.                      *
// *                                                                          *
// *  RETURNS    : The number of colors in the DIB.                           *
// *                                                                          *
// ****************************************************************************/
WORD CSmartBitmap::DibNumColors (VOID FAR * pv)
{
    INT                 bits;
    LPBITMAPINFOHEADER  lpbi;
    LPBITMAPCOREHEADER  lpbc;
//................................................................................
    lpbi = ((LPBITMAPINFOHEADER)pv);
    lpbc = ((LPBITMAPCOREHEADER)pv);

    /*  With the BITMAPINFO format headers, the size of the palette
     *  is in biClrUsed, whereas in the BITMAPCORE - style headers, it
     *  is dependent on the bits per pixel ( = 2 raised to the power of
     *  bits/pixel).
     */
    if (lpbi->biSize != sizeof(BITMAPCOREHEADER)){
        if (lpbi->biClrUsed != 0)
            return (WORD)lpbi->biClrUsed;
        bits = lpbi->biBitCount;
    }
    else
        bits = lpbc->bcBitCount;

    switch (bits){
        case 1:
                return 2;
        case 4:
                return 16;
        case 8:
                return 256;
        default:
                /* A 24 bitcount DIB has no color table */
                return 0;
    }
}
//###########################################################################
