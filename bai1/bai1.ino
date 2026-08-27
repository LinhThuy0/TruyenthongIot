/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/
#define LED_1 7
#define LED_2 6
#define LED_3 5
#define LED_4 4
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
   digitalWrite(LED_1, HIGH);
  delay(300);
  digitalWrite(LED_1, LOW);

  // LED 2
  digitalWrite(LED_2, HIGH);
  delay(300);
  digitalWrite(LED_2, LOW);

  // LED 3
  digitalWrite(LED_3, HIGH);
  delay(300);
  digitalWrite(LED_3, LOW);

  // LED 4
  digitalWrite(LED_4, HIGH);
  delay(300);
  digitalWrite(LED_4, LOW);  

//
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_4, LOW);

  delay(300);

  // D1 và D3 tắt
  // D2 và D4 sáng
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, HIGH);

  delay(300);  
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
  delay(300);

}
