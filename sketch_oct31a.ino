//#include <SparkFunMPU9250-DMP.h> // Include SparkFun MPU-9250-DMP library
#include <Wire.h> // Depending on your Arduino version, you may need to include Wire.h

//MPU9250_DMP imu; // Create an instance of the MPU9250_DMP class






#define INTERRUPT_PIN 4 // MPU-9250 INT pin tied to D4
void setup()
{
      if (imu.begin() != INV_SUCCESS)
    {
        while (1)
        {
            // Failed to initialize MPU-9250, loop forever
        }
    }
    // Use setSensors to turn on or off MPU-9250 sensors.
    // Any of the following defines can be combined:
    // INV_XYZ_GYRO, INV_XYZ_ACCEL, INV_XYZ_COMPASS,
    // INV_X_GYRO, INV_Y_GYRO, or INV_Z_GYRO
    imu.setSensors(INV_XYZ_GYRO | INV_XYZ_ACCEL | INV_XYZ_COMPASS); // Enable all sensors
    
    
    // Use setGyroFSR() and setAccelFSR() to configure the
    // gyroscope and accelerometer full scale ranges.
    // Gyro options are +/- 250, 500, 1000, or 2000 dps
    imu.setGyroFSR(2000); // Set gyro to 2000 dps
    // Accel options are +/- 2, 4, 8, or 16 g
    imu.setAccelFSR(2); // Set accel to +/-2g
    
    // setLPF() can be used to set the digital low-pass filter
    // of the accelerometer and gyroscope.
    // Can be any of the following: 188, 98, 42, 20, 10, 5
    // (values are in Hz).
    imu.setLPF(5); // Set LPF corner frequency to 5Hz
    
    // The sample rate of the accel/gyro can be set using
    // setSampleRate. Acceptable values range from 4Hz to 1kHz
    imu.setSampleRate(10); // Set sample rate to 10Hz
    
    // Likewise, the compass (magnetometer) sample rate can be
    // set using the setCompassSampleRate() function.
    // This value can range between: 1-100Hz
    imu.setCompassSampleRate(10); // Set mag rate to 10Hz
    pinMode(INTERRUPT_PIN, INPUT_PULLUP); // Set interrupt as an input w/ pull-up resistor
    
    // Use enableInterrupt() to configure the MPU-9250's 
    // interrupt output as a "data ready" indicator.
    imu.enableInterrupt();

    // The interrupt level can either be active-high or low. Configure as active-low.
    // Options are INT_ACTIVE_LOW or INT_ACTIVE_HIGH
    imu.setIntLevel(INT_ACTIVE_LOW);

    // The interrupt can be set to latch until data is read, or as a 50us pulse.
    // Options are INT_LATCHED or INT_50US_PULSE
    imu.setIntLatched(INT_LATCHED);
}


void loop() {
  // put your main code here, to run repeatedly:
  // Call update() to update the imu objects sensor data. You can specify 
  // which sensors to update by OR'ing UPDATE_ACCEL, UPDATE_GYRO, 
  // UPDATE_COMPASS, and/or UPDATE_TEMPERATURE.
  // (The update function defaults to accel, gyro, compass, so you don't 
  // have to specify these values.)
  imu.update(UPDATE_ACCEL | UPDATE_GYRO | UPDATE_COMPASS);
  float accelX = imu.calcAccel(imu.ax); // accelX is x-axis acceleration in g's
  float accelY = imu.calcAccel(imu.ay); // accelY is y-axis acceleration in g's
  float accelZ = imu.calcAccel(imu.az); // accelZ is z-axis acceleration in g's
  
  float gyroX = imu.calcGyro(imu.gx); // gyroX is x-axis rotation in dps
  float gyroY = imu.calcGyro(imu.gy); // gyroY is y-axis rotation in dps
  float gyroZ = imu.calcGyro(imu.gz); // gyroZ is z-axis rotation in dps
  
  float magX = imu.calcMag(imu.mx); // magX is x-axis magnetic field in uT
  float magY = imu.calcMag(imu.my); // magY is y-axis magnetic field in uT
  float magZ = imu.calcMag(imu.mz); // magZ is z-axis magnetic field in uT



}
