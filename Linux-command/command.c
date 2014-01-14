#include <string.h>
#include "command.h"

#define COM_MAX 100		/*implement at most 'COM_MAX' commands*/

int execute_command(struct command *com, int argc, char *argv[]);

struct command com[] = {
	{"uname", my_uname},
	{"pwd", my_pwd},
	{"hostname", my_hostname},
	{"mkdir", my_mkdir},
};

int com_num = sizeof com / sizeof(struct command);

int main(int argc, char *argv[])
{
	if (argc >= 2)
		return execute_command(com, argc - 1, &argv[1]);
	else{
		printf("Usage: ./command [command] [options]\n");	
		printf("[command]:\n");

		int i;
		for (i = 0; i < com_num; ++i)
			printf("\t%s\n", com[i].name);
	}

	return 0;
}

int execute_command(struct command *com, int argc, char *argv[])
{
	int i;
	for (i = 0; i < com_num; ++i)
	{
		if (!strcmp(com[i].name, argv[0])) {
			return com[i].execute(argc, argv);
		}
	}

	printf("%s: cannot find!\n", argv[0]);
	return -1;
}
