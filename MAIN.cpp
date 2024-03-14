#include"PMS.cpp"
int main() {
    int size;
    int No;
    string Na;

    cout << "\n\n\n!!!! Welcome to PLAYER MANAGEMENT SYSTEM !!!!";
    cout << "\n\t===============================\n\n\n";
    cout << "Enter how many players data you want to store: ";
    cin >> size;
    Player* p = new Player[size];

    int Choice;
    do {
        cout << "\n\n\n";
        cout << "\n+===========================================+";
        cout << "\n#-------------------------------------------#";
        cout << "\n#-------------------------------------------#";
        cout << "\n#-------------------------------------------#";
        cout << "\n#\t=============================\t    #";
        cout << "\n#-------| Player Management System  |-------#";
        cout << "\n#\t=============================\t    #";
        cout << "\n#-------------------------------------------#";
        cout << "\n#-------------------------------------------#";
        cout << "\n#-------------------------------------------#";
        cout << "\n+===========================================+";
        cout << "\n|\t 1.Store Data:                      |";
        cout << "\n|\t 2.Display Data:                    |";
        cout << "\n|\t 3.Search Data by Jersey No:        |";
        cout << "\n|\t 4.Search Data by Name:             |";
        cout << "\n|\t 5.Update Data:                     |";
        cout << "\n|\t 6.Delete Data:                     |";
        cout << "\n|\t 7.Display Top 3 Data:              |";
        cout << "\n|\t 8.To Exit program:                 |";
        cout << "\n+===========================================+\n\n";

        cout << "\nEnter your choice: ";
        cin >> Choice;

        switch (Choice) {
        case 1: storeData1(p, size); break;
        case 2: for (int i = 0; i < size; i++)
        {
            p[i].display();
        }
        break;
        case 3:
            cout << "\nEnter Jersey No to be search: ";
            cin >> No;
            indexx = searchByNo(p, No);
            if (indexx == -1) {
                cout << "\nRecord not found";
            } else {
                p[indexx].display();
            }
            break;
        case 4:
            cout << "\nEnter Name to be search: ";
            cin >> Na;
            indexx = searchByName(p, Na);
            if (indexx == -1) {
                cout << "\nRecord not found";
            } else {
                display(p[indexx]);
            }
            break;
        case 5:
            cout << "\nEnter Jersey No to be updated: ";
            cin >> No;
            indexx = update(p, No);
            if (indexx == -1) {
                cout << "\nRecord not found";
            } else {
                p->display(p[indexx]);
            }
            break;
        case 6:
            cout << "Enter Jersey No to be delete: ";
            cin >> No;
            deletee(p, No);
            break;
        case 7: topData(p, size); break;
        default:
            cout << "\n\n\t !!!! invalid choice";
            cout << "\n\t=======================\n\n\n";
        }
    } while (Choice != 8);

    cout << "\n\t -: !!!!!! Thank you for using P..M..S !!!!!! :- ";
    cout << "\n\t\t==================================\n\n\n";

    delete[] p;
    return 0;
}