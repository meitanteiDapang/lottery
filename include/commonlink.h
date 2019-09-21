#ifndef COMMONLINK_H_
#define COMMONLINK_H_

#include"common.h"
//#include"commonlink.h"
#include"lotterytype.h"
#include"lottery.h"
#include"punter.h"
//#include"manager.h"
//#include"notary.h"
//#include"control.h"
//#include"view.h"



typedef union uniondata
{
	//值域存放不同类型的 data
	Punter_data* punter;
	Lottery_data* lottery;
	Lotterytype_data* lotterytype;

	//头结点存放链表大小
	int size;
}Udata;


typedef struct commonlink
{
	Udata data;
	struct commonlink* previous;
	struct commonlink* next;
}CLnode;


/*
	功能：创建头结点
	参数：无
	返回值：返回头结点指针
	function: create head
	arguments:	none
	return: the pointer of head
*/
CLnode* create_common_link_head(void);


/*
	功能： 创建通用链表结点
	参数：data: 值域地址；type:1 代表 punter,2 代表 loteery
			, 3 代表 lotterytype
	返回值：返回结点
	function: create common link node
	arguments: data: address of value field; type: 
		1 for punter, 2 for lottery, 3 for lotterytype
	return: the address of new node
*/
CLnode* create_common_link_node(void* data, int type);


/*
	功能：插入新结点，尾插法
	参数：链表头与需要插入的新结点
	返回值： 1 表示插入成功，0 表示失败
	function: insert new node by tail inserting
	arguments:	the head of link and the new node need insert
	return:1 for success, 0 for failure
*/
int insert_common_link_node(CLnode* head, CLnode* new);



/*
	功能：查询链表中是否存在指定 char 型信息
	参数：表头，char*型目标，比较方法，因为 值域是 Udata，所以
	需要传入一个 Udata 与 char
	返回值： 找到返回地址，失败返回 NULL
	function:is the des string in the link
	arguments: head, char* the string needed checking, and compare
	method, wee need match showing 0
	return: success: address, failure: NULL
*/
CLnode* find_char_in_common_link(CLnode* head,
			char* des, int(*method)(Udata, char*));


/*
	功能：查询节点是否存在指定 char* 型信息
	参数：node: 需要查询的节点。   des:需要匹配的字符串
		method:匹配方法，成功返回 0
	返回值：0 匹配，-1 不匹配
	function: verify that  the string is in the node or not,
	with given method
	arguments:node: needed check.  des: string needed match
		method: method for matching, return 0 for success
	return:0 match, -1 not match
*/
int match_char_with_common_node(CLnode* node,
			char* des, int (*method)(Udata, char*));



/*
	功能：查询链表中是否存在指定 int 型信息
	参数：表头，int型目标，匹配方法，成功返回 0
	返回值： 找到返回地址，失败返回 NULL
	function:is the des int in the link
	arguments: head, des the target, and compare
	method, matching returns 0
	return: success: address, failure: NULL
*/
CLnode* find_int_in_common_link_back(CLnode* head, int des,
			 int(*method)(Udata, int));

/*
	功能：查询节点是否存在指定 int 型信息
	参数：node: 需要查询的节点。   des:需要匹配的整型数据
		method:匹配方法，成功返回 0
	返回值：0 匹配，-1 不匹配
	function: verify that   the int is in the node or not,
	with given method
	arguments:node: needed check.  des: int needed match
		method: method for matching, return 0 for success
	return:0 match, -1 not match
*/
int match_int_with_common_node(CLnode* node,
			int des, int (*method)(Udata, int*));


/*
	功能：将链表排序 冒泡
	参数：head:你想排序的链表的表头， ascendIng:1 代表升序，0 代表降序
	method：如何比较节点大小的方法,当第一个节点比较大时，返回正数
	返回值：成功 1，失败 0
	function:  sort the common link by bubble sort
	arguments: head: the head of the common link u want to sort
	ascending: 1 for ascending , 0 for descending
	method: method for comparing the node, 
		return postive number when the first node is bigger
	返回值： success 1, failure 0 
*/
int bubble_sort_common_link(CLnode* head, int ascending, int(*method)(CLnode*, CLnode*));


/*
	功能：打印链表信息
	参数：传入表头与打印方法
	返回值：成功 1， 失败 0
	function: print the data in the common link
	arguments: the link head and the method of printing
	return:success 1, failure 0
*/
int display_common_link(CLnode* head, int(*method)(Udata));


/*
	功能：删除链表中的一个节点
	参数：传入要删除的节点及其存在的表头
	返回值：成功 1. 失败 0
	function: delete a node in common link
	arguments: the node u want to delete and the head of the node
	return: success 1, failure 0
*/
int delete_common_link_node(CLnode* node, CLnode* head);



/*
	功能：销毁通用链表
	参数：传入表头与对应 Udata 的销毁方法
	返回值：成功 1， 失败 0
	function:  destory common link
	arguments: the link head and the method for destory Udata
	return:success 1, failure 0
*/
int destory_common_link(CLnode* head, int(*method)(Udata));














































#endif