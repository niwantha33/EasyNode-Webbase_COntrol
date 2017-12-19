/*======================================================================*/
/* This code example is to control 13,12,14 and 16 pins of the EasyNode */
/* Auth: Niwantha for Algobel on 19yh December 2017                                           */
/* Based on html button method and reading argument which return from   */
/* Web header                                                           */
/*======================================================================*/

/*======================================================================*/
/*calling  WiFi interface libraries and configuration details           */
#include <ESP8266WiFi.h>
const char* ssid = "TP"; // Router SSID 
const char* password = "12345678"; // Router Password
WiFiServer server(80);
/*======================================================================*/

void setup() {

/*======================================================================*/
/* Setting hardware on EasyNode module                                  */

  Serial.begin(115200);  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(16, OUTPUT);  
/*======================================================================*/


/*======================================================================*/
/* WiFi interface accessing                                             */

  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  server.begin();
  Serial.print(WiFi.localIP()); 
  /*======================================================================*/
}

void loop() {
   /*======================================================================*/  
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  /*======================================================================*/
  
   /*======================================================================*/
  // Wait until the client sends some data
 
  while(!client.available()){
    delay(1);
  }
   /*======================================================================*/
   
   
  /*======================================================================*/
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  /*======================================================================*/
  
   /*======================================================================*/
  // Match the request
 
  
  if (request.indexOf("/LED_13=ON") != -1)  {
    digitalWrite(13, HIGH);   
  }
  if (request.indexOf("/LED_13=OFF") != -1)  {
    digitalWrite(13, LOW);   
  }   
  if (request.indexOf("/LED_12=ON") != -1)  {
    digitalWrite(12, HIGH);    
  }
  if (request.indexOf("/LED_12=OFF") != -1)  {
    digitalWrite(12, LOW);    
  }
    if (request.indexOf("/LED_14=ON") != -1)  {
    digitalWrite(12, HIGH);    
  }
  if (request.indexOf("/LED_14=OFF") != -1)  {
    digitalWrite(12, LOW);    
  }
    if (request.indexOf("/LED_16=ON") != -1)  {
    digitalWrite(12, HIGH);    
  }
  if (request.indexOf("/LED_16=OFF") != -1)  {
    digitalWrite(12, LOW);    
  }
 /*======================================================================*/
 
 
  /*======================================================================*/
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<br><br>");
  /*======================================================================*/
  
  /*======================================================================*/
  // HTML Buttons 
  
  client.println("<a href=\"/LED_13=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED_13=OFF\"\"><button>Turn Off </button></a><br />");  
  client.println("<a href=\"/LED_12=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED_12=OFF\"\"><button>Turn Off </button></a><br />");  
  client.println("<a href=\"/LED_14=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED_14=OFF\"\"><button>Turn Off </button></a><br />");  
  client.println("<a href=\"/LED_16=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED_16=OFF\"\"><button>Turn Off </button></a><br />");  
  client.println("</html>"); 
  delay(1);
   /*======================================================================*/
  Serial.println("Client disonnected");
  Serial.println("");
 
}










