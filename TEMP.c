#include "TEMP.h"

u16 getTemp(void)
{
	u16 temp,volt;
	volt = ADC_ReadVolt(LM35);
	temp = volt/10;
	return temp;
}
