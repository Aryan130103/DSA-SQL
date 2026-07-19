# Write your MySQL query statement below
SELECT t.id
FROM Weather y
JOIN Weather t
ON DATEDIFF(t.recordDate,y.recordDate) = 1
WHERE t.temperature>y.temperature;
