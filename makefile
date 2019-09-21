CC = gcc
TARGET = bin/lottery
OBJ = main.c
OBJ += obj/common.o
OBJ += obj/view.o
OBJ += obj/control.o
OBJ += obj/commonlink.o
OBJ += obj/lotterytype.o
OBJ += obj/lottery.o
OBJ += obj/punter.o
OBJ += obj/manager.o
OBJ += obj/notary.o

#编译选项
FLAG = -Iinclude -g -Wall

$(TARGET):$(OBJ)
	$(CC) $^ $(FLAG) -o $@



obj/common.o:src/common.c
	$(CC) -c $^ -o $@ $(FLAG)
obj/commonlink.o:src/commonlink.c
	$(CC) -c $^ -o $@ $(FLAG)
obj/lotterytype.o:src/lotterytype.c
	$(CC) -c $^ -o $@ $(FLAG)
obj/lottery.o:src/lottery.c
	$(CC) -c $^ -o $@ $(FLAG)
obj/punter.o:src/punter.c
	$(CC) -c $^ -o $@ $(FLAG)			
obj/manager.o:src/manager.c
	$(CC) -c $^ -o $@ $(FLAG)
obj/notary.o:src/notary.c
	$(CC) -c $^ -o $@ $(FLAG)
obj/view.o:src/view.c
	$(CC) -c $^ -o $@ $(FLAG) 
obj/control.o:src/control.c
	$(CC) -c $^ -o $@ $(FLAG)






.PHONY:clean
clean:
	rm -rf bin/*
	rm obj/*

.PHONY:deldata
deldata:
	rm data/*

.PHONY:copydata
copydata:
	cp -r data-copy/. data 





















