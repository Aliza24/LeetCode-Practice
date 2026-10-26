# Write your MySQL query statement below
SELECT 
    p.product_name, 
    o.unit
FROM (
    SELECT 
        product_id, 
        SUM(unit) AS unit
    FROM Orders
    WHERE order_date >= '2020-02-01' AND order_date <= '2020-02-29'
    GROUP BY product_id
    HAVING SUM(unit) >= 100
) o
INNER JOIN Products p 
    ON o.product_id = p.product_id;