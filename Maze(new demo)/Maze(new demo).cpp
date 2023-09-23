#include "Maze.h"
int main()
{
	system("title Maze");
	info.bVisible = false;
	info.dwSize = 100; 
	SetConsoleCursorInfo(h, &info);
	srand(time(0));//генерация СЧ
	//переменные
	int two = 0;//подсчет монет
	int coins = 0;//монетки
	int health = 100;//здоровье
	int money = two;
	int maze[height][width] = {};//двумерный массив
	//двойной цикл
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			maze[y][x] = rand() % 5; //генерим числа от 1 до 5
			//делаем вход и выход
			if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
				maze[y][x] = 1;
			if (x == 0 && y == 2 || x == 1 && y == 2 || x == 2 && y == 2 ||
				x == width - 1 && y == height - 3)
				maze[y][x] = 0;
			//сокращаем кол-во врагов
			if (maze[y][x] == 3)
			{
				int r = rand() % 10; 

				if (r != 0) 
				{
					maze[y][x] = 0; 
				}
			}
			//сокращаем кол-во аптечек
			if (maze[y][x] == 4)
			{
				int a = rand() % 10;
				if (a != 0) 
				{
					maze[y][x] = 0; 
				}
			}
			//считаю кол-во сгенерированных монет
			if (maze[y][x] == 2)
			{
				two++;
			}
			if (maze[y][x] == 0)//коридор
			{
				Text(0, " ");
			}
			else if (maze[y][x] == 1)//стена
			{
				Text(3,"");
				cout << (char)178;
			}
			else if (maze[y][x] == 2)//монетки
			{
				Text(14,".");
			}
			else if (maze[y][x] == 3)//враг
			{
				Text(12,"");
				cout << (char)1;
			}
			else if (maze[y][x] == 4)//аптечка
			{
				Text(9,"+");
	
			}
			else
			{
				cout << maze[y][x];
			}

		}
		cout << "\n";
	}
	//координаты гг
	SetCursor(0, 2, 13, "");
	cout << (char)1;
	// начинаем интерактив (польщователь управляет смайликом с помощью клавиатуры)
	while (true)
	{
		int code = _getch(); 
		if (code == 224) 
		{
			code = _getch();
		}
		// можно стереть смайлик в его текущей позиции
		TextColor(0," ");

		if (code == 77 and maze[position.Y][position.X + 1] != 1) 
		{
			position.X++; 
		}
		else if (code == 75 and maze[position.Y][position.X - 1] != 1)
		{
			position.X--;
		}
		else if (code == 72 and maze[position.Y - 1][position.X] != 1)
		{
			position.Y--;
		}
		else if (code == 80 and maze[position.Y + 1][position.X] != 1)
		{
			position.Y++;
		}
		// показываем смайлик в новых координатах
		TextColor(13, "");
		cout << (char)1;
		//вывожу общее кол-во монет 
		CoinsHM(1, 1, 10, "The number of coins in the gaim : ");
		CoinsHM(35, 1, 10,to_string(two));
		//делаю победу в случае нахождения выхода
		if (position.X == width - 1 and position.Y == height - 3)
		{
			MessageBoxA(0, "You found your way out of the maze!!!!", "You win!!!", MB_OK);
			break;
		}
		//вывожу моенеты
		if (maze[position.Y][position.X] == 2)
		{
			coins++;
			maze[position.Y][position.X] = 0;
			Coins(1,2,14,"Number of coins picked up : ");
			Coins(30, 2, 14, to_string(coins));
		}
		//делаю победу в случае сбора всех монет
		if (coins == two)
		{
			MessageBoxA(0, "You have collected all the coins!!! ", "You win!!!", MB_OK);
		    break;
		}
		//отеимаю здоровье при встрече с врагом и вывожу его
		if (maze[position.Y][position.X] == 3)
		{
			health -= 20;
			maze[position.Y][position.X] = 0;
			Health(1,3,13,"Hit points : ");
			Health(14, 3, 13, to_string(health));
			cout << " ";
		}
		//если здоровье меньше чем 100 и мы подобрали аптечку до добавояю 20хп
		if (maze[position.Y][position.X] == 4 and health < 100)
		{
			health += 20;
			maze[position.Y][position.X] = 0;
			Health(1, 3, 13, "Hit points : ");
			Health(14, 3, 13, to_string(health));
			cout << " ";
		}
		//конец игры если хп=0
		if (health == 0)
		{
			MessageBoxA(0, "You have run out of health!!!!", "You are dead!!!!", MB_OK);
			break;
		}
	}
	//конец игры
	system("cls");//стираем все
	main();//перегенерируем лаберинт
	Sleep(INFINITE);//задержка
}