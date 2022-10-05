#include <ThingSpeak.h>
#include <ESP8266WiFi.h>

#define IP "184.106.153.149" //thingspeak ip

const int analogPin = A0;
float gerilim;
float sicaklik;
float sensor;

//----------- Wi-Fi Bilgileri---------//
char ssid[] = "Melih"; //id
char pass[] = "melihozmen"; // sifre
//-------------------------------------------//



WiFiClient  client;

unsigned long kanalNumarasi = 1842544; 
const int FieldNumber = 1;
const char * myWriteAPIKey = "XZNI3UF7X8RRQFNY"; 

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(" baglanmaya calisiliyor: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nBaglandi.");
 
 
 }
 
  sensor = analogRead(analogPin);  /* sıcaklık okunr */
  gerilim = (sensor/1023)*3300; /* gerilim degeri */
  sicaklik = (gerilim / 10); /* LM35 10mv/°C verir */
  Serial.print("Temperature = ");
  Serial.print(sicaklik);
  Serial.println(" *C");

  ThingSpeak.writeField(kanalNumarasi, FieldNumber, sicaklik, myWriteAPIKey);
  
     if (sicaklik > 0)
     {
      sicaklik_gonder();
     }
  
  delay(1000);
}

void sicaklik_gonder() 
{
  Serial.println(String("AT+CIPSTART=\"TCP\",\"") + IP + "\",80"); //thingspeak sunucusuna bağlanmak için kod 
  //AT+CIPSTART ile sunucuya bağlanmak için sunucudan izin istiyoruz. 
  //TCP burada bağlantı çeşidini gösteriyor. 80 ise portu gösteriyor
  delay(1500);
  String tweet = "POST /apps/thingtweet/1/statuses/update HTTP/1.1\n";
  tweet += "Host: api.thingspeak.com\n";
  tweet += "Connection: close\n";
  tweet += "Content-Type: application/x-www-form-urlencoded\n";
  tweet += "Content-Length:50\r\n\r\napi_key=";
  tweet += String("KAMJP4PCTPBSBXYO"); //Twitter API KEY i buraya yazıyoruz.
  tweet += String("&status=");
  tweet += String("Baya Sıcak #esp8266"); // Yollamak istediğimiz tweeti buraya yazıyoruz.
}
