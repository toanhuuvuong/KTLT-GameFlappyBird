#include"1.h"
#define second 100
#define discoutPipe 4
int main()
{
	resizeCMD(1200, 600);
	int k;
	do
	{
		system("cls");
		int flag1, flag2, flag3 = 0;
		flag1 = flag2 = 0;
		KHUNG khung;
		creatKhung(khung);
		displayKhung(khung);

		BIRD bird;
		creatBird(bird);

		PIPE *arrayOver, *arrayUnder;
		arrayOver = new PIPE[discoutPipe];
		arrayUnder = new PIPE[discoutPipe];
		creatPipe(arrayOver[0], arrayUnder[0], khung);

		SCORE score;
		creatScore(score, khung);
		gotoxy(khung.n + 30, 1);
		textColor(14);
		printf("SCORE = ");
		displayScore(score);
		textColor(15);

		gotoxy(khung.n + 20, 5);
		textColor(9);
		printf("PRESS <W> TO CONTROL THE BIRD");
		textColor(15);
		int key;
		while (1)
		{
			if (_kbhit())
			{
				key = _getch();
				if (key == 'W' || key == 'w')
					bird.tt = UP;
			}
			conTrol(bird, arrayOver, arrayUnder, khung, flag1, flag2, flag3);
			if (winLost(bird, arrayOver, arrayUnder, khung) == 0)
			{
				gotoxy(0, khung.m + 1);
				textColor(11);
				printf("====================================YOU LOST=================================");
				textColor(7);
				break;
			}
			addScore(score, bird, arrayOver, arrayUnder, khung);
			Sleep(second);
		}
		delete[] arrayOver;
		delete[] arrayUnder;
		printf("\nDO YOU WANT TO PLAY AGAIN ?\n1. YES\t2. NO\n");
		scanf_s("%d%*c", &k);
		printf("YOU CHOOSE %d", k);
	} while (k == 1);
	_getch();
	return 0;
}