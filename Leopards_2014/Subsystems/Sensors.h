#ifndef SENSORS_H
#define SENSORS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Dillan
 */
class Sensors: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Sensors();
	void InitDefaultCommand();
	void DistanceIndicator();
	double GetDistance();
	double Smoothing(double valtosmooth);
	void yellowlight();
	void redlight();
	void ledoff();
	void greenlight();
	void violetlight();
	void cyanlight();
	void whitelight();
	void bluelight();
	double distance;
    double total,average;
    int index;
	Relay *rg;
	Relay *b;
	AnalogChannel *ultra ;
	
};

#endif
