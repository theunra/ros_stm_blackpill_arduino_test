/* 
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote prducts derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ROS_ARDUINO_HARDWARE_H_
#define ROS_ARDUINO_HARDWARE_H_

#if ARDUINO>=100
  #include <Arduino.h>  // Arduino 1.0
#else
  #include <WProgram.h>  // Arduino 0022
#endif

/**
 * Change this serial class depend on what type of serial used for communicating with ROS
 * ex : using onboard uart Serial1 , use HardwareSerial
 *      using software serial, use SoftwareSerial , kayaknya, blm pernah coba
*/ 

// Use usb type-c serial cdc on board
#define SERIAL_CLASS USBSerial

class ArduinoHardware {
  public:
    ArduinoHardware(SERIAL_CLASS* io , long baud= 57600){
      iostream = io;
      baud_ = baud;
    }
    ArduinoHardware()
    {
      //Use serialUSB
      iostream = &Serial;
      //whoosh baudrate
      baud_ = 500000;
    }
    ArduinoHardware(ArduinoHardware& h){
      this->iostream = h.iostream;
      this->baud_ = h.baud_;
    }

    void setPort(SERIAL_CLASS* io){
      this->iostream = io;
    }
  
    void setBaud(long baud){
      this->baud_= baud;
    }
  
    int getBaud(){return baud_;}

    void init(){
      // Startup delay as a fail-safe to upload a new sketch
      // This will delay the whole program, called in nodehandle initNode()
      delay(5000); 
      iostream->begin(baud_);
    }

    int read(){return iostream->read();};
    void write(uint8_t* data, int length){
      iostream->write(data, length);
    }

    unsigned long time(){return millis();}

  protected:
    SERIAL_CLASS* iostream;
    long baud_;
};

#endif
