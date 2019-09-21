#ifndef MANAGER_H_
#define MANAGER_H_

#include"common.h"
#include"commonlink.h"
#include"lotterytype.h"
#include"lottery.h"
#include"punter.h"
//#include"manager.h"
#include"notary.h"
#include"control.h"
#include"view.h"

/*
typedef struct manager_data
{
  char username[NAME_SIZE];
  char password[NAME_SIZE];

}Manager_data;
*/
typedef union uniondata Udata;
typedef struct punter_data Punter_data;
typedef struct commonlink CLnode;

void test_pro(void);


/*
	功能：发行彩票
	参数：彩票类型头
	返回值：成功 1，失败 0
	function:issue lottery handler
	arguments: head of lotterytype
	return: success 1, failure 0
*/
int issue_lottery(CLnode* lotterytypeHead);


/*
	功能：询问 username，打印彩民信息,包括历史记录
	参数: 彩民的表头
	返回值: 成功1， 失败 0
	function: the function will ask user for a username
		and print the information of punter matching the username
		also print the history record
	arguments: the head of punter link
	return: success 1, failure 0 
*/
int print_punter_with_username(CLnode* punterHead);


/*
	功能：询问查询的余额区间，打印其中的彩民信息
	参数 彩民的表头
	返回值： 成功 1， 失败0
	function: the function wall ask user for a section of balance,
		and print the information of punters whose balance are in the balance
	return: success 1, failure 0
*/
int print_punter_with_balance(CLnode* punterHead);

/*
	处理彩民排序
	punter sorting handler
*/
int sort_punter(CLnode* punterHead);

int get_issue_now(int type);








































#endif