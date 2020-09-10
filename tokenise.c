#include "./headers.h" 


int tokenise(char *inp,char tokens[100][1024],char *delim)
{
	int x =0;
	char *token = strtok(inp,delim);
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<1024;j++)
			tokens[i][j] = '\0';
	}
	while(1)
	{
		if(token==NULL)
			break;
		else
		{
			strcpy(tokens[x],token);
			token = strtok(NULL,delim);

		}
		x++;
	}
	return x;

}

