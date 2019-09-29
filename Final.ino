#include <SPI.h>
#include <Ethernet.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Ethernet.h>
#include <Adafruit_Fingerprint.h>

SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
uint8_t id;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = {192, 168, 0, 100}; //Enter the IP of ethernet shield
byte serv[] = {192, 168, 0, 102} ; //Enter the IPv4 address
LiquidCrystal lcd(A1, A0, 8, 7, 6, 5);
EthernetClient cliente;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600); //setting the baud rate at 9600
  Ethernet.begin(mac, ip);
  pinMode(A0, OUTPUT);

  Serial.begin(9600);
  while (!Serial);
  delay(100);
  Serial.println("\n\nAdafruit Fingerprint sensor enrollment");

  // set the data rate for the sensor serial port
  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
    lcd.println("Found sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    lcd.println("Not found :(");
    /*while (1) { delay(1); }*/
    delay(10000);
  }
}

uint8_t readnumber(void) {
  uint8_t num = 0;

  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;

}

String readstring(void) {
  String str = "";

  while (str == "") {
    while (! Serial.available());
    str = Serial.readString();
  }
  return str;

}

void loop() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fingerprint");
  lcd.setCursor(0, 1);
  lcd.print("System");

 
  if (digitalRead(A3) == HIGH) {
    int finger_id = getFingerprintID();

    Serial.print(finger_id);

    if (finger_id != 254) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Welcome!" + finger_id);


      
      if (cliente.connect(serv, 80)) { //Connecting at the IP address and port we saved before
        Serial.println("connected");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Connected");

        String query = "GET /fingerprint-database/data.php?";
        query += "id=";
        query += finger_id;
        query += "&in_out=";
        query += 1; 
        Serial.println(query);
        cliente.println(query); //Connecting and Sending values to database


        
        cliente.stop(); //Closing the connection
        Serial.print("Closed");
        delay(5000);
      }
      else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }

      /*
      cliente.print("GET /fingerprint-database/data.php?"); //Connecting and Sending values to database
      cliente.print("id=");
      cliente.print(finger_id);
      cliente.print("&in_out=");
      cliente.println(in_out);*/
    }
    /*
      Serial.print("GET /fingerprint-database/data.php?"); //Connecting and Sending values to database
        Serial.print("id=");
        Serial.print(finger_id);
        cliente.print("&in_out=");
        cliente.print(in_out);
    */
    delay(5000);
  }


    if (digitalRead(A2) == HIGH) {
    int finger_id = getFingerprintID();

    Serial.print(finger_id);

    if (finger_id != 254) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Welcome!" + finger_id);

      
      if (cliente.connect(serv, 80)) { //Connecting at the IP address and port we saved before
        Serial.println("connected");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Connected");

        String query = "GET /fingerprint-database/data.php?";
        query += "id=";
        query += finger_id;
        query += "&in_out=";
        query += 0; 
        Serial.println(query);
        cliente.println(query); //Connecting and Sending values to database


        
        cliente.stop(); //Closing the connection
        Serial.print("Closed");
        delay(5000);
      }
      else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }

    }
    delay(5000);
  }
  
}


uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }


  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  int flag = 0;

  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return 254;

    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);

  return finger.fingerID;
}

int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}
