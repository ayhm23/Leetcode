SELECT w1.id
FROM Weather As w1
JOIN Weather AS w2
on DATEDIFF(w1.recordDate, w2.recordDate) = 1
Where w1.temperature > w2.temperature;