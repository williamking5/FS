int sign(){
	printf("Please input a username: ");
	char username[30],password[30];
	scanf("%s",username);
	printf("Loading...\n");
	Download("",".userconf");
	chdir(".tmp");
	system("mv *.userconf user.conf");
	FILE *fp=fopen("user.conf","r");
	char tmp[100],mt[30];
	while (1){
		int k=fscanf(fp,"%s%s",tmp,mt);
		if (k!=2) break;
		if (!strcmp(tmp,username)){
			printf("Sorry, \"%s\" has been used\n",username);
			system("rm user.conf");
			fclose(fp);
			chdir("..");
			return 0;
		}
	}
	fclose(fp);

	printf("Ok,you can use\"%s\" as your username\n",username);
	printf("Please input your password: ");
	scanf("%s",password);
	fp=fopen("user.conf","a");
	fprintf(fp,"%s %s\n",username,password);
	fclose(fp);

	char cmd[100];
	gettime(mt);

	system("mv user.conf ../user.conf");
	chdir("..");
	sprintf(cmd,"./qshell fput %s %s.userconf user.conf",BUCKET,mt);
	printf("Adding...\n");

	fp=fopen("download.list","r");
	while (1){
		int k=fscanf(fp,"%s",tmp);
		if (k!=1) break;
		if (strstr(tmp,".userconf")==NULL) continue;
		if (strstr(tmp,".userconf")-tmp==strlen(tmp)-9) break;
	}
	fclose(fp);

	system(cmd);

	sprintf(cmd,"./qshell delete %s %s >delete.LOG",BUCKET,tmp);
	system(cmd);
	system("rm user.conf");
	return 1;
}
