#--DROP DATABASE Sales;

#--1. Creating the Database
CREATE DATABASE Sales;
USE Sales;

#--2. Creating the table
CREATE TABLE Customer (
	`C Name` VARCHAR(40),
	`C No` INT,
	`C City` VARCHAR(40),
	`S No` INT,
	`S City` VARCHAR(40),
	`C Rating` FLOAT);

#--3. Inserting the values
INSERT INTO Customer VALUES ('ABC', 2, 'Thrissur', 3, 'Palakkad', 6);
INSERT INTO Customer VALUES ('DEF', 4, 'Kannur', 5, 'Thrivanantapuram', 2);
INSERT INTO Customer VALUES ('GHI', 6, 'Ernakulam', 7, 'Kannur', 7);
INSERT INTO Customer VALUES ('IJK', 8, 'Kozikode', 9, 'Ernakulam', 5);
INSERT INTO Customer VALUES ('LMN', 10,'Thrivanantapuram', 11, 'Thrissur', 8);

#--4. Display only those customers whose city is thrissur
SELECT *
FROM Customer
WHERE `C City` = 'Thrissur';

#--5. Delete the details of those customers whose rating comes below 3
DELETE FROM Customer
WHERE `C Rating` < 3;

#--6. Select customer name, number and city
SELECT `C Name`, `C No`, `C City`
FROM Customer;

#--7. Update Table customer to set the rating of sales man 4 who are woring in the city thrissur.
UPDATE Customer
SET `C Rating` = 4
WHERE `S City` = 'Thrissur';

SELECT * FROM Customer;
