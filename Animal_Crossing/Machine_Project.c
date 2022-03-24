/******************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the
concepts learned. I have constructed the functions and their respective algorithms
and corresponding code by myself. The program was run, tested, and debugged by my own efforts. I further
certify that I have not copied in part or whole or otherwise plagiarized the work of other students and/or
persons.

<Jeremy Cerwin Cai Wang>, DLSU ID# <12132543>
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Displays welcome message
void displayWelcomeMessage()
{
    printf("Welcome to Stalk Market Millionaire!\n\n");
}

//Displays the mechanics of the game
void displayMechanics()
{

    printf("You will be given 5,000 bells to achieve 1,000,000 bells by the end of 20 weeks.\n\n");

    printf("Every Sunday, Daisy Mae will visit to sell you Turnips.\n");
    printf("The buying price of each turnip would be between 90-110 bells each week.\n");
    printf("NOTE: You may only buy turnips in stacks. 1 stack = 10 turnips.\n\n");

    printf("You can sell your Turnips at Nook's Cranny any day excecpt for Sundays.\n");
    printf("The price Nook's Cranny will buy your turnips for will randomly change each day.\n");
    printf("IMPORTANT: Any unsold turnips will spoil by the end of the week.\n\n");

    printf("There will be 3 different price trends randomly set at Nook's Cranny each week.\n");
    printf("Average Trend - The pricing for the week for this trend will have a minimum of the 80 Bells and a maximum of a 5%% increase of the Sunday price.\n");
    printf("Awesome Trend - The pricing for the week for this trend will have a minimum of the Sunday price and a maximum of 300%% of the Sunday price.\n");
    printf("Bad Trend - The pricing for the week for this trend will have a minimum price of 20 Bells and have a maximum of the Sunday price.\n\n");

    printf("The game will end after the end of the 20th week whether you finish or not.\n");
    printf("It will also end if you do not have enough bells to buy atleast 1 stack of turnips.\n\n");
}

/* This function displays the current day of the player in word form.
@param nDay The current day the player is in. (In numeric form)
@return Day of week in word form
*/
void displayCurrentDay(int nDay)
{
    while(nDay > 7)
    {
        nDay = nDay - 7;
    }

    if(nDay == 7)
    {
        printf("Saturday\n");
    }

    if(nDay == 6)
    {
        printf("Friday\n");
    }

    if(nDay == 5)
    {
        printf("Thursday\n");
    }

    if(nDay == 4)
    {
        printf("Wednesday\n");
    }

    if(nDay == 3)
    {
        printf("Tuesday\n");
    }

    if(nDay == 2)
    {
        printf("Monday\n");
    }

    if(nDay == 1)
    {
        printf("Sunday\n");
    }

}

/* This function determines the week based on the current day
@param nDay The current day the player is in.
@return Current week
*/
int getCurrentWeek(int nDay)
{
    int nWeek;

    if(nDay % 7 != 0)
    {
        nWeek = nDay / 7 + 1;
        return nWeek;
    }
    
    else if(nDay % 7 == 0)
    {
        nWeek = nDay / 7;
        return nWeek;
    }

    return 0;
}

/* This function displays the current status of the player.
@param nCurrentDay The current day the player is in. (In numeric form)
@param nCurrentBells Amount of bells the player currently has.
@param nCurrentTurnips Amount of turnips the player current has.
*/
void displayStatus(int nCurrentDay, int nCurrentBells, int nCurrentTurnips)
{
    printf("\n-------------------------------\n");
    printf("Week: %d\n", getCurrentWeek(nCurrentDay));
    printf("Day: "), displayCurrentDay(nCurrentDay);
    printf("Bells: %d\n", nCurrentBells);
    printf("Turnips (Stacks): %d\n", nCurrentTurnips);
    printf("Turnips: %d\n", nCurrentTurnips * 10);
    printf("-------------------------------\n\n");
}

/* This function displays how much bells and turnips the player currently has.
@param nCurrentBells Amount of bells the player currently has.
@param nCurrentTurnips Amount of turnips the player current has.
*/
void displayTurnipStatus(int nCurrentBells, int nCurrentTurnips)
{
    printf("\n-------------------------------\n");
    printf("Bells: %d\n", nCurrentBells);
    printf("Turnips (Stacks): %d\n", nCurrentTurnips);
    printf("Turnips: %d\n", nCurrentTurnips * 10);
    printf("-------------------------------\n\n");
}

