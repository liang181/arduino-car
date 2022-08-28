//舵机初始化
const int a=15;

//pwm
const int f=50;
const int r=8;
const int c=0;
const int d=20;//77-32

void setup() {
  ledcSetup(c,f,r);
  ledcAttachPin(a,c);

}

void loop() {
  ledcWrite(c,d);
  

}
