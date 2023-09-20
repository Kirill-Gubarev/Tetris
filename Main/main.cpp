#include "../Interaction/Control/Control.h"
#define HEIGHT_AREA 20
#define WIDTH_AREA 10
int main()
{
	Control::start(WIDTH_AREA, HEIGHT_AREA);
	std::thread thr(Control::controlShape);

	do
	{
		do
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(400));
		} while (Control::fall());
	} while (Control::record());

	thr.join();
	Control::end();
	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	return 0;
}