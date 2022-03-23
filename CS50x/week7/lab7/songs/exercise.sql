CREATE TABLE people (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL
);

CREATE TABLE courses (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    code TEXT NOT NULL,
    title TEXT NOT NULL
);

CREATE TABLE students (
    person_id INTEGER NOT NULL,
    course_id INTEGER NOT NULL
);

CREATE TABLE instructors (
    person_id INTEGER NOT NULL,
    course_id INTEGE NOT NULL
);

INSERT INTO people (name) VALUES ("alice");
Boaz
Charlie
David
Erin
Fiona
Greg
Helen
Irene
Jason
Stuart

INSERT INTO courses (code, title) VALUES ("CS50", "Introduction to Computer Science");
INSERT INTO courses (code, title) VALUES ("ECON 10a", "Principles of Economics");
INSERT INTO courses (code, title) VALUES ("CS51", "Abstraction and Design in Computation");
INSERT INTO courses (code, title) VALUES ("CS121", "Introduction to Theoretical Computer Science");
INSERT INTO courses (code, title) VALUES ("CS182", "Artificial Intelligence");

INSERT INTO instructors (person_id, course_id) VALUES (4, 1);
INSERT INTO instructors (person_id, course_id) VALUES (10, 2);
INSERT INTO instructors (person_id, course_id) VALUES (11, 3);
INSERT INTO instructors (person_id, course_id) VALUES (2, 4);

INSERT INTO students (person_id, course_id) VALUES (3, 1);
INSERT INTO students (person_id, course_id) VALUES (5, 1);
INSERT INTO students (person_id, course_id) VALUES (6, 1);
INSERT INTO students (person_id, course_id) VALUES (3, 2);
INSERT INTO students (person_id, course_id) VALUES (6, 2);
INSERT INTO students (person_id, course_id) VALUES (7, 2);
INSERT INTO students (person_id, course_id) VALUES (8, 2);
INSERT INTO students (person_id, course_id) VALUES (7, 3);
INSERT INTO students (person_id, course_id) VALUES (8, 3);
INSERT INTO students (person_id, course_id) VALUES (9, 3);
INSERT INTO students (person_id, course_id) VALUES (1, 4);
INSERT INTO students (person_id, course_id) VALUES (9, 4);