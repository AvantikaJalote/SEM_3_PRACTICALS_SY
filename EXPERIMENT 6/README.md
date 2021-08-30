### Concept to be implemented: friend function and friend class

### PROBLEM STATEMENT 1:
Examination department of NMIMS wants to develop an application to calculate the results depending on ICA and TEE marks. They accept marks of ICA and TEE from different sources and combine them as internal and external marks out of 100. Therefore, two separate classes as “ICA” and “TEE” with following data members are created. (out of 50 marks for each class)
•	Marks of Math
•	Marks of OPP
•	Marks of SE
•	Marks of DS
Use member functions to input the marks for each class. Identify a concept and write a function that can accept data members of both the classes and calculate the results.  Same function will print the result and total marks subject wise.    

OUTPUT:

![2021-08-30 (10)](https://user-images.githubusercontent.com/87412265/131334494-adf01ffa-fec3-4099-9b94-701f37defd5d.png)


### PROBLEM STATEMENT 2:
Write a program to demonstrate friend class behaviour. Friend class functions will access the data members of the other class.  
A.	Write a class “Employee” to read and print information of an employee with following details: 
•	Name of the employee, 
•	Id of the employee, 
•	Department of the employee
•	monthly salary
B.	Write another class “Sales” that read and print employee details as follows
•	Sales in month, 
•	Incentives acquired 
Calculation of Incentives will be as follows:
1.	10 % of the monthly salary if sales is between 50 to 100 units 
2.	20 % of monthly salary if sales is between 100 and 150 units
3.	30 % of monthly salary if sales is more than 150 units.
Later on company has decided to include performance indicator depending on total sales made in a month as Excellent, Good, Satisfactory or Poor. Add one more function in sales class to assign performance indicators to the employee.
Use following conditions:
•	Sales above 150 – Excellent   
•	Sales between 101 to 150 – Good
•	Sales between 50 to 100 – Satisfactory
•	Sales below 50 - Poor 
Write main () function to implement the friend class and perform the operation.

OUTPUT:

![2021-08-30 (11)](https://user-images.githubusercontent.com/87412265/131335126-f830610e-0cb7-440e-8ffd-421423e2e460.png)

