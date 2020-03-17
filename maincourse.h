#include<iostream>
#include<conio.h>
#include<string.h>
#include <vector>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "starter.h"

using namespace std;

class maincourse: public foodbase
{
	private:
		string name[10][5];	//Food name
		int price[10][5];	//Food price
		int restchoice;		//Restaurant Choice
	public:
		maincourse()
		{
			
		}
		
		void displaylist(int a)
		{
			int count=1;
			for(int i=0;i<5;i++)
			{
				cout<<count<<"- "<<name[a-1][i]<<"\t"<<price[a-1][i]<<endl;
				count++;
			}
		}
		
		// Initializes food names with prices with respect to restaurant
		void foodlist(int a)
		{
			int restchoice=a;
			switch(restchoice)
			{
				case 1:
					{
						name[0][0]="Chicken Karahi\t";
						name[0][1]="Chicken Tandoori\t";
						name[0][2]="Chicken Handi\t";
						name[0][3]="Chicken Mayo Pasta\t";
						name[0][4]="Chicken Biryani\t";
						price[0][0]=200;
						price[0][1]=150;
						price[0][2]=200;
						price[0][3]=50;
						price[0][4]=175;
						break;
					}
				case 2:
					{
						name[1][0]="Shahi Karahi\t";
						name[1][1]="Shami Kabab\t";
						name[1][2]="Seekh Boti\t";
						name[1][3]="Chicken Shashlik\t";
						price[1][0]=200;
						price[1][1]=310;
						price[1][2]=250;
						price[1][3]=50;
						price[1][4]=500;
						break;
					}
				case 3:
					{
						name[2][0]="Chicken Broast\t";
						name[2][1]="Jumbo Burger\t";
						name[2][2]="Chicken Burger\t";
						name[2][3]="Zinger Burger\t";
						name[2][4]="Chicken Cheese Burger\t";
						price[2][0]=250;
						price[2][1]=300;
						price[2][2]=150;
						price[2][3]=300;
						price[2][4]=400;
						break;
					}
				case 4:
					{
						name[3][0]="Veg Burger\t";
						name[3][1]="Hot Dog Sausage\t";
						name[3][2]="Aloo Tiki\t";
						name[3][3]="Cheese Burger\t";
						name[3][4]="Chicken Broast\t";
						price[3][0]=100;
						price[3][1]=150;
						price[3][2]=100;
						price[3][3]=200;
						price[3][4]=200;
						break;
					}
				case 5:
					{
						name[4][0]="Chicken Biryani\t ";
						name[4][1]="Meat Pulao\t";
						name[4][2]="Special Sindhi Biryani\t";
						name[4][3]="Salad and Raita\t";
						name[4][4]="Pasta\t";
						price[4][0]=150;
						price[4][1]=200;
						price[4][2]=250;
						price[4][3]=50;
						price[4][4]=175;
						break;
					}
				case 6:
					{
						name[5][0]="Chicken Karahi\t";
						name[5][1]="Chicken Haleem\t ";
						name[5][2]="Special Kaybees Burger\t";
						name[5][3]="Fries\t";
						name[5][4]="Chicken Wings\t";
						price[5][0]=400;
						price[5][1]=250;
						price[5][2]=200;
						price[5][3]=50;
						price[5][4]=175;
						break;
					}
				case 7:
					{
						name[6][0]="Zinger Burger\t";
						name[6][1]="Chicken Burger\t";
						name[6][2]="Chicken Burger with Extra dip\t";
						name[6][3]="Fries\t";
						name[6][4]="Doupler Burger\t";
						price[6][0]=120;
						price[6][1]=150;
						price[6][2]=350;
						price[6][3]=100;
						price[6][4]=350;
						break;
					}
				case 8:
					{
						name[7][0]="Chicken Handi\t";
						name[7][1]="Chapli Kabab\t";
						name[7][2]="Cheese Balls\t";
						name[7][3]="Salad\t";
						name[7][4]="Chicken Shashlik\t";
						price[7][0]=300;
						price[7][1]=150;
						price[7][2]=200;
						price[7][3]=50;
						price[7][4]=300;
						break;
					}
				case 9:
					{
						name[8][0]="Chicken Biryani\t";
						name[8][1]="Kabab\t";
						name[8][2]="Chicken Karahi\t";
						name[8][3]="Salad\t";
						name[8][4]="Chicken Wings\t";
						price[8][0]=200;
						price[8][1]=150;
						price[8][2]=400;
						price[8][3]=50;
						price[8][4]=250;
						break;
					}
				case 10:
					{
						name[9][0]="Chilli Cheeza\t";
						name[9][1]="Club Sandwich\t";
						name[9][2]="Chicken Broast\t";
						name[9][3]="Zinger Burger\t";
						name[9][4]="Crunchy Munchy Rolls\t";
						price[9][0]=400;
						price[9][1]=150;
						price[9][2]=200;
						price[9][3]=150;
						price[9][4]=100;
						break;
					}
			}
		}
		void savefood(int a, int b)		//a= Restaurant Choice, b= Food index
		{
			maincoursename[maincoursecount]=name[b-1][a-1];
			maincourseprices[maincoursecount]=price[b-1][a-1];
			maincoursecount++;
		}
		void makemaincoursebackup(string u_name)
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
			file<<"MainCourse :";
			file<<endl;
			for(int i=0;i<maincoursecount;i++)
			{
				file<<maincoursename[i]<<"\nQuantity:"<<quantitymaincourse[i]<<"\nPrice="<<maincourseprices[i]<<endl;
			}
			file.close();
		}
};
