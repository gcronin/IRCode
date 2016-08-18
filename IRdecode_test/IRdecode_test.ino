#include <IRLib.h>
 
//Create a receiver object to listen on pin 11
IRrecv My_Receiver(11);
 
//Create a decoder object
IRdecode My_Decoder;

//32 bit value of the button pressed on IR remote
unsigned long reading = 0;
 
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  My_Receiver.enableIRIn(); // Start the receiver
}
 
void loop() {
//Continuously look for results. When you have them pass them to the decoder
  if (My_Receiver.GetResults(&My_Decoder)) {
    My_Decoder.decode();    //Decode the data
    if(My_Decoder.value != 0xFFFFFFFF)
    {
      reading = My_Decoder.value;
    }
    Serial.println(reading, HEX);
    //My_Decoder.DumpResults(); //Show the results on serial monitor
    My_Receiver.resume();     //Restart the receiver
    
  }

  if(reading == 0xFD58A7)
    digitalWrite(13, HIGH);
    
  else
    digitalWrite(13, LOW);

}
