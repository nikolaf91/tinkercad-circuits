#include <Servo.h> // Inlcuded Tinkercard library for Servomotor

// rename sensor-pins
const int MoisturePin = A0;
const int TemperaturePin = A1;
const int LightSensorPin = A2;

// create servo-object from included library
Servo servo;

void setup()
{
  	servo.attach(13);
  	// start series
  	Serial.begin(9600);
  	Serial.println("Simulation started");
}

void loop()
{
  	// Read the sensordata
    int Moisture = analogRead(MoisturePin);
    int Temperature = analogRead(TemperaturePin);
    int LightIntensity = analogRead(LightSensorPin);      
  
    Serial.println("Moisture = = "+String(Moisture));
    Serial.println("Temperature = = "+String(Temperature));
    Serial.println("Light intensity = "+String(LightIntensity));
  
    // If soil is dry, the temperature and light intensity too high,
    // then the motor for the waterpump will be activated and set to 90
    if (Moisture < 300 && Temperature > 200 && LightIntensity > 65) {
      
      servo.write(90);
      Serial.println("Motor on");
      delay(10); //wait for 10 milliseconds
    } 
  	else {
      // else motor will be switched to 0
      servo.write(0);
      Serial.println("Motor off");
      delay(10); //wait for 10 milliseconds
    }

    // Wait 1 second until next measurement
    delay(2000);

}