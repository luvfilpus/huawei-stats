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


extern void modechange(char *buff); 
extern void flowreport(char *buff); 
extern void rssi(char *buff);
extern void init_ncurses(void);

void unknown(char *buff) {

	/*
	I function left for the future.
	Maybe you know what BOOT: means?
	*/

	return;
}

int main(int argc, char **argv) {
   int fd, bytes;
   char *buf, *buf2;
   char c;
    
   printf("\nHUAWEI e220 statistics by OOZIE <oozie@poczta.fm>\n\n");
   // FOR DEBUGGING - you can change ncrs to 0 and enjoy raw output
   ncrs=1;
	buf=(char *)malloc(BUFSIZE*sizeof(char));

	fd = open(UIDEVICE, O_RDONLY | O_NOCTTY ); 
	if (fd < 0) {
	 	printf("%s: Problem opening %s.\n",argv[0],UIDEVICE);
		exit(1);
	}

	if (ncrs) {
		init_ncurses();
		printw(" HUAWEI E220 Statistics   [q]uit ");
	}

	while (c!='q'&&c!='Q')
	while ((c=getch())==ERR) {
		bytes = read(fd,buf,255);
		buf2=strchr(buf,'^');
		buf[bytes]=0x00; 
 
		if (buf2) {
			strcpy(buf, buf2); 
			if (buf[0]=='^') {
				fflush(stdout);
				switch (buf[1]) {
					case 'B': unknown(buf); break;
					case 'M': modechange(buf+8); break;
					case 'D': flowreport(buf+11); break;
					case 'R': rssi(buf+6); break;
					default : unknown(buf);
				}
				if (ncrs) {
				wrefresh(rssi_);
				wrefresh(rssi_hide);
				wrefresh(stats);
				wrefresh(mode); 
				}
			}
		}
	}
	
	if (ncrs) endwin();
	return 0;
}

