DROP DATABASE Company;

#--1. Creating the Database
CREATE DATABASE Company;
USE Company;

#--2. Creating the table
CREATE TABLE Employee(
	`EID` INT PRIMARY KEY,
	`Name` VARCHAR(30),
	`Salary` INT,	#--If Check() is given here then insert fails that defies the same.
	`Dept` VARCHAR(30),
	`City` VARCHAR(30),
	`Phone` BIGINT NOT NULL,
	`Email` VARCHAR(20));

#--3. Inserting the values
INSERT INTO Employee VALUES (1, 'ABC', 2000, 'Physics', 'Palakkad', 9876543210, 'abc@123.com');
INSERT INTO Employee VALUES (2, 'DEF', 10000, 'Chemistry', 'Thrivanantapuram', 9877543210, 'def@123.com');
INSERT INTO Employee VALUES (3, 'GHI', 6000, 'Biology', 'Kannur', 9876543330, 'abc@123.com'); #--not unique change here
INSERT INTO Employee VALUES (4, 'IJK', 17000, 'Maths', 'Ernakulam', 9236543210, 'jkl@123.com');
INSERT INTO Employee VALUES (5, 'LMN', 8000,'English', 'Thrissur', 9876589210, 'mno@123.com');

SELECT * FROM Employee;

#--4. Change the structure of employee table to add the constrain unique Email Id
ALTER TABLE Employee
ADD CONSTRAINT UniqueEmail
UNIQUE (`Email`);	#--Produces error if email not unique; DESC Employee;

#--5. Create table EmpSalary which contains foreign key which refer from table Employee
CREATE TABLE EmpSalary (
	`SID` INT,
	`BP` INT, #--Basic Pay
	`DA` INT,
	`PF` INT,
	FOREIGN KEY (`SID`) REFERENCES Employee (`EID`));
INSERT INTO EmpSalary VALUES (5, 223, 332, 534);
INSERT INTO EmpSalary VALUES (1, 210, 430, 570);
INSERT INTO EmpSalary VALUES (3, 293, 313, 514);

SELECT * FROM EmpSalary;

#--6. Add a constraint that checks the salary if it's between 5000 AND 10000
ALTER TABLE Employee
ADD CONSTRAINT SalaryLimit
CHECK (`Salary` BETWEEN 5000 AND 10000);	#--Adds constraint with error if table already defies it

#--7. Display ID, Name, Dept, Phone where Salary in Employee is between 5000 & 10000 and ElmpoyeeID matches SalaryID
SELECT E.`EID`, E.`Name`, E.`Dept`, S.`BP`
FROM Employee E, EmpSalary S
WHERE (E.`Salary` BETWEEN 5000 AND 10000) AND (S.`SID` = E.`EID`);
