#define LEDPIN 13
#define SENSE 4

int triggerLevel = 450;
void setup()
{
  pinMode( LEDPIN, OUTPUT );
  digitalWrite( LEDPIN, LOW );
  pinMode( SENSE, INPUT );
  digitalWrite( SENSE, HIGH );
  Serial.begin( 9600 );
  Serial.println( "started latency tester" );
}

void loop()
{
  //Serial.println( analogRead( 0 ) );
  //delay( 1000 );  
  
  if( Serial.available() )
  {
  while( Serial.available() )
  {
    Serial.read();
   
 
  }
 
   startTimer();
  }
}

void startTimer()
{
  Serial.println( "started" );
  double time = millis();
  digitalWrite( LEDPIN, HIGH );
  while(  analogRead( 0 ) < triggerLevel )
  {
    delay( 1 );
}
  Serial.print( "took " );
  Serial.println( millis() - time );
  digitalWrite( LEDPIN, LOW );
}
  
