/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer : MCAL                  *****************/
/**************       SWC:     ADC_PRIVATE_H_        *****************/
/**************       Version : 1.0                 *****************/
/**************       Date : 30/12/2021              *****************/


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/* Voltage Refrence Selection */
#define  AREF_OFF                1             // Internal Vref turned off
#define  AVCC                    2             //AVCC with external capacitor at AREF pin
#define  RESERVED                3
#define  INTERNAL_2V56           4             //Internal 2.56V Voltage Reference with external capacitor at AREF pin

#define  LEFT_ADJUST             1
#define  RIGHT_ADJUST            2

/* Interrupt  or pulling */
#define  INTERRUPT_ASYNCH        1
#define  NO_INTERRUPT_ASYNCH     2

/* Prescalar */
#define DIVBY_2                  0
#define DIVBY_4                  2
#define DIVBY_8                  3
#define DIVBY_16                 4
#define DIVBY_32                 5
#define DIVBY_64                 6
#define DIVBY_128                7

/* Prescalar mask*/
#define ADC_PRESCALER_MASK       0b1111000

/* channel mask*/
#define  ADC_CHANNEL_MASK        0b1110000
#define ADC_CHANNEL_0            0
#define ADC_CHANNEL_1            1
#define ADC_CHANNEL_2            2
#define ADC_CHANNEL_3            3
#define ADC_CHANNEL_4            4
#define ADC_CHANNEL_5            5
#define ADC_CHANNEL_6            6
#define ADC_CHANNEL_7            7
#define ADC_CHANNEL_8            8


#endif /* ADC_PRIVATE_H_ */
