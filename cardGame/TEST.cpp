#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int TEST()
{
	srand(time(NULL));
	int player=2;
	int card_num = 54;
	int round = card_num /player;
	int card[2][28]; 
	int card_all[54]; 
	char color[4][5] = { "黑桃","紅心","方塊","梅花" }; 
	char point[13][3] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K"};//
	int play_card;
	

	for (int i = 0; i < card_num; i++) card_all[i] = i;
	//for (int i = 0; i < card_num; i++) printf("%d ",  card_all[i]);
	//printf("\n");

	for (int j = 0; j < round; j++) { //發牌 X 回
		for (int i = 0; i < player; i++) {
			/*printf("card all原先");
			for (int i = 0; i < 28; i++)
			{
				printf("%2d, ", card_all[i]+1);
			}
			printf("\n");*/
			play_card = rand() % card_num;
			card[i][j] = card_all[play_card];
			/*printf("%d回，%d玩家抽到 %d：\n", j + 1, i + 1, card_all[play_card] + 1);*/
			card_all[play_card] = card_all[card_num - 1];
			card_num--;
			/*printf("card all後來");
			for (int i = 0; i < card_num; i++)
			{
				printf("%2d, ", card_all[i] + 1);
			}
			printf("\n \n");*/
		}
	}
	

	//for (int i = 0; i < player; i++) {
	//	printf("玩家%d：\n", i + 1);
	//	for (int j = 0;j < round; j++) 
	//	{
	//		printf("%2d ", card[i][j]+1);
	//	}
	//	printf("\n");
	//}

	for (int i = 0; i < player; i++)
	{
		printf("玩家%d：\n", i + 1);
		for (int k = 1; k < round; k++)
		{//總共需要檢查的次數
			for (int j = 0; j < round - k; j++)//[玩家I][第J張牌] 第1回向後檢查25次，第2回向後檢查24次....
			{
				if (card[i][j] > card[i][j + 1])
				{
					int temp = card[i][j];
					card[i][j] = card[i][j + 1];
					card[i][j + 1] = temp;
				}
			}
		}
		for (int j = 0; j < round; j++)
		{
			if (card[i][j] == 52 || card[i][j] == 53)
			{
				printf("JOKER");
			}
			else {
				printf("%s", color[card[i][j] % 4]);
				printf("%2s", point[card[i][j] / 4]);
			}

			if (j != round - 1)
			{
				printf(",");
			}
			else {

				printf("\n\n");
			}
		}
	}


		
	
	
	return 0;
}



//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#pragma warning (disable:4996)
//
//int main() {
//	int setForA[4] = { 0,0,0,0 };
//	int setForB[4];
//	srand(time(NULL));
//	int setIni;
//	int cardNum[13];
//	int sA[13];
//
//	for (int i = 0; i <13; i++)
//	{
//		cardNum[i] = i + 1;
//	}
//
//	for (int i = 0; i < 26; i++)
//	{
//		setIni = rand()%4;
//		setForA[setIni]+=1;
//	}
//
//	for (int i = 0; i < 4; i++)
//	{	
//		setForB[i]=13- setForA[i];
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		printf("A:%d \n", setForA[i]);
//		printf("B:%d \n", setForB[i]);
//	}
//
//	for (int i = 0; i < 1; i++)
//	{
//		if (setForA[i] < setForB[i])
//		{
//			for (int j = 0; j < setForA[i]; j++) 
//			{
//				for (int k = 0; k < 13; k++) {
//					printf("card sequ :%d \n", cardNum[k]);
//				}
//				int tempN = rand() % (13-j);
//				printf("I got  :%d \n", cardNum[tempN]);
//				sA[j] = cardNum[tempN];
//				cardNum[tempN] = cardNum[12-j];
//
//			}
//			
//			for (int i = 0; i < setForA[0]; i++)
//			{
//				printf("A num:%d \n", sA[i]);
//			}
//		}
//	}
//	
//
//	
//
//
//	return 0;
//
//}
//
//
