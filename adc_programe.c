/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer : MCAL                  *****************/
/**************       SWC:     ADC_Program_c                  *****************/
/**************       Version : 1.0                 *****************/
/**************       Date : 30/12/2021              *****************/


#include "bit_cal.h"
#include "std_types.h"
#include "adc_private.h"
#include "adc_interface.h"


void adc_init(void){
	set_bit(adcsra,0);      /* prescales = 128 */
	set_bit(adcsra,1);
	set_bit(adcsra,2);

    clear_bit(admux,7); /*  refrence voltages = 5v */
    set_bit(admux,6);


    set_bit(admux,5);   /* left adjustment*/


    set_bit(adcsra,7); /* adc enable */
}




u16 adc_read(u8 channel){

	admux &= 0b11100000;
	admux |= channel;
	set_bit(adcsra,6); /* start convresion */
	while((get_bit(adcsra,4))==0);
	set_bit(adcsra,4);
	u16 res = adcl >>6 ;
	res |= (adch<<2);

	return res ;

}









