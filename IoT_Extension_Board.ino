/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "5ide4pAHsFStJO7turIxt93heFB6S6e-";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Miss you";
char pass[] = "Hotspot@123";

int onSwitches = 0;

BLYNK_CONNECTED()
{
    Blynk.syncAll();
}

BLYNK_WRITE(V0)       // Button Widget is writing to Pin V0
{
  if(param.asInt())   // As active low pin, so 1 means all ports off
  {
    digitalWrite(D1,HIGH);
    Blynk.virtualWrite(V1,1);
    digitalWrite(D2,HIGH);
    Blynk.virtualWrite(V2,1);
    digitalWrite(D5,HIGH);
    Blynk.virtualWrite(V3,1);
    digitalWrite(D6,HIGH);
    Blynk.virtualWrite(V4,1);
    onSwitches = 0;
  }
  else                // As active low pin, so 0 means all ports on
  {
    digitalWrite(D1,LOW);
    Blynk.virtualWrite(V1,0);
    digitalWrite(D2,LOW);
    Blynk.virtualWrite(V2,0);
    digitalWrite(D5,LOW);
    Blynk.virtualWrite(V3,0);
    digitalWrite(D6,LOW);
    Blynk.virtualWrite(V4,0);
    onSwitches = 4;
  }
}

BLYNK_WRITE(V1)       // Button Widget is writing to Pin V1
{
  if(param.asInt())
  {
    digitalWrite(D1,HIGH);
    onSwitches--;
  }
  else
  {
    digitalWrite(D1,LOW);  
    onSwitches++;
  }
}

BLYNK_WRITE(V2)       // Button Widget is writing to Pin V2
{
  if(param.asInt())
  {
    digitalWrite(D2,HIGH);
    onSwitches--;
  }
  else
  {
    digitalWrite(D2,LOW);  
    onSwitches++;
  }
}

BLYNK_WRITE(V3)       // Button Widget is writing to Pin V3
{
  if(param.asInt())
  {
    digitalWrite(D5,HIGH);
    onSwitches--;
  }
  else
  {
    digitalWrite(D5,LOW);  
    onSwitches++;
  }
}

BLYNK_WRITE(V4)       // Button Widget is writing to Pin V4
{
  if(param.asInt())
  {
    digitalWrite(D6,HIGH);
    onSwitches--;
  }
  else
  {
    digitalWrite(D6,LOW); 
    onSwitches++;
  } 
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D1,OUTPUT);   // Port 1
  digitalWrite(D1,HIGH);
  pinMode(D2,OUTPUT);   // Port 2
  digitalWrite(D2,HIGH);
  pinMode(D5,OUTPUT);   // Port 3
  digitalWrite(D5,HIGH);
  pinMode(D6,OUTPUT);   // Port 4
  digitalWrite(D6,HIGH);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  if(onSwitches == 4)
  {
    Blynk.virtualWrite(V0,0);   // V0 on
  }
  else
    Blynk.virtualWrite(V0,1);   // V0 off
}
