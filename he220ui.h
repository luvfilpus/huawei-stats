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

#include <string.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BAUDRATE B9600            
#define UIDEVICE "/dev/ttyUSB2"
#define BUFSIZE 256

#define HEIGHT 24
#define WIDTH 80

#define RSSI_HEIGHT 6
#define RSSI_WIDTH 10
#define RSSI_Y 2
#define RSSI_X 2

#define NORMAL "\033[0;0m"
#define BLUE   "\033[34;1m"
#define YELLOW "\033[33;1m"
#define CYAN   "\033[36;1m"
#define WHITE  "\033[37;1m"
#define LIGHTGREEN "\033[32;1m"
#define GREEN "\033[39;1m"
#define GRAY	"\033[30;1m"
#define PINK	"\033[35;1m"

WINDOW *rssi_, *stats, *rssi_hide, *mode;

int ncrs;

#define INDICATOR \
"        ||"\
"      ||||"\
"    ||||||"\
"  ||||||||"\
"||||||||||"\
"\n STRENGTH";
