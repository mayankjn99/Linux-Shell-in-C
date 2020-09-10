#include "./headers.h"

void trim(char *inp)
{

	int i=0,j=0;

	while(inp[i]==' ' || inp[i]=='\t')
	{
		i++;
	}
		while(i<strlen(inp))
	{
		inp[j] = inp[i];
		j++;i++;
	}
	
	inp[j] = '\0';
	int k = 0;
	i = 0;
	while(i<j)
	{
		if(inp[i]!=' ' && inp[i]!='\t')
		{
			k = i;
		}
		i++;
	}
	inp[k+1]='\0';

}