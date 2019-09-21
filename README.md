# lottery
A C project about lottery system and  just for parcticing

I am learning C, and this is my first project.

The  menu of program(all included in view.c) and prompt  were  all done in Chinese, but you may find English annotation in  .h files. And I will list the choices in menus in English below one by one.

## Functions included

#### main
1. punter login
2. punter register
3. manager or notary login (username: admin, password:123) (username: notary, password:123)
0. exit

#### punter
1. but lotter
2. check the balance
3. topup
4. check ten history records
5. change the password
6. cancel the account
7. withdraw
8.  show the rules of lotteries
0. go back

#### manager
1. show infomations of all punters
2. check information of a punter by username
3. check informatons of some punters by balance
4. sort punter by balance
5. issue lottery
6. show all issued lottery types
7. test for probability
0. go back

#### notary
1. draw the lottery
6. show all issued lottery types
0. goback




## How to use it
You  need firstly go to the lottery directory.
Run

    make clean
    
    make deldata (alternative, just delete the data of mine, or maybe you want to see my data. tips: 32bits system will not read my data correctly, )
    
    make
    
    ./bin/lottery
    
If you are using mac OSX,you could run the excuteable file directly:

    ./bin/lottery








This project was finished with the help of teachers and friends in IOTEK.

