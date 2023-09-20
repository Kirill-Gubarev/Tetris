#include "Shape.h"
#include <iostream>
#include <ctime>

unsigned char Shape::center = 5;


Shape::Shape()
{
	overWrite(); 
	setXYCenter();
}

void Shape::start(unsigned char WIDTH_AREA)
{
	srand(time(nullptr));
	center = WIDTH_AREA / 2;
}

char Shape::getBlockX(unsigned char index)
{
	switch (rotate)
	{
	case 0: return blocksX[index] + X; break;
	case 1: return blocksY[index] + X; break;
	case 2: return -blocksX[index] + X; break;
	case 3: return -blocksY[index] + X; break;
	}
}
char Shape::getBlockY(unsigned char index)
{
	switch (rotate)
	{
	case 0: return  blocksY[index] + Y; break;
	case 1: return  -blocksX[index] + Y; break;
	case 2: return  -blocksY[index] + Y; break;
	case 3: return  blocksX[index] + Y; break;
	}
}

void Shape::saveXY()
{
	for (unsigned char i = 0; i < SIZE_SHAPE; i++)
	{
		previousBlocksX[i] = getBlockX(i);
		previousBlocksY[i] = getBlockY(i);
	}
}
void Shape::setXYCenter()
{
	X = center;
	Y = 1;
}
void Shape::setXY(unsigned char x, unsigned char y)
{
	X = x;
	Y = y;
}

void Shape::overWrite()
{
	setType(std::rand() % 7);
}
void Shape::setType(unsigned char type)
{
	rotate = 0;
	switch (type)
	{
	case 0://O
		color = (unsigned char)ConsoleColor::DarkYellow;
		numOfDir = 1;
		blocksX[0] = 0;
		blocksX[1] = 1;
		blocksX[2] = 0;
		blocksX[3] = 1;

		blocksY[0] = 0;
		blocksY[1] = 0;
		blocksY[2] = 1;
		blocksY[3] = 1;
		break;
	case 1://I
		color = (unsigned char)ConsoleColor::DarkMagenta;
		numOfDir = 2;
		blocksX[0] = -2;
		blocksX[1] = -1;
		blocksX[2] = 0;
		blocksX[3] = 1;

		blocksY[0] = 0;
		blocksY[1] = 0;
		blocksY[2] = 0;
		blocksY[3] = 0;
		break;
	case 2://S
		color = (unsigned char)ConsoleColor::DarkBlue;
		numOfDir = 2;
		blocksX[0] = -1;
		blocksX[1] = 0;
		blocksX[2] = 0;
		blocksX[3] = 1;

		blocksY[0] = 1;
		blocksY[1] = 1;
		blocksY[2] = 0;
		blocksY[3] = 0;
		break;
	case 3://Z
		color = (unsigned char)ConsoleColor::DarkRed;
		numOfDir = 2;
		blocksX[0] = -1;
		blocksX[1] = 0;
		blocksX[2] = 0;
		blocksX[3] = 1;

		blocksY[0] = 0;
		blocksY[1] = 0;
		blocksY[2] = 1;
		blocksY[3] = 1;
		break;
	case 4://L
		color = (unsigned char)ConsoleColor::Red;
		numOfDir = 4;
		blocksX[0] = -1;
		blocksX[1] = 0;
		blocksX[2] = 0;
		blocksX[3] = 0;

		blocksY[0] = -1;
		blocksY[1] = -1;
		blocksY[2] = 0;
		blocksY[3] = 1;
		break;
	case 5://J
		color = (unsigned char)ConsoleColor::Blue;
		numOfDir = 4;
		blocksX[0] = 0;
		blocksX[1] = 0;
		blocksX[2] = 0;
		blocksX[3] = 1;

		blocksY[0] = -1;
		blocksY[1] = 0;
		blocksY[2] = 1;
		blocksY[3] = -1;
		break;
	case 6://T
		color = (unsigned char)ConsoleColor::DarkGreen;
		numOfDir = 4;
		blocksX[0] = -1;
		blocksX[1] = 0;
		blocksX[2] = 0;
		blocksX[3] = 1;

		blocksY[0] = 0;
		blocksY[1] = 0;
		blocksY[2] = 1;
		blocksY[3] = 0;
		break;
	}
}