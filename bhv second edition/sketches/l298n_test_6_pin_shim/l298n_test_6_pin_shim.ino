// Создадим переменные для хранения номеров используемых пинов/портов Arduino.
int In1, In2, In3, In4, ENA, ENB;
void setup() // Настройка
{
  // Присвоим переменным номера пинов Arduino.
  In1 = 5; // Двигатель M2
  In2 = 4;
  In3 = 3; // Двигатель M1
  In4 = 2;
  ENA = 6; // Двигатель M2 шим 
  ENB = 9; // Двигатель M1 шим
  //Переведем данные пины/порты в режим вывода.
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() //Тело программы
{
  //Отключим оба двигателя.
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  analogWrite(ENA, 0); // ШИМ двигателя М2 полностью выключен.
  analogWrite(ENB, 0); // ШИМ двигателя М1 полностью выключен.

  delay(1000); // Ждем 1 сек.
  //Включим двигатель М2.
  digitalWrite(In1, LOW); // Двигатель М2.
  digitalWrite(In2, HIGH);
  for(int i = 0; i < 255; i++)
    {
      analogWrite(ENA, i); // Посылаем на шим сигнал.
      delay(300); // Ждем 0.3 сек.
    }
  analogWrite(ENA, 0); // ШИМ двигателя М2 полностью выключен.

  // Вращаем двигатель М2 в другую сторону.
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  for(int i=0;i<255;i++)
  {
    analogWrite(ENA,i);
    delay(300); // Ждем 0.3 сек.
  }
  analogWrite(ENA,0); // ШИМ двигателя М2 полностью выключен.
  delay(1000); // Ждем 1 сек.
  //Включим двигатель М1.
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  for(int i = 0; i < 255; i++)
    {
      analogWrite(ENB, i);
      delay(300);
    }
  analogWrite(ENB, 0);
  // Вращаем двигатель М1 в другую сторону.
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  for(int i = 0; i < 255; i++)
    {
      analogWrite(ENB, i);
      delay(300);
    }
  analogWrite(ENB, 0);
  delay(1000);
}
