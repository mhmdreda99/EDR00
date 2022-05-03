/*
 ============================================================================
 Name        : GPIO.c
 Author      : Mostafa Magdy
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 29/08/2021
 Copyright   : This is an open source code for all embedded systems students
 Description : GPIO Driver
 ============================================================================
 */
#include "GPIO.h"

void GPIO_init(void)
{
    // initializing all pins are input
    DDRA=0;
    DDRB=0;
    DDRC=0;
    DDRD=0;

    PORTA=0;
    PORTB=0;
    PORTC=0;
    PORTD=0;

    //enable the internal pull up resistor
    CLEAR_BIT(SFIOR,PUD);
}

StdReturn GPIO_SetPinDirection(GPIO_port port, uint8 pin, GPIO_pinType state)
{
    // check انت اهبل
    if(pin>MAX_PIN_NUM)
    {
        return E_NOK; 
    }
    else
    {
        switch (port)
        {
            //controlling Port A
        case GPIO_PORTA:
            switch (state)
            {
            case GPIO_INPUT:
                CLEAR_BIT(DDRA,pin);
                break;
            case GPIO_OUTPUT:
                SET_BIT(DDRA,pin);
                break;
            default:
                return E_NOK;
            }
            break;

            //controlling Port B
        case GPIO_PORTB:
            switch (state)
            {
            case GPIO_INPUT:
                CLEAR_BIT(DDRB,pin);
                break;
            case GPIO_OUTPUT:
                SET_BIT(DDRB,pin);
                break;
            default:
                return E_NOK;
            }
            break;

            //controlling Port C
        case GPIO_PORTC:
            switch (state)
            {
            case GPIO_INPUT:
                CLEAR_BIT(DDRC,pin);
                break;
            case GPIO_OUTPUT:
                SET_BIT(DDRC,pin);
                break;
            default:
                return E_NOK;
            }
            break;

            //controlling Port D
        case GPIO_PORTD:
            switch (state)
            {
            case GPIO_INPUT:
                CLEAR_BIT(DDRD,pin);
                break;
            case GPIO_OUTPUT:
                SET_BIT(DDRD,pin);
                break;
            default:
                return E_NOK;
            }
            break;

        default:
            return E_NOK;
        }
    } 
        return E_OK;
}

StdReturn GPIO_WritePin(GPIO_port port, uint8 pin, GPIO_pinState state)
{
    if (pin>MAX_PIN_NUM)
    {
        return E_NOK; 
    }
    else
    {
        switch (port)
        {
        case GPIO_PORTA:
            switch (state)
            {
                case GPIO_HIGH:
                    SET_BIT(PORTA,pin);
                    break;
                case GPIO_LOW:
                    CLEAR_BIT(PORTA,pin);
                    break;
                default:
                    return E_NOK;
            }
            break;

        case GPIO_PORTB:
            switch (state)
            {
                case GPIO_HIGH:
                    SET_BIT(PORTB,pin);
                    break;
                case GPIO_LOW:
                    CLEAR_BIT(PORTB,pin);
                    break;
                default:
                    return E_NOK;
            }
            break;

        case GPIO_PORTC:
            switch (state)
            {
                case GPIO_HIGH:
                    SET_BIT(PORTC,pin);
                    break;
                case GPIO_LOW:
                    CLEAR_BIT(PORTC,pin);
                    break;
                default:
                    return E_NOK;
            }
            break;
        
        case GPIO_PORTD:
            switch (state)
            {
                case GPIO_HIGH:
                    SET_BIT(PORTD,pin);
                    break;
                case GPIO_LOW:
                    CLEAR_BIT(PORTD,pin);
                    break;
                default:
                    return E_NOK;
            }
            break;
        }
    }
        return E_OK;
}

StdReturn TOOGLE_PIN(GPIO_port port,uint8 pin)
{
    if (pin>MAX_PIN_NUM)
    {
        return E_NOK; 
    }
    else
    {
        switch (port)
        {
            case GPIO_PORTA:
                TOGGLE_BIT(PORTA,pin);
                break;

            case GPIO_PORTB:
                TOGGLE_BIT(PORTB,pin);
                break;

            case GPIO_PORTC:
                TOGGLE_BIT(PORTC,pin);
                break;

            case GPIO_PORTD:
                TOGGLE_BIT(PORTD,pin);
                break;
                
            default:
                return E_NOK;
        }
    }
        return E_OK;
}

StdReturn GPIO_ReadPin(GPIO_port port, uint8 pin, GPIO_pinState *state)
{
    if (pin>MAX_PIN_NUM)
    {
        return E_NOK; 
    }
    else
    {
        switch (port)
        {
        case GPIO_PORTA:
            *state=READ_BIT(PINA,pin);
            break;

        case GPIO_PORTB:
            *state=READ_BIT(PINB,pin);
            break;

        case GPIO_PORTC:
            *state=READ_BIT(PINC,pin);
            break;

        case GPIO_PORTD:
            *state=READ_BIT(PIND,pin);
            break;

        default:
            return E_NOK;
        }
    }
        return E_OK;
}

StdReturn GPIO_EnablePullup(GPIO_port port, uint8 pin, GPIO_pullupEnable state)
{
    if (pin>MAX_PIN_NUM)
    {
        return E_NOK; 
    }
    else
    {
        switch (port)
        {
        case GPIO_PORTA:
            switch (state)
            {
            case GPIO_PULLUP_DISABLE:
                SET_BIT(PORTA,pin);
                break;
            case GPIO_PULLUP_ENABLE:
                CLEAR_BIT(PORTA,pin);
                break;
            default:
                return E_NOK;
            }
            break;

        case GPIO_PORTB:
            switch (state)
            {
            case GPIO_PULLUP_DISABLE:
                SET_BIT(PORTB,pin);
                break;
            case GPIO_PULLUP_ENABLE:
                CLEAR_BIT(PORTB,pin);
                break;
            default:
                return E_NOK;
            }
            break;

        case GPIO_PORTC:
            switch (state)
            {
            case GPIO_PULLUP_DISABLE:
                SET_BIT(PORTC,pin);
                break;
            case GPIO_PULLUP_ENABLE:
                CLEAR_BIT(PORTC,pin);
                break;
            default:
                return E_NOK;
            }
            break;
        case GPIO_PORTD:
            switch (state)
            {
            case GPIO_PULLUP_DISABLE:
                SET_BIT(PORTD,pin);
                break;
            case GPIO_PULLUP_ENABLE:
                CLEAR_BIT(PORTD,pin);
                break;
            default:
                return E_NOK;
            }
            break;
        }
    }
        return E_OK;
}
