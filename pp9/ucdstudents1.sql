CREATE DATABASE ucdstudents;
USE ucdstudents;

CREATE TABLE programme (
	p_id INT (8) NOT NULL,
	p_name VARCHAR (30),
	p_faculty VARCHAR (30),
	p_description VARCHAR (300),
	PRIMARY KEY (p_id)
	);
	
CREATE TABLE student (
	s_id INT (8) NOT NULL,
	f_name VARCHAR (30),
	l_name VARCHAR (30),
	dob DATE,
	address VARCHAR (300),
	phone VARCHAR (15),
	email VARCHAR (50),
	p_id INT (8) NOT NULL,
	PRIMARY KEY (s_id),
	FOREIGN KEY (p_id) REFERENCES programme (p_id) ON UPDATE CASCADE
	);
	
CREATE TABLE modules (
	m_id INT (8) NOT NULL,
	m_name VARCHAR (30),
	m_description VARCHAR (300),
	PRIMARY KEY (m_id)
	);
	
CREATE TABLE students_on_module (
	s_id INT (8) NOT NULL,
	m_id INT (8) NOT NULL,
	reg_date DATE,
	PRIMARY KEY (s_id, m_id),
	FOREIGN KEY (s_id) REFERENCES student (s_id),
	FOREIGN KEY (m_id) REFERENCES modules (m_id)
	);
	
CREATE TABLE student_module_grade (
	s_id INT (8) NOT NULL,
	m_id INT (8) NOT NULL,
	grade FLOAT (5,2) NOT NULL,
	date_awarded DATE,
	PRIMARY KEY (s_id, m_id),
	FOREIGN KEY (s_id) REFERENCES students_on_module (s_id),
	FOREIGN KEY (m_id) REFERENCES students_on_module (m_id)
	);
	
INSERT INTO programme
	VALUES
	('001', 'Archaeology', 'Arts', 'The study of human activity in the past'),
	('002', 'Philosophy', 'Arts', 'The study of general and fundamental problems'),
	('003', 'Psychology', 'Arts', 'The study of mental functions and behaviours'),
	('101', 'Genetics', 'Science', 'The science of genes, heredity, and variation in living organisms'),
	('102', 'Computer Science', 'Science', 'The scientific approach to computation and its applications'),
	('103', 'Physics', 'Science', 'The study of matter and its motion through space and time'),
	('201', 'Biomedical Engineering', 'Engineering', 'The application of engineering principles and design concepts to medicine and biology'),
	('202', 'Civil Engineering', 'Engineering', ' The design, construction, and maintenance of the physical and naturally built environment'),
	('203', 'Mechanical Engineering', 'Engineering', 'Apply the principles of physics and materials science for analysis, design, manufacturing, and maintenance of mechanical systems')
	;

