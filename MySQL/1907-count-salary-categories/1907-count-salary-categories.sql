# Write your MySQL query statement below
SELECT c.category, COUNT(a.account_id) as accounts_count
FROM(
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
)c

LEFT JOIN Accounts a
ON CASE
    WHEN a.income<20000 THEN 'Low Salary'
    WHEN a.income BETWEEN 20000 AND 50000 THEN 'Average Salary'
    ELSE 'High Salary'
   END=c.category
GROUP BY c.category;


