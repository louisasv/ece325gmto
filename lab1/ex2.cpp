#include <iostream>
#include <algorithm>
using namespace std;

// Global array of 10 integers
int arr[10];

// (a) Find average value
double findAverage() {
    int sum = 0;
    for (int i = 0; i < 10; i++) sum += arr[i];
    return (double)sum / 10.0;
}

// (b) Difference between largest and smallest number
int differenceMaxMin() {
    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < 10; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal - minVal;
}

// (c) Index of largest element
int indexOfMax() {
    int maxIndex = 0;
    for (int i = 1; i < 10; i++) {
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }
    return maxIndex;
}

// (d) Find unique elements (appear exactly once)
void findUnique() {
    cout << "Unique elements: ";
    for (int i = 0; i < 10; i++) {
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count == 1) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// (e) Raise each element to power of 2
void squareElements() {
    for (int i = 0; i < 10; i++) arr[i] *= arr[i];
}

// (f) Sort the array
void sortArray() {
    sort(arr, arr + 10);
}

// Helper: Print array
void printArray() {
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // User input
    cout << "Enter 10 integers: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "\nArray entered: ";
    printArray();

    cout << "Average value: " << findAverage() << endl;
    cout << "Difference between largest and smallest: " << differenceMaxMin() << endl;
    cout << "Index of largest element: " << indexOfMax() << endl;
    findUnique();

    cout << "\nArray after squaring elements: ";
    squareElements();
    printArray();

    cout << "Array after sorting: ";
    sortArray();
    printArray();

    return 0;
}
