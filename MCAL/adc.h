/*
 * adc.h
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */

#ifndef BASE_ADC_H_
#define BASE_ADC_H_

#include "macros.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
u16 ADC_readChannel(u8 channel_num);

#endif /* BASE_ADC_H_ */
