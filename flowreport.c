/*
                    (c)opyleft 2007 by 00ZIE <oozie@poczta.fm>

         All programs and config files in this package are considered
             free software; you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
       the Free Software Foundation; either version 3 of the License, or
       any later version. If you do modify the files in this package,
            plese leave the information about the author unchanged.
                       !!! FOR NON-COMMERCIAL USE ONLY !!!

*/

#include "he220ui.h"
#include <stdio.h>
#include <stdarg.h>

void flowreport(char *buff) {

	unsigned int \
		  SecondsPast,\
		  SpeedUp,\
		  SpeedDown,\
		  TX,\
		  RX;

		
	sscanf(buff,"%X,%X,%X,%X,%X", &SecondsPast,&SpeedUp,&SpeedDown,&TX,&RX);
	if (ncrs) {
		wclear(stats);	
		wprintw(stats,\
"Uptime\t: %is\nSpeedUp\t: %ikB/s\nSpeedDn\t: %ikB/s\nTrnsfd\t: %.1fMB\nRecvd\t: %.1fMB\n",\
SecondsPast,SpeedUp/1024,SpeedDown/1024,(double )TX/(1024*1024), (double)RX/(1024*1024));
		wrefresh(stats);
	} else printf("%is: %ikB/s UP, %ikB/s DOWN, TX %.1FMB / RX %.1fMB \n", SecondsPast, SpeedUp/1024, SpeedDown/1024, (double )TX/(1024*1024), (double)RX/(1024*1024));
	return;
		

}
