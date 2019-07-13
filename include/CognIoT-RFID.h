
/* ================================================================== */
/*                                                                    */
/*   Utilities.h                                                      */
/*   (c) 2012 Author                                                  */
/*                                                                    */
/*   Description                                                      */
/*   API for the CognIot RFID application.                            */
/* ================================================================== */



#define CMD_SUCCESS	0x00
#define CMD_FAILURE 0x01

#define	TAGMODE_a	0x01	// Hitag H2
#define	TAGMODE_b	0x02	// Hitag H1/S (factory default)
#define	TAGMODE_c	0x03	// EM/MC2000



extern int	WaitForCTS( int *sPort, int GPIO_PIN);

extern int	GetCmdResult( int *sPort, int cmd, char **result);

extern int	SendCmds( int *sPort, int *cmds, char *result);

extern int	SetTagMode( int *sPort, int mode);
