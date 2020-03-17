//Admin, Restaurant and Customer class

#include <iostream>
#include <conio.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include<sstream>
#include <ctime>
#include "dessert.h"
using namespace std;

//Admin class
class admin
{
	private:
		string id;
		string password;
	public:
		void input()
		{
			cout<<"Enter admin ID= ";
			cin>>id;
			cout<<"Enter password= ";
			cin>>password;
		}
		void friend checklogin(admin obj);
		void seebackup()
		{
			string uname;
			char c;
			string filetxt;
			int choice=1;
			system("cls");
			while(choice!=2)
			{
				cout<<"Enter details for user (backup):"<<endl;
				cout<<"Enter User name= ";
				cin>>uname;
				filetxt=uname+ "backup.txt";
				fstream file;
				file.open(filetxt.c_str(),ios::in| ios::out);
				if(!file.is_open())
				{
					cout<<"File not found"<<endl;
				}
				else
				{
					while(!file.eof())
					{
						while(file.get(c))
						{
							cout<<c;
						}
					}
					cout<<endl<<"Do you want to see any other file (1 for yes, 2 for no)= ";
					cin>>choice;
				}
			}
		}
};

//Checks login credentials
void checklogin(admin obj)
{
	if(obj.id=="mission" && obj.password=="completed")
	{
		obj.seebackup();
	}
	else
	{
		cout<<"Wrong credentials"<<endl;
	}
}

class restaurant
{
	private:
		vector <string> name;	//Restaurant names
		string User_Name;	//User name
		foodbase *sf;
		foodbase *mf;
		foodbase *df;
		string time_l;
	public:
	//friend	class customer;
	void timecal()
	{
		    time_t rawtime;
	    	struct tm tstruct;
	    	
	    	time (&rawtime);
	    	time_t now=time(0);
	    	tstruct= *localtime(&now);
	    	time_l=ctime(&rawtime);
	    	
	}
		restaurant()
		{
			//Extracting restaurant names and storing in name vector
			fstream myfile("restname.txt");
			string line;
			if(myfile.is_open())
			{
				while(getline(myfile,line))
				{
					name.push_back(line);
				}
				myfile.close();
			}
			sf= new starter;
			mf= new maincourse;
			df= new dessert;
		}
		
		//Displays restaurant names
		void display()
		{
			cout<<"Restaurants: "<<endl;
			for(int i=0;i<10;i++)
			{
				cout<<i+1<<"- "<<name[i]<<endl;
			}
		}
		//Prompts user to choose restaurant with food. Main procedure
		void choose_restaurant()
		{
			int choice;
			cout<<"Choose your restaurant:"<<endl;
			jump00:
			cin>>choice;
			
			try
			{
				if(choice>0 && choice<11)
				{
					system("cls");
					cout<<"*****Welcome to "<<name[choice-1]<<"*****"<<endl;
					cout<<"Choose your starter="<<endl;
					int choice2=1;
					while(choice2==1)
					{
						int choice3;
						sf->foodlist(choice);
						sf->displaylist(choice);
						jump0:
						cout<<"If you want no starter food, press 0"<<endl;
						cin>>choice3;
						if(choice3!=0)
						{
							try
							{
								//Exception handling
								if(choice3<6)
								{
									sf->savefood(choice3,choice);
								}
								else
								{
									throw choice3;
								}
							}
							catch(int)
							{
								cout<<"Invalid Input"<<endl;
								goto jump0;
							}
							cout<<endl;
							cout<<"Do you want more(Press 1 for yes, 0 for no)= ";
							cin>>choice2;
							choice2==0;
						}
						else if(choice3==0)
						{
							choice2=0;
						}
					}
					system("cls");
					cout<<endl<<"Choose your main course="<<endl;
					int choice4=1;
					while(choice4==1)
					{
						int choice5;
						mf->foodlist(choice);
						mf->displaylist(choice);
						cout<<"If you want nothing from main course press 0"<<endl;
						jump1:
							
						cin>>choice5;
						
						if(choice5!=0)
						{
							try
							{
								if(choice5<6 && choice>0)
								{
									mf->savefood(choice5,choice);
								}
								else
								{
									throw choice5;
								}
							}
							catch(int)
							{
								cout<<"Invalid Input"<<endl;
								goto jump1;
							}
							cout<<endl;
							cout<<"Do you want more? (Press 1 for yes, 0 for no)= ";
							cin>>choice4;
						}
						else if (choice5==0)
						{
							choice4=0;
						}
					}
					system("cls");
					cout<<"Choose your dessert= "<<endl;
					int choice6=1;
					while(choice6==1)
					{
						df->foodlist(choice);
						df->displaylist(choice);
						int choice7;
						cout<<"Want to exit dessert section? Press 0"<<endl;
						jump2:
						cin>>choice7;
						if(choice7!=0)
						{
							try
							{
								if(choice7<6)
								{
									df->savefood(choice7,choice);
								}
								else
								{
									throw choice7;
								}
							}
							catch(int)
							{
								cout<<"Invalid input"<<endl;
								goto jump2;
							}
							cout<<endl;
							cout<<"Do you want more? (Press 1 for yes, 0 for no)= ";
							cin>>choice6;
						}
						else if (choice7==0)
						{
							choice6=0;
						}
					}
				}
				else
				{
					throw choice;
				}
			}
			catch(int choice)
			{
				cout<<"Invalid input"<<endl;
				goto jump00;
			}
		}
		//Prints bill
		void bill(string username)
		{
			timecal();
			 system("cls");
			cout<<"\t\tBill\t\t"<<endl;
			sf->displaystarter();
			mf->displaymaincourse();
			df->displaydessert();
			system("cls");
			cout<<endl;
			sf->makestarterbackup(username);
			mf->makemaincoursebackup(username);
			df->makedessertbackup(username);
			int startfsum=sf->getstarterbill();
			int mainfsum=mf->getmaincoursebill();
			int dessertfsum=df->getdessertbill();
			int totalfsum=startfsum+mainfsum+dessertfsum;
			
			
			cout<<"Time of order is "<<time_l<<endl;
			
			cout<<"------------------ Food Cost 		= "<<totalfsum<<"\n";
	    	cout<<"------------------ Delivery Charges	= 100"<<endl;
	    	cout<<"------------------ Total Cost           = "<<(totalfsum+100)<<endl;
	    	//backup total bill
	    	//time of order
	    	string filetxt=username + "backup.txt";
			fstream file;
			file.open(filetxt.c_str(),ios::in | ios::out | ios::app);
			if(!file.is_open())
			{
				cout<<"Error opening file";
			}
			file<<"Time of order is   "<<time_l<<endl;
			file<<"------------------ Food Cost 		= "<<totalfsum<<"\n";
	    	file<<"------------------ Delivery Charges	= 100"<<endl;
	    	file<<"------------------ Total Cost           = "<<(totalfsum+100)<<endl;
	    	
			file.close();
	    	
		}
};

