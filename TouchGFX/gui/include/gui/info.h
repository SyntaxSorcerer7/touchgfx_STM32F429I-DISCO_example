#ifndef INFO_H
#define INFO_H

#include <time.h>

#ifndef SIMULATOR
struct SensorRecord {
	uint8_t sensorId;
	int32_t value;
	time_t timestamp;
};
#endif

//Simulator doesn't know uint8_t ....
#ifdef SIMULATOR
struct SensorRecord {
	int sensorId;
	int value;
	time_t timestamp;
};
#endif

#endif // INFO_H
