#include <gui/containers/historyRecord.hpp>
#include <time.h>

historyRecord::historyRecord()
{

}

void historyRecord::initialize()
{
    historyRecordBase::initialize();
}

void historyRecord::updateValue(const SensorRecord& record){

	#ifndef SIMULATOR

	this->record = record;
	Unicode::snprintfFloat(valueTxtBuffer1, VALUETXTBUFFER1_SIZE, "%3.1f", record.value);
	switch(record.sensorId){
	case 0:
		Unicode::snprintf(valueTxtBuffer2, VALUETXTBUFFER2_SIZE, " °C");
		break;
	case 1:
		Unicode::snprintf(valueTxtBuffer2, VALUETXTBUFFER2_SIZE, " % ");
		break;
	case 2:
		Unicode::snprintf(valueTxtBuffer2, VALUETXTBUFFER2_SIZE, "kPa");
		break;
	}
	char buff[16];
	tm t;
	localtime_r(&record.timestamp, &t);
	strftime(buff, 16, "%d.%m. %H:%M:%S", &t);
	Unicode::snprintf(dateTxtBuffer, DATETXT_SIZE, buff);
	dateTxt.invalidate();
	valueTxt.invalidate();

	#endif
}

SensorRecord historyRecord::getValue(){
	return this->record;
}

