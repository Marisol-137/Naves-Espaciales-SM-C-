#include<conio.h>
#include<iostream>
#include<windows.h>

#define IZQUIERDA 75
#define DERECHA 77

char avion_l1[]={' ',' ',' ', '*',' ',' ',' ',0};
char avion_l2[]={' ',' ','*', '*','*',' ',' ',0};
char avion_l3[]={' ','*','*', '*','*','*',' ',0};

char explosion_l1[]={' ',' ','*','*',' ',' ',' ',0};
char explosion_l2[]={' ','*','*','*','*',' ',' ',0};
char explosion_l3[]={' ',' ','*','*',' ',' ',' ',0};

char explosion_r1[]={'*',' ','*','*',' ','*',' ',0};
char explosion_r2[]={' ','*','*','*','*',' ',' ',0};
char explosion_r3[]={'*',' ','*','*',' ','*',' ',0};

char borrar_avion[]={' ',' ',' ',' ',' ',' ',' ',0};

int Num_vidas = 3;
int Corazones = 3;
int ix = 45;
int iy = 19;

int y = 8 , x = 12; 
int yy = 12 , xx = 17;
int x1 = 58 , y1 = 6;
int x2 = 70 , y2 = 9;

int i,v;

int repeticion = 0 , nivel = 1;
bool condicion = false;

void gotoxy(int x , int y)
{
	HANDLE hCon;
	COORD dwPos;
	
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
	
}

void vidas(int vi)
{
	gotoxy(2,1); printf("VIDAS %d",vi);
	
}

void Barra_salud(int n)
{
	gotoxy(91,1); printf(" ");
	gotoxy(92,1); printf(" ");
	gotoxy(93,1); printf(" ");
	
	for(v = 0 ; v < n ; v++)
	{
		gotoxy(91+v,1);
		printf("%c",3);
	}
}

void Explocion(void)
{
	gotoxy(ix,iy); puts(explosion_l1);
	gotoxy(ix,iy+1); puts(explosion_l2);
	gotoxy(ix,iy+2); puts(explosion_l3);
	
	Sleep(380);
	
	gotoxy(ix,iy); puts(explosion_r1);
	gotoxy(ix,iy+1); puts(explosion_r2);
	gotoxy(ix,iy+2); puts(explosion_r3);
	
	Sleep(380);
	
	gotoxy(ix,iy); puts(avion_l1);
	gotoxy(ix,iy+1); puts(avion_l2);
	gotoxy(ix,iy+2); puts(avion_l3);
}

void jugar(void)
{
	
	gotoxy(x,y);   printf("%c",42);
	gotoxy(xx,yy); printf("%c",42);
	gotoxy(x1,y1); printf("%c",42);
	gotoxy(x2,y2); printf("%c",42);
	
	Sleep(70);
	
	gotoxy(x,y);   printf(" ");
	gotoxy(xx,yy); printf(" ");
	gotoxy(x1,y1); printf(" ");
	gotoxy(x2,y2); printf(" ");
	
	if (y > 20)
	{
		y = 4;
		x = (rand() % 70) +6;
	}
	if (yy > 20)
	{
		yy = 4;
		xx = (rand() % 70) +6;
	}
	if (y1 > 20)
	{
		y1 = 4;
		x1 = (rand() % 70) +6;
	}
	if (y2 > 20)
	{
		y2 = 4;
		x2 = (rand() % 70) +6;
	}
	
	
	if(kbhit())
	{
		unsigned char tecla = getch();
		switch (tecla)
		{
			case IZQUIERDA:
				if( ix > 4)
				{
					gotoxy(ix,iy); puts(borrar_avion);
					gotoxy(ix,iy+1); puts(borrar_avion);
					gotoxy(ix,iy+2); puts(borrar_avion);
					
					ix -=2;
					
					gotoxy(ix,iy); puts(avion_l1);
					gotoxy(ix,iy+1); puts(avion_l2);
					gotoxy(ix,iy+2); puts(avion_l3);
					
				}
				break;
				
			case DERECHA:
				if( ix <90)
				{
					gotoxy(ix,iy); puts(borrar_avion);
					gotoxy(ix,iy+1); puts(borrar_avion);
					gotoxy(ix,iy+2); puts(borrar_avion);
					
					ix +=2;
					
					gotoxy(ix,iy); puts(avion_l1);
					gotoxy(ix,iy+1); puts(avion_l2);
					gotoxy(ix,iy+2); puts(avion_l3);
				}
				break;
		}
	}
	
	// Choque con las estrellas
	
	if( (x > ix && x < ix + 6 && y == iy-1) || ( xx > ix && xx < ix + 6 && yy == iy-1)
	|| ( x1 > ix && x1 < ix + 6 && y1 == iy-1) || ( x2 > ix && x2 < ix + 6 && y2 == iy-1) )
	{
		Corazones --;
		Barra_salud(Corazones);
		printf("\a");
		
	}
	
	gotoxy(ix,iy); puts(avion_l1);
	gotoxy(ix,iy+1); puts(avion_l2);
	gotoxy(ix,iy+2); puts(avion_l3);
	
	if(!Corazones)
	{
		Num_vidas--;
		vidas(Num_vidas) ;
		Explocion();
		Corazones = 3;
		
		Barra_salud(Corazones);
		
	}
	
	y++;
	yy++;
	y1++;
	y2++;
	
}

int main()
{
	vidas(Num_vidas);
	Barra_salud(Corazones);
	
	gotoxy(ix,iy); puts(avion_l1);
	gotoxy(ix,iy+1); puts(avion_l2);
	gotoxy(ix,iy+2); puts(avion_l3);
	
	while(Num_vidas > 0)

		jugar();
	
	getch();
	return 0;
}
