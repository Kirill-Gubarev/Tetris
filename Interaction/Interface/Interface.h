#pragma once
#include "../Rendering/Render.h"
static class Interface
{
private:
	static Shape* nextShape;
	static Shape* reserveShape;
	static int score;
	static unsigned char WIDTH;
	static unsigned char HEIGHT;
public:
	static unsigned char colorText;
	static void swapNextShapes(Shape*& shape);
	static void swapReserveShapes(Shape*& shape);
	static void start(unsigned char WIDTH_AREA, unsigned char HEIGHT_AREA);
	static void end();
	static void inline drawInterface();
	static void drawText();
	static void drawScore();
	static void drawGame(bool game = true);
	static void addScore(int value);
};