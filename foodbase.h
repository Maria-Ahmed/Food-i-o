//foodbase class

#include<iostream>
#include<conio.h>
#include<string.h>
#include <vector>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

//Overall counter for total starter, main and dessert ordered
int startercount=0;
int maincoursecount=0;
int dessertcount=0;

//Counter for specific food for starter, main and dessert
int quantitystarter[10], quantitymaincourse[10], quantitydessert[10];

class foodbase
{
	private:
		
	protected:
		string startername[10];		//Saving starter names
		string maincoursename[10];	//Saving main course names
		string dessertname[10];		//Saving dessert names
		
		int starterprices[10];		//Saving starter prices
		int maincourseprices[10];	//Saving main course prices
		int dessertprices[10];		//saving dessert prices
		
		int startersum, maincoursesum, dessertsum;	//Total prices of all starter, main and dessert ordered
	public:
		foodbase()		//default constructor
		{
			startersum=0;
			maincoursesum=0;
			dessertsum=0;
		}
		void virtual foodlist(int restchoice)=0;	//Lists down food depending on the restaurant (initialization)
		void virtual displaylist(int restchoice)=0;	//Displays the menu depending on the restaurant
		void virtual savefood(int restchoice, int foodindex)=0;		//Saves the food on the basis of restaurant and food index
		void displaystarter()
		{
			int startquantity;	//Quantity of starter (temporary)
			for(int i=0;i<startercount;i++)
			{
				cout<<startername[i]<<"\t"<<starterprices[i]<<endl;
				cout<<"Enter quantity of "<<startername[i]<<" =";
				cin>>startquantity;
				quantitystarter[i]=startquantity;
				starterprices[i]*=startquantity;
				startersum+=starterprices[i];
			}
		}
		void displaymaincourse()
		{
			int mainquantity;	//Quantity of maincourse (temporary)
			for(int i=0;i<maincoursecount;i++)
			{
				cout<<maincoursename[i]<<"\t"<<maincourseprices[i]<<endl;
				cout<<"Enter quantity of "<<maincoursename[i]<<" =";
				cin>>mainquantity;
				quantitymaincourse[i]=mainquantity;
				maincourseprices[i]*=mainquantity;
				maincoursesum+=maincourseprices[i];
			}
		}
		void displaydessert()
		{
			int dessertquantity;	//Quantity for dessert (temporary)
			for (int i=0;i<dessertcount;i++)
			{
				cout<<dessertname[i]<<"\t"<<dessertprices[i]<<endl;
				cout<<"Enter quantity of "<<dessertname[i]<<"= ";
				cin>>dessertquantity;
				quantitydessert[i]=dessertquantity;
				dessertprices[i]*=dessertquantity;
				dessertsum+=dessertprices[i];
			}
		}
		int getstarterbill()	//Display total sum for starter
		{
			cout<<"Starter Bill: "<<endl;
			for(int i=0;i<startercount;i++)
			{
				cout<<startername[i]<<":"<<quantitystarter[i]<<"="<<starterprices[i]<<endl;
			}
			cout<<"Starters total cost= "<<startersum<<endl;
			return startersum;
		}
		int getmaincoursebill()
		{
			cout<<"Main course Bill: "<<endl;
			for(int i=0;i<maincoursecount;i++)
			{
				cout<<maincoursename[i]<<":"<<quantitymaincourse[i]<<" = "<<maincourseprices[i]<<endl;
			}
			cout<<"Main course total cost= "<<maincoursesum<<endl;
			return maincoursesum;
		}
		int getdessertbill()
		{
			cout<<"Dessert Bill: "<<endl;
			for(int i=0;i<dessertcount;i++)
			{
				cout<<dessertname[i]<<":"<<quantitydessert[i]<<" = "<<dessertprices[i]<<endl;
			}
			cout<<"Dessert total cost= "<<dessertsum<<endl;
			return dessertsum;
		}
		virtual void makestarterbackup(string u_name)
		{
			string user=u_name;
			string filetxt=user + "backup.txt";
			fstream file(filetxt.c_str(),ios::in | ios::out | ios::app);
			if(!file.is_open())
			{
				cout<<"Error opening file";
			}
			file<<endl;
			for(int i=0;i<startercount;i++)
			{
				file<<startername[i]<<":"<<quantitystarter[i]<<"= "<<starterprices[i]<<endl;
			}
			file.close();
		}
		virtual void makemaincoursebackup(string u_name)
		{
			string user=u_name;
			string filetxt=user + "backup.txt";
			fstream file;
			file.open(filetxt.c_str(),ios::in | ios::out | ios::app);
			if(!file.is_open())
			{
				cout<<"Error opening file";
			}
			file<<endl;
			for(int i=0;i<maincoursecount;i++)
			{
				file<<maincoursename[i]<<":"<<quantitymaincourse[i]<<"= "<<maincourseprices[i]<<endl;
			}
			file.close();
		}
		virtual void makedessertbackup(string u_name)
		{
			string user=u_name;
			string filetxt=user + "backup.txt";
			fstream file;
			file.open(filetxt.c_str(),ios::in | ios::out | ios::app);
			if(!file.is_open())
			{
				cout<<"Error opening file";
			}
			file<<endl;
			for(int i=0;i<dessertcount;i++)
			{
				file<<dessertname[i]<<":"<<quantitydessert[i]<<"= "<<dessertprices[i]<<endl;
			}
			file.close();
		}
		~foodbase()
		{
			
		}
};
