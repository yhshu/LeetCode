# Write your MySQL query statement below
SELECT employee.Name AS Employee
FROM Employee AS employee
WHERE employee.Salary > (
  SELECT Salary
  FROM Employee AS manager
  WHERE Id = employee.ManagerId
)