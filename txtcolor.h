#include <windows.h>

//Define extra colours
#define FOREGROUND_WHITE	(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN)
#define FOREGROUND_YELLOW  	(FOREGROUND_RED | FOREGROUND_GREEN)
#define FOREGROUND_CYAN		(FOREGROUND_BLUE | FOREGROUND_GREEN)
#define FOREGROUND_MAGENTA	(FOREGROUND_RED | FOREGROUND_BLUE)
#define FOREGROUND_BLACK	NULL

#define FOREGROUND_INTENSE_RED		(FOREGROUND_RED | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_GREEN	(FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_BLUE		(FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_WHITE	(FOREGROUND_WHITE | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_YELLOW	(FOREGROUND_YELLOW | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_CYAN		(FOREGROUND_CYAN | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_MAGENTA	(FOREGROUND_MAGENTA | FOREGROUND_INTENSITY)

#define BACKGROUND_WHITE	(BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN)
#define BACKGROUND_YELLOW	(BACKGROUND_RED | BACKGROUND_GREEN)
#define BACKGROUND_CYAN		(BACKGROUND_BLUE | BACKGROUND_GREEN)
#define BACKGROUND_MAGENTA	(BACKGROUND_RED | BACKGROUND_BLUE)
#define BACKGROUND_BLACK	NULL

#define BACKGROUND_INTENSE_RED		(BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BACKGROUND_INTENSE_GREEN	(BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define BACKGROUND_INTENSE_BLUE		(BACKGROUND_BLUE | BACKGROUND_INTENSITY)
#define BACKGROUND_INTENSE_WHITE	(BACKGROUND_WHITE | BACKGROUND_INTENSITY)
#define BACKGROUND_INTENSE_YELLOW	(BACKGROUND_YELLOW | BACKGROUND_INTENSITY)
#define BACKGROUND_INTENSE_CYAN		(BACKGROUND_CYAN | BACKGROUND_INTENSITY)
#define BACKGROUND_INTENSE_MAGENTA	(BACKGROUND_MAGENTA | BACKGROUND_INTENSITY)

// Define cursors
#define _NOCURSOR		0
#define _NORMALCURSOR	1
#define _HALFCURSOR		50
#define _SOLIDCURSOR	100


void _setcursortype(int selection)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	
	switch(selection)
	{
		case 0:
			cursor.dwSize = _NORMALCURSOR;
			cursor.bVisible = 0;
			break;
		case 1:
			cursor.dwSize = _NORMALCURSOR;
			cursor.bVisible = 1;
			break;
		case 2:
			cursor.dwSize = _HALFCURSOR;
			cursor.bVisible = 1;
			break;
		case 3:
			cursor.dwSize = _SOLIDCURSOR;
			cursor.bVisible = 1;
			break;
		default:
			cursor.dwSize = _NORMALCURSOR;
			cursor.bVisible = 1;
			break;
	}
	SetConsoleCursorInfo(hout, &cursor);
	
}

void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}
 
void clrscr()
{
	 system("cls");
}
 
void textcolor(int selection)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	switch(selection)
	{
		case 0:
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLACK);
			break;
		case 1:
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
			break;
		case 2:
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			break;
		case 3:
			SetConsoleTextAttribute(hConsole, FOREGROUND_CYAN);
			break;
		case 4:
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			break;
		case 5:
			SetConsoleTextAttribute(hConsole, FOREGROUND_MAGENTA);
			break;
		case 6:
			SetConsoleTextAttribute(hConsole, FOREGROUND_YELLOW);
			break;
		case 7:
			SetConsoleTextAttribute(hConsole, FOREGROUND_WHITE);
			break;
		case 8:
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSE_BLUE);
			break;
		case 9:
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSE_GREEN);
			break;
		case 10:
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSE_CYAN);
			break;
		case 11:
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSE_RED);
			break;
		case 12:
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSE_MAGENTA);
			break;
		case 13:
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSE_YELLOW);
			break;
		case 14:
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSE_WHITE);
			break;
		default:
			SetConsoleTextAttribute(hConsole, FOREGROUND_WHITE);
			break;
	}
}
 
void textbackground(int selection)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch(selection)
	{
		case 0:
			SetConsoleTextAttribute(hConsole, BACKGROUND_BLACK);
			break;
		case 1:
			SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
			break;
		case 2:
			SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
			break;
		case 3:
			SetConsoleTextAttribute(hConsole, BACKGROUND_CYAN);
			break;
		case 4:
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
			break;
		case 5:
			SetConsoleTextAttribute(hConsole, BACKGROUND_MAGENTA);
			break;
		case 6:
			SetConsoleTextAttribute(hConsole, BACKGROUND_YELLOW);
			break;
		case 7:
			SetConsoleTextAttribute(hConsole, BACKGROUND_WHITE);
			break;
		case 8:
			SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSE_BLUE);
			break;
		case 9:
			SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSE_GREEN);
			break;
		case 10:
			SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSE_CYAN);
			break;
		case 11:
			SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSE_RED);
			break;
		case 12:
			SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSE_MAGENTA);
			break;
		case 13:
			SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSE_YELLOW);
			break;
		case 14:
			SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSE_WHITE);
			break;
		default:
			SetConsoleTextAttribute(hConsole, BACKGROUND_BLACK);
			break;
	}
}