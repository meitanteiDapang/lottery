#ifndef VIEW_H_
#define VIEW_H_

#include"common.h"
#include"commonlink.h"
#include"lotterytype.h"
#include"lottery.h"
#include"punter.h"
#include"manager.h"
#include"notary.h"
#include"control.h"
#include"view.h"



/*
	功能：展示入口菜单
	参数：无
	返回值：无
	function :show entrance menu
	arguments: none
	return:	none
*/
void show_entrance_menu(void);


void print_stars(int len);
void print_tabs(int len);
/*
	展示彩民菜单
	show punter menu；
*/
void show_punter_menu(void);

void show_manager_menu(void);

void show_notary_menu(void);

void view_QR(void);

void print_punter_data_title(void);


void print_lotterytype_data_title(void);
void show_lottery_rule(void);

#endif


