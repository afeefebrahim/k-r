#include<stdio.h>
int day_of_year(int year,int month,int day);
void month_day(int year,int yearday, int *day,int *month);
static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
main()
{
	int year =1990,month,day,yearday =78;
//	day_of_year(year,month,day);
//	printf("\n %d \n",day_of_year(year,month,day));
	month_day(year, yearday,&month,&day);
	printf("\n %d \t %d \n", month,day);
}
int day_of_year(int year, int month, int day)
{
	int leap,i;
	leap = (year%4 == 0) && (year%100 != 0)|| (year%400 == 0);
	if(month <1 || month >12 || year < 0 || day <0 || day > daytab[leap][month])
		return -1;	
	for(i = 0; i < month; i++)
		day = day + daytab[leap][i];
	return day;
}
void month_day(int year,int yearday, int *day, int *month)
{
	int leap,i;
	leap = (year%4) && (year%100) || (year%400);
	if(year <0){
		*day = -1;
		*month = -1;
		return ;
 	}
	if (yearday > 366 || (leap != 1 && yearday > 365)){
		*day = -1;
		*month = -1;
		return ;
	}			
	for(i = 0; yearday >= daytab[leap][i]; i++){
		yearday -=daytab[leap][i];
	}
	*month = i;
	*day = yearday;
}
		
