/*
Aim
===
	To familiarize with SQL Triggers.
	
Problem 1:
----------
Write a trigger which executes when we insert the values into the customer table and display the particulars of each item with it's total cost in separate tables. Assume `customer` relation has attributes (id, item, cost, quantity) and new table `bill` contains attributes (id, item, total_cost)

Problem 2:
----------
The HR manager has decided to raise the salary of all the employees in the dept. 'IT' by 20%. When ever any such raise is given to an employee, a record fo the same is maintained in the employee_raise_table. It includes emp_id, date in which the raise was made, present salary and raised amount.
Write a shared procedure to update the salary of each employee & insert a record in the employee_raise_table.
*/

Solution 1:
-----------

CREATE DATABASE Random;
USE Random;

CREATE TABLE Customer(
	`ID`		INT,
	`Item` 		VARCHAR(40),
	`Cost`		INT,
	`Quantity`	INT
);

CREATE TABLE Bill(
	`c_id`		INT,
	`item_bought`	VARCHAR(30),
	`total_cost`	INT
);

DELIMITER $$ ;

CREATE TRIGGER def_trig
AFTER INSERT
ON Customer FOR EACH ROW
BEGIN
    INSERT INTO Bill (`c_id`, `item_bought`, `total_cost`)
    VALUES (NEW.ID, NEW.Item, NEW.Cost*NEW.Quantity);
END $$

CREATE PROCEDURE invoke_trig ()
BEGIN
	INSERT INTO Customer (`ID`, `Item`, `Cost`, `Quantity`)
	VALUES
		(101, 'iPhone X', 30000, 3),
		(301, 'OnePlus 7', 35000, 4),
		(301, 'Pixel 4', 20000, 2),
		(401, 'Samsung A10', 40000, 5);
END $$
DELIMITER ; $$

CALL invoke_trig();
SELECT * FROM Customer;
SELECT * FROM Bill;

DROP DATABASE Random;

Solution 2:
-----------
CREATE DATABASE Random;
USE Random;

CREATE TABLE Employee(
	`ID`		INT,
	`Name` 		VARCHAR(40),
	`Salary`	INT,
	`Date`		DATE,
	`Dept`		VARCHAR(10)
);

INSERT INTO Employee (`ID`, `Name`, `Salary`, `Date`, `Dept`)
VALUES
	(101, 'Smith', 30000,'2019-10-10', 'HR'),
	(201, 'George', 35000,'2019-10-10', 'IT'),
	(301, 'Philip', 20000,'2019-10-10', 'RD'),
	(401, 'Jasper', 40000,'2019-10-10', 'IT'),
	(501, 'Ronald', 25000,'2019-10-10', 'FN');

SELECT * FROM Employee;

CREATE TABLE employee_raise_table(
	`emp_id`		INT,
	`date_of_raise`		DATE,
	`present_salary`	INT
);

DELIMITER $$ ;

CREATE TRIGGER def_trig
AFTER UPDATE
ON Employee FOR EACH ROW
BEGIN
    INSERT INTO employee_raise_table (`emp_id`, `date_of_raise`, `present_salary`)
    VALUES (OLD.ID, NEW.Date, NEW.Salary);
END $$

CREATE PROCEDURE invoke_trig (IN dp VARCHAR(10))
BEGIN
	UPDATE Employee
	SET `Salary` = `Salary` + (`Salary`*0.2), `Date` = '2019-11-10'
	WHERE `Dept` = dp;
END $$
DELIMITER ; $$

CALL invoke_trig('IT');
SELECT * FROM Employee;
SELECT * FROM employee_raise_table;

DROP DATABASE Random;
