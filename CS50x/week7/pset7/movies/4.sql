-- SELECT title FROM movies WHERE id IN (SELECT movie_id FROM ratings WHERE rating = 10.0);
-- But I want to try doing the same thing with a JOIN command as well
SELECT COUNT(title) FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE rating = 10.0;
-- GOT IT! Interesting that it's in a different order somewhere down the line though