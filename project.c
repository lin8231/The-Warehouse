/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */
// NAME: JIARU LIN
// UID: 536902223
// UPI: JLIN296


#include "project.h"

// This function outputs the amount of time that has elapsed (in seconds) given 
// two pairs of minutes and seconds as inputs. The function calculates the time 
// elapsed by converting the pairs of minutes and seconds into just seconds, and
// taking the positive difference between the two. 
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{
	int timeA, timeB;

	timeA = minuteA*60 + secondA;
	timeB = minuteB*60 + secondB;

	if (timeB < timeA){
		return timeA - timeB;
	}
	else
	{
		return timeB - timeA;
	}
	
}


// This function looks for the largest prime number that is smaller than the input
// number and returns it as the output. It cycles through numbers smaller than the 
// input number in decreasing order, and checks whether each number is divisible by 
// numbers (other than 1) that are smaller than it. If it is divisible by some number, 
// then it is not a prime number. The function returns the first value that has no 
// whole divisors. 
int WarehouseAddress(int maximum)
{
	int flag = 0;
	int divisor, dividend;

	for (dividend = maximum - 1; dividend > 2; dividend--)
	{
		for (divisor = 2 ; divisor <= dividend/2; divisor++)
		{
			if (dividend % divisor == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			return dividend;
		}
		flag = 0;
	}
	return 2;
}


// This function takes a string as input and edits the string such that each character 
// in the string has shifted one character to the left (and the first character has
// wrapped around to become the last character) by the end of the function. 
void Advertise(char *words)
{
	int wordslength;
	wordslength = strlen(words);

	char temp;
	temp = words[0];

	for (int i = 0; i < wordslength-1; i++){
		words[i] = words[i+1];
	}

	words[wordslength-1] = temp;
}

// This function returns the smallest unique as output given the input of an array
// containing a sequence of unassorted positive integers. It first cycles through 
// each number in the array to check if it is unique. If it is, then the value is
// compared against the current minimum value and the current minimum value is replaced
// if a lower value is found. 
int WinningBid(int *values, int length)
{
	int min = -1;
	int i, j;
	int counter = 0;

	for (i = 0; i < length; i++)
	{
		for (j = 0; j < length; j++)
		{
			if (values[i] == values[j])
			{
				counter++;
			}
		}
		if (counter == 1)
		{
			if (min == -1 || values[i] < min)
			{
				min = values[i];
			}
		}
		counter = 0;
	}
	return min;
}

// This function edits a string to contain the representation of a box with a center
// mark given an empty string, and the height and the width of the box required. The 
// outer rim of the box is represneted by asterisks. The center of the box is represented
// by one or more "X"s. It does so by making an empty arary of the appropriate size
// first, then writing the asterisks in using for loops. Then, after checking wehther 
// the row and column numbers are even or odd, the function places the "X" center mark(s) 
// accordingly as long as the box is big enough to fit center marks.  
void BoxDesign(char *design, int width, int height)
{
	int i;

	for (i = 0; i < (width+1)*height-1; i++){
		design[i] = ' ';
	}
	for (i = 0; i <width; i++){
		design[i] = '*';
	}
	for (i = width; i <= (width+1)*height; i += (width+1)){
		design[i] = '\n';
	}
	for (i = width+1; i < (width+1)*height; i += (width+1)){
		design[i] = '*';
	}
	for (i = 2*width; i < (width+1)*height; i += (width+1)){
		design[i] = '*';
	}
	for (i = (width+1)*(height-1); i < (width+1)*height-1; i++){
		design[i] = '*';
	}
	design[(width+1)*height-1] = '\n';

	int colX, rowX;

	if (width%2){
		colX = 1;
	} else 
	{
		colX = 2;
	}
	
	if (height%2){
		rowX = 1;
	} else
	{
		rowX = 2;
	}
	
	if (colX == 1 && rowX ==1 && width >= 3 && height >= 3){
		design[(width+1)*height/2-1] = 'X';
	} else if (colX == 1 && rowX == 2 && width >= 3 && height >= 3){
		design[(width+1)*(height-1)/2-1] = 'X';
		design[(width+1)*(height+1)/2-1] = 'X';
	} else if (colX == 2 && rowX == 1 && width >= 3 && height >= 3){
		design[(width+1)*(height)/2-1] = 'X';
		design[(width+1)*(height)/2] = 'X';
	} else if (colX == 2 && rowX == 2 && width >= 3 && height >= 3){
		design[(width+1)*(height-1)/2-1] = 'X';
		design[(width+1)*(height-1)/2] = 'X';
		design[(width+1)*(height+1)/2-1] = 'X';
		design[(width+1)*(height+1)/2] = 'X';
	}
}

// This function takes a 10x10 2D array as input which represents a map of the warehouse 
// floor with one worker (represented by 1) and one box (represented by 2). The function 
// edits the 2D array such that the direct route from the worker to the box is represented
// by the number 3 in the array. The worker must reach the box in two straight lines, first
// horizontally then vertically. The function does this by finding the index positions of 
// the worker and the box. Depending on if the box is to the left or right of the worker, 
// the worker moves in the box's direction until he reaches the same column as the box, or 
// the box is on the same row as the worker, then the worker moves until he is just beside
// the box. Then, if the worker has not yet reached the box, he move up/down in the direction 
// of the box until he reaches the box. 
void WorkerRoute(int warehouse[10][10])
{
	int i, row, col, workerRow = -1, workerCol = -1, boxRow = -1, boxCol = -1;
	
	for (row = 0; row < 10; row++){
		for (col = 0; col <10; col++){
			if (warehouse[row][col] == 1){
				workerRow = row;
				workerCol = col;
			}
			else if (warehouse[row][col] == 2){
				boxRow = row;
				boxCol = col;
			}
		}
	}
	
	if (boxCol > workerCol){
		if (boxRow == workerRow){
			for (i = workerCol+1; i < boxCol; i++){
				warehouse[workerRow][i] = 3;
			}
		} else{
			for (i = workerCol+1; i <= boxCol; i++){
				warehouse[workerRow][i] = 3;
			}
		}
	} else if (boxCol < workerCol){
		if (boxRow == workerRow){
			for (i = workerCol-1; i > boxCol; i--){
			warehouse[workerRow][i] = 3;
			}
		} else {
		for (i = workerCol-1; i >= boxCol; i--){
			warehouse[workerRow][i] = 3;
			}
		}
	}

	if (boxRow > workerRow){
		for (i = workerRow+1; i < boxRow; i++){
			warehouse[i][boxCol] = 3;
		}
	} else if (boxRow < workerRow){
		for (i = workerRow-1; i > boxRow; i--){
			warehouse[i][boxCol] = 3;
		}
	}
}

// This ia a helper function that takes the map of the warehouse as an input and  
// edits the array to move the worker up (and only up) if it is a legal move. 
// It does so by first finding the position of the worker. Then for each move, it 
// checks if the destination of the move is an empty space. If it is an empty sapce, the 
// worker gets moved there and the square where the worker initially was becomes empty. If
// space that the worker is trying to move to contains a box, if the space next to the box
// is empty, the worker can push the box. Else both the box and the worker stay where
// they are. 
void MoveUp(int warehouse[10][10])
{
	int row, col, workerRow = -1, workerCol = -1;

	for (row = 0; row < 10; row++){
		for (col = 0; col <10; col++){
			if (warehouse[row][col] == 5 || warehouse[row][col] == 6){
				workerRow = row;
				workerCol = col;
				
			}
		}
	}

	if (warehouse[workerRow-1][workerCol] == 0){ //if row above has empty space
		warehouse[workerRow-1][workerCol] = 5; //row above gets occupied by worker
		if (warehouse[workerRow][workerCol] == 5){
			warehouse[workerRow][workerCol] = 0; //original worker spot becomes empty
		} else {
			warehouse[workerRow][workerCol] = 2; //original worker spot becomes a target
		}
	} else if (warehouse[workerRow-1][workerCol] == 3 && warehouse[workerRow-2][workerCol] == 0){
		//if row above has a box AND 2 rows above it is empty
		warehouse[workerRow-2][workerCol] = 3; //2 rows above becomes box
		warehouse[workerRow-1][workerCol] = 5; //above row becomes worker
		if (warehouse[workerRow][workerCol] == 5){
			warehouse[workerRow][workerCol] = 0; //original worker spot becomes empty
		} else {
			warehouse[workerRow][workerCol] = 2; //original worker spot becomes a target
		}
	} else if (warehouse[workerRow-1][workerCol] == 2){ //if row above is a target
		warehouse[workerRow-1][workerCol] = 6; //row above becomes WORKER ON TARGET
		if (warehouse[workerRow][workerCol] == 5){
			warehouse[workerRow][workerCol] = 0; //original worker spot becomes empty
		} else {
			warehouse[workerRow][workerCol] = 2; //original worker spot becomes a target
		}
	} else if (warehouse[workerRow-1][workerCol] == 3 && warehouse[workerRow-2][workerCol] == 2){
		//if row above has a box AND 2 rows above it is a target
		warehouse[workerRow-2][workerCol] = 4; //2 rows above becomes BOX ON TARGET
		warehouse[workerRow-1][workerCol] = 5; //above row becomes worker
		if (warehouse[workerRow][workerCol] == 5){
			warehouse[workerRow][workerCol] = 0; //original worker spot becomes empty
		} else {
			warehouse[workerRow][workerCol] = 2; //original worker spot becomes a target
		}
	} else if (warehouse[workerRow-1][workerCol] == 4 && warehouse[workerRow-2][workerCol] == 0){
		//if row above has a BOX ON TARGET and the row above the BOX ON TARGET is empty
		warehouse[workerRow-2][workerCol] = 3; //2 rows above becomes box
		warehouse[workerRow-1][workerCol] = 6; //above row becomes WORKER ON TARGET
		if (warehouse[workerRow][workerCol] == 5){
			warehouse[workerRow][workerCol] = 0; //original worker spot becomes empty
		} else {
			warehouse[workerRow][workerCol] = 2; //original worker spot becomes a target
		}		
	} else if (warehouse[workerRow-1][workerCol] == 4 && warehouse[workerRow-2][workerCol] == 2){
		// if row about has BOX ON TARGET and the row above that is TARGET
		warehouse[workerRow-2][workerCol] = 4; //2 rows above becomes box
		warehouse[workerRow-1][workerCol] = 6; //above row becomes WORKER ON TARGET
		if (warehouse[workerRow][workerCol] == 5){
			warehouse[workerRow][workerCol] = 0; //original worker spot becomes empty
		} else {
			warehouse[workerRow][workerCol] = 2; //original worker spot becomes a target
		}	
	}

}


// This is a function that takes an array that represents the warehouse floor and a move as
// input and changes the positions of the objects on the map according to the requested move
// (if the move is legal). It does so by calling the MoveUp helper function. If the requested
// move is not UP, the warehouse array is rotated such that the move becomes UP in the new 
// orientation of the array and after MoveUp is executed, the array is rotated back into its 
// original state. It checks for the completion for the game within every call by cycling 
// each value of the warehouse array at the end of the function to check if there are any 
// unoccupied targets left (represented by 2). If there is any, the game is incomplete. If 
// there is none, the game is complete. 
int MakeMove(int warehouse[10][10], char move)
{
	int rotatedWarehouse[10][10];
	int numTargets = 0;

	for (int i = 0; i < 10; i++){ //find the number of targets on the board for later use
		for (int j = 0; j < 10; j++){
			if (warehouse[i][j] == 2 || warehouse[i][j] == 4 || warehouse[i][j] == 6){
				numTargets++;
			}
		}
	}

	if (move == 'w'){
		MoveUp(warehouse);
	}

	if (move == 's'){
		for (int i = 0; i <10; i++){
			for (int j = 0; j < 10; j++){
				rotatedWarehouse[i][j] = warehouse[9-i][9-j];
			}
		}
		MoveUp(rotatedWarehouse);
		for (int i = 0; i <10; i++){
			for (int j = 0; j < 10; j++){
				warehouse[i][j] = rotatedWarehouse[9-i][9-j];
			}
		}
	}

	if (move == 'a'){
		for (int i = 0; i <10; i++){
			for (int j = 0; j < 10; j++){
				rotatedWarehouse[j][i] = warehouse[9-i][j];
			}
		}
		MoveUp(rotatedWarehouse);
		for (int i = 0; i <10; i++){
			for (int j = 0; j < 10; j++){
				warehouse[j][i] = rotatedWarehouse[i][9-j];
			}
		}
	}

	if (move == 'd'){
		for (int i = 0; i <10; i++){
			for (int j = 0; j < 10; j++){
				rotatedWarehouse[j][i] = warehouse[i][9-j];
			}
		}
		MoveUp(rotatedWarehouse);
		for (int i = 0; i <10; i++){
			for (int j = 0; j < 10; j++){
				warehouse[j][i] = rotatedWarehouse[9-i][j];
			}
		}
	}

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (warehouse[i][j] == 2){
				// printf("one");
				return 0;
			}
		}
	}

	if (numTargets == 0){
		// printf("two");
		return 0;
	}

	// printf("three");
	return 1;

}

