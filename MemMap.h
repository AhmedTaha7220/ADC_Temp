/*
 * MemMap.h
 *
 * Created: 2/18/2023 4:54:29 PM
 *  Author: Ahmed Wael
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

/******************** DIO REGISTERS ************************/
/*PORTC*/
#define DDRC *((volatile unsigned char *)0x27)
#define PORTC *((volatile unsigned char *) 0x28)
#define PINC *((volatile unsigned char *)0x26)
/*PORTB*/
#define DDRB *((volatile unsigned char *)0x24)
#define PORTB *((volatile unsigned char *) 0x25)
#define PINB *((volatile unsigned char *)0x23)
/*PORTD*/
#define PORTD *((volatile unsigned char *) 0x2B)
#define DDRD *((volatile unsigned char *)0x2A)
#define PIND *((volatile unsigned char *) 0x29)
/***********************************************************/

/******************** ADC REGISTERS ************************/

#define ADMUX *((volatile unsigned char *)0x7c)

#define REFS1 7
#define REFS0 6
#define ADLAR 5

#define ADCSRA *((volatile unsigned char *) 0x7a)

#define ADEN 7
#define ADSC 6


#define ADCH *((volatile unsigned char *) 0x79)
#define ADCL *((volatile unsigned char *) 0x78)


/******************** UART REGISTERS ************************/
#define UDR *((volatile unsigned char *) 0xc6)
#define UBRRH *((volatile unsigned char *) 0xc5)
#define UBRRL *((volatile unsigned char *) 0xc4)
#define	UCSRC *((volatile unsigned char *) 0xc2)
#define UCSRB *((volatile unsigned char *) 0xc1)
#define	UCSRA *((volatile unsigned char *) 0xc0)




#endif /* MEMMAP_H_ */