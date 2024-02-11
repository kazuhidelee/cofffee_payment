# Coffee Payment Algorithm
<img width="477" alt="Screenshot 2024-02-10 at 12 11 19 AM" src="https://github.com/kazuhidelee/cofffee_payment/assets/122251831/29b93c5f-a839-4ce9-8f49-d9be398a947f">
<br>Having a hard time deciding who's turn is it to pay for coffee? Try this algorithm ;)
<br>Given an array of employees and their information, the algorithm will help you decide which employee should pay for coffee.

## Idea
When we are deciding who should pay for the coffe, what kind of things do we usually consider? Personally, I would first consider the number of times they have already paid for coffee since it would be fair for the person who have never paid or paid less times to pay for coffee. Also, we would consider how much money did each person cost, and I would likely pick the person who's coffee costs the most since it will cost them less money to pay for the whole group than other people. Hence, I designed my algorithm accordingly. 

## How to run the program
1. Run the executable
2. Specify how many employees are getting coffee (7 in this scenario but the program can take more employees)
3. Enter the employee's information one by one in the following format:
   > [Name] [Favorite Drink] [Drink's price] [number of times paid for coffee] (seperate each item with a white space)
   
The program will return output after entering all necessary information
<br>
<br>Alternativelly, we can also use a textfile to enter the information by using the command ```./main.exe < [TEXTFILE] ```:
<br> i.e)
<img width="301" alt="Screenshot 2024-02-10 at 12 21 19 AM" src="https://github.com/kazuhidelee/cofffee_payment/assets/122251831/9cc4d9c3-fa79-455e-bb75-f0b272b0aebe">
 <br>```./main.exe < test1.txt ```
<br>
<br>You can also activate optional command line flags:
<br>```./main.exe -h ```: program will print out a help message to inform users about the program usage
<br>```./main.exe -s ```: program will print out specfic statistics/priority calculated for each employee

## Assumptions
- The program will assume that the number of employees provided by user is accurate
- The number of times an employee paid for coffee is a positive integer
- The input format is correct 

## How do the program decide who to pay
The program takes 'number of times the employee have paid for coffee' and 'the cost of their favorite coffee' as input and calculate their priority in paying the coffee based on those parameters. The more expensive the employee's favorite coffee is, the higher priority the program will put them in. However, if they have already paid for coffee in the past, the program will put them in a lower priority so everyone can take turn paying. 
