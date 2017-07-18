#include<iostream>
#include<windows.h>


using namespace std;

void gotoxy(int x, int y)   //콘솔 커서 제어  
{

	COORD Pos;

	Pos.X = x;

	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void rotate_left(int var[4][4]) {

	int temp[4][4] = { { var[0][3],var[1][3],var[2][3],var[3][3] },{ var[0][2],var[1][2],var[2][2],var[3][2] },{ var[0][1],var[1][1],var[2][1],var[3][1] },{ var[0][0],var[1][0],var[2][0],var[3][0] } };
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			var[i][j] = temp[i][j];
		}
	}

}


void rotate_right(int var[4][4]) {

	int temp[4][4] = { { var[3][0],var[2][0],var[1][0],var[0][0] },{ var[3][1],var[2][1],var[1][1],var[0][1] },{ var[3][2],var[2][2],var[1][2],var[0][2] },{ var[3][3],var[2][3],var[1][3],var[0][3] } };
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			var[i][j] = temp[i][j];
		}
	}

}





int main() {

	int O[4][4] = { { 0,0,0,0 },{ 0,1,1,0 },{ 0,1,1,0 },{ 0,0,0,0 } };
	int I[4][4] = { { 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 } };
	int T[4][4] = { { 0,0,0,0 },{ 1,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 } };
	int S[4][4] = { { 0,0,0,0 },{ 0,0,1,1 },{ 0,1,1,0 },{ 0,0,0,0 } };
	int J[4][4] = { { 0,0,1,0 },{ 0,0,1,0 },{ 0,1,1,0 },{ 0,0,0,0 } };
	int L[4][4] = { { 0,1,0,0 },{ 0,1,0,0 },{ 0,1,1,0 },{ 0,0,0,0 } };

	bool brk = false;
	char input;
	char rot;

	while (!brk) {
		gotoxy(0, 0);
		cin >> input;
		if (input == 'T') {
			for (int i = 0;i<4;i++) {
				for (int j = 0;j<4;j++) {
					if (T[i][j] == 0) cout << "@@";
					else if (T[i][j] == 1) cout << "■";


				}
				cout << endl;
			}
			cin >> rot;
			while (1) {
				if (rot == 'b') break;
				else if (rot == 'r') {
					rotate_right(T);
					gotoxy(0, 1);
					for (int i = 0;i<4;i++) {
						for (int j = 0;j<4;j++) {
							if (T[i][j] == 0) cout << "@@";
							else if (T[i][j] == 1) cout << "■";
						}
						cout << endl;
					}
					cin >> rot;

				}
				else if (rot == 'l') {
					rotate_left(T);
					gotoxy(0, 1);
					for (int i = 0;i<4;i++) {
						for (int j = 0;j<4;j++) {
							if (T[i][j] == 0) cout << "@@";
							else if (T[i][j] == 1) cout << "■";
						}
						cout << endl;
					}
					cin >> rot;
				}
				else {
					cin >> rot;
					continue;
				}
				
			}
		}
		else if (input == 'S') {
			for (int i = 0;i<4;i++) {
				for (int j = 0;j<4;j++) {
					if (S[i][j] == 0) cout << "@@";
					else if (S[i][j] == 1) cout << "■";


				}
				cout << endl;
			}
			cin >> rot;
			while (1) {
				if (rot == 'b') break;
				else if (rot == 'r') {
					rotate_right(S);
					gotoxy(0, 1);
					for (int i = 0;i<4;i++) {
						for (int j = 0;j<4;j++) {
							if (S[i][j] == 0) cout << "@@";
							else if (S[i][j] == 1) cout << "■";
						}
						cout << endl;
					}
					cin >> rot;

				}
				else if (rot == 'l') {
					rotate_left(S);
					gotoxy(0, 1);
					for (int i = 0;i<4;i++) {
						for (int j = 0;j<4;j++) {
							if (S[i][j] == 0) cout << "@@";
							else if (S[i][j] == 1) cout << "■";
						}
						cout << endl;
					}
					cin >> rot;
				}
				else {
					cin >> rot;
					continue;
				}

			}
		}

		gotoxy(0, 0);
		for (int i = 0;i < 10;i++) {
			cout << "                     "<< endl;
		}


	}




	return 0;
}
