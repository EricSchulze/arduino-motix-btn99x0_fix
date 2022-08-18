#include "BTN99x0_motorcontrol.hpp"

using namespace btn99x0_motorcontrol;

BTN99x0_motorcontrol::BTN99x0_motorcontrol(btn99xx_novalith_shield & shield)
:
   sw1(shield.get_switch(BTN99x0_SWITCH_1)),
    sw2(shield.get_switch(BTN99x0_SWITCH_2))
{
 
}

BTN99x0_motorcontrol::~BTN99x0_motorcontrol()
{

}
void BTN99x0_motorcontrol::begin()
{
    sw1.begin();
    sw2.begin();
}
void BTN99x0_motorcontrol::set_speed(int16_t duty)
{ 
    
     sw1.enable();
     sw2.enable();
     if(duty>=0)
     {
     /*
     switch 1 with duty cycle 
     switch 2 is off
     */
     sw1.pwm(duty);                                
     sw2.pwm(0);                                   
     }else
     {
     duty=-duty;
     /*
     switch 1 is off 
     switch 2 with duty cycle
     */    
     sw1.pwm(0);                                   
     sw2.pwm(duty);

    }
 };

 void BTN99x0_motorcontrol::freewheel()
{
     /*
     disabled both chips, that freewheel is possible
     */

     sw1.disable();                                  
     sw2.disable();
 };

 void BTN99x0_motorcontrol::brake()
 {
     /*
     set both input chips to low
     */
     sw1.pwm(0);                                  
     sw2.pwm(0);
 };

 void BTN99x0_motorcontrol::slew_rate_motor(uint8_t selected)
 {
     sw1.set_slew_rate(selected);
     sw2.set_slew_rate(selected);
 }


