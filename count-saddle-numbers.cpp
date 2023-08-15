#include <iostream>
using namespace std;

void input2DArray(int**& arr, int &row, int &col){
	cin >> row >> col;	// Read the number

	arr = new int*[row];

	for(int i=0; i<row; i++){ // read matrix data
		arr[i] = new int[col];

		for(int j=0;j<col; j++)
			cin >> arr[i][j];
	}

}

int findMaxInARow(int**  arr, int col, int rowID){
	int max = arr[rowID][0];
	for(int i=1; i<col; i++)
		if (arr[rowID][i] > max)
			max = arr[rowID][i];
	// cout << max << endl;
	return max;
}

int findMinInAColumn(int** arr, int row, int colID){
	int min = arr[0][colID];
	for(int j=1; j<row; j++)
		if (arr[j][colID] < min)
			min = arr[j][colID];
	// cout << min << endl;
	return min;
}

int countSaddles(int** array, int row, int col){
	int saddles = 0;

	for(int rowIndex=0; rowIndex<row; rowIndex++){
		int maxInCurrentRow = findMaxInARow(array, col, rowIndex); // this is MAX in each i row
		// cout << "Row: " << rowIndex << ".Max row nay la: " << maxInRowI << endl;

		for(int colIndex=0; colIndex<col ; colIndex++){
			// cout << "Checking " <<i << "," << j << endl;

			if (array[rowIndex][colIndex] == maxInCurrentRow){ // Only check those in a row which equal to the max value
				// cout << j << " ";
				int minInCurrentColumn = findMinInAColumn(array, row, colIndex); // this is min in current column
				// cout << "min in " << j <<": " << minInColumnJ <<endl;

				if ( array[rowIndex][colIndex] == minInCurrentColumn)
					saddles++;
			}
		}
		// cout << endl; 
		
	}
	return saddles;

}

int main(){
	int** array;
	int nRow, nCol;

	input2DArray(array, nRow, nCol);
	cout << countSaddles(array, nRow, nCol);
	delete [] array;
	return 0;
}