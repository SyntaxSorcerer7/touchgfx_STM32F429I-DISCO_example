#include <gui/gardendata_screen/gardenDataView.hpp>
#include <gui/gardendata_screen/gardenDataPresenter.hpp>

gardenDataPresenter::gardenDataPresenter(gardenDataView& v)
    : view(v)
{
}

void gardenDataPresenter::activate()
{

}

void gardenDataPresenter::deactivate()
{

}

void gardenDataPresenter::valueChanged(const SensorRecord& rec){
	view.updateValues(rec);
}
