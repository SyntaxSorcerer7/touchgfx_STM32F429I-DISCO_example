#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include "cmsis_os.h"

extern osPoolId mpool;
extern osMessageQId queue;
#endif

Model::Model() :
		modelListener(0) {

}

#ifndef SIMULATOR
void Model::readQueue() {
	osEvent evt;
	do {
		SensorRecord *rec;
		//Lese alle Nachrichten aus der Queue
		evt = osMessageGet(queue, 1);
		if (evt.status == osEventMessage) {
			rec = (SensorRecord*) evt.value.p;
			modelListener->valueChanged((*rec));
			osPoolFree(mpool, rec);
		}
	} while (evt.status == osEventMessage);
}
#endif

//jede Sekunde
int i = 0;
void Model::tick() {
	if (i >= 60) {
#ifndef SIMULATOR
		readQueue();
#endif
		i = 0;
	}
	i++;

}

