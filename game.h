#include "board.h"
#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <time.h>
using namespace std;

void delay()
{
	Sleep(70);
	cout.flush();
}

void gotoxy(short y,short x ) 
{ 
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ; 
    COORD position = { x, y } ; 
     
    SetConsoleCursorPosition( hStdout, position ) ; 
}

void sterge(P* points,int width)
{
	for(int i=0;i<8;i++)
	     {
	     	gotoxy(points[i].x,points[i].y);
	     	if(points[i].y>=width)
	     	printf(" ");
	     	else
			printf("0");
	     }
}
void rescrie(P* points)
{
	for(int i=0;i<8;i++)
	     {
	     	gotoxy(points[i].x,points[i].y);
	     	printf("1");
	     }
}

class game
{
	private:
		board b1;
		board b2;
    public:
    	game(int height,int width);
    	//~game();
    	void preGame(int height,int width);  //setare nume,avioane
    	void startGame(int height,int width);
    	void endGame();
};

/*game::~game()
{
	this->b1.~board();
	this->b2.~board();
}*/

void game::startGame(int height,int width)
{
	system("cls");
	for(int i=65;i<65+width;i++)
	  printf("%c",i);
	printf("\n");
	b1.printA(0);
	for(int i=0;i<width;i++)
	{
		gotoxy(i+1,width+1);
		printf("%d",i+1);
	}
	printf("\n\n\n");
	for(int i=65;i<65+width;i++)
	  printf("%c",i);
	printf("\n");
	b2.printA(0);
	for(int i=13;i<width+13;i++)
	{
		gotoxy(i+1,width+1);
		printf("%d",i-12);
	}
	printf("\n");
	system("PAUSE");
	
	int x;
	int y;
	int **a;
	P* heads;
	int score1=0;
	int score2=0;
	
	printf("LEGENDA");
	gotoxy(27,12);
	printf("x-lovit  #-ratat");
	
	
	while(1)
	{
		gotoxy(3,22);
	    printf("%s:%d %s:%d",b1.getName(),score1,b2.getName(),score2);
	    gotoxy(4,22);
		fflush(stdin);
		gotoxy(5,15);
		printf("Randul lui %s.",b1.getName());
		gotoxy(6,15);
		printf("Introdu coordonatele punctului");
		for(int i=1;i<10;i++)
		 {
		 	printf(" ");
		 }
		 gotoxy(7,15);
		for(int i=1;i<10;i++)
		 {
		 	printf(" ");
		 }
		
		gotoxy(7,15);
		cout<<"x="; cin>>x;
		gotoxy(7,20);
		cout<<" y="; cin>>y;
		a=b2.getA();
		if(a[x-1][y-1]==1)
		{
		heads = this->b2.getHeads();
		for(int i=0;i<3;i++)
	      {
	      	if(heads[i].x==x-1 && heads[i].y==y-1)
	      	    {
	      	    	gotoxy(8,15);
		            printf("LOVIT CAP AVION");
		            gotoxy(13+x,y-1);
		            printf("*");
		            score1++;
		            break;
	      	    }
	      
	      if(i==2){
	      	        gotoxy(8,15);
		            printf("LOVIT          ");
		            gotoxy(13+x,y-1);
		            printf("x");
	      }
	      }
		
		}else{
			gotoxy(8,15);
		    printf("AI RATAT");
		    gotoxy(13+x,y-1);
		    printf("#");
		}
		gotoxy(3,22);
	    printf("%s:%d %s:%d",b1.getName(),score1,b2.getName(),score2);
		gotoxy(25,1);
		system("PAUSE");
		if(score1==3)
		{
		   gotoxy(30,25);
		   printf("OVER! %s a castigat!",b1.getName());
		   break;	
		}
		
		fflush(stdin);
		gotoxy(15,15);
		printf("Randul lui %s.",b2.getName());
		gotoxy(16,15);
		printf("Introdu coordonatele punctului");
		for(int i=1;i<10;i++)
		 {
		 	printf(" ");
		 }
		 gotoxy(17,15);
		for(int i=1;i<10;i++)
		 {
		 	printf(" ");
		 }
		
		gotoxy(17,15);
		cout<<"x="; cin>>x;
		gotoxy(17,20);
		cout<<" y="; cin>>y;
		a=b1.getA();
		
		if(a[x-1][y-1]==1)
		{
		heads = this->b1.getHeads();
		for(int i=0;i<3;i++)
	      {
	      	if(heads[i].x==x-1 && heads[i].y==y-1)
	      	    {
	      	    	gotoxy(18,15);
		            printf("LOVIT CAP AVION");
		            gotoxy(x,y-1);
		            printf("*");
		            score2++;
		            break;
	      	    }
	      if(i==2){
	      	        gotoxy(18,15);
		            printf("LOVIT          ");
		            gotoxy(x,y-1);
		            printf("x");
	             }
	     }
		
		}else{
			gotoxy(18,15);
		    printf("AI RATAT");
		    gotoxy(x,y-1);
		    printf("#");
		}
		
		gotoxy(25,1);
         if(score2==3)
		{
		   gotoxy(30,25);
		   printf("OVER! %s a castigat!",b2.getName());
		   break;
		}
		gotoxy(3,22);
	    printf("%s:%d %s:%d",b1.getName(),score1,b2.getName(),score2);
	    gotoxy(25,1);
		system("PAUSE");
		
		
	}
	
}

