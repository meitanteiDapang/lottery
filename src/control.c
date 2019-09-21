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

void entrance_handler(CLnode* punterHead, CLnode* lotteryHead,
					CLnode* lotterytypeHead)
{
	if(NULL == punterHead || NULL == lotteryHead || NULL == lotterytypeHead)
	{
		return;
	}
	int choice = 0;
	int flag = 1;
	while(flag)
	{
		system("clear");
		show_entrance_menu();

		print_tabs(6);
		printf("请输入你的选择:");
		scanf("%d", &choice);
		FLUSH;

		print_tabs(6);
		print_stars(42);
		printf("\n");
		int road = 0;
		int temp = 0;
		CLnode* punter = NULL;
		switch(choice)
		{
			case 1:
			{
				punter = login_punter(punterHead);
				if(NULL != punter)
				{
					road = 1;
				}
				break;
			}
			case 2:
				regist_punter(punterHead);
				break;
			case 3:
				temp = login_manager_notary();
				if(2 == temp)
				{
					road = 2;
				}
				else if( 3 == temp)
				{
					road = 3;
				}
				break;
			case 0:
				flag = 0;
				break;
			default:
				print_tabs(6);
				CONTINUE("输入错误，请回车返回");
				break;
		}

		//去往不同地方界面，1 去往彩民菜单，2 去往管理员 3. 去往公证人
		if(road == 1)
		{
			//登录成功，进入punter menu
			punter_menu_handler(punter, punterHead, lotterytypeHead, lotteryHead);
		}
		else if(road == 2)
		{
			manager_menu_handler(punterHead, lotterytypeHead);
		}
		else if(road == 3)
		{
			notary_menu_handler(punterHead, lotteryHead, lotterytypeHead);
		}
		else
		{
			road = 0;
		}
	}

}


void punter_menu_handler(CLnode* punter, CLnode* punterHead, CLnode* lotterytypeHead, CLnode* lotteryHead)
{
	if(NULL == punter || NULL == punterHead || NULL == lotterytypeHead || NULL == lotteryHead)
	{
		return;
	}
	int choice = 0;
	int flag = 1;
	while(flag)
	{
		system("clear");
		show_punter_menu();
		print_tabs(6);	
		printf("请输入你的选择:");
		scanf("%d", &choice);
		FLUSH;

		print_tabs(6);
		print_stars(42);
		printf("\n");
		int road = 0;
		switch(choice)
		{
			case 1:
				buy_lottery(lotterytypeHead, lotteryHead, punter);
				break;
			case 2:
				show_punter_balance(punter);
				break;
			case 3:
				topup_punter_balance(punter);
				break;
			case 4:
				show_punter_history(punter);
				break;
			case 5:
				if(0==modify_punter_password(punter))
				{
					road = 5;
				}
				break;
			case 6:
				if(1 == cancle_punter(punter,punterHead,lotteryHead))
				{
					return;
				}
				break;
			case 7:
				withdraw_punter_balance(punter);
				break;
			case 8:
				show_lottery_rule();
				break;
			case 0:
				flag = 0;
				break;
			default:
				print_tabs(6);
				CONTINUE("输入错误，请回车返回");
				break;
		}
		if(road == 5)
		{
			return;
		}

	}
}


void manager_menu_handler(CLnode* punterHead ,CLnode* lotterytypeHead)
{
	if(NULL == punterHead || lotterytypeHead == NULL)
	{
		return;
	}
	int choice = 0;
	int flag = 1;
	while(flag)
	{
		system("clear");
		show_manager_menu();
		print_tabs(6);
		printf("请输入你的选择:");
		scanf("%d", &choice);
		FLUSH;

		print_tabs(6);
		print_stars(42);
		printf("\n");
		//int road = 0;
		switch(choice)
		{
			case 1:
				print_punter_data_title();
				display_common_link(punterHead, display_punter_data);
				print_tabs(6);
				CONTINUE("-----展示完成-----");
				break;
			case 2:
				print_punter_with_username(punterHead);
				print_tabs(6);
				CONTINUE("-----展示完成-----");
				break;
			case 3:
				print_punter_with_balance(punterHead);
				FLUSH;
				print_tabs(6);
				CONTINUE("-----展示完成-----");
				break;
			case 4:
				if(1 == sort_punter(punterHead))
				{
					print_tabs(6);
					CONTINUE("----排序完成-----")
				}
				break;
			case 5:
				issue_lottery(lotterytypeHead);
				break;
			case 6:
				print_lotterytype_data_title();
				display_common_link(lotterytypeHead, display_lotterytype_data);
				print_tabs(6);
				CONTINUE("--------打印完成，回车继续----------");
				break;
			case 7:
				test_pro();
				break;
			case 0:
				flag = 0;
				break;
			default:
				print_tabs(6);
				CONTINUE("输入错误，请回车返回");
				break;
		}
	}
}

