#include <iostream>
#include <sstream>
using namespace std;

char area[100][100];
int colorBlindPerson = 0, ordinaryPerson = 0;

void glassFire(int n, int areaY, int areaX, char color)
{ 
	
	if (area[areaY][areaX] == color) {
		if (color == 'G')
			area[areaY][areaX] = 'R';
		area[areaY][areaX] += 32;
	}
	else return;

	if (areaX + 1 < n) 
		glassFire(n, areaY, areaX + 1, color);
	if (areaY + 1 < n) 
		glassFire(n, areaY + 1, areaX, color);
	if (areaX - 1 >= 0)
		glassFire(n, areaY, areaX - 1, color);
	if (areaY - 1 >= 0)
		glassFire(n, areaY - 1, areaX, color);
}


int Serching(int n, int type)
{
	int areaCount = 0;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			//¾¾µå
			if (area[j][i] == 'R' + 32 * type || area[j][i] == 'G' + 32 * type || area[j][i] == 'B' + 32 * type)
			{
				areaCount++;
				glassFire(n, j, i, area[j][i]);
			}
		}
	}
	
	return areaCount;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < n; j++) {
			area[i][j] = input[j];
		}
	}

	ordinaryPerson = Serching(n, 0);
	colorBlindPerson = Serching(n, 1);

	cout << ordinaryPerson << " " << colorBlindPerson << "\n";

	return 0;
}