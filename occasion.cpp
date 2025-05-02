#include <iostream>
#include <cctype>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

string occasion()
{
    string occ;
    cout << "Enter the event scheduled for the day: ";

    cin.ignore(); // Prevents input buffer issues
    getline(cin, occ);

    // Validate non-empty input
    if (occ.empty()) {
        cout << "Event description cannot be empty! Please enter again.\n";
        getline(cin, occ);
    }

    return occ;
}
