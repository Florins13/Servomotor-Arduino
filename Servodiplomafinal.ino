#include <Servo.h>

Servo servosus;
Servo servojos;
Servo servovarf;
int angle = 35;
int angle1 = 50;
int angle2 = 10;


int senzor = 5;
int led = 4;
int ledverde = 2; // verde
int ledportocaliu = 11;

int areobstacol = HIGH;
int stareswitch = 0; // setare valoare intrerupator
int banda = 3; // rosu
const int butonswitch = 12;
int start = false; // starea de start intrerupator

void setup() {
  Serial.begin(9600);
  pinMode(senzor, INPUT);
  pinMode(ledportocaliu, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(banda, OUTPUT);
  pinMode(butonswitch, INPUT);
 

  
  servojos.attach(8);
  servojos.write(angle);
  servosus.attach(6);
  servosus.write(angle1);
  servovarf.attach(9);
  servovarf.write(angle2);
  delay(4000); // incepe sistemul dupa 4 secunde  !
}


void loop() {
if (stareswitch == HIGH){ // stare intrerupator
  start = true;
}
if(stareswitch == LOW){   // stare intrerupator
    start = false;
  }
if(start == false){      // executare conditie
  digitalWrite(banda, LOW); // opreste banda
  digitalWrite(led, LOW); // aprinde led
}

stareswitch = digitalRead(butonswitch);
Serial.println(stareswitch); // printeaza in serial monitor variabila, aici printam sa vedem starea butonului


if(start == true){  // executare conditie
digitalWrite(led, HIGH); //porneste led rosu la pornirea benzii
digitalWrite(ledverde, LOW);
digitalWrite(banda, HIGH); // porneste banda

areobstacol = digitalRead(senzor); //citeste valoare senzor si stocheaza in variabila areobstacol

Serial.println("Valoare este: "); // printeaza in serial monitor
Serial.println(areobstacol); // printeaza in serial monitor variabila 

if ( areobstacol == LOW){  // conditias daca detecteaza miscare
digitalWrite(banda, LOW); // opreste banda
digitalWrite(led, LOW); // aprinde led
digitalWrite(ledverde, HIGH);

delay(2000);
      
servojos1();
delay(1000);
servovarf1();
digitalWrite(ledportocaliu, HIGH); // aprinde led portocaliu
delay(500);
servosus2();
delay(1000);
servovarf2();
delay(500);

servosus1();
delay(1000);
servojos2();
delay(1000);
servosus2();
delay(500);

servovarf1();
delay(500);
digitalWrite(ledportocaliu, LOW); // stinge led portocaliu
servosus1();
delay(1000);

    }
}
}



void servojos1(){
  for(angle = 35; angle < 115; angle++)  
  {                                  
    servojos.write(angle);               
    delay(15);                   
  } 

}
void servojos2()
{
    //
  for(angle = 115; angle > 35; angle--)    
  {                                
    servojos.write(angle);           
    delay(15);       
  } 
  
}

void servosus1()
{
    for(angle1 = 13; angle1 < 55; angle1++)  
  {                                  
    servosus.write(angle1);               
    delay(15);                   
  } 
}

void servosus2()
{
      // 
  for(angle1 = 55; angle1 > 13; angle1--)    
  {                                
    servosus.write(angle1);           
    delay(15);       
  } 
}

void servovarf1()
{
    for(angle2 = 10; angle2 < 50; angle2++)  
  {                                  
    servovarf.write(angle2);               
    delay(15);                   
  } 
}

void servovarf2()
{
      // 
  for(angle2 = 50; angle2 > 10; angle2--)    
  {                                
    servovarf.write(angle2);           
    delay(15);       
  } 
}

