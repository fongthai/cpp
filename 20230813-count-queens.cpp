/* Count queens
Cho ma trận n dòng x n cột (n<=100), mỗi ô có 1 giá trị bất kỳ được input.
Một ô được gọi là "queen" khi nó có giá trị lớn nhất 
trên dòng, cột và hai đường chéo đi qua nó.

Vd:
Input: Nhập n và các dòng tiếp theo của ma trận
3
1 5 6
3 5 9
8 4 2

Output: Số lượng các số queen
2
*/

#include <iostream>
using namespace std;

void print2DArray(int** arr, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n ; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

void input2DArray(int** &arr, int &n){
	cin >> n;	// Read the number
	arr = new int*[n];

	for(int i=0; i<n; i++){ // read matrix data
		arr[i] = new int[n];

		for(int j=0;j<n; j++)
			cin >> arr[i][j];
	}

}

int countQueens(int** arr, int n){

	int queens =0;
	for(int row=0; row<n; row++){ // for each row
		for(int col=0; col<n; col++){ //each column
			bool isQueen = true;
			
			// cùng dòng: [row, element]. Cùng cột [element, col]
			for(int element=0; element<n; element++) //duyệt hết dòng và cột ứng với mỗi con i,j
				if (arr[row][element] > arr[row][col] || arr[element][col] > arr[row][col]){
					isQueen = false;
					break;
				} 
			// Đường chéo trái / trên: [row-1, col-1]
			// Đường chéo trái / dưới: [row+1, col-1]
			// Đường chéo phải / dưới: [row+1, col+1]
			// Đường chéo phải / trên: [row-1, col+1]

			// loop với 2 biến chạy lun nà
			for(int r=row-1,s=col-1 ; r>0 && s>0; --r, --s) // trái-trên
				if (arr[r][s] > arr[row][col]){
					isQueen = false;
					break;
				}
			for(int r=row+1, s=col-1; r<n && s>0; ++r, --s) // trái-dưới
				if (arr[r][s] > arr[row][col]){
					isQueen = false;
					break;
				}
			
			for(int r=row+1,s=col+1 ; r<n && s<n; ++r, ++s) // phải-dưới
				if (arr[r][s] > arr[row][col]){
					isQueen = false;
					break;
				}
			for(int r=row-1, s=col+1; r>0 && s<n; --r, ++s) // phải-trên
				if (arr[r][s] > arr[row][col]){
					isQueen = false;
					break;
				}
			
			// Đến được đây mà không break thì là queen rùi, nhưng phải kiểm tra isQueen mới biết
			if (isQueen)
                queens++;
        }
    }
	return queens;
}

int main(){
	int size, tmpMax = 0;
	int** arrayToCheck;

	input2DArray(arrayToCheck, size);
	//print2DArray(arrayToCheck, size);

	cout << countQueens(arrayToCheck, size);

	delete [] arrayToCheck; 
	//cout << "done";
	return 0;
}