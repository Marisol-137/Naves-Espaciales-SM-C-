//Nivel 3: 

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>


#define Arriba 72
#define Izquierda 75
#define Derecha 77
#define Abajo 80

using namespace std;

void cordenadas(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}

void ocultar_cursor(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 200;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cci);
}

void Limites(){
	for(int i=1; i<102; i++){
		cordenadas(0,3); cout<<"\311";
		cordenadas(i,3); cout<<"\315";
		cordenadas(i,43); cout<<"\315";
		cordenadas(102,3); cout<<"\273";
		
		}
	
	for(int i=4; i<43; i++){
		cordenadas(0,43); cout<<"\310";
		cordenadas(0,i); cout<<"\272";
		cordenadas(102,i); cout<<"\272";
		cordenadas(102,43); cout<<"\274";
	}
	}
	
	
	

class Nave{
	int x,y;
	int Combustible;
public:
	Nave(int xx, int yy, int C): x(xx),y(yy), Combustible(C){}
	void pintar();
	void borrar();
	void mover();
	void Barra_Combustible();
	void Explotar();
};

void Nave::pintar(){
	cordenadas(x,y); cout<<"           \334\334\334\334";
	cordenadas(x,y+1); cout<<"  \334\334      \333\333\333\333\333\333      \334\334";
	cordenadas(x,y+2); cout<<" \334\334\334\334    \333\333\333\333\333\333\333\333    \334\334\334\334";
	cordenadas(x,y+3); cout<<"  \333\333    \333\333  \334\334  \333\333    \333\333";
	cordenadas(x,y+4); cout<<"  \333\333   \333\333  \333\333\333\333  \333\333   \333\333";
	cordenadas(x,y+5); cout<<"  \333\333   \333\333  \333\333\333\333  \333\333   \333\333";
	cordenadas(x,y+6); cout<<"  \333\333    \333\333  \337\337  \333\333    \333\333";
	cordenadas(x,y+7); cout<<" \334\333\333\333\333\333\333\333\333\333\333\337\337\333\333\333\333\333\333\333\333\333\333\334";
	cordenadas(x,y+8); cout<<"\337\337\333\333\337\337  \337\337\333\333\376\376\333\333\337\337  \337\337\333\333\337\337";
	cordenadas(x,y+9); cout<<"  \334\334                  \334\334";
	cordenadas(x,y+10); cout<<" \333\333\333\333                \333\333\333\333";
	cordenadas(x,y+11); cout<<"  \333\333                  \333\333";
}

void Nave::borrar(){
	cordenadas(x,y);   cout<<"                          ";
	cordenadas(x,y+1); cout<<"                          ";
	cordenadas(x,y+2); cout<<"                          ";
	cordenadas(x,y+3); cout<<"                          ";
	cordenadas(x,y+4); cout<<"                          ";
	cordenadas(x,y+5); cout<<"                          ";
	cordenadas(x,y+6); cout<<"                          ";
	cordenadas(x,y+7); cout<<"                         ";
	cordenadas(x,y+8); cout<<"                          ";
	cordenadas(x,y+9); cout<<"                          ";
	cordenadas(x,y+10); cout<<"                          ";
	cordenadas(x,y+11); cout<<"                          ";
}

void Nave::mover(){
	if(kbhit()){
			char tecla = getch();
			borrar();
			if(tecla == Izquierda && x>2) x=x-3;
			if(tecla == Derecha && x<74) x=x+3;
			if(tecla == Arriba && y>4) y=y-3;
			if(tecla == Abajo && y<30) y=y+3;
			if(tecla == 'e') Combustible--;
			pintar();
			Barra_Combustible();
			
		}
}

void Nave::Barra_Combustible(){
	cordenadas(83,2); cout<<"Combustible";
	cordenadas(96,2); cout<<"\272     \272";
	for(int i=0; i<Combustible; i++){
		cordenadas(97+i, 2); cout<<"\333";
		
	}
}

void Nave::Explotar(){
	if(Combustible==0){
		borrar();
		cordenadas(x,y); cout<<"    \333\333";
		cordenadas(x,y+1); cout<<"       \333\333";
		cordenadas(x,y+2); cout<<"  \333\333";
		cordenadas(x,y+3); cout<<"    \333\333\333\333\333\333";
		cordenadas(x,y+4); cout<<" \333\333\333\333\333\333\333\333\333\333";
		cordenadas(x,y+5); cout<<"  \333\333\333\333\333\333\333\333\333\333\333   \333\333";
		cordenadas(x,y+6); cout<<"\333\333\333\333\333\333\333\333\333\333\333\333\333\333";
		cordenadas(x,y+7); cout<<"  \333\333\333\333\333\333\333\333\333\333\333";
		cordenadas(x,y+8); cout<<"     \333\333\333\333";
		cordenadas(x,y+9); cout<<"  \333\333";
		cordenadas(x,y+10); cout<<"       \333\333";
		cordenadas(x,y+11); cout<<"   \333\333     \333\333";
		Sleep(200);
		
		//borrar();
		//Sleep(200);
		getch();
		Combustible= 5;
		Barra_Combustible();
		pintar();
	}
} 

int main(){
	ocultar_cursor();
	Limites();
	Nave N(7,7,5);
	N.pintar();
	N.Barra_Combustible();
	
	
	bool game_over = false;
	
	while(!game_over){
		N.Explotar();
		N.mover();
		Sleep(30);
	}	
	
	return 0;
}
