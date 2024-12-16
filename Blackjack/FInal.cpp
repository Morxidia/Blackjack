#include <bits/stdc++.h>
#include <conio.h>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::this_thread;

struct Card
{
    int Values;
    string Name;
    string Type;
};
enum Condition
{
    Blackjack,
    Win,
    Losee,
    Push
};
struct Card Deck[52],Player[10],Dealer[10];
float Money=0;
int Bet,Round=0;
int CardIndex=0,PlayerIndex=0,DealerIndex=0;
int PlayerTotal=0,DealerTotal=0;

void Menu();
void Play();
enum Condition Game();
void DeckInput();
void DeckShuffle();
void Checkshuffle();

main()
{
    DeckInput();
    DeckShuffle();
    Menu();
}

void DeckInput()
{
    int i,n;
    for(i=0;i<4;i++)
    {
        for(n=1;n<=13;n++)
        {
            Deck[(i*13)+n-1].Values = n;
            if(n>10)
                Deck[(i*13)+n-1].Values = 10;
            Deck[(i*13)+n-1].Name = to_string(n);
            if (n==1)
                Deck[(i*13)+n-1].Name = "Ace";
            else if(n==11)
                Deck[(i*13)+n-1].Name = "Jack";
            else if(n==12)
                Deck[(i*13)+n-1].Name = "Queen";
            else if(n==13)
                Deck[(i*13)+n-1].Name = "King";
            //Input the type of card
            if(i==0)
                Deck[(i*13)+n-1].Type = 6;
            else if (i==1)
                Deck[(i*13)+n-1].Type = 3;
            else if (i==2)
                Deck[(i*13)+n-1].Type = 5;
            else
                Deck[(i*13)+n-1].Type = 4;
        }
    }
}

void DeckShuffle()
{
    int SizeDeck = sizeof(Deck) / sizeof(Deck[0]);
    srand(time(0));
    random_shuffle(Deck, Deck + SizeDeck);
}

void Checkshuffle()//Not run in the main program
{
    int i;
    DeckInput();
    for(i=0;i<52;i++)
    {
        //cout << i << "   ";
        cout << Deck[i].Values << " " << Deck[i].Name << "   " << Deck[i].Type << endl;
    }
    cout << endl;
    DeckShuffle();
    cout << endl; 
    for(i=0;i<52;i++)
    {
        //cout << i << "   ";
        cout << left << setw(3) << Deck[i].Values << setw(6) << Deck[i].Name << Deck[i].Type << endl;
    }
}

void DealerShowCard()
{
    cout << "> Dealer <" << endl;
    cout << setfill('-') << setw(11) << "" << endl << setfill(' ');
    for(int i=0;i<DealerIndex;i++)
    {
        //sleep_for(500ms);
        cout << "| " << setw(6) << left << Dealer[i].Name << Dealer[i].Type << " |" << endl;
    }
    cout << setfill('-') << setw(11) << "" << endl << setfill(' ');
    cout << "Values : " << DealerTotal << endl << endl;
}

void PlayerShowCard()
{
    cout << "> PLAYER <" << endl;
    cout << setfill('-') << setw(11) << "" << endl << setfill(' ');
    for(int i=0;i<PlayerIndex;i++)
    {
        //sleep_for(500ms);
        cout << "| " << setw(6) << left << Player[i].Name << Player[i].Type << " |" << endl;
    }
    cout << setfill('-') << setw(11) << "" << endl << setfill(' ');
    cout << "Values : " << PlayerTotal << endl << endl;
}

void DealerRaise()
{
    Dealer[DealerIndex].Name = Deck[CardIndex].Name;
    Dealer[DealerIndex].Type = Deck[CardIndex].Type;
    if(DealerTotal < 11 && Dealer[DealerIndex].Name == "Ace")
        Dealer[DealerIndex].Values = 11;
    else
        Dealer[DealerIndex].Values = Deck[CardIndex].Values;
    DealerTotal += Dealer[DealerIndex].Values;
    DealerIndex++;
    CardIndex++;
}

void Raise()
{
    Player[PlayerIndex].Name = Deck[CardIndex].Name ;
    Player[PlayerIndex].Type = Deck[CardIndex].Type;
    if(PlayerTotal < 11 && Player[PlayerIndex].Name == "Ace")
        Player[PlayerIndex].Values = 11;
    else
        Player[PlayerIndex].Values = Deck[CardIndex].Values;
    PlayerTotal += Player[PlayerIndex].Values;
    PlayerIndex++;
    CardIndex++;
}

void Stand()
{
    system("cls");
    cout << "___STAND___" << endl;
    DealerShowCard();
    PlayerShowCard();
    while (DealerTotal<PlayerTotal)
    {
        DealerRaise();
        system("cls");
        cout << "== STAND ==" << endl << endl;
        DealerShowCard();
        PlayerShowCard();
    }
}

