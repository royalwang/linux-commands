#include "command.h"
#include <sys/utsname.h> 

int my_uname(int argc, char *argv[])
{
	/*supports: -a, -s, -n, -r, -v, -m*/
	char *opts = "asnrvm";
	char opt;

	struct utsname name;
	if(uname(&name) >= 0){
		while((opt = getopt(argc, argv, opts)) != -1){
			if (opt == 'a' || opt == 's')
				printf("%s ", name.sysname);

			if (opt == 'a' || opt == 'n')
				printf("%s ", name.nodename);

			if (opt == 'a' || opt == 'r')
				printf("%s ", name.release);

			if (opt == 'a' || opt == 'v')
				printf("%s ", name.version);

			if (opt == 'a' || opt == 'm')
				printf("%s ", name.machine);
	
			if (opt == 'a'){
				printf("\n");
				return 0;
			}
		}
		printf("\n");
		return 0;
	} else
		perror(argv[0]);

	return -1;
}
