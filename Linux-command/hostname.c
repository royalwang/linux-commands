#include "command.h"

int my_hostname(int argc, char *argv[])
{
	char hostname[HOSTNAME_MAX];
	if(gethostname(hostname, HOSTNAME_MAX) == 0){
		printf("%s\n", hostname);
		return 0;	
	}
	else
		perror(argv[0]);

	return -1;
}
