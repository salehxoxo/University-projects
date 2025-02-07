#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include<sstream>
#include <bits/stdc++.h>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#define ENTER 13
#define TAB 9
#define BACKSPACE 8
#define SPACE 32

using namespace std;
class Register //CLASS REGISTER----------------------------
{
	public:
	int Login()
	{
		login:
		system("cls");
		string username,pass;
		char ch;
		int i=0,flag=0;
		
		cout << "LOGIN" << endl;
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		ch = '\0';
		i = 0;
		while(ch!=13)
		{
			ch=getch();
			if(ch==ENTER)
			{
				//pass[i]='\0';
				break;
			}
			else if(ch==BACKSPACE)
			{
				if(i>0)
				{
					pass.pop_back();
					i--;
					cout << "\b \b";
				}
		    }
		    else if(ch==TAB || ch==SPACE)
		    {
		    	continue;
			}
			else
			{
				pass += ch;
				i++;
				cout << "*";
			}
	    }
		ifstream reg;
		reg.open("Register.txt",ios::in);
		if(reg.is_open())
		{
			string tuname,tpwd;
			while(reg >> tuname >> tpwd)
			{
				if(username == tuname && pass == tpwd)
				{
					cout << "\nLogin Successful!" <<endl;
					cout << "Press any key to continue..... ";
					getch();
					flag=1;
					return flag;
				}else if(username == "admin" && pass == "admin123"){
					cout << "\nLogin for admin Successful!" <<endl;
					cout << "Press any key to continue..... ";
					getch();
					flag=2;
					return flag;
				}
			}
			if(flag!=1)
			{
				
				cout << "\a\nIncorrect Username or Password!" ;
				getch();
				system("cls");
				goto login;
			}
			reg.close();
		}
								
	}
			
	
	void SignUp(void)
	{
		int i,flag;
		string uname,tuname,pwd,tpwd;
		system("cls");
		signup:
		flag=0;
		cout << " SIGN UP " <<endl;
		cout << "Enter username: ";
		cin >> uname;
		cout << "Enter password: ";
		cin >> pwd;
		
		ifstream reg;
		reg.open("Register.txt", ios::in);
		if(reg.is_open())
		{
			while(!reg.eof())
			{
				reg >> tuname;
				if(uname == tuname)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				cout << "Username is already taken. Choose a different username!";
				getch();
				system("cls");
				goto signup;
			}
			else
			{
				ofstream file;
				file.open("Register.txt", ios::app);
				if(file.is_open())
				{
					file << uname << " " << pwd <<endl;
				}
			}
		}
		else
		{
			ofstream file;
			file.open("Register.txt", ios::app);
			if(file.is_open())
			{
				file << uname << " " << pwd <<endl;
			}
		}
		cout << endl<< "Sign Up Successful!" <<endl;
		cout << "Press any key to continue.";
		getch();
		reg.close();
		Login();
	}
};

class cafe{  //CLASS CAFE---------------------------------
protected:
	int tb=0;
public:
	
	display(){
		Menu:
		//gotoxy(19,5);	
		cout << "WELCOME TO CARPE DIEM CAFE" <<endl;
		cout <<"\nWhat would you like to order?";
		//gotoxy(19,6);
		cout <<"\nPress:";
		//gotoxy(19,7);
		cout <<"\nT/t for Tea";
		//gotoxy(19,8);
		cout <<"\nC/c for coffee";
		//gotoxy(19,9);
		cout <<"\nD/d for Drink";
		//gotoxy(19,10);
		cout <<"\nB/b for Burgers";
		//gotoxy(19,11);
		cout <<"\nP/p for Pizza";
		//gotoxy(19,12);
		cout <<"\nS/s for Shawarma";
		//gotoxy(19,13);
		cout <<"\nE/e to Exit";
		//gotoxy(19,15); 
		cout <<"\nEnter choice: ";
    }
    
    virtual placeOrder() = 0;
    virtual receipt()=0;
};