void notary_menu_handler(CLnode* punterHead, CLnode* lotteryHead, CLnode* lotterytypeHead)
{
	if(NULL == punterHead || NULL == lotteryHead || NULL == lotterytypeHead)
	{
		return;
	}
	int choice = 0;
	int flag = 1;
	while(flag)
	{
		system("clear");
		show_notary_menu();
		print_tabs(6);
		printf("请输入你的选择:");
		scanf("%d", &choice);
		FLUSH;

		print_tabs(6);
		print_stars(42);
		printf("\n");
		//int road = 0;
		switch(choice)
		{
			case 1:
				draw_lottery(punterHead, lotteryHead, lotterytypeHead);
				break;
			//case 2:
			//	break;
			//case 3:
			//	break;
			case 6:
				print_lotterytype_data_title();
				display_common_link(lotterytypeHead, display_lotterytype_data);
				print_tabs(6);
				CONTINUE("--------打印完成，回车继续----------");
				break;
			case 0:
				flag = 0;
				break;
			default:
				print_tabs(6);
				CONTINUE("输入错误，请回车返回");
				break;
		}
	}
}



int regist_punter(CLnode* head)
{
	if(NULL == head)
	{
		return 0;
	}
	char username[NAME_SIZE] = "\0";
	char password1[NAME_SIZE] = "\0";
	char password2[NAME_SIZE] = "\0";
	double balance = 0.0;
	char history[HISTORY_NUM][50] = {{'\0'}};

	int flag = 1;
	while(flag)
	{
		print_tabs(6);
		printf("请输入账户,少于%d个字符:", NAME_SIZE-1);
		fgets(username, NAME_SIZE, stdin);
		if(username[strlen(username) - 1] == '\n')
		{
			username[strlen(username) - 1] = '\0';
		}
		else
		{
			FLUSH;
		}

		if(strlen(username) == 0)
		{
			print_tabs(6);
			CONTINUE("不能为空,请回车返回\n");
			return 0;
		}

		if(NULL != find_char_in_common_link(head, username, match_punter_username))
		{
			print_tabs(6);
			CONTINUE("账户名已经存在，请回车返回\n");
			return 0;
		}
		else
		{
			flag = 0;
		}
	}

	flag = 1;
	while(flag)
	{
		print_tabs(6);
		printf("请输入密码,少于%d个字符:", NAME_SIZE-1);
		get_password(password1);
		print_tabs(6);
		printf("请再输入密码,少于%d个字符:", NAME_SIZE-1);
		get_password(password2);

		if(strlen(password1) == 0 || strlen(password2) == 0)
		{
			print_tabs(6);
			CONTINUE("不能为空,请回车返回\n");
			return 0;
		}

		if(strcmp(password1,password2) == 0)
		{
			flag = 0;
		}
		else
		{
			print_tabs(6);
			CONTINUE("密码不一样哦，请回车返回");
		}
	}
	//确定验证码
	if(identifyCode() == 0)
	{
		print_tabs(6);
		CONTINUE("验证码错误，回车返回");
		return 0;
	}
	else
	{
		print_tabs(6);
		CONTINUE("验证码验证成功，回车继续");
	}

	Punter_data* data = create_punter_data(username,
							password1,balance,history);
	CLnode* node = create_common_link_node(data, 1);
	insert_common_link_node(head, node);
	print_tabs(6);
	CONTINUE("注册成功，请回车返回");


	return 1;
}


