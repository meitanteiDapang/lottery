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









int draw_lottery(CLnode* punterHead, CLnode* lotteryHead, CLnode* lotterytypeHead)
{
	//查看彩票类型是否合法
	int type = get_lottery_type();
	if(type == 0)
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("不存在此类彩票，回车返回");
		return 0;
	}
	else
	{	print_tabs(6);
		CONTINUE("彩票类型确认,回车继续");
	}
	//查看此类彩票是否可可开奖
	CLnode* p = find_int_in_common_link_back(lotterytypeHead,
				type, match_lotterytype_type);
	if(p == NULL)
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("未发行过此类彩票，回车返回");
		return 0;
	}
	else if((p->data).lotterytype->status == 1)
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("最近一期此类彩票为已开奖状态，回车返回");
		//待检查
		return 0;
	}
	else
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("彩票可开奖，回车继续");
	}

	int flag = 0;
	switch(type)
	{
		case 1:
			flag = draw_lotterytype1(punterHead, lotteryHead,
					lotterytypeHead);
			break;
		case 2:
			flag = draw_lotterytype2(punterHead, lotteryHead,
					lotterytypeHead);
			break;
		case 0:
			return 0;
	}
	if(flag == 1)
	{
		print_tabs(6);
		CONTINUE("开奖完成，回车返回");
	}
	else
	{
		print_tabs(6);
		CONTINUE("开奖失败，回车返回");
	}
	return 1;
}

