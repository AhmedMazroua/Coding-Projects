--a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.


SELECT title, year FROM movies WHERE title like "%harry potter%" ORDER BY year ASC;