#include "Render.h"

std::mutex Render::mtx;

void Render::move(Shape& shape)
{
	print(shape);
	clear(shape);
	shape.saveXY();
}
void Render::print(Shape& shape)
{
	mtx.lock();
	Console::setColor(0, shape.color);
	for (unsigned int i = 0; i < SIZE_SHAPE; i++)
	{
		Console::Cell(shape.getBlockX(i), shape.getBlockY(i));
	}
	mtx.unlock();
}
void Render::clear(Shape& shape)
{
	mtx.lock();
	Console::setColor(0, 0);
	for (unsigned int i = 0; i < SIZE_SHAPE; i++)
	{
		if (!isCollision(shape, i))
		{
			Console::Cell(shape.previousBlocksX[i], shape.previousBlocksY[i]);
		}
	}
	mtx.unlock();
}

bool Render::isCollision(Shape& shape, unsigned char index)
{
	bool result = false;
	for (unsigned int i = 0; i < SIZE_SHAPE; i++)
	{
		if (shape.getBlockX(i) == shape.previousBlocksX[index] && shape.getBlockY(i) == shape.previousBlocksY[index])
		{
			result = true;
		}
	}
	return result;
}

void Render::fillLine(const char WIDTH_AREA, char y)
{
	mtx.lock();
	Console::setColor(0, 15);
	for (char i = 0; i < WIDTH_AREA; i++)
	{
		Console::Cell(i, y);
	}
	mtx.unlock();
}
void Render::printLine(GameArea& gamearea, char y)
{
	mtx.lock();
	char WIDTH_AREA = gamearea.getWidthArea();
	for (char x = 0; x < WIDTH_AREA; x++)
	{
		Console::setColor(0, gamearea.area[y][x]);
		Console::Cell(x, y);
	}
	mtx.unlock();
}
void Render::printLine(GameArea& gamearea, char y, unsigned char color)
{
	mtx.lock();
	char WIDTH_AREA = gamearea.getWidthArea();
	Console::setColor(0, color);
	for (char x = 0; x < WIDTH_AREA; x++)
	{
		if (gamearea.area[y][x] != 0)
		{
			Console::Cell(x, y);
		}
	}
	mtx.unlock();
}