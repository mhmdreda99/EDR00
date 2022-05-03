/****************************************************/
/****************************************************/
/************  Author: Mahmoud Mohamed   ************/
/************  Layer: MCAL               ************/
/************  SWC: DIO                  ************/
/************  Version: 1.00             ************/
/****************************************************/
/****************************************************/

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_Math.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"
//function to set the pin direction , to be input or output . we took 3 arg 
//which port ,which pin ,direction ip or op
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
    u8 Local_u8ErrorState=0; //seting local error value with 0

    if(Copy_u8Pin<=DIO_u8PIN7) //checking that the pin value dosen't exceed 7
    {

        //we have two options for the direction of pin to be  input or output
        if (Copy_u8Direction==DIO_u8PIN_INPUT) //for the input pin direction
        {
         switch (Copy_u8Port) //we switch between the 4 port cases to clear bit
         {
             //if he chose dio_u8portA we use clr_bit func which take 2 arg ,the port and the pin number whic we take from him at the first setpindirection func
             case DIO_u8PORTA:CLR_BIT(DDRA,Copy_u8Pin);break;
             case DIO_u8PORTB:CLR_BIT(DDRB,Copy_u8Pin);break;
             case DIO_u8PORTC:CLR_BIT(DDRC,Copy_u8Pin);break;
             case DIO_u8PORTD:CLR_BIT(DDRD,Copy_u8Pin);break;
             default:Local_u8ErrorState=1; //return a local error with 1 if chose wrong port
         }   
        }
        else if (Copy_u8Direction==DIO_u8PIN_OUTPUT) //for the outout pin
        {
            switch (Copy_u8Port)
            {
             //same thing but we set the pin to make it output
             case DIO_u8PORTA:SET_BIT(DDRA,Copy_u8Pin);break;
             case DIO_u8PORTB:SET_BIT(DDRB,Copy_u8Pin);break;
             case DIO_u8PORTC:SET_BIT(DDRC,Copy_u8Pin);break;
             case DIO_u8PORTD:SET_BIT(DDRD,Copy_u8Pin);break;
             default:Local_u8ErrorState=1;
            }
        }
         else 
        {
        Local_u8ErrorState=1; //error if he didn't chose ip or op
        }
    }

    else 
    {
        Local_u8ErrorState=1; //error if he chose more than pin7
    }
    
    return Local_u8ErrorState; 
	
}
u8 DIO_u8SetPortDirection(u8 Copy_u8Port,  u8 Copy_u8Direction)//func to set port direction ip or op
{
	u8 Local_u8ErrorState=0;

    switch (Copy_u8Port)
    {
        case DIO_u8PORTA : DDRA =Copy_u8Direction;break;
        case DIO_u8PORTB : DDRB =Copy_u8Direction;break;
        case DIO_u8PORTC : DDRC =Copy_u8Direction;break;
        case DIO_u8PORTD : DDRD =Copy_u8Direction;break;
        default: Local_u8ErrorState=1;
    
    }
    return Local_u8ErrorState;
}
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=0;

    if (Copy_u8Pin<=DIO_u8PIN7)
    {
        if(Copy_u8Value==DIO_u8PIN_LOW)
        {
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8Pin);break;
                case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin);break;
                case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin);break;
                case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin);break;
                default :Local_u8ErrorState=1;break;
            }
        }
        
        else if (Copy_u8Value==DIO_u8PIN_HIGH)
        {
            switch (Copy_u8Port)
            {
                case DIO_u8PORTA : SET_BIT (PORTA,Copy_u8Pin);break;
                case DIO_u8PORTB : SET_BIT (PORTB,Copy_u8Pin);break;
                case DIO_u8PORTC : SET_BIT (PORTC,Copy_u8Pin);break;
                case DIO_u8PORTD : SET_BIT (PORTD,Copy_u8Pin);break;
                default:Local_u8ErrorState=1;break;

            }
        }
        else
        {
            Local_u8ErrorState=1;
        }

    } 
    else 
    {
        Local_u8ErrorState=1;
    }
    

    
    
    return Local_u8ErrorState;
}
u8 DIO_u8SetPortValue(u8 Copy_u8Port,  u8 Copy_u8Value)
{
	u8 Local_u8ErrorState=0;
    
        switch (Copy_u8Port)
    {
        case DIO_u8PORTA : PORTA =Copy_u8Value;break;
        case DIO_u8PORTB : PORTB =Copy_u8Value;break;
        case DIO_u8PORTC : PORTC =Copy_u8Value;break;
        case DIO_u8PORTD : PORTD =Copy_u8Value;break;
        default: Local_u8ErrorState=1;
    }
    return Local_u8ErrorState;
}
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin, u8*Copy_pu8Value)
{
	u8 Local_u8ErrorState=0;
    
    if ((Copy_pu8Value!=Null) && (Copy_u8Pin<=DIO_u8PIN7))
    {
           switch (Copy_u8Port)
    {
        case DIO_u8PORTA : *Copy_pu8Value =GET_BIT(PINA,Copy_u8Pin);break;
        case DIO_u8PORTB : *Copy_pu8Value =GET_BIT(PINB,Copy_u8Pin);break;
        case DIO_u8PORTC : *Copy_pu8Value =GET_BIT(PINC,Copy_u8Pin);break;
        case DIO_u8PORTD : *Copy_pu8Value =GET_BIT(PIND,Copy_u8Pin);break;
        default: Local_u8ErrorState=1;
    }
    


    }
    else {
        Local_u8ErrorState=1;
        }
    return Local_u8ErrorState;
}
/*u8 DIO_u8PullUpEnable(u8 Copy_u8Port,u8 Copy_u8Pin, u8 Copy_pu8Value)
{*/






//}

