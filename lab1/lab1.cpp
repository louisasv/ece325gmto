#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> list1, list2;
    string input;
    int num;

    cout << "Enter first sorted list (end with #): ";
    while (cin >> input && input != "#") {
        if (input.back() == ',') input.pop_back(); // remove trailing comma
        num = stoi(input);
        list1.push_back(num);
    }

    cout << "Enter second sorted list (end with #): ";
    while (cin >> input && input != "#") {
        if (input.back() == ',') input.pop_back(); // remove trailing comma
        num = stoi(input);
        list2.push_back(num);
    }

    vector<int> common;
    int sum = 0;
    int i = 0, j = 0;
    int comparisons = 0;

    while (i < list1.size() && j < list2.size()) {
        comparisons++;
        if (list1[i] == list2[j]) {
            common.push_back(list1[i]);             // if the elements are equal, add to common and sum
            sum += list1[i];
            i++;                                    //increase the index of list1
            j++;                                    //increase the index of list2
        } else if (list1[i] < list2[j]) {
            i++;                                    // if list1's element is smaller, move to next element of list1
        } else {
            j++;                                    // if list2's element is smaller, move to next element of list2
        }
    }

    cout << "Common elements: ";
    for (int val : common) cout << val << " ";
    cout << "\nSum of common elements: " << sum << endl;

    cout << "Maximum number of comparisons: m + n - 1" << endl;
    cout << "Actual comparisons made: " << comparisons << endl;

    return 0;
}
