#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>


typedef struct Card{
    char Bez[50];
    int usetime ; 
    double wight;
    struct Card* pNext;
} struCard;

typedef struct Player {
    char name[50];
    Card* pfirstCardOfList;
    Card* pLastCardOfList;
}struPlayer;


// Autor der Methode Raksana
void Output(Card* firstCard) {
    Card* pTemp = firstCard;
    while (pTemp != NULL)
    {
        printf(" %s\n", pTemp->Bez);
        printf(" usetime: %i\n", pTemp->usetime);
        printf(" wight: %lf\n", pTemp->wight);
        printf("\n");
        pTemp = pTemp->pNext;
    }



}
/*
* Autor der Methode Raksana
* Dise Methode schaut,ob der Wert 1 oder 2 ist
*/
bool checkInputValue(int *pvalueToCompare) {
    
        return  (*pvalueToCompare == 1 || *pvalueToCompare == 2);
    
}
/*
* Autor der Methode Raksana
* Dise Methode f�gt die Karte zum schluss hinzu
*/
void addCard(Card* cardToAdd, Player* pPlayer) {
    cardToAdd->pNext = NULL;
    pPlayer->pLastCardOfList->pNext = cardToAdd;
    pPlayer->pLastCardOfList = pPlayer->pLastCardOfList->pNext;

    printf("addCart");
    Output(pPlayer->pfirstCardOfList);
}
/*
* Autor der Methode Raksana
* Dise Methode nimmt die Liste auseinander 
* an einer  bestimmten postition
* und f�gt sie wieder hinzu.
* Ein Listen Object wird weggenommen.Das Objekt,
* dass weggenommen wird wird zur�ck gegeben.
*/
Card* splittListAndMerge(Player* pPlayer,Card* moveTo) {
    Card* pRemovedCard = pPlayer->pfirstCardOfList;
    Card* ptemp2 = pPlayer->pfirstCardOfList;
    Card* ptemp = pPlayer->pfirstCardOfList;
    while (ptemp->pNext != NULL && moveTo != pPlayer->pfirstCardOfList)
    {
        ptemp = ptemp->pNext;
        if (ptemp->pNext == moveTo && pPlayer->pfirstCardOfList != moveTo)
        {
            pRemovedCard = ptemp->pNext;
            ptemp->pNext = ptemp->pNext->pNext;
            printf("splitted and merged Cart");
            return pRemovedCard;
            
            break;

        }

    }
 
}

/*
* Autor der Methode Raksana
* Dise Methode schiebt die Karte eins nach Oben.
*/
Card *moveCardUp(Player* pPlayer,Card* moveTo) {
    if (pPlayer->pfirstCardOfList!= moveTo)
    {
       return splittListAndMerge(pPlayer, moveTo);
    }else{
    Card* pRemovedCard = pPlayer->pfirstCardOfList;
      pPlayer->pfirstCardOfList = pPlayer->pfirstCardOfList->pNext;
     return pRemovedCard; 
    }

}


/*
* Author of mehtod Raksana
* Diese Methode entfernt die Karte schiebt, die n�achte Karte hoch 
* und f�gt die Karte zum Schluss von dem Talon hinzu
*/

Card * removeCard(Player* pPlayer, Card *pCardToRemove) {
    Card* removed = pPlayer->pfirstCardOfList;
    Card* pTemp= pPlayer->pfirstCardOfList;
    while (pTemp->pNext!= pCardToRemove->pNext->pNext)
    {
        if (pTemp==pCardToRemove)
        {
            removed = pPlayer->pfirstCardOfList;
            Card* temp=moveCardUp(pPlayer, pCardToRemove);
            break;
            printf("::::::::::::::::::::::::::");
        }
        pTemp=pTemp->pNext;      
    }
            Output(pPlayer->pfirstCardOfList);
            return removed;
}


//TODO: Raksana
void welcome() {
//name input player 
//and short explaination of game
}


/*Autor: Tamara
* Es schaut wie viele Karten ein Spieler hat
*/
int sizeOfCardStack(Player* pPlayer) {
    int count = 0;
    Card* pTemp = pPlayer->pfirstCardOfList;
    while (pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
        count++;
    }
    return count;
}
                                   
//TODO: Raksana
void radomMixOfCardStack(Player *pPlayer) {
  
    for (int i = 0; i < 5; i++)
    {
        Card * pTemp = pPlayer->pfirstCardOfList;
        int randNr=rand() % 4;
        int* pRandNr = &randNr;
        int j=0;
        for (int *pj = &j; *pj < *pRandNr; *pj++) {
        
            pTemp = pTemp->pNext;
        }
        Card *toEnd=moveCardUp(pPlayer,pTemp);
        addCard(toEnd,pPlayer);
        printf("//////////RANDOM////////");
        Output(pPlayer->pfirstCardOfList);
    }
    
    

}
Card* getIndex (int index, Player* pPlayer) {
    Card* pTemp = pPlayer->pfirstCardOfList;
    int countDown=index;
    while (countDown!=0)
    {
        *pTemp = *pTemp->pNext;
        countDown--;
    }
    Output(pTemp);
    return pTemp;
    

}
Card* getLast(Card* pPlayer) {
    Player tempPlayer;
    Player *pTempPlayer = &tempPlayer;
    pTempPlayer->pfirstCardOfList = pPlayer;
    int indexLastCard=sizeOfCardStack(pTempPlayer);
   return getIndex(indexLastCard,pTempPlayer);
   

}

