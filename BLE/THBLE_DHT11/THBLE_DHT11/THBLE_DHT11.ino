
#include <DHT.h>

// Khai bao chan cam bien
#define DHT_PIN 4
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  // Khoi dong UART
  Serial.begin(9600);

  // Khoi dong cam bien DHT11
  dht.begin();

  delay(2000);
  Serial.println("BAT DAU DOC DHT11");
}

void loop() {
  // Doc do am va nhiet do
  float doAm = dht.readHumidity();
  float nhietDo = dht.readTemperature();

  // Kiem tra loi doc cam bien
  if (isnan(doAm) || isnan(nhietDo)) {
    Serial.println("ERROR");
    delay(2000);
    return;
  }

  // Gui du lieu theo dinh dang de Node.js doc
  Serial.print("T:");
  Serial.print(nhietDo, 1);

  Serial.print(",H:");
  Serial.println(doAm, 1);

  // DHT11 nen doc cach nhau khoang 2 giay
  delay(2000);
}
