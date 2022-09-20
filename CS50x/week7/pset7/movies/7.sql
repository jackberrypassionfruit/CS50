SELECT title, rating FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE year = 2010 ORDER BY rating DESC, title ASC;
-- Second ORDER BY clause runs when first comparison is equal