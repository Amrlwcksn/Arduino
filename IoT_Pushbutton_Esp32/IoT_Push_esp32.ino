#define BLYNK_TEMPLATE_ID "TMPL65HKH9IXx"
#define BLYNK_TEMPLATE_NAME "komputer"
#define BLYNK_AUTH_TOKEN "esT0pcnqIMBFixUqjPyaRjieXsa9Q3HD"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Ratio";
char pass[] = "20051510Am";

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
