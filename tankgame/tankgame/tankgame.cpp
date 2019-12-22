// tankgame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
//#include<Windows.h>
#include<conio.h>
#include "time.h"




using namespace std;

struct _tagPoint {
	int x;
	int y;
	int count;
	bool rotate;
	bool rotate2;
	int shotDirection=1;
};
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

void Delay(clock_t wait) {
	
	clock_t goal;
	goal = wait + clock();
	while (goal > clock()) {
		
	}
	
}
void SetMap(char MAP[41][41], PPOINT pPlayerPos, PPOINT pTurretPos, PPOINT pShotPos) {
	pPlayerPos->x=20;
	pPlayerPos->y = 36;
	pTurretPos->count = 2;
	pTurretPos->x = pPlayerPos->x+1;
	pTurretPos->y = pPlayerPos->y-1;
	pTurretPos->rotate = true;
	pTurretPos->rotate2 = true;

	strcpy_s(MAP[0], "1111111111111111111111111111111111111111");
	strcpy_s(MAP[1], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[2], "1000000000000000000100000000000000000001");
	strcpy_s(MAP[3], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[4], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[5], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[6], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[7], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[8], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[9], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[10], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[11], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[12], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[13], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[14], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[15], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[16], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[17], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[18], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[19], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[20], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[21], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[22], "1000000000000000000000000000000000000101");
	strcpy_s(MAP[23], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[24], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[25], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[26], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[27], "1010000000000000000000000000000000000001");
	strcpy_s(MAP[28], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[29], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[30], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[31], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[32], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[33], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[34], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[35], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[36], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[37], "1000000000100000000000000000000000000001");
	strcpy_s(MAP[38], "1000000000000000000000000000000000000001");
	strcpy_s(MAP[39], "1111111111111111111111111111111111111111");

}
void MoveUp(char MAP[41][41], PPOINT pPlayerPos, PPOINT pTurretPos) {	
	if (pPlayerPos->y - 1 >= 0) {
		if (MAP[pPlayerPos->y - 1][pPlayerPos->x] != '1') {
			--pPlayerPos->y;
			--pTurretPos->y;
		}
	}			
}
void MoveDown(char MAP[41][41], PPOINT pPlayerPos, PPOINT pTurretPos) {

	if (pPlayerPos->y +1 >= 0) {
		if (MAP[pPlayerPos->y + 1][pPlayerPos->x] != '1') {
			++pPlayerPos->y;
			++pTurretPos->y;

		}
	}


}
void MoveLeft(char MAP[41][41], PPOINT pPlayerPos, PPOINT pTurretPos) {

	if (pPlayerPos-> x-1 >= 0) {
		if (MAP[pPlayerPos->y][pPlayerPos->x-1] != '1') {
			--pPlayerPos->x;
			--pTurretPos->x;

		}
	}


}