bool logg=false;

//Customer class
class customer
{
	private:
		string name;
		string u_name;
		string pass;
		int phone;
		string address;
		string filetxt;
		int usercode;
	public:
		 
		string getusername()
		{
			return u_name;
		}
		void RegisterUser()
		{
			cout<<"\n*****Registration Page*****"<<endl;
			//Basic Data input of User
			//Output stream
			ofstream ofile;
			fflush(stdin);
			cout<<"Enter name= ";
			getline(cin,name);
			fflush(stdin);
			cout<<"Enter Username= ";
			cin>>u_name;
			//Creating file of user with the respective username
			filetxt=u_name+".txt";
			ofile.open(filetxt.c_str());
			
			//Writing name and username in file
			ofile<<"Name:"<<name<<endl;
			ofile<<"Username:"<<u_name<<endl;
			
			fflush(stdin);
			cout<<"Enter Password= ";
			cin>>pass;
			//Writing password with "(" and ")"
			ofile<<"("<<pass<<")"<<endl;
			
			cout<<"Enter contact number= ";
			cin>>phone;
			//Writing phone number in file
			ofile<<"Phone:"<<phone<<endl;
			fflush(stdin);
			cout<<"Enter Address= ";
			getline(cin,address);
			//Writing address in file
			ofile<<"Address:"<<address<<endl;
			
			login();
		}
	void Display_C()	//Display data
	{
		char data[100];
			ifstream ifile;
			ifile.open(filetxt.c_str());
			int i=0;
			while(!ifile.eof() )
			{
				//Gets 100 characters and stores into data from file
				ifile.getline(data,100);
				if(data[i]!='(')
				{
					cout<<data<<endl;
					
					
				}
			}
			ifile.close();
	}
		void login()
		{
			cout<<endl<<"\n*****Login Page*****"<<endl;
			int i=0,j=0,count=0;
			//Input stream
			
			
			char data[100], pasc[15]={'\0'},l;
			char chk_pass[15]={'\0'};
			
			cout<<"Enter Username=";
			cin>>u_name;
			//To open the file saved with username
			filetxt=u_name+".txt";
			
			cout<<"Enter Password= ";
			cin>>chk_pass;
			ifstream ifile;
			ifile.open (filetxt.c_str(),ios::in);
			bool lop=ifile.good();
			//cout<<lop;
			//cout<<ifile.good()<<ifile.good();;
			if(lop==true)
			{
				i=0,j=0;
				fflush(stdin);
				while(ifile.eof()!=true)
				{
					fflush(stdin);
					ifile.getline(data,100);
					fflush(stdin);
					
					if(data[i]=='(')
					{
						for(i=1;data[i]!=')';i++,j++)
						{
							pasc[j]=data[i];
						}
					}
				}
				
			}
			for(i=0;i<strlen(chk_pass);i++)
			{
				if(pasc[i]==chk_pass[i])
				{
					count++;
				}
			}
			//cout<<lop;
			if(strlen(pasc)==count && lop)
			{
				system("cls");
				Display_C();
				logg=true;
			}
			else
			{
				cout<<"Incorrect Password or username!"<<endl;
				logg=false;
			}
			ifile.close();
		}
	
};

class reciept
{
	public:
		customer *c;
		restaurant *res;
		reciept(customer *obj1, restaurant *obj2)
		{
			c=new customer();
			c=obj1;
			res=new restaurant();
			res=obj2;
		}
		void recieptdisplay()
		{
			system("cls");
			cout<<"Bill for Customer"<<endl;
			res->bill(c->getusername());
			c->Display_C();
		}
};
