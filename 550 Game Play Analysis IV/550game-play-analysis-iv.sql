WITH FirstLogin AS (
    -- Step 1: Find the first login date for each player
    SELECT 
        player_id, 
        MIN(event_date) AS first_date
    FROM 
        Activity
    GROUP BY 
        player_id
)

-- Step 2 & 3: Join and calculate the fraction
SELECT 
    ROUND(
        COUNT(DISTINCT a.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 
        2
    ) AS fraction
FROM 
    FirstLogin f
INNER JOIN 
    Activity a 
ON 
    f.player_id = a.player_id 
    AND a.event_date = DATE_ADD(f.first_date, INTERVAL 1 DAY);
