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

CLnode* create_common_link_head(void)
{
	CLnode* head = (CLnode*) calloc(1,sizeof(CLnode));

	head->data.size = 0;
	head->previous = head;
	head->next = head;
	return head;
}


CLnode* create_common_link_node(void* data, int type)
{
	CLnode* node = (CLnode*) calloc(1,sizeof(CLnode));

	switch(type)
	{
		case 1:
			node->data.punter = data;
			break;
		case 2:
			node->data.lottery = data;
			break;
		case 3:
			node->data.lotterytype = data;
			break;
		default:
			printf("illegal type in create_common_link_node\n");
			return NULL;
	}
	node->previous = NULL;
	node->next = NULL;

	return node;
}


int insert_common_link_node(CLnode* head, CLnode* new)
{
	if(NULL == head || NULL == new)
	{
		printf("insert_common_link_node, NULL error");
		return 0;
	}
	CLnode* p = head->previous;
	new->previous = p;
	new->next = head;
	head->previous = new;
	p->next = new;
	head->data.size++;
	return 1;
}


CLnode* find_char_in_common_link(CLnode* head,
			char* des, int(*method)(Udata, char*))
{
	if(NULL == head)
	{
		//printf("find_char_in_common_link,NULL error\n");
		return NULL;
	}
	int len = head->data.size;
	if(len == 0)
	{
		//printf("find_char_in_common_link, blank link\n");
		return NULL;
	}
	int i = 0;
	CLnode* p = head->next;
	for(i = 0; i < len; i++)
	{
		if(method(p->data, des) == 0)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}


int match_char_with_common_node(CLnode* node,
			char* des, int (*method)(Udata, char*))
{
	if(NULL == node)
	{
		printf("match_char_with_common_node,NULL error\n");
		return 0;
	}
	if(method(node->data, des) == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}

}

CLnode* find_int_in_common_link_back(CLnode* head, int des,
			 int(*method)(Udata, int))
{
	if(NULL == head)
	{
		printf("find_int_in_common_link,NULL error\n");
		return NULL;
	}
	int len = head->data.size;
	if(len == 0)
	{
		printf("find_int_in_common_link, blank link\n");
		return NULL;
	}
	int i = 0;
	CLnode* p = head->previous;
	for(i = 0; i < len; i++)
	{
		if(method(p->data, des) == 0)
		{
			return p;
		}
		p = p->previous;
	}
	return NULL;	
}



int match_int_with_common_node(CLnode* node,
			int des, int (*method)(Udata, int*))
{
	if(NULL == node)
	{
		printf("match_char_with_common_node,NULL error\n");
		return 0;
	}
	if(method(node->data, &des) == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}

}



int exchange_common_node_with_next(CLnode* p)
{

	CLnode* temp1 = p->next;

	p->previous->next = temp1;
	temp1->previous = p->previous;
	p->next = temp1->next;
	temp1->next->previous = p;
	temp1->next = p;
	p->previous = temp1;

	return 1;
}


int bubble_sort_common_link(CLnode* head, int ascending , int(*method)(CLnode*, CLnode*))
{
	if(NULL == head)
	{
		printf("bubble_sort_common_link, NULL error");
		return 0;
	}
	else if(head == head->next || head == head->next->next)
	{
		print_tabs(6);
		CONTINUE("空链表或唯一数据，无法冒泡排序，回车返回");
		return 0;
	}
	int len = (head->data).size;
	int i = 0;
	int j = 0;
	int k = 0;
	CLnode* p = head;
	for(i = 1; i <= len - 1; ++i)
	{
		for(j = 1; j <= len -i; ++j)
		{
			p = head;
			for(k = 1; k <=j; k++)
			{
				p = p->next;
			}
			if(ascending)
			{
				if(method(p, p->next)>0)
				{
					exchange_common_node_with_next(p);
				}
			}
			else
			{
				if(method(p, p->next)<0)
				{
					exchange_common_node_with_next(p);
				}
			}
		}
	}
	return 1;
}




int display_common_link(CLnode* head, int(*method)(Udata))
{
	int len = (head->data.size);
	int i = 0;
	CLnode* p = head->next;
	for(i = 0; i < len; ++i)
	{
		print_tabs(6);
		method(p->data);
		p = p->next;
	}
	return 1;
}

int delete_common_link_node(CLnode* node, CLnode* head)
{
	//此项目只涉及到 punter 的删除，所以这边 type 恒为 1
		//若有需要删除其他类型的节点，修改此函数传参;
	//int type = 1;
	if(NULL == node)
	{
		CONTINUE("无法删除针对空指针删除节点");
		return 0;
	}
	CLnode* temp = node;
	node->previous->next = temp->next;
	node->next->previous = temp->previous;
	free((node->data).punter);
	free(node);
	node = NULL;
	temp = NULL;

	(head->data).size -= 1;
	return 1;
}










































int destory_common_link(CLnode* head, int (*method)(Udata))
{
	if(NULL == head)
	{
		printf("destory_common_link, NULL error");
		return 0;
	}
	int len = head->data.size;
	CLnode* p = head->next;
	int i = 0;
	for(i = 0; i < len; ++i)
	{
		CLnode* q = p->next;
		method(p->data);
		free(p);
		p = q;
	}
	free(head);
	return 1;
}






















































