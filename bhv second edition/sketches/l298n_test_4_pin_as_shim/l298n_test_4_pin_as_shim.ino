// Создадим переменные для хранения номеров используемых пинов/портов Arduino.
int In1, In2, In3, In4;
void setup() // Настройка
{  
  // Присвоим переменным номера пинов Arduino.
  In1 = 5; // Двигатель M2
  In2 = 4;
  In3 = 3; // Двигатель M1
  In4 = 2;
  // Переведем данные пины/порты в режим вывода.
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
}

void loop() // Тело программы
{
  int i;
  int long_c;
  //Остановить оба двигателя.
  digitalWrite(In1, LOW); // Двигатель M2
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW); // Двигатель M1
  digitalWrite(In4, LOW);
  delay(1000); // Ждем 1 сек.
  long_c = 100;
  for(i = 0; i <= long_c; i++)
    {
      // Остановить двигатель М2.
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
      delay(long_c - i); // Ждем (long_c-i)*0.001 сек.
      // Включим двигатель M2.
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);
      delay(i); // Ждем (i*0.001) сек.
    }
  delay(3000);
  // Вращаем двигатель М2 в другую сторону.
  for(i = 0; i <= long_c; i++)
    {
      // Остановить двигатель М2.
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
      delay(long_c - i); // Ждем (long_c-i)*0.001 сек.
      //Включим двигатель М2.
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      delay(i); // Ждем (i*0.001) сек.
    }
  delay(3000);
  
  for(i = 0; i <= long_c; i++)
    {
      digitalWrite(In3, LOW);
      digitalWrite(In4, LOW);
      delay(long_c-i);

      digitalWrite(In3, LOW);
      digitalWrite(In4, HIGH);
      delay(i);
    }
  delay(3000);

  for(i = 0; i <= long_c; i++)
    {
      digitalWrite(In3, LOW);
      digitalWrite(In4, LOW);
      delay(long_c-i);

      digitalWrite(In3, HIGH);
      digitalWrite(In4, LOW);
      delay(i);
    }
  delay(3000);
}
