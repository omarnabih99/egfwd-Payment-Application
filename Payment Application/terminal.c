#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include "terminal.h"
                                                         /* Global variables */
ST_terminalData_t terminal;
ST_terminalData_t* terminalptr = &terminal;

														/* Terminal Functions */

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	EN_terminalError_t trans_date_error_type = 0; // OK or WRONG_DATE
	uint8_t transaction[20] = {0};
	uint16_t i = 0;
	uint8_t dd[3] = {0};
	uint8_t mm[3] = {0};
	uint8_t yyyy[5] = {0};
	uint16_t dd_number = 0;
	uint16_t mm_number = 0;
	uint16_t yyyy_number = 0;

	printf("Please enter transaction date in form DD/MM/YYYY : "); // Asking the client to enter transaction date
	//printf("\n");
	fgets(transaction, sizeof(transaction), stdin);  // Take string input from the client

	while (transaction[i] != '\0')
	{
		i++;
	}

	dd[0] = transaction[0];
	dd[1] = transaction[1];
	dd[2] = '\0';
	dd_number = atoi(dd);

	mm[0] = transaction[3];
	mm[1] = transaction[4];
	mm[2] = '\0';
	mm_number = atoi(mm);

	yyyy[0] = transaction[6];
	yyyy[1] = transaction[7];
	yyyy[2] = transaction[8];
	yyyy[3] = transaction[9];
	yyyy[4] = '\0';
	yyyy_number = atoi(yyyy);

	if ((transaction[2] != '/') | (transaction[5] != '/')) 
	{
		trans_date_error_type = WRONG_DATE;
	}
	else if (dd_number > 31)
	{
		trans_date_error_type = WRONG_DATE;
	}
	else if (mm_number > 12)
	{
		trans_date_error_type = WRONG_DATE;
	}
	else if (yyyy_number < 2022)
	{
		trans_date_error_type = WRONG_DATE;
	}
	else if (i != 11)
	{
		trans_date_error_type = WRONG_DATE;
	}
	else
	{
		trans_date_error_type = TERMINAL_OK;
		strcpy(termData->transactionDate, transaction);
		terminalptr->transactionDate[10] = '\0';
	}

	return trans_date_error_type;
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	EN_terminalError_t expired_card_error_type = 0;
	uint8_t mm_trans[3] = {0};
	uint8_t yy_trans[3] = {0};
	uint8_t mm_exp[3] = {0};
	uint8_t yy_exp[3] = {0};
	uint16_t mm_trans_number = 0;
	uint16_t yy_trans_number = 0;
	uint16_t mm_exp_number = 0;
	uint16_t yy_exp_number = 0;

	mm_trans[0] = termData->transactionDate[3];
	mm_trans[1] = termData->transactionDate[4];
	mm_trans[2] = '\0';
	mm_trans_number = atoi(mm_trans);

	yy_trans[0] = termData->transactionDate[8];
	yy_trans[1] = termData->transactionDate[9];
	yy_trans[2] = '\0';
	yy_trans_number = atoi(yy_trans);

	mm_exp[0] = cardData->cardExpirationDate[0];
	mm_exp[1] = cardData->cardExpirationDate[1];
	mm_exp[2] = '\0';
	mm_exp_number = atoi(mm_exp);

	yy_exp[0] = cardData->cardExpirationDate[3];
	yy_exp[1] = cardData->cardExpirationDate[4];
	yy_exp[2] = '\0';
	yy_exp_number = atoi(yy_exp);

	if (yy_trans_number > yy_exp_number)
	{
		expired_card_error_type = EXPIRED_CARD;
	}
	else if (yy_trans_number < yy_exp_number)
	{
		expired_card_error_type = TERMINAL_OK;
	}
	else if (yy_trans_number == yy_exp_number)
	{
		if (mm_trans_number <= mm_exp_number)
		{
			expired_card_error_type = TERMINAL_OK;
		}
		else if (mm_trans_number > mm_exp_number)
		{
			expired_card_error_type = EXPIRED_CARD;
		}
	}

	return expired_card_error_type;

}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	EN_terminalError_t trans_amount_error_type = 0; // OK or INVALID_AMOUNT
	float trans_amount = 0.0;

	printf("Enter Transaction Amount : ");
	//printf("\n");
	scanf_s("%f", &trans_amount);

	if (trans_amount <= 0.0)
	{
		trans_amount_error_type = INVALID_AMOUNT;
	}
	else
	{
		trans_amount_error_type = TERMINAL_OK;
		termData->transAmount = trans_amount;
	}
	return trans_amount_error_type;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	EN_terminalError_t below_max_amout_error_type = 0; // OK or EXCEED_MAX_AMOUNT

	if (termData->transAmount > termData->maxTransAmount) 
	{
		below_max_amout_error_type = EXCEED_MAX_AMOUNT;
	}
	else
	{
		below_max_amout_error_type = TERMINAL_OK;
	}
	return below_max_amout_error_type;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
	EN_terminalError_t max_amount_error_type = 0;

	if (maxAmount <= 0.0)
	{
		max_amount_error_type = INVALID_MAX_AMOUNT;
	}
	else
	{
		max_amount_error_type = TERMINAL_OK;
		termData->maxTransAmount = maxAmount;
	}

	return max_amount_error_type;

}


