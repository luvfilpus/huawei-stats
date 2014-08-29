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

void rssi(char *buff) {

	int signal;
	char *ind=INDICATOR;
	signal=atoi(buff);

	if (ncrs) {
		delwin(rssi_hide);
		wclear(rssi_);
		wprintw(rssi_,"%s",ind);
		rssi_hide = newwin(RSSI_HEIGHT, \
			RSSI_X+RSSI_WIDTH-(signal/2),\
			RSSI_Y,RSSI_X+signal/2);
		wclear(rssi_hide);
	} else printf("Signal strength: %i\n", signal);
	return;
		

}
