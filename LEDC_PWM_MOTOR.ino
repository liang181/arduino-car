const int a=26;
const int b=27;
//pwm
const int freq=2000;
const int resolution=8;
const int channel=0;
const int duty_cycle=255;

void setup() {
  ledcSetup(channel,freq,resolution);
  ledcAttachPin(b,channel);
  pinMode(a,OUTPUT);
  digitalWrite(a,LOW);
  
}

void loop() {
  ledcWrite(channel,duty_cycle);

}
