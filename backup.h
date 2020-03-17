#include <iostream>
#include <conio.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "AdmRestCust.h"

class backup
{
	private:
		
	public:
		backup()
		{
			
		}
		void makebackup(restaurant &r)
		{
			r.bill();
		}
};
