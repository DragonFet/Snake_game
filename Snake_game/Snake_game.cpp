#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;
int const weight = 60;
int const hight = 19;
int x, y, apple_x, apple_y;
int score;
int g;
int tale_x[100], tale_y[100];
int tails_apple=0;
int control_score_for_print = 0;
enum movement { STOP = 0, RIGHT, LEFT, UP, DOWN};
movement trafic;
bool game_status_end;
struct date
{
	int score_2;
	string namesurname;;
	

};
void begin()
{
	game_status_end =false;
	 trafic= STOP;
	 x = weight/2 -1;
	 y = hight / 2 -1;
	 int weights_apple, hight_apple;
	 weights_apple = weight - 5;
	 hight_apple = hight - 5;
	 apple_x = rand()% weights_apple;
	 apple_y = rand()% hight_apple;
	 score = 0;
}
void Draw()
{
	g = rand() % 10;
	system("cls");
	int a = 120;
	if (a==10)
	{
		cout << '\n';
		if (control_score_for_print == 1)
		{
			cout << "SCORE " << score << " " << "YAMI" << endl;
			control_score_for_print = 0;
			
		}
		else cout << "SCORE " << score << endl;
	}
	else {
		cout << '\n';
		if (control_score_for_print == 1)
		{
			cout << "SCORE " << score << " " << "YAMI" << endl;
			control_score_for_print = 0;
			a = a - 10;
		}
		else cout << "SCORE " << score << endl;
	}
	
	
	for (int i = 0; i < weight + 1; i++)
	{
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), g);
		while (g == 0)
		{
			g = rand() % 10;
		}
		cout << "#";
	}
		
	cout << endl;
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < weight; j++)
		{
			if (j==0 ||j==weight-1)
				
				cout << "#";
			if (i == y && j == x)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), g);
				while (g==0)
				{
					g = rand() % 10;
				}
				cout << "*";
			}
			else
				if (i == apple_y && j == apple_x)
				{
					cout << "0";
				}
			
				else {
					bool print = false;
					for (int k = 0; k < tails_apple; k++)
					{

						if (tale_x[k]==j&& tale_y[k]==i)
						{
							print = true;
							cout << "*";
						}
					}
					if (print==false)
					{
						cout << " ";
					}
					
				}
		}
		cout << endl;
	}
	
	for (int i = 0; i < weight + 1; i++)
		cout << "#";
	cout << endl;
	Sleep(a);
	
}
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			trafic = LEFT;
			break;
		case 'w':
			trafic = UP;
			break;
		case'd':
			trafic = RIGHT;
			break;
		case 's':
			trafic = DOWN;
			break;
		case 'f':
				game_status_end = true;
				break;
		}
	}
}
void core()
{
	int pref_x= tale_x[0];
	int pref_y = tale_y[0];
	int pref_2x, pref_2y;
	tale_x[0] = x;
	tale_y[0] = y;
	for (int  i = 1; i < tails_apple; i++)
	{
		pref_2x = tale_x[i];
		pref_2y = tale_y[i];
		tale_x[i] = pref_x;
		tale_y[i] = pref_y;
		pref_x = pref_2x;
		pref_y = pref_2y;
	}
	switch (trafic)
	{
		case LEFT:
			x--;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		case RIGHT:
			x++;
			break;
		

	}
	if (x>weight||x<0||y>hight||y<0)
	{
		game_status_end = true;
	}
	for (int i = 0; i < tails_apple; i++)
	{
		if (tale_x[i]==x && tale_y[i]==y)
		{
			game_status_end = true;
		}
	}
	if (x==apple_x&&y==apple_y)
	{
		score++;
		control_score_for_print = 1;
		apple_x = rand() % weight + 1;
		apple_y = rand() % hight + 1;
		tails_apple++;
	}
}
int main()
{
	date* base = new date[10000];
	string solution;
	int g;
	int vallue_games = 0;
	int number;
	cout << '\n';
	cout << "PIN_11_PRODUCTION INK PRESENT by MrGoblin" << endl;
	cout << "SNAKE v2.0 'No back home '" << endl;
	cout << "__---__---__" << endl;
	cout << "==_+_==_+_==" << endl;
	cout << "  \\ |  | /" << endl;
	cout << "   \\____/" << endl;
	cout << "Main Menu" << endl;
	cout << "Input 'Exit' if you scared else tab  f for run out in game " << endl;
	cout << "Please input 'Play' for start gamesssss....." << endl;
	cout << "Input 'Lider' for watch Lider Bord" << endl;
	cout << "Input 'Contact' if you want start game and  record your progresssssss...."<<endl;
	while ((solution != "Exit") || (solution != "exit"))
	{
		cin >> solution;
		int solution_2;
		if (solution=="Exit")
		{
			solution_2 = 0;
			if (solution == "Lider")
			{
				solution_2 = 2;
				if (solution == "Play")
				{
					solution_2 = 1;
					if (solution == "Contact")
					{
						solution_2 = 3;
					}
				}
			}
		}
		switch (solution_2)
		{
		case 0:
			solution = "Exit";
			break;
		case 1:
			{
				begin();
				while (!game_status_end)
				{
					Draw();
					input();
					core();
				}
				cout << "Please input your Name and Surname";
				string name, surname;
				cin>>name>>surname;
				base[number].namesurname = name + " " + surname;
				base[number].score_2 = score;
				score = 0;
				name = " ";
				surname = " ";
				vallue_games++;
				number++;
			}
		case 2:
			{
				if (vallue_games>0)
				{
					cout << "Lider____board" << endl;
					for (int i = 0; i < number; i++)
					{
						cout<<"Name and Surname :>>>"<< base[i].namesurname <<'\t'<<"Score"<<base[i].score_2;
						
					}
				}
			}

		case 3:
			{
			solution = "Play";

			}

		}
	}
	srand(time(0));

	


}