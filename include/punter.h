#ifndef PUNTER_H_
#define PUNTER_H_

#include"common.h"
#include"commonlink.h"
#include"lotterytype.h"
#include"lottery.h"
//#include"punter.h"
#include"manager.h"
#include"notary.h"
//#include"control.h"
//#include"view.h"


typedef union uniondata Udata;

typedef struct punter_data
{
 	
	char username[NAME_SIZE];//账号
 	char password[NAME_SIZE];//密码
 	double balance;          //金额
 	char history[HISTORY_NUM][120];     //历史记录信息
}Punter_data;


/*
	功能：创建 punter_data
	参数：punter_data 的全部成员
	返回值：data 的地址
	function: create punter_data
	arguments: the members of punter_data
	return: address of data
*/
Punter_data* create_punter_data(char* username, 
	char* password, double balance, char (*history)[50]);



/*
	功能：查询用户名是否匹配
	参数：传入 Udata，和 与其匹配的 username
	返回值：1 匹配， 0 不匹配
	function: query that  username input are same to
		one of punter_data
	arguments: Udata: the data u want to compare; username
	 	 waiting for being checked
	return: 0 matched, -1 not matched 
*/
int match_punter_username(Udata data,
		 char* username);

/*
	功能：查询密码是否匹配
	参数：传入 Udata，和 与其匹配的 password
	返回值：1 匹配， 0 不匹配
	function: query that   password input are same to
		one of punter_data
	arguments: Udata: the data u want to compare; password
	 	 waiting for being checked
	return: 0 matched, -1 not matched 
*/
int match_punter_password(Udata data,
		 char* password);


/*
	功能：获得彩民余额
	参数：传入 共同体指针值域
	返回值：余额
	function: get balance of punter
	arguments: union Udata
	return: balance
*/
double get_punter_data_balance(Udata data);

/*
	功能：改变彩民余额
	参数：传入共同体指针值域，和更改的数值，负数表示减少
	返回值：成功 1，失败 0
	function:change the balance of punter
	arguments: union Udata, and the change of balance, negative
	number meaning minus
	return: success 1, failure 0
*/
int change_punter_data_balance(Udata data, double change);

/*
	功能：获得彩民账户名
	参数：传入 共同体指针值域
	返回值：账户名
	function: get username of punter
	arguments: union Udata
	return: username
*/
char* get_punter_data_username(Udata data);

/*
	功能：获得彩民密码
	参数：传入 共同体指针值域
	返回值：余额
	function: get password of punter
	arguments: union Udata
	return: password
*/
char* get_punter_data_password(Udata data);

/*
	功能：改变彩民密码
	参数：传入共同体指针值域，和新密码
	返回值：成功 1，失败 0
	function:change the password of punter
	arguments: union Udata, and new password
	return: success 1, failure 0
*/
int change_punter_data_password(Udata data, char* new);

/*
	功能：打印账户与余额
	参数：共同体指针值域
	返回值：成功 1，失败 0
	function: print the username and balance
	arguments: Udata
	return: success 1 , failure 0
*/
int display_punter_data(Udata data);

/*
	功能：打印指定的第几条历史记录
	参数：Udata, 和第几条
	返回值：历史记录 字符串
	function:print the which(th) history 
	arguments: Udata, and which one(from 0 to HISTORY_NUM)
	return: the string of history record
*/
char* get_punter_data_history(Udata data, int which);

/*
	功能：增加一条历史记录
	参数：共同体指针值域，与需要添加的历史记录字符串
	返回值：成功 1， 失败 0
	function: add a new history record
	arguments: Udata and the new history record (char*)
	return: 成功 1， 失败 0
*/
int add_punter_data_history(Udata data, char* change);


/*
	功能：交换节点与其下一个节点的位置
	参数：参与交换的节点的前面那个
	返回值：成功 1， 失败 0
	function: exchange postions of a node and the node after it
	argument: the node
	return: success 1, failure 0
*/
int exchange_common_node_with_next(CLnode* p);


/*
	功能：比较两个彩民的余额
	参数：两个彩民结点
	返回值：彩民 1 比彩民 2 多多少
	function: compare the balance of 
	arguments: two punter nodes
	return: the number balance of punter1 minus balance of punter2
*/
int compare_punter_balance(CLnode* punter1, CLnode* punter2);
















/*
	释放代表彩民的 Udata
	free the memory of punter Udata 
*/
int free_punter_data(Udata data);




























#endif


