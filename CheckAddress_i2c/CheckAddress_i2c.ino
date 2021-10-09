#include <Wire.h>


void Logic_Check_AddressI2C() {
  Serial.println("******************** Check_AddressI2C ****************");
  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  String address = "";
  byte count = 0;


  Wire.begin();
  for (int i = 8; i < 120; i++)
  { Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
    {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);

      address = String(i, DEC);
      //     Serial.print(String(i));
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);
    } // end of good response

    address = "";

  } // end of for loop
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");

}




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Nursery Arduino");

  Logic_Check_AddressI2C();
}

void loop() {
  // put your main code here, to run repeatedly:

}
