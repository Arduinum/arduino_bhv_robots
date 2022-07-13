// Попробовать пульт AKAI он передаёт непрерывно данные, а маленький нет
// От маленького пульта робот движется

#include "IRremote.h" // Подключаем локально библиотеку для IR.
#include "motor.h" // Подключаем локально библиотеку для моторов.
// Порт для IR-приемника.
int RECV_PIN = 7;
// Создание IR-приемника.
IRrecv irrecv(RECV_PIN);
//Переменная для хранения кодов кнопок, получаемых от IR-приемника.
decode_results results;
// Хранит время последнего нажатия кнопки.
unsigned long _time;
// Опишем коды кнопок макроподстановками:
#define FORWARD 0x3D9AE3F7
#define FORWARD2 0x511DBB
#define BACKWARD 0x1BC0157B
#define BACKWARD2 0xA3C8EDDB
#define LEFT 0x8C22657B
#define LEFT2 0x52A3D41F
#define RIGHT 0x449E79F
#define RIGHT2 0x20FE4DBB
#define STOP 0x488F3CBB
#define STOP2 0xD7E84B1B
#define FORWARDLEFT 0xE318261B
#define FORWARDRIGHT 0xEE886D7F
#define BACKWARDLEFT 0xF076C13B
#define BACWARDRIGHT 0xE5CFBD7F
// #define STARWARSMUSIC 0x97483BFB
// #define AUDIOSIGNAL 0xF0C41643
// #define AUTOLEDSFLASH 0xC101E57B
void setup() 
{
  // Переменные – номера контактов (пинов) Arduino.
  // Для левых и правых моторов машинки.
  setup_motor_system(2, 3, 4, 5);
  _stop(); //Двигатели остановлены.
  // Запуск IR-приемника.
  irrecv.enableIRIn();
  _time = millis();
}

void loop() 
{
  if(irrecv.decode(&results))
  {
    _time = millis();
    switch (results.value){
    // Вперед
    case FORWARD:
      forward();
      break;
    case FORWARD2:
      forward();
      break;
    // Влево
    case LEFT:
      reversal_left();
      break;
    case LEFT2:
      reversal_left();
      break;
    // Вправо
    case RIGHT:
      reversal_right();
      break;
    case RIGHT2:
      reversal_right();
      break;
    // Стоп
    case STOP:
      _stop();
      break;
    case STOP2:
      _stop();
      break;
    // Назад
    case BACKWARD: // делает вперёд и влево
      backward();
      break;
    case BACKWARD2:
      backward();
      break;
    // Вперёд и влево
    case FORWARDLEFT:
      forward_left();
      break;
    // Вперёд и вправо
    case FORWARDRIGHT:
      forward_right();
      break; 
   // Назад и влево
   case BACKWARDLEFT:
     backward_left();
     break;
   // Назад и вправо
   case BACWARDRIGHT:
     backward_right();
     break;
  }
  irrecv.resume();
 }
 //Если никакая клавиша не нажата более 0.3сек., то остановка.
 if((millis()-_time)>300) {_stop();}
}
