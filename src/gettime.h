void gettime(char t[]){
	struct tm *timeinfo;
	time_t nowtime;
	time(&nowtime);
	timeinfo=localtime(&nowtime);
	int YEAR=timeinfo->tm_year+1900,MONTH=timeinfo->tm_mon+1,DAY=timeinfo->tm_mday,HOUR=timeinfo->tm_hour,MIN=timeinfo->tm_min,SEC=timeinfo->tm_sec;
	sprintf(t,"%d%02d%02d%02d%02d%02d",YEAR,MONTH,DAY,HOUR,MIN,SEC);
}
