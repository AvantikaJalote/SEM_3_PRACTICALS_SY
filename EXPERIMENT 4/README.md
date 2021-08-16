### Concept to be implemented: Array of objects and passing them to the member function as arguments.

### PROBLEM STATEMENT 1:
Electricity board wants to generate the monthly electricity bills for their consumers based on electricity units consumed. They apply following conditions to calculate the bill as per type of the consumer. 
1.	If Consumer type is “Commercial” then 5 Rs. per unit till first 200 units, after that 10 Rs. per unit for remaining units.  
2.	If Consumer type is “Non-commercial” then 3 Rs. per unit till first 100 units, after that 5 Rs. per unit for remaining units. 
 
Following data members are used as consumer information. 
1.	Consumer name (50 characters)
2.	Consumer number (long int, - 6 digits)
3.	Consumer type (15 characters)
4.	Current Meter Reading (long int)
5.	Last Meter Reading (long int)
6.	Bill month (character 10)
7.	Amount to pay

Following member functions will be used to perform this task
1.	readData() – will read the data for all the consumers
2.	calculateBill() – will calculate bill with conditions mentioned above
3.	printBill() – will display the consumer information with amount

Write main () function to implement the class and perform the operation.


OUTPUT:

![2021-08-16 (2)](https://user-images.githubusercontent.com/87412265/129568125-5f261e82-4b32-412c-aa48-bef3a149f172.png)

### PROBLEM STATEMENT 2:
Cricket control board would like to generate the list of all-rounder players for the selection in the cricket team based on following conditions.
1.	Batting average should be more than 30
2.	Bowling average should be below 25  

Following data members are used as player’s information. 
1.	Name of the player (40 characters)
2.	Name of the region (20 characters)
3.	Batting average (float) 
4.	Bowling average (float)

Following member functions will be used to perform this task
1.	readData() – will read the data all the players
2.	generateList() – will prepare the list of common players whose batting average > 30 and bowling average < 25. 
3.	sortList() or other function()– will sort the list as per batting and bowling average separately 
4.	displayList() – will display both the lists of the players 

Write main () function to implement the class and perform the operation.


OUTPUT:

![2021-08-16 (4)](https://user-images.githubusercontent.com/87412265/129569085-ca6d3069-ccfd-4512-a020-3488434f09a7.png)

