#ifndef NOTARY_H_
#define NOTARY_H_

#include"common.h"
#include"commonlink.h"
#include"lotterytype.h"
#include"lottery.h"
#include"punter.h"
#include"manager.h"
//#include"notary.h"
#include"control.h"
#include"view.h"

typedef union uniondata Udata;
typedef struct punter_data Punter_data;
typedef struct commonlink CLnode;

/*
typedef struct notary_data
{
	char username[NAME_SIZE];
 	char password[NAME_SIZE];

}Notary_data;
*/



/*
	功能：开奖总函数
	参数：
	返回值：成功1，失败 0
	function: the main function of issuing lotterying
	arguments:
	return: success 1, failure 0
*/
int draw_lottery(CLnode* punterHead,
		 CLnode* lotteryHead, CLnode* lotterytypeHead);


/*
	功能：类型 1 彩票开奖函数
	参数：
	返回值：成功 1，失败 0
	function:type 1 lottery issuing 
	arguments:
	return:success 1, failure 0
*/
int draw_lotterytype1(CLnode* punterHead,
		 CLnode* lotteryHead, CLnode* lotterytypeHead);

/*
	功能：类型 2 彩票开奖函数
	参数：可机选和手选
	返回值：成功 1，失败 0
	function:type 2 lottery issuing 
	arguments: random get winNum or input manuly
	return:success 1, failure 0
*/
int draw_lotterytype2(CLnode* punterHead,CLnode* lotteryHead,
			CLnode* lotterytypeHead);




int jidengjiang2(CLnode* lottery, int* Num);

























#endif