using namespace std;
#include "game.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	
	HWND bigger; 
    AllocConsole();
    bigger=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(bigger,3);
	
	 game GAME = game(10,10);
	 GAME.preGame(10,10);
	 GAME.startGame(10,10);
	 //GAME.~game();
	 


	return 0;
	
}
