#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/SimpleAutonCommand.h"
#include "Commands/AutonCommandGroup.h"
class CommandBasedRobot: public IterativeRobot {
private:
	Command *autonomousCommand;
	SendableChooser *autoChooser;
	SendableChooser *chooser;
	LiveWindow *lw;
	Compressor *pump;
	DriverStationLCD *dsLCD;
	int i;
public:
	CommandBasedRobot(void) {
		dsLCD = DriverStationLCD::GetInstance();
		autoChooser = new SendableChooser();
	    pump = new Compressor(ch_PressureSwitch, ch_PumpRelay);
		i = 0;
	}
	virtual void RobotInit() {
		CommandBase::init();
		pump->Start();
		lw = LiveWindow::GetInstance();
		chooser = new SendableChooser();
		chooser->AddDefault("Ultrasonic auto", new AutonCommandGroup());
		SmartDashboard::PutData("Autonomous modes", chooser );
		//autoChooser->AddDefault("No Drive, Back Pyramid", new SimpleAutonCommand());
		
	}

	virtual void AutonomousInit() {
		pump->Start();
//		autonomousCommand = (Command *) chooser ->GetSelected();
		autonomousCommand = new AutonCommandGroup();
		autonomousCommand->Start();
	}

	virtual void AutonomousPeriodic() {
		
		Scheduler::GetInstance()->Run();
		//dsLCD->Clear();
		//dsLCD->PrintfLine(DriverStationLCD::kUser_Line1,"Hello");
		//dsLCD->PrintfLine(DriverStationLCD::kUser_Line2,"Distance %f", CommandBase::sensors->GetDistance()/12);
		//dsLCD->PrintfLine(DriverStationLCD::kUser_Line3,"ArmPot %f", CommandBase::intakearms->GetAngle());
		//dsLCD->PrintfLine(DriverStationLCD::kUser_Line4,"LauncherPot %f", CommandBase::launcher->GetShooterPosition());
		//dsLCD->UpdateLCD();
	}

	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

	}

	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
		dsLCD->Clear();
		dsLCD->PrintfLine(DriverStationLCD::kUser_Line1,"ArmPot %f",  CommandBase::intakearms->GetAngle());
		//dsLCD->PrintfLine(DriverStationLCD::kUser_Line2,"LauncherPot %f", CommandBase::launcher->GetShooterPosition());
		dsLCD->PrintfLine(DriverStationLCD::kUser_Line2,"Distance %f",CommandBase::sensors->GetDistance());
		dsLCD->PrintfLine(DriverStationLCD::kUser_Line3,"Launcher Set",CommandBase::launcher->launcher_limit->Get());
		//dsLCD->PrintfLine(DriverStationLCD::kUser_Line5,"X Val",CommandBase::driveStick->GetX());
		//dsLCD->PrintfLine(DriverStationLCD::kUser_Line6,"Y Val",CommandBase::driveStick->GetY());
		dsLCD->UpdateLCD();
	}

	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot)
;
