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
	char color[4][5] = { "�®�","����","���","����" };
	char point[13][3] = { "A","2","3","4","5","6","7","8","9","T","J","Q","K" };//
	int play_card;


	for (int i = 0; i < card_num; i++) card_all[i] = i;
	for (int j = 0; j < round; j++) { //�o�P X �^
		for (int i = 0; i < player; i++) {
			play_card = rand() % card_num;
			card[i][j] = card_all[play_card];
			card_all[play_card] = card_all[card_num - 1];
			card_num--;
		}
	}


	for (int i = 0; i < player; i++) //�q���a1�}�l�̷Ӥj�p�Ƥ�P�C
	{
		printf("���a%d�G\n", i + 1);
		for (int k = 1; k < round; k++)//�`�@�ݭn�ˬd������
		{
			for (int j = 0; j < round - k; j++)//[���aI][��J�i�P] ��1�^�V���ˬd25���A��2�^�V���ˬd24��....
			{
				if (card[i][j] > card[i][j + 1])//�p�G��X�i�P�Ʀr>X+1(���)����N��̤����C
				{
					int temp = card[i][j];
					card[i][j] = card[i][j + 1];
					card[i][j + 1] = temp;
				}
			}
		}

		//�N���X���������J�P�C�X
		for (int j = 0; j < round; j++)
		{
			if (card[i][j] == 52 || card[i][j] == 53)//�S����⪺���P
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

	//�P����\�b�@�_
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

