#include <gui/gardendata_screen/gardenDataView.hpp>
//#include "info.h"



gardenDataView::gardenDataView()
{

}

void gardenDataView::setupScreen()
{
    gardenDataViewBase::setupScreen();
}

void gardenDataView::tearDownScreen()
{
    gardenDataViewBase::tearDownScreen();
}

void gardenDataView::updateValues(const SensorRecord& rec){
	if(rec.sensorId==0){
		Unicode::snprintfFloat(tempTextBuffer, TEMPTEXT_SIZE, "%3.1f", rec.value);
		tempText.invalidate();
	} else if (rec.sensorId==1){
		Unicode::snprintfFloat(humidityTextBuffer, HUMIDITYTEXT_SIZE, "%3.1f", rec.value);
		humidityText.invalidate();
		progressWater.setValue(rec.value);
	} else if (rec.sensorId==2){
		Unicode::snprintfFloat(presTextBuffer, PRESTEXT_SIZE, "%3.1f", rec.value);
		presText.invalidate();
	}
	insertNewHistoryValue(rec);
}

void gardenDataView::insertNewHistoryValue(const SensorRecord& rec){
	touchgfx::DrawableListItems<historyRecord, 8> *targetList = NULL;

	switch(rec.sensorId){
	case 0:
		targetList = &tempHistoryListItems;
		break;
	case 1:
		targetList = &humidityHistoryListItems;
		break;
	case 2:
		targetList = &pressureHistoryListItems;
		break;
	default:
		return;
	}

	int numberOfItems = targetList->getNumberOfDrawables();

	SensorRecord tmp = rec;
	SensorRecord tmpNext;

	//Verschiebe alle Einträge in der Liste um eins nach unten
	for(int i=0; i<numberOfItems;i++){
		tmpNext = targetList->operator [](i).getValue();
		targetList->operator [](i).updateValue(tmp);
		tmp = tmpNext;
	}
}

void gardenDataView::scrollList1UpdateItem(historyRecord& item, int16_t itemIndex){


}
