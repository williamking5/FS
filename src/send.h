int Send(char lockname[],char username[]){
	char putname[500],filename[500],*pp;
	printf("请输入文件名： ");
	scanf("%s",filename);
	
	pp=putname;
	strcpy(putname,filename);
	if (putname[0]=='\''&&putname[strlen(putname)-1]=='\''){
		putname[strlen(putname)-1]=0;
		pp++;
	}

	FILE *fp=fopen(pp,"r");
	if (fp==NULL) {
		printf("没有找到%s,您要创建该文件吗？  y/n\n",filename);
		char tmp[3];
		scanf("%s",tmp);
		if (!strcmp(tmp,"n")) return 0;

		fp=fopen(pp,"w");
		fclose(fp);
		char cmd[200];
		sprintf(cmd,"gedit %s",pp);
		system(cmd);
	}
	else fclose(fp);

	while (strstr(pp,"/")!=NULL){
		int k=strstr(pp,"/")-pp;
		pp+=k+1;
	}

	char cmd[500],nowtime[20];
	gettime(nowtime);
	sprintf(cmd,"./qshell fput %s %s-%s-%s-%s %s",BUCKET,lockname,nowtime,pp,username,filename);
	system(cmd);
}
