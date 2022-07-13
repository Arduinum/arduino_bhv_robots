// Подключаем библиотеку для создания дополнительных последовательных (Serial) портов.
#include "GyverTimers.h"
#include <SoftwareSerial.h>
#include "motor.h"
#include "leds.h"
// порядок имеет значение если leds написать снизу, то её функци не увидит case_bluetooth_robot.h
#include "case_bluetooth_robot.h"
//Создаем последовательный порт на пинах 10-чтение и 11-передача.
SoftwareSerial BTSerial(10, 11); // RX, TX
// Переменная для приема данных по Bluetooth.
char bt_input;
// Хранит время последнего нажатия кнопки.
unsigned long _time;

void setup() 
{
  // Переменные – номера контактов (пинов) Arduino.
  setup_motor_system(2, 3, 4, 5);
  _stop(); //Двигатели остановлены.
  // номира аналоговых пинов для leds
  setup_led(A1, A2);
  // Устанавливаем скорость передачи данных для НС-05 (Bluetooth-модуль).
  BTSerial.begin(9600);
  // Устанавливаем скорость передачи данных по кабелю.
   Serial.begin(9600);
  _time = micros();
  // Настройки для таймера:
  Timer1.setPeriod(200000); // 200000 мкс
  Timer1.enableISR(CHANNEL_A);
}

void loop() 
{
  if(BTSerial.available())
  {
    // Читаем команду и заносим ее в переменную. char преобразует
    // код символа команды в символ.
    bt_input = (char)BTSerial.read();
    // Отправляем команду в порт, чтобы можно было
    // их проверить в "Мониторе порта".
    Serial.println(bt_input);
    //Вызов функции выбора действия по команде
    move_case(bt_input);
    _time = micros();
  }
 
  if((micros() - _time) >= _move_time)
  {
    _stop();
  }
  
  if ((micros() - _time) >= 500)
  {
    _time = micros();
    if (move_case(bt_input)){
      move_case(bt_input);
    } else{_stop();}
  }
}

ISR(TIMER1_A)
{
  if(value_timer == 1)
  {
    digitalWrite(Led_01, !digitalRead(Led_01)); // мигаем двумя
    digitalWrite(Led_02, !digitalRead(Led_02));
  }

  if(value_timer == 2)
  {
    leds_on();
  }

  if(value_timer == 3)
  {
    digitalWrite(Led_01, !digitalRead(Led_01)); // мигаем двумя
    digitalWrite(Led_02, !digitalRead(Led_02));
  }
  
  if(value_timer == 4)
  {
    digitalWrite(Led_02, !digitalRead(Led_02));
  }

  if(value_timer == 5)
  {
    digitalWrite(Led_01, !digitalRead(Led_01));
  }

  if(value_timer == 6)
  {
    red_on();
  }

  if(value_timer == 7)
  {
    blue_on();
  }

  if(value_timer == 0)
  {
    Timer1.pause(); // выключаем таймер
    leds_off(); // выключаем светодиоды
  }
}

// написать два режима для buzzer сигнал и мелодия