INSERT INTO student
	VALUES
	('10001', 'Merkin', 'Muffley', '1964-01-29', 'Rathmines, Dublin 06', '92104691', 'drstrangelove@ucdconnect.ie', '103'),
	('10002', 'Tony', 'Montana', '1983-12-09', 'Donnybrook, Dublin 04', '90213891', 'scarface@ucdconnect.ie', '201'),
	('10003', 'Black', 'Mamba', '2003-10-10', 'Ranelagh, Dublin 06', '01013002', 'killbill@ucdconnect.ie', '003'),
	('10004', 'Vermithrax', 'Pejorative', '1981-06-26', 'Blackrock, Co Dublin', '62601891', 'dragonslayer@ucdconnect.ie', '201'),
	('10005', 'Rocky', 'Balboa', '1976-12-03', 'Greystones, Co Wicklow', '30216791', 'rocky@ucdconnect.ie', '202'),
	('10006', 'Breathless', 'Mahoney', '1990-06-15', 'Bray, Co Wicklow', '51600991', 'dicktracy@ucdconnect.ie', '101'),
	('10007', 'Atticus', 'Finch', '1962-03-16', 'Roscrea, Co Tipperary', '61302691', 'mockingbird@ucdconnect.ie', '002'),
	('10008', 'Maximus', 'Decimus Meridius', '2000-05-05', 'Birr, Co Offaly', '50500002', 'gladiator@ucdconnect.ie', '001'),
	('10009', 'Egon', 'Spengler', '1984-06-08', 'Galway, Co Galway', '80604891', 'ghostbusters@ucdconnect.ie', '003'),
	('10010', 'Pepper', 'Potts', '2008-05-02', 'Nenagh, Co Tipperary', '20508002', 'ironman@ucdconnect.ie', '102'),
	('10011', 'Don', 'Vito', '1972-03-24', 'Donabate, Co Dublin', '42302791', 'thegodfather@ucdconnect.ie', '201'),
	('10012', 'Luke', 'Skywalker', '1977-05-25', 'Rush, Co Dublin', '52507791', 'starwars@ucdconnect.ie', '103'),
	('10013', 'Sugar', 'Kane Kowalczyk', '1959-03-29', 'Portlaoise, Co Laois', '92309591', 'somelikeithot@ucdconnect.ie', '001'),
	('10014', 'Travis', 'Bickle', '1976-02-08', 'Kildare, Co Kildare', '92309591', 'taxidriver@ucdconnect.ie', '203'),
	('10015', 'Sam', 'Spade', '1941-10-18', 'Cork, Co Cork', '81011491', 'maltesefalcon@ucdconnect.ie', '102'),
	('10016', 'Cruella', 'De Vil', '1961-01-25', 'Belfast, Co Antrim', '52101691', 'dalmations@ucdconnect.ie', '001'),
	('10017', 'Holly', 'Golightly', '1961-11-08', 'Shinrone, Co Offaly', '80111691', 'tiffanys@ucdconnect.ie' , '001'),
	('10018', 'Jack', 'Sparrow', '2003-07-09', 'Ennis, Co Clare', '90703002', 'pirates@ucdconnect.ie', '002'),
	('10019', 'Clarice', 'Starling', '1991-02-14', 'Belfield, Dublin 04', '41201991', 'lambs@ucdconnect.ie', '003'),
	('10020', 'Gordon', 'Gekko', '1987-12-11', 'Donnybrook, Dublin 04', '11217891', 'wallstreet@ucdconnect.ie', '101'),
	('10021', 'Jack', 'Skellington', '1993-10-29', 'Rathmines, Dublin 06', '92013991', 'nightmare@ucdconnect.ie', '201'),
	('10022', 'Donnie', 'Darko', '2001-10-25', 'Galway, Co Galway', '52011002', 'ddarko@ucdconnect.ie', '003'),
	('10023', 'Keyser', 'Soze', '1995-08-16', 'Roscrea, Co Tipperary', '61805991', 'suspects@ucdconnect.ie', '202'),
	('10024', 'John', 'Blutarsky', '1978-07-28', 'Birr, Co Offaly', '82708791', 'animalhouse@ucdconnect.ie', '203'),
	('10025', 'Hedley', 'Lamarr', '1974-02-07', 'Greystones, Co Wicklow', '70204791', 'blazingsaddles@ucdconnect.ie', '202')
	;
	
INSERT INTO modules
	VALUES
	('1001', 'Prehistoric Archaeology', 'Introduction to Prehistoric Archaeology'),
	('1002', 'Historical Archaeology', 'Introduction to Historical Archaeology'),
	('1003', 'Material Culture', 'Introduction to Material Culture'),
	('2001', 'Knowledge and Truth', 'Introduction to Knowledge and Truth'),
	('2002', 'Mind and Meaning', 'Introduction to Mind and Meaning'),
	('2003', 'Brain and Behaviour', 'Introduction to Brain and Behaviour'),
	('2004', 'Genetics', 'Introduction to Genetics'),
	('3001', 'Mathematics', 'Introduction to Mathematics'),
	('3002', 'Programming', 'Introduction to Programming'),
	('3003', 'Database Management Systems', 'Introduction to Database Management Systems'),
	('4001', 'Physics', 'Introduction to Physics'),
	('4002', 'Mechanics', 'Introduction to Mechanics'),
	('4003', 'Heat Transfer', 'Introduction to Heat Transfer'),
	('5001', 'Applied Dynamics', 'Introduction to Applied Dynamics'),
	('5002', 'Hydraulic Engineering', 'Introduction to Hydraulic Engineering'),
	('5003', 'Creativity in Design', 'Introduction to Creativity in Design')
	;
	
