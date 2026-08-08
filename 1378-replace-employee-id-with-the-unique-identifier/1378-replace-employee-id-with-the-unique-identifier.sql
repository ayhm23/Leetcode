# Write your MySQL query statement below
SELECT unique_id, name
From Employees AS e1
LEFT JOIN EmployeeUNI AS e2 ON e1.id = e2.id;