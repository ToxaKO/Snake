#include <iostream>  //стандартная библиотека
#include <time.h> //случайные числа
#include <stdio.h> //для printf
#include <windows.h> // для HANDLE, курсора, цвета
#include <conio.h>  //для kbhit

using namespace std;



HANDLE hConsole;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GotoXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
} 
//Цвет
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


class Snake  // структура змейка 
{
	public:COORD *t; //точки
	public:int PCount; //количество яблок
};
enum Control{LEFT,UP,RIGHT,DOWN}; //направление змейки
class Game //даные-точности: змейки, яблок, передвижение по X и Y, задержка, направление
{
	public:Snake cobra; //змейка 
	public:COORD apple; //яблоко 
	public:int dx,dy; //передвижение
	public:int pause; //задержка
	public:int nav; //направление
	
};


void PlusApple(Game &g) //Функция разброски яблок PlusJabloko
{
	int i,x,y;
	int n = g.cobra.PCount;
	do
	{
		x = rand() % 56+3; //
		y = rand() % 19+3; //кординаты яблока
		for(i = 0; i < n; i++)
		{
			if(x == g.cobra.t[i].X && y == g.cobra.t[i].Y) // проверка чтоб яблоко не бросить на змею
				break;
		}
	}
	while(i < n);
	g.apple.X = x; //
	g.apple.Y = y; //запоминаем позицию яблока
	SetConsoleCursorPosition(hConsole, g.apple); //переносим курсор в эту позицию
	SetConsoleTextAttribute(hConsole,0x0c); //цвет яблока  
	printf("%c", 4); //рисуем яблоко каким хотим символом
	
}


void SpeedGame(Game &g) // Функция старта змейки ее координат и скорости skorostGame
{
	system("cls");
	g.cobra.PCount = 3; //сколько точек в змейке
	g.cobra.t = new COORD [3];//создали точки
	for(int i = 0; i < 3; i++)
	{
		g.cobra.t[i].X = 20 + i;
		g.cobra.t[i].Y = 20;
		
	}
	g.dx = 1;
	g.dy = 0;
	g.pause = 100;//скорость передвижение змеи
	PlusApple(g);//рисуем яблока
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
void WallWindow() //Вся информация, отображаемая на стене STENA_2
{
	SetColor(LightBlue , Black);GotoXY(20,0);cout << "Snake game " <<endl;  //НАДПИСЬ: Игра Змейка Даниленко Александра
	GotoXY(64,2);cout <<  "Info:" << endl ; //Данные
	GotoXY(64,3);cout <<  "Apple:0" << endl ; //Яблок
	GotoXY(64,4); cout <<  "Length:3"<< endl; //Длина
	GotoXY(64,5); cout <<  "Speed:0" << endl; //Скорость
	GotoXY(64,7); cout << "Control:" <<  endl; //Управление
    GotoXY(64,8); cout << "Esc:Exit" <<  endl; //Выход
	GotoXY(64,9); cout << "P:Pause" <<  endl; //Пауза
	GotoXY(64,10); cout <<"S:Start" <<  endl; //Старт
	GotoXY(64,11); cout <<"L:Level" <<  endl; //Уровень
	GotoXY(64,13);printf("%c",24);cout <<":Up"<<endl; //Вверх
	GotoXY(64,14);printf("%c",25);cout<<":Down"<<endl;   //Вниз
	GotoXY(64,15);printf("%c",27);cout<<":Left"<<endl;  //Влево
	GotoXY(64,16);printf("%c",26);cout<<":Right"<<endl; //Вправо
				{SetColor(LightMagenta , Black);
				
                GotoXY(2,2); //Рисуем верхнюю горизонтальную линию-стенку
				int m = 0;
				for(m = 0; m < 60; m++)
				{
					printf("*");
				}
				}
				
				{
					GotoXY(2,24); //Рисуем нижнюю горизонтальную линию-стенку
					int m = 0;
					for(m = 0; m < 60;m++)
					{
						printf("*");
					}
				}
				{	//Рисуем левую вертикальную линию-стенку
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
				{   //Рисуем правую вертикальную линию-стенку
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


//Функция которая двигает и рисует
enum {END, WALL,  PLUS, MOVE};
int MoveSnake(Game &g)
{
	int & n = g.cobra.PCount;
	COORD head = g.cobra.t[n - 1]; //голова
	COORD tail = g.cobra.t[0]; //хвост
	COORD next;
	next.X = head.X + g.dx;
	next.Y = head.Y + g.dy; //проверка следующей точки по направлению
	
    if(next.X < 3 || next.Y < 3 || next.X > 60 || next.Y > 23)//не уперлась ли в стену?
		return WALL;
		
	if(n > 4)
	{
		for(int i = 0; i < n; i++)
			if(next.X == g.cobra.t[i].X && next.Y == g.cobra.t[i].Y) //не наехали ли на себя?
				return END;
	}
	
	if(next.X == g.apple.X && next.Y == g.apple.Y)
	{
		COORD*temp = new COORD[ ++n ]; //новый масив больший на 1
		for(int i = 0; i < n; i++)
			temp[i] = g.cobra.t[i]; //перекопируем
		temp[n - 1] = next; //добавляем одну
		delete [] g.cobra.t;
		g.cobra.t = temp;
		
		SetConsoleCursorPosition(hConsole,head);
		SetConsoleTextAttribute(hConsole, 0x0a); //закрашываем яблоко которое сели 
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
	SetConsoleCursorPosition(hConsole,tail);//закрашиваем хвост
	printf(" ");
	
	SetConsoleCursorPosition(hConsole,head);
	SetConsoleTextAttribute(hConsole, 0x0a);//красим хвост змеи в зелений цвет
	printf("*");
	SetConsoleCursorPosition(hConsole,next);
	SetConsoleTextAttribute(hConsole,0x0f); //красим курсор в белый цвет (голову змеи) 
	printf("%c",1);
	
	return MOVE;
}

int IntroWindow()
{
        GotoXY(3,10); //Интруха
	printf("Snake game. (Press Enter...)");
	getch();
	return 0;
}

int main()
{

    
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //получаем дескриптор консоли
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
		while(!kbhit()) //ждет пока нажмем
		{
			if(Pause==true)
			{
				Sleep(1); 
				continue;
			}
			
			switch (MoveSnake(g))//движение
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
                    GotoXY(24,1); cout << "U win!" << endl; //Вы выиграли
					getch();
					return(0);
				}
				break;
				
			case WALL:
				
			case END:
				GotoXY(23,1); printf("U loose!"); //Вы проиграли, ХА ХА ХА
				getch();
				break;
			}
			
			Sleep(g.pause); //Задержка
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
