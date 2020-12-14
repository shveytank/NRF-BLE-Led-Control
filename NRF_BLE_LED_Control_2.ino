#include <RF24.h>
#include <BTLE.h>

RF24 radio(9, 10);
BTLE btle(&radio);
String DeviceName="OnePlus 7";
void setup() {
  Serial.begin(9600);
  while (!Serial) { }
  Serial.println("BTLE LED Control");
  btle.begin("");
  }
void loop() {
  String string="";
   if (btle.listen()) 
   {
    for (uint8_t i = 2; i &&(btle.buffer.pl_size) - 6; i++)
    {
    string = string + (char(btle.buffer.payload[i]));
    //Serial.println(string);
    //Serial.println(char(btle.buffer.payload[i],HEX));
    //Serial.print(" ");
    }
    if (string.startsWith(DeviceName)) 
    {
      //Serial.println(string);
      string.replace(DeviceName,"");
      Serial.println(string);
      pinMode((string.charAt(2)),1);
      digitalWrite((string.charAt(2)),(string.charAt(3)));
    }
  }
}
