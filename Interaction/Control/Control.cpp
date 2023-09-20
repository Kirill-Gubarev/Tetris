#include "Control.h"

bool Control::cheatMode = false;
bool Control::reserve = false;
bool Control::lock = false;
unsigned char Control::key = 0;
Shape* Control::shape = nullptr;
GameArea* Control::gameArea = nullptr;
void Control::start(unsigned char WIDTH_AREA, unsigned char HEIGHT_AREA)
{
	Shape::start(WIDTH_AREA);
	Interface::start(WIDTH_AREA, HEIGHT_AREA);

	shape = new Shape;
	gameArea = new GameArea(WIDTH_AREA, HEIGHT_AREA);

}
void Control::end()
{
	delete shape;
	delete gameArea;
	Interface::end;
}
void Control::controlShape()
{
	while (key != 27)
	{
		if (!lock)
		{
			if (_kbhit())
			{
				key = _getch();
				switch (key)
				{
				case ' ':
					reserveShape();
					break;
				case 'q':
					turnLeft();
					break;
				case 'e':
					turnRight();
					break;
				case 'a':
					moveLeft();
					break;
				case 'd':
					moveRight();
					break;
				case 's':
					fall();
					break;
				case 'M':
					enableCheatMode();
					break;
				default:
					runCheatMode(key);
				}
			}
			Render::move(*shape);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}
	unsigned char HEIGHT_AREA = (*gameArea).getHeightArea();
	for (unsigned char i = HEIGHT_AREA - 1; 0 < i; i--)
	{
		Render::printLine(*gameArea, i, (unsigned char)ConsoleColor::DarkGray);
	}
	(*shape).color = (unsigned char)ConsoleColor::DarkGray;
	Render::print(*shape);
	Interface::drawGame(false);
}

void Control::enableCheatMode()
{
	cheatMode = true;
	Interface::colorText = (unsigned char)ConsoleColor::Magenta;
	Interface::drawText();
}
void Control::runCheatMode(unsigned char key)
{
	if (cheatMode)
	{
		switch (key)
		{
		case '1':
			(*shape).setXYCenter();
			(*shape).setType(0);
			break;
		case '2':
			(*shape).setXYCenter();
			(*shape).setType(1);
			break;
		case '3':
			(*shape).setXYCenter();
			(*shape).setType(2);
			break;
		case '4':
			(*shape).setXYCenter();
			(*shape).setType(3);
			break;
		case '5':
			(*shape).setXYCenter();
			(*shape).setType(4);
			break;
		case '6':
			(*shape).setXYCenter();
			(*shape).setType(5);
			break;
		case '7':
			(*shape).setXYCenter();
			(*shape).setType(6);
			break;
		}
	}
}

bool Control::record()
{
	lock = true;
	unsigned char color = (*shape).color;
	for (unsigned char i = 0; i < SIZE_SHAPE; i++)
	{
		(*gameArea).area[(*shape).getBlockY(i)][(*shape).getBlockX(i)] = color;
	}
	for (unsigned char i = 0; i < SIZE_SHAPE; i++)
	{
		char y = (*shape).getBlockY(i);
		unsigned char score = 0;
		unsigned char n = 0;
		while ((*gameArea).removeLine(y))
		{
			Render::fillLine((*gameArea).getWidthArea(), y);
			(*gameArea).swapLine(y);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			unsigned char HEIGHT_AREA = (*gameArea).getHeightArea();
			for (unsigned char j = HEIGHT_AREA - 1; 0 < j; j--)
			{
				Render::printLine(*gameArea, j);
			}
			++n;
			score = (9 + ((*gameArea).getHeightArea() - y))*n;
			Interface::addScore(score);
			Interface::drawScore();
		}
	}
	bool value = Control::nextShape();
	lock = false;
	return value;
}

bool Control::nextShape()
{
	Interface::swapNextShapes(shape);
	reserve = false;
	if (isFree() == 1)
	{
		key = 27;
		return false;
	}
	return true;
}
void Control::reserveShape()
{
	if (!reserve || cheatMode)
	{
		Interface::swapReserveShapes(shape);
		reserve = true;
	}
}

bool Control::fall()
{
	(*shape).Y++;
	if (isFree() == 2)
	{
		return true;
	}
	else
	{
		(*shape).Y--;
		return false;
	}
}

void Control::turnLeft()
{
	incrementRotate();
	switch (isFree())
	{
	case 0:
		if (isBottomFree())
		{
			char c = isLeftFree();
			if (c == 1)
			{
				(*shape).X--;
			}
			else if (isRightFree())
			{
				(*shape).X++;
				if (c == -1)
				{
					(*shape).X++;
				}
			}
			else
			{
				decrementRotate();
			}
		}
		else
		{
			decrementRotate();
		}
		break;
	case 1:
		decrementRotate();
		break;
	}
}
void Control::turnRight()
{
	decrementRotate();
	switch (isFree())
	{
	case 0:
		if (isBottomFree())
		{
			char c = isLeftFree();
			if (c == 1)
			{
				(*shape).X--;
			}
			else if (isRightFree())
			{
				(*shape).X++;
				if (c == -1)
				{
					(*shape).X++;
				}
			}
			else
			{
				incrementRotate();
			}
		}
		else
		{
			incrementRotate();
		}
		break;
	case 1:
		incrementRotate();
		break;
	}
}

void Control::moveLeft()
{
	(*shape).X--;
	if (isFree() != 2)
	{
		(*shape).X++;
	}
}
void Control::moveRight()
{
	(*shape).X++;
	if (isFree() != 2)
	{
		(*shape).X--;
	}
}



unsigned char Control::isFree()
{
	for (size_t i = 0; i < SIZE_SHAPE; i++)
	{
		if ((*shape).getBlockY(i) >= (*gameArea).getHeightArea() || (*shape).getBlockX(i) >= (*gameArea).getWidthArea() || (*shape).getBlockX(i) < 0)
		{
			return 0;
		}
		else if ((*gameArea).area[(*shape).getBlockY(i)][(*shape).getBlockX(i)] != 0)
		{
			return 1;
		}
	}
	return 2;
}

bool Control::isBottomFree()
{
	for (unsigned char i = 0; i < SIZE_SHAPE; i++)
	{
		if ((*shape).getBlockY(i) >= (*gameArea).getHeightArea())
		{
			return false;
		}
	}
	return true;
}
bool Control::isRightFree()
{
	char c = 0;
	for (unsigned char i = 0; i < SIZE_SHAPE; i++)
	{
		if ((*shape).getBlockX(i) >= (*gameArea).getWidthArea())
		{
			return false;
		}
	}
	return true;
}
char Control::isLeftFree()
{
	for (unsigned char i = 0; i < SIZE_SHAPE; i++)
	{
		char c = (*shape).getBlockX(i);
		if (c < 0)
		{
			if (c < -1)
			{
				return -1;
			}
			return 0;
		}
	}
	return 1;
}

void Control::incrementRotate()
{
	(*shape).rotate++;
	(*shape).rotate %= (*shape).numOfDir;
}
void Control::decrementRotate()
{
	(*shape).rotate--;
	(*shape).rotate %= (*shape).numOfDir;
}
