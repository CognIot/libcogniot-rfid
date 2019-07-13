/* ================================================================== */
/*                                                                    */
/*   GetResult.c                                                      */
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



int	GetResult( int *sPort, int cmd, char *result)
{

	int i = 0, inc_char = 1;  	// counters
	
	char	rec_byte;
	
	serialPutchar(*sPort, cmd);
	
	delay(100); // ??? Need to wait otherwise the command does not work

	while (serialDataAvail ( *sPort))
		{
						
			rec_byte = serialGetchar( *sPort) ;
			
			result = (char*)realloc(result, inc_char * sizeof(char));
			result[i] = rec_byte;
			
			i++;
			inc_char++;
			
		}
	
	result[i] = '\0';
	
	printf("GetResult : %s\n", result);
	
	
	
	
	
}
