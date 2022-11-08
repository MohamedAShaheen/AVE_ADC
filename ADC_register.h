/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer :  MCAL                  *****************/
/**************       SWC:     ADC_REGISTER_H_        *****************/
/**************       Version : 1.0                 *****************/
/**************       Date :    7/11/2022              *****************/


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_


#define ADMUX           *((volatile u8*)0x27)         //ADC multiplexer selection register 
#define ADMUX_REFS1     7                             //Refrence selection bit 1
#define ADMUX_REFS0     6                             //Refrence selection bit 0
#define ADMUX_ADLAR     5                             //ADC left adjust result
												      
#define ADCSRA           *((volatile u8*)0x26)        //ADC control and status register A
#define ADCSRA_ADEN       7                           //ADC Enable
#define ADCSRA_ADSC       6                           //start conversion 
#define ADCSRA_ADATE      5                           //Auto trigger enable
#define ADCSRA_ADIF       4                           //Interrupt flag
#define ADCSRA_ADIE       3                           //Interrupt Enable
#define ADCSRA_ADPS2      2                           //Prescaler bit2
#define ADCSRA_ADPS1      1                           //Prescaler bit1
#define ADCSRA_ADPS0      0                           //Prescaler bit0
												      
#define ADC               *((volatile u16*)0x24)      //TO read form ADCH AND ADCL togither
												      
#define ADCH              *((volatile u8*)0x25)       //ADC high register
#define ADCL              *((volatile u8*)0x24)       //ADC Low  register
				           						  	    
#define SFIOR             *((volatile u8*)0x23)       //Special function register
#define SFIOR_ADTS2       7                           //ADC Auto Trigger Source Selections 2
#define SFIOR_ADTS1       6                           //ADC Auto Trigger Source Selections 1
#define SFIOR_ADTS0       5                           //ADC Auto Trigger Source Selections 0

#endif /* ADC_PRIVATE_H_ */