CLnode* login_punter(CLnode* head)
{
	if(NULL == head)
	{
		return 0;
	}
	char username[NAME_SIZE] = "\0";
	char password[NAME_SIZE] = "\0";
	int flag = 1;
	CLnode *p = NULL;
	while(flag>0&& flag <= 3)
	{
		print_tabs(6);
		printf("请输入账户名:");
		fgets(username, NAME_SIZE, stdin);
		if(username[strlen(username) - 1] == '\n')
		{
			username[strlen(username) - 1] = '\0';
		}
		else
		{
			FLUSH;
		}
		print_tabs(6);
		printf("请输入密码");
		get_password(password);

		if(identifyCode() == 0)
		{
			print_tabs(6);
			CONTINUE("验证码错误，回车返回");
			return 0;
		}

		p = find_char_in_common_link(head, username,
						 match_punter_username);

		if(p != NULL)
		{
			if(match_char_with_common_node(p, 
				password, match_punter_password) == 0)
			{
				flag = -1;
				print_tabs(6);
				CONTINUE("Login done,回车继续");
			}
			else
			{
				print_tabs(6);
				CONTINUE("Wrong password");
			}
		}
		else
		{
			print_tabs(6);
			CONTINUE("用户名不存在,回车返回");
		}
		++flag;
	}
	if(flag > 3)
	{
		print_tabs(6);
		CONTINUE("三次机会耗尽，回到主菜单")
		return NULL;
	}
	return p;
}

int login_manager_notary(void)
{
	char admin_name[NAME_SIZE] = ADMIN_NAME;
	char admin_psw[NAME_SIZE] = ADMIN_PSW;
	char notary_name[NAME_SIZE] = NOTARY_NAME;
	char notary_psw[NAME_SIZE] = NOTARY_PSW;

	char username[NAME_SIZE] = "\0";
	char password[NAME_SIZE] = "\0";
	int flag = 1;
	while(flag)
	{
		print_tabs(6);
		printf("请输入管理员/公证人账户名:");
		fgets(username, NAME_SIZE, stdin);
		if(username[strlen(username) - 1] == '\n')
		{
			username[strlen(username) - 1] = '\0';
		}
		else
		{
			FLUSH;
		}

		print_tabs(6);
		printf("请输入密码:");
		get_password(password);

		if(identifyCode() == 0)
		{
			print_tabs(6);
			CONTINUE("验证码错误，回车返回");
			return 0;
		}

		if(strcmp(admin_name,username) ==0)
		{
			if(strcmp(admin_psw, password) == 0)
			{
				flag = 0;
				print_tabs(6);
				CONTINUE("Login succeed, 回车继续");
				return 2;
			}
			else
			{
				print_tabs(6);
				CONTINUE("Wrong password,回车返回");
				return 0;
			}
		}
		else if(strcmp(notary_name, username) == 0)
		{
			if(strcmp(notary_psw, password) == 0)
			{
				flag = 0;
				print_tabs(6);
				CONTINUE("Login done，回车继续\n");
				return 3;
			}
			else
			{
				print_tabs(6);
				CONTINUE("Wrong password\n");
				return 0;
			}
		}
		else
		{
			print_tabs(6);
			CONTINUE("Not existed username\n");
			return 0;
		}
	}
	return 0;
}





//****************punter part********************************
int show_punter_balance(CLnode* node)
{
	if(NULL == node)
	{
		return 0;
	}
	double balance = get_punter_data_balance(node->data);
	print_tabs(6);
	printf("%s,您的余额为%11.2f,", get_punter_data_username(node->data),
									 balance);
	
	CONTINUE("请回车继续");
	return 1;
}


int topup_punter_balance(CLnode* node)
{
	if(NULL == node)
	{
		return 0;
	}
	double change = 0.0;
	print_tabs(6);
	printf("请输入你想充值的金额:");
	scanf("%lf", &change);
	if(change <= 0.0 || change >= 100000)
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("充值失败,只能充值正数金额哦，或一次不可超出 10W");
		return 0;
	}
	else
	{
		view_QR();
		print_tabs(6);
		CONTINUE("扫码充值");
		FLUSH;
		print_tabs(6);
		CONTINUE("充值完成");
		change_punter_data_balance(node->data, change);
		show_punter_balance(node);
		char str1[120]= "充值";
		sprintf(str1+6,"%g元, 余额%11.2f元",change, (node->data).punter->balance);
		add_punter_data_history(node->data, str1);
		FLUSH;
		print_tabs(6);
		CONTINUE("充值完成，回车继续");


		return 1;
	}
}

