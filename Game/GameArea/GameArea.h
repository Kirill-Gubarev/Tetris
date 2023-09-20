#pragma once
class GameArea
{
private:
	unsigned char HEIGHT_AREA;
	unsigned char WIDTH_AREA;
public:
	bool isNull(unsigned char y);
	bool isFilled(unsigned char y);
	char** area;
	GameArea(const unsigned char WIDTH_AREA,const unsigned char HEIGHT_AREA);
	~GameArea();
	void clear();
	void swapLine(char y);
	bool removeLine(char y);
	unsigned char getHeightArea();
	unsigned char getWidthArea();
};