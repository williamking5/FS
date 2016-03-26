int login(char *username){
	char password[30];
	printf("Loading...\n");
	Download("",".userconf");
	chdir(".tmp");
	system("mv *.userconf user.conf");
	FILE *fp=fopen("user.conf","r");
	char tmp[100],mt[30];

	int avail=0;
	while (1){
		int k=fscanf(fp,"%s%s",tmp,mt);
		if (k!=2) break;
		if (!strcmp(tmp,username)){
			avail=1;
			break;
		}
	}
	fclose(fp);
	if (!avail) {
		printf("Not found a username named %s\n",username);
		system("rm user.conf");
		chdir("..");
		return 0;
	}

	printf("Please input your password: ");
	scanf("%s",password);
	if (!strcmp(password,mt)) {
		printf("OK.Welcome,%s\n",username);
	}
	else {
		printf("Password wrong!\n");
		system("rm user.conf");
		chdir("..");
		return 0;
	}

	system("rm user.conf");
	chdir("..");

	return 1;
}
