#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

struct Participant {
    int id;
    string name;
    int prevParticipations;
    double project1;
    double project2;
    double total;

    void calculateTotal() {
        total = project1 * 0.6 + project2 * 0.4;
    }
};

// Global container
vector<Participant> participants;

void addParticipant() {
    Participant p;
    cout << "Enter ID: ";
    cin >> p.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, p.name);
    cout << "Enter Number of Previous Participations: ";
    cin >> p.prevParticipations;
    cout << "Enter Project 1 score: ";
    cin >> p.project1;
    cout << "Enter Project 2 score: ";
    cin >> p.project2;
    p.calculateTotal();
    participants.push_back(p);
    cout << "Participant added successfully!\n";
}

void deleteParticipant() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    for (auto it = participants.begin(); it != participants.end(); ++it) {
        if (it->id == id) {
            participants.erase(it);
            cout << "Participant deleted.\n";
            return;
        }
    }
    cout << "Participant not found.\n";
}

void updateParticipant() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;
    for (auto &p : participants) {
        if (p.id == id) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, p.name);
            cout << "Enter new Number of Previous Participations: ";
            cin >> p.prevParticipations;
            cout << "Enter new Project 1 score: ";
            cin >> p.project1;
            cout << "Enter new Project 2 score: ";
            cin >> p.project2;
            p.calculateTotal();
            cout << "Participant updated.\n";
            return;
        }
    }
    cout << "Participant not found.\n";
}

void saveToFile() {
    ofstream file("participants.txt");
    for (auto &p : participants) {
        file << p.id << "," << p.name << "," << p.prevParticipations << ","
             << p.project1 << "," << p.project2 << "," << p.total << "\n";
    }
    file.close();
    cout << "Records saved to participants.txt\n";
}

void loadFromFile() {
    ifstream file("participants.txt");
    if (!file) {
        cout << "No file found.\n";
        return;
    }
    participants.clear();
    Participant p;
    while (file >> p.id) {
        file.ignore(); // skip comma
        getline(file, p.name, ',');
        file >> p.prevParticipations;
        file.ignore();
        file >> p.project1;
        file.ignore();
        file >> p.project2;
        file.ignore();
        file >> p.total;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        participants.push_back(p);
    }
    file.close();
    cout << "Records loaded from participants.txt\n";
}

void viewAll() {
    cout << left << setw(5) << "ID" << setw(15) << "Name" 
         << setw(8) << "Prev" << setw(8) << "P1" 
         << setw(8) << "P2" << setw(8) << "Total" << "\n";
    for (auto &p : participants) {
        cout << setw(5) << p.id << setw(15) << p.name
             << setw(8) << p.prevParticipations
             << setw(8) << p.project1 << setw(8) << p.project2
             << setw(8) << p.total << "\n";
    }
}

void viewByParticipations() {
    int n;
    cout << "Enter number of previous participations: ";
    cin >> n;
    for (auto &p : participants) {
        if (p.prevParticipations == n) {
            cout << p.id << " - " << p.name << " (" << p.total << ")\n";
        }
    }
}

void viewHighestScore() {
    if (participants.empty()) {
        cout << "No participants available.\n";
        return;
    }
    Participant *best = &participants[0];
    for (auto &p : participants) {
        if (p.total > best->total) best = &p;
    }
    cout << "Highest Scorer: " << best->name << " (Total: " << best->total << ")\n";
}

void averageScore() {
    if (participants.empty()) {
        cout << "No participants available.\n";
        return;
    }
    double sum = 0;
    for (auto &p : participants) sum += p.total;
    cout << "Average Total Score: " << sum / participants.size() << "\n";
}

int main() {
    int choice;
    do {
        cout << "===============Menu===============\n";
        cout << "1. Add participant record\n";
        cout << "2. Delete participant record\n";
        cout << "3. Update participant record\n";
        cout << "4. Save all participant records in a .txt file\n";
        cout << "5. Load all participant records from a .txt file\n";
        cout << "6. View all participant records\n";
        cout << "7. View participants by number of previous participations\n";
        cout << "8. View participant with highest total score\n";
        cout << "9. Calculate average total score over all participants\n";
        cout << "10. Exit program\n";
        cout << "===================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addParticipant(); break;
            case 2: deleteParticipant(); break;
            case 3: updateParticipant(); break;
            case 4: saveToFile(); break;
            case 5: loadFromFile(); break;
            case 6: viewAll(); break;
            case 7: viewByParticipations(); break;
            case 8: viewHighestScore(); break;
            case 9: averageScore(); break;
            case 10: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
        cout << "\n";
    } while (choice != 10);

    return 0;
}