enum Condition Game()
{
    int UserInput;
    PlayerTotal=0,DealerTotal=0;
    PlayerIndex=0,DealerIndex=0;
    cout << setfill(' ');
    if(Round == 6)
    {
        system("cls");
        DeckShuffle();
        string text="Deck Shuffle....";
        for(int i=1;i<=17;i++)
        {
            cout << text[i-1];
            sleep_for(200ms);
        }
        cout << endl;
        CardIndex=0;
        Round=0;
    }
    for(int i=0;i<2;i++)
    {
        //Dealer Input
        DealerRaise();
        //PLayer Input
        Raise();
    }
    do
    {
        system("cls");
        cout << "> Dealer <" << endl;
        cout << setfill('-') << setw(11) << "" << endl << setfill(' ');
        for(int i=0;i<DealerIndex;i++)
        {
            //sleep_for(500ms);
            if(i==0)
                cout << "| " << setw(6) << left << "xxxxx" << "x" << " |" << endl;
            else
                cout << "| " << setw(6) << left << Dealer[i].Name << Dealer[i].Type << " |" << endl;
        }
        cout << setfill('-') << setw(11) << "" << endl << setfill(' ');
        cout << "Values : " << Dealer[1].Values << endl << endl;
        PlayerShowCard();
            if(PlayerTotal==21)
            {
                system("cls");
                DealerShowCard();
                PlayerShowCard();
                break;
            }
        cout << "1. Stand" << endl;
        cout << "2. Raise" << endl;
        cin >> UserInput;
        switch (UserInput)
        {
        case 1:
            Stand();
            break;
        case 2:    
            Raise();
            if(PlayerTotal>21)
            {
                system("cls");
                DealerShowCard();
                PlayerShowCard();
            }
            else if(PlayerTotal==21)
            {
                system("cls");
                DealerShowCard();
                PlayerShowCard();
            }
            break;
        default:
            break;
        }
        if(UserInput==1)
            break;
    } 
    while (DealerTotal<21 && PlayerTotal<21);
    Round++;
    if(DealerTotal == PlayerTotal)
        return Push;
    else if(PlayerTotal==21)
        return Blackjack;
    else if(DealerTotal > 21)
        return Win;
    else
        return Losee;
}

void Play()
{
    int BetInput;
    float Bet;
    enum Condition Result;
    do
    {
        system("cls");
        cout << setfill('=') << setw(20) << "" << endl;
        cout << setfill(' ') << setw(12) << right <<">BET<" << endl;
        cout << setfill('=') << setw(20) << "" << endl;
        cout << setfill(' ') << setw(19) << left << "|  1. $ 5" << "|" << endl;
        cout << setfill(' ') << setw(19) << left << "|  2. $ 10" << "|" << endl;
        cout << setfill(' ') << setw(19) << left << "|  3. $ 25" << "|" << endl;
        cout << setfill(' ') << setw(19) << left << "|  4. $ 50" << "|" << endl;
        cout << setfill(' ') << setw(19) << left << "|  5. $ 100" << "|" << endl;
        cout << setfill('=') << setw(20) << "" << endl;
        cout << "BET Option : ";
        cin >> BetInput;
        switch (BetInput)
        {
        case 1:
            Bet = 5;
            break;
        case 2:
            Bet = 10;
            break;
        case 3:
            Bet = 25;
            break;
        case 4:
            Bet = 50;
            break;
        case 5:
            Bet = 100;
            break;
        }
    }
    while (BetInput < 1 || BetInput > 6);
    Result = Game();
    if(Result == Push)
        cout << "PUSH" << endl;
    else if(Result == Blackjack)
    {
        cout << "BLACKJACK" << endl;
        Money += Bet*1.5;
    }
    else if(Result == Win)
    {
        cout << "WIN" << endl;
        Money += Bet;
    }
    else if(Result == Losee)
    {
        cout << "Losee" << endl;
        Money -= Bet;
    }
    cout << "Your Money : " << Money << endl;
    cout << "press enter to continue..." << endl;
    getch();
}

void Menu()
{
    int MenuInput;
    Money = 200;
    string text = "INSERTING YOUR MONEY $ 200 ..........";
    string O = "Convert your Chip Into Money......";
    system("cls");
    for(int i=0;i<37;i++)
    {
        cout << text[i];
        sleep_for(200ms);
    }
    do
    {
    system("cls");
    cout << setfill('=') << setw(30) << "" << endl;
    cout << setfill(' ') << setw(22) << right << "> BLACKJACK <" << endl;
    cout << setfill('=') << setw(30) << "" << endl;
    cout << setfill(' ') << setw(15) << left << "|  1.PLAY!!" << setw(15) << right << "|" << endl;
    cout << setfill(' ') << setw(15) << left << "|  2.See Money" << setw(15) << right << "|" << endl;
    cout << setfill(' ') << setw(15) << left << "|  3.Rules" << setw(15) << right << "|" << endl;
    cout << setfill(' ') << setw(15) << left << "|  4.Check Out" << setw(15) << right << "|" << endl;
    cout << setfill('=') << setw(30) << "" << endl;
    cout << "Input : " ;
    cin >> MenuInput;
    switch (MenuInput)
    {
    case 1:
        Play();
        break;
    case 2:
        system("cls");
        cout << "$ " << Money << endl;
        getch();
        break;
    case 3:
        system("cls");
        cout << "1. If you win You get an amount of your Bet,\n   if you losee you lost your money an amount of your bet\n   If you got a Blackjack\n   You get 3/2 the money of your Bet\n";
        cout << "2. You can win by getting a Blackjack\n   or get more card values than the Dealer\n   if the amount of values of both are equal the game end with draw\n   and you will not losee your money\n";
        cout << "3. Get more money!!" << endl;
        getch();
        break;
    case 4:
        system("cls");
        for(int i=0;i<34;i++)
        {
            cout << O[i];
            sleep_for(300ms);
        }
        cout << endl;
        cout << "Money You Got : $ " << Money;
        break;
    default:
        break;
    }
    } 
    while (MenuInput != 4);
}