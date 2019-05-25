#ifndef SCREEN1_VIEW_HPP
#define SCREEN1_VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void foo();
    void handleTickEvent(){
    	//foo();
    }
    void helloButtonWasClicked(){
    	foo();
    }
protected:
    int count = 1;
    Unicode::UnicodeChar txtBuffer[1] = { 2 };
};

#endif // SCREEN1_VIEW_HPP
