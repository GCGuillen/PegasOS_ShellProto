//	help.c C File
//	Author: Giancarlo Guillen
//	Editor(s): 
//	Date Created: 5/23/2020
//	Summary: This file that will provide all the working commands for PegasOS.
//	Last Edited By: Giancarlo Guillen (6/9/2020)
#include "commands.h"

int main()
{
    fprintf(stdout,"This is a list of the Commands for PegasOS:\n\tbackgroundpalette\n\tcd\n\tclear\n\tconcat\n\tcopy\n\tcreatedir");
    fprintf(stdout,"\n\tcreatefile\n\tcurrentdir\n\tdelete\n\tdeletedir\n\techo\n\tfilespace\n\tfind\n\thead\n\thello\n\thelp\n\tlogin\n\tmount\n\tmove\n\tpower, systeminfo,tail");
    fprintf(stdout,"\n\tmount\n\tmove\n\tpower\n\tsysteminfo\n\ttail\n\ttasklist\n\ttermiantetask\n\ttextpalette\n\tuninstall\n");
    return 1;
}