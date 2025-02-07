#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<unistd.h>

const char* Inventory[6] = { "Treadmil", "Benchpress", "Recumbent Bikes", "Squat-Rack", "CablesnPulleys","Hammer-Strength" };
int Quantity[6] = { 2,4,3,4,2,3 };

struct booking_details
{
	char name[20];
	int roll_no;
	const char* status[1];
	int amount;
	char item[20];
};

void Menu(struct booking_details);

void exit_program()
{
	gotoxy(19,7);
	printf("\xDB\xDB\xDB\xDB\xB2 Thank you! \xB2\xDB\xDB\xDB\xDB");
	sleep(2);
	mainmenu();
}

void ItemList(struct booking_details obj)
{
	int i,n=5;
	for (i = 0; i < 6; i++)
	{
		gotoxy(19,n);
		printf("\xDB\xDB\xDB\xDB\xB2 %d. %s", i + 1, Inventory[i]);
		n++;
	}
}

void PostBook(struct booking_details obj, int index)
{
start:
	system("cls");
	struct booking_details temp;
	gotoxy(19,5);
	printf("\xDB\xDB\xDB\xDB\xB2 Availabe Quantity of %s is: %d\n", Inventory[index], Quantity[index]);
	int q;
	gotoxy(19,7);
	printf("\xDB\xDB\xDB\xDB\xB2 Amount of %s you want: ", Inventory[index]);
	scanf("%d", &q);
	if (q > Quantity[index])
	{
		printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input \xB2\xDB\xDB\xDB\xDB");
		gotoxy(19,14);
		printf("Would you like to re-enter amount?");
		gotoxy(19,15);
		printf("1. Yes");
		gotoxy(19,16);
		printf("2. No");
		int y;
		gotoxy(25,16);
		scanf("%d", &y);
		if (y == 1) {
			system("cls");
			goto start;
		}
		else
			exit_program();
	}
	else
	{
		Quantity[index] -= q;
		gotoxy(19,9);
		printf("\xDB\xDB\xDB\xDB\xB2 Your roll no: ");
		scanf("%d", &obj.roll_no);
		fflush(stdin);
		gotoxy(19,11);
		printf("\xDB\xDB\xDB\xDB\xB2 Your name: ");
		scanf("%[^\n]%*c", &obj.name);
		obj.status[0] = "booked";

		// filing;
		int i, flag = -1;
		obj.amount = q;
		for (i = 0; i < 10; i++)	{
			obj.item[i] = Inventory[index][i];
		}
		FILE* fptr;
		fptr = fopen("Gym Bookings.bin", "ab+");
		while(fread(&temp, sizeof(struct booking_details), 1, fptr))
		{
			if(temp.roll_no == obj.roll_no && temp.status[0] == "booked")
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			gotoxy(19,13);
			printf("\xDB\xDB\xDB\xDB\xB2 Cannot write in file, roll number already exist.\xDB\xDB\xDB\xDB\xB2");
		}
		else
		{
			fwrite(&obj, sizeof(struct booking_details), 1, fptr);
			gotoxy(19,13);
			printf("\xDB\xDB\xDB\xDB\xB2 Your booking has been done!\n\n");
		}
		fclose(fptr);
		gotoxy(19,15);
		printf("\xDB\xDB\xDB\xDB\xB2 Press 1 to go to Main Menu and 0 to Exit. \xDB\xDB\xDB\xDB\xB2");
		gotoxy(19,17);
		printf("\xDB\xDB\xDB\xDB\xB2 Enter Choice: ");
		int x;
		scanf("%d", &x);
		if (x == 1)
			Menu(obj);
		else
			exit_program();
	}
}

void ShowFileContent(struct booking_details obj)
{
	FILE* fptr;
	fptr = fopen("Gym Bookings.bin", "rb");
	while (fread(&obj, sizeof(struct booking_details), 1, fptr))
	{
		gotoxy(19,4);
		printf("\xDB\xDB\xDB\xDB\xB2 Name: %s\n", obj.name);
		gotoxy(19,6);
		printf("\xDB\xDB\xDB\xDB\xB2 Roll no: %d\n", obj.roll_no);
		gotoxy(19,8);
		printf("\xDB\xDB\xDB\xDB\xB2 Status: %s\n", obj.status[0]);
		gotoxy(19,10);
		printf("\xDB\xDB\xDB\xDB\xB2 Item: %s\n", obj.item);
		gotoxy(19,12);
		printf("\xDB\xDB\xDB\xDB\xB2 Quantity: %d\n\n", obj.amount);
	}
	fclose(fptr);
}

