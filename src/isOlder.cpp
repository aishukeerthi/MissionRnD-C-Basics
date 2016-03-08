/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int validate_date(int day, int month, int year)
{
	if (month == 0 || day == 0 || year == 0 || month>12)
		return -1;
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day >31)
			return -1;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day>30)
			return -1;
	}
	else
	{
		if ((year % 4 == 0 && year % 100!=0 )|| year %400==0)
		{
			if (day>29)
				return -1;
		}
		else
		{
			if (day>28)
				return -1;
		}
	}

}
int validate_length(char *dob1)
{
	int i;
	for (i = 0; dob1[i] != '\0'; ++i);
	return i;
}
int isOlder(char *dob1, char *dob2)
{
	int day_1, day_2, month_1, month_2, year_1, year_2, temp, temp1,i,j;
	i = validate_length(dob1);
	j = validate_length(dob2);
	day_1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
	day_2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
	month_1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
	month_2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
	year_1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + (dob1[9] - '0');
	year_2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + (dob2[9] - '0');
	temp = (validate_date(day_1, month_1, year_1));
	temp1 = (validate_date(day_2, month_2, year_2));
	if (temp != -1 && temp1 != -1 && i==10 && j==10 )
	{
		if (year_1<year_2)
			return 1;
		else if (year_1>year_2)
			return 2;
		else
		{
			if (month_1<month_2)
				return 1;
			else if (month_1>month_2)
				return 2;
			else
			{
				if (day_1<day_2)
					return 1;
				else if (day_1>day_2)
					return 2;
				else
					return 0;
			}
		}
	}
	else return -1;
}

