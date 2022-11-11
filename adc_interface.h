/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer :  MCAL                  *****************/
/**************       SWC:     ADC_INTERFACE_H_     *****************/
/**************       Version : 1.0                 *****************/
/**************       Date :   7/11/2021              *****************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


/*Functon Prototypes *******************************************/
/*
* Description : This function is used to initialize the ADC
* Parameters  : void
* Return      : void
*/

void ADC_voidInit(void);

/*Functon Prototypes *******************************************/
/*
* Description : This function is used to read value form channnel Synchronous
* Parameters  :  select one of this channel:
                ADC_CHANNEL_0 
*               ADC_CHANNEL_1 
*               ADC_CHANNEL_2 
*               ADC_CHANNEL_3 
*               ADC_CHANNEL_4 
*               ADC_CHANNEL_5 
*               ADC_CHANNEL_6 
*               ADC_CHANNEL_7 
*               ADC_CHANNEL_8 
*
*
* Return      : u16 :reading value
*/

ERROR_STATE ADC_u16ReadChannelSync(uint8 Copy_u8Channel  ,uint16* Copy_u16Reading );

/*Functon Prototypes *******************************************/
/*
* Description : This function is used to read value form channnel Asynchronous
* Parameters  : 1. select one of this channel:
                ADC_CHANNEL_0 
*               ADC_CHANNEL_1 
*               ADC_CHANNEL_2 
*               ADC_CHANNEL_3 
*               ADC_CHANNEL_4 
*               ADC_CHANNEL_5 
*               ADC_CHANNEL_6 
*               ADC_CHANNEL_7 
*               ADC_CHANNEL_8 
              2. pointer to uint16 reading 
              3. pointer to Notification function "pointer to fun"
*
*
* Return      : void
*/

ERROR_STATE ADC_voidReadChannelAsync(uint8 Copy_u8Channel ,uint16* Copy_pu16Reading , void (* Copy_pvNotificationFun)(void));


#endif /* ADC_INTERFACE_H_ */
