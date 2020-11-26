#include <stdio.h>
#include <stdlib.h>

void generateCard(void);
void printCard(int rankNum, int suitNum);
char *getRank(int rankNum);
char *getSuit(int suitNum);

int main(int argc, char *argv[])
{
    int i;
    int numCards = 5;

    printf("arvg is: %d\n", argc);
    
    if (argc > 1)
        numCards = atoi(argv[1]);

    printf("Generating %d cards\n", numCards);

    for (i = 0; i < numCards; i++)
    {
        generateCard();
    }

    return 0;
}
void generateCard(void)
{
    long r;
    int suit, rank;

    r = random();
    suit = (int)(r % 4);
    r = random();
    rank = (int)(r % 13) + 2;

    printCard(rank, suit);
}
void printCard(int rankNum, int suitNum)
{
    printf("%s of %ss\n", getRank(rankNum), getSuit(suitNum));
}
char *getSuit(int suitNum)
{
    if (suitNum == 0)
        return "Spade";
    if (suitNum == 1)
        return "Heart";
    if (suitNum == 2)
        return "Diamond";
    if (suitNum == 3)
        return "Club";
    return "Unknown Suit";
}

char *getRank(int rankNum)
{
    switch (rankNum)
    {
    case 2:
        return "2";
    case 3:
        return "3";
    case 4:
        return "4";
    case 5:
        return "5";
    case 6:
        return "6";
    case 7:
        return "7";
    case 8:
        return "8";
    case 9:
        return "9";
    case 10:
        return "10";
    case 11:
        return "Jack";
    case 12:
        return "Queen";
    case 13:
        return "King";
    case 14:
        return "Ace";
    }
    return "Unknown Rank";
}
