#--SHOW TABLES;
#--SHOW DATABASES;
DROP DATABASE Library;

#--0. Creating the Database
CREATE DATABASE Library;
USE Library;

#--1. Create the table publisher
CREATE TABLE Publisher (`PID` INT PRIMARY KEY,
     `Name` VARCHAR(100),
     `Country` VARCHAR(100));

#--2. Inserting the values
INSERT INTO Publisher VALUES (101, 'Packt Books', 'US');
INSERT INTO Publisher VALUES (201, 'Penguin', 'UK');
INSERT INTO Publisher VALUES (301, 'S Chand', 'IN');
INSERT INTO Publisher VALUES (401, 'Kitaab', 'SG');
SELECT * FROM Publisher;

#--3. Creating the table Book
CREATE TABLE Book (
     `BID` INT,
     `Title` VARCHAR(100),
     `Author` VARCHAR(40),
     `Price` FLOAT,
     `Pages` INT,
     `Genre` VARCHAR(30),
	`PubID` INT,
	FOREIGN KEY (`PubID`) REFERENCES Publisher (`PID`));

#--4. Inserting the values
INSERT INTO Book VALUES (111, 'The Lost Symbol', 'Dan Brown', 500, 600,  'Fiction', 201);
INSERT INTO Book VALUES (121, 'Vedic Maths', 'Ravi Vakil', 243, 300,  'Text Book', 301);
INSERT INTO Book VALUES (131, 'Walking from east to west', 'Ravi Zacharias', 220.45, 240, 'Biography', 201);
INSERT INTO Book VALUES (152, 'The Time Machine', 'H.G. Wells', 245, 120.45, 'Novel', 301);
SELECT * FROM Book;

#--5. Change id of book whose author is H.G. Wells ...
UPDATE Book
SET `BID` = 131
WHERE (`Author` LIKE '%Wells'
AND `Genre` = 'Novel'
AND `PubID` = (
SELECT `PID`
FROM Publisher
WHERE `Name` LIKE 'Pen%'));

#--6. Get BID, Title, Genre of the book...
SELECT `BID`, `Title`, `Genre`
FROM Book
WHERE `Price` = (
SELECT MIN(`Price`)
FROM Book);

#--7. Get Book details with price greater than or equal to...
SELECT *
FROM Book
WHERE `Price` >= (
SELECT `Price`
FROM Book
WHERE `Genre` LIKE 'Novel');

#--8. Get details of the book with pages...
SELECT *
FROM Book
WHERE `Pages` > 300;

#--9. Retrive the details of the publisher, having at least...
SELECT *
FROM Publisher
WHERE `PID` IN (
SELECT `PubID`
FROM Book);

#--10. Retrive the details of the publisher, having no...
SELECT *
FROM Publisher P
WHERE NOT EXISTS (
SELECT `PubID`
FROM Book B
WHERE B.`PubID` = P.`PID`);

#--11. Delete the details of the book which has an publisherID which ...
DELETE FROM Book
WHERE `PubID` = (
SELECT `PID`
FROM Publisher
WHERE `Name` LIKE 'Pen%');