int withdraw_punter_balance(CLnode* node)
{
	if(NULL == node)
	{
		return 0;
	}
	double change = 0.0;
	print_tabs(6);
	printf("请输入你想提款的的金额:");
	scanf("%lf", &change);
	if(change <= 0.0)
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("提款失败,只能提款正数金额哦");
		return 0;
	}
	else if(change > (node->data).punter->balance)
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("提款失败,余额不足，回车返回");
		return 0;
	}
	else
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("开始提款，回车继续");


		//输入支付宝，看是否是合法支付宝
		char email[40] = "\0";
		//FLUSH;
		print_tabs(6);
		printf("请输入支付宝:");
		fgets(email, 40, stdin);
		if(email[strlen(email) - 1] == '\n')
		{
			email[strlen(email) - 1] = '\0';
		}
		else
		{
			FLUSH;
		}

		if(0 != match_mobile(email) && 0!= match_email(email))
		{
			print_tabs(6);
			CONTINUE("请输入正确的支付宝账号，应该为手机号码或者 email 地址，回车返回");
			return 0;
		}
		print_tabs(6);
		CONTINUE("支付宝输入正确，回车继续");

		//更新余额，写入历史记录
		change_punter_data_balance(node->data, -1.0*change);
		show_punter_balance(node);
		char str1[120]= "提款";
		sprintf(str1+6,"%g元, 余额%11.2f元",change, (node->data).punter->balance);
		add_punter_data_history(node->data, str1);
		//写入文件
		FILE* fp = fopen(WITHDRAW_FILE,"a");
		fprintf(fp, "%s %11.2f\n",email, change);
		fclose(fp);
		fp = NULL;

		print_tabs(6);
		CONTINUE("提款完成，回车继续");
		return 1;
	}
}


int modify_punter_password(CLnode* node)
{
	if(NULL == node)
	{
		return 0;
	}
	char matchword[NAME_SIZE] = "\0";
	char password1[NAME_SIZE] = "\0";
	char password2[NAME_SIZE] = "\0";
	int i = 0;
	for(i = 0; i < 3; i++)
	{
		print_tabs(6);
		printf("请输入原密码:");
		get_password(matchword);
		//printf("%s\n",get_punter_data_password(node->data));
		if(strcmp(matchword,get_punter_data_password(node->data)) == 0)
		{
		
			print_tabs(6);
			printf("请输入密码,少于%d个字符:", NAME_SIZE-1);
			get_password(password1);
			print_tabs(6);
			printf("请再输入密码,少于%d个字符:", NAME_SIZE-1);
			get_password(password2);

			if(strlen(password1) == 0 || strlen(password2) == 0)
			{
				print_tabs(6);
				CONTINUE("不能为空,请回车并重新输入");
			}
			else if(strcmp(password1,password2) == 0)
			{
				change_punter_data_password(node->data, password1);
				print_tabs(6);
				CONTINUE("修改成功，请回车返回\n");
				return 1;
			}
			else
			{
				print_tabs(6);
				CONTINUE("密码不一样哦，请回车并重新输入");
			}		


		}
		else
		{
			print_tabs(6);
			CONTINUE("密码错误,回车返回");
		}
	
	}
	print_tabs(6);
	CONTINUE("3次机会耗尽，回车回到主菜单");
	return 0;
}

int show_punter_history(CLnode* node)
{
	if(NULL == node)
	{
		return 0;
	}
	int i = 0;
	for(i = 0; i< HISTORY_NUM; ++i)
	{
		print_tabs(6);
		printf("%d.%s\n",i+1, get_punter_data_history(node->data, i));
	}
	print_tabs(6);
	CONTINUE("------------历史记录输出完成--------------\n");
	return 1;
}

