
/* ================================================================== */
/*                                                                    */
/*   WaitForCTS.c                                                     */
/*   (c) 2012 Author                                                  */
/*                                                                    */
/*   Description                                                      */
/*                                                                    */
/* ================================================================== */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>


#include <wiringPi.h>
#include <wiringSerial.h>

#include "../include/CognIoT-RFID.h"


int	WaitForCTS( int *sPort, int GPIO_PIN)
{

	serialFlush(*sPort);

	while (digitalRead(GPIO_PIN) == HIGH)
	{
		// Do Nothing
		
	}
	
	//printf("\n");
	
	return CMD_SUCCESS;
	
}
