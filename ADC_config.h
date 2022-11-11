/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer :  MCAL                  *****************/
/**************       SWC:     ADC_CONFIG_H_     *****************/
/**************       Version : 1.0                 *****************/
/**************       Date :   8/11/2021              *****************/


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

 /* Voltage Refrence Selection */
  /* AREF_OFF     
     AVCC         
     RESERVED     
     INTERNAL_2V56 */
 #define REFRENCE_SELECTION       AVCC

/*   LEFT_ADJUST    OR     RIGHT_ADJUST*/
#define ADC_ADJUST                LEFT_ADJUST

/* synchronization Interrupt  or pulling */
/*
INTERRUPT_ASYNCH
NO_INTERRUPT_ASYNCH*/
#define  OP_MODE                INTERRUPT_ASYNCH

/* Prescaler */
/*
DIVBY_2
DIVBY_4
DIVBY_8
DIVBY_16
DIVBY_32
DIVBY_64
DIVBY_128*/
#define  ADC_PRESCALER_SELECTION              DIVBY_128

#define ADC_CONVERSION_TIME_OUT                      10000000
 


#endif 