# Write your MySQL query statement below
WITH RankedWeather AS (
    SELECT 
    id, 
    recordDate,
    temperature,
    LAG(temperature) OVER (ORDER BY recordDate) AS prev_temp,
    LAG(recordDate) OVER (ORDER BY recordDate) AS prev_date
    FROM Weather
)
SELECT id
FROM RankedWeather
WHERE temperature > prev_temp
   AND DATEDIFF(recordDate, prev_Date) = 1;