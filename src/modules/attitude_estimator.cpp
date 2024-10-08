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
    imu.gx = 0.0;
    imu.gy = 0.0;

}
// Initialize class
void AttitudeEstimator::init ()
{
    imu.init();
    for(int i=0; i<500;i++)
    {
        imu.read();
        p_bias += imu.gx/500.0;
        q_bias += imu.gy/500.0;
        r_bias += imu.gz/500.0;
        wait(dt);
    }
}
// Estimate Euler angles ( rad ) and angular velocities ( rad / s )
void AttitudeEstimator::estimate ()
{
    imu.read();
    // phi_a : phi do aceçerometro
    // atan2: Para saber em qual quadrante o ângulo está
    float phi_a = atan2(-imu.ay,-imu.az);
    float theta_a = atan2(imu.ax,((imu.az>0)-(imu.az<0))*sqrt((imu.ay)*(imu.ay)+(imu.az)*(imu.az)));
    //phi = (1-alpha)*phi + alpha*phi_a;
    p = imu.gx - p_bias;
    q = imu.gy - q_bias;
    r = imu.gz - r_bias;
    float phi_g = phi + (p+sin(phi)*tan(theta)*q+cos(phi)*tan(theta)*r)*dt;
    float theta_g = theta + (cos(phi)*q-sin(phi)*r)*dt;
    float psi_g = psi + (sin(phi)/cos(theta)*q+cos(phi)/cos(theta)*r)*dt;
    //phi = phi_g;
    //phi = (1-alpha)*phi_g;


    phi = (1-alpha)*phi_g + alpha*phi_a;
    theta = (1-alpha)*theta_g + alpha*theta_a;
    psi = psi_g;
}
