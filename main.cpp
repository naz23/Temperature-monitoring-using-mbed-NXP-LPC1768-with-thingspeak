#include "mbed.h"
#include "EthernetInterface.h"
int main() {
    
static const char*          mbedIp       = "192.168.137.2";  //IP
static const char*          mbedMask     = "255.255.255.0";  // Mask
static const char*          mbedGateway  = "192.168.137.1";    //Gateway

    EthernetInterface eth;
 //   eth.init(); //Use DHCP
 eth.init(mbedIp,mbedMask,mbedGateway); 
    eth.connect();
    printf("IP Address is %s\n", eth.getIPAddress());

    while(1) {}
}
