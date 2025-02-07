#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<windows.h>

#define ENTER 13
#define TAB 9
#define BACKSPACE 8
#define SPACE 32

void Login()
{

	login:
	system("cls");
	char username[100],d[8]=" LOGIN ";
	char tuname[100],tpwd[20];
	char ch,pass[20];
	int i=0,flag=0;
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
	for(i=0;i<7;i++)
	{
		delay(30);
		printf("%c",d[i]);
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

	gotoxy(18,6);
	printf("Enter username: ");
	scanf("%s",&username);
	gotoxy(18,7);
	printf("Enter Password: ");
	ch = '\0';
	i = 0;
	while(ch!=13)
	{
		ch=getch();
		if(ch==ENTER)
		{
			pass[i]='\0';
			break;
		}
		else if(ch==BACKSPACE)
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
	    }
	    else if(ch==TAB || ch==SPACE)
	    {
	    	continue;
		}
		else
		{
			pass[i]=ch;
			i++;
			printf("*");
		}
    }
	pass[i] = '\0';
	FILE *reg;
	reg = fopen("Register.txt","r");
	while((fscanf(reg,"%s %s",&tuname,&tpwd))!=EOF)
	{
		if(strcmp(username,tuname)==0 && strcmp(pass,tpwd)==0)
		{
			gotoxy(18,9);
			printf("Login Successful!");
			gotoxy(18,10);
			printf("Press any key to continue.....");
			getch();
		//  MAIN MENU
			mainmenu();
			flag=1;
		}
		
	}
	if(flag!=1)
	{
		gotoxy(18,9);
		printf("\aIncorrect Username or Password!");
		getch();
		system("cls");
		goto login;
	}
	fclose(reg);
	
}
void SignUp(void)
{
	int i,flag;
	char uname[100],tuname[100],pwd[20],tpwd[20],s[10]=" SIGN UP ";
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
	for(i=0;i<9;i++)
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
	signup:
	flag=0;
	gotoxy(18,6);
	printf("Enter username: ");
	scanf("%s",&uname);
	gotoxy(18,7);
	printf("Enter password: ");
	scanf("%s",&pwd);
	FILE *reg;
	reg = fopen("Register.txt","a+");
	while((fscanf(reg,"%s %s",&tuname,&tpwd))!=EOF)
	{
		if(strcmp(uname,tuname)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		gotoxy(18,9);
		printf("Username is already taken. Choose a different username!");
		getch();
		system("cls");
		goto signup;
	}
	else
	{
	fprintf(reg, "%s ",uname);
	fprintf(reg, " %s\n",pwd);
	
	gotoxy(18,9);
	printf("Sign Up Successful!");
	gotoxy(18,10);
	printf("Press any key to continue.");
	getch();
	}
	fclose(reg);
	Login();
}

void HomePage()
{
	int choice;
	char d[25]=" WELCOME TO STORTAL";
	int i=0,j;
	home:
    gotoxy(19,1);
    for(j=0;j<38;j++)
    {
		delay(30);
		printf("\xcd");
	}
	gotoxy(27,2);
	
    for(j=0;j<20;j++)
	{
		delay(30);
		printf("%c",d[j]);
	}
	gotoxy(19,3);
   for(j=0;j<38;j++)
   {
		delay(30);
		printf("\xcd");
   }

	i=0;
	char s[7]={" HOME "};
	gotoxy(20,4);
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
	for(i=0;i<6;i++)
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
	gotoxy(20,6);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Sign Up   ");
	gotoxy(20,8);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Login");
	gotoxy(20,10);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Close App");
	gotoxy(20,11);
	printf("Enter Choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			SignUp();
			break;
		case 2:
			Login();
			break;
		case 3:
			system("cls");
			int i;
			char s[14]={" Team Members "};
			gotoxy(20,4);
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
			for(i=0;i<14;i++)
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
		
			gotoxy(20,6);
			printf("\xDB\xDB\xDB\xDB\xB2 1. Muneeb Khan");
			gotoxy(20,8);
			printf("\xDB\xDB\xDB\xDB\xB2 2. Saleh Shamoon");
			gotoxy(20,10);
			printf("\xDB\xDB\xDB\xDB\xB2 3. Danish Nanjiani");
			gotoxy(20,12);
			printf("\xDB\xDB\xDB\xDB\xB2 4. Zohaib Farooqui");
			gotoxy(20,14);
			printf("\xDB\xDB\xDB\xDB\xB2 5. Ahmed Saif");
			break;
		default:
			printf("Invalid Input.");
		//	goto home;
			break;
}
}

	

	

