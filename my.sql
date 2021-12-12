-- create db
CREATE DATABASE TEMP_DB

-- delete db
DROP DATABASE TEMP_DB

-- create table
CREATE TABLE Persons (
    PersonID int,
    LastName varchar(255),
    FirstName varchar(255),
    Address varchar(255),
    City varchar(255)
);

-- create table using another table
CREATE TABLE newTable AS
SELECT customername, contactname
FROM customers;

-- delete table
DROP TABLE Persons

-- alter table
-- add column
ALTER TABLE Customers
ADD Email varchar(255);

-- drop column
ALTER TABLE Customers
DROP COLUMN Email;

-- modify column
ALTER TABLE table_name
MODIFY COLUMN column_name datatype;

/*
SQL Constraints
SQL constraints are used to specify rules for the data in a table.

Constraints are used to limit the type of data that can go into a table. This ensures the accuracy and reliability of the data in the table. If there is any violation between the constraint and the data action, the action is aborted.

Constraints can be column level or table level. Column level constraints apply to a column, and table level constraints apply to the whole table.

The following constraints are commonly used in SQL:

NOT NULL - Ensures that a column cannot have a NULL value
UNIQUE - Ensures that all values in a column are different
PRIMARY KEY - A combination of a NOT NULL and UNIQUE. Uniquely identifies each row in a table
FOREIGN KEY - Prevents actions that would destroy links between tables
CHECK - Ensures that the values in a column satisfies a specific condition
DEFAULT - Sets a default value for a column if no value is specified
CREATE INDEX - Used to create and retrieve data from the database very quickly
*/

-- NOT NULL --
CREATE TABLE Persons (
    ID int NOT NULL,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255) NOT NULL,
    Age int
);

ALTER TABLE Persons
MODIFY Age int NOT NULL;

-- UNIQUE -------------------------------------
-- Method 1
CREATE TABLE Persons (
    ID int NOT NULL,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int,
    UNIQUE (ID)
);

ALTER TABLE Persons
ADD UNIQUE (ID);

-- Method 2
CREATE TABLE Persons (
    ID int NOT NULL,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int,
    CONSTRAINT UC_Person UNIQUE (ID,LastName)
);

ALTER TABLE Persons
ADD CONSTRAINT UC_Person UNIQUE (ID,LastName);

-- Drop unique constraint
DROP INDEX index_name ON tbl_name
-- or
ALTER TABLE tbl_name DROP INDEX index_name

-- PRIMARY KEY -------------------------------------
-- Method 1
CREATE TABLE Persons (
    ID int NOT NULL,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int,
    PRIMARY KEY (ID)
);

ALTER TABLE Persons
ADD PRIMARY KEY (ID);

-- Method 2
CREATE TABLE Persons (
    ID int NOT NULL,
    LastName varchar(255) NOT NULL,
    FirstName varchar(255),
    Age int,
    CONSTRAINT PK_Person PRIMARY KEY (ID)
);

ALTER TABLE Persons
ADD CONSTRAINT PK_Person PRIMARY KEY (ID);

-- Drop primary key constraint
ALTER TABLE Persons
DROP PRIMARY KEY;

-------------------
-- create a table
CREATE TABLE census (
  id INTEGER PRIMARY KEY,
  age INTEGER NOT NULL,
  gender TEXT NOT NULL
);
-- insert some values
INSERT INTO census VALUES (1, 23, 'M');
INSERT INTO census VALUES (2, 33, 'F');
INSERT INTO census VALUES (3, 3, 'M');
INSERT INTO census VALUES (4, 43, 'F');
INSERT INTO census VALUES (5, 53, 'M');
INSERT INTO census VALUES (6, 63, 'F');
INSERT INTO census VALUES (7, 73, 'M');
INSERT INTO census VALUES (8, 3, 'F');
INSERT INTO census VALUES (9, 21, 'M');
INSERT INTO census VALUES (10, 23, 'F');
INSERT INTO census VALUES (11, 29, 'M');
INSERT INTO census VALUES (12, 30, 'F');
INSERT INTO census VALUES (13, 5, 'M');
INSERT INTO census VALUES (14, 22, 'F');
INSERT INTO census VALUES (15, 6, 'M');
INSERT INTO census VALUES (16, 67, 'F');
INSERT INTO census VALUES (17, 75, 'M');
INSERT INTO census VALUES (18, 7, 'F');
INSERT INTO census VALUES (19, 35, 'M');
INSERT INTO census VALUES (20, 22, 'F');

-- query to group age and display count and split gender into 2 columns
SELECT
    age_group,
    COUNT(*) as total,
    SUM(CASE gender WHEN 'M' THEN 1 ELSE 0 END) AS Male,
    SUM(CASE gender WHEN 'F' THEN 1 ELSE 0 END) AS Female
FROM (
    SELECT
    CASE 
      WHEN census.age BETWEEN 1 AND 14 THEN 'children'
      WHEN census.age BETWEEN 15 AND 24 THEN 'youth'
      WHEN census.age BETWEEN 25 AND 60 THEN 'adults'
      ELSE 'seniors'
    END as age_group,
    Gender
    FROM census
)
GROUP BY age_group
Order by total desc;