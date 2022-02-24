SELECT title FROM movies, stars, people, ratings
ON movies.id = ratings.movie_id
AND movies.id = stars.movie_id
AND stars.person_id = people.id
WHERE people.name LIKE "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;

-- list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
