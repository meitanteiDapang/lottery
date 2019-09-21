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

int main(void)
{
	CLnode* punterHead = create_common_link_head();
	CLnode* lotteryHead = create_common_link_head();
	CLnode* lotterytypeHead = create_common_link_head();
	get_data(punterHead, lotteryHead, lotterytypeHead);
	entrance_handler(punterHead, lotteryHead, lotterytypeHead);



	write_data(punterHead, lotteryHead, lotterytypeHead);

	destory_common_link(punterHead, free_punter_data);
	destory_common_link(lotteryHead, free_lottery_data);
	destory_common_link(lotterytypeHead, free_lotterytype_data);

	CONTINUE("回车退出程序 ");
	return 0;
}

int main1(void)
{

	return 0;
}