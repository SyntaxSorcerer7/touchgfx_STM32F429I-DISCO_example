/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef HISTORYRECORD_BASE_HPP
#define HISTORYRECORD_BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>

class historyRecordBase : public touchgfx::Container
{
public:
    historyRecordBase();
    virtual ~historyRecordBase() {}

    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box box1;
    touchgfx::TextAreaWithOneWildcard dateTxt;
    touchgfx::TextAreaWithTwoWildcards valueTxt;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;

    /*
     * Wildcard Buffers
     */
    static const uint16_t DATETXT_SIZE = 20;
    touchgfx::Unicode::UnicodeChar dateTxtBuffer[DATETXT_SIZE];
    static const uint16_t VALUETXTBUFFER1_SIZE = 4;
    touchgfx::Unicode::UnicodeChar valueTxtBuffer1[VALUETXTBUFFER1_SIZE];
    static const uint16_t VALUETXTBUFFER2_SIZE = 4;
    touchgfx::Unicode::UnicodeChar valueTxtBuffer2[VALUETXTBUFFER2_SIZE];

private:

};

#endif // HISTORYRECORD_BASE_HPP