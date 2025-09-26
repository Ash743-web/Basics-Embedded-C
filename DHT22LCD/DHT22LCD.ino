#include "DHT.h"
#include <LiquidCrystal_I2C.h>
#define redLED 10
#define greenLED 12
#define DHTPIN 5    // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd (0x27, 16,2);  //
 
void setup() {
  lcd. init ();
  lcd. backlight ();
  
  Serial.begin(9600);
 // Serial.println(F("DHT11 test!"));
  dht.begin();
  lcd.print ( "DHT22 test!" );
  delay(1000);
  lcd.clear();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    lcd.setCursor(0,0);
    lcd.print(F("Failed DHT22"));
    delay(1000);
    lcd.clear();
    return;
  }
  if(t>=50)
  {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  else
  {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  lcd.setCursor(0,0);
  lcd.print(F("Humidity: "));
  lcd.setCursor(10,0);
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print(F("%Temperature:"));
  lcd.setCursor(14,1);
  lcd.print(t);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("°C:"));
  lcd.setCursor(3,0);
  lcd.print(f);
  lcd.setCursor(0,1);
  lcd.print(F("°F Heat index:"));
  lcd.setCursor(14,1);
  lcd.print(hic);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("°C:"));
  lcd.setCursor(4,0);
  lcd.print(hif);
  lcd.setCursor(0,1);
  lcd.print(F("°F"));
 /* if(t>=50)
  {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  else
  {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }*/
}
