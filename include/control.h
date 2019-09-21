#ifndef CONTROL_H_
#define CONTROL_H_

#include"common.h"
#include"commonlink.h"
#include"lotterytype.h"
#include"lottery.h"
#include"punter.h"
#include"manager.h"
#include"notary.h"
#include"control.h"
#include"view.h"

typedef union uniondata Udata;
typedef struct punter_data Punter_data;
typedef struct commonlink CLnode;

/*
	此文件包含了所有通用的操作函数如读写，界面操作函数，登录注册
	以及彩民相关的操作函数

	彩民相关的操作函数，分为：彩民内部查询调整的函数，彩民购买彩票相关的函数
		两个 part
*/


//*************handler part***********************
/*
	功能：入口界面
	参数：punter，lottery,lotterytype 的表头
	返回值： 无
	function : entrance handler
	arguments: punterHead,lotteryhead,lotterytypeHead
	return:	None
*/
void entrance_handler(CLnode* punterHead, CLnode* lotteryHead,
					CLnode* lotterytypeHead);

/*
	功能：punter界面
	参数：，lotterytypehead， lottery的表头,punter
	返回值： 无
	function : punter handler
	arguments: punterHead
	return:	None
*/
void punter_menu_handler(CLnode* punter, CLnode* punterHead ,CLnode* lotterytypeHead, CLnode* lotteryHead);

/*
	功能：管理员界面
	参数：punter，lottery,lotterytype 的表头
	返回值：
	function: manager handler
	arguments:punterHead,lotteryhead,lotterytypeHead
	return:
*/
void manager_menu_handler(CLnode* punterHead, CLnode* lotterytypeHead);

/*
	功能：公证人界面
	参数：punter，lottery,lotterytype 的表头：
	返回值：
	function:notary handler
	arguments:punterHead,lotteryhead,lotterytypeHead
	return:
*/
void notary_menu_handler(CLnode* punterHead, CLnode* lotteryHead, CLnode* lotterytypeHead);












//******************regist and login part***************
/*
	功能： 彩民注册
	参数：punterlink 的表头
	返回值：1 成功，0 失败
	function: punter registing
	arguments: head of the link of punter.
	return: 1 for success , 0 for failure
*/
int regist_punter(CLnode* head);


/*
	功能：彩民登录
	参数：punterlink 的表头
	返回值： 1 成功
	function: punter login
	arguments: head of the punterlink
	return:	1 for success
*/
CLnode* login_punter(CLnode* head);

/*
	功能：管理员，公证人登录
	参数：无
	返回值：管理员登录成功 2， 公证人登录成功 3， 失败 0
	function: login manager and notary
	arguments: none
	return: manager login successed 2, notary 3, and failure for 1
*/
int login_manager_notary(void);



//********************彩民内部操作 part*********************
/*
	功能：展示彩民余额
	参数：彩民结点
	返回值：成功 1，失败 0
	function: show the balance of punter
	arguments: node of punter
	return: success 1, failure 0
*/
int show_punter_balance(CLnode* node);

/*
	功能：充值彩民余额
	参数：彩民结点
	返回值：成功 1，失败 0
	function: topup balance of punter
	arguments:the node of punter
	return: success 1, failure 0
*/
int topup_punter_balance(CLnode* node);

int withdraw_punter_balance(CLnode* node);

/*
	功能：修改彩民密码
	参数：彩民结点
	返回值：成功 1， 失败 0
	function: modify the password of punter
	arguments:node of punter
	return:success 1, failure 0
*/
int modify_punter_password(CLnode* node);

/*
	功能：打印历史记录
	参数：彩民结点
	返回值：成功 1，失败 0
	function:display the history record of punter
	arguments: node of punter
	return: success 1, failure 0
*/
int show_punter_history(CLnode* node);

/*
	功能：彩民注销，如果仍有未开奖彩票，不允许注销
	参数：彩民结点，彩民表头，单张彩票表头
	返回值：成功 1， 失败 0
	function: cancle the punter, 
		when there are lotteries remaining not drawed, 
		canclation is not allowed
	arguments: node of punter, head of punter link, 
		and the head of the lottery link
	return: success 1, failure 0
*/
int cancle_punter(CLnode* punter, CLnode* punterHead ,CLnode* lotteryHead);


//********************购买彩票 part*********************





/*
	功能：人工输入选号，第一类彩票
	参数：选号数组(输入前最好置为 0)
	返回值：成功 1，失败 0
	function: input the picknumber manuly, the type 1
	arguments: the int array of picknumber(better set 
		to be 0 before input)
	return: success 1, failure 0
*/
int get_lottery_type1_num(int *Num, double pool);

int get_lottery_type2_num(int *Num, double pool);

/*
	功能： 获得彩票类型，
	参数：none
	返回值：成功返回类型，失败返回 0
	function: get the type of lottery, manuly
	arguments: none
	return: success returning the type, failure returning 0
*/
int get_lottery_type(void);

/*
	功能： 获得彩票数量，
	参数：none
	返回值：成功返回数量，失败返回 0
	function: get the number of lottery, manuly
	arguments: none
	return: success returning the number, failure returning 0
*/
int get_buy_how_many(int type);


/*
	功能：购买彩票函数
	参数：彩票与彩票类型的表头，以及正在购买的彩民
	返回值：成功 1，失败 0
	function:buying handler
	arguments: head of lotterytype and lottery. And the punter who is buying.
	return:success 1, failure 0
*/
int buy_lottery(CLnode* lotterytypeHead, CLnode* lotteryHead,CLnode* punter);



/*
	功能：匹配中奖号码
	传入要匹配的彩票节点，Num是想要匹配的选号数组（这里是中间选号);
	len 为选号的个数
	匹配返回 0

	function: match the num of lottery with winNum
	len is the number of chosen number
	matched return 0
*/



int match_lottery_num(CLnode* lottery, int* Num, int len);

//******************** 读写 部分 *********************
/*
	载入三条链表和一些配置变量，从文件中，文件路径与文件名在 common.h 中
	load three links and content of config from files
	the path and filename are defined in common.h
*/
void get_data(CLnode* punterHead, CLnode* lotteryHead,
				 CLnode* lotterytypeHead);


/*
	将三条链表和一些配置变量写入文件中，文件路径与文件名在 common.h 中
	write three links and config value to files, 
	the path and filename are defined in common.h
*/
void write_data(CLnode* punterHead, CLnode* lotteryHead,
				 CLnode* lotterytypeHead);
















#endif









