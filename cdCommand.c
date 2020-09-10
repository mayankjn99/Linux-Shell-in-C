#include "./headers.h"

int cd (char *inp, char *cwd,char *home)
{

	for(int i=0;i<1024;i++)
		cwd[i] = '\0';
	if(inp[0]!='~')
	{
		int  k =chdir(inp);
		if(k<0)
		{
			printf("\033[1;31mNo such Directory \033[0m:(\n");
			getcwd(cwd,1024);
			return 1;

		}

		getcwd(cwd,1024);
	}
	else
	{
		char temp[1024];
		strcpy(temp,inp);
		memmove(temp, temp+1, sizeof(temp));
		strcpy(cwd,home);
		strcat(cwd,temp);
		int k = chdir(cwd);
		if(k==-1)
		{
			printf("No such Directory :(\n");
			return 1;
		}
	}
	return 0;

}