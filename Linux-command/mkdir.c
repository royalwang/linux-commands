#include "command.h"

#define DIR_MODE S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH

int my_mkdir(int argc, char *argv[])
{
	char cwd[PATH_MAX];
	char path[PATH_MAX];
	
	if (argc < 2) {
		printf("Usage: ./command %s DIRECTORY...\n", argv[0]);
	}

	if (getcwd(cwd, PATH_MAX) == NULL) {
		perror(argv[0]);
		return -1;
	}	

	if (argv[1][0] == '/')
		strcpy(path, argv[1]);
	else{
		strcpy(path, cwd);
		strcat(path, "/");
		strcat(path, argv[1]);
	}

	if (mkdir(path, DIR_MODE) == 0)
		return 0;
	else{
		perror(argv[0]);
		return -1;
	}
}
