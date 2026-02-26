#include <iostream>
#include <string>
using namespace std;

class Appliance {
private:
    string name;
    double power;
    double hours;

public:
    void setAppliance() {
        cout << "Enter appliance name: ";
        cin >> name;

        cout << "Enter power rating (Watts): ";
        cin >> power;

        cout << "Enter daily usage hours: ";
        cin >> hours;
    }

    void display() const {
        cout << "\nAppliance: " << name << endl;
        cout << "Power: " << power << " W" << endl;
        cout << "Daily Usage: " << hours << " hrs" << endl;
    }
};

const int MAX = 50;
Appliance appliances[MAX];
int applianceCount = 0;

int main() {

    int choice;

    do {
        cout << "\n=== Electrical Load Monitoring System ===\n";
        cout << "1. Register Appliance\n";
        cout << "2. View All Appliances\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            if (applianceCount < MAX) {
                appliances[applianceCount].setAppliance();
                applianceCount++;
                cout << "Appliance added successfully.\n";
            } else {
                cout << "Storage full.\n";
            }
            break;

        case 2:
            if (applianceCount == 0)
                cout << "No appliances registered.\n";
            else
                for (int i = 0; i < applianceCount; i++)
                    appliances[i].display();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}