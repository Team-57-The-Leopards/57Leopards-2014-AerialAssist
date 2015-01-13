#include "Launcher.h"
#include "../Robotmap.h"

Launcher::Launcher() :
	Subsystem("Launcher") {

	winchM = new CANJaguar(ch_WinchM);
	winchValve = new Solenoid(ch_WinchValve);
    launcher_limit = new DigitalInput(ch_LauncherLimitSwitch);
	launcher_pot = new AnalogChannel(ch_LauncherPotentiometer);
    isSet = false;
}
void Launcher::Extend() {
	currentposition = GetShooterPosition();

	if (currentposition < 4.5) {
		winchM->Set(0.5);
	} else if (currentposition >= 4.5) {
		winchM->Set(0.0);
	} else {
		winchM->Set(0.0);
	}
}
void Launcher::Retract() {
	currentposition = GetShooterPosition(); // Gets position of arm

	if (launcher_limit->Get()==false) { // Retracts arm 
		winchM->Set(-1.0);
	} else {
		winchM->Set(0.0);
	}
}
void Launcher::WinchActive() { //Activates the winch for use
	winchValve->Set(0);

}
void Launcher::WinchRelease() { //Releases winch and allows us to shoot 
	winchValve->Set(1);
	
}
double Launcher::GetShooterPosition() { // Uses limitswitch to check if shooter is all the way down ture is set
	shooterpos = launcher_pot->GetVoltage(); // Dont understand why this doesn't work
	return shooterpos;
}
void Launcher::SetShooterPosition(float setposition) {
	//setpointPosition = setposition;
	currentposition = GetShooterPosition();
	if (currentposition < setposition) { //Know which direction is up
		Extend();
	} else if (currentposition > setposition) { //If the angle is below  
		Retract();
	}
}
//bool isShooterSet() {

//}
void Launcher::Fire() { // Fire Winch
	//if (launcher_limit->Get()==true) { // Retracts arm 
		 WinchRelease();
		//} 
	    //else {
		// WinchActive();	
	//	}
	}
bool Launcher::IsShooterSet(){
	
	if(launcher_limit->Get() == 1){
		isSet = true;
	}
	else{
	isSet = false;	
	}
  return isSet;
}
