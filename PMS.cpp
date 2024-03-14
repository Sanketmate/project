#include"PMS.h"

int ctr = 0;
int indexx;


Player::Player() {
    this->JNo = 0;
    this->Run = 0;
    this->Matches = 0;
    this->Wicket = 0;
    this->Name = "Not Set";
}

Player::Player(int j, int r, int m, string n, int w) {
    this->JNo = j;
    this->Run = r;
    this->Matches = m;
    this->Name = n;
    this->Wicket = w;
}

// SETTERS
void Player::setJNo(int j) { this->JNo = j; }
void Player::setRun(int r) { this->Run = r; }
void Player::setMatches(int m) { this->Matches = m; }
void Player::setName(string n) { this->Name = n; }
void Player::setWicket(int w) { this->Wicket = w; }

// GETTERS
int Player::getJNo() { return this->JNo; }
int Player::getRun() { return this->Run; }
int Player::getMatches() { return this->Matches; }
string Player::getName() { return this->Name; }
int Player::getWicket() { return this->Wicket; }


//member Functions;
void Player::display() {
    cout << "\n\n\n#------- All Store Data are as followed -------#";
    cout << "\n\n Jersy No \t Name \t Runs \t Wickets \tNO of matches";
    cout << "\n=======================================================";
    cout << "\n\t" << this->JNo << " |\t" << this->Name << " \t |" << this->Run << " \t |" << this->Wicket << " \t|\t " << this->Matches << "|";
    cout << "\n|=======================================================|";
}


//Non Member Function;
void storeData1(Player* p, int size) {
    bool exitLoop = false;

    for (int i = 0; i < size && !exitLoop; i++) {
        if (ctr != size) {
            cout << "\n\n\n\t\t!!! Please Enter your Data !!!";
            cout << "\n\t\t  ==========================";
            cout << "\n\nEnter your Jersey No (enter -1 to exit): ";
            cin >> p[ctr].JNo;

            if (p[ctr].JNo == -1) {
                exitLoop = true;
            } else {
                cout << "\nEnter your Name: ";
                cin >> p[ctr].Name;
                cout << "\nEnter your Runs: ";
                cin >> p[ctr].Run;
                cout << "\nEnter your Wickets: ";
                cin >> p[ctr].Wicket;
                cout << "\nEnter your No of Matches: ";
                cin >> p[ctr].Matches;
                ctr++;
            }
        } else {
            cout << "\n\nList is full\n\n\n";
            break;
        }
    }
}

// void display1(Player* p, int size) {
//     cout << "\n\n\n\t#------- All Store Data are as followed -------#";
//     cout << "\n\t\t ==================================\t";
//     cout << "\n\n|=======================================================|\t";
//     cout << "\n|   Jersy No |\t Name |\t Runs |\t Wickets | Matches N.O  |";
//     cout << "\n|=======================================================|";

//     for (int i = 0; i < ctr; i++) {
//         cout << "\n|\t" << p[i].JNo << "   |\t" << p[i].Name << " |\t " << p[i].Run << "  |\t  " << p[i].Wicket << " \t |\t  " << p[i].Matches << "\t|";
//     }

//     cout << "\n|=======================================================|";
//     cout << "\n\n\n";
// }

// void display(Player p) {
//     cout << "\n\n\n#------- All Store Data are as followed -------#";
//     cout << "\n\n Jersy No \t Name \t Runs \t Wickets \tNO of matches";
//     cout << "\n=======================================================";
//     cout << "\n\t" << p.JNo << " |\t" << p.Name << " \t |" << p.Run << " \t |" << p.Wicket << " \t|\t " << p.Matches << "|";
//     cout << "\n|=======================================================|";
// }

int searchByNo(Player* p, int No) {
    for (int i = 0; i < ctr; i++) {
        if (p[i].JNo == No) {
            return i;
        }
    }
    return -1;
}

int searchByName(Player* p, string name) {
    for (int i = 0; i < ctr; i++) {
        if (p[i].Name == name) {
            return i;
        }
    }
    return -1;
}

