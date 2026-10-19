# Write your MySQL query statement below
SELECT e.name, j.bonus
FROM Employee e
LEFT JOIN Bonus j ON e.empId = j.empId
WHERE j.bonus < 1000 OR j.bonus IS NULL;