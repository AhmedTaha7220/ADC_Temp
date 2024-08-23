/*
 * Utils.h
 *
 * Created: 3/20/2023 2:31:38 PM
 *  Author: CAIRO
 */ 


#ifndef UTILS_H_
#define UTILS_H_


/**********************UTILS********************************/
#define GET_BIT(reg,bit)     ((reg>>bit)&1)
#define SET_BIT(reg,bit)     (reg |= (1<<bit))
#define CLR_BIT(reg,bit)     (reg &= ~(1<<bit))
#define TOG_BIT(reg,bit)     (reg ^= (1<<bit))
#define write_bit(reg,bit,val)    (reg = reg&~(1<<bit)|val<<bit)





#endif /* UTILS_H_ */