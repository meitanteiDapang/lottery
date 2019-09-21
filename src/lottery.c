#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include"common.h"
#include"commonlink.h"
#include"lotterytype.h"
#include"lottery.h"
#include"punter.h"
#include"manager.h"
#include"notary.h"
#include"control.h"
#include"view.h"







Lottery_data* create_lottery_data(CLnode* lotterytypeHead
					,int type, int number,
				 int* Num, char* owner)
{
	Lottery_data* data = (Lottery_data*) 
			calloc(1,sizeof(Lottery_data));

	data->type = type;
	data->number = number;
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		data->Num[i] = Num[i];
	}
	strcpy(data->owner, owner);
	data->status = 0;
	CLnode* p = find_int_in_common_link_back(lotterytypeHead,
		 					type, match_lotterytype_type);
	if(NULL == p)
	{
		FLUSH;
		printf("create_lottery_data, no this kind of lottery\n");
		CONTINUE("回车继续");
		return NULL;
	}
	else if((p->data).lotterytype->status == 1)
	{
		FLUSH;
		printf("没有已发行的%d类彩票", type);
		CONTINUE("回车返回")
		return NULL;
	}
	data->issue = (p->data).lotterytype->issue;

	return data;
}


















int free_lottery_data(Udata data)
{
	free(data.lottery);
	return 1;
}










































