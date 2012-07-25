#include "mbed.h"
#include "EthernetInterface.h"

int main() {
    EthernetInterface eth;
    eth.init(); //Use DHCP
    eth.connect();
    printf("IP Address is %s\n", eth.getIPAddress());
    
    TCPSocketConnection sock;
    sock.connect("mbed.org", 80);
    
    char http_cmd[] = "GET /media/uploads/donatien/hello.txt HTTP/1.1\r\nHost: %s\r\n\r\n";
    sock.send_all(http_cmd, sizeof(http_cmd) - 1, 3000);
    
    char in_buf[256];
    int ret;
    while (true) {
        ret = sock.receive(in_buf, 255, 100);
        if (ret <= 0)
            break;
        
        in_buf[ret] = '\0';
        printf("Received %d chars from server: %s\n", ret, in_buf);
    }
      
    sock.close();
    
    eth.disconnect();
    
    while(1) {
    }
}