int update(Player* p, int No) {
    int i = searchByNo(p, No);
    if (i == -1) {
        cout << "\nRecord not found";
    } else {
        int ch;
        cout << "\nWhat you want to update: ";
        cout << "\n\t1.Matches";
        cout << "\n\t2.run";
        cout << "\n\t3.wickets";
        cout << "\n\t4.Exit";
        cout << "\n\tEnter your choice ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "\nEnter your updated matches:";
            cin >> p[i].Matches;
            break;
        case 2:
            cout << "\nEnter your updated Runs:";
            cin >> p[i].Run;
            break;
        case 3:
            cout << "\nEnter your updated Wickets:";
            cin >> p[i].Wicket;
            break;
        default:
            cout << "\nYour Data is Updated Sucessfull !!!";
        }
    }
    return i;
}

void deletee(Player* p, int No) {
    int i = searchByNo(p, No);
    if (i == -1) {
        cout << "\nRecord not found";
    } else {
        while (i < ctr - 1) {
            p[i] = p[i + 1];
            i++;
        }
        ctr--;
    }
    cout << "\nData is deleted successfully!!!";
}

void swapPlayers(Player* a, Player* b) {
    Player temp = *a;
    *a = *b;
    *b = temp;
}

voidsortByRuns(Player* p, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (p[j].Run < p[j + 1].Run) {
                swapPlayers(&p[j], &p[j + 1]);
            }
        }
    }
}

void displayTopRuns(Player* p, int size) {
    sortByRuns(p, size);

    cout << "\n\n\n\t#------- Top 3 Players by Runs -------#";
    cout << "\n Jersy No \t Name \t Runs \t Wickets \t NO of matches";
    cout << "\n=======================================================";

    int displayCount = (size < 3) ? size : 3;

    for (int i = 0; i < displayCount; i++) {
        cout << "\n\t" << p[i].JNo << " |\t" << p[i].Name << " \t |" << p[i].Run << " \t |" << p[i].Wicket << " \t|\t " << p[i].Matches << "|";
    }

    cout << "\n|=======================================================|";
}

void sortByWickets(Player* p, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (p[j].Wicket < p[j + 1].Wicket) {
                swapPlayers(&p[j], &p[j + 1]);
            }
        }
    }
}

void displayTopWickets(Player* p, int size) {
    sortByWickets(p, size);

    cout << "\n\n\n\t#------- Top 3 Players by Wickets -------#";
    cout << "\n Jersy No \t Name \t Runs \t Wickets \t NO of matches";
    cout << "\n=======================================================";

    int displayCount = (size < 3) ? size : 3;

    for (int i = 0; i < displayCount; i++) {
        cout << "\n\t" << p[i].JNo << " |\t" << p[i].Name << " \t |" << p[i].Run << " \t |" << p[i].Wicket << " \t|\t " << p[i].Matches << "|";
    }

    cout << "\n\t|=======================================================|";
}

void sortByMatches(Player* p, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (p[j].Matches < p[j + 1].Matches) {
                swapPlayers(&p[j], &p[j + 1]);
            }
        }
    }
}

void displayTopMatches(Player* p, int size) {
    sortByMatches(p, size);

    cout << "\n\n\n\t#------- Top 3 Players by Matches -------#";
    cout << "\n Jersy No \t Name \t Runs \t Wickets \t NO of matches";
    cout << "\n=======================================================";

    int displayCount = (size < 3) ? size : 3;

    for (int i = 0; i < displayCount; i++) {
        cout << "\n\t" << p[i].JNo << " |\t" << p[i].Name << " \t |" << p[i].Run << " \t |" << p[i].Wicket << " \t|\t " << p[i].Matches << "|";
    }

    cout << "\n\t|=======================================================|";
}

void topData(Player* p, int size) {
    int cho;
    do {
        cout << "\nWhat you want to see: ";
        cout << "\n\t1.Runs";
        cout << "\n\t2.Wickets";
        cout << "\n\t3.Matches";
        cout << "\n\t4.Exit";
        cout << "\n\tEnter your choice ";

        cin >> cho;

        switch (cho) {
        case 1:
            sortByRuns(p, size);
            displayTopRuns(p, size);
            break;
        case 2:
            sortByWickets(p, size);
            displayTopWickets(p, size);
            break;
        case 3:
            sortByMatches(p, size);
            displayTopMatches(p, size);
            break;
        default:
            cout << "\nYour Data is Display Successful !!!";
        }
    } while (cho != 4);
}
