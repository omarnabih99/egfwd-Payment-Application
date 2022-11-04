#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "app.h"

int main() 
{
		appStart();
}

void appStart(void)
{
																		/* card module local variables*/
	EN_cardError_t get_card_holder_name = 0;
	EN_cardError_t get_exp_date = 0;
	EN_cardError_t get_card_PAN = 0;

																	/*terminal module local variables*/
	EN_terminalError_t transaction_date = 0;
	EN_terminalError_t card_expiry = 0;
	EN_terminalError_t transaction_amount = 0;
	EN_terminalError_t max_amount = 0;
	EN_terminalError_t below_max_amount = 0;

																	/* server module local variables */
	EN_transState_t trans_state = 0;


	max_amount = setMaxAmount(terminalptr, 30000.0);
	while (1)
	{
																		/* card module */
		do
		{
			get_card_holder_name = getCardHolderName(cardptr);
		} while (get_card_holder_name != CARD_OK);

		do 
		{
			get_exp_date = getCardExpiryDate(cardptr);
		} while (get_exp_date != CARD_OK);

		do 
		{
			get_card_PAN = getCardPAN(cardptr);
		} while (get_card_PAN != CARD_OK);

																		  /* terminal module */
		do
		{
			transaction_date = getTransactionDate(terminalptr);
		} while (transaction_date != TERMINAL_OK);

		card_expiry = isCardExpired(cardptr, terminalptr);
		if (card_expiry != TERMINAL_OK)
		{
			printf("Declined : Expired card");
			printf("\n");
			continue;
		}

		do 
		{
			transaction_amount = getTransactionAmount(terminalptr);
		} while (transaction_amount != TERMINAL_OK);

		below_max_amount = isBelowMaxAmount(terminalptr);
		if (below_max_amount != TERMINAL_OK)
		{
			printf("Declined : Amount Exceeding Limit");
			printf("\n");
			continue;
		}

																		/* server module */
		trans_state = recieveTransactionData(transactionsDBptr);
	}

}
