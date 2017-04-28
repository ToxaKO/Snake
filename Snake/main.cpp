#include <iostream>  //ñòàíäàðòíàÿ áèáëèîòåêà
#include <time.h> //ñëó÷àéíûå ÷èñëà
#include <stdio.h> //äëÿ printf
#include <windows.h> // äëÿ HANDLE, êóðñîðà, öâåòà
#include <conio.h>  //äëÿ kbhit

using namespace std;



HANDLE hConsole;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GotoXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
} 
//Öâåò
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


class Snake  // ñòðóêòóðà çìåéêà 
{
	public:COORD *t; //òî÷êè
	public:int PCount; //êîëè÷åñòâî ÿáëîê
};
enum Control{LEFT,UP,RIGHT,DOWN}; //íàïðàâëåíèå çìåéêè
class Game //äàíûå-òî÷íîñòè: çìåéêè, ÿáëîê, ïåðåäâèæåíèå ïî X è Y, çàäåðæêà, íàïðàâëåíèå
{
	public:Snake cobra; //çìåéêà 
	public:COORD apple; //ÿáëîêî 
	public:int dx,dy; //ïåðåäâèæåíèå
	public:int pause; //çàäåðæêà
	public:int nav; //íàïðàâëåíèå
	
};


void PlusApple(Game &g) //Ôóíêöèÿ ðàçáðîñêè ÿáëîê PlusJabloko
{
	int i,x,y;
	int n = g.cobra.PCount;
	do
	{
		x = rand() % 56+3; //
		y = rand() % 19+3; //êîðäèíàòû ÿáëîêà
		for(i = 0; i < n; i++)
		{
			if(x == g.cobra.t[i].X && y == g.cobra.t[i].Y) // ïðîâåðêà ÷òîá ÿáëîêî íå áðîñèòü íà çìåþ
				break;
		}
	}
	while(i < n);
	g.apple.X = x; //
	g.apple.Y = y; //çàïîìèíàåì ïîçèöèþ ÿáëîêà
	SetConsoleCursorPosition(hConsole, g.apple); //ïåðåíîñèì êóðñîð â ýòó ïîçèöèþ
	SetConsoleTextAttribute(hConsole,0x0c); //öâåò ÿáëîêà  
	printf("%c", 4); //ðèñóåì ÿáëîêî êàêèì õîòèì ñèìâîëîì
	
}


