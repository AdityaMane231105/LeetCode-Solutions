WITH filtered_stadium AS (
    SELECT 
        id, 
        visit_date, 
        people,
        id - ROW_NUMBER() OVER (ORDER BY id) AS id_group
    FROM Stadium
    WHERE people >= 100
),
group_counts AS (
    SELECT 
        id, 
        visit_date, 
        people,
        COUNT(*) OVER (PARTITION BY id_group) AS group_size
    FROM filtered_stadium
)
SELECT id, visit_date, people
FROM group_counts
WHERE group_size >= 3
ORDER BY visit_date ASC;
