#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "..........";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Your_WIFI_NAME";
char pass[] = "Your_WIFI_password";

#include <SoftwareSerial.h>
int analogInput = A0;
float vout = 0.0;
float vin = 0.0;
float R1 = 96700; //<-- here u must enter ur R1 value
float R2 = 9400;  //<-- here u must enter ur R2 value
int value = 0;

void setup() {
 pinMode(analogInput, INPUT);
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);
 Blynk.virtualWrite(V6,vin);
 }
void loop() {
 value = analogRead(analogInput) - 10;
 vout = (value * 3.3) / 1024.0;
 vin = vout / (R2/(R1+R2));
 if (vin <= 2) {
 vin = vin - 0.13;
 Serial.print("INPUT V= ");
 Serial.println(vin);
 Serial.println(value);
 Blynk.virtualWrite(V6,vin);
 };
 if (vin >2 && vin <=5) {
 vin = vin - 0.2;
 Serial.print("INPUT V= ");
 Serial.println(vin);
 Serial.println(value);
 Blynk.virtualWrite(V6,vin);
 }; 
 
 if (vin > 5 && vin <= 9){
 vin = vin - 0.48;
 Serial.print("INPUT V= ");
 Serial.println(vin);
 Serial.println(value);
 Blynk.virtualWrite(V6,vin);
 };

 
 if (vin > 9  &&  vin <= 18){
 vin = vin - 0.78;
 Serial.print("INPUT V= ");
 Serial.println(vin,4);
 Serial.println(value);
 Blynk.virtualWrite(V6,vin);
 };
 
 delay(1000);
 Blynk.run();
}
