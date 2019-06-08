#define S0 7
#define S1 8
#define S2 5
#define S3 4
#define motor 9
#define sensorOut 6

// Stores frequency read by the photodiodes
int redFrequency = 0;
int r;
int greenFrequency = 0;
int g;
int blueFrequency = 0;
int b;
int i;
int j;
int z;

void setup() 
{
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(motor, OUTPUT);
  
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
   // Begins serial communication 
  Serial.begin(9600);

  for(i=1;i>0;i++)
  {
    label:
    delay (1000);
   // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  
  r=redFrequency;
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  
  g=greenFrequency;
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  
 b=blueFrequency;
 Serial.print("r=");
 Serial.print(r);
 Serial.print("g=");
 Serial.print(g);
 Serial.print("b=");
 Serial.print(b);
 

 if(r<g && r<b)
 {
  Serial.println ("Red Detected ");
  z=1;
  break;
 }
  else if(g<r && g<b)
  {
   Serial.println ("Green Detected ");
   z=2;
   break;
  }
 
  else if(b<r && b<g)
  {
   Serial.println ("Blue Detected ");
   z=3;
   break;
  }
  }
  if (z==1)
  {
    for(j=0;j<2;j++)
    {
    digitalWrite(motor, HIGH);//red
    delay(500);
    digitalWrite(motor, LOW);
    delay(500);
    
  }
  goto label;
  }
  else if(z==2)
  {
     for(j=0;j<3;j++)
    {
     digitalWrite(motor, HIGH);//green
    delay(500);
    digitalWrite(motor, LOW);
    delay(500);
  }
  goto label;
  }

   else if(z==3)
  {
     for(j=0;j<4;j++)
    {
     digitalWrite(motor, HIGH);//blue
    delay(500);
    digitalWrite(motor, LOW);
    delay(500);
  }
  goto label;
  }
  
  
}//void setup
void loop() {
}
