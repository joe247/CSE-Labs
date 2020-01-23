DROP DATABASE Market;
CREATE DATABASE Market;
USE Market;

#--1. Creating the table
CREATE TABLE Product(
	`Product No` INT,
	`Product Name` VARCHAR(30),
	`Quantity` INT,
	`Selling Price` FLOAT,
	`Actual Price` FLOAT);

INSERT INTO Product VALUES (1, 'Samsung Note 10', 3, 86000, `Selling Price`*`Quantity`);
INSERT INTO Product VALUES (2, 'Zenfone MaxPro M2', 5, 11500, `Selling Price`*`Quantity`);
INSERT INTO Product VALUES (3, 'iPhone X', 2, 70000, `Selling Price`*`Quantity`);
INSERT INTO Product VALUES (4, 'Pixel 3', 4, 32500, `Selling Price`*`Quantity`);
INSERT INTO Product VALUES (5, 'Honor P20 View', 3, 75000, `Selling Price`*`Quantity`);

SELECT * FROM Product;

#--2. Show structure of the table
DESC Product;

#--3. Counting the numbers of Orders Set == Quantity Required
SELECT SUM(`Quantity`)
FROM Product;

#--4. Calculating the average of the Price
SELECT AVG(`Selling Price`)
FROM Product;

#--5. Selecting the minimum of Price
SELECT MIN(`Selling Price`)
FROM Product;

#--6. Determine Minimum & Maximum of Actual Price
SELECT MIN(`Actual Price`) AS 'Min Price', MAX(`Actual Price`) AS 'Max Price'
FROM Product;

#--7. Count of Products Price > 40000
SELECT COUNT(`Product No`)
FROM Product
WHERE `Selling Price` >= 40000;

#--8. Sort by Product name
SELECT *
FROM Product
ORDER BY `Product Name`;

#--9. Retrive Avg Selling Price for the product for which the qty >=3
SELECT AVG(`Selling Price`)
FROM Product
GROUP BY `Quantity`
HAVING `Quantity` >= 3;