int cancle_punter(CLnode* punter, CLnode* punterHead ,CLnode* lotteryHead)
{
	if(NULL == punter || NULL == punterHead || NULL == lotteryHead)
	{
		CONTINUE("cancel_punter, NULL error");
		return 0;
	}
	char name[NAME_SIZE] = "\0";
	strcpy(name,(punter->data).punter->username);
	int lotteryLen = (lotteryHead->data).size;
	int i = 0;
	CLnode* lottery = lotteryHead;

	//查看是否有彩票未开奖
	for(i = 0; i < lotteryLen; ++i)
	{
		lottery = lottery->previous;
		if(0 == strcmp(name, (lottery->data).lottery->owner)
			&& 0 == (lottery->data).lottery->status)
		{
			print_tabs(6);
			CONTINUE("您仍有未开奖的彩票，请等待开奖后再尝试注销，回车返回");
			return 0;
		}
	}

	//再确认是否有意愿
	char makesure = '\0';
	print_tabs(6);
	printf("确认销户吗？输入 y 为确认,其他为返回");
	scanf("%c", &makesure);
	if('y' != makesure)
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("销户中断，回车返回");
		return 0;
	}




	//删除 punter
	print_tabs(6);
	CONTINUE("您的所有彩票已经开奖，开始注销，回车继续");
	if(!delete_common_link_node(punter, punterHead))
	{
		print_tabs(6);
		printf("some impossible error in cancle_punter\n");
		return 0;
	}
	FLUSH;
	print_tabs(6);
	CONTINUE("注销完成，回车返回主菜单");
	return 1;
}





















//********************lottery part*********************





int get_lottery_type1_num(int *Num, double pool)
{
	int i = 0;
	int ppp = 0;
	print_tabs(6);
	printf("彩票名:%s,彩票单价: %g, 彩票奖池: %g: \n",
		LOTTERYNAME1, TYPE1_PRICE, pool);
	int choice = 0;
	int flag = 0;
	srand((unsigned)time(NULL));
	while(flag<3)
	{
		flag = 0;
		print_tabs(6);
		printf("机选(1)还是手选(0):");
		scanf("%d", &choice);
		if(choice == 0)
		{
			for(i = 0; i < 3; i++)
			{
				print_tabs(6);
				printf("请输入你的第%d个选号,0-9:",i+1);
				scanf("%d",&ppp);
				if(ppp<=9 && ppp>= 0)
				{
					Num[i] = ppp;
					flag++;
				}
				else
				{
					FLUSH;
					print_tabs(6);
					CONTINUE("请输入 0-9 的整数，回车返回");
					break;
				}

			}
		}
		else if(choice == 1)
		{
			for(i = 0; i < 3; i++)
			{
				int s = 0;
			    
    			s = rand()%10;
    			Num[i] = s;
    			print_tabs(6);
    			printf("第%d个机选号为:%d\n",i,s);	
    			flag = 3;
			}
		}
		//else if(choice == -1)
		//{
		//	CONTINUE("回车返回菜单");
		//	break;
		//}
		else
		{
			print_tabs(6);
			CONTINUE("请选择正确的方式,回车继续");
		}


	}	
	return 1;
}

int get_lottery_type2_num(int *Num, double pool)
{
	int i = 0;
	int ppp = 0;
	print_tabs(6);
	printf("彩票名:%s,彩票单价: %g, 彩票奖池: %g: \n",
		LOTTERYNAME2, TYPE2_PRICE, pool);
	int choice = 0;
	int flag = 1;
	srand((unsigned)time(NULL));
	while(flag<3)
	{
		flag = 0;
		print_tabs(6);
		printf("机选(1)还是手选(0):");
		scanf("%d", &choice);
		if(choice == 0)
		{
			for(i = 0; i < 6; i++)
			{
				print_tabs(6);
				printf("请输入你的第%d个选号,1-25:",i+1);
				scanf("%d",&ppp);
				if(ppp<=25 && ppp>= 1)
				{
					Num[i] = ppp;
					flag++;
				}
				else
				{
					FLUSH;
					print_tabs(6);
					CONTINUE("请输入 1-25 的整数，回车返回");
					break;
				}
				
			}
		}
		else if(choice == 1)
		{
			for(i = 0; i < 6; i++)
			{
				int s = 0;
			    
    			s = rand()%26 + 1;
    			Num[i] = s;
    			print_tabs(6);
    			printf("第%d个机选号为:%d\n",i,s);
    			flag = 3;	
			}
		}
		//else if(choice == -1)
		//{
		//	print_tabs(6);
		//	CONTINUE("回车返回菜单");
		//	break;
		//}
		else
		{
			print_tabs(6);
			CONTINUE("请选择正确的方式,回车继续");
		}


	}	
	return 1;
}


