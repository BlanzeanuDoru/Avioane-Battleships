using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "airplane.h"

class board
{
	private:
		P* heads;;
		int nr;
		int height;
		int width;
		int **a;
		char name[20];	
	public:
	
	  	 board(int height=10,int width=10);
	  	 //~board();
	void setShip(avion &a1);
	void retShip(avion &a1);
	void setName(char *name);
	P * getHeads();
	bool cond(avion &a1,int x);
	bool exists(avion &a1);
	void printA(int b);
	int** getA();
	char* getName();

		
};

/*board::~board()
{
	free(this->a);
	free(this->heads);
}*/

P * board::getHeads()
{
	return this->heads;
}

int ** board::getA()
{
	return this->a;
}

bool board::exists(avion &a1)
{
	P* points = a1.getPoints();
	
	for(int i=0;i<8;i++)
	  {
	  	if(a[points[i].x][points[i].y]==1)
	  	 return false;
	  }
	  return true;
}

bool board::cond(avion &a1,int x)
{
	P* points = a1.getPoints();
	
	    if(points[0].x > points[5].x) //cu capul in jos XXX
	    {
	    	if(x==1) //daca se poate muta la stanga
	 	  {
	 	  	if(points[6].y-1<0 || a[points[0].x][points[0].y-1]==1 || a[points[3].x][points[3].y-1]==1 || a[points[6].x][points[6].y-1]==1)
	 	  	  return false;
	 	  }
	 	if(x==2) //daca se poate muta in jos
	 	  {
	 	  	if(points[0].x+1>=this->height || a[points[0].x+1][points[0].y]==1 || a[points[1].x+1][points[1].y]==1 || a[points[3].x+1][points[3].y]==1 || a[points[6].x+1][points[6].y]==1 || a[points[7].x+1][points[7].y]==1)
	 	  	  return false;
	 	  }
	 	if(x==3) //daca se poate muta la dreapta
	 	  {
	 	  	if(points[7].y+1>=this->width || a[points[0].x][points[0].y+1]==1 || a[points[1].x][points[1].y+1]==1 || a[points[7].x][points[7].y+1]==1)
	 	  	  return false;
	 	  }
	 	if(x==4) //daca se poate muta in sus
	 	  {
	 	  	if(points[5].x-1<0 || a[points[1].x-1][points[1].y]==1 || a[points[3].x-1][points[3].y]==1 || a[points[5].x-1][points[5].y]==1 || a[points[6].x-1][points[6].y]==1 || a[points[7].x-1][points[7].y]==1)
	 	  	  return false;
	 	  }
	    }
		else if(points[0].x < points[5].x) //cu capul in sus XXX
	    {
	    	if(x==1) //daca se poate muta la stanga
	 	  {
	 	  	if(points[7].y-1 < 0 || a[points[0].x][points[0].y-1]==1 || a[points[1].x][points[1].y-1]==1 || a[points[7].x][points[7].y-1]==1)
	 	  	  return false;
	 	  }
	 	if(x==2) //daca se poate muta in jos
	 	  {
	 	  	if( points[5].x+1>=this->height || a[points[5].x+1][points[5].y]==1 || a[points[1].x+1][points[1].y]==1 || a[points[3].x+1][points[3].y]==1 || a[points[6].x+1][points[6].y]==1 || a[points[7].x+1][points[7].y]==1)
	 	  	  return false;
	 	  }
	 	if(x==3) //daca se poate muta la dreapta
	 	  {
	 	  	if(points[6].y+1>=this->width || a[points[0].x][points[0].y+1]==1 || a[points[3].x][points[3].y+1]==1 || a[points[6].x][points[6].y+1]==1)
	 	  	  return false;
	 	  }
	 	if(x==4) //daca se poate muta in sus
	 	  {
	 	  	if(points[0].x-1<0 || a[points[0].x-1][points[0].y]==1 || a[points[1].x-1][points[1].y]==1 || a[points[3].x-1][points[3].y]==1 || a[points[6].x-1][points[6].y]==1 || a[points[7].x-1][points[7].y]==1)
	 	  	  return false;
	 	  }
	    }
	    else if(points[0].y < points[5].y) //cu capul la stanga XXX
	    {
	    	if(x==1) //daca se poate muta la stanga
	 	  {
	 	  	if(points[0].y-1<0 || a[points[0].x][points[0].y-1]==1 || a[points[1].x][points[1].y-1]==1 || a[points[3].x][points[3].y-1]==1 || a[points[6].x][points[6].y-1]==1 || a[points[7].x][points[7].y-1]==1)
	 	  	  return false;
	 	  }
	 	if(x==2) //daca se poate muta in jos
	 	  {
	 	  	if(points[1].x+1>=height || a[points[0].x+1][points[0].y]==1 || a[points[1].x+1][points[1].y]==1 || a[points[7].x+1][points[7].y]==1 )
	 	  	  return false;
	 	  }
	 	if(x==3) //daca se poate muta la dreapta
	 	  {
	 	  	if(points[5].y+1 >= width || a[points[5].x][points[5].y+1]==1 || a[points[1].x][points[1].y+1]==1 || a[points[3].x][points[3].y+1]==1 || a[points[7].x][points[6].y+1]==1 || a[points[7].x][points[7].y+1]==1)
	 	  	  return false;
	 	  }
	 	if(x==4) //daca se poate muta in sus
	 	  {
	 	  	if(points[3].x-1 < 0 || points[0].x-1<0 || a[points[0].x-1][points[0].y]==1 || a[points[3].x-1][points[3].y]==1 || a[points[6].x-1][points[6].y]==1)
	 	  	  return false;
	 	  }
	    }else //cu capul la dreapta
	    {
	    	if(x==1) //daca se poate muta la stanga
	 	  {
	 	  	if(points[5].y-1<0 || a[points[1].x][points[1].y-1]==1 || a[points[5].x][points[5].y-1]==1 || a[points[3].x][points[3].y-1]==1 || a[points[6].x][points[6].y-1]==1 || a[points[7].x][points[7].y-1]==1)
	 	  	  return false;
	 	  }
	 	if(x==2) //daca se poate muta in jos
	 	  {
	 	  	if(points[3].x+1>=this->height || a[points[0].x+1][points[0].y]==1 || a[points[3].x+1][points[3].y]==1 || a[points[6].x+1][points[6].y]==1)
	 	  	  return false;
	 	  }
	 	if(x==3) //daca se poate muta la dreapta
	 	  {
	 	  	if(points[0].y+1>=this->width || a[points[0].x][points[0].y+1]==1 || a[points[1].x][points[1].y+1]==1 || a[points[3].x][points[3].y+1]==1 || a[points[6].x][points[6].y+1]==1 || a[points[7].x][points[7].y+1]==1)
	 	  	  return false;
	 	  }
	 	if(x==4) //daca se poate muta in sus
	 	  {
	 	  	if(points[1].x-1<0 || a[points[0].x-1][points[0].y]==1 || a[points[1].x-1][points[1].y]==1 || a[points[7].x-1][points[7].y]==1)
	 	  	  return false;
	 	  }
	    }
	
        
	 return true;
}

void board::retShip(avion &a1)
{
	P* points = a1.getPoints();
	for(int i=0;i<8;i++)
	   a[points[i].x][points[i].y]=0;
}


char * board::getName()
{
	return this->name;
}


void board::setName(char *name)
{
	strcpy(this->name,name);
}

void board::printA(int b)
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		 {
		 	if(b==1)
		 	printf("%d",a[i][j]);
		 	else printf("0");
		 }
		 printf("\n");
	}
}

//constructorul tablei de avioane
board::board(int height, int width)
{
	this->heads = (P*)malloc(3*sizeof(P));
	this->nr=0;
	this->height=height;
	this->width=width;
	a=(int**)malloc(height*sizeof(int*));
	for(int i=0;i<height;i++) a[i]=(int*)calloc(width,sizeof(int));
}

//metoda care adauga avioan pe tabla
void board::setShip(avion &a1)
{
	
	P punct;
	P *points = a1.getPoints();
    punct.x=points[0].x;
	punct.y=points[0].y;
	
	this->heads[nr++] = punct;
	
	for(int i=0;i<8;i++)
	 {
	 	a[points[i].x][points[i].y]=1;
	 }
}
