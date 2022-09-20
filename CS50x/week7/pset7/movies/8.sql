SELECT name FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id WHERE title LIKE "toy story";
-- Only giving 4 people for some reason, and LAURIE METCALF among others won't show up all the time for some reason
-- Laurie metcalf doesn't have TOY STORY id to her credit at least
-- Neither does Wallace shawn, wtf
-- I don't see a reason why this would fail a test at the moment, so I'll let it go. Seems more like a mistake in the database