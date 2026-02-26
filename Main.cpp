#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Appliance {
private:
    string name;
    double power;
    double hours;

public:
    void setAppliance() {
        cin.ignore();
        cout << "Enter appliance name: ";
        getline(cin, name);

        while (name.empty()) {
            cout << "Name cannot be empty. Enter again: ";
            getline(cin, name);
        }

        cout << "Enter power rating (Watts): ";
        cin >> power;
        while (power <= 0) {
            cout << "Power must be greater than 0: ";
            cin >> power;
        }

        cout << "Enter daily usage hours (0-24): ";
        cin >> hours;
        while (hours < 0 || hours > 24) {
            cout << "Invalid hours. Enter between 0 and 24: ";
            cin >> hours;
        }
    }

    void loadFromFile(string n, double p, double h) {
        name = n;
        power = p;
        hours = h;
    }

    double calculateDailyEnergy() const {
        return (power * hours) / 1000.0;
    }

    double calculateMonthlyEnergy() const {
        return calculateDailyEnergy() * 30;
    }

    void display() const {
        cout << "\nAppliance: " << name << endl;
        cout << "Power: " << power << " W" << endl;
        cout << "Daily Usage: " << hours << " hrs" << endl;
        cout << "Monthly Energy: "
             << calculateMonthlyEnergy() << " kWh" << endl;
    }

    string getName() const { return name; }
    double getPower() const { return power; }
    double getHours() const { return hours; }
};

const int MAX = 50;
Appliance appliances[MAX];
int applianceCount = 0;

void saveToFile() {
    ofstream file("appliances.txt");
    for (int i = 0; i < applianceCount; i++) {
        file << appliances[i].getName() << ","
             << appliances[i].getPower() << ","
             << appliances[i].getHours() << endl;
    }
    file.close();
}

void loadFromFile() {
    ifstream file("appliances.txt");
    string name;
    double power, hours;
    char comma;

    while (getline(file, name, ',') &&
           file >> power >> comma >> hours) {

        appliances[applianceCount].loadFromFile(name, power, hours);
        applianceCount++;
    }
    file.close();
}

void searchAppliance() {
    cin.ignore();
    string searchName;
    cout << "Enter appliance name to search: ";
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < applianceCount; i++) {
        if (appliances[i].getName() == searchName) {
            appliances[i].display();
            found = true;
        }
    }

    if (!found)
        cout << "Appliance not found.\n";
}

void removeAppliance() {
    cin.ignore();
    string removeName;
    cout << "Enter appliance name to remove: ";
    getline(cin, removeName);

    for (int i = 0; i < applianceCount; i++) {
        if (appliances[i].getName() == removeName) {

            for (int j = i; j < applianceCount - 1; j++)
                appliances[j] = appliances[j + 1];

            applianceCount--;
            saveToFile();
            cout << "Appliance removed successfully.\n";
            return;
        }
    }

    cout << "Appliance not found.\n";
}

int main() {

    loadFromFile();

    int choice;

    do {
        cout << "\n=== Electrical Load Monitoring System ===\n";
        cout << "1. Register Appliance\n";
        cout << "2. View All Appliances\n";
        cout << "3. Search Appliance\n";
        cout << "4. Remove Appliance\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            if (applianceCount < MAX) {
                appliances[applianceCount].setAppliance();
                applianceCount++;
                saveToFile();
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

        case 3:
            searchAppliance();
            break;

        case 4:
            removeAppliance();
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
