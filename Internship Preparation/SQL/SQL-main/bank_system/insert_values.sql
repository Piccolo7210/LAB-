INSERT INTO BRANCH VALUES('BRIGHTON','BROOKLYN',7100000);
INSERT INTO BRANCH VALUES('DOWNTOWN','BROOKLYN',9000000);
INSERT INTO BRANCH VALUES('MIANUS','HORSENECK',400000);
INSERT INTO BRANCH VALUES('NORTH TOWN','RYE',3700000);
INSERT INTO BRANCH VALUES('PERRYRIDGE','HORSENECK',1700000);
INSERT INTO BRANCH VALUES('POWNAL','BENNINGTON',300000);
INSERT INTO BRANCH VALUES('REDWOOD','PALO ALTO',2100000);
INSERT INTO BRANCH VALUES('ROUND HILL','HORSENECK',8000000);
-- 
INSERT INTO CUSTOMER VALUES('ADAMS','SPRING','PITTSFIELD');
INSERT INTO CUSTOMER VALUES('BROOKS','SENATOR','BROOKLYN');
INSERT INTO CUSTOMER VALUES('CURRY','NORTH','RYE');
INSERT INTO CUSTOMER VALUES('GLENN','SAND HILL','WOODSIDE');
INSERT INTO CUSTOMER VALUES('GREEN','WALNUT','STAMFORD');
INSERT INTO CUSTOMER VALUES('HAYES','MAIN','HARRISON');
INSERT INTO CUSTOMER VALUES('JOHNSON','ALMA','PALO ALTO');
INSERT INTO CUSTOMER VALUES('JONES','MAIN','HARRISON');
INSERT INTO CUSTOMER VALUES('LINDSAY','PARK','PITTSFIELD');
INSERT INTO CUSTOMER VALUES('SMITH','NORTH','RYE');
INSERT INTO CUSTOMER VALUES('TURNER','PUTNAM','STAMFORD');
INSERT INTO CUSTOMER VALUES('WILLIAMS','NASSAU','PRINCETON');
-- 
INSERT INTO ACCOUNT VALUES('A-101','DOWNTOWN',500);
INSERT INTO ACCOUNT VALUES('A-102','PERRYRIDGE',400);
INSERT INTO ACCOUNT VALUES('A-201','BRIGHTON',900);
INSERT INTO ACCOUNT VALUES('A-215','MIANUS',700);
INSERT INTO ACCOUNT VALUES('A-217','BRIGHTON',750);
INSERT INTO ACCOUNT VALUES('A-222','REDWOOD',700);
INSERT INTO ACCOUNT VALUES('A-305','ROUND HILL',350);
-- 
INSERT INTO LOAN VALUES('L-11','ROUND HILL',900);
INSERT INTO LOAN VALUES('L-14','DOWNTOWN',1500);
INSERT INTO LOAN VALUES('L-15','PERRYRIDGE',1500);
INSERT INTO LOAN VALUES('L-16','PERRYRIDGE',1300);
INSERT INTO LOAN VALUES('L-17','DOWNTOWN',1000);
INSERT INTO LOAN VALUES('L-23','REDWOOD',2000);
INSERT INTO LOAN VALUES('L-93','MIANUS',500);
-- 
INSERT INTO DEPOSITOR VALUES('HAYES','A-102');
INSERT INTO DEPOSITOR VALUES('JOHNSON','A-101');
INSERT INTO DEPOSITOR VALUES('JOHNSON','A-201');
INSERT INTO DEPOSITOR VALUES('JONES','A-217');
INSERT INTO DEPOSITOR VALUES('LINDSAY','A-222');
INSERT INTO DEPOSITOR VALUES('SMITH','A-215');
INSERT INTO DEPOSITOR VALUES('TURNER','A-305');
-- 
INSERT INTO BORROWER VALUES('ADAMS','L-16');
INSERT INTO BORROWER VALUES('CURRY','L-93');
INSERT INTO BORROWER VALUES('HAYES','L-15');
INSERT INTO BORROWER VALUES('JOHNSON','L-14');
INSERT INTO BORROWER VALUES('JONES','L-17');
INSERT INTO BORROWER VALUES('SMITH','L-11');
INSERT INTO BORROWER VALUES('SMITH','L-23');
INSERT INTO BORROWER VALUES('WILLIAMS','L-17');