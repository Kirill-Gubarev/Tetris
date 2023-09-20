#include "Console.h"


HANDLE Console::handle = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Console::coord = { 0,0 };
CONSOLE_CURSOR_INFO Console::cursor{ 100 };
void Console::setColor(unsigned char backGroundColor, unsigned char foreGroundColor)
{
	SetConsoleTextAttribute(handle, (backGroundColor << 4) | foreGroundColor);
}
void Console::SetCursorVisible(bool b)
{
	cursor.bVisible = b;
	SetConsoleCursorInfo(handle, &cursor);
}
void Console::SetCursorPosition(unsigned char x, unsigned char y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
}
void Console::Cell(unsigned char x, unsigned char y)
{
	SetCursorPosition(x * INTERVAL, y);
	std::cout << (unsigned char)219 << (unsigned char)219 << std::endl;
}