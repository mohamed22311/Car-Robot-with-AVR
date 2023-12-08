/*
 * bluetooth.h
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */

#ifndef BASE_BLUETOOTH_H_
#define BASE_BLUETOOTH_H_


void BT_Init();
u8  BT_RX();
void BT_TX(u8 data);
void BT_TX_string (u8 data[]);

#endif /* BASE_BLUETOOTH_H_ */
