
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLEAdvertising.h>
#include <Adafruit_NeoPixel.h>

// LED RGB tich hop tren ESP32-S3
#define LED_PIN 48
#define NUM_LEDS 1

Adafruit_NeoPixel led(
  NUM_LEDS,
  LED_PIN,
  NEO_GRB + NEO_KHZ800
);

// Ten Bluetooth hien tren dien thoai
#define BLE_NAME "LINH_BLE"

// UUID cua Service va Characteristic
#define SERVICE_UUID "12345678-1234-1234-1234-1234567890ab"
#define CHAR_UUID    "12345678-1234-1234-1234-1234567890ac"

// Xu ly lenh dieu khien LED RGB
class MyCallbacks : public BLECharacteristicCallbacks {

  void onWrite(BLECharacteristic *pCharacteristic) override {

    auto value = pCharacteristic->getValue();

    // Khong xu ly neu khong co du lieu
    if (value.length() == 0) return;

    // Lay ky tu lenh dau tien
    char lenh = value[0];

    Serial.print("Nhan lenh: ");
    Serial.println(lenh);

    // A: Mau do
    if (lenh == 'A' || lenh == 'a') {
      led.setPixelColor(0, led.Color(255, 0, 0));
      Serial.println("LED mau DO");
    }

    // B: Mau xanh la
    else if (lenh == 'B' || lenh == 'b') {
      led.setPixelColor(0, led.Color(0, 255, 0));
      Serial.println("LED mau XANH LA");
    }

    // C: Mau vang
    else if (lenh == 'C' || lenh == 'c') {
      led.setPixelColor(0, led.Color(255, 255, 0));
      Serial.println("LED mau VANG");
    }

    // D: Mau cam
    else if (lenh == 'D' || lenh == 'd') {
      led.setPixelColor(0, led.Color(255, 80, 0));
      Serial.println("LED mau CAM");
    }

    // E: Mau hong
    else if (lenh == 'E' || lenh == 'e') {
      led.setPixelColor(0, led.Color(255, 0, 100));
      Serial.println("LED mau HONG");
    }

    // Hien thi mau LED
    led.show();
  }
};

// Xu ly ket noi Bluetooth
class ServerCallbacks : public BLEServerCallbacks {

  void onConnect(BLEServer *pServer) override {
    Serial.println("Dien thoai da ket noi!");
  }

  void onDisconnect(BLEServer *pServer) override {
    Serial.println("Da ngat ket noi!");

    // Phat lai Bluetooth de dien thoai ket noi lai
    BLEDevice::startAdvertising();
  }
};

void setup() {

  // Khoi dong Serial Monitor
  Serial.begin(115200);

  // Khoi tao LED RGB
  led.begin();
  led.clear();
  led.setBrightness(100);
  led.show();

  // Khoi tao Bluetooth BLE
  BLEDevice::init(BLE_NAME);

  // Tao Bluetooth Server
  BLEServer *server = BLEDevice::createServer();
  server->setCallbacks(new ServerCallbacks());

  // Tao Service
  BLEService *service =
    server->createService(SERVICE_UUID);

  // Tao Characteristic nhan lenh tu dien thoai
  BLECharacteristic *characteristic =
    service->createCharacteristic(
      CHAR_UUID,
      BLECharacteristic::PROPERTY_WRITE |
      BLECharacteristic::PROPERTY_WRITE_NR
    );

  // Gan ham xu ly lenh
  characteristic->setCallbacks(new MyCallbacks());

  // Bat dau Service
  service->start();

  // Cau hinh phat ten Bluetooth
  BLEAdvertising *advertising =
    BLEDevice::getAdvertising();

  BLEAdvertisementData advData;
  advData.setFlags(0x06);
  advData.setName(BLE_NAME);

  advertising->setAdvertisementData(advData);
  advertising->start();

  Serial.println("=====================");
  Serial.println("BLUETOOTH BLE DA PHAT SONG");
  Serial.println("TEN: LINH_BLE");
  Serial.println("MO NRF CONNECT DE QUET");
  Serial.println("A: DO");
  Serial.println("B: XANH LA");
  Serial.println("C: VANG");
  Serial.println("D: CAM");
  Serial.println("E: HONG");
  Serial.println("=====================");
}

void loop() {
  delay(100);
}
