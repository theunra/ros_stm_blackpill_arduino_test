#include <Arduino.h>
#include <ros.h>
#include <fukuro_common/STMData.h>
#include <fukuro_common/SerialData.h>

ros::NodeHandle nh;

fukuro_common::STMData stm_data;

ros::Publisher stm_pub("/stm_out", &stm_data);

void updateSerialData(const fukuro_common::SerialData &serial_data);
void processSerialData();
ros::Subscriber<fukuro_common::SerialData> serial_data_sub("/stm_in", &updateSerialData);
bool led_status = false;

void initHardware();
void blink(int ms);
void handleSpinResult(int result);

void getSensor();

void setup() {
  initHardware();
  nh.setSpinTimeout(1000);
  nh.initNode();
  nh.subscribe(serial_data_sub);
  nh.advertise(stm_pub);
}

void loop() {
  processSerialData();
  getSensor();
  
  if(!stm_pub.publish(&stm_data)){
    blink(100);
  }

  handleSpinResult(nh.spinOnce());
  delay(50);
}

void initHardware()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void blink(int ms)
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(ms);
  digitalWrite(LED_BUILTIN, LOW);
  delay(ms);
}

void getSensor()
{
  stm_data.distance = 100.0;
  stm_data.ready_kick = 0;
}

void handleSpinResult(int result)
{
  if(result == ros::SPIN_TIMEOUT) blink(50);
}

void updateSerialData(const fukuro_common::SerialData &serial_data)
{
  led_status = serial_data.kick;
}

void processSerialData()
{
  if(led_status) digitalWrite(LED_BUILTIN, HIGH);
  else digitalWrite(LED_BUILTIN, LOW);
}