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

static uint16* ADC_pu16GlobalReadingVlue=0;
static void (*ADC_pvGlobalCallBackNotificationFunc)(void)=NULL;


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




ERROR_STATE ADC_u16ReadChannelSync(uint8 Copy_u8Channel ,uint16* Copy_pu16Reading){
    uint32 Local_u32Counter=0;
	ERROR_STATE  Local_emErrorState=OK;
	
	
	if(Copy_pu16Reading == NULL){
		
		Local_emErrorState=	NOK;
		return Local_emErrorState;
	}
	else{
	/* SELECT CHANNEL */
	ADMUX &= ADC_CHANNEL_MASK;
	ADMUX |= Copy_u8Channel;
	
	 /* start convresion */
	SET_BIT(ADCSRA,ADSC);
	
	/*Wait until conversion complete*/
	while((GET_BIT(ADCSRA,ADIF))==0   &&   Local_u32Counter < ADC_CONVERSION_TIME_OUT){
		Local_u32Counter++;
	}
	
	if(Local_u32Counter >= ADC_CONVERSION_TIME_OUT){
		Local_emErrorState =NOK;
		return Local_emErrorState;
	}
	else{
		Local_emErrorState =OK;
		
		/*clear flag*/
		SET_BIT(ADCSRA,ADIF);
		
		/* ADC Adjust*/
		#if ADC_ADJUST      LEFT_ADJUST
		     uint16 Local_u16Reading = ADCL >>6 ;
		     Local_u16Reading |= (ADCH<<2);

		     *Copy_pu16Reading= Local_u16Reading ;
			 
		#elif ADC_ADJUST    RIGHT_ADJUST
		     uint16 Local_u16Reading = ADCL ;
		     Local_u16Reading |= (ADCH <<8);

		     *Copy_pu16Reading= Local_u16Reading ;
		#endif
		
		
		/* *Copy_u16Reading = ADC; */      // ADC  pointer to 16  (adcl , adch)
		
		return Local_emErrorState
	}
	}
	
}


ERROR_STATE ADC_voidReadChannelAsync(uint8 Copy_u8Channel ,uint16* Copy_pu16Reading , void (* Copy_pvNotificationFun)(void)){
	
	uint32 Local_u32Counter=0;
	ERROR_STATE  Local_emErrorState=OK;
	
	if(Copy_pu16Reading == NULL || Copy_pvNotificationFun==NULL){
		
		Local_emErrorState=	NOK;
		return Local_emErrorState;
	}
	else{
		  /* initialize the reading variable globally */
		   ADC_pu16GlobalReadingVlue =Copy_pu16Reading;
		   /* initialize the call back function globally  */
		  ADC_pvGlobalCallBackNotificationFunc=Copy_pvNotificationFun;		
		  
		  /* SELECT CHANNEL */
		  ADMUX &= ADC_CHANNEL_MASK;
		  ADMUX |= Copy_u8Channel;
		  
		  /* start convresion */
		  SET_BIT(ADCSRA,ADSC);
		  
		  /* Enable ADC Interrupt */
		  SET_BIT(ADCSRA,ADCSRA_ADIE);
		
		return Local_emErrorState;
	}
	
}

void __vector_16 (void)  __attribute__(signal)
void __vector_16 (void)
{
    /* read ADC Value*/
	/* ADC Adjust*/
	#if ADC_ADJUST      LEFT_ADJUST
	uint16 Local_u16Reading = ADCL >>6 ;
	Local_u16Reading |= (ADCH<<2);

	*ADC_pu16GlobalReadingVlue= Local_u16Reading ;
	
	#elif ADC_ADJUST    RIGHT_ADJUST
	uint16 Local_u16Reading = ADCL ;
	Local_u16Reading |= (ADCH <<8);

	*ADC_pu16GlobalReadingVlue= Local_u16Reading ;
	#endif
	
	/* call call back Notificatio function */
	
	ADC_pvGlobalCallBackNotificationFunc();
	
	/* Disable ADC intrrupt */
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}






