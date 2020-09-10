#include "./headers.h"
void trim(char *inp);



void pinfo(char *arg,int flag)
{

	char temp[] = "/proc/";
	strcat(temp,arg);
	strcat(temp,"/status");
	FILE *fp;
	 fp = fopen(temp,"r");

	if(!fp)
	{
		printf("Invalid PID :) \n");
	}
	else
	{		
			char info[1024];
			char temp[1024];
			int i = 0;
			while(fgets(info,1024,fp)!=NULL)
			{
					if (strncmp("State",info,5) == 0)
					{	

						for(i=6;i<strlen(info);i++)
						{
							temp[i-6] = info[i];
						}
						temp[i-6] = '\0';
						trim(temp);
						//printf("%s\n",temp);	
						printf("Process Status -- %s", temp);
					}
					
					else if (strncmp("Pid",info, 3) == 0)
					{
						for(i=4;i<strlen(info);i++)
						{
							temp[i-4] = info[i];
						}
						temp[i-4] = '\0';
						trim(temp);
						//printf("%s\n",temp);	
						printf("PID -- %s", temp);
					}
					else if (strncmp("VmSize",info,6) == 0)
					{
						for(i=7;i<strlen(info);i++)
						{
							temp[i-7] = info[i];
						}
						temp[i-7] = '\0';
						trim(temp);
						printf("Memory -- %s", temp);
					}
					
			}
	char tempi[] = "/proc/";
	strcat(tempi,arg);
	strcat(tempi,"/exe");
	char out[1024];
	readlink(tempi, out, 1024);
	printf("Executable Path -- %s\n", out);
	fclose(fp);
	}

}