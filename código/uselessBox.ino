#include <Servo.h>
Servo puertaServo;
Servo brazoServo;

int switch_pin = 2;
int pos =0;
void setup()
{
  Serial.begin(9600);
  pinMode(switch_pin, INPUT);
  puertaServo.attach(9);           //set del servo de la puerta en 9
  brazoServo.attach(10);          //set de la mano en el pin 10
  puertaServo.write(80);           //set de la puerta en la pos 80
  brazoServo.write(0);            //set de la mano en la pos 0
 
}


void loop(){

  int numMovimiento = random(0,13);
  if(digitalRead(switch_pin) == HIGH){
   
      if (numMovimiento == 1) {
        movBasico();
      }
      else if (numMovimiento == 2) {
        movEngano();
      }
      else if (numMovimiento == 3) {
        movTroll();
      }
      else if (numMovimiento == 4) {
        movLento();
      }
      else if (numMovimiento == 5) {
        movTapa();
      }
      else if (numMovimiento == 6) {
        movSuspenso();
      }
      else if (numMovimiento == 7) {
        movPuertaAbierta();
      }
      else if (numMovimiento == 8) {
        movPuertaLoca();
      }
      else if (numMovimiento == 9) {
        movAbrePoco();
      }
      else if (numMovimiento == 10) {
        movNoJoda();
      }
      else if (numMovimiento == 11) {
        movBrazoLoco();
      }
      else if (numMovimiento == 12) {
        movPuertaConBasico();
      }
    
  }
}

// metodos de los movimientos

