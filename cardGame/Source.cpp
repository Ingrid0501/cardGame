#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	int player = 2;
	int card_num = 54;
	int round = card_num / player;
	int card[2][28];
	int card_all[54];
	char color[4][5] = { "黑桃","紅心","方塊","梅花" };
	char point[13][3] = { "A","2","3","4","5","6","7","8","9","T","J","Q","K" };//
	int play_card;


	for (int i = 0; i < card_num; i++) card_all[i] = i;
	for (int j = 0; j < round; j++) { //發牌 X 回
		for (int i = 0; i < player; i++) {
			play_card = rand() % card_num;
			card[i][j] = card_all[play_card];
			card_all[play_card] = card_all[card_num - 1];
			card_num--;
		}
	}


	for (int i = 0; i < player; i++) //從玩家1開始依照大小排手牌。
	{
		printf("玩家%d：\n", i + 1);
		for (int k = 1; k < round; k++)//總共需要檢查的次數
		{
			for (int j = 0; j < round - k; j++)//[玩家I][第J張牌] 第1回向後檢查25次，第2回向後檢查24次....
			{
				if (card[i][j] > card[i][j + 1])//如果第X張牌數字>X+1(後方)那麼將兩者互換。
				{
					int temp = card[i][j];
					card[i][j] = card[i][j + 1];
					card[i][j + 1] = temp;
				}
			}
		}

		//將號碼對應的撲克牌列出
		for (int j = 0; j < round; j++)
		{
			if (card[i][j] == 52 || card[i][j] == 53)//沒有花色的鬼牌
			{
				printf("JOKER"); 
			}
			else {
				printf("%s_", color[card[i][j] % 4]);
				printf("%s", point[card[i][j] / 4]);
			}

			if (j != round - 1)printf(" , ");
			else printf("\n\n");
		}

	}

	//同花色擺在一起
	for (int i = 0; i < player; i++)
	{
		for (int j = 0; j < round; j++)
		{
			/*if (card[i][j] == card[i][j + 1])
			{
				card[i][j] = card[i][j+2];
				card[i][j + 1] = card[i][j+3];
			}*/
			printf("%2d, ", card[i][j] );
		}
		printf("\n");
	}


	return 0;
}

