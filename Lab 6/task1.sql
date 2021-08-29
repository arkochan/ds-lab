CREATE TABLE Doctor (
    name varchar2(30),
    age INT,
    qualification varchar2(30),
    specialization varchar2(30),
    ID INT,
    room_no INT,
    slot_id INT,
    constraint d_pk primary key(ID),
    constraint d_fkr foreign key(room_no) references room,
    constraint d_fkt foreign key(slot_id) references timeslot,
);
CREATE TABLE receptionists (
    r_id int primary key,
    salary number,
    name varchar2(30)
);
CREATE TABLE patient (
    name varchar2(30),
    age INT,
    gender varchar2(10),
    height INT,
    weight INT,
    ID INT,
    medicines varchar2(50),
    diagnosis_no INT,
    doctor_id INT,
    constraint p_pk primary key(ID),
    constraint p_fkr foreign key(diagnosis_no) references report(diagnosis_no),
    constraint p_fkd foreign key(doctor_id) references Doctor(ID),
);
CREATE TABLE timeslot (
    start_time time,
    end_time time,
    slot_id INT primary key
);
CREATE TABLE room (
    floor INT,
    purpose varchar2(30),
    room_no INT primary key
);
CREATE TABLE report (
    diagnosis_no int primary KEY,
    type varchar2(20)
);