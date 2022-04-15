/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : DIO                  ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)                   CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)            0b##b7##b6##b5##b4##b3##b2##b1##b0

#define PORTA_DIR           CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR           CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR           CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR           CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)

#define PORTA_INT           CONC(PORTA_PIN7_INT,PORTA_PIN6_INT,PORTA_PIN5_INT,PORTA_PIN4_INT,PORTA_PIN3_INT,PORTA_PIN2_INT,PORTA_PIN1_INT,PORTA_PIN0_INT)
#define PORTB_INT           CONC(PORTB_PIN7_INT,PORTB_PIN6_INT,PORTB_PIN5_INT,PORTB_PIN4_INT,PORTB_PIN3_INT,PORTB_PIN2_INT,PORTB_PIN1_INT,PORTB_PIN0_INT)
#define PORTC_INT           CONC(PORTC_PIN7_INT,PORTC_PIN6_INT,PORTC_PIN5_INT,PORTC_PIN4_INT,PORTC_PIN3_INT,PORTC_PIN2_INT,PORTC_PIN1_INT,PORTC_PIN0_INT)
#define PORTD_INT           CONC(PORTD_PIN7_INT,PORTD_PIN6_INT,PORTD_PIN5_INT,PORTD_PIN4_INT,PORTD_PIN3_INT,PORTD_PIN2_INT,PORTD_PIN1_INT,PORTD_PIN0_INT)




#endif
