  #include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <FS.h>
const char* ssid = "bgreen";
const char* password = "92221234";

void setup() {
  // put your setup code here, to run once:
   pinMode(D1,OUTPUT);
   Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
 if (!SPIFFS.begin()) {
    Serial.println("Failed to mount SPIFFS");
    return;
  }

  // Open the file
  File file = SPIFFS.open("dictionary.txt", "r");
  if (!file) {
    Serial.println("Failed to open file");
    ///return;
  }
   File file2 = SPIFFS.open("/data.txt", "w");
  if (!file) {
    Serial.println("Failed to create file");
   // return;
  }

  // Write data to the file
  file2.println("Hello, World!");
  file.println("This is a test file.");

  // Close the file
  file.close();

  Serial.println("File saved");

}

void loop() {
  // put your main code here, to run repeatedly:
   while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
   
    Serial.println("Connecting to WiFi..");
   //wifi.begin(ssid,pass);
  }
  // Print ESP32 Local IP Address
 // Serial.println(WiFi.localIP());
  delay(1000);
}
