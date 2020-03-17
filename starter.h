#include<iostream>
#include<conio.h>
#include<string.h>
#include <vector>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "foodbase.h"

using namespace std;

class starter:public foodbase
{
	private:
		string name[10][5];		//Food names
		int price[10][5];		//Food prices
		int restchoice;		//Restaurant choice
	public:
		starter()	//Default Constructor
		{
			
		}
		//Displays the food list
		void displaylist(int a)
		{
			int count=1;
			for(int i=0;i<5;i++)
			{
				cout<<count<<"- "<<name[a-1][i]<<"\t"<<price[a-1][i]<<endl;
				count++;
			}
		}
		
		//Initializes the name and price array with food and price depending on the choice of restaurant
		void foodlist(int a)
		{
			restchoice=a;
			switch(restchoice)
			{
				case 1:
					{
						name[0][0]="Chicken Soup\t";
						name[0][1]="Kabab\t";
						name[0][2]="Cheese Balls\t";
						name[0][3]="Salad\t";
						name[0][4]="Chicken Wings\t";
						price[0][0]=60;
						price[0][1]=50;
						price[0][2]=100;
						price[0][3]=50;
						price[0][4]=100;
						break;
					}
				case 2:
					{
						name[1][0]="Chicken Soup\t";
						name[1][1]="Shami Kabab\t ";
						name[1][2]="Chicken Yankee\t";
						name[1][3]="Salad\t";
						name[1][4]="Cheese Rolls\t";
						price[1][0]=80;
						price[1][1]=90;
						price[1][2]=20;
						price[1][3]=50;
						price[1][4]=80;
						break;
					}
				case 3:
					{
						name[2][0]="HOT N SOUR SOUP\t";
						name[2][1]="CHEESE BROAST\t";
						name[2][2]="GOLDEN FRIES\t";
						name[2][3]="CHICKEN SANDWICH\t";
						name[2][4]="GARLIC BREADS WITH FRIES\t";
						price[2][0]=120;
						price[2][1]=120;
						price[2][2]=80;
						price[2][3]=120;
						price[2][4]=50;
						break;
					}
				case 4:
					{
						name[3][0]="ITALIAN SALID\t";
						name[3][1]="CHEEXE SALID\t";
						name[3][2]="MACRONIS\t";
						name[3][3]="CHOWMIN\t";
						name[3][4]="RICE BALLS\t";
						price[3][0]=100;
						price[3][1]=80;
						price[3][2]=100;
						price[3][3]=150;
						price[3][4]=90;
						break;
					}
				case 5:
					{
						name[4][0]="Italian Salad\t";
						name[4][1]="Chicken Wings\t";
						name[4][2]="Onion Rings With Garlic sauce\t";
						name[4][3]="Chinese Corn Soup\t";
						name[4][4]="Hot'n'Sour Nuggets\t";
						price[4][0]=120;
						price[4][1]=80;
						price[4][2]=100;
						price[4][3]=90;
						price[4][4]=135;
						break;
					}
				case 6:
					{
						name[5][0]="Garlic Bread\t";
						name[5][1]="Cheese Rolls\t";
						name[5][2]="Cheese Fries\t";
						name[5][3]="Chicken Sausage\t";
						name[5][4]="Peporoni\t";
						price[5][0]=50;
						price[5][1]=70;
						price[5][2]=80;
						price[5][3]=50;
						price[5][4]=150;
						break;
					}
				case 7:
					{
						name[6][0]="Chicken Yankee\t";
						name[6][1]="Cheese Balls\t";
						name[6][2]="Italian Salad\t";
						name[6][3]="Cheese Rolls\t";
						name[6][4]="Chicken Sandwich\t";
						price[6][0]=30;
						price[6][1]=90;
						price[6][2]=120;
						price[6][3]=80;
						price[6][4]=100;
						break;
					}
				case 8:
					{
						name[7][0]="Chicken Sandwich\t";
						name[7][1]="Italian Salad\t";
						name[7][2]="Cheese Rolls\t";
						name[7][3]="Cheese Balls\t";
						name[7][4]="Chicken Yankee\t";
						price[7][0]=100;
						price[7][1]=120;
						price[7][2]=80;
						price[7][3]=100;
						price[7][4]=50;
						break;
					}
				case 9:
					{
						name[8][0]="Cheese Rolls\t";
						name[8][1]="Chicken Yankee\t";
						name[8][2]="Shami Kabab \t";
						name[8][3]="Italian Salad\t";
						name[8][4]="Cheese Rolls\t";
						price[8][0]=100;
						price[8][1]=50;
						price[8][2]=80;
						price[8][3]=120;
						price[8][4]=80;
						break;
					}
				case 10:
					{
						name[9][0]="Peporoni\t";
						name[9][1]="Italian Salad\t";
						name[9][2]="Shami Kabab \t";
						name[9][3]="Cheese Rolls\t";
						name[9][4]="Chinese Corn Soup\t";
						price[9][0]=150;
						price[9][1]=120;
						price[9][2]=50;
						price[9][3]=80;
						price[9][4]=20;
						break;
					}
			}
		}
		void savefood(int a, int b)		//a= restaurant choice, b= food index
		{
			startername[startercount]=name[b-1][a-1];
			starterprices[startercount]=price[b-1][a-1];
			startercount++;
		}
		void makestarterbackup(string u_name)
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
			file<<"Starter :";
			file<<endl;
			for(int i=0;i<startercount;i++)
			{
				file<<startername[i]<<"\nQuantity:"<<quantitystarter[i]<<"\nPrice="<<starterprices[i]<<endl;
			}
			file.close();
		}
};
