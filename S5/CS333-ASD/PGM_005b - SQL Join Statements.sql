DROP DATABASE Library;

CREATE DATABASE Library;
USE Library;

#--i. Creating Table Publisher
CREATE TABLE Publisher (
	`PID`		INT PRIMARY KEY,
	`Name`		VARCHAR(100),
	`Country`	VARCHAR(100));

#--ii. Inserting the values
INSERT INTO Publisher VALUES (247, 'Macmillan', 'UK');
INSERT INTO Publisher VALUES (122, 'Penguin', 'US');
INSERT INTO Publisher VALUES (341, 'Westland', 'IN');
INSERT INTO Publisher VALUES (121, 'Kitaab', 'SG');

#--iii. Creating table Book
CREATE TABLE Book (
	`BID`		INT,
	`Title`		VARCHAR(100),
	`Author`	VARCHAR(100),
	`Pages`		INT,
	`Price`		FLOAT,
	`Genre`		VARCHAR(30),
	`ISBN`		BIGINT,
	`PubID`		INT,
	FOREIGN KEY (`PubID`) REFERENCES Publisher (`PID`));

#--iv. Inserting the values
INSERT INTO Book VALUES (101, 'The Lost Symbol', 'Dan Brown', 500, 520, 'Fiction', 7953652407, 247);
INSERT INTO Book VALUES (201, 'The Great Zoo of China', 'Mathew Reilly', 312, 400, 'Fantasy', 6320694695, 341);
INSERT INTO Book VALUES (301, 'Walking from east to west', 'Ravi Zacharias', 240, 220, 'Biography', 5938616577, 247);
INSERT INTO Book VALUES (401, 'The Time Machine', 'H.G. Wells', 245, 120, 'Novel', 3026440037, 121);
INSERT INTO Book VALUES (501, 'Flamingo', 'NCERT', 235, 345, 'Text Book', 5199744426, 121);

SELECT `Title`, `Author`
FROM Book B
INNER JOIN Publisher P
ON B.`PubID` = P.`PID`
ORDER BY B.`Title`;

SELECT `Title`, `Genre`
FROM Book B
LEFT JOIN Publisher P
ON B.`PubID` = P.`PID`;

SELECT *
FROM Book
JOIN Publisher;
