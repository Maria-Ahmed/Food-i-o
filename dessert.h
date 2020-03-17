#include<iostream>
#include<conio.h>
#include<string.h>
#include <vector>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "maincourse.h"

class dessert: public foodbase
{
	private:
		string name[10][5];	//Saving names of Food with respective to restaurant
		int price[10][5];	//Saving prices for those food items
		int restchoice;	//Restaurant Choice
	public:
		dessert()
		{
			
		}
		void displaylist(int a)
		{
			int count=1;	//Just some random counter
			for(int i=0;i<5;i++)
			{
				cout<<count<<"- "<<name[a-1][i]<<price[a-1][i]<<endl;
				count++;
			}
		}
		
		void foodlist(int a)
		{
			restchoice=a;
			switch(restchoice)
			{
				case 1:
					{
						name[0][0]="Shakes\t";
						name[0][1]="Lava Cakes\t";
						name[0][2]="Pecan Pie\t";
						name[0][3]="Gelato\t";
						name[0][4]="Cocktail Custard\t";
						price[0][0]=80;
						price[0][1]=200;
						price[0][2]=250;
						price[0][3]=150;
						price[0][4]=170;
						break;
					}
				case 2:
					{
						name[1][0]="Shakes\t";
						name[1][1]="Iice Cream\t";
						name[1][2]="Pavlova\t";
						name[1][3]="Gelato\t";
						name[1][4]="Cocktail Custard\t";
						price[1][0]=90;
						price[1][1]=150;
						price[1][2]=200;
						price[1][3]=150;
						price[1][4]=170;
						break;
					}
				case 3:
					{
						name[2][0]="Custard Pie\t";
						name[2][1]="Black Forest Gataeu\t";
						name[2][2]="Schaumrolle\t";
						name[2][3]="Gelato\t";
						name[2][4]="Milk Shakes\t";
						price[2][0]=200;
						price[2][1]=250;
						price[2][2]=120;
						price[2][3]=160;
						price[2][4]=100;
						break;
					}
				case 4:
					{
						name[3][0]="Ice Cream\t";
						name[3][1]="Cocktail Desserts\t";
						name[3][2]="Moon Cake\t ";
						name[3][3]="Labb-e-Sheeren\t";
						name[3][4]="Gulaab Jaamun\t";
						price[3][0]=100;
						price[3][1]=150;
						price[3][2]=200;
						price[3][3]=350;
						price[3][4]=250;
						break;
					}
				case 5:
					{
						name[4][0]="Milkshakes\t";
						name[4][1]="Cocktail Custard\t";
						name[4][2]="Lava Cakes\t";
						name[4][3]="SchaumRolle\t";
						name[4][4]="Custard Pie\t";
						price[4][0]=100;
						price[4][1]=250;
						price[4][2]=200;
						price[4][3]=120;
						price[4][4]=200;
						break;
					}
				case 6:
					{
						name[5][0]="Black Forest Gatau\t";
						name[5][1]="Peccan Pie\t";
						name[5][2]="Custard\t";
						name[5][3]="Gelato\t";
						name[5][4]="Strawberry Cup IceCream\t";
						price[5][0]=300;
						price[5][1]=200;
						price[5][2]=250;
						price[5][3]=150;
						price[5][4]=70;
						break;
					}
				case 7:
					{
						name[6][0]="Peccan Pie\t";
						name[6][1]="Milkshakes\t";
						name[6][2]="Black Forest Gataeu\t";
						name[6][3]="Custard\t";
						name[6][4]="Gelato\t";
						price[6][0]=210;
						price[6][1]=90;
						price[6][2]=250;
						price[6][3]=170;
						price[6][4]=220;
						break;
					}
				case 8:
					{
						name[7][0]="SchaumRolle\t";
						name[7][1]="Lava Cakes\t";
						name[7][2]="Cocktail Custard\t";
						name[7][3]="Custard Pie\t";
						name[7][4]="Gelato\t";
						price[7][0]=120;
						price[7][1]=150;
						price[7][2]=250;
						price[7][3]=200;
						price[7][4]=170;
						break;
					}
				case 9:
					{
						name[8][0]="Custard Pie\t";
						name[8][1]="Lava Cakes\t";
						name[8][2]="Cocktail Custard\t";
						name[8][3]="Shakes\t";
						name[8][4]="Chocalate Crunchy'Munchy Icecream\t";
						price[8][0]=220;
						price[8][1]=150;
						price[8][2]=250;
						price[8][3]=90;
						price[8][4]=100;
						break;
					}
				case 10:
					{
						name[9][0]="Shakes\t";
						name[9][1]="Black Forest Gataeu\t";
						name[9][2]="Lava Cakes\t";
						name[9][3]="Gelato\t";
						name[9][4]="Cocktail Custard\t";
						price[9][0]=120;
						price[9][1]=220;
						price[9][2]=180;
						price[9][3]=200;
						price[9][4]=300;
						break;
					}
			}	
		}
		void savefood(int a, int b)		//a= food index, b=restaurant choice
		{
			dessertname[dessertcount]=name[b-1][a-1];
			dessertprices[dessertcount]=price[b-1][a-1];
			dessertcount++;
		}
		void makedessertbackup(string u_name)
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
			file<<"Dessert :";
			file<<endl;
			for(int i=0;i<dessertcount;i++)
			{
				file<<dessertname[i]<<"\nQuantity:"<<quantitydessert[i]<<"\nPrice="<<dessertprices[i]<<endl;
			}
			file.close();
		}
};
