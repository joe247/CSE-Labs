#--SHOW TABLES;
#--SHOW DATABASES;
#--DROP DATABASE mydb;

#--1. Creating the Database
CREATE DATABASE mydb;
USE mydb;

#--2. Creating the table
CREATE TABLE Book (`ID` INT PRIMARY KEY AUTO_INCREMENT,
     `Title` VARCHAR(100),
     `Author` VARCHAR(40),
     `Pages` INT,
     `Price` FLOAT,
     `GENRE` VARCHAR(30));

#--3. Inserting the values
INSERT INTO Book VALUES (1, "The Lost Symbol", "Dan Brown", 500, 524.75, "Fiction");
INSERT INTO Book VALUES (2, "Flamingo", "NCERT", 235, 345.55, "Text Book");
INSERT INTO Book VALUES (3, "The Great Zoo of China", "Mathew Reilly", 312, 401.75, "Fantasy");
INSERT INTO Book VALUES (4, "Walking from east to west", "Ravi Zacharias", 240, 220.45, "Biography");
INSERT INTO Book VALUES (5, "The Time Machine", "H.G Wells", 245, 120.45, "Novel");
INSERT INTO Book VALUES (6, "Flamingo", "NCERT", 235, 345.55, "Text Book");

#-- 4. Display the table structure:
DESC Book;

#--5. Rename table
ALTER TABLE Book CHANGE `Title` `Book Title` VARCHAR(100);

#--6. Select
SELECT * FROM Book;

#--7. Drop Column
ALTER TABLE Book DROP COLUMN Author;

#--8. Add Column
ALTER TABLE Book ADD COLUMN Year INT;
UPDATE Book SET Year = 1987 WHERE ID = 1;
UPDATE Book SET `Year` = 2001 WHERE ID = 2;
UPDATE Book SET Year = 1997 WHERE ID = 3;
UPDATE Book SET Year = 1983 WHERE ID = 4;
UPDATE Book SET `Year` = 1974 WHERE ID = 5;
UPDATE Book SET Year = 2001 WHERE ID = 6;

/*
UPDATE Book
SET `Year` = CASE `ID`
                WHEN 1 THEN 1987
                WHEN 2 THEN 2001
                WHEN 3 THEN 1997
                WHEN 4 THEN 1983
                WHEN 5 THEN 1974
                WHEN 6 THEN 2001
           END
WHERE `ID` IN (1,2,3,4,5,6);
*/

#--8. order by the price
SELECT * FROM Book ORDER BY Price;

#--10. under such catogery
SELECT * FROM Book WHERE GENRE = "Text Book" OR GENRE = "Novel";

#--11. price b/w 200 & 400
SELECT * FROM Book WHERE Price BETWEEN 200 AND 400;

#--12. with distinct title
SELECT DISTINCT `Book Title` FROM Book;

SELECT * FROM Book;
