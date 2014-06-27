/*
 *      Author  : Atul Rokade
 *      Orga.   : IIT Bombay
 */
#ifndef  FIREBIRD_H
#define  FIREBIRD_H


typedef unsigned char	uint8;
typedef unsigned int	uint16;
typedef int				int16;
typedef unsigned long	uint32;

#define HANDLE  int*
#define BOOL    void
#define DWORD   unsigned long
#define TRUE    1
#define FALSE   0

#define SUCCESS		0
#define FAILURE		1

#define N	78
#define E	69
#define	X	88

#define CMD_SIZE	5
#define RESPONSE_HEADER	5
#define	RESPONSE_SIZE	6

#define GET_SENSOR_ARRAY				0x05
#define GET_SENSOR_ARRAY_SONAR			0x01
#define GET_SENSOR_ARRAY_IRPROXIMITY	0x02
#define GET_SENSOR_ARRAY_LINE			0x04


#define	ULTRASONIC_SENSOR_COUNT		8
#define	IRDISTANCE_SENSOR_COUNT		8
#define	IRPROXIMITY_SENSOR_COUNT	8
#define	LINE_SENSOR_COUNT			8


#define SET_SENSOR_ON_OFF			0x09
#define GET_SENSOR_ON_OFF			0x0A

#define SENSOR_STATUS_OFF			0x00
#define SENSOR_STATUS_ON			0x01

// Communication APIs
HANDLE connect_comm(char *portName);
void disconnect_comm(HANDLE *h);

// Inertial sensors
#define GET_INERTIAL_XYZ			0x05
#define GET_ACCELEROMETER_XYZ		0x05
#define GET_GYRO_XYZ				0x06
#define GET_MAGNETOMETER_XYZ		0x07


#define GET_ACCELEROMETER_VALUE		0x10
#define GET_ACCELEROMETER_X			0x01
#define GET_ACCELEROMETER_Y			0x02
#define GET_ACCELEROMETER_Z			0x03

#define GET_GYRO_VALUE				0x11
#define GET_GYRO_X					0x01
#define GET_GYRO_Y					0x02
#define GET_GYRO_Z					0x03

#define GET_MAGNETOMETER_VALUE		0x12
#define GET_MAGNETOMETER_X			0x01
#define GET_MAGNETOMETER_Y			0x02
#define GET_MAGNETOMETER_Z			0x03

#define INERTIAL_DATA_RESPONSE_SIZE 0x07
#define INERTIAL_DATA_RESPONSE_SIZE_XYZ INERTIAL_DATA_RESPONSE_SIZE + 4

//void inertialSensorsTest(HANDLE hComm);
void myfun();
BOOL getAccelerometerX(HANDLE hComm, int16 *accelerationX);
BOOL getAccelerometerY(HANDLE hComm, int16 *accelerationY);
BOOL getAccelerometerZ(HANDLE hComm, int16 *accelerationZ);
BOOL getAccelerometerXYZ(HANDLE hComm, int16* accelerometerXYZ);
BOOL getGyroX(HANDLE hComm, int16 *gyroX);
BOOL getGyroY(HANDLE hComm, int16 *gyroY);
BOOL getGyroZ(HANDLE hComm, int16 *gyroZ);
BOOL getGyroXYZ(HANDLE hComm, int16* GyroXYZ);
BOOL getMagnetometerX(HANDLE hComm, int16 *magnetometerX);
BOOL getMagnetometerY(HANDLE hComm, int16 *magnetometerY);
BOOL getMagnetometerZ(HANDLE hComm, int16 *magnetometerZ);
BOOL getMagnetometerXYZ(HANDLE hComm, int16* magnetometerXYZ);

//--------------------------------------------------------------------------------
BOOL InitPeripherals (HANDLE hComm);

BOOL DelaymSec(HANDLE hComm, unsigned int mSec);

