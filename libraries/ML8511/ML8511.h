#pragma once
//
//    FILE: ML8511.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.1
// PURPOSE: ML8511 - UV sensor - library for Arduino
//     URL: https://github.com/RobTillaart/Arduino
//
// HISTORY:
// see ML8511.cpp file
//
// NOTES
// - ML8511 is a 3.3 Volt device, 
//   so do not connect to a 5V device (e.g. UNO)
//   this includes the ENABLE PIN !!
//

#include <Arduino.h>

#define ML8511_LIB_VERSION "0.1.1"


class ML8511
{
public:
	// if enablePin is omitted, one must connect EN to 3V3.
    ML8511(uint8_t analogPin, uint8_t enablePin = -1);

	// energyMode = HIGH or LOW;
	float getUV(uint8_t energyMode = HIGH);
	
	// voltage must be > 0 otherwise it is not set
	void  setVoltsPerStep(float voltage, uint32_t steps);

	// manually enable / disable
	void  enable();
	void  disable();
	bool  isEnabled() { return _enabled; };

private:
	uint8_t _analogPin;
	uint8_t _enablePin;
	float   _voltsPerStep;
	bool    _enabled;
};

// END OF FILE
