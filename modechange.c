#include "he220ui.h"
/*
                    (c)opyleft 2007 by 00ZIE <oozie@poczta.fm>

         All programs and config files in this package are considered
             free software; you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
       the Free Software Foundation; either version 3 of the License, or
       any later version. If you do modify the files in this package,
            plese leave the information about the author unchanged.
                       !!! FOR NON-COMMERCIAL USE ONLY !!!


<sys_mode>: System mode. The values are as follows: 
0 No service. 
1 AMPS mode (not in use currently) 
2 CDMA mode (not in use currently) 
3 GSM/GPRS mode 
4 HDR mode 
5 WCDMA mode 
6 GPS mode 
<sys_submode>: System sub mode. The values are as follows: 
0 No service. 
1 GSM mode 
2 GPRS mode 
3 EDEG mode 
4 WCDMA mode 
5 HSDPA mode 
6 HSUPA mode 
7 HSDPA mode and HSUPA mode 
8 TD-SCDMA mode 
9 HSPA+ 

*/

#define BLUE   "\033[34;1m"
#define CYAN   "\033[36;1m"
#define NORMAL "\033[0;0m"
#define GREEN "\033[39;1m"
void modechange(char *buff) {

	switch (buff[0]) {
		case '4':	if (ncrs) wprintw(mode,"\rMode: WCDMA "); 
				printf("%s",BLUE);
				break;
		case '5':	if (ncrs) wprintw(mode,"\rMode: HSDPA "); 
				printf("%s",CYAN);
				break;
                case '6':	if (ncrs) wprintw(mode,"\rMode: HSUPA ");
                                printf("%s",GREEN);
                                break;
                case '7':	if (ncrs) wprintw(mode,"\rMode: HSDPA+HSUPA ");
                                printf("%s",GREEN);
                                break;
                case '8':	if (ncrs) wprintw(mode,"\rMode: TD-SCDMA ");
                                printf("%s",GREEN);
                                break;
                case '9':	if (ncrs) wprintw(mode,"\rMode: HSPA+ ");
                                printf("%s",GREEN);
                                break;
		default:	if (ncrs) wprintw(mode,"\rMode: ?? %s ??",buff);
		                /* printf("%s",buff[0]); */
	}
	if (ncrs) wrefresh(mode);
	printf("%s",NORMAL);	
	return;
}
