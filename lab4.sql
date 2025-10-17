--3.Retrieve the first and last names of staff from staff table who are currently active but do not have a picture stored.
SELECT first_name, last_name FROM staff WHERE active=true AND picture IS NULL;

--4.List the titles of all films from the film table with their lengths, but only include films longer than 50 minutes. Sort the results by length from longest to shortest.
SELECT title, length FROM film WHERE length>50 ORDER BY length DESC;

--5.Find all films with a length between 100 and 110 minutes that have a rating of 'G'. The result should be ordered by length in Ascending order.
SELECT title, length, rating  FROM film WHERE length BETWEEN 100 AND 110 AND rating='G' ORDER BY length ASC;

--6.Find the minimum film length for every rating in the film table.
SELECT rating, MIN(length) AS min_length FROM film GROUP BY rating;

--7.Find each unique set of special_features with the total sum of rental rates of all films from the film table that have those features.
SELECT special_features, SUM(rental_rate) AS total_rentel_rate FROM film GROUP BY special_features;

--8.Find the number of films in each rating categoe. Only display the categories that have more than 200 films.
SELECT rating, COUNT(*) AS film_count FROM film GROUP BY rating HAVING COUNT(*)>200;

--9.Find all first names and last names of the actor and staff from actor and staff tables.
SELECT first_name, last_name FROM actor UNION SELECT first_name, last_name FROM staff;

--10.select first name and last name of the actor table that do not exist in staff table.
SELECT first_name, last_name FROM actor EXCEPT SELECT  first_name, last_name FROM staff;

--11.select the intersect of the films with film length greater than 100 and cost_replacement less then 25 from the film table
SELECT * FROM film WHERE length>100 INTERSECT SELECT * FROM film WHERE replacement_cost<25;

--12.select distinct rating system records from the table film.
SELECT DISTINCT rating FROM film;

--13.select the number of films released in each year with the amount greater than 5.
SELECT release_year, COUNT(*) AS film_count FROM film GROUP BY release_year HAVING COUNT(*)>5;

--14.Reduce the value of the third largest replacement cost by 15% from the film table.
UPDATE film SET replacement_cost=replacement_cost * 0.85 
WHERE replacement_cost=(
    SELECT DISTINCT replacement_cost FROM film
    ORDER BY replacement_cost DESC
    OFFSET 2 LIMIT 1
);

--15.Remove films with the length greater than 180 from the film table
DELETE FROM film WHERE length > 180;

--16.Remove all the films from film table which are in Mandarin language returning all.
DELETE FROM film
WHERE language_id = (SELECT language_id FROM language WHERE name = 'Mandarin')
RETURNING *;
