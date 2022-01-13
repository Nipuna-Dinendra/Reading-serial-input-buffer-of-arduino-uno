/*This program was written to respond to serial input integer 0 and 1
  If you send 1, pin 13 will be HIGH (LED is on)
  If you send 0, pin 13 will be LOW (LED is off)*/

int store[10];                                    //to store the serial buffer input data
int i=0;                                          //to count the number of serial buffer input data elements
int incoming_byte=0;                              //Defines a variable to save incoming byte from serial port to arduino

void setup() {
 Serial.begin(9600);                             //Starting serial communication
 pinMode(13,OUTPUT);                             //defines pin 13 as an output
}

void loop() {
   
   
   while (Serial.available()>0){                 //check for the serial port incoming data
   //Serial.println(Serial.available());         // for debugging purposes
   incoming_byte=Serial.read();                  //read incoming byte to arduino 
   store[i]=incoming_byte;                       //store serial buffer i-th input element to the store array
   delay(5);
   i=i+1;
   }

  if (i>1){
    Serial.print("enter 0 or 1 ! \n");          //if the input is longer than one byte print this message
  }
  else if(i==1){
     if (store[0]==49)                          //reads the ASCII value and compare it with the ASCII value of int 1
   { 
    digitalWrite(13,HIGH);                      //turn on the built-in led of arduino pin 13
   }
   else if(store[0]==48)                        //reads the ASCII value and compare it with the ASCII value of int 0
   {
    digitalWrite(13,LOW);                       //turn off the built-in led of arduino pin 13
   }
   else{
    Serial.print("enter 0 or 1 ! \n");
   }
  }
  i=0;
}