int draw_lotterytype1(CLnode* punterHead,CLnode* lotteryHead,
			CLnode* lotterytypeHead)
{
	int type = 1;
	//遍历 lotterytypeHead，找出最新的，未开奖的 lotterytype,并得到
	//他的 pool
	CLnode* lotterytype = lotterytypeHead;
	int lotterytypeLen = lotterytypeHead->data.size;
	int issue = -1;
	double pool = 0.0;
	int flag = 0;
	int i = 0;
	for(i = 0; i<lotterytypeLen; ++i)
	{
		lotterytype = lotterytype -> previous;
		if((lotterytype->data).lotterytype->type == type
			&& (lotterytype->data).lotterytype->status == 0)
		{
			issue = (lotterytype->data).lotterytype->issue;
			pool = (lotterytype->data).lotterytype->pool;
			print_tabs(6);
			printf("将开奖期号为%d 的彩票,", issue);
			CONTINUE("回车继续");
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		print_tabs(6);
		CONTINUE("draw_lotterytype1, impossible error");
	}
	//输入中奖号码
	flag = 1;
	int Num[10] = {0};
	while(flag)
	{
		if(get_lottery_type1_num(Num, pool) == 1)
		{
			FLUSH;
			print_tabs(6);
			CONTINUE("选号完成,回车继续");
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	//更新 lotterytype 的 Num
	i = 0;
	for(i = 0; i < 3; ++i)
	{
		(lotterytype->data).lotterytype->winNum[i] = Num[i];
	}

	//遍历 lottery，统计中奖人数
	CLnode* lottery = lotteryHead;
	int lotteryLen = lotteryHead->data.size;
	int how_many = 0;//中奖人数
	for(i = 0; i < lotteryLen; ++i)
	{
		lottery = lottery->previous;
		if((lottery->data).lottery->issue == issue
			&& (match_lottery_num(lottery, Num, 3) == 0))
		{
			how_many += (lottery->data).lottery->number;
		}
	}
	//检测是否有人中奖
	double award = 0.0;
	if(how_many == 0)
	{
		print_tabs(6);
		CONTINUE("无人中奖，奖金滚入下期，回车继续");
	}
	else
	{
	//获得人均奖金
	 	award = pool/how_many;
	 	print_tabs(6);
	 	printf("%d 注彩票中奖，每注奖金%g,",how_many, award);
	 	CONTINUE("回车继续");
	}
	//遍历lottery，找到中间 lottery，找到 owner
	//遍历 punterhead,找到 punter，更新余额与历史记录
	//，更改lottery status
	lottery = lotteryHead;
	CLnode* punter = NULL;
	for(i = 0; i < lotteryLen; ++i)
	{
		lottery = lottery->previous;
		if((lottery->data).lottery->issue == issue
			&& (match_lottery_num(lottery, Num, 3) == 0))
		{
			//找到对应中奖者
			punter = find_char_in_common_link(punterHead, 
				(lottery->data).lottery->owner,
					match_punter_username);
			//更新余额
			(punter->data).punter->balance += (lottery->data).lottery->number * award;
			//更新历史记录
			char str0[120] = "\0";
			sprintf(str0+0, "%d", (lottery->data).lottery->number);
			char str1[15] = "注期号\0";
			char str2[15] = "\0";
			sprintf(str2+0,"%d", issue);
			char str3[25] = "中奖了,每注奖金:\0";
			char str4[10] = "\0";
			sprintf(str4+0, "%g",award);
			char str5[10] = ",余额:";
			char str6[20] = "\0";
			sprintf(str6+0, "%11.2f",get_punter_data_balance(punter->data));

			strcat(str0,str1);
			strcat(str0,str2);
			strcat(str0,str3);
			strcat(str0,str4);
			strcat(str0,str5);
			strcat(str0,str6);


			add_punter_data_history(punter->data, str0);
			//清空奖池
			(lotterytype->data).lotterytype->pool = 0.0;
			(lotterytype->data).lotterytype->wins += (lottery->data).lottery->number;

		}
		//假如期号对了，但是没中奖
		else if((lottery->data).lottery->issue == issue
			&& (match_lottery_num(lottery, Num, 3) != 0))
		{
			//找到对应未中奖者，更新历史记录
			punter = find_char_in_common_link(punterHead, 
				(lottery->data).lottery->owner,
					match_punter_username);
			char str0[120] = "\0";
			sprintf(str0+0, "%d", (lottery->data).lottery->number);
			char str1[15] = "注期号\0";
			char str2[15] = "\0";
			sprintf(str2+0,"%d", issue);
			char str3[25] = "未中奖\0";
			char str4[10] = "\0";
			char str5[10] = ",余额:";
			char str6[20] = "\0";
			sprintf(str6+0, "%11.2f",get_punter_data_balance(punter->data));

			strcat(str0,str1);
			strcat(str0,str2);
			strcat(str0,str3);
			strcat(str0,str4);
			strcat(str0,str5);
			strcat(str0,str6);

			add_punter_data_history(punter->data, str0);		
		}
		//更改 lottery status
		(lottery->data).lottery->status = 1;
		
	}
	//更新 lotterytype 的 status和 award
	(lotterytype->data).lotterytype->status = 1;
	(lotterytype->data).lotterytype->award = award;
	return 1;

}


int draw_lotterytype2(CLnode* punterHead,CLnode* lotteryHead,
			CLnode* lotterytypeHead)
{
	int type = 2;
	//遍历 lotterytypeHead，找出最新的，未开奖的 lotterytype,并得到
	//他的 pool
	CLnode* lotterytype = lotterytypeHead;
	int lotterytypeLen = lotterytypeHead->data.size;
	int issue = -1;
	double pool = 0.0;
	int flag = 0;
	int i = 0;
	for(i = 0; i<lotterytypeLen; ++i)
	{
		lotterytype = lotterytype -> previous;
		if((lotterytype->data).lotterytype->type == type
			&& (lotterytype->data).lotterytype->status == 0)
		{
			issue = (lotterytype->data).lotterytype->issue;
			pool = (lotterytype->data).lotterytype->pool;
			print_tabs(6);
			printf("将开奖期号为%d 的彩票,", issue);
			CONTINUE("回车继续");
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		print_tabs(6);
		CONTINUE("draw_lotterytype1, impossible error");
	}


	if (0==(lotterytype->data).lotterytype->soldNum)
	{
		char makesure = '\0';
		print_tabs(6);
		printf("无人购买此期彩票，确认开奖吗？y 为确认，其他为不开奖");
		scanf("%c", &makesure);
		if('y' != makesure)
		{
			FLUSH;
			print_tabs(6);
			CONTINUE("开奖中断，回车返回");
			return 0;
		}
	}

	//输入中奖号码
	flag = 1;
	int Num[10] = {0};
	while(flag)
	{
		if(get_lottery_type2_num(Num, pool) == 1)
		{
			FLUSH;
			print_tabs(6);
			CONTINUE("选号完成,回车继续");
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	//更新 lotterytype 的 Num
	i = 0;
	for(i = 0; i < 6; ++i)
	{
		(lotterytype->data).lotterytype->winNum[i] = Num[i];
	}

	//遍历 lottery，统计中奖人数
	CLnode* lottery = lotteryHead;
	int lotteryLen = lotteryHead->data.size;
	int how_many = 0;//中奖人数
	for(i = 0; i < lotteryLen; ++i)
	{
		lottery = lottery->previous;
		if((lottery->data).lottery->issue == issue
			&& (match_lottery_num(lottery, Num, 6) == 0))
		{
			how_many += (lottery->data).lottery->number;
		}
	}
	//检测是否有人中奖
	double award = 0.0;
	if(how_many == 0)
	{
		print_tabs(6);
		CONTINUE("无人中一等奖奖，奖金滚入下期，回车继续");
	}
	else
	{
	//获得人均奖金
	 	award = pool/how_many;
	 	print_tabs(6);
	 	printf("%d 注彩票中一等奖，每注奖金%g,",how_many, award);
	 	CONTINUE("回车继续");
	}
	//遍历lottery，找到中间 lottery，找到 owner
	//遍历 punterhead,找到 punter，更新余额与历史记录
	//，更改lottery status
	lottery = lotteryHead;
	CLnode* punter = NULL;
	for(i = 0; i < lotteryLen; ++i)
	{
		lottery = lottery->previous;
		if((lottery->data).lottery->issue == issue
			&& (match_lottery_num(lottery, Num, 6) == 0))
		{
			//找到对应中奖者
			punter = find_char_in_common_link(punterHead, 
				(lottery->data).lottery->owner,
					match_punter_username);
			//更新余额
			(punter->data).punter->balance += (lottery->data).lottery->number * award;
			//更新历史记录
			char str0[120] = "\0";
			sprintf(str0+0, "%d", (lottery->data).lottery->number);
			char str1[15] = "注期号\0";
			char str2[15] = "\0";
			sprintf(str2+0,"%d", issue);
			char str3[35] = "中1等奖了,每注奖金:\0";
			char str4[20] = "\0";
			sprintf(str4+0, "%11.2f",award);
			char str5[10] = ",余额:";
			char str6[20] = "\0";
			sprintf(str6+0, "%11.2f",get_punter_data_balance(punter->data));

			strcat(str0,str1);
			strcat(str0,str2);
			strcat(str0,str3);
			strcat(str0,str4);
			strcat(str0,str5);
			strcat(str0,str6);


			add_punter_data_history(punter->data, str0);
			//清空奖池
			(lotterytype->data).lotterytype->pool = 0.0;
			(lotterytype->data).lotterytype->wins += (lottery->data).lottery->number;

		}
		//假如期号对了，但是没中奖
		else if((lottery->data).lottery->issue == issue
			&& (match_lottery_num(lottery, Num, 6) != 0))
		{

			if(jidengjiang2(lottery,Num) == 0)
			{

				//找到对应未中奖者，更新历史记录
				punter = find_char_in_common_link(punterHead, 
					(lottery->data).lottery->owner,
						match_punter_username);
				char str0[120] = "\0";
				sprintf(str0+0, "%d", (lottery->data).lottery->number);
				char str1[20] = "注期号\0";
				char str2[20] = "\0";
				sprintf(str2+0,"%d", issue);
				char str3[25] = "未中奖\0";
				char str4[15] = "\0";
				char str5[20] = ",余额:";
				char str6[20] = "\0";
				sprintf(str6+0, "%11.2f",get_punter_data_balance(punter->data));

				strcat(str0,str1);
				strcat(str0,str2);
				strcat(str0,str3);
				strcat(str0,str4);
				strcat(str0,str5);
				strcat(str0,str6);

				add_punter_data_history(punter->data, str0);
			}
			else if (jidengjiang2(lottery,Num) == 2)
			{
				//找到对应中奖者
				punter = find_char_in_common_link(punterHead, 
					(lottery->data).lottery->owner,
						match_punter_username);
				//更新余额
				(punter->data).punter->balance += (lottery->data).lottery->number * 1000;
				//更新历史记录
				char str0[120] = "\0";
				sprintf(str0+0, "%d", (lottery->data).lottery->number);
				char str1[20] = "注期号\0";
				char str2[20] = "\0";
				sprintf(str2+0,"%d", issue);
				char str3[35] = "中2等奖了,每注奖金:\0";
				char str4[20] = "\0";
				sprintf(str4+0, "%d",1000);
				char str5[10] = ",余额:";
				char str6[20] = "\0";
				sprintf(str6+0, "%11.2f",get_punter_data_balance(punter->data));

				strcat(str0,str1);
				strcat(str0,str2);
				strcat(str0,str3);
				strcat(str0,str4);
				strcat(str0,str5);
				strcat(str0,str6);

				add_punter_data_history(punter->data, str0);
			}
			else if (jidengjiang2(lottery,Num) == 3)
			{
				//找到对应中奖者
				punter = find_char_in_common_link(punterHead, 
					(lottery->data).lottery->owner,
						match_punter_username);
				//更新余额
				(punter->data).punter->balance += (lottery->data).lottery->number * 100;
				//更新历史记录
				char str0[120] = "\0";
				sprintf(str0+0, "%d", (lottery->data).lottery->number);
				char str1[15] = "注期号\0";
				char str2[15] = "\0";
				sprintf(str2+0,"%d", issue);
				char str3[35] = "中3等奖了,每注奖金:\0";
				char str4[20] = "\0";
				sprintf(str4+0, "%d",100);
				char str5[10] = ",余额:";
				char str6[20] = "\0";
				sprintf(str6+0, "%11.2f",get_punter_data_balance(punter->data));

				strcat(str0,str1);
				strcat(str0,str2);
				strcat(str0,str3);
				strcat(str0,str4);
				strcat(str0,str5);
				strcat(str0,str6);

				add_punter_data_history(punter->data, str0);				
			}


		}
		//更改 lottery status
		(lottery->data).lottery->status = 1;
		
	}
	//更新 lotterytype 的 status和 award
	(lotterytype->data).lotterytype->status = 1;
	(lotterytype->data).lotterytype->award = award;
	return 1;

}


int jidengjiang2(CLnode* lottery, int* Num)
{
	int i = 0;
	int count = 0;
	for(i = 0; i < 6; i++)
	{
		if(Num[i] == (lottery->data).lottery->Num[i])
		{
			count++;
		}
	}
	if(4 == count)
	{
		return 3;
	}
	else if(5 == count)
	{
		return 2;
	}
	else if(6 == count)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 