void SpeedGame(Game &g) // Ôóíêöèÿ ñòàðòà çìåéêè åå êîîðäèíàò è ñêîðîñòè skorostGame
{
	system("cls");
	g.cobra.PCount = 3; //ñêîëüêî òî÷åê â çìåéêå
	g.cobra.t = new COORD [3];//ñîçäàëè òî÷êè
	for(int i = 0; i < 3; i++)
	{
		g.cobra.t[i].X = 20 + i;
		g.cobra.t[i].Y = 20;
		
	}
	g.dx = 1;
	g.dy = 0;
	g.pause = 100;//ñêîðîñòü ïåðåäâèæåíèå çìåè
	PlusApple(g);//ðèñóåì ÿáëîêà
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
void WallWindow() //Âñÿ èíôîðìàöèÿ, îòîáðàæàåìàÿ íà ñòåíå STENA_2
{
	SetColor(LightBlue , Black);GotoXY(20,0);cout << "Snake game " <<endl;  //ÍÀÄÏÈÑÜ: Èãðà Çìåéêà Äàíèëåíêî Àëåêñàíäðà
	GotoXY(64,2);cout <<  "Info:" << endl ; //Äàííûå
	GotoXY(64,3);cout <<  "Apple:0" << endl ; //ßáëîê
	GotoXY(64,4); cout <<  "Length:3"<< endl; //Äëèíà
	GotoXY(64,5); cout <<  "Speed:0" << endl; //Ñêîðîñòü
	GotoXY(64,7); cout << "Control:" <<  endl; //Óïðàâëåíèå
    GotoXY(64,8); cout << "Esc:Exit" <<  endl; //Âûõîä
	GotoXY(64,9); cout << "P:Pause" <<  endl; //Ïàóçà
	GotoXY(64,10); cout <<"S:Start" <<  endl; //Ñòàðò
	GotoXY(64,11); cout <<"L:Level" <<  endl; //Óðîâåíü
	GotoXY(64,13);printf("%c",24);cout <<":Up"<<endl; //Ââåðõ
	GotoXY(64,14);printf("%c",25);cout<<":Down"<<endl;   //Âíèç
	GotoXY(64,15);printf("%c",27);cout<<":Left"<<endl;  //Âëåâî
	GotoXY(64,16);printf("%c",26);cout<<":Right"<<endl; //Âïðàâî
				{SetColor(LightMagenta , Black);
				
                GotoXY(2,2); //Ðèñóåì âåðõíþþ ãîðèçîíòàëüíóþ ëèíèþ-ñòåíêó
				int m = 0;
				for(m = 0; m < 60; m++)
				{
					printf("*");
				}
				}
				
				{
					GotoXY(2,24); //Ðèñóåì íèæíþþ ãîðèçîíòàëüíóþ ëèíèþ-ñòåíêó
					int m = 0;
					for(m = 0; m < 60;m++)
					{
						printf("*");
					}
				}
				{	//Ðèñóåì ëåâóþ âåðòèêàëüíóþ ëèíèþ-ñòåíêó
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
				{   //Ðèñóåì ïðàâóþ âåðòèêàëüíóþ ëèíèþ-ñòåíêó
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


//Ôóíêöèÿ êîòîðàÿ äâèãàåò è ðèñóåò
enum {WALL=0,  PLUS=1, MOVE=2};
int MoveSnake(Game &g)
{
	int & n = g.cobra.PCount;
	COORD head = g.cobra.t[n - 1]; //ãîëîâà
	COORD tail = g.cobra.t[0]; //õâîñò
	COORD next;
	next.X = head.X + g.dx;
	next.Y = head.Y + g.dy; //ïðîâåðêà ñëåäóþùåé òî÷êè ïî íàïðàâëåíèþ
	
    if(next.X < 3 || next.Y < 3 || next.X > 60 || next.Y > 23)//íå óïåðëàñü ëè â ñòåíó?
		return WALL;
	
	if(next.X == g.apple.X && next.Y == g.apple.Y)
	{
		COORD*temp = new COORD[ ++n ]; //íîâûé ìàñèâ áîëüøèé íà 1
		for(int i = 0; i < n; i++)
			temp[i] = g.cobra.t[i]; //ïåðåêîïèðóåì
		temp[n - 1] = next; //äîáàâëÿåì îäíó
		delete [] g.cobra.t;
		g.cobra.t = temp;
		
		SetConsoleCursorPosition(hConsole,head);
		SetConsoleTextAttribute(hConsole, 0x0a); //çàêðàøûâàåì ÿáëîêî êîòîðîå ñåëè 
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
	SetConsoleCursorPosition(hConsole,tail);//çàêðàøèâàåì õâîñò
	printf(" ");
	
	SetConsoleCursorPosition(hConsole,head);
	SetConsoleTextAttribute(hConsole, 0x0a);//êðàñèì õâîñò çìåè â çåëåíèé öâåò
	printf("*");
	SetConsoleCursorPosition(hConsole,next);
	SetConsoleTextAttribute(hConsole,0x0f); //êðàñèì êóðñîð â áåëûé öâåò (ãîëîâó çìåè) 
	printf("%c",1);
	
	return MOVE;
}

int IntroWindow()
{
        GotoXY(3,10); //Èíòðóõà
	printf("Snake game. (Press Enter...)");
	getch();
	return 0;
}

int main()
{

    
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //ïîëó÷àåì äåñêðèïòîð êîíñîëè
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
		while(!kbhit()) //æäåò ïîêà íàæìåì
		{
			if(Pause==true)
			{
				Sleep(1); 
				continue;
			}
			
			switch (MoveSnake(g))//äâèæåíèå
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
                    GotoXY(24,1); cout << "U win!" << endl; //Âû âûèãðàëè
					getch();
					return(0);
				}
				break;
				
			case WALL:
				
			case END:
				GotoXY(23,1); printf("U loose!"); //Âû ïðîèãðàëè, ÕÀ ÕÀ ÕÀ
				getch();
				break;
			}
			
			Sleep(g.pause); //Çàäåðæêà
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
