M :M Veh owner because,
A vehicle can only have one owner.A citizen can have many vehicle.1 :1: citizen driving license because,
A citizen can have only one driving licence.a driving licence can be issued to only one citizen but a citizen can have only one driving licence.M :M: because,
same drivier multiple acc
and one accident multiple driver M :M: because,
same veh.multiple acc
and one accident multiple vehicle CREATE TABLE Citizen (
    NID INT,
    Name VARCHAR2(20),
    DOB DATE,
    Address VARCHAR2(30),
    Contact INT,
    constraint pk_citizen primary key NID
);
CREATE TABLE Vehicle (
    V_ID INT,
    Owner_NID INT,
    Type VARCHAR2(10),
    reg_date DATE,
    Description VARCHAR2(100),
    Color VARCHAR2(10),
    Engine_no.INT,
    constraint pk_vehicle primary key V_ID,
    constraint fk_vehicle foreign Key Owner_NID references Citizen(NID)
);
CREATE TABLE Driving_licence (
    d_licn int primary key,
    issue_date date,
    expire_date date,
    blood_group varchar2(5),
    NID int,
    constraint dfk foreign key NID references citizen(nid)
);
CREATE TABLE Accident (
    v_ID int,
    d_licn int,
    time TIMESTAMP,
    place varcahr2(50),
    dateac date constraint afk foreign key v_ID references vehicle(v_id),
    constraint afk foreign key d_licn references Driving_licence(d_licn)
);
CREATE TABLE Driving_licence (
    d_licn int primary key,
    issue_date date,
    expire_date date,
    blood_group varchar2(5),
    NID int,
    constraint dfk foreign key NID references citizen(nid)
);
CREATE TABLE Accident (
    v_ID int,
    d_licn int,
    time TIMESTAMP,
    place varcahr2(50),
    dateac date constraint afk foreign key v_ID references vehicle(v_id),
    constraint afk foreign key d_licn references Driving_licence(d_licn)
);