int get_lottery_type(void)
{
	int type = 0;
	print_tabs(6);
	printf("请输入彩票类型:");
	scanf("%d", &type);
	//int flag = 1;
	if(type < 1 || type > NUM_LOTTERYTYPE)
	{
		return 0;
	}
	else
	{
		return type;
	}

}

int get_buy_how_many(int type)
{
	//传入 type 是为了未来也许其他彩票限购不同数量
	type = 1;
	int number = 0;
	while(1)
	{
		print_tabs(6);
		printf("请输入你想购买的彩票张数,最多 5 张:");
		scanf("%d", &number);
		if(number < 1 || number >5)
		{
			FLUSH;
			print_tabs(6);
			CONTINUE("请输入 1-5 的整数，回车返回");
		}
		else
		{
			return number;
		}
	}
}




int buy_lottery(CLnode* lotterytypeHead, CLnode* lotteryHead,CLnode* punter)
{
	if(NULL == lotterytypeHead || NULL == lotteryHead || NULL == punter)
	{
		return 0;
	}
	//查看彩票类型是否合法
	int type = get_lottery_type();
	int issue = 0;
	if(type == 0)
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("不存在此类彩票，回车返回");
		return 0;
	}
	else
	{
		
		print_tabs(6);
		CONTINUE("彩票类型确认，回车继续");
	}
	//查看此类彩票是否可购买
	CLnode* p = find_int_in_common_link_back(lotterytypeHead,
				type, match_lotterytype_type);
	if(p == NULL)
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("未发行过此类彩票\n");
		return 0;
	}
	else if((p->data).lotterytype->status == 1)
	{
		FLUSH;
		print_tabs(6);
		CONTINUE("最近一期此类彩票为已开奖状态\n");
		
		return 0;
	}
	else
	{
		issue = (p->data).lotterytype->issue;
		FLUSH;
		print_tabs(6);		
		CONTINUE("彩票可购买，回车继续")
	}
	//获得购买数量与奖池
	int number = get_buy_how_many(type);
	double pool = (p->data).lotterytype->pool;

	//获得选号
	int flag = 1;
	int Num[10] = {0};
	if(1 == type)
	{
		while(flag)
		{
			if(get_lottery_type1_num(Num, pool) == 1)
			{
				FLUSH;
				print_tabs(6);
				CONTINUE("选号完成，回车继续");
				flag = 0;
			}
			else
			{
				flag = 1;
			}
		}
	}
	else if(2 == type)
	{
		while(flag)
		{
			if(get_lottery_type2_num(Num, pool) == 1)
			{
				FLUSH;
				print_tabs(6);
				CONTINUE("选号完成，回车继续");
				flag = 0;
			}
			else
			{
				flag = 1;
			}
		}
	}
	//查看余额是否足够
	double price = (p->data).lotterytype->price;
	double all = price * number;
	if((punter->data).punter->balance < all)
	{
		print_tabs(6);
		CONTINUE("余额不足，请回车返回充值");
		return 0;
	}
	//查看此期是否买过此期同样选号彩票，买过多少张？
	int bought_num = 0;
	char username[NAME_SIZE] = "\0";
	strcpy(username, (punter->data).punter->username );
	CLnode* lottery_check = lotteryHead;
	int lotteryLen = (lotteryHead->data).size;
	int i = 0;
	for(i = 0; i < lotteryLen; ++i)
	{
		lottery_check = lottery_check->previous;
		if((lottery_check->data).lottery->issue == issue
			&& (strcmp((lottery_check->data).lottery->owner,username) == 0) 
			&& ((match_lottery_num(lottery_check, Num, 3) == 0 && type == 1)
			||  (match_lottery_num(lottery_check, Num, 6) == 0 && type == 2)) )
		{
			bought_num = (lottery_check->data).lottery->number;
			break;
		}
	}
	//如果没买过
	if(bought_num == 0)
	{
		print_tabs(6);
		CONTINUE("未买过此期同样选号彩票，回车继续")
		//建立新链表节点，并插入
		Lottery_data* lotterydata = create_lottery_data(lotterytypeHead
			,type , number, Num, (punter->data).punter->username);
		CLnode* lottery = create_common_link_node(lotterydata ,2);
		insert_common_link_node(lotteryHead, lottery);
		//更新余额
		change_punter_data_balance(punter->data, -1.0*all);		
	}
	//如果超额了
	else if( bought_num + number > 5)
	{
		print_tabs(6);
		printf("已经买过此期同样选号彩票，仅能够再购买%d 注", 5-bought_num);
		CONTINUE(",回车返回");
		return 0;
	}
	//如果没超额
	else
	{
		//更新数量
		(lottery_check->data).lottery->number += number;
		//更新余额
		change_punter_data_balance(punter->data, -1.0*all);	
		print_tabs(6);
		printf("购买完成，共持有此期同样选号彩票%d注",(lottery_check->data).lottery->number );
		CONTINUE(",回车继续")	;		
	}

	//更新销售数量
	(p->data).lotterytype->soldNum += number;
	//增加钱到奖池
	(p->data).lotterytype->pool += number * (p->data).lotterytype->price;



	//更新历史记录
	char str1[120] = "购买了\0";
	char str2[20] = "\0";
	sprintf(str2+0,"%d", number);
	char str3[20] = "注\0";
	char str4[20] = "\0";
	sprintf(str4, "%d", (p->data).lotterytype->issue);
	char str5[20] = ",余额:";
	char str6[20] = "\0";
	sprintf(str6+0, "%11.2f",get_punter_data_balance(punter->data));

	strcat(str1,str2);
	strcat(str1,str3);
	strcat(str1,str4);
	strcat(str1,str5);
	strcat(str1,str6);

	if(type == 1)
	{
		char str7[20] = "\0";
		sprintf(str7+0,",选号:(%d,%d,%d)",Num[0],Num[1], Num[2]);
		strcat(str1,str7);
	}
	else if(type == 2)
	{
		char str7[40] = "\0";
		sprintf(str7+0,",选号:(%d,%d,%d,%d,%d,%d)",Num[0],Num[1], Num[2], Num[3], Num[4], Num[5]);
		strcat(str1,str7);		
	}


	add_punter_data_history(punter->data, str1);

	print_tabs(6);
	CONTINUE("购买完成，回车返回彩民菜单");
	return 1;
}










