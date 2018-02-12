#include "mbed.h"
#include "EthernetInterface.h"
#include "LM75B.h"
#include "HTTPClient.h"


LM75B tmp(p28,p27); // temperature sensor
char* thingSpeakUrl = "http://api.thingspeak.com/update";
char* thingSpeakKey = "C9T47QDLBY4NU7MW";
char buffer[256];


void ethernetSetup(){
//static const char*          mbedIp       = "192.168.137.2";  //IP
//static const char*          mbedMask     = "255.255.255.0";  // Mask
//static const char*          mbedGateway  = "192.168.137.1";    //Gateway

EthernetInterface eth;
    eth.init(); //Use DHCP
//eth.init(mbedIp,mbedMask,mbedGateway); 
    eth.connect();
    printf("IP Address is %s\n", eth.getIPAddress());
    
    }
    
void thingspeak(){
    HTTPClient http;
    buffer[0] = 0;
    sprintf(buffer,"%s?key=%s&field2=%2f",thingSpeakUrl,thingSpeakKey,tmp.read());
    printf("Send to %s\r\n", buffer);
    http.get(buffer, buffer , 10); // Execute the URL of urlBuffer
    
    }

int main() {
    ethernetSetup();
    
    while(1) {
        thingspeak();
        
        }
}
