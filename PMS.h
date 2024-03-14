#include <iostream>
#include <string>
using namespace std;
extern int ctr ;
extern int indexx;


class Player {
    int JNo, Run, Wicket, Matches;
    string Name;

public:
    
    Player() ;
    Player(int j, int r, int m, string n, int w);

    // SETTERS
    void setJNo(int j); 
    void setRun(int r) ;
    void setMatches(int m);
    void setName(string n) ;
    void setWicket(int w) ;

    // GETTERS
    int getJNo() ;
    int getRun() ;
    int getMatches() ;
    string getName() ;
    int getWicket() ;

    // MEMBER FUNCTIONS
    void display();
    
};


void storeData1(Player* p, int size);
    // void display1(Player* p, int size);
    // void display(Player p);
    int searchByNo(Player* p, int No);
    int searchByName(Player* p, string name);
    int update(Player* p, int No);
    void deletee(Player* p, int No);
    void topData(Player* p, int size);
    void swapPlayers(Player* a, Player* b);
    void sortByMatches(Player* p, int size);
    void displayTopMatches(Player* p, int size);
    void sortByRuns(Player* p, int size);
    void displayTopRuns(Player* p, int size);
    void sortByWickets(Player* p, int size);
    void displayTopWickets(Player* p, int size);


    
