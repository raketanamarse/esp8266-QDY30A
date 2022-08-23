#include <SoftwareSerial.h>
#define RXD2 D1
#define TXD2 D2
#define DE_RE D7

SoftwareSerial S(RXD2, TXD2); //   (RX , TX)

byte ByteArray[250];
int ByteData[20];

void setup() {
  Serial.begin(74880);
  while (!Serial) { }// ожидаем подключения к последовательному порту.
  pinMode(DE_RE, OUTPUT);
  S.begin(9600, SWSERIAL_8N1);

}

void loop() {
  delay(1000);
  // выбери что нужн делать:
  
  //           |address |function code |data start (H) |data start (L) |nuber of data (H) |nuber of data (L) |CRC16(L) |CRC16(H)
  //byte msg[] = {0x01,   0x03,          0x00,           0x01,           0x00,              0x01,               0xD5,     0xCA}; //скорость порта 01
  //byte msg[] = {0x02,   0x03,          0x00,           0x01,           0x00,              0x01,               0xD5,     0xF9}; //скорость порта 02
   
  //byte msg[] = {0x01,   0x03,          0x00,           0x00,           0x00,              0x01,               0x84,     0x0A}; //узнать адрес устройства 01
  //byte msg[] = {0x02,   0x03,          0x00,           0x00,           0x00,              0x01,               0x84,     0x39}; //узнать адрес устройства 02
  
  //byte msg[] = {0x01,   0x03,          0x00,           0x02,           0x00,              0x01,               0x25,     0xCA}; //ед, измерения 01 
  //byte msg[] = {0x02,   0x03,          0x00,           0x02,           0x00,              0x01,               0x25,     0xF9}; //ед, измерения 02
  
  //byte msg[] = {0x01,   0x03,          0x00,           0x04,           0x00,              0x01,               0xC5,     0xCB}; //померять давление 01
  byte msg[] = {0x02,   0x03,          0x00,           0x04,           0x00,              0x01,               0xC5,     0xF8}; //померять давление 02
  
  //byte msg[] = {0x01,   0x06,          0x00,           0x00,           0x00,              0x02,               0x08,     0x0B}; // изменить адрес на 02
  //byte msg[] = {0x02,   0x06,          0x00,           0x00,           0x00,              0x01,               0x48,     0x39}; // изменить адрес на 01
  
  
  int len = 8;


  digitalWrite(DE_RE, 1); 
  
  Serial.println("SEND DATA:");
  for (int i = 0 ; i < len ; i++) {
    S.write(msg[i]);
    Serial.print("[");
    Serial.print(i);
    Serial.print("]");
    Serial.print("=");
    Serial.print(String(msg[i], HEX));
    Serial.print(" ");
  }
  Serial.println();
  Serial.println();


  digitalWrite(DE_RE, 0); 

  int a = 0;
  while (S.available())
  {
    ByteArray[a] = S.read();
    a++;
  }

  String registros;
  Serial.println("DATA RECEPTION:");
  for (int b = 0 ; b < a ; b++) {
    Serial.print("[");
    Serial.print(b);
    Serial.print("]");
    Serial.print("=");

    registros = String(ByteArray[b], HEX);
    Serial.print(registros);
    Serial.print(" ");
  }
  Serial.println();
  Serial.println(); 
  
  long davlenie = 0;
  davlenie = long(ByteArray[3]) * 256;
  davlenie += long(ByteArray[4]);
  Serial.println(davlenie);
                     
}
