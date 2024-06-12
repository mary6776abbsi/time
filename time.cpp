#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    // Function to validate the time
    bool isValidTime(int h, int m, int s) {
        return (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60);
    }

public:
    // Constructor with validation
    Time(int h = 0, int m = 0, int s = 0) {
        if (isValidTime(h, m, s)) {
            hours = h;
            minutes = m;
            seconds = s;
        }
        else {
            hours = minutes = seconds = 0;
            cout << "Invalid time entered. Defaulting to 00:00:00" << endl;
        }
    }

    // Function to display time in HH:MM:SS format
    void displayTime() const {
        cout << setfill('0') << setw(2) << hours << ":"
            << setfill('0') << setw(2) << minutes << ":"
            << setfill('0') << setw(2) << seconds << endl;
    }

    // Function to calculate the difference between two times
    Time difference(const Time& t) const {
        int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds2 = t.hours * 3600 + t.minutes * 60 + t.seconds;
        int diffSeconds = abs(totalSeconds1 - totalSeconds2);

        int diffHours = diffSeconds / 3600;
        diffSeconds %= 3600;
        int diffMinutes = diffSeconds / 60;
        diffSeconds %= 60;

        return Time(diffHours, diffMinutes, diffSeconds);
    }
};

int main() {
    // Create two Time objects
    Time time1(14, 30, 45); // 14:30:45
    Time time2(16, 45, 30); // 16:45:30

    // Display the times
    cout << "Time 1: ";
    time1.displayTime();

    cout << "Time 2: ";
    time2.displayTime();

    // Calculate and display the difference
    Time diff = time1.difference(time2);
    cout << "Difference: ";
    diff.displayTime();

    return 0;
}
