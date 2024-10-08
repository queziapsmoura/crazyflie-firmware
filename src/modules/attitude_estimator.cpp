# include "attitude_estimator.h"
// Class constructor
AttitudeEstimator::AttitudeEstimator():imu( IMU_SDA , IMU_SCL )
{
    phi = 0.0;
    theta = 0.0;
    psi = 0.0;
    p = 0.0;
    q = 0.0;
    r = 0.0;
    imu.ax = 0.0;
    imu.ay = 0.0;

}
// Initialize class
void AttitudeEstimator::init ()
{
    imu.init();
}
// Estimate Euler angles ( rad ) and angular velocities ( rad / s )
void AttitudeEstimator::estimate ()
{
    imu.read();
    // phi_a : phi do aceçer}ometro
    // atan2: Para saber em qual quadrante o ângulo está
    float phi_a = atan2(-imu.ay,-imu.az);
    phi = (1-alpha)*phi + alpha*phi_a;
}
