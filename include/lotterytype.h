#ifndef LOTTERYTYPE_H_
#define LOTTERYTYPE_H_


#include"common.h"
#include"commonlink.h"
//#include"lotterytype.h"
#include"lottery.h"
#include"punter.h"
#include"manager.h"
#include"notary.h"
//#include"control.h"
//#include"view.h"



typedef union uniondata Udata;
typedef struct punter_data Punter_data;

typedef struct lotterytype_data
{
	int type;
 	int issue;
 	int status; //1 表示 已开奖，0 表示未开奖
 	int winNum[10];// 初始化为 10 个 0;
 	double price;
 	int soldNum;
 	double pool;
 	double award;
 	int wins;
}Lotterytype_data;

Lotterytype_data* create_lotterytype_data(int type, double pool);

/*
	功能：匹配 Udata 中的期号与期号
	参数：共同体指针值域，与 期号
	返回值：match 0 , not matched -1
	function: match the issue of Udata with given issue
	arguments: Udata and the issue need checked
	return:match 0 , not matched -1
*/
int match_lotterytype_issue(Udata data,
		 int issue);
/*
	功能：匹配 Udata 中的类型与给的类型
	参数：共同体指针值域，与 类型
	返回值：match 0 , not matched -1
	function: match the type of Udata with given data
	arguments: Udata and the type need checked
	return:match 0 , not matched -1
*/
int match_lotterytype_type(Udata data,
		 int type);



/*
	功能：释放彩票类型的 UDATA
	参数：
	返回值：
	function: free the udata as lotterytype
	arguments:
	return:
*/
int free_lotterytype_data(Udata data);


int display_lotterytype_data(Udata data);




#endif