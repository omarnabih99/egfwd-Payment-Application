# Payment-Application
C project in Embedded Systems Professional Track provided by Udacity and EGY FWD
• Payment systems are now available everywhere and everyone interacts with these systems every day.
• I implemented the SALE transaction only by simulating the card, terminal(ATM), and server using the C programming language.
• Card Module is responsible for storing the card data which is Card Holder Name, Primary Account Number, and Card Expiry Date.
• Terminal (ATM) Module is responsible for user interfacing. The module stores the transaction date and checks whether the card is expired or valid. Also, it stores the transaction amount and checks if it exceeds the max limit allowed for the ATM.
• Server Module is responsible for authentication and account verification. It checks if the account is found within the server database if the account state whether running or blocked and if the account has a sufficient amount to withdraw or not.
