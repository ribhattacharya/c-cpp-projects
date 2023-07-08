/*
Poker hand probabilities using Monte Carlo
C for Everyone: Structured Programming
Week 2
Rishabh Bhattacharya
Jul 6th, 2023

Program description: Shuffle a deck of 52 cards NCALLS times, and then pick out a 7 card hand.
Compute the probabilities of a pattern appearing over all the trials (Monte Carlo method).
Verify using combinatorial mathematics.

--------------------OUTPUT-----------------------

SAMPLES RUN: 0%
SAMPLES RUN: 10%
SAMPLES RUN: 20%
SAMPLES RUN: 30%
SAMPLES RUN: 40%
SAMPLES RUN: 50%
SAMPLES RUN: 60%
SAMPLES RUN: 70%
SAMPLES RUN: 80%
SAMPLES RUN: 90%

------SUMMARY---------
NCALLS: 100000000

Pattern          Appearances     Probability

Four of a kind : 168281          (0.001683)
Full house     : 2553838         (0.025538)
Three of a kind: 4964910         (0.049649)
Two pair       : 23999193        (0.239992)
One pair       : 47286379        (0.472864)
No pair        : 21027399        (0.210274)
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NCALLS 100000000        // calls to make for estimating probability
#define NHAND 7                 // No. of hands to deal
#define NDECK 52                // Deck size
#define NSUITS 4
#define NPIPS 13
#define NPATTERNS 6             // No. of patterns to detect


// Initialize the required data structures
typedef enum {HEARTS, DIAMONDS, SPADES, CLUBS} Suit;
typedef struct {Suit suit; short int pip;} Card;   // suit (0-3); pip (0-12)
typedef enum {FOUR_OF_A_KIND, FULL_HOUSE, THREE_OF_A_KIND, TWO_PAIR, ONE_PAIR, NO_PAIR} Patterns;
typedef enum {false, true} bool;

const char *suits[NSUITS] = {"Hearts", "Diamonds", "Spades", "Clubs"};
const char *pips[NPIPS] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const char* patterns[NPATTERNS] = {"Four of a kind", "Full house", "Three of a kind", "Two pair", "One pair", "No pair"};

void createDeck(Card deck[]) {
    /*
    DESC: Fills the empty deck.
    INPUTS:
        Card deck[]: Empty deck.
    */
    int k=0;
    
    for (int i=0; i<NSUITS; i++){
        for (int j=0; j<NPIPS; j++){
            deck[k].suit = i;
            deck[k].pip = j;
            k++;
        }
    }

    return;   
}

void shuffleDeck(Card deck[]) {
    /*
    DESC: Shuffles the deck.
    INPUTS:
        Card deck[]: Deck.
    */

    for (int i=0; i<NDECK; i++) {
        int j = rand() % NDECK;

        // Swap cards
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    return;
}

void printcard(const Card c) {
    /*
    DESC: Prints current card.
    
    INPUTS:
        card c: card.
    */
    printf("%s of %s\n", pips[c.pip], suits[c.suit]);
    return;
}

void checkHand(Card hand[], int counter[]) {
    /*
    DESC: Checks the current hand and increments the detected pattern
    
    INPUTS:
        Card hand[]: The current hand.
        int counter[]: The counter array for counting the patterns cumulatively.
    */
    int pip_freq[NPIPS] = {0}; // Pip frequencies

    // Count all pips
    for (int i=0; i<NHAND; i++) 
        pip_freq[hand[i].pip]++;
    
    bool four_of_a_kind = false, three_of_a_kind = false, 
            two_pair = false, one_pair = false;
    
    // Detect frequency of each pip
    for (int i=0; i<NPIPS; i++) {
        if (pip_freq[i] == 4)
            four_of_a_kind = true;
        else if (pip_freq[i] == 3)
            three_of_a_kind = true;
        else if (pip_freq[i] == 2) {
            if (one_pair)
                two_pair = true;
            one_pair = true;
        }
    }

    // Increment counter based on the priority of the pattern detected.
    if (four_of_a_kind)
        counter[FOUR_OF_A_KIND]++;
    else if (three_of_a_kind && one_pair)
        counter[FULL_HOUSE]++;
    else if (three_of_a_kind)
        counter[THREE_OF_A_KIND]++;
    else if (two_pair)
        counter[TWO_PAIR]++;
    else if (one_pair)
        counter[ONE_PAIR]++;
    else
        counter[NO_PAIR]++;

    return;
}

int main(void) { 
    
    srand(time(NULL));
    
    Card deck[NDECK];    // Create empty deck
    int counter[NPATTERNS] = {0};
    
    createDeck(deck);    // Fill the deck with unique cards.
       
    for (int i=0; i<NCALLS; i++) {
        if (i % (NCALLS/10) == 0) 
            printf("\nSAMPLES RUN: %ld%%", (long int) i * 100 / NCALLS);
        
        // Shuffle deck and pull a hand from the top of the deck
        shuffleDeck(deck);   
        Card hand[NHAND];
        for (int j=0; j<NHAND; j++) 
            hand[j] = deck[j];
        
        checkHand(hand, counter);   // Check the current hand for any patterns
    }
    
    printf("\n\n------SUMMARY---------\n");
    printf("NCALLS: %d\n\n", NCALLS);
    printf("%-15s  %-15s %s\n", "Pattern", "Appearances", "Probability");
    printf("\n");

    for(int j=0; j<NPATTERNS; j++)
        printf("%-15s: %-15d (%lf)\n", patterns[j], counter[j], (double)counter[j] / NCALLS);
    
    return 0;
}