game::game(int height,int width)
{
	b1 = board(height,width);
	b2 = board(height,width);
}

void game::preGame(int height,int width)
{
	game(height,width);
	char name[20];
	
	cout<<"player1=";
	cin>>name;
	b1.setName(name);
	cout<<"\nplayer2=";
	cin>>name;
	b2.setName(name);
	system("cls");
	
	 
	for(int i=0;i<3;i++)
	{
	  avion a = avion(5,width+1);
	  system("cls"); 
	  P *points = a.getPoints();
	  fflush(stdin);
	  b1.printA(1);
	  rescrie(points);
	  gotoxy(height+1,1);
	  cout<<b1.getName()<<" seteaza avioanele";
	  gotoxy(height+2,2);
	  cout<<"din sageti se navigheaza, ctrl roteste, shift seteaza avion";
	
	  while(1)
	  {	
		if(GetAsyncKeyState(VK_LEFT))
		  {
		  	if(b1.cond(a,1))
		  	{
		  	 sterge(points,width);
		  	 a.goLeft();
		  	 delay();
		  	 rescrie(points);
		  	 fflush(stdout);	
		  	}
		  	
		  }
		 else if(GetAsyncKeyState(VK_RIGHT))
		  {
		  	if(b1.cond(a,3))
		  	 {
		  	    sterge(points,width);
		  	    a.goRight(width-1);
		  	    delay();
		  	    rescrie(points);
		  	    fflush(stdout);
		  	 }
		  }
		  else if(GetAsyncKeyState(VK_UP))
		   {
		  	      	if(b1.cond(a,4))
		  	      	{ 
		  	      	sterge(points,width);
		           	a.goUp();
		           	delay();
		           	rescrie(points);
		           	fflush(stdout);
		  	      	}
		  }
		   else if(GetAsyncKeyState(VK_DOWN))
		      {
		  	          if(b1.cond(a,2))
		  	          {
		  	          sterge(points,width);
		  	          a.goDown(height-1);
		  	          delay();
		  	          rescrie(points);
		  	          fflush(stdout);
		  	          }
		     }
		     else if(GetAsyncKeyState(VK_LCONTROL))
		      {
		  	          sterge(points,width);
		  	          a.rotateLeft(height,width);
		  	          delay();
		  	          rescrie(points);
		  	          fflush(stdout);
		     }
		         else if(GetAsyncKeyState(VK_LSHIFT))
		           {
		          	b1.setShip(a);
		          	delay();
		          	fflush(stdout);
		       	   break;
		           }
	   }
	    
	}
	

	for(int i=0;i<3;i++)
	{
	  avion a = avion(5,width+1);
	  system("cls"); 
	  P *points = a.getPoints();
	  fflush(stdin);
	  b2.printA(1);
	  rescrie(points);
	  gotoxy(height+1,1);
	  cout<<b1.getName()<<" seteaza avioanele";
	  gotoxy(height+2,2);
	  cout<<"din sageti se navigheaza, ctrl roteste, shift seteaza avion";
	  while(1)
	  {	
		if(GetAsyncKeyState(VK_LEFT))
		  {
		  	if(b2.cond(a,1))
		  	{
		  	 sterge(points,width);
		  	 a.goLeft();
		  	 delay();
		  	 rescrie(points);
		  	 fflush(stdout);	
		  	}
		  	
		  }
		 else if(GetAsyncKeyState(VK_RIGHT))
		  {
		  	if(b2.cond(a,3))
		  	 {
		  	    sterge(points,width);
		  	    a.goRight(width-1);
		  	    delay();
		  	    rescrie(points);
		  	    fflush(stdout);
		  	 }
		  }
		  else if(GetAsyncKeyState(VK_UP))
		   {
		  	      	if(b2.cond(a,4))
		  	      	{
		  	      	sterge(points,width);
		           	a.goUp();
		           	delay();
		           	rescrie(points);
		           	fflush(stdout);
		  	      	}
		  }
		   else if(GetAsyncKeyState(VK_DOWN))
		      {
		  	          if(b2.cond(a,2))
		  	          {
		  	          sterge(points,width);
		  	          a.goDown(height-1);
		  	          delay();
		  	          rescrie(points);
		  	          fflush(stdout);
		  	          }
		     }
		     else if(GetAsyncKeyState(VK_LCONTROL))
		      {
		  	          sterge(points,width);
		  	          a.rotateLeft(height,width);
		  	          delay();
		  	          rescrie(points);
		  	          fflush(stdout);
		     }
		         else if(GetAsyncKeyState(VK_LSHIFT))
		           {
		          	b2.setShip(a);
		          	delay();
		          	fflush(stdout);
		       	   break;
		           }
	   }
	    
	} 
	
	
	
	
}
