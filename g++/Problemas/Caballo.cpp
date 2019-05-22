#include <stdio.h>
 
int pos[8][8] = { 0 };
 
int travel(int, int);
 
int travel(int x, int y) {
	int i, j, k, l, m;
	int tmpX, tmpY;
	int count, min, tmp;
 
	//The eight directions the knight can walk (clockwise)
	int ktmoveX[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int ktmoveY[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
 
	 // Test the next coordinates
	int nextX[8] = { 0 };
	int nextY[8] = { 0 };
 
	 // Record the number of ways out in each direction
	int exists[8] = { 0 };
 
	 // Start with 1 mark position
	i = x;
	j = y;
	pos[i][j] = 1;
 
	 // traversing the board
	for (m = 2; m <= 81; m++){
		 // Initialize the number of exits in eight directions
		for (l = 0; l < 9; l++) {
			exists[l] = 0;
		}
		 l = 0; //calculate the direction of the walk
 
			    //Exploring eight directions
		for (k = 0; k < 9; k++) {
			tmpX = i + ktmoveX[k];
			tmpY = j + ktmoveY[k];
			 //Border Skip
			if (tmpX < 0 || tmpY < 0 || tmpX>7 || tmpY>7) {
				continue;
			}
			 //can go, record
			if (pos[tmpX][tmpY] == 0) {
				nextX[l] = tmpX;
				nextY[l] = tmpY;
				 l++; //Can move direction plus 1
			}
		}
		count = l;
		 //No way to go back
		if (count == 0) {
			return 0;
			 //One direction can go.
		}
		else if (count == 1) {
			min = 0;
			 // Find out the number of outlets in the next position
		}
		else {
			for (l = 0; l < count; l++) {
				for (k = 0; k < 9; k++) {
					tmpX = nextX[l] + ktmoveX[k];
					tmpY = nextY[l] + ktmoveY[k];
					if (tmpX < 0 || tmpY < 0 || tmpX>7 || tmpY>7) {
						continue;
					}
					if (pos[tmpX][tmpY] == 0) {
						exists[l]++;
					}
				}
			}
			 // Find the direction of the next position the least way out
			min = 0;
			tmp = exists[0];
			for (l = 0; l < count; l++) {
				if (exists[l] < tmp) {
					tmp = exists[l];
					min = l;
				}
			}
		}
		 // Mark the position passed by the serial number
		i = nextX[min];
		j = nextY[min];
		pos[i][j] = m;
	}
	return 1;
}
 
int main()
{
	int i, j, startX, startY;
	while (1)
	{
		printf("Enter the starting point:");
		scanf("%d%d", &startX, &startY);
		if (travel(startX, startY)) {
			 printf("Travel completed!\n");
		}
		else {
			 printf("Travel failed! \n");
		}
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				printf("%2d ", pos[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
 
	return 0;
}