class order: public cafe{ //CLASS ORDER -------------------------------------------
protected:
	char ch;
	char yorn;
	int a,bill,o,o1;
	int qty;
public:
	placeOrder(){
		Menu:
		display();
		cin >> ch;
		if(ch=='B'||ch=='T'||ch=='C'||ch=='D'||ch=='P'||ch=='S'||ch=='E'||ch=='b'||ch=='t'||ch=='c'||ch=='d'||ch=='p'||ch=='s'||ch=='e')
		{
	
		switch(ch)
		{
				case 'T':
				case 't':
					{
						system("cls");
						//gotoxy(19,5);
						cout <<"Which Tea would you like?\n"; 
						tea:
						//gotoxy(19,6);
						cout <<"\nPress:";
						//gotoxy(19,7);
						cout <<"\n1. With sugar.";
						//gotoxy(19,8);
						cout <<"\n2. Sugarfree.";
						//gotoxy(19,10);
						cout <<"\nEnter choice: ";					
						cin>>o;
						system("cls");
						switch(o)
						{
							case 1:
								{
									tea1:
									cout <<"Which Tea would you like?";
									//gotoxy(19,6);	
									//gotoxy(19,6);
									cout <<"\nPress: ";
									//gotoxy(19,7);
									cout <<"\n1. Tea bag        40/-";
									//gotoxy(19,8);
									cout <<"\n2. Doodh patti    40/-";
									//gotoxy(19,10);										  
									cout <<"\nEnter choice: ";	
									cin>>o1;
									system("cls");
									switch(o1)
									{
										case 1:
											{
												//gotoxy(19,5);
												cout <<"Enter Quantity: ";
												cin>>qty;
												bill=40*qty;
												tb=tb+bill;
												system("cls");
												 
												break;
											}
										case 2:
											{
												//gotoxy(19,5);
												cout <<"Enter Quantity: ";
												cin>>qty;
												bill=40*qty;
												tb=tb+bill;
												system("cls");
												break;
												 
											}
										default:
											{
												//gotoxy(19,5);
												cout <<"Invalid Input! ";
												//gotoxy(19,6);
												cout <<"\nPlease Order from given menu ";
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
									//gotoxy(19,5);
									cout <<"Which Tea would you like?";
									//gotoxy(19,6);
									cout <<"\nPress:";
									//gotoxy(19,7);
									cout <<"\n1. Tea bag     40/-";
									//gotoxy(19,8);
									cout <<"\n2. Doodh Patti 40/-";
									//gotoxy(19,10);
									cout <<"\nEnter choice: ";
									cin>>o1;
									system("cls");
						 			switch(o1)
									{
										case 1:
											{
												//gotoxy(19,5);
												cout <<"Enter Quantity: ";
												cin>>qty;
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										case 2:
											{
												//gotoxy(19,5);
												cout <<"Enter Quantity: ";
												cin>>qty;
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										default:
											{
												//gotoxy(19,5);
												cout <<"Invalid Input! ";
												//gotoxy(19,6);
												cout <<"\nPlease Order from given menu ";
												goto tea2;
												break;
											}
										}
								break;
								}
							default:
								{
									//gotoxy(19,5);
									cout <<"Invalid Input! ";
									//gotoxy(19,5);
									cout <<"\nPlease Order from given menu ";
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
						//gotoxy(19,5);
						cout <<"Which Coffee would you like?"; 
						coffee:
						//gotoxy(19,6);
						cout <<"\nPress:";
						//gotoxy(19,7);
						cout <<"\n1. With Sugar";
						//gotoxy(19,8);
						cout <<"\n2. Sugarfree";
						//gotoxy(19,10);
						cout <<"\nEnter choice: ";
						cin>>o;
						system("cls");
						switch(o)
						{
							case 1:
								{
									coffee1:
									//gotoxy(19,5);
									cout <<"Which Coffee would you like?";
									//gotoxy(19,6);
									cout <<"\nPress:";
									//gotoxy(19,7);
									cout <<"\n1. for Normal Coffee 70/-";
									//gotoxy(19,8);
									cout <<"\n2. for Black Coffee  80/-";
									//gotoxy(19,9);
									cout <<"\n3. for Cold Coffee  100/-";
									//gotoxy(19,11);
									cout <<"\nEnter choice: ";
									cin>>o1;
									system("cls");
						 			switch(o1)
									{
										case 1:
											{
												//gotoxy(19,5);
												cout <<"Enter Quantity: ";
												cin>>qty;
												bill=70*qty;
												tb=tb+bill;
												 
												break;
											}
										
										case 2:
											{
												//gotoxy(19,5);
												cout <<"Enter Quantity: ";
												cin>>qty;
												bill=80*qty;
												tb=tb+bill;
												 
												break;
											}
										
										case 3:
											{
												//gotoxy(19,5);
												cout <<"Enter Quantity: ";
												cin>>qty;
												bill=100*qty;
												tb=tb+bill;
												 
												break;
											}
										default:
											{
												//gotoxy(19,5);
												cout <<"Invalid Input! ";
												//gotoxy(19,5);
												cout <<"\nPlease Order from given menu ";
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
								//gotoxy(19,5);
								cout <<"Which Coffee would you like?";
								//gotoxy(19,6);	
								cout <<"\nPress:";
								//gotoxy(19,7);
								cout <<"\n1. for Normal Coffee 70/-";
								//gotoxy(19,8);
								cout <<"\n2. for Black Coffee  80/-";
								//gotoxy(19,9);
								cout <<"\n3. for Cold Coffee  100/-";
								//gotoxy(19,11);
								cout <<"\nEnter choice: ";
								cin>>o1;
								system("cls");
					 			 switch(o1)
								{
									case 1:
										{
											//gotoxy(19,5);
											cout <<"Enter Quantity: ";
											cin>>qty;
											bill=70*qty;
											tb=tb+bill;
											 
											break;
										}
									
									case 2:
										{
											//gotoxy(19,5);
											cout <<"Enter Quantity: ";
											cin>>qty;
											bill=80*qty;
											tb=tb+bill;
											 
											break;
										}
									
									case 3:
										{
											//gotoxy(19,5);
											cout <<"Enter Quantity: ";
											cin>>qty;
											bill=100*qty;
											tb=tb+bill;
											 
											break;	
										}
									default:
										{
											//gotoxy(19,5);
											cout <<"Invalid Input! ";
											//gotoxy(19,6);
											cout <<"\nPlease Order from given menu ";
											goto coffee2;
											break;
										}
									
								}
							break;
							}
							default:
								{
									//gotoxy(19,5);
									cout <<"Invalid Input! ";
									//gotoxy(19,6);
									cout <<"\nPlease Order from given menu ";
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
						//gotoxy(19,5);	
						cout <<"What size of Cold drink would you like?";
						//gotoxy(19,6);
						cout <<"\nPress:";
						//gotoxy(19,7);
						cout <<"\n1. for Regular";
						//gotoxy(19,8);
						cout <<"\n2. for 500 ml";
						//gotoxy(19,10);
						cout <<"\nEnter choice: "; 
						cin>>o;
						system("cls");
						switch(o)
						{
							case 1:
								{
									//gotoxy(19,5);
									cout <<"What Cold Drink would you like?\n";
									drink1:
									//gotoxy(19,6);
									cout <<"\nPress:";
									//gotoxy(19,7);
									cout <<"\n1. for Pepsi   40/-";
									//gotoxy(19,8);
									cout <<"\n2. for Dew		40/";
									//gotoxy(19,9);
									cout <<"\n3. for 7up     40/-";
									//gotoxy(19,10);
									cout <<"\n4. for Sting   50/-";
									//gotoxy(19,11);
									cout <<"\n5. for Pakola  40/-";
									//gotoxy(19,12);
									cout <<"\n6. for Mirinda 40/-";
									//gotoxy(19,14);
									cout <<"\nEnter choice: ";
									cin>>o1;
									system("cls");
									switch(o1)
									{
										case 1:
											{
												//gotoxy(19,5);
												cout <<("\nEnter Quantity: ");
												cin>>qty;
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										case 2:
											{
												//gotoxy(19,5);
												cout <<("Enter Quantity: ");
												cin>>qty;
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										case 3:
											{
												//gotoxy(19,5);
												cout <<("Enter Quantity: ");
												cin>>qty;
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										case 4:
											{
												//gotoxy(19,5);
												cout <<("Enter Quantity: ");
												cin>>qty;
												bill=50*qty;
												tb=tb+bill;
												 
												break;
											}
										case 5:
											{
												//gotoxy(19,5);
												cout <<("Enter Quantity: ");
												cin>>qty;
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										case 6:
											{
												//gotoxy(19,5);
												cout <<("Enter Quantity: ");
												cin>>qty;
												bill=40*qty;
												tb=tb+bill;
												 
												break;
											}
										default:
											{
												//gotoxy(19,5);
												cout <<("Invalid Input! ");
												//gotoxy(19,6);
												cout <<("\nPlease Order from given menu ");
												goto drink1;
												break;
											}
										}
								break;
								}
							case 2:
							{
								//gotoxy(19,5);
								system("cls");
								cout <<("What Cold Drink would you like?");
								drink2:
								//gotoxy(19,6);
								cout <<("\nPress:");
								//gotoxy(19,7);
								cout <<("\n1. for Pepsi   60/-");
								//gotoxy(19,8);
								cout <<("\n2. for Mtn Dew 60/-");
								//gotoxy(19,9);
								cout <<("\n3. for 7up     60/-");
								//gotoxy(19,10);
								cout <<("\n4. for Sting   70/-");
								//gotoxy(19,11);
								cout <<("\n5. for Pakola  60/-");
								//gotoxy(19,12);
								cout <<("\n6. for Mirinda 60/-");
								//gotoxy(19,14);
								cout <<("\nEnter choice: ");
								cin>>o1;
								system("cls");
					 			 switch(o1)
								{
									case 1:
										{
											//gotoxy(19,5);
											cout <<("Enter Quantity: ");
											cin>>qty;
											bill=60*qty;
											tb=tb+bill;
											 
											break;
										}
									system("cls");	
									case 2:
										{
											//gotoxy(19,5);
											cout <<("Enter Quantity: ");
											cin>>qty;
											bill=60*qty;
											tb=tb+bill;
											 
											break;
										}
									system("cls");
									case 3:
										{
											//gotoxy(19,5);
											cout <<("Enter Quantity: ");
											cin>>qty;
											bill=60*qty;
											tb=tb+bill;
											 
											break;
										}
									system("cls");
									case 4:
										{
											//gotoxy(19,5);
											cout <<("Enter Quantity: ");
											cin>>qty;
											bill=70*qty;
											tb=tb+bill;
											 
											break;
										}
									system("cls");
									case 5:
										{
											//gotoxy(19,5);
											cout <<("Enter Quantity: ");
											cin>>qty;
											bill=60*qty;
											tb=tb+bill;
											 
											break;
										}
									system("cls");
									case 6:
										{
											//gotoxy(19,5);
											cout <<("Enter Quantity: ");
											cin>>qty;
											bill=60*qty;
											tb=tb+bill;
											 
											break;
										}
									default:
										{
											//gotoxy(19,5);
											cout <<("Invalid Input! ");
											//gotoxy(19,5);
											cout <<("\nPlease Order from given menu ");
											goto drink2;
											break;
										}
								}
								break;
							}
							default:
								{
									//gotoxy(19,5);
									cout <<("Invalid Input! ");
									//gotoxy(19,5);
									cout <<("\nPlease Order from given menu ");
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
						//gotoxy(19,5);
						cout <<("Which Burger would you like?");
						burger:
						//gotoxy(19,6);	
						cout <<("\nPress:");
						//gotoxy(19,7);
						cout <<("\n1. for Shami Burger    70/-");
						//gotoxy(19,8);
						cout <<("\n2. for Chicken Burger 100/-");
						//gotoxy(19,9);
						cout <<("\n3. for Beef Burger    110/-");
						//gotoxy(19,10);
						cout <<("\n4. for Zinger Burger  160/-");
						//gotoxy(19,12);
						cout <<("\nEnter choice: ");
						cin>>o;
						system("cls");
						switch(o)
						{
							case 1:
								{
									//gotoxy(19,5);
									cout <<("Enter Quantity: ");
									cin>>qty;
									bill=70*qty;
									tb=tb+bill;
									 
									break;
								}
							
							case 2:
								{
									//gotoxy(19,5);
									cout <<("Enter Quantity: ");
									cin>>qty;
									bill=100*qty;
									tb=tb+bill;
									 
									break;
								}
							
							case 3:
								{
									//gotoxy(19,5);
									cout <<("Enter Quantity: ");
									cin>>qty;
									bill=110*qty;
									tb=tb+bill;
									 
									break;
								}
							
							case 4:
								{
									//gotoxy(19,5);
									cout <<("Enter Quantity: ");
									cin>>qty;
									bill=160*qty;
									tb=tb+bill;
									 
									break;
								}
							default:
								{
									//gotoxy(19,5);
									cout <<("Invalid Input! ");
									//gotoxy(19,6);
									cout <<("\nPlease Order from given menu ");
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
						//gotoxy(19,5);
						cout <<("Which Shawarma would you like?");
						shawrma:
						//gotoxy(19,6);
						cout <<("\nPress:");
						//gotoxy(19,7);
						cout <<("\n1. for Chicken Shawarma       80/-");
						//gotoxy(19,8);
						cout <<("\n2. for Chicken Mayo Shawarma  90/-");
						//gotoxy(19,9);
						cout <<("\n3. for Zinger Shawarma       110/-");
						//gotoxy(19,10);
						cout <<("\n4. for Macaroni Shawarma 	  100/-");
						//gotoxy(19,12);
						cout <<("\nEnter choice: ");
						cin>>o;
						system("cls");
						switch(o)
						{
							case 1:
								{
									//gotoxy(19,5);
									cout <<("Enter Quantity: ");
									cin>>qty;
									bill=80*qty;
									tb=tb+bill;
									 
									break;
								}
							
							case 2:
								{
									//gotoxy(19,5);
									cout <<("Enter Quantity: ");
									cin>>qty;
									bill=90*qty;
									tb=tb+bill;
									 
									break;
								}
							case 3:
								{
									//gotoxy(19,5);
									cout <<("Enter Quantity: ");
									cin>>qty;
									bill=110*qty;
									tb=tb+bill;
									 
									break;
								}
							case 4:
								{
									//gotoxy(19,5);
									cout <<("Enter Quantity: ");
									cin>>qty;
									bill=100*qty;
									tb=tb+bill;
									 
									break;
								}
							default:
								{
									//gotoxy(19,5);
									cout <<("Invalid Input! ");
									//gotoxy(19,6);
									cout <<("\nPlease Order from given menu ");
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
						//gotoxy(19,5);
						cout <<("Which size of Pizza would you like?"); 
						pizza:
						//gotoxy(19,6);
						cout <<("\nPress:");
						//gotoxy(19,7);
						cout <<("\n1. for Pan Pizza");	
						//gotoxy(19,8);
						cout <<("\n2. for Regular Pizza");
						//gotoxy(19,9);
						cout <<("\n3. for Large Pizza");
						//gotoxy(19,11);
						cout <<("\nEnter choice: ");
						cin>>o;
						system("cls");
						switch(o)
						{
							case 1:
								{
									//gotoxy(19,5);
									cout <<("Which flavour would you like?");
									pizza1:
									//gotoxy(19,6);
									cout <<("\nPress:");
									//gotoxy(19,7);
									cout <<("\n1. for Chicken Tikka   250/-");
									//gotoxy(19,8);
									cout <<("\n2. for Chicken Fajita  250/-");
									//gotoxy(19,9);
									cout <<("\n3. for Chicken Supreme 250/-");
									//gotoxy(19,11);
									cout <<("\nEnter choice: ");
									cin>>o1;
									system("cls");
						 			switch(o1)
									{
										case 1:
											{
												//gotoxy(19,5);
												cout <<("Enter Quantity: ");
												cin>>qty;
												bill=250*qty;
												tb=tb+bill;
												 
												break;
											}
										
										case 2:
											{
												//gotoxy(19,5);
												cout <<("Enter Quantity: ");
												cin>>qty;
												bill=250*qty;
												tb=tb+bill;
												 
												break;
											}
										
										case 3:
											{
												//gotoxy(19,5);
												cout <<("Enter Quantity: ");
												cin>>qty;
												bill=300*qty;
												tb=tb+bill;
												 
												break;
											}
										default:
											{
												//gotoxy(19,5);
												cout <<("Invalid Input! ");
												//gotoxy(19,6);
												cout <<("\nPlease Order from given menu ");
												goto pizza1;
												break;
								
											}
										}
								break;
								}
							case 2:
							{
								//gotoxy(19,5);
								cout <<("Which flavour would you like?");
								pizza2:
								//gotoxy(19,6);
								cout <<("\nPress:");
								//gotoxy(19,7);
								cout <<("\n1. for Chicken Tikka   550/-");
								//gotoxy(19,8);
								cout <<("\n2. for Chicken Fajita   550/-");
								//gotoxy(19,9);
								cout <<("\n3. for Chicken Supreme  600");
								//gotoxy(19,11);
								cout <<("\nEnter choice: ");
								cin>>o1;
								system("cls");
					 			switch(o1)
								{
									case 1:
										{
											//gotoxy(19,5);
											cout <<("Enter Quantity: ");
											cin>>qty;
											bill=550*qty;
											tb=tb+bill;
											 
											break;
										}
									case 2:
										{
											//gotoxy(19,5);
											cout <<("Enter Quantity: ");
											cin>>qty;
											bill=550*qty;
											tb=tb+bill;
											 
											break;
										}
									case 3:
										{
											//gotoxy(19,5);
											cout <<("Enter Quantity: ");
											cin>>qty;
											bill=600*qty;
											tb=tb+bill;
											 
											break;
										}
									default:
											{
												//gotoxy(19,5);
												cout <<("Invalid Input! ");
												//gotoxy(19,6);
												cout <<("\nPlease Order from given menu ");
												goto pizza2;
												break;
								
											}
									}
								break;
							}
							case 3:
							{
								//gotoxy(19,5);
								cout <<("Which flavour would you like?");
								pizza3:
								//gotoxy(19,6);	
								cout <<("\nPress:");
								//gotoxy(19,7);
								cout <<("\n1. for Chicken Tikka   1000/-");
								//gotoxy(19,8);
								cout <<("\n2. for Fajita          1000/-");
								//gotoxy(19,9);
								cout <<("\n3. for chicken Supreme 1100/-");
								//gotoxy(19,11);
								cout <<("\nEnter choice: ");
								cin>>o1;
								system("cls");
					 			switch(o1)
								{
									case 1:
										{
											//gotoxy(19,5);
											cout <<("Enter Quantity: ");
											cin>>qty;
											bill=1000*qty;
											tb=tb+bill;
											 
											break;
										}
									
									case 2:
										{
											//gotoxy(19,5);
											cout <<("Enter Quantity: ");
											cin>>qty;
											bill=1000*qty;
											tb=tb+bill;
											 
											break;
										}
									case 3:
										{
											//gotoxy(19,5);
											cout <<("Enter Quantity:"); 
											cin>>qty;
											bill=1100*qty;
											tb=tb+bill;
											 
											break;
										}
									default:
											{
												//gotoxy(19,5);
												cout <<("Invalid Input! ");
												//gotoxy(19,6);
												cout <<("\nPlease Order from given menu ");
												goto pizza3;
												break;
								
											}
								}			
							break;
							}
							default:
								{
									//gotoxy(19,5);
									cout <<("Invalid Input! ");
									//gotoxy(19,6);
									cout <<("\nPlease Order from given menu ");
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
			//gotoxy(19,5);
			cout << "Invalid Input! ";
			//gotoxy(19,6);
			cout << "\nPlease Order from given menu ";
			goto Menu;
		}
		system("cls");
		//gotoxy(19,5);
		cout << "\nYour Current Bill is Rs. " << tb;
		//gotoxy(19,7);
		cout <<("\nWould you like to order again? [Y/N] or [y/n] : ");
		cin>>yorn;
		system("cls");
		if(yorn=='Y' || yorn=='y')
		{
			goto Menu;
		}
		else if(yorn=='n' || yorn=='N')
		{
			receipt();
		}
	}
	receipt(){
		system("cls");
	    //gotoxy(19,5);	
	    cout <<" Your total bill is Rs. " << tb;
	    //gotoxy(19,7);
	    cout <<(" Thank you for Ordering :) ");
	}
};

const string inventory[5] = { "Football", "Bat", "Ball", "Badminton", "Basketball" };
int quantity[5] = { 5,6,10,6,4 };

class Sports //CLASS SPORTS ----------------------------------------------------
{
	public:
	struct Book{
		string name;
		int memb_no;
		string status;
		int amount;
		string item;
	};
	int q;
	
	Book obj;

//	void MainMenu();
	
	void ExitProgram()
	{
		cout << " Thank you! ";
		sleep(1);
	}
	
	void ListItems()
	{
		int i,n=5;
		for (i = 0; i < 5; i++)
		{
			cout <<  i + 1 << " " << inventory[i] << endl;
			n++;
		}
	}
	
	void PostBooking(int index)
	{
	start:
		Book temp;
		system("cls");
		cout << " Availabe Quantity of " << inventory[index] << " is: " << quantity[index] << endl;
		
		cout << " Amount of " << inventory[index] << " you want: "; 
		cin >> q;
		if (q > quantity[index])
		{
			cout << " Invalid Input ";
			cout << "\nWould you like to re-enter amount?" << endl;
			cout << "1. Yes" <<endl;
			cout << "2. No ";
			int y;
			cin >> y;
			if (y == 1)
			{
				system("cls");
				goto start;
			}
			else
				ExitProgram();
		}
		else
		{
			cout << " Your membership no: ";
			cin >> obj.memb_no;
			fflush(stdin);
			cout << " Your name: ";
			cin >> obj.name;
			obj.status = "booked";
	
			// filing;
			int i; 
			obj.amount = q;
			
			obj.item = inventory[index];
			
			ifstream file;
			file.open("Sports Bookings.txt", ios::in);
			if(file.is_open())
			{
				int flag = 0;
				while(!file.eof())
				{
					file >> temp.name >> temp.memb_no >> temp.item >> temp.status >> temp.amount;
					if (temp.memb_no == obj.memb_no && temp.status == "booked")
					{
						flag = 1;
					}
				}
				file.close();
				
				if (flag == 1)
				{
					cout << " Cannot write in file, membership number already exist.";
					cout << "\nWould you like to re-enter amount?" << endl;
					cout << "1. Yes" <<endl;
					cout << "2. No ";
					int y;
					cin >> y;
					if (y == 1)
					{
						system("cls");
						goto start;
					}
					else
						ExitProgram();
				}
				else
				{
					ofstream file;
					file.open("Sports Bookings.txt", ios::app);
					if(file.is_open())
					{
						file << obj.name << " " << obj.memb_no << " " << obj.item << " " << obj.status << " " << obj.amount << endl;
					}
				}
			}
			else
			{
				ofstream file;
				file.open("Sports Bookings.txt", ios::app);
				if(file.is_open())
				{
					file << obj.name << " " << obj.memb_no << " " << obj.item << " " << obj.status << " " << obj.amount << endl;
				}
			}	
			
			
			file.close();
			cout << " Your booking has been done!"<< endl;
			quantity[index] -= q;
			cout << " Press 1 to go to Main Menu and 0 to Exit. "<< endl;
			cout << " Enter Choice: ";
			int x;
			cin >> x;
			if (x == 1)
				Main_Menu();
			else
				ExitProgram();
		}
	}
	
	void BookItems()
	{
		int a;
		booking:
		for (a = 0; a < 5; a++)
		{
			cout << a + 1 << ". "<<inventory[a] << " " << quantity[a] << endl;
		}
		cout << " Which item would you like to select? ";
		int i;
		cin >> i;
		if (i >= 1 && i <= 5)
		{
			PostBooking(i - 1);
		}
		else
		{
			system("cls");
			cout << "Invalid input.";
			goto booking;
		}
	}
	
	void CancelBooking()
	{
		int m_no, i, flag = 0;
		Book tempObj;
		cout << " Your membership no: ";
		cin >> m_no;
		
		ifstream fptr;
		fptr.open("Sports Bookings.txt", ios::in);
		
		ofstream temp;
		temp.open("temp.txt");
		
		if(fptr.is_open())
		{
			while(fptr >> tempObj.name >> tempObj.memb_no >> tempObj.item >> tempObj.status >> tempObj.amount)
			{
				if (tempObj.memb_no == m_no && tempObj.status != "Cancelled")
				{
					if (tempObj.item == "Football") 
					{
						quantity[0] += tempObj.amount;
					}
					else if(tempObj.item == "Bat")
					{
						quantity[1] += tempObj.amount;
					} 
					else if(tempObj.item == "Ball")
					{
						quantity[2] += tempObj.amount;
					} 
					else if(tempObj.item == "Badminton")
					{
						quantity[3] += tempObj.amount;
					} 
					else if(tempObj.item == "Basketball")
					{
						quantity[4] += tempObj.amount;
					} 
					flag = 1;
				}
				else
				{
					temp << tempObj.name << " " << tempObj.memb_no << " " << tempObj.item << " " << tempObj.status << " " << tempObj.amount << endl;
				}
			}
		}
		if(flag == 1)
		{
			cout << " Item Cancelled Successfully! " ;
		}
		else
		{
			cout << " Membership number not found. ";
		}
		temp.close();
		fptr.close();
		
		remove("Sports Bookings.txt");
		rename("temp.txt", "Sports Bookings.txt");
	}
	
	void Main_Menu()
	{
	start:
		system("cls");
		int i,con;

		cout << " SPORTS ITEM RESERVATION " <<endl;
		menu:
		cout << " 1. List Items" <<endl;
		cout << " 2. Book Items" <<endl;
		cout << " 3. Cancel Booking" << endl;
		cout << " 4. Exit" <<endl; 
		int choice;
		cout << " Enter Choice: " <<endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			ListItems();
			break;
		case 2:
			system("cls");
			BookItems();
			break;
		case 3:
			system("cls");
			CancelBooking();
			break;
		case 4:
			system("cls");
			ExitProgram();
			break;
		default:
			cout << "\nInvalid input";
			goto start;
		}
//		again:
//		cout << " Press 1 to go to Main Menu and 0 to Exit. " <<endl;
//		cout << " Enter Choice: ";
//		cin >> con;
//		if (con == 1)
//		{
//			system("cls");
//			goto start;
//		}
//		else if(con == 0)
//		{
//			ExitProgram();
//		}
//		else
//		cout <<endl << " Invalid input";
//		goto again;
	}
};

const string inventori[5] = { "Treadmill", "Pull-Down", "Bench", "Elliptical-Trainer", "Step Mill" };
int quantiti[5] = { 5,6,10,6,4 };

class Gym  //CLASS GYM---------------------------------------------------
{
	public:
	struct Book{
		string name;
		int memb_no;
		string status;
		int amount;
		string item;
	};
	int q;
	
	Book obj;

	void Exitprog()
	{
		cout << " Thank you! ";
		sleep(1);
	}
	
	void List()
	{
		int i,n=5;
		for (i = 0; i < 5; i++)
		{
			cout <<  i + 1 << " " << inventori[i] << endl;
			n++;
		}
	}
	
	void Post(int index)
	{
	start:
		Book temp;
		system("cls");
		cout << " Availabe quantiti of " << inventori[index] << " is: " << quantiti[index] << endl;
		
		cout << " Amount of " << inventori[index] << " you want: "; 
		cin >> q;
		if (q > quantiti[index])
		{
			cout << " Invalid Input ";
			cout << "\nWould you like to re-enter amount?" << endl;
			cout << "1. Yes" <<endl;
			cout << "2. No ";
			int y;
			cin >> y;
			if (y == 1)
			{
				system("cls");
				goto start;
			}
			else
				Exitprog();
		}
		else
		{
			cout << " Your membership no: ";
			cin >> obj.memb_no;
			fflush(stdin);
			cout << " Your name: ";
			cin >> obj.name;
			obj.status = "booked";
	
			// filing;
			int i; 
			obj.amount = q;
			
			obj.item = inventori[index];
			
			ifstream file;
			file.open("Gym Bookings.txt", ios::in);
			if(file.is_open())
			{
				int flag = 0;
				while(!file.eof())
				{
					file >> temp.name >> temp.memb_no >> temp.item >> temp.status >> temp.amount;
					if (temp.memb_no == obj.memb_no && temp.status == "booked")
					{
						flag = 1;
					}
				}
				file.close();
				
				if (flag == 1)
				{
					cout << " Cannot write in file, membership number already exist.";
					cout << "\nWould you like to re-enter amount?" << endl;
					cout << "1. Yes" <<endl;
					cout << "2. No ";
					int y;
					cin >> y;
					if (y == 1)
					{
						system("cls");
						goto start;
					}
					else
						Exitprog();
				}
				else
				{
					ofstream file;
					file.open("Gym Bookings.txt", ios::app);
					if(file.is_open())
					{
						file << obj.name << " " << obj.memb_no << " " << obj.item << " " << obj.status << " " << obj.amount << endl;
					}
				}
			}
			else
			{
				ofstream file;
				file.open("Gym Bookings.txt", ios::app);
				if(file.is_open())
				{
					file << obj.name << " " << obj.memb_no << " " << obj.item << " " << obj.status << " " << obj.amount << endl;
				}
			}	
			
			
			file.close();
			cout << " Your booking has been done!"<< endl;
			quantiti[index] -= q;
			cout << " Press 1 to go to Main Menu and 0 to Exit. "<< endl;
			cout << " Enter Choice: ";
			int x;
			cin >> x;
			if (x == 1)
				Menu();
			else
				Exitprog();
		}
	}
	
	void Booking()
	{
		int a;
		bookin:
		for (a = 0; a < 5; a++)
		{
			cout << a + 1 << ". "<<inventori[a] << " " << quantiti[a] << endl;
		}
		cout << " Which item would you like to select? ";
		int i;
		cin >> i;
		if (i >= 1 && i <= 5)
		{
			Post(i - 1);
		}
		else
		{
			system("cls");
			cout << "Invalid input.";
			goto bookin;
		}
	}
	
	void Cancellation()
	{
		int m_no, i, flag = 0;
		Book tempObj;
		cout << " Your membership no: ";
		cin >> m_no;
		
		ifstream fptr;
		fptr.open("Gym Bookings.txt", ios::in);
		
		ofstream temp;
		temp.open("temp.txt");
		
		if(fptr.is_open())
		{
			while(fptr >> tempObj.name >> tempObj.memb_no >> tempObj.item >> tempObj.status >> tempObj.amount)
			{
				if (tempObj.memb_no == m_no && tempObj.status != "Cancelled")
				{
					if (tempObj.item == "Treadmill") 
					{
						quantiti[0] += tempObj.amount;
					}
					else if(tempObj.item == "Pull-Down")
					{
						quantiti[1] += tempObj.amount;
					} 
					else if(tempObj.item == "Bench")
					{
						quantiti[2] += tempObj.amount;
					} 
					else if(tempObj.item == "Elliptical-Trainer")
					{
						quantiti[3] += tempObj.amount;
					} 
					else if(tempObj.item == "Step Mill")
					{
						quantiti[4] += tempObj.amount;
					} 
					flag = 1;
				}
				else
				{
					temp << tempObj.name << " " << tempObj.memb_no << " " << tempObj.item << " " << tempObj.status << " " << tempObj.amount << endl;
				}
			}
		}
		if(flag == 1)
		{
			cout << " Item Cancelled Successfully! " ;
		}
		else
		{
			cout << " Membership number not found. ";
		}
		temp.close();
		fptr.close();
		
		remove("Gym Bookings.txt");
		rename("temp.txt", "Gym Bookings.txt");
	}
	
	void Menu()
	{
	start:
		system("cls");
		int i,con;

		cout << " GYM ITEM RESERVATION " <<endl;
		menu:
		cout << " 1. List Items" <<endl;
		cout << " 2. Book Items" <<endl;
		cout << " 3. Cancel Booking" << endl;
		cout << " 4. Exit" <<endl; 
		int choice;
		cout << " Enter Choice: " <<endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			List();
			break;
		case 2:
			system("cls");
			Booking();
			break;
		case 3:
			system("cls");
			Cancellation();
			break;
		case 4:
			system("cls");
			Exitprog();
			break;
		default:
			cout << "\nInvalid input";
			goto start;
		}
//		again:
//		cout << " Press 1 to go to Main Menu and 0 to Exit. " <<endl;
//		cout << " Enter Choice: ";
//		cin >> con;
//		if (con == 1)
//		{
//			system("cls");
//			goto start;
//		}
//		else if(con == 0)
//		{
//			Exitprog();
//		}
//		else
//		cout <<endl << " Invalid input";
//		goto again;
	}
};

class LostAndFound{   //CLASS LOSTNFOUND-------------------------------------------
public:
	char type[20],desc[100];
	int serial;
	int found;
	
	void choice(){
		int c1;
		system("CLS");
		cout << "Choose from below: \n1. Report a lost item\n2. Search a lost Item\n Enter choice: ";
		cin >> c1;
		if(c1==1){
			system("CLS");
			report();
		}else if(c1==2){
			system("CLS");
			search();
		}
	}
	
	report(){
		fstream file;
		file.open("admin.txt",ios::app);
		LostAndFound obj;
		cout<< "What type of item is lost? ";
		fflush(stdin);
		fgets(obj.type, 20, stdin);
		cout << "Please provide a description of the lost item: ";
		fflush(stdin);
		fgets(obj.desc, 100, stdin);
		int r1,r2,r3;
		r1 = (rand() % 100) + 1;
		r2 = (rand() % 100) + 1;
		r3 = (rand() % 100) + 1;
		r1 = r1+r2+r3;
		cout << "Serial number for the lost item(Please save it somewhere): " << r1 << endl;
		sleep(3);
		obj.serial=r1;
		obj.found=0;
		file << "Type: " << obj.type << "Description: " << obj.desc << "Serial Number: " << r1 << obj.found << endl;
		fstream f;
		f.open("lostnfound.dat", ios::app);
		f.write((char*)&obj, sizeof(obj));
		f.close();
	}
	search(){
		LostAndFound obj;
	    char type[20],desc[100];
		int n;
		cout <<"Enter the serial number of the lost item to search: ";
		cin >> n;
		fstream f;
		f.open("lostnfound.dat", ios::in);
		int flag=0;
		while(f.read((char*)&obj , sizeof(obj))){
			if(obj.serial==n && obj.found == 1){
    		    cout << "Item type: " << obj.type << "Description: " << obj.desc << "Object has been found. Please come by the LostNFound Stop." << endl;
    		    sleep(2);
    		    flag =1;
			}else if(obj.serial==n && obj.found == 0){
				cout << "Item type: " << obj.type << "Description: " << obj.desc << "Object has not been found yet."<< endl;
				sleep(2);
				flag=1;
			}
		}
		if(flag==0){
			cout << "Item not found" << endl;
			sleep(2);
		} 
	}
	assign(){
		string code;
		up:
		cout << "Enter admin code: ";
		cin >> code;
		if(code!="XDL798"){
			cout << "Incorrect, try again." << endl;
			sleep(1);
			goto up;
		}
		LostAndFound obj,obj2;
		int flag=0,n;
		char f,f2;
		fstream file;
		fstream copy;
		copy.open("copy.dat",ios::out);
		file.open("lostnfound.dat", ios::in | ios::out);
		cout << "Enter the serial number of the item: ";
		fflush(stdin);
		cin>>n;
		while(file.read((char*)&obj , sizeof(obj))){
			if(obj.serial==n){
				flag=1;
    		    cout << "Has the item been found?[y/n] ";
    		    fflush(stdin);
		        cin >> f;
	        	if(f=='y' || f=='Y'){
	        		obj.found=1;
	        		cout << "Assigned" << endl;
	        		sleep(1);
				}
				cout << "Has the item been retreived by the owner?[y/n] ";
				fflush(stdin);
				cin >> f2;
				if(f2=='Y' || f2=='y'){
					obj.serial=-1;
				}
				
			}
			if(flag==0){
				cout << "Serial number not found\n";
				sleep(1);
			}
			if(obj.serial!=-1) copy.write((char*)&obj,sizeof(obj));
		}
		copy.close();
		file.close();
		copy.open("copy.dat",ios::in);
		file.open("lostnfound.dat",ios::out);
		while(copy.read((char*)&obj2,sizeof(obj2))){
			file.write((char*)&obj2,sizeof(obj2));
		}
		copy.close();
		remove("copy.dat");	
	}
};

class Reservation{
	int cho;
	int date,month,year,guests=0,till,from,time;
		int flag=0,temp_d,temp_m,temp_y;;
	public:
		int get_date(){
			return date;
		}
		int  get_month(){
			return month;
		}
		int get_year(){
			return year;
		}
		int time_calc(){
				int T;
				return (till-from);
				
			}
		void Exitpr()
		{	
			cout << " Thank you! ";
			sleep(1);
		}
		void set_date(){
			fflush(stdin);
			d_check:
			cin>>date;
				if (date>31||date<1){
						cout<<"Invalid date! Please enter from a range of (1-31)\n";
						goto d_check;
				}
			m_check:
			cin>>month;
			if(month>12||month<1){
				cout<<"Invalid month! Please enter month from (1-12) ";
				goto m_check;
			}
			y_check:
			cin>>year;
				if(year<2022||year>3000){
					cout<<"Invalid year! Please enter year from a range of (2022-3000)";
					goto y_check;
				}
		}
		void reserve(){
			fflush (stdin);
			cout<<"\n\nEnter the date (dd<enter>mm<enter>yyyy): \n";
			set_date();
			fflush (stdin);
			gues:
				cout<<"How many guests will be invited: ";
				cin>>guests;
				if (guests > 100){
					cout<<"There's not enough space, right now the maximum capacity is of 100 people!\n";
					goto gues;
				}
			reserv:
			time_check:
			frm:	
			cout<<"Enter the time range for this reservation in 24-hr format (1hrs-24hrs)\nFrom:";
			cin>>from;
			if(from>23){
				cout<<"The Club closes at 12 AM and the reservation must be of 1 hour at least!";
				goto frm;
			}
			till:
			cout<<"\nTill:";
			cin>>till;
			if(till>24){
				cout<<"The Club closes after 12 AM!";
				goto till;
			}
			
			time=time_calc();
			if(time>4){
				cout<<"\nYou can not reserve more than 4 hours!\n";
				goto time_check;
			}if(time==0){
				cout<<"\nReservation must be of 1 hour at least";
			}
			ifstream myfile;
			myfile.open("date.txt",ios::in);
			if(myfile.is_open()){
				
				while(!myfile.eof())
				{//cout<<"0";
					myfile>> temp_d>>temp_m>>temp_y;
					if(temp_d==get_date())
					{//cout<<"1";
						if(temp_m==get_month())
						{//cout<<"2";
							if(temp_y==get_year())
							{//cout<<"3";
								flag=1;
							}
						}
								
					}
						
				}
			}
			myfile.close();
			if(flag==1){
				cout<<"\nReservation for this date has already been made!\n";
				goto reserv;
			}else{
			
				ofstream myfile;
				myfile.open("date.txt", ios::app);
				if(myfile.is_open()){
					myfile<<date<<" "<<month<<" "<<year<<endl;
			}
			}
				cout<<"\n\t\t Your reservation for the CarpeDiem Dining Hall for the whole evening has been made!\n";
		}
			
		void cancel_res(){
			cout<<"Enter the date of reservation that has been made (dd<enter>mm<enter>yyyy): \n";
			set_date();
			
		
		ofstream temp;
		temp.open("temp.txt");
		ifstream myfile;
		myfile.open("date.txt",ios::in);

		if(myfile.is_open())
		{
			while(myfile>> temp_d>>temp_m>>temp_y)
			{
				if(temp_d==date)
				{
					if(temp_m==month)
					{
						if(temp_y==year)
						{
					    	flag=1;
						}
							
					}
				}
				else
				{
					temp << temp_d << " " << temp_m << " " << temp_y << endl;
				}
				
			}
		}
			if(flag==1){
				
				cout<<"\nYour reservation of "<<date<<"/"<<month<<"/"<<year<<" has been cancelled.\n";
			}else{
				cout<<"\nNo reservations found!";
			temp.close();
			myfile.close();
			}
			
			remove("date.txt");
			rename("temp.txt","date.txt");
		}
	
		void resdisplay(){
			cout<<"Welcome to CarpeDiem Dinner hall!\n ";
			cout<<"1. Make reservation\n2. Cancel Reservation\n3. Exit";
			cin>>cho;
			switch (cho){
				case 1:
				reserve();
				break;
				case 2:	
				cancel_res();	
				break;
				case 3:
				Exitpr();
				
				default:
					break;
			}
			
		}	
};


class mainmenu: public Register, public order, public Sports, public Gym, public LostAndFound, public Reservation  //CLASS MAINMENU-------
{
	public:
	int c,c1,c2;
	display()
	{
		while(1){
			up:
			system("CLS");
			cout << "WELCOME TO CARPE DIEM" << endl;
			cout << "1.Cafe\n2.Lost and Found\n3.Sports Reservation\n4.Gym Equipment Reservation\n5.Dining Reservation\n6.Exit\nEnter Choice: ";
			cin >> c;
			if(c==1){
				system("CLS");
				placeOrder();
			}else if(c==2){
				choice();
			}else if(c==3){
				system("CLS");
				Main_Menu();
			}else if(c==4){
				system("CLS");
				Menu();
			}else if(c==5){
				system("CLS");
				resdisplay();
			}else if(c==6){
				exit(0);
		    }else{
		    	cout << "Invalid Input, Try again\n";
				goto up;
			}
		}
		
		
	}
	displayAdmin(){
		while(1){
			system("CLS");
			cout << "1. Assign state of LAF\n2. Exit\nEnter choice: ";
			cin >> c2;
			if(c2==1){
				assign();
		    }else if(c2==2){
		    	exit(1);
			}else{
				cout << "Invalid input, try again\n";
			}
		}
		
	}
};


main()
{
	srand((unsigned) time(0));
	mainmenu obj;
	int choice;
	home:
    cout << " WELCOME TO CARPE DIEM " << endl;
	cout << " 1. Sign Up   "<< endl;
	cout << " 2. Login" << endl;
	cout << " 3. Close App"<< endl;
	cout << "Enter Choice: ";
	cin >> choice;
	switch(choice)
	{
		case 1:
			obj.SignUp();
			break;
		case 2:
			int i;
			i=obj.Login();
			if(i==1){
				obj.display();
			}else if(i==2){
				obj.displayAdmin();
			}
			break;
		case 3:
			system("cls");
			cout << " Team Members " <<endl;
			cout << " 1. Maaz Jamshedi" <<endl;
			cout << " 2. Saleh Shamoon" <<endl;
			cout << " 3. Ahmed Saif" <<endl;
			break;
		default:
			cout << "Invalid Input.";
			goto home;
			break;
	}
}

