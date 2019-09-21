#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <unistd.h>
//#include <curses.h>

#include"common.h"
#include"commonlink.h"
#include"lotterytype.h"
#include"lottery.h"
#include"punter.h"
#include"manager.h"
#include"notary.h"
#include"control.h"
#include"view.h"


void print_stars(int len)
{
	int i = 0;
	for(;i < len; ++i)
	{
		printf("*");
	}
}

void print_tabs(int len)
{
	int i = 0;
	for(;i < len; ++i)
	{
		printf("\t");
	}
}

void print_spaces(int len)
{
	int i = 0;
	for(;i < len; ++i)
	{
		printf(" ");
	}
}

void show_entrance_menu(void)
{
	printf("\n\n\n\n\n");

	print_tabs(6);
	print_stars(1);
	printf("****🐷****彩****票*🐷*系****统****🐷****");
	print_stars(1);	
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("1.彩民登录");//完成
	print_spaces(23);
	print_stars(1);
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("2.彩民注册");//完成
	print_spaces(23);
	print_stars(1);
	printf("\n");


	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("3.管理员,公证员操作");//完成
	print_spaces(14);
	print_stars(1);
	printf("\n");


	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("0.退出");//完成
	print_spaces(27);
	print_stars(1);
	printf("\n");


	print_tabs(6);
	print_stars(1);
	print_stars(40);
	//printf("");
	print_stars(1);
	printf("\n");

}


void show_punter_menu(void)
{
	printf("\n\n\n\n\n");

	print_tabs(6);
	print_stars(1);
	print_stars(10);
	printf("彩****民*🐗*菜****单");
	print_stars(10);
	print_stars(1);	
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("1.购买彩票");//完成
	print_spaces(23);
	print_stars(1);
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("2.查看余额");//完成
	print_spaces(23);
	print_stars(1);
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("3.充值");//完成
	print_spaces(27);
	print_stars(1);
	printf("\n");	

	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("4.查看%d条历史记录", HISTORY_NUM);//完成
	print_spaces(15);
	print_stars(1);
	printf("\n");	
	

	print_tabs(6);
	print_stars(1);
	print_tabs(1);	
	printf("5.修改密码");//完成
	print_spaces(23);
	print_stars(1);
	printf("\n");	


	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("6.注销账户");//完成
	print_spaces(23);
	print_stars(1);
	printf("\n");	

	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("7.取款");//完成
	print_spaces(27);
	print_stars(1);
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("8.展示彩票规则");//完成
	print_spaces(19);
	print_stars(1);
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("0.返回上一级");
	print_spaces(21);
	print_stars(1);
	printf("\n");	

	print_tabs(6);
	print_stars(1);	
	print_stars(41);
	printf("\n");

}

void show_manager_menu(void)
{
	printf("\n\n\n\n\n");

	print_tabs(6);
	print_stars(1);
	print_stars(10);
	printf("管****理*🐖*菜****单");
	print_stars(11);
	printf("\n");


	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("1.展示所有彩民信息");//完成
	print_spaces(15);
	print_stars(1);
	printf("\n");


	print_tabs(6);
	print_stars(1);
	print_tabs(1);	
	printf("2.按账号查询彩民信息");//完成
	print_spaces(13);
	print_stars(1);
	printf("\n");


	print_tabs(6);
	print_stars(1);
	print_tabs(1);	
	printf("3.按余额区间查询彩民信息");//完成
	print_spaces(9);
	print_stars(1);
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);	
	printf("4.按余额排序彩民信息");//完成
	print_spaces(13);
	print_stars(1);
	printf("\n");


	print_tabs(6);
	print_stars(1);
	print_tabs(1);	
	printf("5.发行彩票");//完成
	print_spaces(23);
	print_stars(1);
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);	
	printf("6.查看所有彩票类型信息");//完成
	print_spaces(11);
	print_stars(1);
	printf("\n");	

	print_tabs(6);
	print_stars(1);
	print_tabs(1);	
	printf("7.测试概率");//完成
	print_spaces(23);
	print_stars(1);
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("0.返回上一级");
	print_spaces(21);
	print_stars(1);
	printf("\n");

	print_tabs(6);
	print_stars(1);	
	print_stars(41);
	printf("\n");

}

void show_notary_menu(void)
{
	printf("\n\n\n\n\n");

	print_tabs(6);
	print_stars(1);	
	print_stars(10);
	printf("公****证****菜****单");
	print_stars(10);
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("1.开奖");//完成
	print_spaces(27);
	print_stars(1);	
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);	
	printf("6.查看所有彩票类型信息");//完成
	print_spaces(11);
	print_stars(1);
	printf("\n");

	print_tabs(6);
	print_stars(1);
	print_tabs(1);
	printf("0.返回上一级");
	print_spaces(21);
	print_stars(1);
	printf("\n");
	
	print_tabs(6);
	print_stars(1);
	print_stars(41);
	printf("\n");

}

void view_QR(void)
{
	FILE *fp1 = fopen("qr.txt", "r");

	int buff = 0;

	
	while(1)
	{
		buff = fgetc(fp1);
		if(feof(fp1))
		{
			break;
		}
		fprintf(stdout,"%c",buff);
	}
	


	fclose(fp1);

	fp1 = NULL;

}


void print_punter_data_title(void)
{
	print_tabs(6);
	printf("用户名\t\t金额\n");
}


void print_lotterytype_data_title(void)
{
	print_tabs(6);
	printf("类型\t期号\t是否开奖\t中奖号\t\t\t单价\t销售量\t每注奖金\t中奖注数\n");
}

void show_lottery_rule(void)
{
	print_tabs(6);
	printf("类型 1：杨中豪彩票\n");
	print_tabs(6);
	printf("单价：2,单次奖池:100\n");
	print_tabs(6);
	printf("共 3 个选号，0-9，全部选中者平分奖池,无人中奖，奖金滚入下一期\n");
	printf("\n\n");

	print_tabs(6);
	printf("类型 2：超级彩票\n");
	print_tabs(6);
	printf("单价：2，单次奖池：500000\n");
	print_tabs(6);
	printf("共 6 个选号，1-25，三等奖匹配 4 个号码，获得 10 元\n");
	print_tabs(6);
	printf("二等奖匹配 5 个号码，获得 1000 元，1 等奖匹配 6 个号码，平分奖池\n");			


	print_tabs(6);
	CONTINUE("回车返回")

}

































