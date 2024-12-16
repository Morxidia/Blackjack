#include <bits/stdc++.h>
#include <conio.h>
#include <iomanip>

using namespace std;

int arr[52];
int i;
int n = sizeof(arr) / sizeof(arr[0]);
int User=0,Dealer=0;
int Current=0;

void DeckShuffle()
{
    for(i=1;i<=52;i++)
    {
        arr[i-1] = i%13;
        if(arr[i-1] > 10)
            arr[i-1] = 10;
        else if (arr[i-1] == 0)
            arr[i-1] = 10;
    }
    /*for(i=0;i<52;i++)
        cout << arr[i] << " ";
    cout << "\nend\n";*/
    srand(time(0));
    random_shuffle(arr, arr + n);
    /*for(i=0;i<52;i++)
        cout << arr[i] << " ";
    cout << endl;*/
}

void Menu()
{
    cout << setfill('=') << setw(50) << "" << endl;
    cout << setfill(' ') << setw(30) << "BLACK JACK" << endl;
    cout << setfill('=') << setw(50) << "" << endl;
    cout << setfill(' ') << "|  1. Play Game " << right << setw(34) << "|" << endl;
    cout << setfill(' ') << "|  1. Deposit " << right << setw(34) << "|" << endl;
    cout << setfill(' ') << "|  1.  " << right << setw(34) << "|" << endl;
}

void TampilKartu()
{
    cout << "Dealer : " << Dealer << endl;
    cout << "User : " << User << endl;
}

void stand()
{
    do
    {
        Dealer += arr[Current];
        Current++;
        cout << "Dealer : " << Dealer << endl;
    } 
    while (Dealer != 21 && Dealer <= User); 
    cout << "User : " << User << endl;
}

void raise()
{
    User += arr[Current];
    Current++;
    TampilKartu();
}

void menu()
{
    int userop;
    cout << "blackjack" << endl;
    cout << "press enter to start" << endl;
    getch();
    system("cls");
    Dealer += arr[Current];
    Current ++;
    for (i = 1; i <= 2; i++)
    {
        User += arr[Current];
        Current++;
    }
    TampilKartu();
    do
    {
        cout << "1.stand\n2.raise" << endl;
        cout << "Input : ";cin >> userop;
        switch (userop)
        {
        case 1:
            stand();
            continue;
            break;
        case 2:
            raise();
            break;
        default:
            break;
        }
        if (Dealer > User)
            break;
    } 
    while (User < 21 && Dealer < 21);
    if(Dealer > 21)
        cout << "win";
    else if(User == 21)
        cout << "Blackjack";
    else if(User == Dealer)
        cout << "push";
    else
        cout << "loose";
}

main()
{
    Menu();
}