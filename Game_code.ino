#define red_led 8
#define green_led 7
#define button_pin 6
bool Running=false;
void setup() {
  // put your setup code here, to run once:
pinMode(red_led, OUTPUT);
pinMode(green_led, OUTPUT);
pinMode(button_pin, INPUT);
Serial.begin(9600);
}
void play() {
  int start_time=millis();
  while((millis()-start_time)<3000){
    Serial.println("Playing");
    if(digitalRead(button_pin)==HIGH){
      Stop();
      //TO DO:Count the number of connected instances
    }
  }
}
void Start() {
  delay(100);
  Running=true;
  digitalWrite(green_led, HIGH);
  digitalWrite(red_led, LOW);
  play();
}
void Stop() {
  delay(100);
  Running=false;
  digitalWrite(red_led, HIGH);
  digitalWrite(green_led, LOW);
}
void state() {
  while (Running==false){
  Serial.println("Connect To Begin");
  if(digitalRead(button_pin)==HIGH){
  Start();
  }
}
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(button_pin));
  state();
}
