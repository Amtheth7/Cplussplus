#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;

public:
    void loadData();
    void searchItem();
    void displayFrequency();
    void displayHistogram();
    void saveBackup();
};

void GroceryTracker::loadData() {
    ifstream inputFile("CS210_Project_Three_Input_File.txt");
    string item;

    if (!inputFile.is_open()) {
        cout << "Error opening input file." << endl;
        return;
    }

    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

void GroceryTracker::searchItem() {
    string item;

    cout << "Enter the item you want to search for: ";
    cin >> item;

    cout << item << " was purchased "
        << itemFrequency[item] << " times." << endl;
}

void GroceryTracker::displayHistogram() {
    cout << "\nItem Purchase Histogram:\n";

    for (const auto& item : itemFrequency) {
        cout << item.first << " ";

        for (int i = 0; i < item.second; i++) {
            cout << "*";
        }

        cout << endl;
    }
}


void GroceryTracker::saveBackup() {
    ofstream outFile("frequency.dat");

    for (const auto& item : itemFrequency) {
        outFile << item.first << " " << item.second << endl;
    }

    outFile.close();
}
void GroceryTracker::displayFrequency() {
    for (const auto& item : itemFrequency) {
        cout << item.first << " " << item.second << endl;
    }
}

int main() {
    GroceryTracker tracker;
    int choice = 0;

    tracker.loadData();
    tracker.saveBackup();

    while (choice != 4) {
        cout << "\n===== Corner Grocer Menu =====" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display item frequencies" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tracker.searchItem();
            break;
        case 2:
            tracker.displayFrequency();
            break;
        case 3:
            tracker.displayHistogram();
            break;
        case 4:
            cout << "Thank you for using Corner Grocer!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

