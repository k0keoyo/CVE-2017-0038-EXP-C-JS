#include<stdio.h>
#include<Windows.h>


int main()
{
	BYTE *pBit = (BYTE *)malloc(16*16*4);//alloca byte array
	BITMAPINFO bi;
	HDC hedc;
	HENHMETAFILE  hemf;
	HBITMAP hbmp = NULL;
	BITMAP bmp;
	int ret;
	int result;
	DWORD color[16];
	RECT rect = {0, 0, 100, 100};
	bi.bmiHeader.biSize = 0x28;
	bi.bmiHeader.biWidth = 0x10;    
	bi.bmiHeader.biHeight = 0x10;    
	bi.bmiHeader.biPlanes = 1;    
	bi.bmiHeader.biBitCount = 0x18;     
	bi.bmiHeader.biCompression = BI_RGB;     
	bi.bmiHeader.biSizeImage = 16*16*4;   
	bi.bmiHeader.biClrUsed = 0;    
	bi.bmiHeader.biClrImportant = 0;
	hedc = GetDC(NULL);
	hemf = GetEnhMetaFile(L"poc1.emf");//get hemf
	//hbmp = CreateCompatibleBitmap(hedc,rect.right,rect.bottom);
	//GetObject(hbmp,sizeof(BITMAP),(LPSTR)&bmp);
	ret = PlayEnhMetaFile(hedc,hemf,&rect);
	for(result=0;result<8;result++)
	{
		color[result]=GetPixel(hedc,0,result);
	}
	//hbmp = (HBITMAP)SelectObject(hedc,hemf);
	//result = GetDIBits(hedc, hbmp, 0, 0x50, pBit, &bi, DIB_RGB_COLORS);
	return 0;
	//SelectObj(hedc,hemf);

}