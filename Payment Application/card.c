#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "card.h"

                                                          /* Global variables */

ST_cardData_t card;
ST_cardData_t* cardptr = &card;


                                                           /* Card Functions */

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
    EN_cardError_t name_error_type = 0;
    uint8_t name[40] = {0};
    uint16_t i = 0;

    printf("Please enter your name : "); // Asking the client to enter their name
   // printf("\n");
    fgets(name, sizeof(name), stdin);  // Take string input from the client

    while (name[i] != '\0')
    {
        i++;
    }

    if (i > 20 && i < 26)
    {
        name_error_type = CARD_OK;
        strcpy(cardData->cardHolderName, name);
        cardData->cardHolderName[i-1] = NULL;
    }
    else 
    {
        name_error_type = WRONG_NAME;
    }

    fflush(stdin);

    return name_error_type;

}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
    EN_cardError_t exp_error_type = 0;
    uint8_t exp[10] = {0};
    uint16_t j = 0;
    uint8_t MM[3] = {0};
    uint8_t YY[3] = {0};
    uint16_t MM_number = 0;
    uint16_t YY_number = 0;

    printf("Please enter card exp date in form MM/YY : "); // Asking the client to enter card expiry date
   // printf("\n");
    fgets(exp, sizeof(exp), stdin);  // Take string input from the client

    while (exp[j] != '\0')
    {
        j++;
    }

    MM[0] = exp[0];
    MM[1] = exp[1];
    MM[2] = NULL;
    MM_number = atoi(MM);

    YY[0] = exp[3];
    YY[1] = exp[4];
    YY[2] = NULL;
    YY_number = atoi(YY);

    if (exp[2] != '/') 
    {
        exp_error_type = WRONG_EXP_DATE;
    }
    else if (MM_number > 12)
    {
        exp_error_type = WRONG_EXP_DATE;
    }
    else if (YY_number < 22)
    {
        exp_error_type = WRONG_EXP_DATE;
    }
    else if (j != 6)
    {
        exp_error_type = WRONG_EXP_DATE;
    }
    else 
    {
        exp_error_type = CARD_OK;
        strcpy(cardData->cardExpirationDate, exp);
        cardData->cardExpirationDate[5] = NULL;
    }

    return exp_error_type;
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
    EN_cardError_t pan_error_type = 0;
    uint8_t pan[40] = {0};
    uint16_t k = 0;

    printf("Please enter your card's PAN : "); // Asking the client to enter their card's PAN
    //printf("\n");
    fgets(pan, sizeof(pan), stdin);  // Take string input from the client

    while (pan[k] != '\0')
    {
        k++;
    }

    if (k > 16 && k < 21)
    {
        pan_error_type = CARD_OK;
        strcpy(cardData->primaryAccountNumber, pan);
        cardData->primaryAccountNumber[k-1] = NULL;
    }
    else
    {
        pan_error_type = WRONG_PAN;
    }

    return pan_error_type;

}






