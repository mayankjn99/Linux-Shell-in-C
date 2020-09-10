int tokenise(char *inp,char tokens[100][1024],char *delim);
void trim(char *inp);
int cd(char *inp,char *cwd,char *home);
void ls(int flag[26]);
void lscall(char *inp,char tokens[100][1024],char *cwd, char *home);
void process_terminated(int sig);
void pinfo(char *arg,int flag);
void syscom(char *command,char *arg);
void history_upd(char *com1,char *arg,char *home,int flag);