//TODO: Tamara
void distributeCardToPlayers(Player* player,Player* enemy, Player* cardDistributer) {
    Card* secondCardStack = getIndex(5, cardDistributer);
    Card* firstCardStack = removeCard(cardDistributer, secondCardStack);
    player->pfirstCardOfList = firstCardStack;
    enemy->pfirstCardOfList = secondCardStack;
    player->pLastCardOfList = getLast(firstCardStack);
    enemy->pLastCardOfList = getLast(secondCardStack);
     
    //Give each player their Stack of Cards
}
// TODO: Tamara
void getFirstElementOfCardStack() {
    //Get First element of player and enemy of Stack ^^
}

// Autor der Methode Raksana
int inputCompareValue() {
    int valueToCompare;
    int* pvalueToCompare = &valueToCompare;
    printf("Geben Sie den Vergleichs wert ein: \n");
    scanf_s("%i", pvalueToCompare);
    printf("%i", valueToCompare);
    if (checkInputValue(pvalueToCompare)) {
        return *pvalueToCompare;
    }

    inputCompareValue();

}

// Autor der Methode Raksana
Player defineHigherCard(Player* pPlayer, Player* pEnemy, int* valueToCheck) {
    Card* enemy= pEnemy->pfirstCardOfList;
    Card* player= pPlayer->pfirstCardOfList;

    if ((*valueToCheck == 1 && player->usetime > enemy->usetime) || (*valueToCheck == 2 && player->wight > enemy->wight))
    {
        return *pPlayer;
    }
    else {
        return *pEnemy;
    }
}
//TODO: Raksana
void addCardToListOfWinnerAndPutSecondTo() {
    //Get first cart of loser and set behinde stack of winner with first card of winner
}


//TODO: Tamara
void showWinner() {
    //show who won and ask if player wants to play again
}

/*Autor: Tamara
* Erstellen von Karten -> Informationen der verschiedenen Laptops
*/
int main()
{
    //1.) Apple MacBook Pro (2021)
    struCard* pcard  = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez,"Apple MacBook Pro(2021)");
    pcard->usetime = 17;
    pcard->wight = 1.6;
    pcard->pNext = NULL;
    struCard* pStartPlayer=pcard;
   
    // 2.) ACER Swift 1-C0WY
    pcard = (struCard*)malloc( sizeof(struCard));
    strcpy_s(pcard->Bez, "ACER Swift 1-C0WY");
    pcard->usetime = 16;
    pcard->wight = 1.5;
    pcard->pNext = NULL;
    pStartPlayer->pNext = pcard;
    struCard* pCard2 = pcard;

    // 3.) HP Pavilion Aero 13
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "HP Pavilion Aero 13");
    pcard->usetime = 10;
    pcard->wight = 1.0;
    pcard->pNext = NULL;
    pCard2->pNext = pcard;
    struCard* pCard3 = pcard;

    // 4.) MICROSOSFT Surface Go
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "MICROSOSFT Surface Go");
    pcard->usetime = 13;
    pcard->wight = 1.110;
    pcard->pNext = NULL;
    pCard3->pNext = pcard;
    struCard* pCard4 = pcard;

    // 5.) LENOVO V15
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "LENOVO V15");
    pcard->usetime = 6;
    pcard->wight = 1.85;
    pcard->pNext = NULL;
    pCard4->pNext = pcard;
    struCard* pCard5 = pcard;
 
    // 6.) HUAWEI MateBook D15
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "HUAWEI MateBook D15");
    pcard->usetime = 7;
    pcard->wight = 1.53;
    pcard->pNext = NULL;
    pCard5->pNext = pcard;
    struCard* pCard6 = pcard;

    //KONTROLLIEREN

    // 7.) LENOVO ThinkPad P17
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "LENOVO ThinkPad P17");
    pcard->usetime = 8;
    pcard->wight = 3.67;
    pcard->pNext = NULL;
    pCard6->pNext = pcard;
    struCard* pCard7 = pcard;

    // 8.) DELL Latitude 7410
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "DELL Latitude 7410");
    pcard->usetime = 6;
    pcard->wight = 1.33;
    pcard->pNext = NULL;
    pCard7->pNext = pcard;
    struCard* pCard8 = pcard;

    // 9.) HP OMEN
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "HP OMEN");
    pcard->usetime = 6;
    pcard->wight = 2.45;
    pcard->pNext = NULL;
    pCard8->pNext = pcard;
    struCard* pCard9 = pcard;

    // 10.) ASUS E210MA
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "ASUS E210MA");
    pcard->usetime = 5;
    pcard->wight = 1.05;
    pcard->pNext = NULL;
    pCard9->pNext = pcard;
    struCard* pCard10 = pcard;

    //start eneamy Card Talon

    struPlayer* pPlayer = (Player*)malloc(sizeof(Player));
    pPlayer->pfirstCardOfList = pStartPlayer;
    pPlayer->pLastCardOfList = pCard6;
    Card* cards = getLast(pPlayer->pfirstCardOfList);
    Output(cards);
    system("pause");
    return 0;
}

