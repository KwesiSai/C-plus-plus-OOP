#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findIntersection(const vector<int>& vector1, const vector<int>& vector2) {
    vector<int> intersection;

    // Sort both input vectors
    vector<int> sortedVector1 = vector1;
    vector<int> sortedVector2 = vector2;
    sort(sortedVector1.begin(), sortedVector1.end());
    sort(sortedVector2.begin(), sortedVector2.end());

    // Use two pointers to traverse both sorted vectors
    size_t i = 0;
    size_t j = 0;

    while (i < sortedVector1.size() && j < sortedVector2.size()) {
        if (sortedVector1[i] == sortedVector2[j]) {
            // Found an intersection element
            intersection.push_back(sortedVector1[i]);
            i++;
            j++;
        } else if (sortedVector1[i] < sortedVector2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return intersection;
}

int main() {
    vector<int> vector1;
    vector<int> vector2;

    // Input values into vector1
    int value;
    cout << "Enter values for vector1 (enter -1 to stop): ";
    while (true) {
        cin >> value;
        if (value == -1) break;
        vector1.push_back(value);
    }

    // Input values into vector2
    cout << "Enter values for vector2 (enter -1 to stop): ";
    while (true) {
        cin >> value;
        if (value == -1) break;
        vector2.push_back(value);
    }

    vector<int> intersection = findIntersection(vector1, vector2);

    if (intersection.empty()) {
        cout << "No intersecting elements found." << endl;
    } else {
        cout << "Intersecting set: ";
        for (int i : intersection) {
            cout << i << " ";
        }
        cout <<endl;
    }

    return 0;
}
