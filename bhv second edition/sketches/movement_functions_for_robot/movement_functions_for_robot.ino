#include "motor.h" // Подключаем все функции управления моторами

void setup() 
{
  // Для левых и правых моторов машинки.
  setup_motor_system(2, 3, 4, 5);
  _stop(); // Двигатели остановлены.
}

void loop() 
{
  forvard();
  delay(1000);
  reversal_right();
  delay(1000);
  forvard_left();
  delay(500);
  forvard_right();
  delay(500);
  _stop();
  delay(500);
  backward();
  delay(800);
  reversal_left();
  delay(1000);
}
