--2.Creating a database
CREATE DATABASE Faculty;


--3.Creating a table 
CREATE TABLE IF NOT EXISTS Students(
    id SERIAL,
    firstname VARCHAR(70),
    lastname VARCHAR(70),
    isActive INT,
    email VARCHAR(70)
);



--4. adding a new integer column Gender 
ALTER TABLE Students ADD COLUMN Gender INT;


--5. changing a type of the column 
ALTER TABLE Students ALTER COLUMN isActive TYPE boolean
USING isActive::boolean;


--6. setting the default value 0 to column gender 
ALTER TABLE Students ALTER COLUMN gender SET DEFAULT 0;


--7. removing the default value of the gender 
ALTER TABLE Students ALTER COLUMN gender DROP DEFAULT;


--8. adding a primary key constraint the id column
ALTER TABLE Students ADD CONSTRAINT students_pk PRIMARY KEY(id);


--9. setting the default value to the email column 
ALTER TABLE Students ALTER COLUMN email SET DEFAULT 'abc@gmail.com';

--10. deleting the table
DROP TABLE Students;

--11. deleting the database
DROP DATABASE Faculty;

