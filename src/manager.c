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

extern int issue1_now;
extern int issue2_now;





int issue_lottery(CLnode* lotterytypeHead)
{
	print_tabs(6);
	printf("请输入你想发行哪种类型的彩票：");
	int type = 0;
	scanf("%d", &type);
	if(type > NUM_LOTTERYTYPE || type < 1)
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("不存在这种类型的彩票，回车返回管理员菜单");
		return 0;
	}

	double pool = 0.0;
	CLnode* p = find_int_in_common_link_back(lotterytypeHead, 
		type*MULT + get_issue_now(type) - 1, match_lotterytype_issue);
	if(NULL == p)
	{
		FLUSH;
		print_tabs(6);
		printf("这是第一个此种类型的彩票,回车继续");
	}
	else if(1 == (p->data).lotterytype->status)
	{
		FLUSH;
		print_tabs(6);
		printf("上次奖池将滚入此次奖池,回车继续");
	}
	else
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("上个此类型彩票未开奖，回车返回管理员菜单");
		return 0;
	}
	//更新奖池
	if(type == 1 && NULL != p)
	{
		pool = (p->data).lotterytype->pool + TYPE1POOL;
	}
	else if(type == 1 && NULL == p)
	{
		pool = TYPE1POOL;
	}
	else if(type == 2 && NULL != p)
	{
		pool = (p->data).lotterytype->pool + TYPE2POOL;
	}
	else if(type == 2 && NULL == p)
	{
		pool = TYPE2POOL;
	}	


	Lotterytype_data* new_data = create_lotterytype_data(type, pool);
	CLnode* new_node = create_common_link_node(new_data, 3);
	insert_common_link_node(lotterytypeHead, new_node);
	FLUSH;
	print_tabs(6);
	printf("发行%d类彩票完成,期号:%d ,奖池:%11.2f",type,
			(lotterytypeHead->previous->data).lotterytype->issue,pool);
	CONTINUE(",回车返回管理员菜单");

	return 1;
}


int print_punter_with_username(CLnode* punterHead)
{
	char username[NAME_SIZE] = "\0";
	print_tabs(6);
	printf("请输入你要查询的 username:");
	fgets(username, NAME_SIZE, stdin);
	if(username[strlen(username) - 1] == '\n')
	{
		username[strlen(username) - 1] = '\0';
	}
	CLnode* p = find_char_in_common_link(punterHead, username, match_punter_username);

	if(NULL == p)
	{
		print_tabs(6);
		CONTINUE("用户名不存在，回车返回");
		return 0;
	}
	
	print_tabs(6);
	print_stars(40);
	printf("\n");
	print_punter_data_title();
	print_tabs(6);
	display_punter_data(p->data);

	print_tabs(6);
	printf("以下为彩民历史记录\n");
	show_punter_history(p);
	return 1;
}


int print_punter_with_balance(CLnode* punterHead)
{
	double top = 0;
	double bottom = 0;
	print_tabs(6);
	printf("请依次输入你想查询余额区间的最小值与最大值:");
	scanf("%lf %lf", &bottom, &top);

	if(top < 0 || bottom < 0 || top < bottom)
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("最小值与最大值必须为非负数，且最小值要小于等于最大值,回车返回");
		return 0;
	}
	print_tabs(6);
	print_stars(42);
	printf("\n");
	//此函数已有
	print_punter_data_title();

	CLnode* p = punterHead;
	int punterLen = (punterHead->data).size;
	int i = 0;
	for(i = 0; i < punterLen; ++i)
	{
		p = p -> previous;
		double balance = (p->data).punter->balance;
		if(balance>=bottom && balance <= top)
		{
			print_tabs(6);
			display_punter_data(p->data);
		}
	}
	//CONTINUE("-----------------展示结束----------------\n");
	return 1;
}



int sort_punter(CLnode* punterHead)
{

	int ascending = -1;
	int flag = 1;
	while(flag)
	{
		print_tabs(6);
		printf("1 代表升序，0 代表降序,请输入:");	
		scanf("%d",&ascending);
		if(ascending == 1 )
		{
			FLUSH;
			print_tabs(6);
			CONTINUE("将升序排列，回车继续");
			flag = 0;
		}
		else if(ascending == 0)
		{
			FLUSH;
			print_tabs(6);
			CONTINUE("将降序排列，回车继续");
			flag = 0;
		}
		else
		{	
			print_tabs(6);
			CONTINUE("请输入合法数值，回车返回继续输入");
			flag = 1;
		}
	}

	return bubble_sort_common_link( punterHead, ascending, compare_punter_balance);
}


int get_issue_now(int type)
{
	if(type == 1)
	{
		return issue1_now;
	}
	else if(type == 2)
	{
		return issue2_now;
	}
	return -1;
}



void test_pro(void)
{
	int mode = 3;
	int number = 25;
	printf("请输入有几个球，以及每个球有多少个选择\n");
	scanf("%d %d", &mode, &number);

	srand((unsigned)time(NULL));
	printf("请输入总测试次数:");
	char win[6];
	//char Num[6];
	int n = 100000000;
	int pro1 = 0;
	int pro2 = 0;
	int pro3 = 0;
	int loser = 0;
	int i = 0;
	int j = 0;
	scanf("%d",&n);
	getchar();
	int res = 0;

	for(i = 0; i < mode; i++)
	{
		int s = 0;
	    
		s = rand()%(number) + 1;
		win[i] = s;
		//print_tabs(6);
		//printf("第%d个机选号为:%d\n",i,s);	
	}

	for(j = 0; j < n; j++)
	{
		res = 0;
		for(i = 0; i < mode; i++)
		{
			int s = 0;
		    
			s = rand()%(number) + 1;
			if(s == win[i])
			{
				res++;
			}
			
		}

		if(res == mode)
		{
			pro1++;
		}
		else if(res == mode - 1)
		{
			pro2++;
		}
		else if(res == mode - 2)
		{
			pro3++;
		}
		if(res == 0)
		{
			loser++;
		}


		if(j%10000==0)
		{
			printf("%d\n", j);
		}

	}
	


	printf("共%d,一：%d,二:%d,三:%d\n，一个没中:%d", n , pro1, pro2, pro3,loser);
	getchar();

}


























