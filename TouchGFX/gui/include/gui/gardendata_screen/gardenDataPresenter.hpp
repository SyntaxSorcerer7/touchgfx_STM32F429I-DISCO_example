#ifndef GARDENDATA_PRESENTER_HPP
#define GARDENDATA_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>
#include "../info.h"

using namespace touchgfx;

class gardenDataView;

class gardenDataPresenter : public Presenter, public ModelListener
{
public:

    gardenDataPresenter(gardenDataView& v);
    virtual void valueChanged(const SensorRecord& rec);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~gardenDataPresenter() {};

private:
    gardenDataPresenter();

    gardenDataView& view;
};


#endif // GARDENDATA_PRESENTER_HPP
