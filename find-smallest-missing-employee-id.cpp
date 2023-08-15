/*
Công ty XYZ nay tuyển thêm 1 nhân viên mới. 
Do đợt vừa rồi có rất nhiều nhân viên nghỉ việc nên có một số mã số nhân viên không sử dụng.

Vì chưa có thời gian tổ chức lại dữ liệu. 
Tổng giám đốc công ty XYZ muốn nhờ bạn thống kê và đưa ra mã số nhân viên còn trống nhỏ nhất để công ty cấp cho nhân viên mới.

Công ty sẽ gửi bạn danh sách các mã số nhân viên đang làm việc tại công ty theo thứ tự lộn xộn.

Bạn sẽ gửi lại cho giám đốc mã số nhân viên còn trống nhỏ nhất.

Mã số nhân viên là một dãy số tự nhiên trong khoảng từ 1 tới 100000.

INPUT:
Dòng đầu: số n nguyên dương <=1000 là số lượng nhân viên hiện tại.
Dòng sau: là n số nguyên là msnv của các nhân viên, 

OUTPUT: MSNV còn trống nhỏ nhất

Vd:
input:
4
1 2 4 6

output:
5
*/

#include <iostream>
#include <algorithm>	// for using the sort function
using namespace std;

void inputArray(int arr[], int &n) {
    cin >> n;  // Read the integer n

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  // Read each element of the array
    }
}

int findSmallestNotInArray(int inputArray[], int sizeOfArray) {
    int sortedArray[1000];
	int smallestNotInArray = 1;

    for (int i = 0; i < sizeOfArray; ++i) {	// copy to a temporary array
        sortedArray[i] = inputArray[i];
    }

    sort(sortedArray, sortedArray + sizeOfArray);  //sort it

    for (int i = 0; i < sizeOfArray; ++i) {
        if (sortedArray[i] > smallestNotInArray)
			break;	// that's it, no need to test further
        else
            smallestNotInArray = sortedArray[i] + 1; // just take the next number to compare with the next one in the array
    }

    return smallestNotInArray;
}

int main() {
    int numberOfEmployee;
    int employeeArray[1000];  // Create an array to store the input

    inputArray(employeeArray, numberOfEmployee);

    int smallestNotInArray = findSmallestNotInArray(employeeArray, numberOfEmployee);

    cout << smallestNotInArray << endl;

    return 0;
}