#include <Arduino.h>


#define  ANALOGE_1 A1
#define  INPUT_VOLTAGE 5.0

int tempSensorPin = ANALOGE_1; // select the input pin for LDR

int sensorValue = 0, mappedValue = 0; // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600); //sets serial port for communication
}
void loop() {
  sensorValue = analogRead(tempSensorPin); // read the value from the sensor
  float voltage = (sensorValue * INPUT_VOLTAGE) / 1024;
  // print out the voltage
  Serial.print(voltage); Serial.println(" volts");

  // now print out the temperature
  float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
  Serial.print(temperatureC); Serial.println(" degrees C");

  mappedValue = map(sensorValue, 0, INPUT_VOLTAGE, 0, 5);
  Serial.println(mappedValue); //prints the values coming from the sensor on the screen

  delay(500);

}
