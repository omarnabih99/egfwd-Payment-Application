# Payment-Application
C project in Embedded Systems Professional Track provided by `Udacity` and `egfwd`. The project is developed using `Microsoft Visual Studio`.

## System Description
-Payment systems are now available everywhere and everyone interacts with these systems every day.

-I implemented the SALE transaction only by simulating the card, terminal(ATM), and server using the `C programming language`.

-Card Module is responsible for storing the card data which is Card Holder Name, Primary Account Number, and Card Expiry Date.

-Terminal (ATM) Module is responsible for user interfacing. The module stores the transaction date and checks whether the card is expired or valid. Also, it stores the transaction amount and checks if it exceeds the max limit allowed for the ATM.

-Server Module is responsible for authentication and account verification. It checks if the account is found within the server database if the account state whether running or blocked and if the account has a sufficient amount to withdraw or not.

![Screenshot 2022-11-04 210823](https://user-images.githubusercontent.com/70335125/200056073-aca21402-c805-488b-91a7-20d8cb3f3099.png)


## System Constraints
### Card Module 
-Card Holder Name must be 20 characters  minimum  and 24 characters maximum .

-Card Expiry Date must be in form MM/YY.

-Primary Account Number must be 16 characters minimum and 19 characters maximum.

### Terminal Module
-Transaction Date must be in form DD/MM/YYYY.

-Transaction Amount must be a positive non-zero value.

-Terminal Max Amount must be set as an initialization for the Terminal.

### Server Module
No constraints on input data.

## File Structue
-Modular Programming is applied in the project

-The image below shows the project file structure.

![Screenshot 2022-09-19 052032](https://user-images.githubusercontent.com/70335125/200058644-362c5da4-4539-4cdc-af82-5c70c283d927.png)
