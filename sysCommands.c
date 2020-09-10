#include "./headers.h"
int tokenise(char *inp,char tokens[100][1024],char *delim);
void trim(char *inp);
int curi=0;
char commandcnt[100][1024];
long int pidsave[100];

void process_terminated(int sig)
{
	pid_t pid;
	int status;
	pid = waitpid(-1,&status,WNOHANG);
	for(int i=0;i<curi;i++)
	{
		if(pid==pidsave[i])
		{
			printf("\n%s with Pid %d exited normally.\n",commandcnt[i],pid);
		}
	}
	
	return;
}

void syscom(char *command, char* arg)
{

	char *argv[1024];
	char tokens[100][1024];
	int a = tokenise(arg,tokens," ");
	int i=0,status;
	int j= 1;
	int flag = 0;
	for(i=0;i<a;i++)
	{
		if(strcmp("&",tokens[i])==0)
			{	
				flag = 1;
			}
		else
		{argv[j] = tokens[i];
		j++;}
	}
	argv[0] = command;
	argv[j] = NULL;
	if(flag==1)
	{strcpy(commandcnt[curi],command);
	curi ++;}
	pid_t par = getpid();
	signal(SIGCHLD,process_terminated);
	pid_t child_pid= fork();
	pid_t temp = getpid();
	if(flag==1)
		pidsave[curi-1] =child_pid;

	if(child_pid  > 0) {
		if(flag != 0 )
		{
			printf("[%d] %d\n",curi,child_pid);
			
		}		
		else
		{
		pid_t tpid = waitpid(child_pid,&status,0);	
		}
	}
	else {

		if(flag==1)
		{close(0);
			close(1);
			close(2);}
			//setgpid(0,0);}
		execvp(argv[0], argv);

		printf("\033[1;31mUnknown command\033[0m :(\n");
		//curi--;
		exit(0);		
	}
	
	
}