//********************lottery type part*********************





int match_lottery_num(CLnode* lottery, int* Num, int len)
{
	if(NULL == lottery)
	{
		return -2;
	}
	int i = 0;
	for(i = 0; i < len;i++)
	{
		if(Num[i] != (lottery->data).lottery->Num[i])
		{
			return -1;
		}
	}
	return 0;
}





void get_data(CLnode* punterHead, CLnode* lotteryHead,
				 CLnode* lotterytypeHead)
{
	if(punterHead == NULL || lotteryHead == NULL || NULL == lotterytypeHead)
	{
		return;
	}
	FILE *fp_config = fopen(CONFIG_FILE,"r");
	FILE *fp_punter = fopen(PUNTER_FILE,"rb");
	FILE *fp_lottery = fopen(LOTTERY_FILE,"rb");
	FILE *fp_lotterytype = fopen(LOTTERYTYPE_FILE,"rb");
	int m = -1;

	//判定
	if(fp_config == NULL || fp_punter == NULL 
		|| fp_lottery == NULL
		|| fp_lotterytype == NULL)
	{
		print_tabs(6);
		CONTINUE("无本地文件,可能为第一次打开或文件丢失，回车继续");
		return;
	}

	fscanf(fp_config, "%d %d", &issue1_now, &issue2_now);
	fclose(fp_config);
	fp_config = NULL;

	Punter_data* punter_data = (Punter_data*)calloc(1,sizeof(Punter_data));
	m = fread(punter_data, sizeof(Punter_data), 1 , fp_punter);	
	while(!feof(fp_punter))
	{
		if(m <= 0)
		{
			free(punter_data);
			break;
		}
		CLnode* punter =  create_common_link_node(punter_data, 1);
		insert_common_link_node(punterHead, punter);
		punter_data = (Punter_data*)calloc(1,sizeof(Punter_data));
		m = fread(punter_data, sizeof(Punter_data), 1 , fp_punter);
	}
	free(punter_data);
	punter_data = NULL;
	fclose(fp_punter);
	fp_punter = NULL;

	Lottery_data* lottery_data = (Lottery_data*)calloc(1,sizeof(Lottery_data));
	m = fread(lottery_data, sizeof(Lottery_data), 1 , fp_lottery);
	while(!feof(fp_lottery))
	{
		if(m <= 0)
		{
			free(lottery_data);
			break;
		}
		CLnode* lottery =  create_common_link_node(lottery_data, 2);
		insert_common_link_node(lotteryHead, lottery);
		lottery_data = (Lottery_data*)calloc(1,sizeof(Lottery_data));
		m = fread(lottery_data, sizeof(Lottery_data), 1 , fp_lottery);
	}
	free(lottery_data);
	lottery_data = NULL;
	fclose(fp_lottery);
	fp_lottery = NULL;
	
	Lotterytype_data* lotterytype_data = (Lotterytype_data*)calloc(1,sizeof(Lotterytype_data));
	m = fread(lotterytype_data, sizeof(Lotterytype_data), 1 , fp_lotterytype);
	while(!feof(fp_lotterytype))
	{
		if(m <= 0)
		{
			free(lotterytype_data);
			break;
		}
		CLnode* lotterytype =  create_common_link_node(lotterytype_data, 3);
		insert_common_link_node(lotterytypeHead, lotterytype);
		lotterytype_data = (Lotterytype_data*)calloc(1,sizeof(Lotterytype_data));
		m = fread(lotterytype_data, sizeof(Lotterytype_data), 1 , fp_lotterytype);
	}
	free(lotterytype_data);
	lotterytype_data = NULL;
	fclose(fp_lotterytype);
	fp_lotterytype = NULL;



	print_tabs(6);
	CONTINUE("载入成功！,回车继续");
}




