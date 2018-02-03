/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <Joystick.h>
#include <Spark.h>
//#include <Talon.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with arcade steering.
 */
class Robot : public frc::IterativeRobot {
//	frc::Spark m_leftMotor{0};
//	frc::Spark m_rightMotor{1};
//	frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};
	frc::Joystick m_stick{0};
//

	WPI_TalonSRX * _rghtFront = new WPI_TalonSRX(1);
	WPI_TalonSRX * _leftFront = new WPI_TalonSRX(2);


	DifferentialDrive * _diffDrive = new DifferentialDrive(*_leftFront,	*_rghtFront);

	//Joystick * _joystick = new Joystick(0);

	//Faults _faults_L;
//	Faults _faults_R;

public:
	void TeleopPeriodic() {
		// drive with arcade style

//		SmartDashboard::PutString("DB/String 0", "My 21 Char TestString");
//		frc::SmartDashboard::PutNumber(
//				"DB/String 0", stickL->GetYChannel());
//		frc::SmartDashboard::PutNumber(
//				"DB/String 1", stickL->GetXChannel());


		//_diffDrive->ArcadeDrive(m_stick.GetRawAxis(1), m_stick.GetRawAxis(2));

		_diffDrive->TankDrive(m_stick.GetRawAxis(LEFT_Y_AXIS), m_stick.GetRawAxis(RIGHT_Y_AXIS), m_stick.GetRawButton(SHOULDER_RIGHT_BUTTON));


	}
};

START_ROBOT_CLASS(Robot)
