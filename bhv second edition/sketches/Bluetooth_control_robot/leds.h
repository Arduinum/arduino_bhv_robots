
int Led_01, Led_02;

void setup_led(int Blue, int Red)
{
   Led_01 = Blue;
   Led_02 = Red;

   pinMode(Led_01, OUTPUT);
   pinMode(Led_02, OUTPUT);
}

void leds_on()
{
  digitalWrite(Led_01, HIGH);
  digitalWrite(Led_02, HIGH);
}

void leds_off()
{
  digitalWrite(Led_01, LOW);
  digitalWrite(Led_02, LOW);
}

void blue_on()
{
  digitalWrite(Led_01, HIGH);
  digitalWrite(Led_02, LOW);
}

void red_on()
{
  digitalWrite(Led_01, LOW);
  digitalWrite(Led_02, HIGH);
}

void blue_on_only()
{
  digitalWrite(Led_01, HIGH);
}

void red_on_only()
{
  digitalWrite(Led_02, HIGH);
}
