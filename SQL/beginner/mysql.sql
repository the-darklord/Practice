DROP TABLE student;

CREATE TABLE student(
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(20) NOT NULL,
    major VARCHAR(20) DEFAULT 'Unknown'
);

DESCRIBE student;

INSERT INTO student(name,major) VALUES('MIHIR', 'Maths');

INSERT INTO student(name,major) VALUES('HRUTHIK', 'Biology');

INSERT INTO student(name) VALUES('TDL');

INSERT INTO student(name,major) VALUES('SAI','Physics');

INSERT INTO student(name,major) VALUES('PGM','Chemistry');

INSERT INTO student(name) VALUES('MIHIRNATH');

UPDATE student 
SET major = 'Bio'
WHERE major = 'Biology';

UPDATE student
SET major = 'Phy'
WHERE major = 'Physics';

UPDATE student
SET major = 'Computer'
WHERE student_id = 3;

UPDATE student
SET major = 'BioChem'
WHERE major = 'Bio' OR major = 'Chemistry';

DELETE FROM student
WHERE student_id = 6;

SELECT * FROM student;

SELECT name FROM student;

SELECT student.name,student.major
FROM student
ORDER BY name;

SELECT *
FROM student
ORDER BY student_id DESC;

SELECT *
FROM student
ORDER BY major,student_id;

SELECT *
FROM student
LIMIT 2;

SELECT *
FROM student
WHERE student_id <= 3 AND name <> 'MIHIR';

SELECT *
FROM student
WHERE name IN ('TDL','PGM') AND student_id >3;






-- DROP TABLE student;

-- ALTER TABLE student ADD gpa DECIMAL(3,2);

-- ALTER TABLE student DROP COLUMN gpa;