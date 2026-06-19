/***************************************************
   Blynk IoT + ESP32 + DHT22 + 16x2 LCD + TRIAC Control
****************************************************/
#define BLYNK_TEMPLATE_ID "TMPL3tzmvCZxl"
#define BLYNK_TEMPLATE_NAME "TEMP and DELAY"
#define BLYNK_AUTH_TOKEN "Iei4avrekYzvcclX_V8-efy8mlQtfM1V"

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BlynkSimpleEsp32.h>

// ---- DHT Sensor ----
#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// ---- LCD ----
LiquidCrystal_I2C lcd(0x27, 16, 2); // If not working, try 0x3F

// ---- TRIAC & Zero-Cross ----
int zeroc = 5;   // Zero-cross input pin
int triac = 4;   // TRIAC gate output pin
volatile bool zeroCrossDetected = false;
volatile unsigned int firingDelay = 10000; // µs delay after zero cross

// ---- Variables ----
float temperature = 0.0;
unsigned long lastTempRead = 0;

// ---- WiFi Credentials ----
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_NAME";  
char pass[] = "YOUR_WIFI_PASS";  

// ---- Interrupt for Zero Cross ----
void IRAM_ATTR zeroCrossISR() {
  zeroCrossDetected = true;
}

void setup() {
  Serial.begin(115200);

  pinMode(triac, OUTPUT);
  pinMode(zeroc, INPUT);

  dht.begin();
  attachInterrupt(digitalPinToInterrupt(zeroc), zeroCrossISR, RISING);

  // ---- LCD Init ----
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Starting...");
  delay(1000);

  // ---- Blynk Init ----
  Blynk.begin(auth, ssid, pass);

  Serial.println("System Ready");
}

void loop() {
  Blynk.run();

  unsigned long currentTime = millis();

  // Read temperature every 2 seconds
  if (currentTime - lastTempRead > 2000) {
    float temp = dht.readTemperature();
    if (!isnan(temp)) {
      temperature = temp;

      // ---- Display on LCD ----
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(temperature);
      lcd.print("C");

      lcd.setCursor(0, 1);
      lcd.print("Delay: ");
      lcd.print(firingDelay);
      lcd.print("us");

      // ---- Send to Blynk ----
      Blynk.virtualWrite(V0, temperature); // Temperature
      Blynk.virtualWrite(V1, firingDelay); // Delay

      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.print(" °C, Delay: ");
      Serial.print(firingDelay);
      Serial.println(" µs");
    } else {
      Serial.println("Failed to read temperature!");
    }
    lastTempRead = currentTime;
  }

  // ---- TRIAC control ----
  if (zeroCrossDetected) {
    delayMicroseconds(firingDelay);
    digitalWrite(triac, HIGH);
    delayMicroseconds(100); // TRIAC trigger pulse
    digitalWrite(triac, LOW);
    zeroCrossDetected = false;
  }
}
