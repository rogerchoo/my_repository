#include <iostream>
using namespace std;

void showgrid(void);
void getInput(void);
bool check_if_same(int a, int b, int c);
bool chooseWinner(void);
void show_result();

int turn = 1;
char lst[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int winner = 0;

int main(void)
{
    do {
        system("cls");
        showgrid();
        getInput();
    } while (chooseWinner());
    system("cls");
    showgrid();
    show_result();
    return 0;
}

void showgrid(void)
{
    int i = 0;
    cout << "Player 1 (X) - Player 2 (O)\n\n" << endl;
    cout << "     |     |     " << endl
        << "  " << lst[0] << "  |  " << lst[1] << "  |  " << lst[2] << endl
        << "_____|_____|_____" << endl
        << "     |     |     " << endl
        << "  " << lst[3] << "  |  " << lst[4] << "  |  " << lst[5] << endl
        << "_____|_____|_____" << endl
        << "     |     |     " << endl
        << "  " << lst[6] << "  |  " << lst[7] << "  |  " << lst[8] << endl
        << "     |     |     \n" << endl;
}

void getInput(void)
{
    int num;
    cout << "Player " << 2 - turn % 2 << ", enter a number: ";
    cin >> num;
    while (num > 9 || num < 1 || lst[num - 1] == 'O' || lst[num - 1] == 'X') {
        cout << "Invalid move" << endl;
        cout << "Player " << 2 - turn % 2 << ", enter a number: ";
        cin >> num;
    }
    cout << endl;
    if (turn % 2 == 0) {
        lst[num - 1] = 'O';
    }
    else lst[num - 1] = 'X';
    turn += 1;
}

void check_winner(char a) {
    if (a == 'X') winner = 1;
    else winner = 2;
}


bool check_if_same(int a, int b, int c)
{
    if (lst[a] == lst[b] && lst[b] == lst[c]) {
        check_winner(lst[a]);
        return true;
    }
    else return false;
}

bool chooseWinner(void)
{
    if (check_if_same(0, 1, 2) || check_if_same(3, 4, 5) || check_if_same(6, 7, 8) || check_if_same(0, 3, 6) ||
        check_if_same(1, 4, 7) || check_if_same(2, 5, 8) || check_if_same(0, 4, 8) || check_if_same(2, 4, 6)) {
        return false;
    }
    else if (turn == 10) {
        return false;
    }
    else return true;
}

void show_result()
{
    if (winner == 0) {
        cout << "Draw" << endl;
    }
    else cout << "Player " << winner << " wins!" << endl;
}