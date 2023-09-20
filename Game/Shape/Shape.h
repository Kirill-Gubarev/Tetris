#pragma once
#include "../../Basis/Enums/Enums.h"
#define SIZE_SHAPE 4
class Shape
{
public:
	Shape();
	void overWrite();
	void setType(unsigned char type);
	void setXY(unsigned char x, unsigned char y);
	void setXYCenter();
	void saveXY();
	char getBlockX(unsigned char index);
	char getBlockY(unsigned char index);
	char X;
	char Y;
	char previousBlocksX[SIZE_SHAPE]{};
	char previousBlocksY[SIZE_SHAPE]{};
	unsigned char rotate = 0;
	unsigned char numOfDir = 0;
	static void start(unsigned char WIDTH_AREA);
	unsigned char color;
private:
	static unsigned char center;
	char blocksX[SIZE_SHAPE];
	char blocksY[SIZE_SHAPE];
};

