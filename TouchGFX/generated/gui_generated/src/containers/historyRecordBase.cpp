/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/historyRecordBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

historyRecordBase::historyRecordBase()
{
    setWidth(228);
    setHeight(30);

    box1.setPosition(1, 3, 226, 25);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    box1.setAlpha(151);

    dateTxt.setPosition(4, 6, 145, 19);
    dateTxt.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    dateTxt.setLinespacing(0);
    Unicode::snprintf(dateTxtBuffer, DATETXT_SIZE, "%s", TypedText(T_SINGLEUSEID95).getText());
    dateTxt.setWildcard(dateTxtBuffer);
    dateTxt.setTypedText(TypedText(T_SINGLEUSEID94));

    valueTxt.setPosition(153, 6, 70, 19);
    valueTxt.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    valueTxt.setLinespacing(0);
    Unicode::snprintf(valueTxtBuffer1, VALUETXTBUFFER1_SIZE, "%s", TypedText(T_SINGLEUSEID103).getText());
    valueTxt.setWildcard1(valueTxtBuffer1);
    Unicode::snprintf(valueTxtBuffer2, VALUETXTBUFFER2_SIZE, "%s", TypedText(T_SINGLEUSEID98).getText());
    valueTxt.setWildcard2(valueTxtBuffer2);
    valueTxt.setTypedText(TypedText(T_SINGLEUSEID96));

    line1.setPosition(149, 5, 3, 22);
    line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    line1.setPainter(line1Painter);
    line1.setStart(1, 1);
    line1.setEnd(1, 20);
    line1.setLineWidth(1);
    line1.setLineEndingStyle(Line::ROUND_CAP_ENDING);

    add(box1);
    add(dateTxt);
    add(valueTxt);
    add(line1);
}

void historyRecordBase::initialize()
{
	
}
