#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  pinMode(19, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP32-BT"); // Bluetooth device name
}

void loop() {
  if (SerialBT.available()) {
    //
    digitalRead(19);
    
    String receivedString = SerialBT.readStringUntil(','); // Read the string until newline character
    //
    int receivedInt = receivedString.toInt(); // Convert the string to an integer
    digitalWrite(receivedInt, HIGH);
    Serial.println("Received integer: " + String(receivedInt));

    if(receivedInt == 0){
      //
      //SerialBt.println(" not valide ")
      SerialBT.println("work not done with esp32 ");

    }
    else{

       while (digitalRead(19) == HIGH){
      //      
      //digitalWrite(receivedInt, HIGH);
        delay(20);
        digitalRead(19);

      } 

      digitalWrite(receivedInt, LOW);
      SerialBT.println("work done with" + String(receivedInt));

    }

   // while (digitalRead(19) == HIGH){
      //      
      //digitalWrite(receivedInt, HIGH);
    //  delay(20);
    //  digitalRead(19);

   // }    
    //
    //delay(1000);

    //digitalWrite(receivedInt, LOW);
    //SerialBT.print("")

   // SerialBT.println("work done with -  " + String(receivedInt));

    
    
   // if(digitalRead(19)== LOW){
      //
    //}
    //
    delay(1000);
    //digitalWrite(receivedInt, LOW);
  }
}
