#include "Sensors.h"
#include "../Robotmap.h"
#include "Ultrasonic.h"

Sensors::Sensors() :
	Subsystem("Sensors") {
	rg = new Relay(ch_RG);
	b = new Relay(ch_B);
	ultra = new AnalogChannel(ch_ULTRASONIC);
   
  //  int index = 0;
	//int total = 0; 
	//int average = 0;


}
void Sensors::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
double Sensors::GetDistance(){
	
	distance = ((ultra->GetVoltage()/.0124))/12;
	return distance;
	
}
void Sensors::DistanceIndicator() {
	
	distance = GetDistance();
	if (distance >= 5.0 && distance <= 12.0) {
		greenlight();
	} else if (distance > 12.0 && distance <= 14) {
		yellowlight();
	} else {
		redlight();
	}
}
/*double Sensors::Smoothing(double valtosmooth) {
	
	   double readings[10];

		total = total - readings[index];
		readings[index] = GetDistance();
		total = total + readings[index];
		index = index +1;
		
		if (index>= 10){
			index = 0;
		}	
		average = total / 10;
		return average;
}*/

void Sensors::redlight() {
	rg->Set(Relay::kForward);
	b->Set(Relay::kOn);
}
void Sensors::greenlight() {
	rg->Set(Relay::kReverse);
	b->Set(Relay::kOn);
}
void Sensors::bluelight() {
	rg->Set(Relay::kOn);
	b->Set(Relay::kForward);
}
void Sensors::yellowlight() {
	rg->Set(Relay::kOff);
	b->Set(Relay::kOn);
}
void Sensors::violetlight() {
	rg->Set(Relay::kForward);
	b->Set(Relay::kForward);
}
void Sensors::cyanlight() {
	rg->Set(Relay::kReverse);
	b->Set(Relay::kForward);
}
void Sensors::whitelight() {
	rg->Set(Relay::kOff);
	b -> Set(Relay::kForward);
}
void Sensors::ledoff() {
	rg->Set(Relay::kOn);
	b-> Set(Relay::kOn);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.




