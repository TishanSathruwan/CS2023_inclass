#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

void findMedian(vector<int> arr) {
    int n = arr.size();
    vector<int> temp(n);
    int medianIndex = 0;

    for (int i = 0; i < n; i++) {
        // Insert element into sorted array
        int j = medianIndex;
        while (j > 0 && arr[i] < temp[j-1]) {
            temp[j] = temp[j-1];
            j--;
        }
        temp[j] = arr[i];
        medianIndex++;

        // Calculate median
        double median;
        if (medianIndex % 2 == 0) {
            median = (double)(temp[medianIndex/2-1] + temp[medianIndex/2]) / 2.0;
        } else {
            median = (double)temp[medianIndex/2];
        }

        // Print result
        cout << "[";
        for (int k = 0; k < medianIndex; k++) {
            if (k > 0) cout << ", ";
            cout << temp[k];
        }
        cout << "] =";
        cout << fixed <<setprecision(1)<<median << endl;
    }
}

int main() {
    string input;
    cout << "Enter the array of numbers separated by spaces: ";
    getline(cin, input);

    stringstream ss(input);
    vector<int> arr;

    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    
    findMedian(arr);
    return 0;
}
