# include "horizontal_estimator.h"

// Class Constuctor

HorizontalEstimator:: HorizontalEstimator(): flow (PA_7, PA_6, PA_5, PB_4)
{
 x = 0;
 y = 0;
 u = 0;
 v = 0;
}
// Inicializa Classe
void HorizontalEstimator::init()
{
    flow.init();
}
// Prever posição vertical e velocidade a partir do modelo
void HorizontalEstimator:: predict(float phi, float theta)
{
    x = x + u*dt;
    y = y + v*dt;
    u = u + g*theta*dt;
    v = v - g*phi*dt;

}
// Corrige velocidades horizontais com os valores mensurados pelo sensor de fluxo ótico
void HorizontalEstimator:: correct (float phi, float theta, float p, float q, float z)
{
    float den = cos(phi)*cos(theta);
    if (den>0.5){
        float d = z/den;
        flow.read();
        float u_m = (sigma*flow.px + q)*d;
        float v_m = (sigma*flow.py - p)*d;
        u = u + l_h*dt*(u_m-u);
        v = v + l_h*dt*(v_m-v);
    }
}
