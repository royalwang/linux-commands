#ifndef	_COMMAND_H
#define _COMMAND_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define LEN 20
#define PATH_MAX 256
#define HOSTNAME_MAX 256

struct command{
	char name[LEN];
	int (*execute)(int argc, char *argv[]);
};

int my_uname(int argc, char *argv[]);
int my_pwd(int argc, char *argv[]);
int my_mkdir(int argc, char *argv[]);
int my_hostname(int argc, char *argv[]);

#endif
