
(
    SELECT u.name AS results
    FROM Users u
    JOIN MovieRating m
        ON u.user_id = m.user_id
    GROUP BY u.user_id
    ORDER BY COUNT(*) DESC, u.name ASC
    LIMIT 1
)

UNION ALL

(
    SELECT m1.title AS results
    FROM Movies m1
    JOIN MovieRating m2
        ON m1.movie_id = m2.movie_id
    WHERE m2.created_at >= '2020-02-01'
      AND m2.created_at < '2020-03-01'
    GROUP BY m1.movie_id
    ORDER BY AVG(m2.rating) DESC, m1.title ASC
    LIMIT 1
);
