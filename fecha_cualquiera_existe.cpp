#include<iostream>
#include<conio.h>

using namespace std;

main ()
{
	int d,m,a;
	cout<<"Programa que determina si una fecha existe o no"<<endl;	
	cout<<"Ingresa el anio: ";
	cin>>a;
	cout<<"Ingresa el mes: ";
	cin>>m;
	cout<<"Ingresa el dia: ";
	cin>>d;
	
	if(a>=1)
	{
		cout<<"\nExiste el anio";
		if (a%4==0)
		{
			if(m>=1 && m<=12)
			{
				cout<<"\nExiste el mes";
				switch(m)
				{
				case 1:; case 3:; case 5:; case 7:; case 8:; case 10:; case 12:
					if(d>=1&&d<=31) 
					{
						cout<<"\nExiste el dia";cout<<"\nEXISTE LA FECHA";	
					}
					else
					{
						cout<<"\nNo existe el dia";cout<<"\nNO EXISTE LA FECHA";
					}
					break;	
				case 2: 
					if(d>=1&&d<=29) 
					{
						cout<<"\nExiste el dia";cout<<"\nEXISTE LA FECHA";	
					}
					else
					{
						cout<<"\nNo existe el dia";cout<<"\nNO EXISTE LA FECHA";
					}	
					break;
		
				case 4:; case 6:; case 9:; case 11:
					if(d>=1&&d<=30) 
					{
						cout<<"\nExiste el dia";cout<<"\nEXISTE LA FECHA";	
					}
					else
					{
						cout<<"\nNo existe el dia";cout<<"\nNO EXISTE LA FECHA";
					}	
					break;
				default:;
				}	
			}
			else
			{
				cout<<"\nNo existe el mes";cout<<"\nNO EXISTE LA FECHA";
			}
		
		}
		else 
		{
			if(m>=1 && m<=12)
			{
				cout<<"\nExiste el mes";
				switch(m)
				{
				case 1:; case 3:; case 5:; case 7:; case 8:; case 10:; case 12:
					if(d>=1&&d<=31) 
					{
						cout<<"\nExiste el dia";cout<<"\nEXISTE LA FECHA";	
					}
					else
					{
						cout<<"\nNo existe el dia";cout<<"\nNO EXISTE LA FECHA";
					}
					break;	
				case 2: 
					if(d>=1&&d<=28) 
					{
						cout<<"\nExiste el dia";cout<<"\nEXISTE LA FECHA";	
					}
					else
					{
						cout<<"\nNo existe el dia";cout<<"\nNO EXISTE LA FECHA";
					}	
					break;
		
				case 4:; case 6:; case 9:; case 11:
					if(d>=1&&d<=30) 
					{
						cout<<"\nExiste el dia";cout<<"\nEXISTE LA FECHA";	
					}
					else
					{
						cout<<"\nNo existe el dia";cout<<"\nNO EXISTE LA FECHA";
					}	
					break;
				default:;
				}	
			}
			else
			{
				cout<<"\nNo existe el mes";cout<<"\nNO EXISTE LA FECHA";
			}

		}
	}
	
	else
		cout<<"\nNO EXISTE LA FECHA";
	
}