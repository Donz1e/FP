#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int times;//�C��������
	int mousex, mousey;//�a����X�ήy��
	int posx, posy;//��l��X��Y�y��
	int hits = 0, missed = 0;//�έp�����P�������a��������
	int i, j, k;//�`���ܶq

	printf("�п�J�n���a�������� : ");//��J���a������
	scanf_s("%d", &times);
	printf("������\n������\n������\n\n");//�C�L9�Ӧa���}

	srand(time(NULL));//�H���ؤl

	for (i = 1; i <= times; i++)//�`�����a�����ĪG
	{
		mousex = rand() % 3 + 1;//����a�����H����� : 1-3
		mousey = rand() % 3 + 1;
		
		do//��J��l���y��
		{
			printf("�п�J��l���y��(X,Y) : ");
			scanf_s("%d %d", &posx, &posy);
		} while (posx < 1 || posx > 3 || posy < 1 || posy > 3);//�P�_��l���d��
		
		if (mousex == posx && mousey == posy)//�P�_��l���y�лP�a�����y�ЬO�_�@�P
			hits++;
		else
			missed++;

		for (j = 1; j <= 3; j++)//�ˬdY�y��
		{
			for (k = 1; k <= 3; k++)//�ˬdX�y��
			{
				if (j == posy && k == posx)// ��l���ĪG��
					printf("��");
				else if (j == mousey && k == mousex)//�a�����ĪG��
					printf("��");
				else
					printf("��"); 
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("���� : %d���A������ : %d��\n\n", hits, missed);//�C�L�����Υ�����������
	printf("========�C������========\n\n");

	system("pause");
	return 0;
}