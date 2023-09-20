#include "Interface.h"
#define SIZE_PANEL 7

unsigned char Interface::colorText = (unsigned char)ConsoleColor::White;
Shape* Interface::nextShape = nullptr;
Shape* Interface::reserveShape = nullptr;
int Interface::score = 0;
unsigned char Interface::WIDTH = 0;
unsigned char Interface::HEIGHT = 0;
void Interface::start(unsigned char WIDTH_AREA, unsigned char HEIGHT_AREA)
{
	WIDTH = WIDTH_AREA;
	HEIGHT = HEIGHT_AREA;
	nextShape = new Shape();

	(*nextShape).setXY(WIDTH + 4, 2);
	Render::move(*nextShape);

	Console::SetCursorVisible(false);
	drawInterface();
}
void Interface::end()
{
	delete nextShape;
	if (reserveShape != nullptr)
	{
		delete reserveShape;
	}
}
void Interface::swapNextShapes(Shape*& shape)
{
	Shape* tempShape = shape;
	shape = nextShape;
	nextShape = tempShape;

	(*nextShape).setXY(WIDTH + 4, 2);
	(*shape).setXYCenter();

	(*nextShape).overWrite();

	Render::clear(*shape);
	(*shape).saveXY();

	Render::print(*nextShape);
	Render::print(*shape);

	(*nextShape).saveXY();
}
void Interface::swapReserveShapes(Shape*& shape)
{
	if (reserveShape == nullptr)
	{
		reserveShape = new Shape();
		swapNextShapes(reserveShape);
	}
	Shape* tempShape = shape;
	shape = reserveShape;
	reserveShape = tempShape;

	(*shape).setXYCenter();
	(*reserveShape).setXY(WIDTH + 4, 8);

	Render::clear(*shape);
	Render::clear(*reserveShape);

	(*shape).saveXY();

	(*reserveShape).rotate = 0;

	Render::print(*reserveShape);
	Render::print(*shape);

	(*reserveShape).saveXY();
}

void Interface::drawInterface()
{
	Console::setColor(0, (unsigned char)ConsoleColor::DarkGray);
	for (unsigned char i = 0; i <= HEIGHT; i++)
	{
		Console::Cell(WIDTH, i);
	}
	for (unsigned char i = 0; i < WIDTH; i++)
	{
		Console::Cell(i, HEIGHT);
	}
	for (unsigned char i = 0; i < SIZE_PANEL; i++)
	{
		Console::Cell(WIDTH + i, SIZE_SHAPE + 1);
	}
	for (unsigned char i = 0; i < SIZE_PANEL; i++)
	{
		Console::Cell(WIDTH + i, (SIZE_SHAPE + 1) * 2 + 1);
	}
	drawText();
}
void Interface::drawText()
{
	Console::setColor(0, colorText);
	Console::SetCursorPosition((WIDTH + 1) * 2, 0);
	std::cout << "Next" << std::endl;
	Console::SetCursorPosition((WIDTH + 1) * 2, SIZE_SHAPE + 2);
	std::cout << "Reserve" << std::endl;
	Console::SetCursorPosition((WIDTH + 1) * 2, (SIZE_SHAPE + 2) * 2);
	std::cout << "Score" << std::endl;
	drawScore();
	Console::SetCursorPosition((WIDTH + 1) * 2, (SIZE_SHAPE + 2) * 2 + 2);
	std::cout << "Game: " << std::endl;
	drawGame();
}
void Interface::drawScore()
{
	Console::setColor(0, colorText);
	Console::SetCursorPosition((WIDTH + 1) * 2, (SIZE_SHAPE + 2) * 2 + 1);
	std::cout << score << std::endl;
}
void Interface::addScore(int value)
{
	score += value;
}
void Interface::drawGame(bool game)
{
	Console::SetCursorPosition((WIDTH + 1) * 2 + 6, (SIZE_SHAPE + 2) * 2 + 2);
	if (game)
	{
		Console::setColor(0,(unsigned char) ConsoleColor::Green);
	}
	else
	{
		Console::setColor(0, (unsigned char)ConsoleColor::DarkRed);
	}
	std::cout << std::boolalpha << game << std::endl;
}