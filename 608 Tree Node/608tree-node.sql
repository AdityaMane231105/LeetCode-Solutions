# Write your MySQL query statement below
SELECT 
    id,
    CASE 
        WHEN p_id IS NULL THEN 'Root'
        WHEN id IN (SELECT DISTINCT p_id FROM Tree WHERE p_id IS NOT NULL) THEN 'Inner'
        ELSE 'Leaf'
    -- Alias the case statement output as 'type'
    END AS type
FROM 
    Tree;
