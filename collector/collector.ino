#include <SPI.h>
#include <Ethernet.h>
#include <Streaming.h>


byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress server(192,168,1,102);
EthernetClient client;

float temperature = 26.1, moisture = 60.5;
int sensorData = 0;
unsigned long past = 0;
const unsigned long interval = 3000L;

void setup() {

    pinMode(7, INPUT);

    Serial.begin(9600);
    Ethernet.begin(mac);
  
    delay(5000);
    Serial.println("Connecting...");

}

void loop() {
  
 
  if(millis() - past > interval){
     sensorData = digitalRead(7);
     sendJSON();
  }
  
}

void readData(){
  sensorData = digitalRead(7);
  //Serial.println(sensorData);
}

void sendJSON(){

  client.stop();
  if(client.connect(server, 8080)){
    Serial.println("Connected!!!");
    
    client << "GET /data?DHT11={\"temp\":" << temperature
           << ",\"moist\":" << moisture
           << ",\"sensorData\":" << sensorData
           << "} HTTP/1.1\r\n";
    client.println();

    past = millis();
  }
  else{
    past = millis();
    Serial.println("Connection failed!!!");                             
  }
}



