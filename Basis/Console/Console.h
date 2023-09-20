#pragma once
#include <Windows.h>
#include <iostream>
#define INTERVAL 2
class Console
{
private:
	static HANDLE handle;
	static COORD coord;
	static CONSOLE_CURSOR_INFO cursor;
public:
	static void SetCursorVisible(bool b);
	static void setColor(unsigned char backGroundColor, unsigned char foreGroundColor);
	static void SetCursorPosition(unsigned char x, unsigned char y);
	static void Cell(unsigned char x, unsigned char y);
};