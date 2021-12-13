#include<stdio.h>
#include<iostream>
#include<windows.h> //permite dar una posicion al cursor
#include<conio.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hCon;
	
	hCon=GetStdHandle(STD_OUTPUT_HANDLE); //recupera el identificador de la consola
	
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	
	SetConsoleCursorPosition(hCon, dwPos);	
}

void OcultarCursor()
{
	HANDLE hCon;
	
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_CURSOR_INFO cci;
	
	cci.dwSize=1;//disminuir el grosor del cursor
	
	cci.bVisible=FALSE; //hace que desaparezca el cursor
	
	SetConsoleCursorInfo(hCon,&cci);
	
}

class NAVE
{ 
	int x,y; //son atributos privados
public:
	NAVE(int _x,int _y):x(_x),y(_y){} //CONSTRUCTOR
	void pintar();
	void borrar();
	void mover();	
};


void NAVE::pintar()
{
	gotoxy(x,y);
	cout<<"    %c";
	gotoxy(x,y+1);
	cout<<"  %c%c%c",40,207,41;
	gotoxy(x,y+2);
	cout<<"%c%c%c%c%c",30,190,190,30;
}

void NAVE::borrar()
{
	gotoxy(x,y);
	cout<<"                 ";
	gotoxy(x,y+1);
	cout<<"                 ";
	gotoxy(x,y+2);
	cout<<"                 ";
		
}

void NAVE::mover()
{
	if(kbhit())                //detecta si se ha presionado una tecla
	{
		char tecla =getch();
		borrar();
		if(tecla==IZQUIERDA)
			x--;
		if(tecla==DERECHA)
			x++;
		if(tecla==ARRIBA)
			y--;         //sube
		if(tecla==ABAJO)
			y++;
		pintar();
		
	}
}



int main()
{
	OcultarCursor();
	
	NAVE N(7,7);
	N.pintar();
 
	bool game_over=false;
	
	while(!game_over)
	{
	
		N.mover();
		Sleep(30);
		
	}
	
	
}






