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
    	count++;
    	foo();
    }
    void helloButtonWasClicked(){
    	count++;
    	foo();
    }
protected:
    int count = 0;
    Unicode::UnicodeChar txtBuffer[1];
};

#endif // SCREEN1_VIEW_HPP
