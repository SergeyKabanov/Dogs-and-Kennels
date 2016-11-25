//#ifdef __SMARTBMP__
//#define __SMARTBMP__
// "����������������" Bitmap:
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
BOOL IsPalette; //� ���� �� ������ ������� � ������ ��������?

public:
int dxBitmap,dyBitmap; //������� ��������
HBITMAP h_bitmap;

// �������:
public:
void DrawPictureFast(CPaintDC& DC, int i, int j);
void DrawPictureSlow(CPaintDC& DC, int i, int j);
void DrawPictureSlowWithoutStretch(CPaintDC& DC,int i,int j);
// ��������� �������� �� 256 ������ (c� ������� � �����������, �� ��� ����) :
void DrawPictureSlowWithStretch(CPaintDC& DC);
// ��������� ����� ��� sprite(��� ������):
void DrawMask(CPaintDC& DC,int i,int j);
// ��������� ����� �� sprite(��� ������):
void DrawSpriteOverMask(CPaintDC& DC,int i,int j);
};
//########################################################################
//#endif //__SMARTBMP__
