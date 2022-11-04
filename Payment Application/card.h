#ifndef CARD_H_
#define CARD_H_

#include <stdio.h>
#include<string.h>
#include <stdlib.h>

                                                                 /* typedef declaration */
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
                                                          /* Card Information typedef declaration */
typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
}ST_cardData_t;

                                                                /* Error typedef declaration */
typedef enum EN_cardError_t
{
    CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;


                                                                /* functions' prototypes */
EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);
                                                                /*extern for global variables*/
extern ST_cardData_t* cardptr;

#endif
