/* DML-Data Manipulation Language(SELECT,INSERT,UPDATE, DELETE). DML statements are SQL statements that manipulate data.
SELECT-is used to query data from one or more tables.
INSERT INTO-is used to add new rows to a table.
UPDATE-is used to modify existing rows in a table.
DELETE-removes rows from a table based on a condition. */

--2.Creating a database
CREATE DATABASE Faculty;

--3.Creating a table
CREATE TABLE students(
    id SERIAL PRIMARY KEY,
    name VARCHAR(20),
    lastname VARCHAR(20),
    gender VARCHAR(10), 
    age INT
);

--4.Inserting one row into the table students for the column name and lastname.
INSERT INTO students(name,lastname)
VALUES('Jackie', 'Chan');

--5.Inserting a new row into the students table with age equals to NULL.
INSERT INTO students(name,lastname,gender,age)
VALUES('Jude','Bellingham','male',NULL);

--6.Inserting 3 rows by a single insert statement.
INSERT INTO students(name,lastname,gender,age)
VALUES('Angelina','Jolie','female',50),
      ('Denis','Ten','male',25),
      ('Andrew','Garfield','male',42);

--7.Setting the default value of the column age to 20.
ALTER TABLE students ALTER COLUMN age SET DEFAULT 20;

--8.Inserting default value to the age column for a row of students table.
INSERT INTO students(name,surname,gender,age)
VALUES('Tom','Holland','male',DEFAULT);

--9.Creating duplicate of students table named teachers with all structure using the LIKE keyword.
CREATE TABLE teachers (LIKE students INCLUDING ALL);

--10.Inserting all rows from students table to teachers table.
INSERT INTO teachers SELECT * FROM students;

--11.Changing the gender of students to 0 if it equals NULL. (Use WHERE clause and IS NULL operator)
UPDATE students SET gender=0 WHERE gender IS NULL;

--12.Changing age of students to 20 if it equals NULL
UPDATE students SET age=20 WHERE age IS NULL;

--13.Writing an SQL statement to increase the age of each student by 2. Statement should return name and updated age column with update_age.
UPDATE students SET age=age+2 RETURNING name, age AS update_age;

--14.Removing all rows from students table who are under age 20
DELETE FROM students WHERE age<20;

--15.Removing all rows from teachers table if id exists in students table. Statement should return all deleted data.
DELETE FROM teachers WHERE id IN (SELECT id FROM students) RETURNING *;

--16.Remove all rows from the students table. Statement should return all deleted data.
DELETE FROM students RETURNING *;