void MoveRight(char MAP[41][41], PPOINT pPlayerPos, PPOINT pTurretPos) {

	
		if (MAP[pPlayerPos->y][pPlayerPos->x + 1] != '1') {
			++pPlayerPos->x;
			++pTurretPos->x;

		}
	


}
void turretLeft(char MAP[41][41],PPOINT pPlayerPos, PPOINT pTurretPos) {
	if (pTurretPos->count >= 4)
		pTurretPos->rotate2 = false; //rotate2 오른쪽 회전

			if (pTurretPos->count >=16) {
				
				pTurretPos->count = 1;
				--pTurretPos->x;
				pTurretPos->shotDirection = 1;
			}
           else if (pTurretPos->count >= 12) {
				
				--pTurretPos->y;
				pTurretPos->count++;
				pTurretPos->shotDirection = 4;
			}
			else if(pTurretPos->count>=8){
				
				++pTurretPos->x;
				pTurretPos->count++;
				pTurretPos->shotDirection = 3;
			}
			else if (pTurretPos->count >=4 ) { 
				
				++pTurretPos->y;
				pTurretPos->count++;
				pTurretPos->shotDirection = 2;
			}
			else {
				pTurretPos->rotate2 = true;
				--pTurretPos->x;
				pTurretPos->count++;			
				pTurretPos->shotDirection = 1;//탱크 미사일 위에
			}
			cout << pTurretPos->count;
		
}
void turretRight(char MAP[41][41],PPOINT pPlayerPos, PPOINT pTurretPos) {
	if (pTurretPos->count < 1)
		pTurretPos->rotate = false;


	if (pTurretPos->count <=- 12 ) {
		
		pTurretPos->count = 3;
		++pTurretPos->x;

	}
	else if (pTurretPos->count <=-8) {
		pTurretPos->shotDirection = 2;
		--pTurretPos->y;
		pTurretPos->count--;
	}
	else if (pTurretPos->count <=-4) {
		pTurretPos->shotDirection = 3;
		--pTurretPos->x;
		pTurretPos->count--;
	}
	else if (pTurretPos->count < 1) { //cont %4 >=1
		
		pTurretPos->shotDirection = 4;
		++pTurretPos->y;
		pTurretPos->count--;
	}
	else {
		pTurretPos->rotate = true;
		++pTurretPos->x;
		pTurretPos->count--;
		pTurretPos->shotDirection = 1;
	}
	

}
void tankShot(char MAP[41][41], PPOINT pTurretPos, PPOINT pShotPos) {	
	
	switch (pTurretPos->shotDirection)
	{	
	case 1: 
		pShotPos->x = pTurretPos->x;
		pShotPos->y = pTurretPos->y - 1;
		while (MAP[pShotPos->y+1][pShotPos->x] != '1')
		{			
			--pShotPos->y;	
		}		
		MAP[pShotPos->y][pShotPos->x] = '0';

		break;

	case 2:
		pShotPos->x = pTurretPos->x+1;
		pShotPos->y = pTurretPos->y ;
		while (MAP[pShotPos->y][pShotPos->x+1] != '1')
		{
		--pShotPos->x;
		}
		MAP[pShotPos->y][pShotPos->x] = '0';
		break;

	case 3: pShotPos->x = pTurretPos->x;
		pShotPos->y = pTurretPos->y+1;
		while (MAP[pShotPos->y-1][pShotPos->x] != '1')
		{
			++pShotPos->y;
		}
		MAP[pShotPos->y+1][pShotPos->x] = '0';
		break;
	case 4: 
		pShotPos->x = pTurretPos->x+1;
		pShotPos->y = pTurretPos->y;
		while (MAP[pShotPos->y][pShotPos->x-1] != '1')
		{
			++pShotPos->x;
		}
		MAP[pShotPos->y][pShotPos->x] = '0';
		break;
	default:
		break;
	}

}
void OutMaP(char MAP[41][41], PPOINT pPlayerPos, PPOINT pTurretPos, PPOINT pShotPos) {		
		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 40; j++) {
				if (pTurretPos->y == i && pTurretPos->x == j) {
					cout << "＊";
					MAP[pTurretPos->y=i][pTurretPos->x=j] = '3';
					
				}if (pShotPos->y == i && pShotPos->x == j) {					
					
				}
				
				if (pPlayerPos->y == i && pPlayerPos->x == j) {
					cout << "＊";
				 //중심에서 상하좌우 별 찍
					MAP[pPlayerPos->y][pPlayerPos->x +1] = '2';
					MAP[pPlayerPos->y][pPlayerPos->x + 2] = '2';
					MAP[pPlayerPos->y+1][pPlayerPos->x] = '2';		
					MAP[pPlayerPos->y + 1][pPlayerPos->x+1] = '2';
					MAP[pPlayerPos->y + 1][pPlayerPos->x + 2] = '2';
					MAP[pPlayerPos->y + 2][pPlayerPos->x] = '2';
					MAP[pPlayerPos->y + 2][pPlayerPos->x+1] = '2';
					MAP[pPlayerPos->y + 2][pPlayerPos->x + 2] = '2';
					
				}
				else if (MAP[i][j] == '0') {
					cout << "  ";
				}
				else if (MAP[i][j] == '1') {
					cout << "■";
				}
				else if (MAP[i][j] == '2') {
					cout << "＊";
				}
				
							
			}
			cout<<endl;
		}
		MAP[pPlayerPos->y][pPlayerPos->x + 1] = '0'; //남아있는거 지움
		MAP[pPlayerPos->y][pPlayerPos->x + 2] = '0';
		MAP[pPlayerPos->y + 1][pPlayerPos->x] = '0';
		MAP[pPlayerPos->y + 1][pPlayerPos->x + 1] = '0';
		MAP[pPlayerPos->y + 1][pPlayerPos->x + 2] = '0';
		MAP[pPlayerPos->y + 2][pPlayerPos->x] = '0';
		MAP[pPlayerPos->y + 2][pPlayerPos->x + 1] = '0';
		MAP[pPlayerPos->y + 2][pPlayerPos->x + 2] = '0';
		MAP[pTurretPos->y][pTurretPos->x] = '0';
}

void MoveTank(char MAP[41][41], char Inchar, PPOINT pPlayerPos, PPOINT pTurretPos, PPOINT pShotPos) {
	switch (Inchar)
	{
	case 'w':
	case 'W':
		MoveUp(MAP, pPlayerPos, pTurretPos);
		break;

	case 'a':
	case 'A':MoveLeft(MAP, pPlayerPos, pTurretPos);
		break;

	case 's':
	case 'S':MoveDown(MAP, pPlayerPos, pTurretPos);
		break;

	case 'd':
	case 'D':MoveRight(MAP, pPlayerPos, pTurretPos);
		break;
	case 'j':
	case 'J':if (pTurretPos->rotate == true) {
		turretLeft(MAP, pPlayerPos, pTurretPos);
	}
		break;
	case 'l':
	case 'L':if (pTurretPos->rotate2 == true) {
		turretRight(MAP, pPlayerPos, pTurretPos);
	}
		break;
	case 'k':
	case'K':tankShot(MAP, pTurretPos, pShotPos);
		break;
	default:
		break;
	}
}

int main()
{
	
	
	char s;
	char setMAP[41][41] = {};

	POINT PlayerPos;
	POINT TurretPos;
	POINT ShotPos;

	SetMap(setMAP, &PlayerPos, &TurretPos, &ShotPos);

	while (true)
	{
		cout << "탱크 게임 " << endl;
		cout << "1 : 게임 시작 , 2:게임 종료" << endl;
		

		cin >> s;

		switch (s)
		{
		case '1':
			while (true)
			{
				system("cls");
				OutMaP(setMAP, &PlayerPos, &TurretPos, &ShotPos);
				cout << "wasd 로 조작 공격 : k  포탑 회전:j(왼쪽)l(오른쪽)" << endl;
			
				char Inputchar = _getch();

				MoveTank(setMAP, Inputchar, &PlayerPos, &TurretPos, &ShotPos);

			}


		case '2': exit(0);
		default:
			break;
		}


	}
	return 0;
	
}


