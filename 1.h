#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
enum TRANGTHAI { UP, DOWN, LEFT};
struct toaDo
{
	int x;
	int y;
}; typedef struct toaDo TOADO;
struct khung
{
	int m;
	int n;
}; typedef struct khung KHUNG;
struct bird
{
	TOADO body[9];
	int nBody;
	TRANGTHAI tt;
	TOADO& operator[](int i)
	{
		if (i < nBody && body != NULL)
			return body[i];
	}
}; typedef struct bird BIRD;
struct pipe
{
	int height;
	int width;
	TOADO td;
	TRANGTHAI tt;
}; typedef struct pipe PIPE;
struct score
{
	int cout;
	TOADO td;
}; typedef struct score SCORE;
void resizeCMD(int, int);
void gotoxy(int, int);
void textColor(int);
void veHinh(int, int, int, int);

void creatKhung(KHUNG &);
void displayKhung(KHUNG);
void deleteKhung(KHUNG);

void creatBird(BIRD &);
void displayBird1(BIRD &);
void displayBird2(BIRD &);
void deleteBird(BIRD);

void creatPipe(PIPE &, PIPE &, KHUNG);
void displayPipe(PIPE, PIPE);
void deletePipe(PIPE, PIPE);

void creatScore(SCORE &, KHUNG);
void displayScore(SCORE);

void conTrol(BIRD &, PIPE *, PIPE *, KHUNG, int &, int &, int &);
void addScore(SCORE &, BIRD, PIPE *, PIPE *, KHUNG);
int winLost(BIRD, PIPE *, PIPE *, KHUNG);