/* Function gets a random number between 90-110
@return Buy price of turnips 
*/
int isTurnipBuyPrice()
{
    int nBuyPrice;
    int nLower = 90; //Minimum price of turnips
    int nUpper = 110; //Maximum price of turnips
    
    srand(time(0));
    
    nBuyPrice = (rand() % (nUpper - nLower + 1)) + nLower;

    return nBuyPrice;
}

/* Function determines which trend it will be for the week
@return 1 for Average Trend,
        2 for Awesome Trend,
        3 for Bad Trend
*/
int getWeeklyTrend()
{
    int nTrend;

    srand(time(0));

    nTrend = rand() % 3 + 1;

    return nTrend;
}

/* Function gets the turnip price based on the weekly trend
@param nTurnipBuyPrice Price of turnips on Sunday
@param nWeeklyTrend Trend of the Week
@return Sell price of turnips 
*/
int isTurnipSellPrice(int nTurnipBuyPrice, int nWeeklyTrend)
{
    int nLower;
    int nUpper;
    int nSellPrice;

    srand(time(0));

    //Average Trend
    if(nWeeklyTrend == 1)
    {
        nLower = 80;
        nUpper = nTurnipBuyPrice * 0.05 + nTurnipBuyPrice;

        nSellPrice = (rand() % (nUpper - nLower + 1)) + nLower;
    }

    //Awesome Trend
    else if (nWeeklyTrend == 2)
    {
        nLower = nTurnipBuyPrice;
        nUpper = nTurnipBuyPrice * 3;

        nSellPrice = (rand() % (nUpper - nLower + 1)) + nLower;
    }
    
    //Bad Trend
    else if (nWeeklyTrend == 3)
    {
        nLower = 20;
        nUpper = nTurnipBuyPrice;

        nSellPrice = (rand() % (nUpper - nLower + 1)) + nLower;
    }

    return nSellPrice;
}

/* Returns 1 if the player want to start playing 
*/
int isWantStart(char cChoice)
{
    if (cChoice == 's' || cChoice == 'S')
    {
        return 1;
    }

    return 0;
}

/* Returns 1 if the day is Sunday 
*/
int isSunday(int nDay)
{
    while(nDay > 7)
    {
        nDay = nDay - 7;
    }

    if (nDay == 1)
    {
        return 1;
    }

    return 0;
}

/* Returns 1 if the player can continue playing
@param nCurrentBells Amount of bells the player currently has.
@param nCurrentTurnips Amount of turnips the player currently has.
@param nCurrentDay The current day the player is in.
*/
int isValidStatus(int nCurrentBells, int nCurrentTurnips, int nCurrentDay)
{
    if (isSunday(nCurrentDay) == 1)
        {
            nCurrentTurnips = 0;
        }

    //Checks if the current amount of bells is enough to buy 1 stack of turnips
    //If bells are not enough and the player has no turnips left, function returns 0
    if (nCurrentBells <= isTurnipBuyPrice() * 10 && nCurrentTurnips == 0)
    {
        return 0;
    }

    //Returns 0 when the 20th week ends
    if (nCurrentDay > 140)
    {
        return 0;
    }

    return 1;
}

/* Returns 1 if the player has enough bells to buy more turnips
@param nTurnipPrice Price of turnips at the time the player is buying them.
@param nBells Amount of bells the player currently has.
@param nStacks Amount of stacks player wants to buy
*/
int isEnoughBells(int nTurnipPrice, int nBells, int nStacks)
{
    if (nBells >= nTurnipPrice * 10 * nStacks)
    {
        return 1;
    }

    return 0;
}

/* Returns 1 if the player has enough turnips to sell
@param nCurrentTurnips Amount of turnips the player currently has.
@param nStacks Amount of stacks player wants to sell
*/
int isEnoughTurnips(int nCurrentTurnip, int nStacks)
{
    if (nCurrentTurnip >= nStacks)
    {
        return 1;
    }

    return 0;
}

/* Gets the final amount of bells and turnips the player has after buying
@param nTurnipPrice Price of turnips at the time the player is buying them.
@param nBells Amount of bells the player currently has.
@param nStacks Amount of stacks player wants to buy.
@param nTurnipStacks Amount of turnips the player has.
*/
void getBuyBellsAndTurnips(int nTurnipPrice, int * nBells, int nStacks, int * nTurnipStacks)
{
    * nBells = * nBells - nStacks * nTurnipPrice * 10;
    * nTurnipStacks = * nTurnipStacks + nStacks;
}

