#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 4);
	printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("       ");
}
void draw_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 0);
	printf("+");
}
void erase_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf(" ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
char cursor(int x, int y) 
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
	{
		return '\0';
	}	
	else
	{
		return buf[0];
	}
}


int main()
{
	char ch = '.';
	int x = 38, y = 20, direction = 2, bullet[5] = { 0 }, a[5], b[5],star=20,c=0,d=0,score=0,i=0;
	setcursor(0);
	draw_ship(x, y);
	srand(time(NULL));
	while(i<20)
	{
		c = rand() % 60 + 10;
		d = rand() % 4 + 2;
		if (cursor(c, d) == '*')
		{
			i--;
		}
		else
		{
			gotoxy(c, d);
			setcolor(3, 0);
			printf("*");
			i++;
		}
		
	}
	do
	{
		if (_kbhit())
		{
			ch = _getch();

			if (ch == 'a')
			{
				direction = 0;
			}
			if (ch == 'd')
			{
				direction = 1;
			}
			if (ch == 's')
			{
				direction = 2;
			}
			if (ch == ' ' && bullet[0] == 0)
			{
				a[0] = x;
				b[0] = y - 1;
				bullet[0] = 1;
			}
			else if (ch == ' ' && bullet[1] == 0)
			{
				a[1] = x;
				b[1] = y - 1;
				bullet[1] = 1;
			}
			else if (ch == ' ' && bullet[2] == 0)
			{
				a[2] = x;
				b[2] = y - 1;
				bullet[2] = 1;
			}
			else if (ch == ' ' && bullet[3] == 0)
			{
				a[3] = x;
				b[3] = y - 1;
				bullet[3] = 1;
			}
			else if (ch == ' ' && bullet[4] == 0)
			{
				a[4] = x;
				b[4] = y - 1;
				bullet[4] = 1;
			}
		}
		if (direction == 0 && x > 0)
		{
			erase_ship(x, y);
			draw_ship(--x, y);
		}
		if (direction == 1 && x < 80)
		{
			erase_ship(x, y);
			draw_ship(++x, y);
		}
		if (direction == 2)
		{
			draw_ship(x, y);
		}

		if (star < 20)
		{
			if (cursor(c, d) == '*')
			{
				c = rand() % 60 + 10;
				d = rand() % 4 + 2;
			}
			else
			{
				c = rand() % 60 + 10;
				d = rand() % 4 + 2;
				gotoxy(c, d);
				setcolor(3, 0);
				printf("*");
				star++;
			}
		}

		if (bullet[0] == 1)
		{
			erase_bullet(a[0], b[0]);
			if (b[0] > 0)
			{
				if (cursor(a[0], b[0] - 1) == '*')
				{
					gotoxy(a[0], b[0] - 1);
					Beep(700, 100);
					printf(" ");
					bullet[0] = 0;
					star--;
					score++;
				}
				else
				{
					draw_bullet(a[0], --b[0]);
				}
			}
			else
			{
				bullet[0] = 0;
			}
		}
		if (bullet[1] == 1)
		{
			erase_bullet(a[1], b[1]);
			if (b[1] > 0)
			{
				if (cursor(a[1], b[1] - 1) == '*')
				{
					gotoxy(a[1], b[1] - 1);
					Beep(700, 100);
					printf(" ");
					bullet[1] = 0;
					star--;
					score++;
				}
				else
				{
					draw_bullet(a[1], --b[1]);
				}
			}
			else
			{
				bullet[1] = 0;
			}
		}
		if (bullet[2] == 1)
		{
			erase_bullet(a[2], b[2]);
			if (b[2] > 0)
			{
				if (cursor(a[2], b[2] - 1) == '*')
				{
					gotoxy(a[2], b[2] - 1);
					Beep(700, 100);
					printf(" ");
					bullet[2] = 0;
					star--;
					score++;
				}
				else
				{
					draw_bullet(a[2], --b[2]);
				}
			}
			else
			{
				bullet[2] = 0;
			}
		}
		if (bullet[3] == 1)
		{
			erase_bullet(a[3], b[3]);
			if (b[3] > 0)
			{
				if (cursor(a[3], b[3] - 1) == '*')
				{
					gotoxy(a[3], b[3] - 1);
					Beep(700, 100);
					printf(" ");
					bullet[3] = 0;
					star--;
					score++;
				}
				else
				{
					draw_bullet(a[3], --b[3]);
				}
			}
			else
			{
				bullet[3] = 0;
			}
		}
		if (bullet[4] == 1)
		{
			erase_bullet(a[4], b[4]);
			if (b[4] > 0)
			{
				if (cursor(a[4], b[4] - 1) == '*')
				{
					gotoxy(a[4], b[4] - 1);
					Beep(700, 100);
					printf(" ");
					bullet[4] = 0;
					star--;
					score++;
				}
				else
				{
					draw_bullet(a[4], --b[4]);
				}
			}
			else
			{
				bullet[4] = 0;
			}
		}
		gotoxy(95, 2);
		setcolor(6, 0);
		printf("SCORE = %d", score);
		fflush(stdin);
		Sleep(100);
	} while (ch != 'x');
	return 0;
}