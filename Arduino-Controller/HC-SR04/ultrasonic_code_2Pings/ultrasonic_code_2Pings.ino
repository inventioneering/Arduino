// I found this here: https://www.youtube.com/watch?v=KOirgo410Xw
// Turns out its in Russian =)

const int firstTrig = 3; // обозначим к какой ножке и что подключаем
const int firstEcho = 2;
const int secondTrig = 5;
const int secondEcho = 4;
void setup()
{
  pinMode(firstTrig, OUTPUT);
  pinMode(secondTrig, OUTPUT);
  pinMode(firstEcho, INPUT); 
  pinMode(secondEcho, INPUT);
  Serial.begin(57600); // Инициализируем сериал порт, дабы вывести результат на монитор
}
unsigned int firstTime_us = 0; // Переменная для хранения временного интервала
unsigned int firstDistance_sm = 0; // Переменная для хранения расстояния в сантиметрах
unsigned int secondTime_us = 0;
unsigned int secondDistance_sm = 0;
void loop()
{
  //Serial.print("first reading: ");
  digitalWrite(firstTrig, HIGH); // Подаем сигнал на выход микроконтроллера
  delayMicroseconds(10); // Удерживаем 10 микросекунд
  digitalWrite(firstTrig, LOW); // Затем убираем
  firstTime_us = pulseIn(firstEcho, HIGH); // Замеряем длину импульса
  firstDistance_sm = firstTime_us / 58; // Пересчитываем в сантиметры
  Serial.print(firstDistance_sm); // Выводим на порт
  Serial.print(",");
  Serial.print(".");

  //Serial.print("\n");

  //Serial.print("second reading: ");
  digitalWrite(secondTrig, HIGH); // Подаем сигнал на выход микроконтроллера
  delayMicroseconds(10); // Удерживаем 10 микросекунд
  digitalWrite(secondTrig, LOW); // Затем убираем
  secondTime_us = pulseIn(secondEcho, HIGH); // Замеряем длину импульса
  secondDistance_sm = secondTime_us / 58; // Пересчитываем в сантиметры
  Serial.print(secondDistance_sm); // Выводим на порт
  Serial.print(",");
  Serial.print(".");
  
  delay(33);// was set to 33
}
