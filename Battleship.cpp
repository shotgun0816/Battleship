#include <iostream>
#include <windows.h>

using namespace std;

char player_grid[10][10]={{'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'}};

char npc_grid[10][10]={{'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'}};

char player_display[10][10]={{'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'}};
            
char npc_display[10][10]={{'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'},
                        {'*','*','*','*','*','*','*','*','*','*'}};

int player_ship=10, npc_ship=10;

void npc_assign() {
    srand(time(NULL));
    int npc_x, npc_y;
    for (int i=0; i<10; i++) {
        npc_x=rand()%10;
        npc_y=rand()%10;
        while (npc_grid[npc_y][npc_x]=='X') {
            npc_x=rand()%10;
            npc_y=rand()%10;
        }
        npc_grid[npc_y][npc_x]='X';
    }
}

void player_assign() {
    int player_x, player_y;
    for (int i=0; i<10; i++) {
        cout << "Please enter the coordinates of the " << i << " ship: ";
        cin >> player_x >> player_y;
        while (player_grid[player_y][player_x]=='O' || player_x>9 || player_x<0 || player_y>9 || player_y<0) {
            cout << "The spot has been taken or out of range, please enter another one: ";
            cin >> player_x >> player_y;
        }
        player_grid[player_y][player_x]='O';
    }
}

void npc_attack() {
    srand(time(NULL));
    int attack_x, attack_y;
    attack_x=rand()%10;
    attack_y=rand()%10;
    while (player_display[attack_y][attack_y]!='*') {
        attack_x=rand()%10;
        attack_y=rand()%10;
    }
    if (player_grid[attack_y][attack_x]=='O') {
        player_display[attack_y][attack_x]='!';
        player_ship--;
    } else {
         player_display[attack_y][attack_x]=' ';
    }
    cout << "NPC has attacked (" << attack_x << " , " << attack_y << ")." << endl << endl;
}

void player_attack() {
    int attack_x, attack_y;
    cout << "Please type in the coordinates of your attack (X , Y): ";
    cin >> attack_x >> attack_y;
    while (npc_display[attack_y][attack_x]!='*' || attack_x>9 || attack_x<0 || attack_y>9 || attack_y<0) {
        cout << "This spot had already been attacked or out of range, please enter another one: ";
        cin >> attack_x >> attack_y;
    }
    if (npc_grid[attack_y][attack_x]=='X') {
        npc_display[attack_y][attack_x]='!';
        npc_ship--;
    } else {
        npc_display[attack_y][attack_x]=' ';
    }
}

void display_npc() {
    cout << "NPC's grid: " << endl;
    cout << "    0  1  2  3  4  5  6  7  8  9" << endl << "---------------------------------" << endl;
    for (int i=0; i<10; i++) {
        cout << i << " | ";
        for (int j=0; j<10; j++) {
            cout << npc_display[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void display_player() {
    cout << "Your grid: " << endl;
    cout << "    0  1  2  3  4  5  6  7  8  9" << endl << "---------------------------------" << endl;
    for (int i=0; i<10; i++) {
        cout << i << " | ";
        for (int j=0; j<10; j++) {
            cout << player_display[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    string choice;
    cout << "Welcome to Battleship!" << endl;
    npc_assign();
    player_assign();
    cout << "Would you like to go first (Yes/No): ";
    cin >> choice;
    if (choice=="Yes") {
        display_npc();
        while (player_ship!=0&&npc_ship!=0) {
            player_attack();
            display_npc();
            Sleep(1000);
            npc_attack();
            display_player();
        }
    } else if ("No") {
        while (player_ship!=0&&npc_ship!=0) {
            npc_attack();
            display_player();
            Sleep(1000);
            player_attack();
            display_npc();
            Sleep(1000);
        }
    }
    if (player_ship==0) {
        cout << "NPC wins!";
    } else if (npc_ship==0) {
        cout << "You win!";
    }
    return 0;
}