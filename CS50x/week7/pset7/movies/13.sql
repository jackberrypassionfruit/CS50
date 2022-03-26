-- list the names of all people who starred in a movie in which Kevin Bacon also starred.

SELECT movies.id FROM movies, stars, people
ON movies.id = stars.movie_id
AND stars.person_id = people.id
WHERE people.name LIKE "%Kevin Bacon%"
AND people.birth IS 1958;


-- SELECT name FROM people, stars
-- ON people.id = stars.person_id
-- WHERE movies.id IN

-- (SELECT movie_id FROM movies, stars, people
-- ON movies.id = stars.movie_id
-- AND stars.person_id = people.id
-- WHERE people.name LIKE "%Kevin Bacon%");

-- DIDnt finish this one, not sure about this error tbh. Kinda dumb