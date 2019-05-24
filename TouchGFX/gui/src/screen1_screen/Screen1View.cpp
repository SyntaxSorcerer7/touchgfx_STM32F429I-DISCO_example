#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{
}

void Screen1View::foo(){
	if(count > 30){
		txtBuffer[0] = '3';
	} else {
		txtBuffer[0] = '2';
	}

	if(count>60){
		count = 0;
	}

    tempText.setWildcard(txtBuffer);
    tempText.invalidate();
}


void Screen1View::setupScreen()
{
	Screen1ViewBase::setupScreen();
    foo();
}



void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
