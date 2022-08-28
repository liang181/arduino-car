const int servo=15;//13 15--舵机
const int motorA=26;//电机A
const int motorB=27;//电机B
//pwm
const int freq=50;//频率
const int resolution=8;//分辨率
//通道
const int servo_channel=0;//舵机
const int motorA_channel=1;//电机A
const int motorB_channel=2;//电机B

void setup() {
  // 舵机
  ledcSetup(servo_channel,freq,resolution);
  ledcAttachPin(servo,servo_channel);
  //电机A
  ledcSetup(motorA_channel,freq,resolution);
  ledcAttachPin(motorA,motorA_channel);
  //电机
  ledcSetup(motorB_channel,freq,resolution);
  ledcAttachPin(motorB,motorB_channel);

  /*初始化*/
  ledcWrite(servo_channel,20);//舵机初始化-->90度-->20,取值范围7--32
  ledcWrite(motorA_channel,0);//A前进
  ledcWrite(motorB_channel,0);//B后退
  
}

void loop() {
  while (1){
    ledcWrite(motorA_channel,128);//0--255,速度从小到大
    delay(3000);
    ledcWrite(servo_channel,7);
    delay(1000);
    ledcWrite(motorA_channel,128);
    delay(3000);
    ledcWrite(servo_channel,20);
    delay(1000);
    ledcWrite(motorA_channel,128);
    delay(3000);
    ledcWrite(servo_channel,32);
    delay(1000);
    ledcWrite(motorA_channel,128);
    delay(3000);
    ledcWrite(servo_channel,20);
    delay(1000);
  }

}
