const int buzzer=25;

//pwm
const int f=2000;
const int c=0;
const int r=8;
const int d=128;

void setup() {
  ledcSetup(c,f,r);
  ledcAttachPin(buzzer,c);

}

void loop() {
  //固定频率（音调）--修改占空比（响度）
  ledcWriteTone(c,f);
  
  ledcWrite(c,d);
  delay(100);

}
