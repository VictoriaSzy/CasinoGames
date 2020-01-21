//1-37,38,39
/* shoot it has to be able to turn, or maybe not
   01234
 15     11
14       16
13       17
 12     10
   85679
*/
/*       V
       30010203
    2829      0405    
  N27            06N
 26                07
25                  08
4                    0
2                    9
23                  10 
 22                11
  N21            12N 
    2019      1314
       18171615
*/
/* 1,1,2,2,3,3,4,4,5,5,6,7,8,8
7 pairs until 2 singles
         NNNNNNNNNN
      NNN          NNN
    NN    NN|NN|NN    NN
   N   NNNN112233NNNN   N   
  N  NNN566      445NNN  N
 N  NN45            56NN  N
N  NN3                7NN  N
N  N2                  8N  N
N  N2                  8N  N
N  NN1                9NN  N
 N  NN98            21NN  N
  N  NNN877      332NNN  N
   N   NNNN665544NNNN   N
    NN    NNNNNNNN    NN
      NNN          NNN
         NNNNNNNNNN
  */
/*
       01N02N03
    NN24      04NN    
  N23            05N
 22                06
21                  07
0         /\         0
2         \/         8
19                  09 
 18                10
  N17            11N 
    NN16      12NN
       15N14N13


  */
/*
        NNNNNNNN
     NNNN      NNNN    
   NNN            NNN
  NN                NN
 NN                  NN
NN                    NN
N                      N
N                      N
NN                    NN
 NN                  NN 
  NN                NN
   NNN            NNN 
     NNNN      NNNN
        NNNNNNNN
  */
#include "roulette.h"
/*int super_sleep(int milliseconds){
	struct timespec ts;
  ts.tv_sec = milliseconds / 1000;
  ts.tv_nsec = (milliseconds % 1000) * 1000000;
  return nanosleep(&ts, NULL);
}*/