BOOL lcdWriteChar(HANDLE hComm, char letter);
BOOL lcdHome(HANDLE hComm);
BOOL lcdWriteString(HANDLE hComm, char *str);
BOOL lcdCursor (HANDLE hComm, unsigned char row, unsigned char column);
BOOL lcdPrint (HANDLE hComm, unsigned char row, unsigned char coloumn, unsigned long value, int digits);
BOOL lcdClear(HANDLE hComm);


BOOL BuzzerOn (HANDLE hComm);
BOOL BuzzerOff (HANDLE hComm);

//void Linear_Distance_mm(unsigned int count, unsigned int pwm_value);	// Do nout use. Remove this API
//void Set_Right_PWM (unsigned int pwm_value);
//void Set_Left_PWM (unsigned int pwm_value);
BOOL Forward_mm(HANDLE hComm, unsigned int count, unsigned int pwm_value);
BOOL Backward_mm(HANDLE hComm, unsigned int count, unsigned int pwm_value);
//void Left_mm(unsigned int count, unsigned int pwm_value);		// Do nout use. Remove this API
//void Right_mm(unsigned int count, unsigned int pwm_value);	// Do nout use. Remove this API
BOOL Rotate(HANDLE hComm, unsigned int Degrees, unsigned int pwm_value);
BOOL TurnLeft(HANDLE hComm, unsigned int Degrees, unsigned int pwm_value);
BOOL TurnRight(HANDLE hComm, unsigned int Degrees, unsigned int pwm_value);


BOOL serialInit(HANDLE hComm, uint8 port, unsigned long baudrate);
BOOL serialWriteChar (HANDLE hComm, uint8 port, uint8 serial_data);
BOOL serialWriteString (HANDLE hComm, uint8 port, void *str, uint32 count);
BOOL serialRead (HANDLE hComm, uint8 port, void *buffer, uint16 count);

//--------------------------------------------------------------------------------

// IR Proximity sensors
#define SET_IRPROXIMITY_SENSOR_ON	0x01
#define SET_IRPROXIMITY_SENSOR_OFF	0x02
#define GET_IRPROXIMITY_SENSOR_STATUS	0x01

#define GET_IRPROXIMITY_SENSOR		0x02

BOOL getIRProximitySensorStatus(HANDLE hComm, uint8 *status);
BOOL setIRProximitySensorON(HANDLE hComm);
BOOL setIRProximitySensorOFF(HANDLE hComm);
BOOL getIRProximitySensor(HANDLE hComm, uint8 sensorNumber, uint8 *irProximityValue);
BOOL getIRProximitySensorArray(HANDLE hComm, uint8 *allIRProximityData);


// Line sensors
#define	LINE_SENSOR_COUNT		8

#define SET_LINE_SENSOR_ON		0x03
#define SET_LINE_SENSOR_OFF		0x04
#define GET_LINE_SENSOR_STATUS	0x02

#define GET_LINE_SENSOR			0x04

BOOL getLineSensorStatus(HANDLE hComm, uint8 *status);
BOOL setLineSensorON(HANDLE hComm);
BOOL setLineSensorOFF(HANDLE hComm);
BOOL getLineSensor(HANDLE hComm, uint8 sensorNumber, uint8 *lineSensorValue);
BOOL getlineSensorArray(HANDLE hComm, uint8 *allLineSensorData);


// Power sensors
#define GET_BATTERY_VOLTAGE		0x20
#define GET_BATTERY_CURRENT		0x21
#define GET_BATTERY_TEMPERATURE	0x22

BOOL getBatteryVoltage(HANDLE hComm, uint16 *batteryVoltage);
BOOL getBatteryCurrent(HANDLE hComm, uint8 * batteryCurrent);
BOOL getBatteryTemprature(HANDLE hComm, uint8 *batteryTemprature);

// Ultrasonic sensors
#define	SONAR_SENSOR_COUNT		8

