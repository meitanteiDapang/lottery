
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"common.h"
#include"commonlink.h"
#include"lotterytype.h"
#include"lottery.h"
#include"punter.h"
#include"manager.h"
#include"notary.h"
#include"control.h"
#include"view.h"

extern int issue1_now;
extern int issue2_now;

Lotterytype_data* create_lotterytype_data(int type,  double pool)
{
	Lotterytype_data* data = (Lotterytype_data*) 
			calloc(1,sizeof(Lotterytype_data));
	data->type = type;
	if(1 == type)
	{
		data->issue = type*MULT + issue1_now++;
	}
	else if(2 == type)
	{
		data->issue = type*MULT + issue2_now++;
	}
	data->status = 0;
	data->price = TYPE1_PRICE;
	data->soldNum = 0;
	data->pool = pool;
	data->award = 0.0;
	data->wins = 0;
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		data->winNum[i] = -1;
	}
	return data;
}


int match_lotterytype_issue(Udata data,
		 int issue)
{
	if((data.lotterytype)->issue == issue)
	{
		return 0;
	}
	else
	{
		return -1;
	}

}

int match_lotterytype_type(Udata data,
		 int type)
{
	if((data.lotterytype)->type == type)
	{
		return 0;
	}
	else
	{
		return -1;
	}

}




int display_lotterytype_data(Udata data)
{
	int type = (data.lotterytype)->type;
	int i = 0;
	printf("%d\t%d\t%d\t\t",type, 
		(data.lotterytype)->issue, (data.lotterytype)->status);
	if(type == 1)
	{
		printf("(");
		for(i = 0; i < 3; ++i)
		{
			printf("%d ", (data.lotterytype)->winNum[i]);
		}
		printf(")\t\t");
	}
	else if(type == 2)
	{
		printf("(");
		int s = 0;
		for(i = 0; i < 6; ++i)
		{
			int numk = (data.lotterytype)->winNum[i];
			printf("%d ", numk);
			if(numk >= 10)
			{
				s++;
			}
		}
		if(s >= 2 || (data.lotterytype)->winNum[0] == -1)
		{
			printf(")\t");
		}
		else
		{
			printf(")\t\t");
		}
	}

	printf("%g\t%d\t%g\t\t%d\n",(data.lotterytype)->price, 
		(data.lotterytype)->soldNum, (data.lotterytype)->award
		, (data.lotterytype)->wins);
	return 1;
}





















































int free_lotterytype_data(Udata data)
{
	free(data.lotterytype);
	return 1;
}









































