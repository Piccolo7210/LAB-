-- Insert data into the 'branch' table
INSERT INTO branch VALUES 
    ('Shahjahanpur','Dhaka',1000000);

INSERT INTO branch VALUES 
    ('Chankharpul','Dhaka',500000);

INSERT INTO branch VALUES 
    ('Chawkbazar','Chattogram',1000000);

INSERT INTO branch VALUES 
    ('Jahangirabad','Bogura',500000);

INSERT INTO branch VALUES 
    ('Hasnabad','Narshingdi',700000);

INSERT INTO branch VALUES 
    ('Chatok','Sylhet',1000000);

-- Insert data into the 'customer' table
INSERT INTO customer VALUES
    ('Yasin','Shahjahanpur','Dhaka');

INSERT INTO customer VALUES
    ('Ayon','Goran','Dhaka');

INSERT INTO customer VALUES
    ('Shuvo','Fashitola','Gaibandha');

INSERT INTO customer VALUES
    ('Farhan','Bayzid Road','Chattorgram');

INSERT INTO customer VALUES
    ('Sejuti','Raipura','Narshingdi');

INSERT INTO customer VALUES
    ('Dhrubo','Shankar','Dhaka');

INSERT INTO customer VALUES
    ('Shaikh','Noyabad','Dinajpur');

INSERT INTO customer VALUES
    ('Habib','Sreemangal','Sylhet');

-- Insert data into the 'account' table
INSERT INTO account VALUES
    (328576829,'Shahjahanpur',1406);

INSERT INTO account VALUES
    (179347832,'Chankharpul',1421);

INSERT INTO account VALUES
    (732894720,'Chankharpul',1431);

INSERT INTO account VALUES
    (334729724,'Chawkbazar',1440);

INSERT INTO account VALUES
    (474830283,'Hasnabad',1420);

INSERT INTO account VALUES
    (847283729,'Jahangirabad',1432);

INSERT INTO account VALUES
    (478274945,'Shahjahanpur',1438);

INSERT INTO account VALUES
    (498201003,'Chatok',1422);

-- Insert data into the 'loan' table
INSERT INTO loan VALUES
    (3652,'Shahjahanpur',1400);

INSERT INTO loan VALUES
    (8273,'Chawkbazar',1200);


-- Insert data into the 'depositor' table row by row
INSERT INTO depositor (customer_name, account_number) VALUES ('Yasin', 328576829);
INSERT INTO depositor (customer_name, account_number) VALUES ('Ayon', 179347832);
INSERT INTO depositor (customer_name, account_number) VALUES ('Shuvo', 334729724);
INSERT INTO depositor (customer_name, account_number) VALUES ('Farhan', 478274945);
INSERT INTO depositor (customer_name, account_number) VALUES ('Sejuti', 474830283);
INSERT INTO depositor (customer_name, account_number) VALUES ('Dhrubo', 847283729);
INSERT INTO depositor (customer_name, account_number) VALUES ('Shaikh', 498201003);
INSERT INTO depositor (customer_name, account_number) VALUES ('Habib', 732894720);

INSERT INTO borrower VALUES ('Yasin',3652);
INSERT INTO borrower VALUES ('Farhan',8273);

