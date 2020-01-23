#--1. Display Distinct Publisher ID
SELECT `PID` FROM Publisher
UNION
SELECT DISTINCT `PubID` FROM Book;

#--2. Display Publisher ID
SELECT `PID` FROM Publisher
UNION ALL
SELECT `PubID` FROM Book;

#-- mySQL Does not support MINUS
#--3. Display Details not in...
SELECT `PubID`, `Title`, `Author` FROM Book
MINUS
SELECT `PID`, `Name`, `Country` FROM Publisher;

#--4. Display publisher details...
SELECT * FROM Publisher
INTERSECT Book;
