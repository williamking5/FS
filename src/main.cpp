#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>

char BUCKET[]="oucjudge";
char DOMAI[]="7xrasr.com1.z0.glb.clouddn.com";
char AK[]="iFYg0UuCbUHK_eSj1SxzjrAH68kVtRoPKyhTcOiv";
char SK[]="ocn7jjNDyYUQjjrJNS49RZi881NA60My8kZRq3f3";

#include "download.h"
#include "gettime.h"
#include "sign.h"
#include "login.h"
#include "send.h"
#include "get.h"
using namespace std;
int main(){
	char order[100],username[100],lockname[100];
	char nowtime[20];
	char cmd[200];
	int lock_status=0;
	sprintf(cmd,"./qshell account %s %s",AK,SK);
	system(cmd);
	system("mkdir .tmp 2>tmp.tmp");
	
	FILE *fp=fopen("login.conf","r");
	if (fp!=NULL){
		fscanf(fp,"%s",username);
		fclose(fp);
		while (1){
			printf("<%s> ",username);
			if (login(username)) break;
		}
	}
	else {
		printf("Input 1 to sign in,input 2 to sign up: ");
		int choose;
		scanf("%d",&choose);
		if (choose==1){
			printf("Please input a username: ");
			scanf("%s",username);
			while (!login(username)){}
			fp=fopen("login.conf","w");
			fprintf(fp,"%s\n",username);
			fclose(fp);
		}
		else if (choose==2){
			while (!sign()){}
			fp=fopen("login.conf","r");
			fscanf(fp,"%s\n",username);
			fclose(fp);
		}
		else {
			printf("Sorry, you are not welcomed.\n");
		}
	}

	int bb=1;
	while (1){
		if (bb) {
			printf("<%s> ->",username);
			if (lock_status) printf("<%s> ",lockname);
		}
		else bb=1;
		fgets(order,100,stdin);
		if (strlen(order)==1) continue;
		else order[strlen(order)-1]=0;
		if (!strcmp(order,"lock")){
			printf("Please input lockname: ");
			scanf("%s",lockname);
			lock_status=1;
			bb=0;
		}
		if (!strcmp(order,"send")){
			if (lock_status){
				Send(lockname,username);
				bb=0;
			}
			else {
				printf("You are not locked!\n");
			}
		}
		if (!strcmp(order,"get")){
			if (lock_status){
				if (getfile(username,lockname)) {
					printf("Download Finished.\n");
				}
				else printf("No file download.\n");
			}
			else {
				printf("You are not locked!\n");
			}
		}
		if (!strcmp(order,"exit")){
			break;
		}
	}
	return 0;
}
