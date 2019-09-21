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



Punter_data* create_punter_data(char* username, 
	char* password, double balance, char (*history)[50])
{
	Punter_data* data = (Punter_data*) calloc(1,sizeof(Punter_data));

	strcpy(data->username, username);
	strcpy(data->password, password);
	data->balance = balance;
	int i = 0;
	for(i = 0; i < HISTORY_NUM; ++i)
	{
		strcpy(data->history[i], history[i]);
	}

	return data;
}


int match_punter_username(Udata data,
		 char* username)
{
	if(strcmp((data.punter)->username,username) == 0 )
	{
		return 0;
	}
	else
	{
		return -1;
	}

}

int match_punter_password(Udata data,
		 char* password)
{
	if(strcmp((data.punter)->password,password) == 0 )
	{
		return 0;
	}
	else
	{
		return -1;
	}

}




double get_punter_data_balance(Udata data)
{
	int balance = (data.punter)->balance;
	return balance;
}

int change_punter_data_balance(Udata data, double change)
{
	(data.punter)->balance += change;
	return 1;
}

char* get_punter_data_username(Udata data)
{
	return (data.punter)->username;
}

char* get_punter_data_password(Udata data)
{
	return (data.punter)->password;
}

int change_punter_data_password(Udata data, char* new)
{
	strcpy((data.punter)->password, new);
	return 1;
}


int display_punter_data(Udata data)
{
	printf("%s\t%11.2f\n",(data.punter)->username, (data.punter)->balance);
	return 1;
}

char* get_punter_data_history(Udata data, int which)
{
	return (data.punter)->history[which];

}


int add_punter_data_history(Udata data, char* change)
{
	Punter_data *punter = data.punter;
	int i = 0;
	/*
	for(i = 0; i < HISTORY_NUM;++i)
	{
		if(punter->history[i][0] == '\0')
		{
			strcpy(punter->history[i], change);
			break;
		}
	}
	*/
	for(i = 0; i < HISTORY_NUM -1; ++i)
	{
		strcpy(punter->history[i], punter->history[i+1]);
	}
	strcpy(punter->history[HISTORY_NUM-1], change);
	return 1;
}



int compare_punter_balance(CLnode* punter1, CLnode* punter2)
{
	return (punter1->data).punter->balance - (punter2->data).punter->balance;
}










































int free_punter_data(Udata data)
{
	free(data.punter);
	return 1;
}