int roulette_spin(int money){
	printf("Enter your bets and then enter spin when you are done.\n");
	printf("\nPossible bets are: betting on a single number from 1-24 or betting on even vs odd\n\n");
	char newBid[100];
	char amount[100];
	int bid;

	int nums[26];//24 + even and odd
	int n = 0;
	int amounts[26];
	int a = 0;

	int even = 0;
	int odd = 0;

	int num;
	while (strcmp(newBid, "spin") != 0){
		num = 0;
		bid = 0;

		printf("Enter what you want to bet on: ");
		fgets(newBid, 100, stdin);
		*strchr(newBid, '\n') = '\0';
		if (strcmp(newBid, "odd") != 0 && strcmp(newBid, "even") != 0){
			num = atoi(newBid);
		}
		while (num > 24 || (num < 1 && strcmp(newBid, "odd") != 0 && strcmp(newBid, "even") != 0 && strcmp(newBid, "spin") != 0)){
			num = 0;
			printf("Invalid entry!!\n");
			printf("Enter the what you want to bet on: ");
			fgets(newBid, 100, stdin);
			*strchr(newBid, '\n') = '\0';
			if (strcmp(newBid, "odd") != 0 && strcmp(newBid, "even") != 0){
				num = atoi(newBid);
			}
		}

		if (num >= 1 && num <= 24){
			nums[n] = num;
			++n;
		}
		if (strcmp(newBid, "spin") != 0) {
			printf("Enter the amount you want place on this bet: ");
			fgets(amount, 100, stdin);
			*strchr(amount, '\n') = '\0';
			bid = atoi(amount);

			while (bid < 0 || bid > money){
				printf("Invalid bet!! You have $%i\n", money);
				printf("Enter the amount you want place on this bet: ");
				fgets(amount, 100, stdin);
				*strchr(amount, '\n') = '\0';
				bid = atoi(amount);
			}

			if (strcmp(newBid, "odd") == 0){
				odd = bid;
			}else if (strcmp(newBid, "even") == 0){
				even = bid;
			}else{
				amounts[a] = bid;
				++a;
			}
			money -= bid; 
			printf("You are now holding $%i\n", money);
	  }
	}

	int spins = rand() % 2 + 2;
	char * wheel[24] = {"15","19","04","21","02","17","06","13","11","08","23","10","05","24","16","01","20","14","09","22","18","07","12","03"};
	int at = 0;
	int b = rand() % 52; //0 - 51
	int w = rand() % 24;
	// b is for ball
	/*
	       NNNNNNNNNN
      NNN 00111122 NNN
    NN   000|01|02233 NN
   N   NN23      03NN44 N   
  N  N22            04N4 N
 N  21                055 N
N  20                  066 N
N  9                    07 N
N  1                    77 N
N  18                  088 N
 N  17                099 N
  N16N16            10N10 N
   N 16NN15      11NN   N
    NN    14N13N12    NN
      NNN 14         NNN
         NNNNNNNNNN
  */
  //char bp = {' ', 'O'};
  int bw[52] = {0,0,1,1,1,1,2,2,2,3,3,4,4,4,5,6,7,7,8,9,10,10,10,11,11,12,12,12,13,13,13,13,14,14,14,15,15,16,16,17,18,19,19,20,21,22,22,22,22,23,23,0};
  //bp(,b)
	for (int s = 0; s < spins * 52+1; s++){
		system("clear");
		printf("Your bets are:\n");
		for (int i = 0; i < n; i++){
			printf("$%i on %i\n",amounts[i], nums[i]);
		}
		if (odd > 0){printf("$%i on odds\n", odd);}
		if (even > 0){printf("$%i on evens\n", even);}
		printf("==================\n\n");

		printf("         ##########\n");
		printf("      ### %c%c%c%c%c%c%c%c ###\n",bp(0,b),bp(1,b),bp(2,b),bp(3,b),bp(4,b),bp(5,b),bp(6,b),bp(7,b));
		printf("    ## %c%c%c%s#%s#%s%c%c%c ##\n", bp(49,b), bp(50,b),bp(51,b), wheel[w], wheel[(w+1)%24], wheel[(w+2)%24], bp(8,b),bp(9,b),bp(10,b));
		printf("   # %c%c##%s      %s##%c%c #  \n", bp(47,b),bp(48,b), wheel[(w+23)%24], wheel[(w+3)%24], bp(11,b),bp(12,b));
		printf("  # %c#%s            %s#%c #\n", bp(46,b), wheel[(w+22)%24], wheel[(w+4)%24], bp(13,b));
		printf(" # %c%s                %s%c #\n", bp(45,b), wheel[(w+21)%24], wheel[(w+5)%24], bp(14,b));
		printf("# %c%s                  %s%c #\n", bp(44,b), wheel[(w+20)%24], wheel[(w+6)%24], bp(15,b));
		printf("# %c%c         /\\         %c%c #\n", bp(43,b), wheel[(w+19)%24][1], wheel[(w+7)%24][0], bp(16,b));
		printf("# %c%c         \\/         %c%c #\n", bp(42,b), wheel[(w+19)%24][0], wheel[(w+7)%24][1], bp(17,b));
		printf("# %c%s                  %s%c #\n", bp(41,b), wheel[(w+18)%24], wheel[(w+8)%24], bp(18,b));
		printf(" # %c%s                %s%c #\n", bp(40,b), wheel[(w+17)%24], wheel[(w+9)%24], bp(19,b));
		printf("  # %c#%s            %s#%c #\n", bp(39,b), wheel[(w+16)%24], wheel[(w+10)%24], bp(20,b));
		printf("   # %c%c##%s      %s##%c%c #\n", bp(38,b),bp(37,b), wheel[(w+15)%24], wheel[(w+11)%24], bp(22,b),bp(21,b));
		printf("    ## %c%c%c%s#%s#%s%c%c%c ##\n", bp(36,b),bp(35,b),bp(34,b), wheel[(w+14)%24], wheel[(w+13)%24], wheel[(w+12)%24] , bp(25,b),bp(24,b),bp(23,b));
		printf("      ### %c%c%c%c%c%c%c%c ###\n", bp(33,b),bp(32,b),bp(31,b),bp(30,b),bp(29,b),bp(28,b),bp(27,b),bp(26,b));
		printf("         ##########\n");

		if(s < spins * 52){
			b = (b+1) % 52;
			w = (w+1) % 24;
			//super_sleep(60); for now
		}
	}/*
	printf("         ##########\n");
	printf("      ### %i%i%i%i%i%i%i%i ###\n",bw[0],bw[1],bw[2],bw[3],bw[4],bw[5],bw[6],bw[7]);
	printf("    ## %i%i%i%s#%s#%s%i%i%i ##\n", bw[49], bw[50],bw[51], wheel[w], wheel[(w+1)%24], wheel[(w+2)%24], bw[8],bw[9],bw[10]);
	printf("   # %i%i##%s      %s##%i%i #  \n", bw[47],bw[48], wheel[(w+23)%24], wheel[(w+3)%24], bw[11],bw[12]);
	printf("  # %i#%s            %s#%i #\n", bw[46], wheel[(w+22)%24], wheel[(w+4)%24], bw[13]);
	printf(" # %i%s                %s%i #\n", bw[45], wheel[(w+21)%24], wheel[(w+5)%24], bw[14]);
	printf("# %i%s                  %s%i #\n", bw[44], wheel[(w+20)%24], wheel[(w+6)%24], bw[15]);
	printf("# %i%i         /\\         %i%i #\n", bw[43], wheel[(w+19)%24][1], wheel[(w+7)%24][0], bw[16]);
	printf("# %i%i         \\/         %i%i #\n", bw[42], wheel[(w+19)%24][0], wheel[(w+7)%24][1], bw[17]);
	printf("# %i%s                  %s%i #\n", bw[41], wheel[(w+18)%24], wheel[(w+8)%24], bw[18]);
	printf(" # %i%s                %s%i #\n", bw[40], wheel[(w+17)%24], wheel[(w+9)%24], bw[19]);
	printf("  # %i#%s            %s#%i #\n", bw[39], wheel[(w+16)%24], wheel[(w+10)%24], bw[20]);
	printf("   # %i%i##%s      %s##%i%i #\n", bw[38],bw[37], wheel[(w+15)%24], wheel[(w+11)%24], bw[22],bw[21]);
	printf("    ## %i%i%i%s#%s#%s%i%i%i ##\n", bw[36],bw[35],bw[34], wheel[(w+14)%24], wheel[(w+13)%24], wheel[(w+12)%24] , bw[25],bw[24],bw[23]);
	printf("      ### %i%i%i%i%i%i%i%i ###\n", bw[33],bw[32],bw[31],bw[30],bw[29],bw[28],bw[27],bw[26]);
	printf("         ##########\n");
	*/
	//printf("B: %i W: %i\n bw: %i\n",b,w, bw[b]);
	//printf("money: %i\n", money);

	printf("The the ball landed on: %s \n",wheel[(w+bw[b]) % 24]);
	int win = atoi(wheel[(w+bw[b]) % 24]);
	for (int i = 0; i < n; i++){
		if (win == nums[i]){
			money += amounts[i] * 24;
			printf("YOU WON!!!!\n");
			printf("You've earned %i\n", amounts[i] * 24);
		}
	}
	if (win % 2 == 0){
		money += even * 2;
	}else{
		money += odd * 2;
	}
	printf("\nYou now have $%i dollars\n", money);

	return money;
}
char bp(int num, int ballpos){
	if (num == ballpos){
		return 'O';
	}
	return ' ';
}
int roulette_game(int money) {
  printf("It's time to play with the Slot Machines!\n") ;
  printf("Match three numbers to win the amount you bet or more.\n") ;
  //printf("Match all three numbers to win 10 times the amount you bet!\n") ;
  printf("Have fun!\n") ;

  printf("\nYou currently have $%i dollars\n", money);

  
  char command[128] = "help";
  int bet = 10;

	while (strcmp(command, "exit") != 0){
		system("clear");
		printf("It's time to play roulette!\n") ;

		printf("\nYou currently have $%i dollars\n", money);

		if (strcmp(command, "play") == 0){
			srand(time(0));
			money = roulette_spin(money);
		}
		else if (strcmp(command, "help") == 0){
			printf("In roulette you can bet that the ball will stop on a number from 1 through 24 or that the ball will land on an even or odd number\n");
			printf("The payoff for betting on the right number if 1 to 24 and 1 to 2 for betting on even or odd correctly\n");
			printf("\nType in commands to play. The Commands are: \n");
			printf("\t-play\n\t  -Type \"play\"\n\t-help\n\t-exit\n");
		}
		//else if (strcmp(command, "") == 0){}
		else {
			printf("You entered: \"%s\"\n", command);
			printf("You did not enter a valid command. Possible commands are: \n\t-play\n\t-help\n\t-exit\n");
		}
		printf("\nEnter your command: ");
		fgets(command, 1024, stdin);
		*strchr(command, '\n') = '\0';
	}
	printf("\nYou are leaving the roulette\n");
	super_sleep(800);
  return money ;
}