void movBasico(){
 
   //mover la tapa
   for(pos = 80; pos >= 40 ; pos -=5){                                  
    puertaServo.write(pos);             
    delay(15);                      
   }
   //Mover el brazo
    for(pos = 0; pos <= 150 && (digitalRead(switch_pin) == HIGH) ; pos=150){                                  
      brazoServo.write(pos);              
      delay(15);   
    }
    
    //bajar el brazo
    for(pos = 150; pos>=0; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    //cerrar tapa
    for(pos = 40; pos<=80; pos+=3){                               
      puertaServo.write(pos);             
      delay(15);                     
    }
}

void movEngano(){
  
   //mover la tapa
   for(pos = 80; pos >=40; pos -=5){     
    puertaServo.write(pos);             
    delay(15);                      
   }
   
   //Mover el brazo
   for(pos= 0; pos<=143; pos+=3){
     brazoServo.write(pos); 
     
   }
   delay(1000);
   for(pos= 143; pos<=170; pos+=5){
     Serial.print(pos);
     brazoServo.write(pos);              
     delay(15);
   }
    
    //bajar el brazo
    for(pos = 150; pos>=0; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    
    for(pos = 40; pos<=80; pos+=3){                               
      puertaServo.write(pos);             
      delay(15);                     
    }
}

//se asoma y luego lo baja
void movTroll(){
  
  //mover la tapa
   for(pos = 80; pos >=40; pos -=5){     
    puertaServo.write(pos);             
    delay(15);                      
   }
   //sube el brazo
    for(pos= 0; pos<=90; pos+=10){
     brazoServo.write(pos);
     }
   
   delay(1000);
   
    //bajar el brazo
    for(pos = 90; pos>=0; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    
    //Mover el brazo
    for(pos = 0; pos <= 150 && (digitalRead(switch_pin) == HIGH) ; pos=150){                                  
      brazoServo.write(pos);              
      delay(15);   
    }
    //bajar el brazo
    for(pos = 150; pos>=0; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    //bajar la puerta
    for(pos = 40; pos<=80; pos+=3){                               
      puertaServo.write(pos);             
      delay(15);                     
    }
    
}

void movLento(){
  
  //mover la tapa
   for(pos = 80; pos >=40; pos-=3){     
    puertaServo.write(pos);             
    delay(15);                      
   }
   
    //Mover el brazo
    for(pos = 0; pos <= 150 && (digitalRead(switch_pin) == HIGH) ; pos++){    
      delay(40);       
      brazoServo.write(pos);                
    }
    
    //bajar el brazo
    for(pos = 150; pos>=0; pos--){                               
      brazoServo.write(pos);              
      delay(40);                       
    }
    
    for(pos = 40; pos<=80; pos++){                               
      puertaServo.write(pos);             
      delay(40);                     
    }
   
}

void movTapa(){
  //mover la tapa
   for(pos = 80; pos >=40; pos-=3){     
    puertaServo.write(pos);             
    delay(15);                      
   }
   //mover la tapa
   for(pos = 80; pos >=40; pos-=3){     
    puertaServo.write(pos);             
    delay(15);                      
   }
   //mover la tapa
   for(pos = 80; pos >=40; pos-=3){     
    puertaServo.write(pos);             
    delay(15);                      
   }
   //mover la tapa
   for(pos = 80; pos >=40; pos-=3){     
    puertaServo.write(pos);             
    delay(15);                      
   }
   //......................
   //mover la tapa
   for(pos = 80; pos >= 40 ; pos -=5){                                  
    puertaServo.write(pos);             
    delay(15);                      
   }
   
   //Mover el brazo
    for(pos = 0; pos <= 150 && (digitalRead(switch_pin) == HIGH) ; pos=150){                                  
      brazoServo.write(pos);              
      delay(15);   
    }
    
    //bajar el brazo
    for(pos = 150; pos>=0; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    
    for(pos = 40; pos<=80; pos+=3){                               
      puertaServo.write(pos);             
      delay(15);                     
    }
}

void movSuspenso(){
  delay(3000);
  movBasico();
}

void movPuertaAbierta(){
  //mover la tapa
   for(pos = 80; pos >= 40 ; pos -=5){                                  
    puertaServo.write(pos);             
    delay(15);                      
   }
   delay(3000);
   
     //Mover el brazo
    for(pos = 0; pos <= 150 && (digitalRead(switch_pin) == HIGH) ; pos=150){                                  
      brazoServo.write(pos);              
      delay(15);   
    }
    
    //bajar el brazo
    for(pos = 150; pos>=0; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    //bajar la puerta
    for(pos = 40; pos<=80; pos+=3){                               
      puertaServo.write(pos);             
      delay(15);                     
    }
}

void movPuertaLoca(){
    //mover la tapa
   for(pos = 80; pos >= 40 ; pos -=5){                                  
    puertaServo.write(pos);             
    delay(15);                      
   }
   delay(1000);
     //cerrar tapa
    for(pos = 40; pos<=80; pos+=3){                               
      puertaServo.write(pos);             
      delay(15);                     
    }
    delay(3000);
    movTroll();
}

void movAbrePoco(){
  //mover la tapa
   for(pos = 80; pos >= 45 ; pos -=5){                                  
    puertaServo.write(pos);             
    delay(15);                      
   }
   //sube el brazo
   for(pos= 0; pos<=90; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   delay(3000);
   //avanza el brazo
   for(pos= 90; pos<=170; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   //bajar el brazo
    for(pos = 170; pos>=0; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    //cerrar tapa
    for(pos = 45; pos<=80; pos+=3){                               
      puertaServo.write(pos);             
      delay(15);                     
    }
}

void movNoJoda(){
  //mover la tapa
   for(pos = 80; pos >= 40 ; pos -=5){                                  
    puertaServo.write(pos);             
    delay(15);                      
   }
    //sube el brazo
   for(pos= 0; pos<=90; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   delay(1000);
   //avanza el brazo
   for(pos= 90; pos<=120; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   //bajar el brazo
    for(pos = 190; pos>=90; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
       //avanza el brazo
   for(pos= 90; pos<=120; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   //bajar el brazo
    for(pos = 190; pos>=90; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
       //avanza el brazo
   for(pos= 90; pos<=120; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   //bajar el brazo
    for(pos = 190; pos>=90; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
       //avanza el brazo
   for(pos= 90; pos<=120; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   //bajar el brazo
    for(pos = 190; pos>=90; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    //....................
     //avanza el brazo
   for(pos= 90; pos<=170; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   //bajar el brazo
    for(pos = 170; pos>=0; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    //cerrar tapa
    for(pos = 45; pos<=80; pos+=3){                               
      puertaServo.write(pos);             
      delay(15);                     
    }
}

void movBrazoLoco(){
  //mover la tapa
   for(pos = 80; pos >= 40 ; pos -=5){                                  
    puertaServo.write(pos);             
    delay(15);                      
   }
   
    //sube el brazo
   for(pos= 0; pos<=90; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
    delay(1000);
    
   //avanza el brazo
   for(pos= 90; pos<=120; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   //bajar el brazo
    for(pos = 120; pos>=90; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    //avanza el brazo
   for(pos= 90; pos<=120; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   //bajar el brazo
    for(pos = 120; pos>=90; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    //avanza el brazo
   for(pos= 90; pos<=120; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   //bajar el brazo
    for(pos = 120; pos>=90; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
     //avanza el brazo
   for(pos= 90; pos<=120; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   //bajar el brazo
    for(pos = 120; pos>=90; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
     //avanza el brazo
   for(pos= 90; pos<=120; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   //bajar el brazo
    for(pos = 120; pos>=90; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    //....................
     //avanza el brazo
   for(pos= 90; pos<=170; pos+=10){
     brazoServo.write(pos);
     delay(15);
   }
   //bajar el brazo
    for(pos = 170; pos>=0; pos-=5){                               
      brazoServo.write(pos);              
      delay(15);                       
    }
    //cerrar tapa
    for(pos = 45; pos<=80; pos+=3){                               
      puertaServo.write(pos);             
      delay(15);
    }  
}

void movPuertaConBasico(){
  //mover la tapa
   for(pos = 80; pos >= 60 ; pos -=5){                                  
    puertaServo.write(pos);             
    delay(15);                      
   }
   delay(3000);
   //cerrar tapa
    for(pos = 65; pos<=80; pos+=3){                               
      puertaServo.write(pos);             
      delay(15);
    } 
    delay(1000);
    movBasico();
}


