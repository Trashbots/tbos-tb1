/*
 * Encoder.h
 *
 *  Created on: May 2, 2018
 *      Author: paulaustin
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include "Value.h"


void Encoder_Init(void);
void Encoder_Run(void);
void Encoder_RunISR(void);
int32_t Encoder_ReadCount(int);


enum
{
	kENCODER_1=0,
	kENCODER_2=1,
	kENCODER_Count
};

// Bit mask for ENC_Reset register
//#define mask_ENC_Reset_ENC1 	(1<<0)	//
//define mask_ENC_Reset_ENC2 	(1<<1)	//

class Encoder {
public:
	// ValueRegisters
	Value 	_ppr;
	Value 	_count;
	Value 	_rpm;
	int		_lastCount;
	// Used by ISR
	int 	_countEdge;  // count on A edge
	bool 	_lastEdgeA;
};

class EncoderManager
{
public:
	Value _resetTrigger;
	void 	Init();
	void 	RunISR();
	void 	CalckRPM(int);
	void 	Run();
	Encoder	_encoders[2];

};

extern EncoderManager gEncoders;


#endif /* ENCODER_H_ */
