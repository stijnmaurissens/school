#include <BH1750.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

BH1750 lightMeter;
#define SDA_1 22
#define SCL_1 21

#define ADC_VREF_mV    3300.0 // in millivolt
#define ADC_RESOLUTION 4096.0
#define PIN_LM35       36

void setup() {
  Serial.begin(9600);
analogSetAttenuation(ADC_11db);

  Wire.begin(SCL_1,SDA_1);//voor de lichtsensor
  //Wire1.begin(SCL_1,SDA_1);//voor het lcd scherm

  lightMeter.begin(BH1750::CONTINUOUS_LOW_RES_MODE, 0x23, &Wire);
  Serial.println(F("BH1750 Test begin"));
}

void loop() {
  //float temp = (analogRead(26)* 0.080586);
  //Serial.println(temp);
  float lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
   // read the ADC value from the temperature sensor
  float tempsens = analogRead(PIN_LM35);
  float temp = tempsens;
  Serial.println(temp);   // print the temperature in °C
  //lcd.clear();

  delay(1000);
}
