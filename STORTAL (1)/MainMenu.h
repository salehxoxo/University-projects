#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void mainmenu()
{

    system("cls");
	int i,choice;
	char s[12]=" MAIN MENU ";
	system("cls");
	gotoxy(16,4);
	for(i=0;i<5;i++)
	{
		delay(30);
		printf("\xDB");
	}
	for(i=0;i<10;i++)
	{
		delay(30);
		printf("\xB2");
	}
	for(i=0;i<12;i++)
	{
		delay(30);
		printf("%c",s[i]);
	}
	for(i=0;i<10;i++)
	{
		delay(30);
		printf("\xB2");
	}
	for(i=0;i<5;i++)
	{
		delay(30);
		printf("\xDB");
	}
	gotoxy(16,6);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Cafeteria");
	gotoxy(16,8);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Sports Items");
	gotoxy(16,10);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Gym Equipment");
	gotoxy(16,12);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Find My Class");
	gotoxy(16,14);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Home Page");
	gotoxy(16,16);
	printf("\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB");
	gotoxy(16,18);
	printf("\xDB\xDB\xDB\xDB\xB2 Enter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		
		case 1:
			system("cls");
			Cafeteria();
			break;
			
		case 2:
			system("cls");
			Sports();
			break;
		
		case 3:
			system("cls");
			Gym();
	    	break;
	    
		case 4:
	    		system("cls");
			FindMyClass();
			break;
	    
		case 5:
			system("cls");
			HomePage();
			break;
		
		default:
			mainmenu();
	}
}

