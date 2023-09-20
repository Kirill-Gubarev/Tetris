#include "GameArea.h"
GameArea::GameArea(const unsigned char WIDTH_AREA = 10,const unsigned char HEIGHT_AREA = 20)
{
	this->HEIGHT_AREA = HEIGHT_AREA;
	this->WIDTH_AREA = WIDTH_AREA;
	area = new char* [this->HEIGHT_AREA];
	for (size_t i = 0; i < this->HEIGHT_AREA; i++)
	{
		area[i] = new char[this->WIDTH_AREA];
	}
	clear();
}
GameArea::~GameArea()
{
	for (size_t i = 0; i < HEIGHT_AREA; i++)
	{
		delete[] area[i];
	}
	delete[] area;
}
void GameArea::clear()
{
	for (size_t x = 0; x < WIDTH_AREA; x++)
	{
		for (size_t y = 0; y < HEIGHT_AREA; y++)
		{
			this->area[y][x] = 0;
		}
	}
}
unsigned char GameArea::getHeightArea()
{
	return HEIGHT_AREA;
}
unsigned char GameArea::getWidthArea()
{
	return WIDTH_AREA;
}

bool GameArea::removeLine(char y)
{
	if (isFilled(y))
	{
		for (size_t i = 0; i < WIDTH_AREA; i++)
		{
			area[y][i] = 0;
		}
		return true;
	}
	return false;
}
void GameArea::swapLine(char y)
{
	for (unsigned int i = y - 1; 0 < i; i--)
	{
		if (!isNull(i))
		{
			char* temp = area[i + 1];
			area[i + 1] = area[i];
			area[i] = temp;
		}
		else
		{
			return;
		}
	}
}

bool GameArea::isNull(unsigned char y)
{
	for (size_t i = 0; i < WIDTH_AREA; i++)
	{
		if (area[y][i] != 0)
			return false;
	}
	return true;
}
bool GameArea::isFilled(unsigned char y)
{
	for (size_t i = 0; i < WIDTH_AREA; i++)
	{
		if (area[y][i] == 0)
		{
			return false;
		}
	}
	return true;
}