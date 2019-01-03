#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int times;//遊戲的次數
	int mousex, mousey;//地鼠的X及座標
	int posx, posy;//錘子的X及Y座標
	int hits = 0, missed = 0;//統計擊中與未擊中地鼠的次數
	int i, j, k;//循環變量

	printf("請輸入要打地鼠的次數 : ");//輸入打地鼠次數
	scanf_s("%d", &times);
	printf("□□□\n□□□\n□□□\n\n");//列印9個地鼠洞

	srand(time(NULL));//隨機種子

	for (i = 1; i <= times; i++)//循環打地鼠的效果
	{
		mousex = rand() % 3 + 1;//獲取地鼠的隨機函數 : 1-3
		mousey = rand() % 3 + 1;
		
		do//輸入錘子的座標
		{
			printf("請輸入錘子的座標(X,Y) : ");
			scanf_s("%d %d", &posx, &posy);
		} while (posx < 1 || posx > 3 || posy < 1 || posy > 3);//判斷錘子的範圍
		
		if (mousex == posx && mousey == posy)//判斷錘子的座標與地鼠的座標是否一致
			hits++;
		else
			missed++;

		for (j = 1; j <= 3; j++)//檢查Y座標
		{
			for (k = 1; k <= 3; k++)//檢查X座標
			{
				if (j == posy && k == posx)// 錘子的效果圖
					printf("■");
				else if (j == mousey && k == mousex)//地鼠的效果圖
					printf("☆");
				else
					printf("□"); 
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("擊中 : %d次，未擊中 : %d次\n\n", hits, missed);//列印擊中或未擊中的次數
	printf("========遊戲結束========\n\n");

	system("pause");
	return 0;
}