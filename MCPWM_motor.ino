#include  "driver/mcpwm.h"
void setup() {
  // 用选定的MCPWM_UNIT_0来初始化gpio口
  mcpwm_gpio_init(MCPWM_UNIT_0,MCPWM0A,26);
  mcpwm_gpio_init(MCPWM_UNIT_0,MCPWM0A,27);
  
  //通过mcpwm_config_t结构体为定时器设置频率和初始值
  mcpwm_config_t motor_pwm_config={
    .frequency=1000,
    .cmpr_a=0,
    .cmpr_b=0,
    .duty_mode=MCPWM_DUTY_MODE_0,
    .counter_mode=MCPWM_UP_COUNTER,
  };
  //使用以上设置配置PWMOA和PWMOB
  mcpwm_init(MCPWM_UNIT_0,MCPWM_TIMER_0,&motor_pwm_config);
}

void loop() {
  // pwm
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_A,0);
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_B,100);
  mcpwm_start(MCPWM_UNIT_0,MCPWM_TIMER_0);
  delay(5000);
  mcpwm_stop(MCPWM_UNIT_0,MCPWM_TIMER_0);
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_A,100);
  mcpwm_set_duty(MCPWM_UNIT_0,MCPWM_TIMER_0,MCPWM_OPR_B,0);
  mcpwm_start(MCPWM_UNIT_0,MCPWM_TIMER_0);
  delay(5000);
  mcpwm_stop(MCPWM_UNIT_0,MCPWM_TIMER_0);
}
