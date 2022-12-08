#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int money = 1000;

int main() {
  srand(time(0));

  int c[7];
  int x;
  int d;
  int b;

  do {
    for (int i = 0; i < 7; i++) {
      int a;
      a = rand() % 10;

      c[i] = a;
    }

    do {
      b = EnterBid(b, money);
      printf("Start (Enter \"1\")\n");
      scanf("%d", & d);

      if (d < 1 || d > 1) {
        printf("+--------------WARNING-------------------+\n");
        printf("Incorrect.\n");
        printf("+-----------------------------------------+\n");
      }
    } while (d < 1 || d > 1);

    printf("--------------------------------------\n");

    for (int i = 0; i < 7; i++) printf("%d\t", c[i]);

    printf("\n--------------------------------------\n");

    if (c[0] == c[1] && c[0] == c[2] && c[0] == c[3] && c[0] == c[4] && c[0] == c[5] && c[0] == c[6]) {
      printf("-----------!JACKPOT!---------- \n");
      money += b * 2;
      b = b * 2;
      printResult(b, money);
      printf("---------------------------- \n");

    } else {
      if (c[0] == 7 || c[1] == 7 || c[2] == 7 || c[3] == 7 || c[4] == 7 || c[5] == 7 || c[6] == 7) {
        printf("-------------ONE OF THE NUMBERS IS 7 -------------\n");

        money += b;
        b = b;
        printResult(b, money);
        printf("---------------------------- \n");
      }
      if (c[0] == c[1] || c[0] == c[2] || c[0] == c[3] || c[0] == c[4] || c[0] == c[5] || c[0] == c[6] || c[1] == c[2] || c[1] == c[3] || c[1] == c[4] || c[1] == c[5] || c[1] == c[6] ||
        c[2] == c[3] || c[2] == c[4] || c[2] == c[5] || c[2] == c[6] ||
        c[3] == c[4] || c[3] == c[5] || c[3] == c[6] ||
        c[4] == c[5] || c[4] == c[6] ||
        c[5] == c[6]) {

        printf("-------------TWO NUMBERS ARE EQUAL!-------------\n");
        money += b;
        b = b;
        printResult(b, money);
        printf("---------------------------- \n");
      } else {
        printf("-------BETTER LUCK NEXT TIME-------\n");
        money = -b;
        b = -b;
        printResult(b, money);
      }
    }

    do {
      printf("Retry (Enter \"0\")\n");
      printf("Leave the game (Enter \"1\")\n");
      scanf("%d", & x);
      if (x < 0 || x > 1) {
        printf("+--------------WARNING-------------------+\n");
        printf("Incorrect.\n");
        printf("+-----------------------------------------+\n");
      }
    } while (x < 0 || x > 1);

  } while (x == 0);

  return 0;
}
