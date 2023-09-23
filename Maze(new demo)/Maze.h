#include <iostream>
#include <ctime> 
#include <Windows.h> 
#include <conio.h> 
#include <string>//подключил библиотеки


using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position;
COORD coins_info;
COORD money_info;
COORD health_info;//добавил все COORD данные


CONSOLE_CURSOR_INFO info;
const int width = 60; 
const int height = 15;//информация о размере лаберинта

//для гг
void SetCursor(int x, int y, int color, string text)
{
    
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(h, position);
    SetConsoleTextAttribute(h, color);
    cout << text;
}

//для цветов 
void TextColor(int color,string mass)
{
    SetConsoleTextAttribute(h, color);
    SetConsoleCursorPosition(h, position);
    cout << mass;
}

//для аптечки монет и тд
void Text(int color,string txt)
{
    SetConsoleTextAttribute(h, color);
    cout << txt;
}

//для монет
void Coins(int x,int y,int color,string text)
{

    
    coins_info.X = width + x;
    coins_info.Y = y;
    SetConsoleCursorPosition(h, coins_info); 
    SetConsoleTextAttribute(h, color);

    cout << text;

}

//для вывода монет
void CoinsHM(int x,int y,int color,string text)
{
    money_info.X = width + x;
    money_info.Y = y;
    SetConsoleCursorPosition(h, money_info); 
    SetConsoleTextAttribute(h, color);
    cout << text;
}

//для здоровья
void Health(int x,int y,int color,string text)
{
    health_info.X = width + x;
    health_info.Y = y;
    SetConsoleCursorPosition(h, health_info); 
    SetConsoleTextAttribute(h, color);
    cout << text;
}