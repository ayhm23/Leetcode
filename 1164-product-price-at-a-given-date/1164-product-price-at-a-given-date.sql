# 1. Get the latest price for products that changed on or before '2019-08-16'
WITH LatestPrices AS (
    SELECT product_id, new_price AS price
    FROM Products
    WHERE (product_id, change_date) IN (
        SELECT product_id, MAX(change_date)
        FROM Products
        WHERE change_date <= '2019-08-16'
        GROUP BY product_id
    )
)

SELECT product_id, price FROM LatestPrices

UNION

# 2. Get products that never had a price change on or before '2019-08-16' (default to 10)
SELECT DISTINCT product_id, 10 AS price
FROM Products
WHERE product_id NOT IN (
    SELECT product_id 
    FROM Products 
    WHERE change_date <= '2019-08-16'
);