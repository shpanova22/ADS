--1.
CREATE TABLE users(
       user_id SERIAL PRIMARY KEY,
	   username VARCHAR(100) UNIQUE NOT NULL,
	   age INT NOT NULL CHECK (age>16),
	   country VARCHAR(20)
);
--2.
INSERT INTO users(username, age, country)
VALUES('Johnny Depp', 62, 'USA'),
      ('Angelina Jolie', 50, NULL),
	  ('Jackie Chan', 71, 'China');

SELECT * FROM users;

--3.
ALTER TABLE users ADD COLUMN phone_number CHAR(12)
                  DEFAULT '+77001234567'
				  CHECK(phone_number ~ '^\+[0-9]{11}$');

--4.				  
ALTER TABLE users ADD COLUMN password TEXT
                  CHECK(
                     LENGTH(password)>=8
					 AND password ~ '[a-z]'
					 AND password ~ '[A-Z]'
					 AND password ~ '[0-9]'
					 AND password ~ '[^a-zA-Z0-9]'
				  );
--5.
ALTER TABLE users ALTER COLUMN username DROP NOT NULL;

--6.
SELECT UPPER(username) AS username_uppercase,
       LOWER(country)  AS county_lowercase
FROM users;

--7.
SELECT SUBSTRING(username FROM 1 FOR 3 ) AS first_three_chars FROM users;


--8.
INSERT INTO users(username, age, country)
VALUES(NULL, 22, 'Kazakhstan'),
      (NULL, 18, 'Italy'),
	  ('Cameron Boyce', 25, NULL),
	  ('Adele Laurie', 37, NULL);

--9.
SELECT COALESCE(username, 'no username') AS username_display,
       COALESCE(country, 'no country') AS country_display FROM users;

--10.
SELECT * FROM users WHERE username ILIKE '%s%';

--11.
SELECT FORMAT ('User %s, %s is from  %s', user_id, username, country) AS user_info FROM users;
SELECT 
    FORMAT(
        'User %s, %s is from %s',
        user_id,
        COALESCE(username, 'no username'),
        COALESCE(country, 'no country')
    ) AS user_info
FROM users;

