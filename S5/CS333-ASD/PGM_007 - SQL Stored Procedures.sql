DROP DATABASE Library;

CREATE DATABASE Library;
USE Library;
CREATE TABLE Book (`BID` INT PRIMARY KEY AUTO_INCREMENT,
     `Title` VARCHAR(100),
     `Author` VARCHAR(40),
     `Pages` INT,
     `Price` FLOAT,
     `GENRE` VARCHAR(30));
INSERT INTO Book VALUES (101, "The Lost Symbol", "Dan Brown", 500, 524.75, "Fiction");
INSERT INTO Book VALUES (201, "Flamingo", "NCERT", 235, 345.55, "Text Book");
INSERT INTO Book VALUES (301, "The Great Zoo of China", "Mathew Reilly", 312, 401.75, "Fantasy");
INSERT INTO Book VALUES (401, "Walking from east to west", "Ravi Zacharias", 240, 220.45, "Biography");
INSERT INTO Book VALUES (501, "The Time Machine", "H.G Wells", 245, 120.45, "Novel");
INSERT INTO Book VALUES (601, "Flamingo", "NCERT", 235, 345.55, "Text Book");

DELIMITER $$ ;

CREATE PROCEDURE getBooks()
BEGIN
  SELECT * FROM Book;
END $$

CREATE PROCEDURE getBookTitle(IN price INT)
BEGIN
	SELECT `Title`
	FROM Book B
	WHERE B.`Price` >= price;
END $$

CREATE PROCEDURE setType(IN bid INT, OUT type VARCHAR(30))
BEGIN
	SELECT B.`Genre`
	INTO type
	FROM Book B
	WHERE B.`BID` = bid;
END $$

DELIMITER ; $$

CALL getBooks();
CALL getBookTitle(400);
CALL setType(401, @type);
SELECT @type;

DROP DATABASE Market;
CREATE DATABASE Market;
USE Market;

CREATE TABLE Customer (
	`CID`		INT,
	`Name`		VARCHAR(40),
	`Credit`	INT);

INSERT INTO Customer VALUES (101, 'ABC', 6000);
INSERT INTO Customer VALUES (102, 'DEF', 40000);
INSERT INTO Customer VALUES (103, 'GHI', 10000);
INSERT INTO Customer VALUES (104, 'JKL', 60000);

DELIMITER ## ;
CREATE PROCEDURE setStatus(IN id INT, IN val INT, OUT status VARCHAR(40))
BEGIN
	SELECT `Credit`
	INTO val
	FROM Customer
	WHERE `CID` = id;
	IF (val >= 50000) THEN
		SET status = 'Platinum';
	ELSEIF (val >= 10000 AND val < 50000) THEN
		SET status = 'Gold';
	ELSEIF (val < 10000) THEN
		SET status = 'Silver';
	END IF;
END ##

DELIMITER ; ##

CALL setStatus(102, 40000, @status);
SELECT @status;
