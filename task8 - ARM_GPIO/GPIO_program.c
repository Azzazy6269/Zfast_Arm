/********************
Author    : Mohammad Ibraheem Fatehy
Date      : 21 Feb 2025
File_name : GPIO_program.c
*********************/

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

Std_ReturnType GPIO_SetPinMode(u8 Copy_PortId , u8 Copy_PinId , u8 Copy_PinMode){
Std_ReturnType Local_FunctionStatus = E_OK ;
	switch(Copy_PortId){
		case GPIO_PORTA :
			if(Copy_PinId<8){
				GPIOA_CRL &= ~((0b1111) << (Copy_PinId * 4)); 
        GPIOA_CRL |= (Copy_PinMode << (Copy_PinId * 4));
			}else if(Copy_PinId<16){
				GPIOA_CRH &= ~((0b1111) << (Copy_PinId * 4)); 
        GPIOA_CRH |= (Copy_PinMode << (Copy_PinId * 4));
			}else{
				Local_FunctionStatus = E_NOT_OK;
			}
			break;
		case GPIO_PORTB :
			if(Copy_PinId<8){
				GPIOB_CRL &= ~((0b1111) << (Copy_PinId * 4)); 
        GPIOB_CRL |= (Copy_PinMode << (Copy_PinId * 4));
			}else if(Copy_PinId<16){
				GPIOB_CRH &= ~((0b1111) << (Copy_PinId * 4)); 
        GPIOB_CRH |= (Copy_PinMode << (Copy_PinId * 4));
			}else{
				Local_FunctionStatus = E_NOT_OK;
			}
			break;
		case GPIO_PORTC :
			if(Copy_PinId<8){
				GPIOC_CRL &= ~((0b1111) << (Copy_PinId * 4)); 
        GPIOC_CRL |= (Copy_PinMode << (Copy_PinId * 4));
			}else if(Copy_PinId<16){
				GPIOC_CRH &= ~((0b1111) << (Copy_PinId * 4)); 
        GPIOC_CRH |= (Copy_PinMode << (Copy_PinId * 4));
			}else{
				Local_FunctionStatus = E_NOT_OK;
			}
			break;
		default:
			Local_FunctionStatus = E_NOT_OK;
			break;
	}
return Local_FunctionStatus ;
}


Std_ReturnType GPIO_Set_Pin_Value(u8 Copy_PortId , u8 Copy_PinId , u8 Copy_PinValue){
Std_ReturnType Local_FunctionStatus = E_OK ;
	switch(Copy_PortId){
		case GPIO_PORTA:
			switch (Copy_PinValue){
				case  GPIO_HIGH :
					SET_BIT(GPIOA_ODR,Copy_PinId);
			    break;
				case  GPIO_LOW :
					CLR_BIT(GPIOA_ODR,Copy_PinId);
				  break;
				default : 
					Local_FunctionStatus = E_NOT_OK ;
		      break;
			}
			break;
     case GPIO_PORTB:
			switch (Copy_PinValue){
				case  GPIO_HIGH :
					SET_BIT(GPIOB_ODR,Copy_PinId);
			    break;
				case  GPIO_LOW :
					CLR_BIT(GPIOB_ODR,Copy_PinId);
				  break;
				default : 
					Local_FunctionStatus = E_NOT_OK ;
		      break;
			}
			break;
			case GPIO_PORTC:
			switch (Copy_PinValue){
				case  GPIO_HIGH :
					SET_BIT(GPIOC_ODR,Copy_PinId);
			    break;
				case  GPIO_LOW :
					CLR_BIT(GPIOC_ODR,Copy_PinId);
				  break;
				default : 
					Local_FunctionStatus = E_NOT_OK ;
		      break;
			}
			break;
		default :
			Local_FunctionStatus = E_NOT_OK ;
		  break;
	}
return Local_FunctionStatus ;

}
Std_ReturnType GPIO_Get_Pin_Value(u8 Copy_PortId , u8 Copy_PinId , u8 * Copy_PinValue){
Std_ReturnType Local_FunctionStatus = E_OK ;
	if (NULL == Copy_PinValue){
		Local_FunctionStatus = E_NOT_OK ;
	}else{
		switch (Copy_PortId) {
			case GPIO_PORTA :
				*Copy_PinValue  =GET_BIT(GPIOA_IDR,Copy_PinId);
			  break;
			case GPIO_PORTB :
				*Copy_PinValue=GET_BIT(GPIOB_IDR,Copy_PinId) ;
			  break;
			case GPIO_PORTC :
				*Copy_PinValue=GET_BIT(GPIOC_IDR,Copy_PinId) ;
			  break;
			default :
				Local_FunctionStatus = E_NOT_OK ;
	}
}
return Local_FunctionStatus ;
}
