// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain
#include "DHT.h"
#include <SoftwareSerial.h>
// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
#define DHTPIN 2     // what pin we're connected to（DHT10 and DHT20 don't need define it）
DHT dht(DHTPIN, DHTTYPE);   //   DHT11 DHT21 DHT22
//DHT dht(DHTTYPE);         //   DHT10 DHT20 don't need to define Pin
char received_data;
// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
int send = 1;

#if defined(ARDUINO_ARCH_AVR)
    #define debug  Serial

#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
    #define debug  SerialUSB
#else
    #define debug  Serial
#endif
SoftwareSerial USART(4, 5);
void setup() {
    Serial.begin(115200);
   //USART.begin(9600);
    //USART.begin(9600);
    Wire.begin();
    
    
  
    /*if using WIO link,must pull up the power pin.*/
    // pinMode(PIN_GROVE_POWER, OUTPUT);
    // digitalWrite(PIN_GROVE_POWER, 1);

    dht.begin();
}

void loop() {
  float temperature = 0.0;
  float humidity = 0.0;
  temperature = dht.readTemperature(); // Read Temperature and DHT from Sensor
  humidity = dht.readHumidity();
  if (isnan(temperature) || isnan(humidity)) {
    Serial.print("Failed to read data from DHT sensor!");
  } else {
  Serial.println(temperature);
  Serial.println(humidity);
    // Send temperature and humidity data to STM32 via serial communication
    delay(100);  // Delay between readings
  }
}
