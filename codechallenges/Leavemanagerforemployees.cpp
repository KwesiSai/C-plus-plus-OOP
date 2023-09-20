#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Define a structure to represent holidays
struct Holiday {
    int month;
    int day;
    string occasion;
};

// Function to check if a date is a weekend (Saturday or Sunday)
bool isWeekend(const tm& date) {
    return date.tm_wday == 0 || date.tm_wday == 6;
}

// Function to calculate leave duration (including weekends and holidays)
int calculateLeaveDuration(const tm& startDate, int originalDuration, const vector<Holiday>& holidays, vector<Holiday>& holidaysDuringLeave) {
    tm currentDate = startDate;
    int leaveDays = originalDuration; // Initialize with original duration

    for (int i = 0; i < originalDuration; ++i) {
        // Check if the current date is a predefined holiday
        for (const Holiday& holiday : holidays) {
            if (holiday.month == currentDate.tm_mon + 1 && holiday.day == currentDate.tm_mday) {
                holidaysDuringLeave.push_back(holiday);
                leaveDays++;
                break;
            }
        }

        // Move to the next day
        currentDate.tm_mday++;
        mktime(&currentDate);
    }

    return leaveDays;
}

int main() {
    tm startDate = {}; // Initialize with zeros
    int originalDuration;

    // Get leave start date
    cout << "Enter leave start date (YYYY MM DD): ";
    cin >> startDate.tm_year >> startDate.tm_mon >> startDate.tm_mday;
    startDate.tm_year -= 1900; // Adjust year
    startDate.tm_mon -= 1;     // Adjust month

    // Get original leave duration (excluding weekends and holidays)
    cout << "Enter original leave duration (in days, excluding weekends and holidays): ";
    cin >> originalDuration;

    // Define a vector to hold holidays (you can add more holidays as needed)
    vector<Holiday> holidays = {
        {1, 1, "New Year's Day"},
        {12, 25, "Christmas Day"},
        {12, 26, "Boxing Day"},
        {1, 9, "Constitution Day"},
        {3, 6, "Independence Day"},
        {4, 7, "Good Friday"},
        {4, 10, "Easter Monday"}


        // Add more holidays here
    };

    // Calculate actual leave duration, considering weekends and holidays
    vector<Holiday> holidaysDuringLeave;
    int leaveDuration = calculateLeaveDuration(startDate, originalDuration, holidays, holidaysDuringLeave);

    // Display holidays during the leave period
    if (!holidaysDuringLeave.empty()) {
        cout << "Holidays during the leave period:" << endl;
        for (const Holiday& holiday : holidaysDuringLeave) {
            cout << holiday.month << "/" << holiday.day << " - " << holiday.occasion << endl;
        }
    } else {
        cout << "No holidays during the leave period." << endl;
    }

    // Calculate and output return date (excluding weekends and holidays)
    tm returnDate = startDate;
    for (int i = 0; i < leaveDuration; ++i) {
        do {
            returnDate.tm_mday++;
            mktime(&returnDate);
        } while (isWeekend(returnDate));
    }

    cout << "Return date: " << returnDate.tm_year + 1900 << "/" << returnDate.tm_mon + 1 << "/" << returnDate.tm_mday << endl;

    return 0;
}
