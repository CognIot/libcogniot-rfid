
/* ================================================================== */
/*                                                                    */
/*   SendCommand.c                                                     */
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





int SendCommand( int *sPort, int cmd)
{
	serialPutchar(*sPort, cmd);
	delay(100); // ??? Need to wait otherwise the command does not work
	
}
