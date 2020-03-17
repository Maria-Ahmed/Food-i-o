#include <iostream>
#include <conio.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <cstring>
#include "AdmRestCust.h"

using namespace std;

void mainmenu()
{
	system("cls");
	int choice;
	
	customer c1;	//Customer object
	admin a1;	//Admin Object
	cout<<"*********FOOD I-O*********"<<endl<<endl;
	cout<<"\tUser Corner: "<<endl;
	int n;	//Choice for login (admin or customer)
	cout<<"1. User Registration"<<endl<<"2. User Login"<<endl<<"3. Admin Login"<<endl;
	cout<<"Enter your choice= ";
	cin>>n;
	
	switch(n)
	{
		case 1:
			{
				c1.RegisterUser();
				break;
			}
		case 2:
			{
				c1.login();
				break;
			}
		case 3:
			{
				a1.input();
				checklogin(a1);
				break;
			}
		default:
			{
				cout<<"Invalid choice"<<endl;
				break;
			}
	}
	
	if(logg==true)	//If login is true
	{
		cout<<endl<<"1. Order Food"<<endl<<"2. Exit"<<endl;
		cout<<"Enter your choice= ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				{
					int b_choice;	//Another choice to either choose restaurant or go back
					system("cls");
					cout<<endl<<"1. Choose Restaurant"<<endl<<"2. Go to Main menu"<<endl;
					cout<<"Enter your choice= ";
					cin>>b_choice;
					if(b_choice==1)
					{
						system("cls");
						restaurant r;
						starter s;
						maincourse m;
						dessert d;
						reciept re(&c1, &r);
						r.display();
						r.choose_restaurant();
						re.recieptdisplay();
						cout<<"Press 2 to go back to main menu"<<endl;
						cin>>b_choice;
					}
					if(b_choice==2)
					{
						mainmenu();
					}
					break;
				}
			default:
				{
					cout<<"INVALID CHOICE"<<endl;
					mainmenu();
				}
		}
	}
}

int main()
{
	mainmenu();
	return 0;
}

