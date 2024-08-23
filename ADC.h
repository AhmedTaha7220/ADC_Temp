


#ifndef ADC_H_
#define ADC_H_

#define F_CPU 16000000
#include "util/delay.h"


#include "../LIB/StdTypes.h"
#include "../LIB/Utils.h"
#include "../LIB/MemMap.h"


/*********Defines*********/

/*vref*/
#define AREF 0
#define AVCC 1	
#define Internal_11V 2   /*11 is 1.1v*/

/*prescaler*/
#define ADC_SCALER_2 1
#define ADC_SCALER_4 2
#define ADC_SCALER_8 3
#define ADC_SCALER_16 4
#define ADC_SCALER_32 5
#define ADC_SCALER_64 6
#define ADC_SCALER_128 7

/*Channels*/
#define CH_0 0
#define CH_1 1
#define CH_2 2
#define CH_3 3
#define CH_4 4
#define CH_5 5





void ADC_Init(u8 prescaler, u8 vref);

u16 ADC_Read(u8 channel);




#endif /* ADC_H_ */