/* Gets the final amount of bells and turnips the player has after selling
@param nTurnipPrice Price of turnips at the time the player is selling them.
@param nBells Amount of bells the player currently has.
@param nStacks Amount of stacks player wants to buy.
@param nTurnipStacks Amount of turnips the player has.
*/
void getSellBellsAndTurnips(int nTurnipPrice, int * nBells, int nStacks, int * nTurnipStacks)
{
    * nBells = * nBells + nStacks * nTurnipPrice * 10;
    * nTurnipStacks = * nTurnipStacks - nStacks;
}

/* Returns 1 if the player chose a valid choice
@param cChoice Choice of the player.
*/
int isValidChoice(char cChoice)
{
    if (cChoice == 'B' || cChoice == 'b')
    {
        return 1;
    }
    
    else if (cChoice == 'S' || cChoice == 's')
    {
        return 1;
    }
    
    else if (cChoice == 'N' || cChoice == 'n')
    {
        return 1;
    }

    return 0;
    
}

int main()
{
    char cStart;
    char cChoice;
    char cBuyChoice = 'B';
    char cSellChoice = 'S';
    int nDay = 1;
    int nBells = 5000;
    int nTurnipStacks;
    int nStacks;
    int nTurnipBuyPrice;
    int nTurnipSellPrice;
    int nWeeklyTrend;
    int nIsBought = 0;
    int nIsSold = 0;

    displayWelcomeMessage();

    displayMechanics();

    //Player will choose to play or not play the game
    printf("[S]tart \n[E]xit \nChoice: ");
    scanf("%c", &cStart);

    //Player chose to play the game
    if (isWantStart(cStart) == 1)
    {
        //Code will run on a loop if the player has enough bells and if it is still not the end of the 20th week
        while(isValidStatus(nBells, nTurnipStacks, nDay) == 1)
        {
            //The leftover turnips will spoil here
            if (isSunday(nDay) == 1)
            {
                nTurnipStacks = 0;
            }

            printf("\n*************************************************************\n");
            displayStatus(nDay, nBells, nTurnipStacks);
            
            if (isSunday(nDay) == 1)
            {
                nWeeklyTrend = getWeeklyTrend();
                nTurnipBuyPrice = isTurnipBuyPrice();
                printf("Turnip Buy Price: %d\n", nTurnipBuyPrice);
                printf("[B]uy\n");
            }

            else if (isSunday(nDay) == 0)
            {
                nTurnipSellPrice = isTurnipSellPrice(nTurnipBuyPrice, nWeeklyTrend);
                printf("Turnip Sell Price: %d\n", nTurnipSellPrice);
                printf("[S]ell\n");
            }
            
            printf("[N]ext Day\n");
            printf("Choice: ");
            scanf(" %c", &cChoice);

            do
            {
                //Buy Condition
                if (cChoice == 'B' || cChoice == 'b')
                {
                    cBuyChoice = 'B';

                    do
                    {
                        if ((cBuyChoice == 'B' || cBuyChoice == 'b') && nBells >= nTurnipBuyPrice * 10)
                        {
                            do
                            {
                                do
                                {
                                    //Asks how much turnips the player wants to buy
                                    printf("\n*************************************************************\n");
                                    displayTurnipStatus(nBells, nTurnipStacks);
                                    printf("Turnip Buy Price: %d\n", nTurnipBuyPrice);
                                    printf("Turnip Buy Price (1 Stack): %d\n\n", nTurnipBuyPrice * 10);
                                    printf("How many stacks of turnips do you want to buy?\n");
                                    printf("Stacks: ");
                                    scanf("%d", &nStacks);
                                } while (nStacks < 0);
                                
                                if (isEnoughBells(nTurnipBuyPrice, nBells, nStacks) == 1)
                                {
                                    //Function solves for bells and turnips after buying
                                    getBuyBellsAndTurnips(nTurnipBuyPrice, &nBells, nStacks, &nTurnipStacks);

                                    nIsBought = 1;
                                }
                            
                                else if (isEnoughBells(nTurnipBuyPrice, nBells, nStacks) == 0)
                                {
                                    printf("\n*************************************************************\n\n");
                                    printf("<<<Insufficient Bells. Please try again.>>>\n");

                                    nIsBought = 0;
                                }
                            } while (isEnoughBells(nTurnipBuyPrice, nBells, nStacks) == 0 && nIsBought == 0);
                        }
                        
                        if ((cBuyChoice == 'B' || cBuyChoice == 'b') && nBells >= nTurnipBuyPrice * 10)
                        {
                            //Asks if player wants to buy more or proceed to the next day
                            printf("\n*************************************************************\n");
                            displayTurnipStatus(nBells, nTurnipStacks);
                            printf("Turnip Buy Price: %d\n", nTurnipBuyPrice);
                            printf("Turnip Buy Price (1 Stack): %d\n\n", nTurnipBuyPrice * 10);
                            printf("[B]uy More\n");
                            printf("[N]ext Day\n");
                            printf("Choice: ");
                            scanf(" %c", &cBuyChoice);
                        }

                        else if (((cBuyChoice == 'N' || cBuyChoice == 'n') || (cBuyChoice == 'B' || cBuyChoice == 'b')) && nBells < nTurnipBuyPrice * 10)
                        {
                            printf("\n*************************************************************\n");
                            displayTurnipStatus(nBells, nTurnipStacks);
                            printf("<<<Insufficient bells to buy more turnips. Please procceed to the next day.>>>\n\n");
                            printf("[N]ext Day\n");
                            printf("Choice: ");
                            scanf(" %c", &cBuyChoice);
                        }

                        //Invalid Input, but the player still has sufficient bells to buy more turnips
                        else if (((cBuyChoice != 'N' || cBuyChoice != 'n') || (cBuyChoice != 'B' || cBuyChoice != 'b')) && nBells > nTurnipBuyPrice * 10)
                        {
                            printf("\n*************************************************************\n");
                            displayTurnipStatus(nBells, nTurnipStacks);
                            printf("<<<Invalid Input. Please try again.>>>\n\n");
                            printf("[B]uy More\n");
                            printf("[N]ext Day\n");
                            printf("Choice: ");
                            scanf(" %c", &cBuyChoice);
                        }

                        //Invalid Input, but the player does not have sufficient bells to buy more turnips
                        else if (((cBuyChoice != 'N' || cBuyChoice != 'n') || (cBuyChoice != 'B' || cBuyChoice != 'b')) && nBells < nTurnipBuyPrice * 10)
                        {
                            printf("\n*************************************************************\n");
                            displayTurnipStatus(nBells, nTurnipStacks);
                            printf("<<<Invalid Input. Please procceed to the next day.>>>\n\n");
                            printf("[N]ext Day\n");
                            printf("Choice: ");
                            scanf(" %c", &cBuyChoice);
                        }
                    
                    } while(cBuyChoice != 'N' && cBuyChoice != 'n');

                    if (cBuyChoice == 'N' || cBuyChoice == 'n')
                    {
                        nDay++;
                        cChoice = 'N';
                    }
                }

                //Sell Condition
                else if (cChoice == 'S' || cChoice == 's')
                {
                    cSellChoice = 'S';

                    do
                    {   
                        if ((cSellChoice == 'S' || cSellChoice == 's') && nTurnipStacks > 0)
                        {
                            do
                            {
                                do
                                {
                                    //Asks how much turnips the player wants to sell
                                    printf("\n*************************************************************\n");
                                    displayTurnipStatus(nBells, nTurnipStacks);
                                    printf("Turnip Sell Price: %d\n", nTurnipSellPrice);
                                    printf("Turnip Sell Price (1 Stack): %d\n\n", nTurnipSellPrice * 10);
                                    printf("How many stacks of turnips do you want to sell?\n");
                                    printf("Stacks: ");
                                    scanf("%d", &nStacks);
                                } while (nStacks < 0);
                                
                                if (isEnoughTurnips(nTurnipStacks, nStacks) == 1)
                                {
                                    //Function solves for bells and turnips after selling
                                    getSellBellsAndTurnips(nTurnipSellPrice, &nBells, nStacks, &nTurnipStacks);

                                    nIsSold = 1;
                                }
                            
                                else if (isEnoughTurnips(nTurnipStacks, nStacks) == 0)
                                {
                                    printf("\n*************************************************************\n\n");
                                    printf("<<<Insufficient Turnips. Please try again.>>>\n\n");

                                    nIsSold = 0;
                                }
                            } while (isEnoughTurnips(nTurnipStacks, nStacks) == 0 && nIsSold == 0);
                        }
                        
                        if ((cSellChoice == 'S' || cSellChoice == 's') && nTurnipStacks > 0)
                        {
                            //Asks if player wants to sell more or proceed to the next day
                            printf("\n*************************************************************\n");
                            displayTurnipStatus(nBells, nTurnipStacks);
                            printf("Turnip Sell Price: %d\n", nTurnipSellPrice);
                            printf("Turnip Sell Price (1 Stack): %d\n\n", nTurnipSellPrice * 10);
                            printf("[S]ell More\n");
                            printf("[N]ext Day\n");
                            printf("Choice: ");
                            scanf(" %c", &cSellChoice);
                        }

                        else if (((cSellChoice == 'N' || cSellChoice == 'n') || (cSellChoice == 'S' || cSellChoice == 's')) && nTurnipStacks <= 0)
                        {
                            printf("\n*************************************************************\n");
                            displayTurnipStatus(nBells, nTurnipStacks);
                            printf("<<<Insufficient turnips to sell. Please procceed to the next day.>>>\n\n");
                            printf("[N]ext Day\n");
                            printf("Choice: ");
                            scanf(" %c", &cSellChoice);
                        }

                        //Invalid Input, but the player has sufficient turnips sell
                        else if (((cSellChoice != 'N' || cSellChoice != 'n') || (cSellChoice != 'S' && cSellChoice != 's')) && nTurnipStacks > 0)
                        {
                            printf("\n*************************************************************\n");
                            displayTurnipStatus(nBells, nTurnipStacks);
                            printf("<<<Invalid Input. Please try again.>>>\n\n");
                            printf("[S]ell More\n");
                            printf("[N]ext Day\n");
                            printf("Choice: ");
                            scanf(" %c", &cSellChoice);
                        }

                        //Invalid Input, but the player does not have sufficient turnips to sell
                        else if (((cSellChoice != 'N' && cSellChoice != 'n') || (cSellChoice != 'S' && cSellChoice != 's')) && nTurnipStacks <= 0)
                        {
                            printf("\n*************************************************************\n");
                            displayTurnipStatus(nBells, nTurnipStacks);
                            printf("<<<Invalid Input. Please procceed to the next day.>>>\n\n");
                            printf("[N]ext Day\n");
                            printf("Choice: ");
                            scanf(" %c", &cSellChoice);
                        }

                    } while(cSellChoice != 'N' && cSellChoice != 'n');

                    if (cSellChoice == 'N' || cSellChoice == 'n')
                    {
                        nDay++;
                        cChoice = 'N';
                    }
                    
                }

                else if (cChoice == 'N' || cChoice == 'n')
                {
                    nDay++;
                }

                else
                {
                    printf("\n*************************************************************\n\n");
                    printf("<<<Invalid Input. Please try again.>>>\n\n");
                     printf("\n*************************************************************\n\n");
                    
                    if (isSunday(nDay) == 1)
                    {
                        printf("Turnip Buy Price: %d\n", nTurnipBuyPrice);
                        printf("[B]uy\n");
                    }

                    else if (isSunday(nDay) == 0)
                    {
                        printf("Turnip Sell Price: %d\n", nTurnipSellPrice);
                        printf("[S]ell\n");
                    }
            
                    printf("[N]ext Day\n");
                    printf("Choice: ");
                    scanf(" %c", &cChoice);
                }
                
            } while (cChoice != 'N' && cChoice != 'n');
            

        }

        //The player ran out of bells
        if(nBells <= nTurnipBuyPrice * 10)
        {
            printf("\n*************************************************************\n\n");
            printf("Sorry, you ran out of bells\n");
            printf("Game Over\n");
            printf("\n*************************************************************\n");
        }

        //The player failed to achieve 1,000,000 bells
        else if(nBells < 1000000 && nDay > 140)
        {
            printf("\n*************************************************************\n\n");
            printf("Sorry, you ran out of time.\n");
            printf("Game Over\n");
            printf("\n*************************************************************\n");
        } 

        //The player succeeded and achieved 1,000,000 bells
        else if(nBells >= 1000000 && nDay > 140)
        {
            printf("\n*************************************************************\n\n");
            printf("Congratulations! You have achieved the goal!\n");
            printf("\n*************************************************************\n");
        }

    }

    //Player chose to not play the game
    else
    {
        printf("Goodbye.");
    }

    system("pause");
    return 0;
}