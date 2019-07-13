/* ================================================================== */
/*                                                                    */
/*   SetTagMode.c                                                       */
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



int	SetTagMode( int *sPort, int mode)
{
	
	printf("Setting mode %d.....\n", mode);
	
	serialPutchar(*sPort, 0x76);
	serialPutchar(*sPort, mode);

	delay(100);
	printf("Mode %d set.\n\n", mode);
	
	
	return CMD_SUCCESS;
}
