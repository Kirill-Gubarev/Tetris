#pragma once
#include "../Interface/Interface.h"
#include <conio.h>
#include <thread>
#include <chrono>
class Control
{
public:
	static void start(unsigned char WIDTH_AREA, unsigned char HEIGHT_AREA);
	static void end();
	static void controlShape();
	static void turnLeft();
	static void turnRight();
	static void moveLeft();
	static void moveRight();
	static bool fall();
	static bool record();
	static bool nextShape();
	static void reserveShape();
	static void enableCheatMode();
	static void inline runCheatMode(unsigned char key);
private:
	static bool cheatMode;
	static bool reserve;
	static bool lock;
	static Shape* shape;
	static GameArea* gameArea;
	static unsigned char key;

	static unsigned char isFree();
	static bool isBottomFree();
	static bool isRightFree();
	static char isLeftFree();
	static void incrementRotate();
	static void decrementRotate();
};