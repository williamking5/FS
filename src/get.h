int getfile(char username[],char lockname[]){
	char cmd[200],total=0;
	sprintf(cmd,"mkdir %s 2>tmp.tmp",lockname);
	system(cmd);

	sprintf(cmd,"./qshell listbucket %s download.txt >tmp.tmp",BUCKET);
	system(cmd);
	char filename[200],tmp[200];
	FILE *fp=fopen("download.txt","r");
	FILE *fw=fopen("download.list","w");
	while (fscanf(fp,"%s%s%s%s%s",filename,tmp,tmp,tmp,tmp)==5){
		if (strstr(filename,username)!=NULL) {
			if (strstr(filename,username)-filename==0&&strstr(filename,lockname)-filename+strlen(lockname)==strlen(filename)) {
				fprintf(fw,"%s\n",filename);
			}
		}
	}
	fclose(fp);
	fclose(fw);
	system("rm download.txt");

	Download(username,lockname);
	fp=fopen("download.list","r");
	while (fscanf(fp,"%s",filename)==1){
		sprintf(cmd,"mv .tmp/%s %s/%s",filename,lockname,filename);
		total++;
		system(cmd);
		printf("%d %s is downloaded\n",total,filename);
	}
	fclose(fp);

	fp=fopen("download.list","r");
	chdir(lockname);
	while (fscanf(fp,"%s",filename)==1){
		char tmp[200],*po;
		po=tmp;
		strcpy(tmp,filename);
		int k=strstr(po,"-")-po;
		po+=k+1;
		k=strstr(po,"-")-po;
		po+=k+1;
		k=strstr(po,"-")-po;
		po[k]=0;
		sprintf(cmd,"mv %s %s",filename,po);
		system(cmd);
		sprintf(cmd,"./qshell delete %s %s",BUCKET,filename);

		chdir("..");
		system(cmd);
		chdir(lockname);
	}
	fclose(fp);
	chdir("..");
	return total;
}
