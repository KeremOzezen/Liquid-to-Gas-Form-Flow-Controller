int RelayControl1 = 5; 
int RelayControl2 = 3;  
int RelayOfPump = 6; 

int Sensor = 0;
uint32_t period = 5 * 60000L;
uint32_t period2 = 5 * 60000L;

void setup() {
  Serial.begin(9600);
  pinMode(RelayControl1, OUTPUT);
  pinMode(RelayControl2, OUTPUT);
  pinMode(RelayOfPump, OUTPUT);
  pinMode(10,INPUT);

}

void Liquid_Level(){

  for(uint32_t tStart = millis(); (millis()-tStart)<period;){
    Sensor = digitalRead(10);
    Serial.println(Sensor, DEC);
    digitalWrite(RelayControl1,HIGH);
    digitalWrite(RelayControl2,LOW);
     
    if(Sensor==1){
       digitalWrite(RelayOfPump,HIGH);
               }
    if(Sensor==0){
       digitalWrite(RelayOfPump,LOW);
    }
     }
   
       
}

void loop() {
  Liquid_Level();
  delay(10);
  for(uint32_t tStart2 = millis(); (millis()-tStart2)<period2;){
     digitalWrite(RelayOfPump,HIGH);
     delay(1);
     digitalWrite(RelayOfPump,LOW);
     digitalWrite(RelayControl1,LOW);
     digitalWrite(RelayControl2,HIGH);     
    }
  delay(10);
 
  
}
