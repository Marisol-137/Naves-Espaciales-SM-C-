#include<conio.h>
#include<iostream>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle (STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	
	SetConsoleCursorPosition(hCon, dwPos);
}

void OcultarCursor(){
	HANDLE hCon;
	hCon = GetStdHandle (STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cur;
	cur.dwSize = 2;
	cur.bVisible = FALSE;
	
	SetConsoleCursorInfo(hCon, &cur);
}

void pintar_limites(){
	for(int i=2 ; i<78 ; i++){
		gotoxy(i,3); cout<<"\315";
		gotoxy(i,33); cout<<"\315";
	}
	
	for(int i=4 ; i<33 ; i++){
		gotoxy(2,i); cout<<"\272";
		gotoxy(77,i); cout<<"\272";
	}
	
	gotoxy(2,3); cout<<"\311";
	gotoxy(2,33); cout<<"\310";
	gotoxy(77,3); cout<<"\273";
	gotoxy(77,33); cout<<"\274";
}

class NAVE{
	int x, y;
	int corazones;
public:
	NAVE(int _x, int _y, int _corazones);
	void pintar();
	void borrar();
	void mover();
	void pintar_corazones();
};

NAVE::NAVE(int _x, int _y, int _corazones){
	x = _x;
	y = _y;
	corazones = _corazones; 
}

void NAVE::pintar(){
	gotoxy(x,y); cout<<"  \36";
	gotoxy(x,y+1); cout<<" (\317)";
	gotoxy(x,y+2); cout<<"\36\276 \276\36";
}

void NAVE::borrar(){
	gotoxy(x,y); cout<<"     ";
	gotoxy(x,y+1); cout<<"     ";
	gotoxy(x,y+2); cout<<"     ";
}

void NAVE::mover(){
	if(kbhit()){
    		char tecla = getch();
    		borrar();
    		if(tecla == 'a' && x>3) x--;
    		if(tecla == 'd' && x+6<77) x++;
    		if(tecla == 'w' && y>4) y--;
    		if(tecla == 's' && y+3<33) y++;
    		gotoxy(x, y);
    	    pintar();
    	    pintar_corazones();
		}
}

void NAVE::pintar_corazones(){
	gotoxy(64,2); cout<<"Salud";
	gotoxy(70,2); cout<<"      ";
	for(int i=0 ; i< corazones ; i++){
		
		gotoxy(70+i,2); cout<<"\3";
	}
}

int main (){
	
    OcultarCursor();
    pintar_limites();
    NAVE N(7,7,3);
    N.pintar();
    N.pintar_corazones();
    
    bool game_over = false;
    while(!game_over){
    	
    	
    	N.mover();
    	Sleep (30);
	}
	
	
}
