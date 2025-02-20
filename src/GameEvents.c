/*
    Description: GameEvents.c is a collection of functions that are required to "play" the game
    Author: Aaron Nicholas Lizardo Gumapac
*/

#include "../libdefs/GameEvents.h"

/*
    Dynamically calculates the cost necessary to pay rent when the player lands on a property owned by the opponent
    Preconditions: the property being checked is owned by the opponent
    @param propIndex the position of the property on the board
    @param roll the player's dice roll during this turn
    @param electricMulti the electric company's multiplier, described in struct settings
    @param railRent the cost of rent for the railroad
    @returns the cost of rent for the property at the given index
*/
int getRent(int propIndex, int roll, int electricMulti, int railRent)
{
    if (propIndex == 2)
        return electricMulti * roll;
    if (propIndex == 7)
        return railRent;

    return propIndex % 7 * 20 * 0.2;
}

/*
    Dynamically calculates the cost necessary to purchase a property owned by the bank
    Preconditions: the property being checked is owned by the bank
    @param propIndex the position of the property on the board
    @param electricCost the cost necessary to purchase the electric company, described in struct settings
    @param railCost the cost necessary to purchase the railraod, described in struct settings
    @returns the cost of the property at the index
*/
int getPropertyCost(int propIndex, int electricCost, int railCost)
{
    if (propIndex == 2)
        return electricCost;
    if (propIndex == 7)
        return railCost;

    return propIndex % 7 * 20;
}

/*
    This pure function creates and returns a new mutated statekey. The mutation occurs at the given index for one digit.
    Preconditions: STATEKEY is a 9 digit integer
    @param STATEKEY 9 digit integer used to track property statuses
    @param index the position of the digit to be changed
    @param value the value of the mutation
    @param OFFSET predefined statekey offset
    @returns new statekey with value inserted at index
*/
int mutateStatekeyAtIndex(unsigned int STATEKEY, unsigned int index, unsigned int value, int OFFSET)
{
    if (STATEKEY / exponentiateNum(10, index - 1) == 0 || index < 1)
    { // if the given index is outside of the statekey's range

        setRed
            printf("\ninvalid index");
        resetColor

        return 0; // standard error value
    }

    index -= 1;
    value %= 10;                                                   // normalize value to prevent inputs > 1 digit
    int normalizedNum = normalizeNumByIndex(STATEKEY, index + 1);  // set values inclusive of index to zero
    int insertion = (value - OFFSET) * exponentiateNum(10, index); // insert the mutation by the index's position
    int trailing = STATEKEY % exponentiateNum(10, index);          // add trailing unmutated numbers
    int mutatedStateKey = normalizedNum + insertion + trailing;    // final summation

    return mutatedStateKey;
}

/*
    This function returns the value of the statekey at the given index
    Preconditions: index is between 1 and 9
    @param STATEKEY 9 digit integer that tracks all properties on the board
    @param index the location of the digit to be returned
    @OFFSET predefined statekey offset
    @returns digit at the index
*/
int readStatekeyAtIndex(unsigned int STATEKEY, unsigned int index, int OFFSET)
{

    if (STATEKEY / exponentiateNum(10, index - 1) == 0 || index < 1)
    { // if the given index is outside of the statekey's range

        setRed
            printf("\ninvalid index");
        resetColor

        return 0; // standard error value
    }

    return (((STATEKEY / exponentiateNum(10, index - 1)) % 10) + OFFSET);
}
