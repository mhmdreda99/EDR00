/*
 * @file          ADC_Config.h
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date          2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * Description :  Configurable file for the ADC driver
 
 */

/*This is preprocessor Header file guard  */
#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/*******************************Voltage Reference Selection***************************/
//#define AREF_Internal_VREF
#define AREF_External_VREF
/*******************************Resolution Selection**********************************/
#define Resolution_10_Bit
//#define Resolution_8_Bit
/********************************Prescaler Selection**********************************/
//#define ADC_Prescaler_2
//#define ADC_Prescaler_4
//#define ADC_Prescaler_8
//#define ADC_Prescaler_16
//#define ADC_Prescaler_32
//#define ADC_Prescaler_64
#define ADC_Prescaler_128
/***************************************************************************************/
/*This is preprocessor Header file guard End  */
#endif /* MCAL_ADC_ADC_CONFIG_H_ */
