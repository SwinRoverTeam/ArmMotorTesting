// send a frame from can bus

#include <SPI.h>
#include "mcp_can.h"

#include <mcp_can.h>
#include <SPI.h>

const int SPI_CS_PIN = 17;              // CANBed V1
// const int SPI_CS_PIN = 3;            // CANBed M0
// const int SPI_CS g_PIN = 9;            // CAN Bus Shield

MCP_CAN CAN(SPI_CS_PIN);                             // Set CS pin


unsigned int motorId = 0x302;
unsigned int speed = 0x30;
unsigned int acc = 0x5;
unsigned int code = 0xF6; 
unsigned int crc = 0;
unsigned int dir = 0x80;

unsigned char stmp[5] = {0, 0, 0, 0, 0};
void setup()
{
    Serial.begin(115200);
    while(!Serial);
    while (CAN_OK != CAN.begin(CAN_1000KBPS))    // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS FAIL!");
        delay(100);
    }
    Serial.println("CAN BUS OK!");

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
    for (int i = 0; i < 5; i++) {
      Serial.print(stmp[i], HEX);
      Serial.println("");
    }
    CAN.sendMsgBuf(motorId, 0, 5, stmp);
    delay(15000);                       // send data per 100ms
    stmp[0] = code;
    stmp[1] = dir;
    stmp[2] = 0;
    stmp[3] = acc;
    crc = 0;
    crc += motorId;
    crc += code;
    crc += dir;
    crc += acc;
    crc &= 0xFF;
    stmp[4] = crc;
    for (int i = 0; i < 5; i++) {
      Serial.print(stmp[i], HEX);
      Serial.println("");
    }
    CAN.sendMsgBuf(motorId, 0, 5, stmp);
    delay(1000);           

    // if (Serial.available() > 0) {
    //   AddressByte = Serial.read(0);
    //   DirByte = Serial.read(1);
    //   stmp[]
    // }

}

void loop()
{
  CAN.sendMsgBuf(motorId, 0, 5, stmp);
  delay(1000);
}

// END FILE
