# Write your MySQL query statement below
SELECT DATE_FORMAT(trans_date, '%Y-%m') as month, country,
COUNT(id) as trans_count,
SUM(state="approved") as approved_count,
SUM(amount) as trans_total_amount,
SUM((state="approved")*amount) as approved_total_amount
FROM Transactions
Group BY month,country;