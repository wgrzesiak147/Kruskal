#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <conio.h>

using namespace std;



struct krawedzie {
	int x;
	int y;
	int waga;
	bool wybrane;
};

struct kolory{
int kolor;
};




int main() {
cout<<"liczbea wierzcholkow : ";
int liczba_wierzcholkow;
int x,y;
int stopien_wypelnienia;
float ile_krawedzi;
cin>>liczba_wierzcholkow;
cout<<"stopien wypelnienia : ";
cin>>stopien_wypelnienia;
ile_krawedzi=(stopien_wypelnienia*0.01) * ((((liczba_wierzcholkow)*(liczba_wierzcholkow))-(liczba_wierzcholkow))/2);
int tablica[liczba_wierzcholkow][liczba_wierzcholkow];
x=ile_krawedzi;
y=liczba_wierzcholkow;
int tablica_krawedzi[x];
srand (time(NULL));

///////////////////////////////////////////////////////////////////////////////////////  warunek

	if(ile_krawedzi<(liczba_wierzcholkow-1)) // Sprawdzam poprawna ilosc krawedzi
		{
		cout<<" Za male wypelnienie!!!! "<<endl;
		system("PAUSE");
		}
		else

{

////////////////////////////////////////////////////////////////////////////////////// wypelnienie 0

for (int i=0;i<liczba_wierzcholkow;i++)
{
for (int j=0;j<liczba_wierzcholkow;j++)
{
tablica[i][j]=0;
}
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////Diagonala



for (int i=0;i<liczba_wierzcholkow;i++)  // w diagonali ustalam znak specjalny
	{
	tablica[i][i]=-1;

		
	}
	
///////////////////////////////////////////////////////////////////////////////////////Tablica krawedzi



for (int i=0;i<x;i++)
{
	tablica_krawedzi[i]=i+1;
}



//////////////////////////////////////////////////////////////////////////////////////losowanie i wype³nianie

		for (int i=0;i<x;i++)
		
		{
			int e= rand() %y+0;
			int u= rand() %y+0;
			if(tablica[u][e] == 0)
			{
			tablica[u][e]=tablica_krawedzi[i];
			tablica[e][u]=tablica[u][e];
			}
			else
			{
			i--;
			}
		
		}


	
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	COUT
 
 
 
for (int i=0;i<liczba_wierzcholkow;i++)
	{
	for (int j=0;j<liczba_wierzcholkow;j++)
      {
      	cout<<tablica[j][i]<<" ";;
      }	
	cout <<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////KRUSKAL







int z=0;
krawedzie mst[y];

krawedzie tabkrawedzie[x];

kolory tabkolory[y];


for (int i=0;i<y;i++)
{
	tabkolory[i].kolor=i+1;
}

///////////////////////////////////// uzupelnienie tablicy struktur


for (int i=0;i<liczba_wierzcholkow;i++)
	{
	for (int j=0;j<liczba_wierzcholkow;j++)
      {
    if (tablica[j][i]==-1)
    {
    	break;
    }
   		 if (tablica[j][i] != 0)
  		 {
   
			tabkrawedzie[z].x=i+1;
      		tabkrawedzie[z].y=j+1;
      		tabkrawedzie[z].waga=tablica[j][i];
      		tabkrawedzie[z].wybrane=0;
      		z++;
 		 }
      }	
	}


///////////////////////////sortowanie po wadze Buble Sort dla wiêkszej efektywnosci mo¿na u¿yæ quick sorta


for (int i=0;i<x;i++)
	{
	for (int j=0;j<x;j++)
      {
      	if (tabkrawedzie[j].waga>tabkrawedzie[j+1].waga)
      	 swap(tabkrawedzie[j],tabkrawedzie[j+1]);
      
      }	
	}


////////////////////////////////////////////////////////UZUPELNIANIE MST

cout<<endl;

int g=0;


   
for (int i=0;i<x;i++)
{
	int wierzchol_x=(tabkrawedzie[i].x)-1;
	int wierzchol_y=(tabkrawedzie[i].y)-1;

		if (tabkolory[wierzchol_x].kolor != tabkolory[wierzchol_y].kolor)
		{
				
				
			mst[g]=tabkrawedzie[i];
			
			g++;
		
			for (int j=0;j<y;j++)
			{
	
			 if (tabkolory[j].kolor==tabkolory[wierzchol_x].kolor)
			 	{
			 		for (int b=0;b<y;b++)
						{
						//cout<<" ";
			 				tabkolory[j].kolor=tabkolory[wierzchol_y].kolor;
			 			}
			 																		
			 	}
			 	
			 	///////////////////////////////////////////////////  Dodatkowo proces farbowania mo¿na usun¹æ ¿eby nie spamowa³o pierdo³ami:D
				for (int i=0;i<y;i++)//przedstawia proces farbowania
				{
				cout<< tabkolory[i].kolor;
				}
				cout<<endl;
				////////////////////////////////////////////////////
	
			}
	
		}	
		
}


/////////////////////////////////////////////COUT

cout<<endl;
for (int i=0;i<y-1;i++)
{
	cout<<mst[i].x<<" "<<mst[i].y<<" "<<mst[i].waga<<endl;
}


cout<<endl;



///////////////////////////////////////////////////////////////////////////////////////////////////////////
main();
	return 0;
	system("PAUSE");
}
}
