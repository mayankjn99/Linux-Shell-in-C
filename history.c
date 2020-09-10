#include "./headers.h"


void history_upd(char *com1,char *arg,char *home,int flag)
{

	char temp[1024];
	int i;
	char comms[21][1024];
	strcpy(temp,home);
	char filehis[]="/history.txt";

	strcat(temp,filehis);
	FILE *file;
	file = fopen(temp,"r");
	int j = 0;
	if(file==NULL)
	{
		printf("Error in opening history.txt\n");
	}
	else
	{
		char com[1024];
		while(fgets(com,1024,file))
		{
			strcpy(comms[j],com);
			j++;
	
		}

	}
	char tempi[1024];
	strcpy(tempi,com1);
	strcat(tempi," ");
	strcat(tempi,arg);
	strcpy(comms[j],tempi);
	int k = strlen(comms[j]);
	comms[j][k] = '\n';
	comms[j][k+1]= '\0';
	j++;
	
	fclose(file);
	file = fopen(temp,"w");
	if(j==20)
	{
		for(i=1;i<j;i++)
		{
			fprintf(file,"%s",comms[i]);
		}
	
	}
	else{
		for(i=0;i<j;i++)
		{
			fprintf(file,"%s",comms[i]);
		}
	}
	fclose(file);
	if(flag==1)
	{
		int n = 10;
		if(arg[0]!='\0')
		{
		n = atoi(arg);
		}
		for(i=j-n;i<j;i++)
		{
			printf("%s",comms[i]);
		}

	}

}