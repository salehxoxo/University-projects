#include<stdio.h>
#include<conio.h>
#include<unistd.h>
void Cafeteria()
{
	int i,j;
	char d[20]="WELCOME TO CAFETERIA";
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
	for(i=0;i<20;i++)
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
	char ch;
	char yorn;
	int a,bill,tb=0,o,o1;
	int qty;
	do
	{
		Menu:
		gotoxy(19,5);	
		printf("What would you like to order?");
		gotoxy(19,6);
		printf("\xDB\xDB\xDB\xDB\xB2 Press:");
		gotoxy(19,7);
		printf("\xDB\xDB\xDB\xDB\xB2 T/t for Tea");
		gotoxy(19,8);
		printf("\xDB\xDB\xDB\xDB\xB2 C/c for coffee");
		gotoxy(19,9);
		printf("\xDB\xDB\xDB\xDB\xB2 D/d for Drink");
		gotoxy(19,10);
		printf("\xDB\xDB\xDB\xDB\xB2 B/b for Burgers");
		gotoxy(19,11);
		printf("\xDB\xDB\xDB\xDB\xB2 P/p for Pizza");
		gotoxy(19,12);
		printf("\xDB\xDB\xDB\xDB\xB2 S/s for Shawarma");
		gotoxy(19,13);
		printf("\xDB\xDB\xDB\xDB\xB2 E/e to Exit");
		gotoxy(19,15); 
		printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
		scanf(" %c",&ch);
		if(ch=='B'||ch=='T'||ch=='C'||ch=='D'||ch=='P'||ch=='S'||ch=='E'||ch=='b'||ch=='t'||ch=='c'||ch=='d'||ch=='p'||ch=='s'||ch=='e')
		{
	
		switch(ch)
		{
				case 'T':
				case 't':
					{
						system("cls");
						gotoxy(19,5);
						printf("Which Tea would you like?\n"); 
						tea:
						gotoxy(19,6);
						printf("\xDB\xDB\xDB\xDB\xB2 Press:");
						gotoxy(19,7);
						printf("\xDB\xDB\xDB\xDB\xB2 1. With sugar.");
						gotoxy(19,8);
						printf("\xDB\xDB\xDB\xDB\xB2 2. Sugarfree.");
						gotoxy(19,10);
						printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");					
						scanf("%d",&o);
						system("cls");
						switch(o)
						{
							case 1:
								{
									tea1:
									printf("Which Tea would you like?");
									gotoxy(19,6);	
									gotoxy(19,6);
									printf("\xDB\xDB\xDB\xDB\xB2 Press: ");
									gotoxy(19,7);
									printf("\xDB\xDB\xDB\xDB\xB2 1. Tea bag        40/-");
									gotoxy(19,8);
									printf("\xDB\xDB\xDB\xDB\xB2 2. Doodh patti    40/-");
									gotoxy(19,10);										  
									printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");	
									scanf("%d",&o1);
									system("cls");
									switch(o1)
									{
										case 1:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=40*qty;
												tb=tb+bill;
												system("cls");
												 
												break;
											}
										case 2:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=40*qty;
												tb=tb+bill;
												system("cls");
												break;
												 
											}
										default:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
												gotoxy(19,6);
												printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
												goto tea1;
												break;
											}
										
										}
								break;
								}
								system("cls");
								case 2:
								{
									tea2:
									gotoxy(19,5);
									printf("Which Tea would you like?");
									gotoxy(19,6);
									printf("\xDB\xDB\xDB\xDB\xB2 Press:");
									gotoxy(19,7);
									printf("\xDB\xDB\xDB\xDB\xB2 1. Tea bag     40/-");
									gotoxy(19,8);
									printf("\xDB\xDB\xDB\xDB\xB2 2. Doodh Patti 40/-");
									gotoxy(19,10);
									printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
									scanf("%d",&o1);
									system("cls");
						 			switch(o1)
									{
										case 1:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										case 2:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										default:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
												gotoxy(19,6);
												printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
												goto tea2;
												break;
											}
										}
								break;
								}
							default:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
									goto tea;
									break;
								}
							
						}
					break;
					}
				
					case 'C':
					case 'c':
					{
						system("cls");
						gotoxy(19,5);
						printf("Which Coffee would you like?"); 
						coffee:
						gotoxy(19,6);
						printf("Press:");
						gotoxy(19,7);
						printf("\xDB\xDB\xDB\xDB\xB2 1. With Sugar");
						gotoxy(19,8);
						printf("\xDB\xDB\xDB\xDB\xB2 2. Sugarfree");
						gotoxy(19,10);
						printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
						scanf("%d",&o);
						system("cls");
						switch(o)
						{
							case 1:
								{
									coffee1:
									gotoxy(19,5);
									printf("Which Coffee would you like?");
									gotoxy(19,6);
									printf("Press:");
									gotoxy(19,7);
									printf("\xDB\xDB\xDB\xDB\xB2 1. for Normal Coffee 70/-");
									gotoxy(19,8);
									printf("\xDB\xDB\xDB\xDB\xB2 2. for Black Coffee  80/-");
									gotoxy(19,9);
									printf("\xDB\xDB\xDB\xDB\xB2 3. for Cold Coffee  100/-");
									gotoxy(19,11);
									printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
									scanf("%d",&o1);
									system("cls");
						 			switch(o1)
									{
										case 1:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=70*qty;
												tb=tb+bill;
												 
												break;
											}
										
										case 2:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=80*qty;
												tb=tb+bill;
												 
												break;
											}
										
										case 3:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=100*qty;
												tb=tb+bill;
												 
												break;
											}
										default:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
												goto coffee1;
												break;
											}
										
										}
								break;
								}
								
							case 2:
							{	
								coffee2:
								system("cls");
								gotoxy(19,5);
								printf("Which Coffee would you like?");
								gotoxy(19,6);	
								printf("\xDB\xDB\xDB\xDB\xB2 Press:");
								gotoxy(19,7);
								printf("\xDB\xDB\xDB\xDB\xB2 1. for Normal Coffee 70/-");
								gotoxy(19,8);
								printf("\xDB\xDB\xDB\xDB\xB2 2. for Black Coffee  80/-");
								gotoxy(19,9);
								printf("\xDB\xDB\xDB\xDB\xB2 3. for Cold Coffee  100/-");
								gotoxy(19,11);
								printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
								scanf("%d",&o1);
								system("cls");
					 			 switch(o1)
								{
									case 1:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=70*qty;
											tb=tb+bill;
											 
											break;
										}
									
									case 2:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=80*qty;
											tb=tb+bill;
											 
											break;
										}
									
									case 3:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=100*qty;
											tb=tb+bill;
											 
											break;	
										}
									default:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
											gotoxy(19,6);
											printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
											goto coffee2;
											break;
										}
									
								}
							break;
							}
							default:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
									gotoxy(19,6);
									printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
									goto coffee;
									break;
								}
						
						}
					break;
					}
				
					case 'D':
					case 'd':
					{
						drink:
						system("cls");
						gotoxy(19,5);	
						printf("What size of Cold drink would you like?");
						gotoxy(19,6);
						printf("\xDB\xDB\xDB\xDB\xB2 Press:");
						gotoxy(19,7);
						printf("\xDB\xDB\xDB\xDB\xB2 1. for Regular");
						gotoxy(19,8);
						printf("\xDB\xDB\xDB\xDB\xB2 2. for 500 ml");
						gotoxy(19,10);
						printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: "); 
						scanf("%d",&o);
						system("cls");
						switch(o)
						{
							case 1:
								{
									gotoxy(19,5);
									printf("What Cold Drink would you like?\n");
									drink1:
									gotoxy(19,6);
									printf("\xDB\xDB\xDB\xDB\xB2 Press:");
									gotoxy(19,7);
									printf("\xDB\xDB\xDB\xDB\xB2 1. for Pepsi   40/-");
									gotoxy(19,8);
									printf("\xDB\xDB\xDB\xDB\xB2 2. for Dew		40/");
									gotoxy(19,9);
									printf("\xDB\xDB\xDB\xDB\xB2 3. for 7up     40/-");
									gotoxy(19,10);
									printf("\xDB\xDB\xDB\xDB\xB2 4. for Sting   50/-");
									gotoxy(19,11);
									printf("\xDB\xDB\xDB\xDB\xB2 5. for Pakola  40/-");
									gotoxy(19,12);
									printf("\xDB\xDB\xDB\xDB\xB2 6. for Mirinda 40/-");
									gotoxy(19,14);
									printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
									scanf("%d",&o1);
									system("cls");
									switch(o1)
									{
										case 1:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										case 2:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										case 3:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										case 4:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=50*qty;
												tb=tb+bill;
												 
												break;
											}
										case 5:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										case 6:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										default:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
												gotoxy(19,6);
												printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
												goto drink1;
												break;
											}
										}
								break;
								}
							case 2:
							{
								gotoxy(19,5);
								system("cls");
								printf("What Cold Drink would you like?");
								drink2:
								gotoxy(19,6);
								printf("\xDB\xDB\xDB\xDB\xB2 Press:");
								gotoxy(19,7);
								printf("\xDB\xDB\xDB\xDB\xB2 1. for Pepsi   60/-");
								gotoxy(19,8);
								printf("\xDB\xDB\xDB\xDB\xB2 2. for Mtn Dew 60/-");
								gotoxy(19,9);
								printf("\xDB\xDB\xDB\xDB\xB2 3. for 7up     60/-");
								gotoxy(19,10);
								printf("\xDB\xDB\xDB\xDB\xB2 4. for Sting   70/-");
								gotoxy(19,11);
								printf("\xDB\xDB\xDB\xDB\xB2 5. for Pakola  60/-");
								gotoxy(19,12);
								printf("\xDB\xDB\xDB\xDB\xB2 6. for Mirinda 60/-");
								gotoxy(19,14);
								printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
								scanf("%d",&o1);
								system("cls");
					 			 switch(o1)
								{
									case 1:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=60*qty;
											tb=tb+bill;
											 
											break;
										}
									system("cls");	
									case 2:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=60*qty;
											tb=tb+bill;
											 
											break;
										}
									system("cls");
									case 3:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=60*qty;
											tb=tb+bill;
											 
											break;
										}
									system("cls");
									case 4:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=70*qty;
											tb=tb+bill;
											 
											break;
										}
									system("cls");
									case 5:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=60*qty;
											tb=tb+bill;
											 
											break;
										}
									system("cls");
									case 6:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=60*qty;
											tb=tb+bill;
											 
											break;
										}
									default:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
											goto drink2;
											break;
										}
								}
								break;
							}
							default:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
									goto drink;
									break;
								
								}		
						
						}
					break;
					}
				
				case 'B':
				case 'b':
					{
						system("cls");
						gotoxy(19,5);
						printf("Which Burger would you like?");
						burger:
						gotoxy(19,6);	
						printf("\xDB\xDB\xDB\xDB\xB2 Press:");
						gotoxy(19,7);
						printf("\xDB\xDB\xDB\xDB\xB2 1. for Shami Burger    70/-");
						gotoxy(19,8);
						printf("\xDB\xDB\xDB\xDB\xB2 2. for Chicken Burger 100/-");
						gotoxy(19,9);
						printf("\xDB\xDB\xDB\xDB\xB2 3. for Beef Burger    110/-");
						gotoxy(19,10);
						printf("\xDB\xDB\xDB\xDB\xB2 4. for Zinger Burger  160/-");
						gotoxy(19,12);
						printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
						scanf("%d",&o);
						system("cls");
						switch(o)
						{
							case 1:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
									scanf("%d",&qty);
									bill=70*qty;
									tb=tb+bill;
									 
									break;
								}
							
							case 2:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
									scanf("%d",&qty);
									bill=100*qty;
									tb=tb+bill;
									 
									break;
								}
							
							case 3:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
									scanf("%d",&qty);
									bill=110*qty;
									tb=tb+bill;
									 
									break;
								}
							
							case 4:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
									scanf("%d",&qty);
									bill=160*qty;
									tb=tb+bill;
									 
									break;
								}
							default:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
									gotoxy(19,6);
									printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
									goto burger;
									break;
								
								}
						}
					break;
					}
				case 'S':
				case 's':
					{
						system("cls");
						gotoxy(19,5);
						printf("Which Shawarma would you like?");
						shawrma:
						gotoxy(19,6);
						printf("\xDB\xDB\xDB\xDB\xB2 Press:");
						gotoxy(19,7);
						printf("\xDB\xDB\xDB\xDB\xB2 1. for Chicken Shawarma       80/-");
						gotoxy(19,8);
						printf("\xDB\xDB\xDB\xDB\xB2 2. for Chicken Mayo Shawarma  90/-");
						gotoxy(19,9);
						printf("\xDB\xDB\xDB\xDB\xB2 3. for Zinger Shawarma       110/-");
						gotoxy(19,10);
						printf("\xDB\xDB\xDB\xDB\xB2 4. for Macaroni Shawarma 	  100/-");
						gotoxy(19,12);
						printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
						scanf("%d",&o);
						system("cls");
						switch(o)
						{
							case 1:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
									scanf("%d",&qty);
									bill=80*qty;
									tb=tb+bill;
									 
									break;
								}
							
							case 2:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
									scanf("%d",&qty);
									bill=90*qty;
									tb=tb+bill;
									 
									break;
								}
							case 3:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
									scanf("%d",&qty);
									bill=110*qty;
									tb=tb+bill;
									 
									break;
								}
							case 4:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
									scanf("%d",&qty);
									bill=100*qty;
									tb=tb+bill;
									 
									break;
								}
							default:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
									gotoxy(19,6);
									printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
									goto shawrma;
									break;
								
								}
						}
					break;
					}
				system("cls");
				case 'P':
				case 'p':
					{
						system("cls");
						gotoxy(19,5);
						printf("Which size of Pizza would you like?"); 
						pizza:
						gotoxy(19,6);
						printf("\xDB\xDB\xDB\xDB\xB2 Press:");
						gotoxy(19,7);
						printf("\xDB\xDB\xDB\xDB\xB2 1. for Pan Pizza");	
						gotoxy(19,8);
						printf("\xDB\xDB\xDB\xDB\xB2 2. for Regular Pizza");
						gotoxy(19,9);
						printf("\xDB\xDB\xDB\xDB\xB2 3. for Large Pizza");
						gotoxy(19,11);
						printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
						scanf("%d",&o);
						system("cls");
						switch(o)
						{
							case 1:
								{
									gotoxy(19,5);
									printf("Which flavour would you like?");
									pizza1:
									gotoxy(19,6);
									printf("\xDB\xDB\xDB\xDB\xB2 Press:");
									gotoxy(19,7);
									printf("\xDB\xDB\xDB\xDB\xB2 1. for Chicken Tikka   250/-");
									gotoxy(19,8);
									printf("\xDB\xDB\xDB\xDB\xB2 2. for Chicken Fajita  250/-");
									gotoxy(19,9);
									printf("\xDB\xDB\xDB\xDB\xB2 3. for Chicken Supreme 250/-");
									gotoxy(19,11);
									printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
									scanf("%d",&o1);
									system("cls");
						 			switch(o1)
									{
										case 1:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=250*qty;
												tb=tb+bill;
												 
												break;
											}
										
										case 2:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=250*qty;
												tb=tb+bill;
												 
												break;
											}
										
										case 3:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
												scanf("%d",&qty);
												bill=300*qty;
												tb=tb+bill;
												 
												break;
											}
										default:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
												gotoxy(19,6);
												printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
												goto pizza1;
												break;
								
											}
										}
								break;
								}
							case 2:
							{
								gotoxy(19,5);
								printf("Which flavour would you like?");
								pizza2:
								gotoxy(19,6);
								printf("\xDB\xDB\xDB\xDB\xB2 Press:");
								gotoxy(19,7);
								printf("\xDB\xDB\xDB\xDB\xB2 1. for Chicken Tikka   550/-");
								gotoxy(19,8);
								printf("\xDB\xDB\xDB\xDB\xB2 2. for Chicken Fajita   550/-");
								gotoxy(19,9);
								printf("\xDB\xDB\xDB\xDB\xB2 3. for Chicken Supreme  600");
								gotoxy(19,11);
								printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
								scanf("%d",&o1);
								system("cls");
					 			switch(o1)
								{
									case 1:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=550*qty;
											tb=tb+bill;
											 
											break;
										}
									case 2:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=550*qty;
											tb=tb+bill;
											 
											break;
										}
									case 3:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=600*qty;
											tb=tb+bill;
											 
											break;
										}
									default:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
												gotoxy(19,6);
												printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
												goto pizza2;
												break;
								
											}
									}
								break;
							}
							case 3:
							{
								gotoxy(19,5);
								printf("Which flavour would you like?");
								pizza3:
								gotoxy(19,6);	
								printf("\xDB\xDB\xDB\xDB\xB2 Press:");
								gotoxy(19,7);
								printf("\xDB\xDB\xDB\xDB\xB2 1. for Chicken Tikka   1000/-");
								gotoxy(19,8);
								printf("\xDB\xDB\xDB\xDB\xB2 2. for Fajita          1000/-");
								gotoxy(19,9);
								printf("\xDB\xDB\xDB\xDB\xB2 3. for chicken Supreme 1100/-");
								gotoxy(19,11);
								printf("\xDB\xDB\xDB\xDB\xB2 Enter choice: ");
								scanf("%d",&o1);
								system("cls");
					 			switch(o1)
								{
									case 1:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=1000*qty;
											tb=tb+bill;
											 
											break;
										}
									
									case 2:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity: ");
											scanf("%d",&qty);
											bill=1000*qty;
											tb=tb+bill;
											 
											break;
										}
									case 3:
										{
											gotoxy(19,5);
											printf("\xDB\xDB\xDB\xDB\xB2 Enter Quantity:"); 
											scanf("%d",&qty);
											bill=1100*qty;
											tb=tb+bill;
											 
											break;
										}
									default:
											{
												gotoxy(19,5);
												printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
												gotoxy(19,6);
												printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
												goto pizza3;
												break;
								
											}
								}			
							break;
							}
							default:
								{
									gotoxy(19,5);
									printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
									gotoxy(19,6);
									printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
									goto pizza;
									break;
								
								}
						}
					break;
				}
			}
		}
		else
		{
			gotoxy(19,5);
			printf("\xDB\xDB\xDB\xDB\xB2 Invalid Input! \xB2\xDB\xDB\xDB\xDB");
			gotoxy(19,6);
			printf("\xDB\xDB\xDB\xDB\xB2 Please Order from given menu \xB2\xDB\xDB\xDB\xDB");
			goto Menu;
		}
	
		system("cls");
		gotoxy(19,5);
		printf("\xDB\xDB Your Current Bill is Rs. %d",tb);
		gotoxy(19,7);
		printf("\xDB\xDB Would you like to order again? [Y/N] or [y/n] : ");
		scanf(" %c",&yorn);
		system("cls");
		if(yorn=='Y' || yorn=='y')
		{
			goto Menu;
		}
		else if(yorn=='n' || yorn=='N')
		{
			break;
		}
}
while(ch!='E'&&ch!='e');
	
	system("cls");
	gotoxy(19,5);	
	printf("\xDB\xDB\xDB\xDB\xB2 Your total bill is Rs. %d",tb);
	gotoxy(19,7);
	printf("\xDB\xDB\xDB\xDB\xB2 Thank you for Ordering :) \xB2\xDB\xDB\xDB\xDB");
	sleep(2);
	mainmenu();
}
