#include <iostream>  //����������� ����������
#include <time.h> //��������� �����
#include <stdio.h> //��� printf
#include <windows.h> // ��� HANDLE, �������, �����
#include <conio.h>  //��� kbhit

using namespace std;



HANDLE hConsole;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GotoXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
} 
//����
enum ConsoleColor
{
    	Black         = 0,
		Blue          = 1,
		Green         = 2,
		Cyan          = 3,
		Red           = 4,
		Magenta       = 5,
		Brown         = 6,
		LightGray     = 7,
		DarkGray      = 8,
		LightBlue     = 9,
		LightGreen    = 10,
		LightCyan     = 11,
		LightRed      = 12,
		LightMagenta  = 13,
		Yellow        = 14,
		White         = 15
};

void SetColor(ConsoleColor text, ConsoleColor background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


class Snake  // ��������� ������ 
{
	public:COORD *t; //�����
	public:int PCount; //���������� �����
};
enum Control{LEFT,UP,RIGHT,DOWN}; //����������� ������
class Game //�����-��������: ������, �����, ������������ �� X � Y, ��������, �����������
{
	public:Snake cobra; //������ 
	public:COORD apple; //������ 
	public:int dx,dy; //������������
	public:int pause; //��������
	public:int nav; //�����������
	
};


void PlusApple(Game &g) //������� ��������� ����� PlusJabloko
{
	int i,x,y;
	int n = g.cobra.PCount;
	do
	{
		x = rand() % 56+3; //
		y = rand() % 19+3; //��������� ������
		for(i = 0; i < n; i++)
		{
			if(x == g.cobra.t[i].X && y == g.cobra.t[i].Y) // �������� ���� ������ �� ������� �� ����
				break;
		}
	}
	while(i < n);
	g.apple.X = x; //
	g.apple.Y = y; //���������� ������� ������
	SetConsoleCursorPosition(hConsole, g.apple); //��������� ������ � ��� �������
	SetConsoleTextAttribute(hConsole,0x0c); //���� ������  
	printf("%c", 4); //������ ������ ����� ����� ��������
	
}


void SpeedGame(Game &g) // ������� ������ ������ �� ��������� � �������� skorostGame
{
	system("cls");
	g.cobra.PCount = 3; //������� ����� � ������
	g.cobra.t = new COORD [3];//������� �����
	for(int i = 0; i < 3; i++)
	{
		g.cobra.t[i].X = 20 + i;
		g.cobra.t[i].Y = 20;
		
	}
	g.dx = 1;
	g.dy = 0;
	g.pause = 100;//�������� ������������ ����
	PlusApple(g);//������ ������
}
void LevelGame()
{
	GotoXY(10,10);cout <<"U will never win!"<<endl; 
	GotoXY(10,11);cout <<"Focus on the snake!"<<endl; 
}
void SnakeStart()
{
	GotoXY(10,15);cout <<"Catch 50 apples"<<endl; 
}
void WallWindow() //��� ����������, ������������ �� ����� STENA_2
{
	SetColor(LightBlue , Black);GotoXY(20,0);cout << "Snake game " <<endl;  //�������: ���� ������ ��������� ����������
	GotoXY(64,2);cout <<  "Info:" << endl ; //������
	GotoXY(64,3);cout <<  "Apple:0" << endl ; //�����
	GotoXY(64,4); cout <<  "Length:3"<< endl; //�����
	GotoXY(64,5); cout <<  "Speed:0" << endl; //��������
	GotoXY(64,7); cout << "Control:" <<  endl; //����������
    GotoXY(64,8); cout << "Esc:Exit" <<  endl; //�����
	GotoXY(64,9); cout << "P:Pause" <<  endl; //�����
	GotoXY(64,10); cout <<"S:Start" <<  endl; //�����
	GotoXY(64,11); cout <<"L:Level" <<  endl; //�������
	GotoXY(64,13);printf("%c",24);cout <<":Up"<<endl; //�����
	GotoXY(64,14);printf("%c",25);cout<<":Down"<<endl;   //����
	GotoXY(64,15);printf("%c",27);cout<<":Left"<<endl;  //�����
	GotoXY(64,16);printf("%c",26);cout<<":Right"<<endl; //������
				{SetColor(LightMagenta , Black);
				
                GotoXY(2,2); //������ ������� �������������� �����-������
				int m = 0;
				for(m = 0; m < 60; m++)
				{
					printf("*");
				}
				}
				
				{
					GotoXY(2,24); //������ ������ �������������� �����-������
					int m = 0;
					for(m = 0; m < 60;m++)
					{
						printf("*");
					}
				}
				{	//������ ����� ������������ �����-������
					GotoXY(2,3); cout << "*"<<endl;
					GotoXY(2,4); cout << "*"<<endl;
					GotoXY(2,5); cout << "*"<<endl;
					GotoXY(2,6); cout << "*"<<endl;
					GotoXY(2,7); cout << "*"<<endl;
					GotoXY(2,8); cout << "*"<<endl;
					GotoXY(2,9); cout << "*"<<endl;
					GotoXY(2,10); cout << "*"<<endl;
					GotoXY(2,11); cout << "*"<<endl;
					GotoXY(2,12); cout << "*"<<endl;
					GotoXY(2,13); cout << "*"<<endl;
					GotoXY(2,14); cout << "*"<<endl;
					GotoXY(2,15); cout << "*"<<endl;
					GotoXY(2,16); cout << "*"<<endl;
					GotoXY(2,17); cout << "*"<<endl;
					GotoXY(2,18); cout << "*"<<endl;
					GotoXY(2,19); cout << "*"<<endl;
					GotoXY(2,20); cout << "*"<<endl;
					GotoXY(2,21); cout << "*"<<endl;
					GotoXY(2,22); cout << "*"<<endl;
					GotoXY(2,23); cout << "*"<<endl;
				}
				{   //������ ������ ������������ �����-������
					GotoXY(61,3); cout << "*"<<endl;
					GotoXY(61,4); cout << "*"<<endl;
					GotoXY(61,5); cout << "*"<<endl;
					GotoXY(61,6); cout << "*"<<endl;
					GotoXY(61,7); cout << "*"<<endl;
					GotoXY(61,8); cout << "*"<<endl;
					GotoXY(61,9); cout << "*"<<endl;
					GotoXY(61,10); cout << "*"<<endl;
					GotoXY(61,11); cout << "*"<<endl;
					GotoXY(61,12); cout << "*"<<endl;
					GotoXY(61,13); cout << "*"<<endl;
					GotoXY(61,14); cout << "*"<<endl;
					GotoXY(61,15); cout << "*"<<endl;
					GotoXY(61,16); cout << "*"<<endl;
					GotoXY(61,17); cout << "*"<<endl;
					GotoXY(61,18); cout << "*"<<endl;
					GotoXY(61,19); cout << "*"<<endl;
					GotoXY(61,20); cout << "*"<<endl;
					GotoXY(61,21); cout << "*"<<endl;
					GotoXY(61,22); cout << "*"<<endl;
					GotoXY(61,23); cout << "*"<<endl;
				}
}


//������� ������� ������� � ������
enum {END, WALL,  PLUS, MOVE};
int MoveSnake(Game &g)
{
	int & n = g.cobra.PCount;
	COORD head = g.cobra.t[n - 1]; //������
	COORD tail = g.cobra.t[0]; //�����
	COORD next;
	next.X = head.X + g.dx;
	next.Y = head.Y + g.dy; //�������� ��������� ����� �� �����������
	
    if(next.X < 3 || next.Y < 3 || next.X > 60 || next.Y > 23)//�� �������� �� � �����?
		return WALL;
		
	if(n > 4)
	{
		for(int i = 0; i < n; i++)
			if(next.X == g.cobra.t[i].X && next.Y == g.cobra.t[i].Y) //�� ������� �� �� ����?
				return END;
	}
	
	if(next.X == g.apple.X && next.Y == g.apple.Y)
	{
		COORD*temp = new COORD[ ++n ]; //����� ����� ������� �� 1
		for(int i = 0; i < n; i++)
			temp[i] = g.cobra.t[i]; //������������
		temp[n - 1] = next; //��������� ����
		delete [] g.cobra.t;
		g.cobra.t = temp;
		
		SetConsoleCursorPosition(hConsole,head);
		SetConsoleTextAttribute(hConsole, 0x0a); //����������� ������ ������� ���� 
		printf("*");
		SetConsoleCursorPosition(hConsole,next);
		SetConsoleTextAttribute(hConsole,0x0a);
		printf("%c",1);
		PlusApple(g);
		return PLUS;
	}
	
	for(int i = 0; i < n - 1; i++)
		g.cobra.t[i] = g.cobra.t[i + 1];
	g.cobra.t[n - 1] = next;
	SetConsoleCursorPosition(hConsole,tail);//����������� �����
	printf(" ");
	
	SetConsoleCursorPosition(hConsole,head);
	SetConsoleTextAttribute(hConsole, 0x0a);//������ ����� ���� � ������� ����
	printf("*");
	SetConsoleCursorPosition(hConsole,next);
	SetConsoleTextAttribute(hConsole,0x0f); //������ ������ � ����� ���� (������ ����) 
	printf("%c",1);
	
	return MOVE;
}

int IntroWindow()
{
        GotoXY(3,10); //�������
	printf("Snake game. (Press Enter...)");
	getch();
	return 0;
}

int main()
{

    
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //�������� ���������� �������
	IntroWindow();
    int key = 0, count = 0;
	bool Pause=false;
	Game g;
	SpeedGame(g);
	WallWindow();
	srand(time(0));
	bool pause = false;
	while(key != 27)
	{
		while(!kbhit()) //���� ���� ������
		{
			if(Pause==true)
			{
				Sleep(1); 
				continue;
			}
			
			switch (MoveSnake(g))//��������
			{
				
			case PLUS:
				++count;
				g.pause-=1;
				SetColor(LightBlue , Black);
				GotoXY(64,2);cout <<  "Info:" << endl ;
				GotoXY(64,3); cout << "Apple:" <<count << endl;
				GotoXY(64,4); cout << "Lenght:" <<g.cobra.PCount << endl;
				GotoXY(64,5); cout << "Speed:" <<g.pause<< endl;
				GotoXY(64,7); cout << "Control:" <<  endl;
				GotoXY(64,8); cout << "Esc:Exit" <<  endl;
				GotoXY(64,9); cout << "P:Pause" <<  endl;
				GotoXY(64,10); cout <<"S:Start" <<  endl;
				GotoXY(64,11); cout <<"L:Level" <<  endl;
				GotoXY(64,13);printf("%c",24);cout <<":Up"<<endl;
				GotoXY(64,14);printf("%c",25);cout<<":Down"<<endl;
				GotoXY(64,15);printf("%c",27);cout<<":Left"<<endl;
				GotoXY(64,16);printf("%c",26);cout<<":Right"<<endl;
				if (count == 50) 
				{
                    SetColor(White , Black);
                    GotoXY(24,1); cout << "U win!" << endl; //�� ��������
					getch();
					return(0);
				}
				break;
				
			case WALL:
				
			case END:
				GotoXY(23,1); printf("U loose!"); //�� ���������, �� �� ��
				getch();
				break;
			}
			
			Sleep(g.pause); //��������
		}
	key = getch();
		
    	if(key=='P'||key=='p')
			Pause=!Pause;
			else if(key=='S'||key=='s')
			SnakeStart();
		else if(key=='L'||key=='l')
			LevelGame();
		else if(key==0||key==224)
		{
			key=getch();
			
			if(key == 72 && g.nav != DOWN)
			{
				g.nav = UP;
				g.dx = 0;
				g.dy = -1;
			}
			else if(key == 80 && g.nav != UP)
			{
				g.nav = DOWN;
				g.dx = 0;
				g.dy = 1;
			}
			else if(key == 75 && g.nav != RIGHT)
			{
				g.nav = LEFT;
				g.dx = -1;
				g.dy = 0;
			}
			else if(key == 77 && g.nav != LEFT)
			{
				g.nav = RIGHT;
				g.dx = 1;
				g.dy = 0;
			}
		}
	}
}
//}
