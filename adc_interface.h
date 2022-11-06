/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer : MCAL                  *****************/
/**************       SWC:     ADC_INTERFACE_H_     *****************/
/**************       Version : 1.0                 *****************/
/**************       Date : 30/12/2021              *****************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define adc_ch_0 0
#define adc_ch_1 1
#define adc_ch_2 2
#define adc_ch_3 3
#define adc_ch_4 4
#define adc_ch_5 5
#define adc_ch_6 6
#define adc_ch_7 7
#define adc_ch_8 8


void adc_init(void);
u16 adc_read(u8 channel);

#endif /* ADC_INTERFACE_H_ */