void ItemBooking(struct booking_details obj)
{

	int a,n=5;
	booking:
	for (a = 0; a < 6; a++)
	{
		gotoxy(19,n);
		printf("\xDB\xDB\xDB\xDB\xB2 %d. %s	%d", a + 1, Inventory[a], Quantity[a]);
		n++;
	}
	gotoxy(19,13);
	printf("\xDB\xDB\xDB\xDB\xB2 Which item would you like to select? ");
	int i;
	scanf("%d", &i);
	switch (i)
	{
		case 1:
		{
			PostBook(obj, i - 1);
			break;
		}
		case 2:
		{
			PostBook(obj, i - 1);
			break;
		}
		case 3:
		{
			PostBook(obj, i - 1);
			break;
		}
		case 4:
		{
			PostBook(obj, i - 1);
			break;
		}
		case 5:
		{
			PostBook(obj, i - 1);
			break;
		}
		case 6:
		{
			PostBook(obj, i - 1);
			break;
		}
		default:
			system("cls");
			printf("Invalid input.");
			goto booking;
	}
}

void Cancellation(struct booking_details obj)
{
	int r_no, i, flag = -1;
	gotoxy(19,6);
	printf("\xDB\xDB\xDB\xDB\xB2 Your roll no: ");
	scanf("%d", &r_no);
	FILE* fptr;
	fptr = fopen("Gym Bookings.bin", "rb+");
	while (fread(&obj, sizeof(struct booking_details), 1, fptr))
	{
		if (obj.roll_no == r_no && obj.status[0] != "Cancelled")
		{
			obj.status[0] = "Cancelled";
			if (obj.item == "Treadmil") 
				Quantity[0] += obj.amount;
			if (obj.item == "Benchpress") 
				Quantity[1] += obj.amount;
			if (obj.item == "Recumbent Bikes") 
				Quantity[2] += obj.amount;
			if (obj.item == "Squat-Rack") 
				Quantity[3] += obj.amount;
			if (obj.item == "CablesnPulleys") 
				Quantity[4] += obj.amount;
			if (obj.item == "Hammer-Strength") 
				Quantity[5] += obj.amount;
			flag = 1;
			fseek(fptr, -sizeof(struct booking_details), SEEK_CUR);
			fwrite(&obj, sizeof(struct booking_details), 1, fptr);
			break;
		}
	}
	if(flag == 1)
		{
			gotoxy(19,8);
			printf("\xDB\xDB\xDB\xDB\xB2 Item Cancelled Successfully! \xDB\xDB\xDB\xDB\xB2\n");
		}
	else{
		gotoxy(19,8);
		printf("\n\xDB\xDB\xDB\xDB\xB2 Roll number not found. \xDB\xDB\xDB\xDB\xB2\n");
	}
	fclose(fptr);
}

void Menu(struct booking_details obj)
{
start:
	system("cls");
	char s[27]=" GYM EQUIPMENT RESERVATION ";
	int i,con;
	gotoxy(19,3);
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
	for(i=0;i<27;i++)
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
	gotoxy(19,5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. List Items");
	gotoxy(19,6);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Book Items");
	gotoxy(19,7);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Cancel Booking");
	gotoxy(19,8);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Show File Contents");
	gotoxy(19,9);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Exit");
	int choice = 0;
	gotoxy(19,11);
	printf("\xDB\xDB\xDB\xDB\xB2 Enter Choice: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		system("cls");
		ItemList(obj);
		break;
	case 2:
		system("cls");
		ItemBooking(obj);
		break;
	case 3:
		system("cls");
		Cancellation(obj);
		break;
	case 4:
		system("cls");
		ShowFileContent(obj);
		break;
	case 5:
		system("cls");
		exit_program();
		break;
	default:
		printf("\nInvalid input");
		goto start;
	}
	again:
	gotoxy(19,14);
	printf("\xDB\xDB\xDB\xDB\xB2 Press 1 to go to Main Menu and 0 to Exit. \xDB\xDB\xDB\xDB\xB2 ");
	gotoxy(19,16);
	printf("\xDB\xDB\xDB\xDB\xB2 Enter Choice: ");
	scanf_s("%d", &con);
	if (con == 1)
	{
		system("cls");
		goto start;
	}
	else if(con == 0)
	{
		ExitProgram();
	}
	else
	gotoxy(19,17);
	printf("\xDB\xDB\xDB\xDB\xB2 Invalid input");
	goto again;
}

int Gym()
{
	struct booking_details obj;
	Menu(obj);
}
