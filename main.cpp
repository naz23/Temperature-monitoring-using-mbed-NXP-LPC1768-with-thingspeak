#include "mbed.h"
#include "EthernetInterface.h"

int main() 
{
    EthernetInterface eth;
    eth.init(); //Use DHCP

    eth.connect();
    
    TCPSocket sock;
    sock.connect("mbed.org", 80);
    
    char http_cmd[] = "GET /media/uploads/donatien/hello.txt HTTP/1.1\r\nHost: %s\r\n\r\n";
    sock.send(http_cmd, sizeof(http_cmd) - 1, 3000);

    char in_buf[256];      
    bool firstIteration = true;
    int ret;
    do
    {
        ret = sock.receive(in_buf, 255, firstIteration?3000:0);
        in_buf[ret] = '\0';
        
        printf("Received %d chars from server: %s\n", ret, in_buf);
        firstIteration = false;
    } while( ret > 0 );
      
    sock.close();  
    
    eth.disconnect();  

    while(1) {
    }
}
