default : main

main :  headers.h functions.h tokenise.c trimSpace.c cdCommand.c lsCommand.c pinfo.c sysCommands.c history.c main.c 
		gcc tokenise.c trimSpace.c cdCommand.c lsCommand.c pinfo.c sysCommands.c history.c main.c -lreadline -o shell