#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
 
int tell_time(){
	    // variables to store the date and time components
    int hours, minutes, seconds, day, month, year;
 
    // `time_t` is an arithmetic time type
    time_t now;
 
    // Obtain current time
    // `time()` returns the current time of the system as a `time_t` value
    time(&now);
 
    // localtime converts a `time_t` value to calendar time and
    // returns a pointer to a `tm` structure with its members
    // filled with the corresponding values
    struct tm *local = localtime(&now);
 
    hours = local->tm_hour;         // get hours since midnight (0-23)
    minutes = local->tm_min;        // get minutes passed after the hour (0-59)
    seconds = local->tm_sec;        // get seconds passed after a minute (0-59)
 
    day = local->tm_mday;            // get day of month (1 to 31)
    month = local->tm_mon + 1;      // get month of year (0 to 11)
    year = local->tm_year + 1900;   // get year since 1900
 
    // print local time
    if (hours < 12) {    // before midday
        return hours;
    }
    else {    // after midday
        return hours-12;
    }
}


void FindMyClass()
{
	int choice,a,k,j,count=0,count2=0,z=0,t,i,l;
    char day,day_copy,sec,sec_copy,t1[1],c,line[255],dep[10],dep1[10],dep_copy[10];
    char d[15]={" Find My Class "};
    FILE *fptr;
   // animation();
    repeat2:
    system("cls");
    gotoxy(35,4);
	for(l=0;l<5;l++)
	{
		delay(30);
		printf("\xDB");
	}
	for(l=0;l<10;l++)
	{
		delay(30);
		printf("\xB2");
	}
	for(l=0;l<14;l++)
	{
		delay(30);
		printf("%c",d[l]);
	}
	for(l=0;l<10;l++)
	{
		delay(30);
		printf("\xB2");
	}
	for(l=0;l<5;l++)
	{
		delay(30);
		printf("\xDB");
	}
	gotoxy(35,6);
    printf("For which day to search classes for?\nMonday ----> M/m\nTuesday ----> T/t\nWednesday ----> W/w\nThursday ----> H/h\nFriday ----> F/f\nSaturday ----> S/s\n");
	printf("Enter choice: ");
	scanf(" %c",&day);
    while(day != 'M' && day != 'm' && day != 't' && day != 'w' && day != 'h' && day != 'f' && day != 's' && day != 'T' && day != 'W' && day != 'H' && day != 'F' && day != 'S'){
    	printf("Please enter a valid option!\n\n");
    	printf("For which day to search classes for?\nMonday ----> M/m\nTuesday ----> T/t\nWednesday ----> W/w\nThursday ----> H/h\nFriday ----> F\nSaturday ----> S/s\n");
        scanf(" %c",&day);
//        system("cls");
	}
	day = toupper(day);
    day_copy = day;
    if(fptr == NULL){
        printf("Error!");
        exit(1);
    }
    
    printf("\nWhat is your department? (e.g BCS/BAI/BCY/BSE)\n");
    scanf("%s",dep);
    system("cls");
    while(strcmp(dep,"BCS") != 0 && strcmp(dep,"bcs") != 0 && strcmp(dep,"Bcs") != 0 && strcmp(dep,"bai") != 0 && strcmp(dep,"Bai") != 0 && strcmp(dep,"bcy") != 0 && strcmp(dep,"Bcy") != 0 && strcmp(dep,"bse") != 0 && strcmp(dep,"BSE") != 0 && strcmp(dep,"BAI") != 0 && strcmp(dep,"BCY") != 0 && strcmp(dep,"BSE") != 0){
    	printf("Please enter a valid department name!\n\n");
    	printf("What is your department? (e.g BCS/BAI/BCY/BSE)\n");
        scanf("%s",dep);
        system("cls");
	}
	for(a=0;a<3;a++){
		dep[a] = toupper(dep[a]);
	}
    strcpy(dep_copy,dep);
    printf("What is your section? (A/B/C/D/E/F/G/H/J/K/L/M)\n");
    scanf(" %c",&sec);
    system("cls");
    while(sec!='A' && sec!='a' && sec!='b' && sec!='c' && sec!='d' && sec!='e' && sec!='f' && sec!='g' && sec!='h' && sec!='j' && sec!='k' && sec!='l' && sec!='m' && sec!='B' && sec!='C' && sec!='D' && sec!='E' && sec!='F' && sec!='G' && sec!='H' && sec!='J' && sec!='K' && sec!='L' && sec!='M'){
    	printf("Please enter a valid section.\n\n");
    	printf("What is your section? (A/B/C/D/E/F/G/H/J/K/L/M)\n");
        scanf(" %c",&sec);
        system("cls");
	}
	sec = toupper(sec);
    sec_copy = sec;
    repeat1:
    system("cls");
    printf("Choose From The Following: \n1. Find my current and next class\n2. Search a class for a specific time\n");
    scanf("%d",&c);
    system("cls");
    while(c != 1 && c!= 2){
    	printf("Please enter a valid option.\n\n");
    	printf("Choose From The Following: \n1. Find my current and next class\n2. Search a class for a specific time\n");
        scanf("%d",&c);
        system("cls");
	}
	switch(day_copy){
    	case 'M':  
		    fptr=fopen("monday.txt","r");
		    break;
		case 'T':
		    fptr=fopen("tuesday.txt","r");
		    break;
		case 'W':
		    fptr=fopen("wednesday.txt","r");
		    break;
		case 'H':
		    fptr=fopen("thursday.txt","r");
		    break;
		case 'F':
		    fptr=fopen("friday.txt","r");
		    break;
		case 'S':
		    fptr=fopen("saturday.txt","r");
		    break;
	}
    if(c==1){
        t = tell_time();
        if(t==10) t1[0] = 'A';
        else if(t==11) t1[0] = 'B';
        else if(t==12) t1[0] = 'C';
        else sprintf(t1,"%d",t);
        while (fgets(line, sizeof line, fptr) != NULL){
        	j=-1;
    	    for(k=24;k<27;k++){
    	    	dep1[++j]=line[k];
	    	}
            if(line[0]==t1[0] && line[29]==sec_copy && strcmp(dep1,dep_copy)==0){
                printf("\nThe current class is: ");
                for(i=16;i<24;i++){
                    printf("%c",line[i]);
                }
                printf("\nThe room is: ");
                for(i=3;i<12;i++){
                    printf("%c",line[i]);
                }
                count++;
            }    
        }
        if(count==0) printf("\nNo class is going on right now.");
        t = tell_time();
        ++t;
        if(t==10) t1[0] = 'A';
        else if(t==11) t1[0] = 'B';
        else if(t==12) t1[0] = 'C';
        else sprintf(t1,"%d",t);
        z=1;
        printf("\n");

    }else if(c==2){
    	printf("\nEnter time(hours only)\ne.g entering '2' will show the class at 2pm: ");
        scanf("%d",&t);
        system("cls");
    	while(t != 8 && t != 9 && t != 10 && t != 11 && t != 12 && t != 1 && t != 2 && t != 3 ){
    		printf("Please enter a valid input\n\n");
    		printf("\nEnter time(hours only)\ne.g entering '2' will show the class at 2pm: ");
            scanf("%d",&t);
            system("cls");
		}
        if(t==10) t1[0] = 'A';
        else if(t==11) t1[0] = 'B';
        else if(t==12) t1[0] = 'C';
        else sprintf(t1,"%d",t);
    }
    switch(day_copy){
    	case 'M':  
		    fptr=fopen("monday.txt","r");
		    break;
		case 'T':
		    fptr=fopen("tuesday.txt","r");
		    break;
		case 'W':
		    fptr=fopen("wednesday.txt","r");
		    break;
		case 'H':
		    fptr=fopen("thursday.txt","r");
		    break;
		case 'F':
		    fptr=fopen("friday.txt","r");
		    break;
		case 'S':
		    fptr=fopen("saturday.txt","r");
		    break;
	}
    while (fgets(line, sizeof line, fptr) != NULL){
    	j=-1;
    	for(k=24;k<27;k++){
    		dep1[++j]=line[k];
		}
        if(line[0]==t1[0] && line[29]==sec_copy && strcmp(dep1,dep_copy)==0){
        	if(z==1) printf("\nThe class in the next hour will be: ");
            else printf("\nThe class will be: ");
            for(i=16;i<24;i++){
                printf("%c",line[i]);
            }
            printf("\nThe room will be: ");
            for(i=3;i<12;i++){
                printf("%c",line[i]);
            }
            count2++;
        }
    }
    if(count2 ==0 && z==1){
    	printf("\nNo classes found for the next hour");
	}else if(count2 ==0){
		printf("\nNo classes found for the specified time");
	}
	printf("\n\nChoose from the following to continue:\n1. Search for another class for the same section?\n2. Search for another day?\n3. Exit\n");
	scanf("%d",&choice);
	system("cls");
	while(choice != 1 && choice != 2 && choice !=3){
		printf("Please enter a valid option.");
		printf("\n\nChoose from the following to continue:\n1. Search for another class for the same section?\n2. Search for another day?\n3. Exit\n");
	    scanf("%d",&choice);
	    system("cls");
	}
	if(choice == 1) goto repeat1;
	if(choice == 2) goto repeat2;
	if(choice == 3){
		printf("Thank you for using!\n");
		exit(0);
	}

}

