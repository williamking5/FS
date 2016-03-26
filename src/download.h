void MakeConf(char pre[],char suf[]){
	FILE *fp=fopen("download.conf","w");
	fprintf(fp,"{\n");
	fprintf(fp,"\"dest_dir\" : \".tmp/\",\n");
	fprintf(fp,"\"bucket\" : \"%s\",\n",BUCKET);
	fprintf(fp,"\"domain\" : \"http://%s\",\n",DOMAI);
	fprintf(fp,"\"access_key\" : \"%s\",\n",AK);
	fprintf(fp,"\"secret_key\" : \"%s\",\n",SK);
	fprintf(fp,"\"is_private\" : false,\n");
	fprintf(fp,"\"prefix\" : \"%s\",\n",pre);
	fprintf(fp,"\"suffix\" : \"%s\",\n",suf);
	fprintf(fp,"\"referer\" : \"\"\n");
	fprintf(fp,"}\n");
	fclose(fp);
}
void Download(char pre[],char suf[]){
	MakeConf(pre,suf);
	char cmd[200],tmp[200],filename[200];
	sprintf(cmd,"./qshell qdownload 10 download.conf >download.LOG");
	system(cmd);
	system("mv *.list.txt download.list");
	FILE *fp=fopen("download.list","r");
	if (fp==NULL) return;
	FILE *fw=fopen("download.tmp","w");

	while (1){
		int k=fscanf(fp,"%s%s%s%s%s",filename,tmp,tmp,tmp,tmp);
		if (k!=5) break;
		fprintf(fw,"%s\n",filename);
	}
	fclose(fw);
	fclose(fp);

	system("mv download.tmp download.list");
}
