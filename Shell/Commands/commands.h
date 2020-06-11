//	commands.h Header File
//	Author: Giancarlo Guillen
//	Editor(s): Christopher Walen
//	Date Created: 5/20/2020
//	Summary: This file is the Commands header file which will hold all the functions to be used within
//           C files for each command in PegasOS.
//	Last Edited By: Giancarlo Guillen (5/24/2020)

#ifndef COMMANDS_H
	#define COMMANDS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    //#include <windows.h>
    #include <dirent.h>
    #include "echo.c"
    #include "changeDir.c"
    #include "backgroundPal.c"
    #include "clear.c"
    #include "concat.c"
    #include "copy.c"
    #include "createDir.c"
    #include "createFile.c"
    #include "currentDir.c"
    #include "delete.c"
    #include "deleteDir.c"
    #include "filespace.c"
    #include "find.c"
    #include "head.c"
    #include "hello.c"
    #include "login.c"
    #include "mount.c"
    #include "move.c"
    #include "power.c"
    #include "systemInfo.c"
    #include "tail.c"
    #include "taskList.c"
    #include "terminateTask.c"
    #include "textPalette.c"
    #include "uninstall.c"

    int changeDirectory(char parameter[]);
    int copyFile();
    int echoString(char *repeatString);
#endif