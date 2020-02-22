#include"1.h"
#define birdX 20
#define birdY 13
#define discoutPipe 4
const int doc = 186, ngang = 205, cach = 32;
// dat lai kich thuoc khung
void resizeCMD(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT bien;
	GetWindowRect(console, &bien);
	MoveWindow(console, bien.left, bien.top, width, height, TRUE);
}
// To mau 
void textColor(int x)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}
// Ham dich chuyen con tro den toa do x y
void gotoxy(int x, int y)
{
	HANDLE toaDoDen;
	COORD toaDoHienTai = { x, y };
	toaDoDen = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(toaDoDen, toaDoHienTai);
}
// ve hinh
void veHinh(int x, int y, int c, int color)
{
	gotoxy(x, y);
	textColor(color);
	printf("%c", c);
	textColor(7);
}
// tao khung
void creatKhung(KHUNG &khung)
{
	khung.m = 20, khung.n = 80;
}
// xuat khung
void displayKhung(KHUNG khung)
{
	for (int i = 0; i < khung.m; i++)
	{
		for (int j = 0; j < khung.n; j++)
		{
			if (i == 0 || i == khung.m - 1)
				veHinh(j, i, ngang, 200);
			else veHinh(j, i, cach, 7);
		}
		printf("\n");
	}
}
// xoa khung
void deleteKhung(KHUNG khung)
{
	for (int i = 0; i < khung.m; i++)
	{
		for (int j = 0; j < khung.n; j++)
		{
			if (i == 0 || j == 0 || i == khung.m - 1 || j == khung.n - 1)
				veHinh(j, i, ' ', 7);
		}
	}
}
// tao con chim dang bay len
void creatBird(BIRD &bird)
{
	bird.nBody = 9;
	bird[0].x = birdX; // dau
	bird[0].y = birdY;
	bird[1].x = birdX - 1; // co
	bird[1].y = birdY;
	bird[2].x = birdX - 2; // than 1
	bird[2].y = birdY;
	bird[3].x = birdX - 3; // than 2
	bird[3].y = birdY;
	bird[4].x = birdX - 4;// than 3
	bird[4].y = birdY;
	bird[5].x = birdX - 3; // canh 1
	bird[5].y = birdY - 1;
	bird[6].x = birdX - 4; // canh 2
	bird[6].y = birdY - 1;
	bird[7].x = birdX - 5; // canh 3
	bird[7].y = birdY - 1;
	bird[8].x = birdX - 5; // duoi
	bird[8].y = birdY;
	bird.tt = DOWN;
}
// hien thi con chim dang bay len
void displayBird1(BIRD &bird)
{
	bird[5].x = bird[0].x - 3; // canh 1
	bird[5].y = bird[0].y - 1;
	bird[6].x = bird[0].x - 4; // canh 2
	bird[6].y = bird[0].y - 1;
	bird[7].x = bird[0].x - 5; // canh 3
	bird[7].y = bird[0].y - 1;
	veHinh(bird[0].x, bird[0].y, 'Q', 15);
	veHinh(bird[1].x, bird[1].y, '=', 15);
	for (int i = 2; i < bird.nBody - 1; i++)
		veHinh(bird[i].x, bird[i].y, '\\', 15);
	veHinh(bird[bird.nBody - 1].x, bird[bird.nBody - 1].y, '<', 15);
}
// hien thi con chim dang bay xuong
void displayBird2(BIRD &bird)
{
	bird[5].x = bird[0].x - 3; // canh 1
	bird[5].y = bird[0].y + 1;
	bird[6].x = bird[0].x - 4; // canh 2
	bird[6].y = bird[0].y + 1;
	bird[7].x = bird[0].x - 5; // canh 3
	bird[7].y = bird[0].y + 1;
	veHinh(bird[0].x, bird[0].y, 'Q', 15);
	veHinh(bird[1].x, bird[1].y, '=', 15);
	for (int i = 2; i < bird.nBody - 1; i++)
		veHinh(bird[i].x, bird[i].y, '/', 15);
	veHinh(bird[bird.nBody - 1].x, bird[bird.nBody - 1].y, '<', 15);
}
// xoa con chim
void deleteBird(BIRD bird)
{
	for (int i = 0; i < bird.nBody; i++)
		veHinh(bird[i].x, bird[i].y, ' ', 7);
}
//  tao ong nuoc
void creatPipe(PIPE &overpipe, PIPE &underpipe, KHUNG khung)
{
	srand(time(0));
	overpipe.width = underpipe.width = 3;
	overpipe.height = 1 + rand() % (khung.m - 5);
	underpipe.height = khung.m - overpipe.height - 8;
	overpipe.td.x = underpipe.td.x = khung.n - 3;
	overpipe.td.y = 1;
	underpipe.td.y = khung.m - underpipe.height - 1;
	overpipe.tt = underpipe.tt = LEFT;
}
// hien thi ong nuoc
void displayPipe(PIPE overpipe, PIPE underpipe)
{
	for (int i = 0; i < overpipe.height; i++)
	{
		for (int j = 0; j < overpipe.width; j++)
			veHinh(overpipe.td.x - j, overpipe.td.y + i, ' ', 160);
	}
	for (int i = 0; i < underpipe.height; i++)
	{
		for (int j = 0; j < underpipe.width; j++)
			veHinh(underpipe.td.x - j, underpipe.td.y + i, ' ', 160);
	}
}
// xoa ong nuoc
void deletePipe(PIPE overpipe, PIPE underpipe)
{
	for (int i = 0; i < overpipe.height; i++)
	{
		for (int j = 0; j < overpipe.width; j++)
			veHinh(overpipe.td.x - j, overpipe.td.y + i, ' ', 7);
	}
	for (int i = 0; i < underpipe.height; i++)
	{
		for (int j = 0; j < underpipe.width; j++)
			veHinh(underpipe.td.x - j, underpipe.td.y + i, ' ', 7);
	}
}
// tao diem
void creatScore(SCORE &score, KHUNG khung)
{
	score.cout = 0;
	score.td.x = khung.n + 39;
	score.td.y = 1;
}
// hien thi diem
void displayScore(SCORE score)
{
	gotoxy(score.td.x, score.td.y);
	textColor(14);
	printf("%d", score.cout);
}
// dieu khien con chim va ong nuoc
void conTrol(BIRD &bird, PIPE *arrayOver, PIPE *arrayUnder, KHUNG khung, int &flag1, int &flag2, int &flag3)
{
	// dieu khien ong nuoc chinh
	if (arrayOver[0].tt == LEFT)
	{
		if (arrayOver[0].td.x == 0)
		{
			deletePipe(arrayOver[0], arrayUnder[0]);
			creatPipe(arrayOver[0], arrayUnder[0], khung);
		}
		else
		{
			deletePipe(arrayOver[0], arrayUnder[0]);
			arrayOver[0].td.x--;
			arrayUnder[0].td.x--;
		}
		displayPipe(arrayOver[0], arrayUnder[0]);
	}
	// truong hop tao them ong nuoc 1
	if (arrayOver[0].td.x == (khung.n - 1) * 3 / 4 && flag1 == 0)
	{
		creatPipe(arrayOver[1], arrayUnder[1], khung);
		displayPipe(arrayOver[1], arrayUnder[1]);
		flag1 = 1;
	}
	if (flag1 == 1 && arrayOver[1].tt == LEFT)
	{
		if (arrayOver[1].td.x == 0)
		{
			deletePipe(arrayOver[1], arrayUnder[1]);
			creatPipe(arrayOver[1], arrayUnder[1], khung);
		}
		else
		{
			deletePipe(arrayOver[1], arrayUnder[1]);
			arrayOver[1].td.x--;
			arrayUnder[1].td.x--;
		}
		displayPipe(arrayOver[1], arrayUnder[1]);
	}

	// truong hop tao them ong nuoc 2
	if (arrayOver[0].td.x == (khung.n - 1) * 2 / 4 && flag2 == 0)
	{
		creatPipe(arrayOver[2], arrayUnder[2], khung);
		displayPipe(arrayOver[2], arrayUnder[2]);
		flag2 = 1;
	}
	if (flag2 == 1 && arrayOver[2].tt == LEFT)
	{
		if (arrayOver[2].td.x == 0)
		{
			deletePipe(arrayOver[2], arrayUnder[2]);
			creatPipe(arrayOver[2], arrayUnder[2], khung);
		}
		else
		{
			deletePipe(arrayOver[2], arrayUnder[2]);
			arrayOver[2].td.x--;
			arrayUnder[2].td.x--;
		}
		displayPipe(arrayOver[2], arrayUnder[2]);
	}
	// truong hop tao them ong nuoc 3
	if (arrayOver[0].td.x == (khung.n - 1) * 1 / 4 && flag3 == 0)
	{
		creatPipe(arrayOver[3], arrayUnder[3], khung);
		displayPipe(arrayOver[3], arrayUnder[3]);
		flag3 = 1;
	}
	if (flag3 == 1 && arrayOver[3].tt == LEFT)
	{
		if (arrayOver[3].td.x == 0)
		{
			deletePipe(arrayOver[3], arrayUnder[3]);
			creatPipe(arrayOver[3], arrayUnder[3], khung);
		}
		else
		{
			deletePipe(arrayOver[3], arrayUnder[3]);
			arrayOver[3].td.x--;
			arrayUnder[3].td.x--;
		}
		displayPipe(arrayOver[3], arrayUnder[3]);
	}
	// dieu khien con chim
	if (bird.tt == UP)
	{
		deleteBird(bird);
		for (int i = 0; i < bird.nBody; i++)
			bird[i].y--;
		displayBird1(bird);
		bird.tt = DOWN;
	}
	else if (bird.tt == DOWN)
	{
		deleteBird(bird);
		for (int i = 0; i < bird.nBody; i++)
			bird[i].y++;
		displayBird2(bird);
	}
}
// tinh diem
void addScore(SCORE &score, BIRD bird, PIPE *arrayOver, PIPE *arrayUnder, KHUNG khung)
{
	for (int i = 0; i < discoutPipe; i++)
	{
		if (bird[8].x == arrayOver[i].td.x + 1) // cai duoi con chim vuot qua ong +1
		{
			score.cout++;
			displayScore(score);
		}
	}
}
// xu li thang thua
int winLost(BIRD bird, PIPE *arrayOver, PIPE *arrayUnder, KHUNG khung)
{
	// kiem tra khung
	for (int k = 0; k < bird.nBody; k++)
		if (bird[k].y == khung.m - 1 || bird[k].y == 0) return 0;
	// kiem tra cac ong nuoc
	for (int pipe = 0; pipe < discoutPipe; pipe++)
		{
			for (int i = 0; i < arrayOver[pipe].height; i++)
				for (int j = 0; j < arrayOver[pipe].width; j++)
					for (int k = 0; k < bird.nBody; k++)
						if (bird[k].x == arrayOver[pipe].td.x - j && bird[k].y == arrayOver[pipe].td.y + i) return 0;
			for (int i = 0; i < arrayUnder[pipe].height; i++)
				for (int j = 0; j < arrayUnder[pipe].width; j++)
					for (int k = 0; k < bird.nBody; k++)
						if (bird[k].x == arrayUnder[pipe].td.x - j && bird[k].y == arrayUnder[pipe].td.y + i) return 0;
		}
	return 1;
}