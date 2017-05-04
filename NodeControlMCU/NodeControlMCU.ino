#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
// pin 4 -> SCL D2
// pin 5 -> SDA D1
//
const char* ssid = "AccessControl";
const char* password = "";

WiFiServer server(80);

//set pin
const int output1 = 16; // D0
const int output2 = 0;  // D3
const int output3 = 2;  // D4
const int output4 = 14; // D5
const int output5 = 12; // D6
const int output6 = 13; // D7
const int output7 = 15; // D8
const int output8 = 10; // SD3

//set status
boolean device1 = false;
boolean device2 = false;
boolean device3 = false;
boolean device4 = false;
boolean device5 = false;
boolean device6 = false;
boolean device7 = false;
boolean device8 = false;

//sensor
float amp = 0;
int pin = A0;
int i = 0;

void setup() {
  //set pin mode
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);
  pinMode(output5, OUTPUT);
  pinMode(output6, OUTPUT);
  pinMode(output7, OUTPUT);
  pinMode(output8, OUTPUT);

  digitalWrite(output1, HIGH);
  digitalWrite(output2, HIGH);
  digitalWrite(output3, HIGH);
  digitalWrite(output4, HIGH);
  digitalWrite(output5, HIGH);
  digitalWrite(output6, HIGH);
  digitalWrite(output7, HIGH);
  digitalWrite(output8, HIGH);

  // initialize the LCD
	lcd.begin();
  lcd.print("Hello (^__^)");
  lcd.setCursor(0, 1);

  Serial.begin(115200);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP()); // show IP at serial

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  lcd.clear();
  lcd.print("WiFi connected");
  lcd.setCursor(0, 1);
  delay(1500);
  lcd.print("Server started");
  delay(2000);
  lcd.clear();
}

