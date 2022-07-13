//Создадим переменные для хранения номеров используемых пинов/портов Arduino
int In1, In2, In3, In4;
void setup() // Настройка 
{
  // Присвоим переменным номера пинов Arduino
  In1 = 5;
  In2 = 4;
  In3 = 3;
  In4 = 2;
  //Переведем данные пины/порты в режим вывода
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
}

void loop() //Тело программы
{
  //Отключим оба двигателя
  digitalWrite(In1, LOW); //двигатель М2
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW); //двигатель М1
  digitalWrite(In4, LOW);
  delay(1000); // Ждем 1 сек
  //Включим двигатель М2 и M1 вперёд
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  delay(1000); // Ждем 1 сек
  //Включим двигатель М2 и M1 назад
  digitalWrite(In1, LOW); //двигатель М2
  digitalWrite(In2, HIGH);
  digitalWrite(In3, LOW); //двигатель М1
  digitalWrite(In4, HIGH);
  delay(1000); // Ждем 1 сек
  // вперёд и влево двигатель M2
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  delay(1000); // Ждем 1 сек
  // вперёд и вправо двигатель M1
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  delay(1000); // Ждем 1 сек
  // назад и вправо двигатель M2
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  delay(1000); // Ждем 1 сек
  // назад и влево двигатель M1
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  delay(1000); // Ждем 1 сек
  // Разворот на месте влево
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  delay(1000); // Ждем 1 сек
  // Разворот на месте вправо
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  delay(1000); // Ждем 1 сек

}
