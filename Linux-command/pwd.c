#include "command.h"

int my_pwd(int argc, char *argv[])
{
	char cwd[PATH_MAX];
	if (getcwd(cwd, PATH_MAX)) {
		printf("%s\n", cwd);
		return 0;
	}
	else
		perror(argv[0]);

	return -1;
}
