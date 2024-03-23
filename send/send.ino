// send a frame from can bus

#include <SPI.h>
#include "mcp_can.h"

#include <mcp_can.h>
#include <SPI.h>


const int SPI_CS_PIN = 17;              // CANBed V1
// const int SPI_CS_PIN = 3;            // CANBed M0
// const int SPI_CS g_PIN = 9;            // CAN Bus Shield
MCP_CAN CAN(SPI_CS_PIN);     


unsigned int motorId;
unsigned int speed;
unsigned int acc;
unsigned int code; 
unsigned int crc;
unsigned int dir;
unsigned char stmp[5] = {0, 0, 0, 0, 0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  //Serial.println("1");
  // put your main code here, to run repeatedly:
    //Serial.println("2");
    // Read the incoming byte
    String incomingByte = Serial.readStringUntil('\n');
    Serial.println(incomingByte);
    if (incomingByte == "1"){
      Serial.println("how to get 1 ");
      motorId = 0x306;
      speed = 0x1E;
      acc = 0x5;
      code = 0xF6; 
      crc = 0;
      dir = 0x0;
      stmp[0] = code;
      stmp[1] = (dir + (speed >> 8));
      stmp[2] = (speed & 0xFF);
      stmp[3] = acc;
      crc = 0;
      crc += motorId;
      crc += code;
      crc += (dir + (speed >> 8));
      crc += (speed & 0xFF);
      crc += acc;
      crc &= 0xFF;
      stmp[4] = crc;
      CAN.sendMsgBuf(motorId, 0, 5, stmp);
    }
    if (incomingByte == "m"){
      
      stmp[0] = code;
      stmp[1] = (dir + (speed >> 8));
      stmp[2] = (speed & 0xFF);
      stmp[3] = acc;
    for (int i = 0; i < 6; i++) {
      crc = 0;
      crc += 0x301+ i;
      crc += code;
      crc += (dir + (speed >> 8));
      crc += (speed & 0xFF);
      crc += acc;
      crc &= 0xFF;
      stmp[4] = crc;

        CAN.sendMsgBuf(0x301+ i, 0, 5, stmp);
      }

    }
  
}
