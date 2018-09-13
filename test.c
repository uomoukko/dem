#include <windows.h>

HINSTANCE ist;

BOOL CALLBACK procedura(
 HWND pdialogo,
 UINT messaggio,
 WPARAM wp,
 LPARAM lp)
{
if(messaggio==WM_INITDIALOG)
	{
 	MessageBox(0,"INIT","A friendly warning",MB_ICONINFORMATION| MB_OK); 
	return TRUE;
	}
if(messaggio==WM_PAINT)
	{
	PAINTSTRUCT strutpaint;
	//HDC miodc,memdc;
	MessageBox(0,"PAINT","A friendly warning",MB_ICONINFORMATION| MB_OK); 
	//miodc=
	BeginPaint(pdialogo,&strutpaint);
	EndPaint(pdialogo,&strutpaint);
	return TRUE;
	}
if(messaggio==3232+WM_CLOSE)
	{
	EndDialog(pdialogo, 0);
	return TRUE;
	}
return FALSE; 
}

int APIENTRY WinMain(
 HINSTANCE istanzacur,
 HINSTANCE istanzapre,
 LPSTR     lineacom,
 int       numerocom)
{
ist=istanzacur;

if((FindWindow(0,"TEST"))!=NULL)
	{
	MessageBox(0,"Program is already running","A friendly warning",MB_ICONINFORMATION| MB_OK);
	return(2);
	}
MessageBox(0,"Program is running","A friendly warning",MB_ICONINFORMATION| MB_OK);
DialogBoxParam(0,MAKEINTRESOURCE(324),0,procedura,0);
MessageBox(0,"Program ends","A friendly warning",MB_ICONINFORMATION| MB_OK);
return 0;
}
