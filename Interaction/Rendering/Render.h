#pragma once
#include "../../Basis/Console/Console.h"
#include "../../Game/GameArea/GameArea.h"
#include "../../Game/Shape/Shape.h"
#include <mutex>

static class Render
{
private:
	static std::mutex mtx;
	static bool isCollision(Shape& shape, unsigned char index);
public:
	static void move(Shape& shape);
	static void print(Shape& shape);
	static void clear(Shape& shape);
	static void fillLine(const char WIDTH_AREA, char y);
	static void printLine(GameArea& gamearea, char y);
	static void printLine(GameArea& gamearea, char y,unsigned char color);
};

