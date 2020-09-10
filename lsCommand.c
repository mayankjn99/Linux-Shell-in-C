#include "./headers.h"
void trim(char *inp);
int cd(char *inp,char *cwd,char *home);


void ls(int flag[26])
{
	char backup[1024];
	struct dirent *dirt;
	struct stat file;
	int f = 0;
	DIR *dir;
	dir = opendir(".");
	long long int size=0;
	while(dirt=readdir(dir))
	{
		struct stat fileStat;
		stat(dirt->d_name,&fileStat);
		if(flag[0]==0)
		{
			if(dirt->d_name[0]!='.')
			size += fileStat.st_blocks;
		}
		else
			size += fileStat.st_blocks;
	}
	 if(flag['l'-'a']==1)
	{
		size = size/2;
		printf("Total : %lld\n",size);

	}
	closedir(dir);
	dir = opendir(".");
	while((dirt = readdir(dir)))
	{
	
			if(flag['l'-'a']!=1)
			{

				if(flag[0]==1)
				{
					printf("%s\t",dirt->d_name);
				}
				else
				{
					if(dirt->d_name[0]!='.')
						printf("%s\t",dirt->d_name);
				}

			}
			else
			{

				if(flag[0]==1)
				{
					struct stat fileStat;
					stat(dirt->d_name,&fileStat);
					struct passwd *pws;
					pws = getpwuid(fileStat.st_uid);
					struct group *grp;
					grp = getgrgid(fileStat.st_gid);
					if(S_ISDIR(fileStat.st_mode))
						printf("d");
					else
						printf("-");
					if((fileStat.st_mode & S_IRUSR))
						printf("r");
					else
						printf("-");
					if((fileStat.st_mode & S_IWUSR))
						printf("w");
					else
						printf("-");
					if((fileStat.st_mode & S_IXUSR))
						printf("x");
					else
						printf("-");
					if((fileStat.st_mode & S_IRGRP))
						printf("r");
					else
						printf("-");
					if((fileStat.st_mode & S_IWGRP))
						printf("w");
					else
						printf("-");
					if((fileStat.st_mode & S_IXGRP))
						printf("x");
					else
						printf("-");
					if((fileStat.st_mode & S_IROTH))
						printf("r");
					else
						printf("-");
					if((fileStat.st_mode & S_IROTH))
						printf("w");
					else
						printf("-");
					if((fileStat.st_mode & S_IROTH))
						printf("x");
					else
						printf("-");
					printf("  %ld", fileStat.st_nlink);
					printf("  %s", pws->pw_name);
					printf("  %s", grp->gr_name);
					printf("  %ld", fileStat.st_size);
					char time[100]; 
					strcpy(time, ctime(&fileStat.st_mtime));
					char temp[100];
					int j = 4;
					int k= 0;
					while(j<16)
					{
						temp[k] = time[j];
						j++;k++;
					}
					temp[13] = '\0';

					printf("  %.12s",temp);
					printf("  %s\n", dirt->d_name);
				}
				else
				{
					if(dirt->d_name[0]!='.')
					{

						struct stat fileStat;

					stat(dirt->d_name,&fileStat);
					struct passwd *pws;
					pws = getpwuid(fileStat.st_uid);
					struct group *grp;
					grp = getgrgid(fileStat.st_gid);
					if(S_ISDIR(fileStat.st_mode))
						printf("d");
					else
						printf("-");
					if((fileStat.st_mode & S_IRUSR))
						printf("r");
					else
						printf("-");
					if((fileStat.st_mode & S_IWUSR))
						printf("w");
					else
						printf("-");
					if((fileStat.st_mode & S_IXUSR))
						printf("x");
					else
						printf("-");
					if((fileStat.st_mode & S_IRGRP))
						printf("r");
					else
						printf("-");
					if((fileStat.st_mode & S_IWGRP))
						printf("w");
					else
						printf("-");
					if((fileStat.st_mode & S_IXGRP))
						printf("x");
					else
						printf("-");
					if((fileStat.st_mode & S_IROTH))
						printf("r");
					else
						printf("-");
					if((fileStat.st_mode & S_IROTH))
						printf("w");
					else
						printf("-");
					if((fileStat.st_mode & S_IROTH))
						printf("x");
					else
						printf("-");					
					printf("  %ld", fileStat.st_nlink);
					printf("  %s", pws->pw_name);
					printf("  %s", grp->gr_name);
					printf("  %ld", fileStat.st_size);
					char time[100]; 
					strcpy(time, ctime(&fileStat.st_mtime));
					char temp[100];
					int j = 4;
					int k= 0;
					while(j<16)
					{
						temp[k] = time[j];
						j++;k++;
					}
					temp[13] = '\0';
					printf("  %.12s",temp);
					printf("  %s\n", dirt->d_name);
					}
				}
			}				
	}
	if(flag[0]==0 && flag['l'-'a']==0)
		printf("\n");
	else if(flag[0]==1 && flag['l'-'a']==0)
		printf("\n");
	//printf("\n");
	
		closedir(dir);

}


void lscall(char *inp,char tokens[100][1024],char *cwd, char *home)
{
	int flag[26]={0};
	char backup[1024];
	getcwd(backup,1024);
	int f= 0;
	int k = 0;

	if(strlen(inp)!=0)
	{
		
		for(int i=0;i<100;i++)
		{
			 if(tokens[i][0]=='-')
			{
				for(int j=0;j<strlen(tokens[i]);j++)
				{
					flag[tokens[i][j]-'a'] = 1;
				}
				
			}

		}
		
	}	
	for(int i=0;i<100;i++)
	{
		if(tokens[i][0]!='-' && tokens[i][0]!='\0')
			{
				//printf("%s :\n",tokens[i]);
				getcwd(backup,1024);
				int k = cd(tokens[i],cwd,home);
				if(k==0)
				{printf("%s :\n",tokens[i]);
					ls(flag);}
				cd(backup,cwd,home);
				f= 1;
				if(k==0)
				printf("\n");
			}
		
	}
	if(f==0)
	{
		ls(flag);
		//printf("\n");
		int k = cd(backup,cwd,home);

	}
	
	cd(backup,cwd,home);

}