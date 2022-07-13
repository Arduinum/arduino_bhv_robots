// Пременная изменения скорости.
unsigned long _move_time;
int value_timer = 0;
int value_led = 0;
char value_bl = 0;
int buzzer = A3;

// Выбор действий:
void move_case(char bt_input)
{
  switch (bt_input)
  {
    // Вперед
    case 'F':
      forward();
      if(value_led == 1 && value_bl != 'F')
      {
        Timer1.pause();
        leds_off();
        value_timer = 2; // горят оба светодиода
        Timer1.resume();
        value_bl = 'F';
      }
      break;
    // Назад
    case 'B':
      backward();
      if(value_led == 1 && value_bl != 'B')
      {
        Timer1.pause();
        leds_off();
        value_timer = 3; // оба светодиода мигают одинакого
        leds_on();
        Timer1.resume();
        value_bl = 'B';
      }
      break;
    // Влево
    case 'L':
      reversal_left();
      if(value_led == 1 && value_bl != 'L')
      {
        Timer1.pause();
        leds_off();
        value_timer = 4; // мигает red_led
        red_on_only();
        Timer1.resume();
        value_bl = 'L';
      }
      break;
    // Вправо
    case 'R':
      reversal_right();
      if(value_led == 1 && value_bl != 'R')
      {
        Timer1.pause();
        leds_off();
        value_timer = 5; // мигает blue_led
        blue_on_only();
        Timer1.resume();
        value_bl = 'R';
      }
      break;
    // Прямо и влево
    case 'G':
      forward_left(); 
      if(value_led == 1 && value_bl != 'G')
      {
        Timer1.pause();
        leds_off();
        value_timer = 6; // горит red_led
        Timer1.resume();
        value_bl = 'G';
      }
      break;
    // Прямо и вправо
    case 'I':
      forward_right();
      if(value_led == 1 && value_bl != 'I')
      {
        Timer1.pause();
        leds_off();
        value_timer = 7; // горит blue_led
        Timer1.resume();
        value_bl = 'I'; 
      }
      break;
    // Назад и влево
    case 'H':
      backward_left();
      if(value_led == 1 && value_bl != 'H')
      {
        Timer1.pause();
        leds_off();
        value_timer = 6; // мигает red_led
        red_on_only();
        Timer1.resume();
        value_bl = 'H';
      }
      break;
    // Назад и вправо
    case 'J':
      backward_right();
      if(value_led == 1 && value_bl != 'J')
      {
        Timer1.pause();
        leds_off();
        value_timer = 7; // мигает blue_led
        blue_on_only();
        Timer1.resume();
        value_bl = 'J'; 
      }
      break;
    // Стоп
    case 'S':
      _stop();
      break;
    // Скорость 0%
    case '0':
      _move_time = 0;
      break;
    // Скорость 10%
    case '1':
      _move_time = 50;
      break;
    // Скорость 20%
    case '2':
      _move_time = 100;
      break;
    // Скорость 30%
    case '3':
      _move_time = 150;
      break;
    // Скорость 40%
    case '4':
      _move_time = 200;
      break;
    // Скорость 50%
    case '5':
      _move_time = 250;
      break;
    // Скорость 60%
    case '6':
      _move_time = 300;
      break;
    // Скорость 70%
    case '7':
      _move_time = 350;
      break;
    // Скорость 80%
    case '8':
      _move_time = 400;
      break;
    // Скорость 90%
    case '9':
      _move_time = 450;
      break;
    case 'q':
      _move_time = 500;
      break;
    case 'D':
      _stop();
      break;
    case 'U': // кнопка задние фары
      if(value_led == 0)// включиться если другой режим светодиодов выключен
      {
        value_timer = 1;
        blue_on(); // стартовая позиция для светодиодов
        Timer1.resume();
      }
      break;
    case 'u':
      if(value_led == 0) // выключиться если другой режим светодиодов выключен
      {
        value_timer = 0;
      }
      break;
    // режимы совмещены теперь нужна защита от дурака!
    case 'W': // кнопка передние фары
      if(value_timer != 1) // включиться если другой режим светодиодов выключен
      {
        value_led = 1;
      }
      break;
    case 'w':
      if(value_timer != 1) // выключиться если другой режим светодиодов выключен
      {
        value_led = 0;
        value_timer = 0;
        value_bl = 0;
      }
      break;
    case 'V': // включить гудок
      tone(buzzer, 500); //включаем на 500 Гц
      break;
    case 'v': // выключить гудок
      noTone(buzzer); // Останавливаем звук
      break;
  }
}
