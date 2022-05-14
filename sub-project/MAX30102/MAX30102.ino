
#include <DFRobot_MAX30102.h>
DFRobot_MAX30102 particleSensor;

#include <Wire.h>

void setup()
{
Serial.begin(9600);

while (!particleSensor.begin()) {
  //lcd.println("MAX30102 was not found");
  delay(1000);
}

particleSensor.sensorConfiguration(/*ledBrightness=*/50, /*sampleAverage=*/SAMPLEAVG_4, \
                      /*ledMode=*/MODE_MULTILED, /*sampleRate=*/SAMPLERATE_100, \
                      /*pulseWidth=*/PULSEWIDTH_411, /*adcRange=*/ADCRANGE_16384);          
}

int32_t SPO2; //SPO2
int8_t SPO2Valid; //Flag to display if SPO2 calculation is valid
int32_t heartRate; //Heart-rate
int8_t heartRateValid; //Flag to display if heart-rate calculation is valid

void loop()
{
 particleSensor.heartrateAndOxygenSaturation(/**SPO2=*/&SPO2, /**SPO2Valid=*/&SPO2Valid, /**heartRate=*/&heartRate, /**heartRateValid=*/&heartRateValid);
 

if (heartRateValid == 1){
Serial.print(F("SPO2: "));
Serial.print(SPO2, DEC);
} else if (heartRateValid == 0) {
Serial.print(F("SPO2: 0"));
Serial.print("%");

}
 delay(10);
}
