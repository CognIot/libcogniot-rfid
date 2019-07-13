/* ================================================================== */
/*                                                                    */
/*   SendCmds.c                                                       */
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



int	SendCmds( int *sPort, int *cmds, char *result)
{
	int numcmds = 0;
	
	numcmds = (int) cmds[0] ;
	
	printf("SendCmds : Number of commands received = %d\n", numcmds);
	
	for (int count = 1; count <= numcmds; count++)
	{
		serialPutchar(*sPort, cmds[count]);
	}
	delay(100);
	
	



	return CMD_SUCCESS;
}
