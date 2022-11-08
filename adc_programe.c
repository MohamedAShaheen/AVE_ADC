/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer : MCAL                  *****************/
/**************       SWC:     ADC_Program_c                  *****************/
/**************       Version : 1.0                 *****************/
/**************       Date : 30/12/2021              *****************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "adc_interface.h"


void ADC_voidInit(void){
	/* V Reference Selection Bits*/
	#if REFRENCE_SELECTION    AREF_OFF
	   CLR_BIT(ADMUX ,ADMUX_REFS0);
	   CLR_BIT(ADMUX ,ADMUX_REFS1);
	   
	#elif REFRENCE_SELECTION  AVCC
	   SET_BIT(ADMUX ,ADMUX_REFS0);
	   CLR_BIT(ADMUX ,ADMUX_REFS1);
	#elif REFRENCE_SELECTION  RESERVED
	   CLR_BIT(ADMUX ,ADMUX_REFS0);
	   SET_BIT(ADMUX ,ADMUX_REFS1);
	#elif REFRENCE_SELECTION  INTERNAL_2V56
	   SET_BIT(ADMUX ,ADMUX_REFS0);
	   SET_BIT(ADMUX ,ADMUX_REFS1);
	#endif
	
	/* ADC Adjust*/
	#if ADC_ADJUST      LEFT_ADJUST
	    SET_BIT(ADMUX, ADLAR);
	#elif ADC_ADJUST    RIGHT_ADJUST
	    CLR_BIT(ADMUX, ADLAR);
	#endif
	
	/* Select Prescaler */
	ADCSRA &=ADC_PRESCALER_MASK;
	ADCSRA |=ADC_PRESCALER_SELECTION;
	
	#if OP_MODE  INTERRUPT_ASYNCH
	   SET_BIT(ADCSRA,ADIE);
	#endif
	  
	 /* ADC Peripheral ENABLE */
	 SET_BIT(ADCSRA ,ADEN);
}




uint16 ADC_u16ReadChannelSync(uint8 Copy_u8Channel){
    
	/* SELECT CHANNEL */
	ADMUX &= ADC_CHANNEL_MASK;
	ADMUX |= Copy_u8Channel;
	
	 /* start convresion */
	SET_BIT(ADCSRA,ADSC);
	
	/*WAIT until conversion complete*/
	while((GET_BIT(ADCSRA,ADIF))==0);
	
	/*clear flag*/
	SET_BIT(ADCSRA,ADIF);
	
	uint16 Local_u16Reading = ADCL >>6 ;
	Local_u16Reading |= (ADCH<<2);

	return Local_u16Reading ;
	
	/*return ADC; */      // ADC  pointer to 16  (adcl , adch)

}









