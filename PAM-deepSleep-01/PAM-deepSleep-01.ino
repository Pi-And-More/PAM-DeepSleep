////////////////////////////////////////////////////////////////////////////////////
//
//                               PI and more
//                         ESP8266 and deep Sleep
//
// https://piandmore.wordpress.com/2016/11/08/deep-sleep-esp8266/
//
////////////////////////////////////////////////////////////////////////////////////
//

void setup() {
  //
  // Turn the internal led on
  //
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  //
  // Wait one second
  //
  delay(1000);
  //
  // Go to deep sleep for 30 seconds
  //
  ESP.deepSleep(30*1000000);
  delay(1);
}

void loop() {
}
