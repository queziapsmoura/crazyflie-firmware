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


}
// Corrige velocidades horizontais com os valores mensurados pelo sensor de fluxo ótico
void HorizontalEstimator:: correct (float phi, float theta, float p, float q, float z)
{

}
