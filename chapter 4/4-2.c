/*Extend atof to handle scientific notation of the form
123.45e-6*/
#include<stdio.h>
#include<ctype.h>
double atof(char s[]);
main()
{
	char s[20] = "123.45e-3";
	printf("result = %f\n",atof(s));
}
double atof( char s[])
{
	int i,sign,pow,mul,temp =0,n = 0;
	double result,val;
	for (i =0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-')? -1: 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0 ; isdigit(s[i]); i++)
		 val = val*10 +(s[i] - '0');
	if (s[i] == '.')
		i++;
	for(pow = 1.0; isdigit(s[i]); i++){
	 	val = val * 10+(s[i] - '0');
		pow *= 10;	
	}
	result = sign * val/pow;
	
	printf("%c\n",s[i]);
	if (s[i] == 'e' || s[i] == 'E'){
		mul = (s[++i] == '+')? 1: 0;
		i++;
		printf("%d\n",mul);
		for (temp = 0 ;isdigit(s[i])  ; i++){
			printf("%d\n",temp);
			temp = temp * 10+(s[i] - '0');
		}
		for(n=1 ;temp> 0; --temp)
			n *=10;
		if (mul == 1)
			result *=n;
		else
			result /=n;
	}
	printf ("n = %d\t temp=%d \n",n, temp);
	return result;
}
	 
