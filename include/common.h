#ifndef COMMON_H_
#define COMMON_H_



//*****配置修改***********
#define CONFIG_FILE "./data/config.txt"
#define PUNTER_FILE "./data/punter.bin"
#define LOTTERY_FILE "./data/lottery.bin"
#define LOTTERYTYPE_FILE "./data/lotterytype.bin"
#define WITHDRAW_FILE "./data/withdrawfile.txt"

#define NAME_SIZE 20
#define HISTORY_NUM 10

#define ADMIN_NAME "admin"
#define ADMIN_PSW "123"
#define NOTARY_NAME "notary"
#define NOTARY_PSW "123"

#define NUM_LOTTERYTYPE 2
#define MULT 100000

#define LOTTERYNAME1 "杨中豪彩票"
#define TYPE1POOL 1000.0
#define TYPE1_PRICE 2.0

#define LOTTERYNAME2 "超级彩票"
#define TYPE2POOL 500000.0
#define TYPE2_PRICE 2.0

//********值域结构体*******




















//******宏函数***********
//缓存清理
#define FLUSH 	{ char c = 0;  while((c = getchar()) != '\n' && c != EOF);  }
//菜单停滞
#define CONTINUE(X) { printf(X); getchar(); }




//******密码输入**********
int getch123(void);
void get_password(char *pwd);


//**********验证码输入*************
/*
	function:验证码
	return:正确返回1，否则返回0
*/
int identifyCode(void);

//***********匹配是否为支付宝***********8
/*
	利用匹配是否为手机号，邮箱
*/
int match_email(char* input);
int match_mobile(char* input);

#endif