void loop() {

  //Show IP on LCD
  lcd.setCursor(0, 0);
  lcd.print(WiFi.localIP());

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    //Serial.print("*");
    return;
  }

  // Wait until the client sends some data
  /*Serial.println("new client");
  while(!client.available()){
    delay(1);
  }*/

  i = analogRead(pin);
  amp = (((long)i * 5000 / 1024) - 500 ) * 1000 / 133;
  amp = amp/1000;

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  Serial.println(".......................");
  client.flush(); //read first lines command

  // Match the request ................. //
  //device1
  if (req.indexOf("/led1on") != -1)  {
    digitalWrite(output1, LOW);
    device1 = true;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 1 on");
  }
  else if (req.indexOf("/led1off") != -1)  {
    digitalWrite(output1, HIGH);
    device1 = false;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 1 off");
  }

  //device2
  else if (req.indexOf("/led2on") != -1)  {
    digitalWrite(output2, LOW);
    device2 = true;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 2 on");
  }
  else if (req.indexOf("/led2off") != -1)  {
    digitalWrite(output2, HIGH);
    device2 = false;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 2 off");
  }

  //device3
  else if (req.indexOf("/led3on") != -1)  {
    digitalWrite(output3, LOW);
    device3 = true;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 3 on");
  }
  else if (req.indexOf("/led3off") != -1)  {
    digitalWrite(output3, HIGH);
    device3 = false;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 3 off");
  }

  //device4
  else if (req.indexOf("/led4on") != -1)  {
    digitalWrite(output4, LOW);
    device4 = true;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 4 on");
  }
  else if (req.indexOf("/led4off") != -1)  {
    digitalWrite(output4, HIGH);
    device4 = false;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 4 off");
  }

  //device5
  else if (req.indexOf("/led5on") != -1)  {
    digitalWrite(output5, LOW);
    device5 = true;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 5 on");
  }
  else if (req.indexOf("/led5off") != -1)  {
    digitalWrite(output5, HIGH);
    device5 = false;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 5 off");
  }

  //device6
  else if (req.indexOf("/led6on") != -1)  {
    digitalWrite(output6, LOW);
    device6 = true;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 6 on");
  }
  else if (req.indexOf("/led6off") != -1)  {
    digitalWrite(output6, HIGH);
    device6 = false;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 6 off");
  }

  //device7
  else if (req.indexOf("/led7on") != -1)  {
    digitalWrite(output7, LOW);
    device7 = true;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 7 on");
  }
  else if (req.indexOf("/led7off") != -1)  {
    digitalWrite(output7, HIGH);
    device7 = false;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 7 off");
  }

  //device8
  else if (req.indexOf("/led8on") != -1)  {
    digitalWrite(output8, LOW);
    device8 = true;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 8 on");
  }
  else if (req.indexOf("/led8off") != -1)  {
    digitalWrite(output8, HIGH);
    device8 = false;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Device 8 off");
  }

  //.....................................//

  //HTML
  String cmd;
    cmd += "<!DOCTYPE HTML>\r\n";
    cmd += "<html>\r\n";
    cmd += "<header><title>ESP8266 Webserver</title></header>";
    cmd += "<head>";
    cmd += "<meta http-equiv='refresh' content='5'/>";
    cmd += "</head>";
    cmd += "";

    cmd += "Current : ";
    cmd += (amp);
    cmd += " A";
    cmd += "<br/>";

    if(device1){
      cmd +=("<br/>Device1  : ON ");
    }
    else{
      cmd +=("<br/>Device1  : OFF ");
    }
    cmd += "<a href=\"/led1on\"\"><button>Turn On </button></a>";
    cmd += "<a href=\"/led1off\"\"><button>Turn Off </button></a><br />";

    if(device2){
      cmd +=("<br/>Device2  : ON ");
    }
    else{
      cmd +=("<br/>Device2  : OFF ");
    }
    cmd += "<a href=\"/led2on\"\"><button>Turn On </button></a>";
    cmd += "<a href=\"/led2off\"\"><button>Turn Off </button></a><br />";

    if(device3){
      cmd +=("<br/>Device3  : ON ");
    }
    else{
      cmd +=("<br/>Device3  : OFF ");
    }
    cmd += "<a href=\"/led3on\"\"><button>Turn On </button></a>";
    cmd += "<a href=\"/led3off\"\"><button>Turn Off </button></a><br />";

    if(device4){
      cmd +=("<br/>Device4  : ON ");
    }
    else{
      cmd +=("<br/>Device4  : OFF ");
    }
    cmd += "<a href=\"/led4on\"\"><button>Turn On </button></a>";
    cmd += "<a href=\"/led4off\"\"><button>Turn Off </button></a><br />";

    if(device5){
      cmd +=("<br/>Device5  : ON ");
    }
    else{
      cmd +=("<br/>Device5  : OFF ");
    }
    cmd += "<a href=\"/led5on\"\"><button>Turn On </button></a>";
    cmd += "<a href=\"/led5off\"\"><button>Turn Off </button></a><br />";

    if(device6){
      cmd +=("<br/>Device6  : ON ");
    }
    else{
      cmd +=("<br/>Device6  : OFF ");
    }
    cmd += "<a href=\"/led6on\"\"><button>Turn On </button></a>";
    cmd += "<a href=\"/led6off\"\"><button>Turn Off </button></a><br />";

    if(device7){
      cmd +=("<br/>Device7  : ON ");
    }
    else{
      cmd +=("<br/>Device7  : OFF ");
    }
    cmd += "<a href=\"/led7on\"\"><button>Turn On </button></a>";
    cmd += "<a href=\"/led7off\"\"><button>Turn Off </button></a><br />";

    if(device8){
      cmd +=("<br/>Device8  : ON ");
    }
    else{
      cmd +=("<br/>Device8  : OFF ");
    }
    cmd += "<a href=\"/led8on\"\"><button>Turn On </button></a>";
    cmd += "<a href=\"/led8off\"\"><button>Turn Off </button></a><br />";

    cmd += "</html>\r\n";
    //server.send(200, "text/html", cmd);
    client.print(cmd);
}
