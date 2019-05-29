#ifndef HISTORYRECORD_HPP
#define HISTORYRECORD_HPP

#include <gui_generated/containers/historyRecordBase.hpp>
#include "../info.h"
class historyRecord : public historyRecordBase
{
private:
	SensorRecord record;
public:
    historyRecord();
    virtual ~historyRecord() {}
    virtual void initialize();
    void updateValue(const SensorRecord& record);
    SensorRecord getValue();
protected:
};

#endif // HISTORYRECORD_HPP
