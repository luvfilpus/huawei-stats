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

*/

void init_ncurses(void) {

   int maxY, maxX;
   char *ind=INDICATOR;
   
   initscr();
   noecho();
   halfdelay(1);
   curs_set(0);

   getmaxyx(stdscr,maxY,maxX);
   
   rssi_ = newwin(RSSI_HEIGHT+1, RSSI_WIDTH, RSSI_Y, RSSI_X);
		   wclear(rssi_);
		   wprintw(rssi_,"%s", ind);

   rssi_hide = newwin(RSSI_HEIGHT, RSSI_WIDTH,RSSI_Y,RSSI_X);

   stats = newwin(RSSI_HEIGHT, RSSI_WIDTH*2, RSSI_Y, RSSI_X+RSSI_WIDTH+2);
   mode = newwin(1, RSSI_WIDTH*2, RSSI_Y+RSSI_HEIGHT, RSSI_X+RSSI_WIDTH+2);
  
   /* draw signal strength bar in rssi window */


   /* 
   for(i=RSSI_WIDTH/2; i ; i--) {
        
	for(j=1; j<i; j++) {
           wprintw(rssi_,"  ");
        }

	for(j=i; j<= RSSI_WIDTH/2; j++)
           wprintw(rssi_,"||");
   }    
*/


   /* -- */ 


   wprintw(stats,"Uptime\t:\nSpeedUp\t:\nSpeedDn\t:\nTX\t:\nRX\t:\n");

   wprintw(mode, "\rMode: (?)");

   wprintw(rssi_hide,"\n\n (no data)");


   return;

}
