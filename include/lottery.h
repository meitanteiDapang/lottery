#ifndef LOTTERY_H_
#define LOTTERY_H_


#include"common.h"
#include"commonlink.h"
#include"lotterytype.h"
//#include"lottery.h"
#include"punter.h"
#include"manager.h"
#include"notary.h"
//#include"control.h"
//#include"view.h"

typedef union uniondata Udata;
typedef struct punter_data Punter_data;
typedef struct commonlink CLnode;

typedef struct lottery_data
{
  int type;
  int issue;
  int number;//这一单的数量，大于等于 1，少于等于 5
  int status; //1 表示已兑奖，0 表示未兑奖
  int Num[10];
  char owner[NAME_SIZE];
  
}Lottery_data;


/*
	功能：创建单张彩票数据
	参数：彩票类型表头，彩票种类，注数，选号，拥有者用户名
	返回值：单张彩票的Udata 
	function:create a lottery udata
	arguments: lotterytypeHead, type of lottery, how many notes
		the number chosen, and username of the owner
	return: Udata of lottery
*/
Lottery_data* create_lottery_data(CLnode* lotterytypeHead
					,int type, int number,
				 int* Num, char* owner);


/*
	功能：释放 Udata
	参数：
	返回值：
	function: free the Udata as lottery
	arguments:
	return:
*/
int free_lottery_data(Udata data);




#endif


