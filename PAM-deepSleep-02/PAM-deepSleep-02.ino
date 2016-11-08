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
    // Send a message through IFTTT
    //
    ifttt(IFTTT_BOOT,"deepSleepTest",WiFi.localIP().toString());
    //
    // Save some data to a test channel on ThingSpeak
    //
    thingspeak(TS_TEST,13,22);
  }
  //
  // Go to deep sleep for 300 seconds (5 minutes)
  //
  ESP.deepSleep(300*1000000);
  delay(1);
}

void loop() {
}
