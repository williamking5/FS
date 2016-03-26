int Send(char lockname[],char username[]){
	char filename[100];
	printf("请输入文件名： ");
	scanf("%s",filename);

	FILE *fp=fopen(filename,"r");
	if (fp==NULL) {
		printf("没有找到%s,您要创建该文件吗？  y/n\n",filename);
		char tmp[3];
		scanf("%s",tmp);
		if (!strcmp(tmp,"n")) return 0;

		fp=fopen(filename,"w");
		fclose(fp);
		char cmd[200];
		sprintf(cmd,"gedit %s",filename);
		system(cmd);
	}
	else fclose(fp);

	char cmd[200],nowtime[20];
	gettime(nowtime);
	sprintf(cmd,"./qshell fput %s %s-%s-%s-%s %s",BUCKET,lockname,nowtime,filename,username,filename);
	system(cmd);
}
