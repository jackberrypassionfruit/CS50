SELECT DISTINCT(name) FROM people JOIN directors ON people.id = directors.person_id JOIN ratings ON directors.movie_id = ratings.movie_id WHERE rating >= 9.0;
-- Gives 2232 people

-- list the names of all people who have directed a movie that received a rating of >= 9.0.