////////////////////////////////////////////////////////////////////////////////////
//
//                               PI and more
//                         ESP8266 and deep Sleep
//
// https://piandmore.wordpress.com/2016/11/08/deep-sleep-esp8266/
//
////////////////////////////////////////////////////////////////////////////////////
//

//
// Include the library to support auto connect to wifi
// Remember to upload the wifi credentials to the file systems
// See https://piandmore.wordpress.com/tag/pam_wificonnect for more information
//
#include <PAM_WiFiConnect.h>
//
// The library with the API for ThingSpeak and IFTTT
//
#include <PAM_WebAPI.h>
//
// Include the ESP8266 wifi library
//
#include <ESP8266WiFi.h>
//
// Include the LM75A library
//
#include <LM75A.h>

//
// Initialize the LM75A library
//
LM75A lm75a_sensor;

void setup() {
  //
  // Turn the internal led on
  //
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  //
  // Connect to the wifi
  //
  wifiAutoConnect();
  if (WiFi.status()==WL_CONNECTED) {
    //
    // Connected to wifi
    //
    // Turn off the internal led
    //
    digitalWrite(2,HIGH);
    //
    // Read the temperature
    //
    float temperature_in_degrees = lm75a_sensor.getTemperatureInDegrees();
    //
    // Sometimes after a restart the temperature sensor needs a second read
    //
    if (temperature_in_degrees!=INVALID_LM75A_TEMPERATURE) {
      temperature_in_degrees = lm75a_sensor.getTemperatureInDegrees();
    }
    if (temperature_in_degrees!=INVALID_LM75A_TEMPERATURE) {
      //
      // Send the temperature to ThingSpeak
      //
      thingspeak(TS_TEST,temperature_in_degrees);
    } else {
      //
      // Cannot read the temperature so send an alert msg
      //
      ifttt(IFTTT_MSG,"deepSleepTemperature","Problem reading temperature");
    }
  }
  //
  // Go to deep sleep for 300 seconds (5 minutes)
  //
  ESP.deepSleep(300*1000000);
  delay(1);
}

void loop() {
}
