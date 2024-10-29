# ifndef horizontal_estimato_h
# define horizontal_estimato_h

# include "mbed.h"
# include "crazyflie.h"

// Horizontal Estimator

class HorizontalEstimator {
public:
  // Class Construtor
  HorizontalEstimator();
  // Inicializa Classe
  void init();
  // Prever posição vertical e velocidade a partir do modelo
  void predict(float phi, float theta);
  // Corrige velocidades horizontais com os valores mensurados
  void correct(float phi, float theta, float p, float q, float z);
  // Posições Horizontais (m) e velocidades (m/s) estimados
  float x, y, u, v;

private:
  PMW3901 flow;
};

#endif