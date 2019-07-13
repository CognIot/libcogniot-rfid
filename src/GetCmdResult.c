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



int	GetCmdResult( int *sPort, int cmd, char **result)
{

	int i = 0, inc_char = 1;  	// counters
	
	char	rec_byte;
	
	//printf("\t==========> ENTERING GetCmdResult\n" );
	//printf("\t==========> Pointer result in GetCmdResult = %p\n", result);
	//printf("\t==========> Result : %s\n", *result);
	
	serialPutchar(*sPort, cmd);
	
	delay(100); // ??? Need to wait otherwise the command does not work
	
	
	
	while (serialDataAvail ( *sPort))
		{
						
			rec_byte = serialGetchar( *sPort) ; 
			
			*result = realloc(*result, inc_char * sizeof(char));
			
			(*result)[i] = (char) rec_byte;
			
			i++;
			inc_char++;
		}
			
		printf("\n");
		
		result[i] = '\0';
	
	//printf("\t==========> LEAVING GetCmdResult\n" );
	//printf("\t==========> Pointer result leaving GetCmdResult  = %p\n", result);	
	//printf("\t==========> Result : %s\n\n\n", *result);
	
	
	return CMD_SUCCESS;
	
	
}