void write_data(CLnode* punterHead, CLnode* lotteryHead,
				 CLnode* lotterytypeHead)
{
	if(punterHead == NULL || NULL == lotteryHead || NULL == lotterytypeHead)
	{
		return;
	}
	//issue_now 写入
	FILE *fp_num = fopen(CONFIG_FILE,"w");
	fprintf(fp_num, "%d %d", issue1_now, issue2_now);
	fclose(fp_num);
	fp_num = NULL;

	int i = 0;

	//punter 输入
	int punterLen = (punterHead->data).size;
	CLnode* punter = punterHead;	
	FILE *fp_punter = fopen(PUNTER_FILE,"wb");
	for(i = 0; i < punterLen; ++i)
	{	
		punter = punter->next;
		fwrite((punter->data).punter, sizeof(Punter_data), 1 , fp_punter);
	}
	fclose(fp_punter);
	fp_punter = NULL;

	//lottery 输入
	int lotteryLen = (lotteryHead->data).size;
	CLnode* lottery = lotteryHead;	
	FILE *fp_lottery = fopen(LOTTERY_FILE,"wb");
	for(i = 0; i < lotteryLen; ++i)
	{	
		lottery = lottery->next;
		fwrite((lottery->data).punter, sizeof(Lottery_data), 1 , fp_lottery);
	}
	fclose(fp_lottery);
	fp_lottery = NULL;

	//lotterytype 输入
	int lotterytypeLen = (lotterytypeHead->data).size;
	CLnode* lotterytype = lotterytypeHead;	
	FILE *fp_lotterytype = fopen(LOTTERYTYPE_FILE,"wb");
	for(i = 0; i < lotterytypeLen; ++i)
	{	
		lotterytype = lotterytype->next;
		fwrite((lotterytype->data).punter, sizeof(Lotterytype_data), 1 , fp_lotterytype);
	}
	fclose(fp_lotterytype);
	fp_lotterytype = NULL;
	print_tabs(6);
	CONTINUE("保存完成，回车退出");
}













