/*
Aim: To implement a procedure to calculate the electricity bill for all the customers using SQL cursors.

Problem:
--------
An electricity board charges the following rates to domestic users to discourage large consumption of energy:
    -> for 1st 100 units Rs. 2 per unit
    -> for 101 to 200 units Rs. 2.5 per unit
    -> for 201 to 300 units Rs. 3 per unit
    -> for greater than 300 units Rs. 4 per unit

Use the table customer (cno, cname, previous_reading, current_reading, amount)
*/

Solution
--------
CREATE DATABASE Random;
USE Random;

CREATE TABLE Customer(
    `c_no`              INT,
    `name`              VARCHAR(40),
    `previous_reading`  INT,
    `current_reading`   INT,
    `amount`            INT DEFAULT 0
);

INSERT INTO Customer (`c_no`, `name`, `previous_reading`,`current_reading`)
VALUES
    (101, 'Smith', 90, 120),
    (201, 'George', 30, 250),
    (301, 'Philip', 120, 200),
    (401, 'Jasper', 10,390);

SELECT * FROM Customer;

DELIMITER $$ 
CREATE PROCEDURE e_bill()
BEGIN
    DECLARE flag INT DEFAULT 0;
    DECLARE cno INT;
    DECLARE pr, cr, amt, unt DOUBLE;
    DECLARE curBill
        CURSOR FOR
            SELECT c_no, `previous_reading`, `current_reading`
            FROM Customer;
    DECLARE CONTINUE HANDLER FOR NOT found SET flag = 1;

    OPEN curBill;
    calUnit: LOOP
        FETCH curBill INTO cno, pr, cr;
        IF flag <> 1 THEN
            SET unt = cr-pr;
        ELSE
            LEAVE calUnit;
        END IF;
        IF (unt <= 100) THEN
            SET amt = unt*2;
        ELSEIF (unt >= 101 AND unt <= 200) THEN
            SET amt = unt*2.5;
        ELSEIF (unt > 201 AND unt <= 300) THEN
            SET amt = unt*3;
        ELSEIF (unt > 301) THEN
            SET amt = unt*4;
        END IF;
        UPDATE Customer
        SET `amount`=amt
		WHERE `c_no`=cno;
    END LOOP;
    CLOSE curBill;
END $$
DELIMITER ; 

CALL e_bill();

SELECT * FROM Customer;

DROP DATABASE Random;
