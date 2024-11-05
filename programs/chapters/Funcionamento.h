#include "crazyflie.h"
#include "mbed.h"

// Crazyflie controller objects
Mixer mixer;
AttitudeEstimator att_est;
AttitudeController att_cont;
VerticalEstimator ver_est;
VerticalController ver_cont;
HorizontalEstimator hor_est;
HorizontalController hor_cont;
Timer tempo;
float t;
// Ticker objects
Ticker tic, tic_range;

// Interrupt flag and counter variables
bool flag, flag_range;

// Callback functions
void callback() { flag = true; }
void callback_range() { flag_range = true; }

// Main program
int main() {
  // Set references
  float z_r = 0.0;
  float x_r = 0.0;
  float y_r = 0.0;
  float psi_r = 0.0;
  // Set Tempos
  float td = 2.0;
  float tv = 5.0;
  float tp = 2.0;
  float h = 1.0;
  float d = 2.0;
  // Initialize estimators objects
  att_est.init();
  ver_est.init();
  hor_est.init();
  // Initialize interrupts
  tic.attach(&callback, dt);
  tic_range.attach(&callback_range, dt_v);
  // Arm motors and run controller while stable
  mixer.arm();

  tempo.start();
  while (abs(att_est.phi) <= pi / 4.0 && abs(att_est.theta) <= pi / 4.0 &&
         abs(att_est.p) <= 4.0 * pi && abs(att_est.q) <= 4.0 * pi &&
         abs(att_est.r) <= 4.0 * pi && t < td+tv+tp+2.0) {
    if (flag) {
      flag = false;
      t = tempo.read();
      if (t < td) {
        z_r = h / td * t;
        x_r = 0.0;
        y_r = 0.0;

      } else if (t < td + tv) {
        z_r = h;
        x_r = d / tv * (t - td);
        y_r = 0.0;
      } else {
        z_r = -(h / tp) * (t - td - tp - tv);
        x_r = d;
        y_r = 0.0;
        }
      att_est.estimate();
      ver_est.predict(ver_cont.f_t);
      if (flag_range) {
        flag_range = false;
        ver_est.correct(att_est.phi, att_est.theta);
      }
      hor_est.predict(att_est.phi, att_est.theta);
      if (ver_est.z >= 0.05) {
        hor_est.correct(att_est.phi, att_est.theta, att_est.p, att_est.q,
                        ver_est.z);
        hor_cont.control(x_r, y_r, hor_est.x, hor_est.y, hor_est.u, hor_est.v);
      }
      ver_cont.control(z_r, ver_est.z, ver_est.w);
      att_cont.control(hor_cont.phi_r, hor_cont.theta_r, psi_r, att_est.phi,
                       att_est.theta, att_est.psi, att_est.p, att_est.q,
                       att_est.r);
      mixer.actuate(ver_cont.f_t / (cos(att_est.phi) * cos(att_est.theta)),
                    att_cont.tau_phi, att_cont.tau_theta, att_cont.tau_psi);
    }
  }
  // Disarm motors and end program
  while (true)
  mixer.disarm()
    ;
}