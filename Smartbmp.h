//#ifdef __SMARTBMP__
//#define __SMARTBMP__
// "Интеллектуальный" Bitmap:
//########################################################################
class CSmartBitmap : public CBitmap
{
//DECLARE_SERIAL(CSmartBitmap)
public:
CSmartBitmap(LPCTSTR FileString);
CSmartBitmap(UINT nIDS);
~CSmartBitmap();

private:
HDIB h_dib;
HPALETTE h_palette;
CPalette* palette;
HBITMAP LoadResourceBitmap(HINSTANCE hInstance, LPCTSTR lpString,HPALETTE FAR* lphPalette);
HPALETTE CreateOurDIBPalette(LPBITMAPINFO lpbmi, LPINT lpiNumColors);
HANDLE DibFromBitmap(HBITMAP hbm, DWORD biStyle, WORD biBits, HPALETTE hpal);
WORD PaletteSize(VOID FAR * pv);
WORD DibNumColors (VOID FAR * pv);
BOOL IsPalette; //а есть ли вообще палитра в данной ситуации?

public:
int dxBitmap,dyBitmap; //размеры картинки
HBITMAP h_bitmap;

// Функции:
public:
void DrawPictureFast(CPaintDC& DC, int i, int j);
void DrawPictureSlow(CPaintDC& DC, int i, int j);
void DrawPictureSlowWithoutStretch(CPaintDC& DC,int i,int j);
// Рисование картинки из 256 цветов (cо сжатием и растяжением, на все окно) :
void DrawPictureSlowWithStretch(CPaintDC& DC);
// Рисование маски для sprite(без сжатия):
void DrawMask(CPaintDC& DC,int i,int j);
// Наложение маски на sprite(без сжатия):
void DrawSpriteOverMask(CPaintDC& DC,int i,int j);
};
//########################################################################
//#endif //__SMARTBMP__