#define SET_SONAR_SENSOR_ON		0x05
#define SET_SONAR_SENSOR_OFF	0x06

#define GET_SONAR_SENSOR		0x01
#define GET_SONAR_SENSOR_STATUS	0x03

BOOL getSonarStatus(HANDLE hComm, uint8 *status);
BOOL setSonarSensorON(HANDLE hComm);
BOOL setSonarSensorOFF(HANDLE hComm);
BOOL getSonar(HANDLE hComm, uint8 sensorNumber, uint8 *sonarValue);
BOOL getSonarArray(HANDLE hComm, uint8 *allSonarData);

// SHARP sensors
#define	IRDISTANCE_SENSOR_COUNT			8

#define SET_IRDISTANCE_SENSOR_ON		0x05
#define SET_IRDISTANCE_SENSOR_OFF		0x06

#define GET_IRDISTANCE_SENSOR			0x01
#define GET_IRDISTANCE_SENSOR_STATUS	0x03

BOOL getIRDistanceStatus(HANDLE hComm, uint8 *status);
BOOL setIRDistanceSensorON(HANDLE hComm);
BOOL setIRDistanceSensorOFF(HANDLE hComm);
BOOL getIRDistance(HANDLE hComm, uint8 sensorNumber, uint16 *irDistanceValue);
BOOL getIRDistanceArray(HANDLE hComm, uint16 *IRDistanceData);

// Motion control

// FB6 command types
#define MOTION_SET_MODE             0x90
#define MOTION_GET_MODE             0x91
#define RESET_MOTOR_ENCODER_COUNT	0x8C
#define GET_LEFT_MOTOR_COUNT		0x92
#define GET_RIGHT_MOTOR_COUNT		0x93

#define	MOTION_CONTROL				0x94
#define SET_LEFT_MOTOR_VELOCITY		0x95
#define SET_RIGHT_MOTOR_VELOCITY	0x96
#define GET_LEFT_MOTOR_VELOCITY		0x9A
#define GET_RIGHT_MOTOR_VELOCITY	0x9B


#define	MOTOR_FORWARD				0x01
#define	MOTOR_BACKWARD				0x02
#define	MOTOR_LEFT					0x03
#define	MOTOR_RIGHT					0x04
#define	MOTOR_STOP					0x06

#define GET_MOTOR_CURRENT			0x97
#define GET_LEFT_MOTOR_CURRENT		0x01
#define GET_RIGHT_MOTOR_CURRENT		0x02

#define SET_ACCELERATION			0x98
#define GET_ACCELERATION			0x99

// function declarations
BOOL SetMode(HANDLE hComm, uint8 mode);						//	F
				//	F
BOOL forward(HANDLE hComm);
BOOL backward(HANDLE hComm);
BOOL left(HANDLE hComm);
BOOL right(HANDLE hComm);
BOOL stop(HANDLE hComm);
BOOL goTo(HANDLE hComm, uint8 r, uint8 c);

BOOL setLeftMotorVelocity(HANDLE hComm, uint8 velocity);
BOOL setRightMotorVelocity(HANDLE hComm, uint8 velocity);
BOOL setVelocity(HANDLE hComm, uint8 leftMotorVelocity, uint8 rightMotorVelocity);

BOOL GetLeftMotorVelocity(HANDLE hComm, uint8 *leftMotorVelocity);
BOOL GetRightMotorVelocity(HANDLE hComm, uint8 *rightMotorVelocity);
BOOL SetAcceleration(HANDLE hComm, uint8 acceleration);			//	F
BOOL GetAcceleration(HANDLE hComm, uint8 *acceleration);							//	F
BOOL GetLeftMotorCount(HANDLE hComm, uint32 *leftMotorCount);
BOOL GetRightMotorCount(HANDLE hComm, uint32 *rightMotorCount);
BOOL ResetMotorEncoderCount(HANDLE hComm);

#endif	// _FB6LIBC_H
