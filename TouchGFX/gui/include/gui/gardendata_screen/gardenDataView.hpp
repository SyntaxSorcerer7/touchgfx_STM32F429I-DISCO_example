#ifndef GARDENDATA_VIEW_HPP
#define GARDENDATA_VIEW_HPP

#include <gui_generated/gardendata_screen/gardenDataViewBase.hpp>
#include <gui/gardendata_screen/gardenDataPresenter.hpp>
#include "../info.h"

class gardenDataView : public gardenDataViewBase
{
public:
    gardenDataView();
    virtual ~gardenDataView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void updateValues(const SensorRecord& rec);
    virtual void scrollList1UpdateItem(historyRecord& item, int16_t itemIndex);
private:
    void insertNewHistoryValue(const SensorRecord& rec);
protected:
};

#endif // GARDENDATA_VIEW_HPP
