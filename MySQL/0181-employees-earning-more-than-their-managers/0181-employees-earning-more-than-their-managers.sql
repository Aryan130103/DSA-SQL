# Write your MySQL query statement below
SELECT e.name as Employee 
FROM employee e
INNER JOIN employee m ON e.managerID = m.id
WHERE e.salary > m.salary