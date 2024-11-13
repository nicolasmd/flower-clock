#include "Network.h"


void Network::connect()
{
    //Serial.begin(9600);
    //Serial.println("Connection");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        //Serial.print(".");
    }
    //Serial.println("Connected");
}

// @todo
void Network::getPageContent(String url)
{
    if (this->_client.connect(host, 80))
    {
        this->_client.print(String("GET /") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n" + "\r\n");
        while (this->_client.connected())         {
            line = this->_client.readStringUntil('\r');
        }
        this->_client.stop();
    }

    /*String t = this->_getExplodeValue(line, '|', timeFunctions.getWeekDay());
    alr = t.toInt();*/
}


String Network::_getExplodedValue(String data, char separator, int index) {
    int found = 0;
    int strIndex[] = {0, -1};
    int maxIndex = data.length() - 1;

    for(int i = 0; i <= maxIndex && found <= index; i++) {
        if(data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1]+1;
            strIndex[1] = (i == maxIndex) ? i + 1 : i;
        }
    }

    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}