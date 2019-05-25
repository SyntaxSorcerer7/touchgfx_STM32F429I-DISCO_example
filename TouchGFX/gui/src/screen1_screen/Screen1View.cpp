#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{
}

void Screen1View::foo(){
	count++;
	if(count>9){
		count = 0;
	}

	if(count>60){
		count = 0;
	}

	Unicode::snprintf(txtBuffer, 1, "%d", count);

    tempText.setWildcard(txtBuffer);
    tempText.invalidate();
}


void Screen1View::setupScreen()
{
	Screen1ViewBase::setupScreen();
}



void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
