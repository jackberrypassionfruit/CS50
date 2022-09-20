SELECT title FROM movies 
WHERE movies.id IN

(SELECT movies.id FROM movies, stars, people
ON movies.id = stars.movie_id
AND stars.person_id = people.id
WHERE people.name LIKE "%Johnny Depp%")

AND movies.id IN

(SELECT movies.id FROM movies, stars, people
ON movies.id = stars.movie_id
AND stars.person_id = people.id
WHERE people.name LIKE "%Helena Bonham Carter%");

-- list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred
