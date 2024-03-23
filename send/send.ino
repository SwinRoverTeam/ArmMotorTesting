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
  Serial.begin(115200); //baud rate
}

void loop() {
  //Serial.println("1");
  // put your main code here, to run repeatedly:
    //Serial.println("2");
    // Read the incoming byte
    String incomingByte = Serial.readStringUntil('\n');
    Serial.println(incomingByte);

    if (incomingByte == "1"){
      Serial.println("Base motor rotating CCW");//looking top-down
      code = 0xF6;
      motorId = 0x301;
      dir = 0x80;
      speed = 0x30;
      acc = 0x5;
      crc = 0;
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
      CAN.sendMsgBuf(motorId, 0, 5, stmp); //0 corresp to the type of CAN we use
    }
    if (incomingByte == "q"){
      Serial.println("Base motor rotating CW"); //looking top-down
      code = 0xF6;
      motorId = 0x301;
      dir = 0x00;
      speed = 0x30;
      acc = 0x5;
      crc = 0;
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
    //==========================================================================================================
    if (incomingByte == "2"){
      Serial.println("1st Swing Arm motor rotating CCW"); //looking from the left of the rover/at motor 2 drivers screen
      code = 0xF6;
      motorId = 0x302;
      dir = 0x80;
      speed = 0xf;
      acc = 0x5;
      crc = 0;
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
      CAN.sendMsgBuf(motorId, 0, 5, stmp); //0 corresp to the type of can used
    }
    if (incomingByte == "w"){
      Serial.println("1st Swing Arm motor rotating CW"); //looking from the left of the rover/at motor 2 drivers screen
      code = 0xF6;
      motorId = 0x302;
      dir = 0x00;
      speed = 0xf;
      acc = 0x5;
      crc = 0;
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
    //==========================================================================================================
    if (incomingByte == "3"){
      Serial.println("2nd Swing Arm motor rotating CCW"); //looking from the right of the rover/at motor 3 drivers screen
      code = 0xF6;
      motorId = 0x303;
      dir = 0x80;
      speed = 0xf;
      acc = 0x5;
      crc = 0;
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
      CAN.sendMsgBuf(motorId, 0, 5, stmp); //0 corresp to the type of can used
    }
    if (incomingByte == "e"){
      Serial.println("2nd Swing Arm motor rotating CW"); //looking from the left of the rover/at motor 3 drivers screen
      code = 0xF6;
      motorId = 0x303;
      dir = 0x00;
      speed = 0xf;
      acc = 0x5;
      crc = 0;
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
    //==========================================================================================================
    if (incomingByte == "4"){
      Serial.println("Wrist motor rotating up"); //looking from the side
      code = 0xF6;
      motorId = 0x304;
      dir = 0x80;
      speed = 0x3C;
      acc = 0x5;
      crc = 0;
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
      CAN.sendMsgBuf(motorId, 0, 5, stmp); //0 corresp to the type of can used
    }
    if (incomingByte == "r"){
      Serial.println("Wrist motor rotating down"); //looking from the side
      code = 0xF6;
      motorId = 0x304;
      dir = 0x00;
      speed = 0x3C;
      acc = 0x5;
      crc = 0;
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
    //==========================================================================================================
    if (incomingByte == "5"){
      Serial.println("Gripper rotating CCW"); //looking from the back of the rover
      code = 0xF6;
      motorId = 0x305;
      dir = 0x00;
      speed = 0x3C;
      acc = 0x5;
      crc = 0;
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
      CAN.sendMsgBuf(motorId, 0, 5, stmp); //0 corresp to the type of can used
    }
    if (incomingByte == "t"){
      Serial.println("Gripper rotating CW"); //looking from the back of the rover
      code = 0xF6;
      motorId = 0x305;
      dir = 0x80;
      speed = 0x3C;
      acc = 0x5;
      crc = 0;
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
    //==========================================================================================================
    if (incomingByte == "6"){
      Serial.println("Gripper closing");
      code = 0xF6;
      motorId = 0x306;
      dir = 0x80;
      speed = 0x1E;
      acc = 0x5;
      crc = 0;
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
      CAN.sendMsgBuf(motorId, 0, 5, stmp); //0 corresp to the type of can used
    }
    if (incomingByte == "y"){
      Serial.println("Gripper opening")
      code = 0xF6;
      motorId = 0x306;
      dir = 0x00;
      speed = 0x1E;
      acc = 0x5;
      crc = 0;
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
    //==========================================================================================================

    if (incomingByte == "h"){ //h - 'halt'.
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
