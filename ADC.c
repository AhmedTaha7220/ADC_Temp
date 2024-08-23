
#include "ADC.h"


void ADC_Init(u8 prescaler, u8 vref)
{
	/*Vref -> []*/
	switch(vref)
	{
		case AREF:
		CLR_BIT(ADMUX,REFS1);
		CLR_BIT(ADMUX,REFS0);
		break;
		case AVCC:
		CLR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
		case Internal_11V:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
	}
	/*prescaler*/
	// here it means use only the first 3 bits in the register because the number f8 means 1111 1000 which means use on the 0 bits to put your pre-scaler in
	ADCSRA = ADCSRA & 0xf8;
	//And now after cleaning the first 3 bits we type our pre-scaler in them
	ADCSRA = ADCSRA | prescaler;

	/*Reading Adjustment [adlar]*/	
	CLR_BIT(ADMUX,ADLAR);
	
	/*Enable*/
	SET_BIT(ADCSRA,ADEN);
}

u16 ADC_Read(u8 channel)
{
	//select channel
	//here it means use only the first 5 bits in the register because the number E0 means 1110 0000 which means use only the 0 bits to put your channel in
	ADMUX =  ADMUX &  0xE0;
	//And now after we cleaned the first 5 bits we type our channel in 
	ADMUX = ADMUX | channel;
	
	//start conversion
	SET_BIT(ADCSRA,ADSC);

	//wait while converstion ends
	while(GET_BIT(ADCSRA,ADSC));
	
	
	//return read
	u16 adc;
	/*
		=> Paraphrase of the equation below:
			the reading of the ADC is stored in 2 registers (ADCH which means  ADC high) and (ADCL which means ADC low) but the value is stored in 10 bits 
			and the register include 8 bits that's why we needed 2 registers (16 bits) so we use the whole (ADCL) register '8 bits' whereas we only need to use 2 bits 
			from the register ADCH not the whole 8 bits inside it, that's why we make 8 bits shifting to obtain only the first 2 bits in the register, and we made casting (u16) for
			both registers to make them stored as one register have 16 bits
	*/
	adc = ((u16)ADCH<<(u16)8) | (u16)ADCL;
	return adc;
}