INSERT INTO students_on_module
	VALUES
	('10001', '1001', '2012-09-01'),
	('10001', '2001', '2012-09-01'),
	('10002', '1002', '2012-09-01'),
	('10003', '1003', '2012-09-01'),
	('10004', '2002', '2012-09-01'),
	('10004', '2003', '2012-09-01'),
	('10005', '2004', '2012-09-01'),
	('10006', '3001', '2012-09-01'),
	('10006', '3002', '2012-09-01'),
	('10007', '3003', '2012-09-01'),
	('10008', '4001', '2012-09-01'),
	('10009', '4002', '2012-09-01'),
	('10010', '4003', '2012-11-01'),
	('10010', '5001', '2012-11-01'),
	('10010', '5002', '2012-11-01'),
	('10011', '5003', '2012-11-01'),
	('10012', '1001', '2012-11-01'),
	('10013', '1002', '2012-11-01'),
	('10013', '1003', '2012-11-01'),
	('10013', '2001', '2012-11-01'),
	('10013', '2002', '2012-11-01'),
	('10014', '2003', '2012-11-01'),
	('10014', '2004', '2013-01-01'),
	('10014', '3001', '2013-01-01'),
	('10014', '3002', '2013-01-01'),
	('10015', '3003', '2013-01-01'),
	('10015', '4001', '2013-01-01'),
	('10016', '4002', '2013-01-01'),
	('10016', '4003', '2013-01-01'),
	('10016', '5001', '2013-01-01'),
	('10017', '5002', '2013-01-01'),
	('10017', '5003', '2013-01-01'),
	('10018', '1001', '2013-03-01'),
	('10018', '1002', '2013-03-01'),
	('10019', '1003', '2013-03-01'),
	('10020', '2001', '2013-03-01'),
	('10020', '2002', '2013-03-01'),
	('10021', '2003', '2013-03-01'),
	('10022', '2004', '2013-03-01'),
	('10023', '3001', '2013-03-01'),
	('10024', '3002', '2013-03-01'),
	('10025', '3003', '2013-03-01')
	;
	
INSERT INTO student_module_grade
	VALUES
	('10001', '1001', '100.00', '2012-12-01'),
	('10001', '2001', '90.25', '2012-12-01'),
	('10002', '1002', '88.75', '2012-12-01'),
	('10003', '1003', '76.55', '2012-12-01'),
	('10004', '2002', '45.33', '2012-12-01'),
	('10004', '2003', '88.72', '2012-12-01'),
	('10005', '2004', '76.40', '2012-12-01'),
	('10006', '3001', '65.84', '2012-12-01'),
	('10006', '3002', '65.92', '2012-12-01'),
	('10007', '3003', '64.87', '2012-12-01'),
	('10008', '4001', '77.65', '2012-12-01'),
	('10009', '4002', '35.25', '2012-12-01'),
	('10010', '4003', '76.82', '2013-01-01'),
	('10010', '5001', '45.58', '2013-01-01'),
	('10010', '5002', '52.78', '2013-01-01'),
	('10011', '5003', '62.55', '2013-01-01'),
	('10012', '1001', '76.95', '2013-01-01'),
	('10013', '1002', '43.89', '2013-01-01'),
	('10013', '1003', '88.90', '2013-01-01'),
	('10013', '2001', '27.85', '2013-01-01'),
	('10013', '2002', '25.42', '2013-01-01'),
	('10014', '2003', '10.55', '2013-02-15'),
	('10014', '2004', '17.85', '2013-02-15'),
	('10014', '3001', '27.75', '2013-02-15'),
	('10014', '3002', '38.55', '2013-02-15'),
	('10015', '3003', '79.86', '2013-02-15'),
	('10015', '4001', '85.75', '2013-02-15'),
	('10016', '4002', '76.50', '2013-02-15'),
	('10016', '4003', '72.45', '2013-02-15'),
	('10016', '5001', '58.75', '2013-02-15'),
	('10017', '5002', '48.95', '2013-02-15'),
	('10017', '5003', '50.00', '2013-02-15'),
	('10018', '1001', '27.85', '2013-03-10'),
	('10018', '1002', '60.00', '2013-03-10'),
	('10019', '1003', '70.25', '2013-03-10'),
	('10020', '2001', '71.50', '2013-03-10'),
	('10020', '2002', '68.95', '2013-03-10'),
	('10021', '2003', '77.25', '2013-03-10'),
	('10022', '2004', '76.25', '2013-03-10'),
	('10023', '3001', '99.58', '2013-03-10'),
	('10024', '3002', '95.75', '2013-03-10'),
	('10025', '3003', '92.50', '2013-03-10')
	;