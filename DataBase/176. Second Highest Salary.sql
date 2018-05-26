# Write your MySQL query statement below
SELECT max(Salary) SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT max(Salary)
                FROM Employee)