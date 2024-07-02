#include <iostream>
#include<iomanip>

using namespace std;

int get_1st_weekday(int year){

  int d;
  d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return d;
}

int main()
{

   int year,month,day,daysInMonth,weekDay=0,startingDay;
   cout << "\nEnter your desired year:";
   cin >> year;

   string months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
   int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};

   if((year%4==0&&year%100!=0)||year%400==0)
       monthDay[1]=29;

   startingDay=get_1st_weekday(year);

   for(month=0;month <12;month++){

      daysInMonth=monthDay[month];
      cout << "\n\n---------------" << months[month] << "-------------------\n";
      cout << "\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n";

      for(weekDay=0;weekDay<startingDay;weekDay++)
        cout << "     ";

      for(day=1;day<=daysInMonth;day++){
        cout << setw(5) << day;

        if(++weekDay>6){
            cout << endl;
            weekDay=0;
        }
        startingDay=weekDay;
      }

   }

 return 0;
}
