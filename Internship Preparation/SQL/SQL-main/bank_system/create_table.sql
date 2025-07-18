CREATE TABLE BRANCH (
	BRANCH_NAME VARCHAR2(20),
	BRANCH_CITY VARCHAR2(20),
	ASSETS NUMBER(20),
	CONSTRAINT BRANCH_PK PRIMARY KEY (BRANCH_NAME)	
);

CREATE TABLE CUSTOMER (
	CUSTOMER_NAME VARCHAR2(20),
	CUSTOMER_STREET VARCHAR2(20),
	CUSTOMER_CITY VARCHAR2(20),
	CONSTRAINT CUSTOMER_PK PRIMARY KEY (CUSTOMER_NAME)	
);

CREATE TABLE ACCOUNT (
	ACCOUNT_NUMBER VARCHAR2(20),
	BRANCH_NAME VARCHAR2(20),
	BALANCE NUMBER(20),
	CONSTRAINT ACCOUNT_PK PRIMARY KEY (ACCOUNT_NUMBER),
	CONSTRAINT ACCOUNT_FK FOREIGN KEY (BRANCH_NAME) REFERENCES BRANCH (BRANCH_NAME)
);

CREATE TABLE LOAN (
	LOAN_NUMBER VARCHAR2(20),
	BRANCH_NAME VARCHAR2(20),
	AMOUNT NUMBER(20),
	CONSTRAINT LOAN_PK PRIMARY KEY (LOAN_NUMBER),
	CONSTRAINT LOAN_FK FOREIGN KEY (BRANCH_NAME) REFERENCES BRANCH (BRANCH_NAME)
);

CREATE TABLE DEPOSITOR (
	CUSTOMER_NAME VARCHAR2(20),
	ACCOUNT_NUMBER VARCHAR2(20),
	CONSTRAINT DEPOSITOR_PK PRIMARY KEY (CUSTOMER_NAME,ACCOUNT_NUMBER),
	CONSTRAINT DEPOSITOR_CUSTOMER_FK FOREIGN KEY (CUSTOMER_NAME) REFERENCES CUSTOMER (CUSTOMER_NAME),
	CONSTRAINT DEPOSITOR_ACCOUNT_FK FOREIGN KEY (ACCOUNT_NUMBER) REFERENCES ACCOUNT (ACCOUNT_NUMBER)
);

CREATE TABLE BORROWER (
	CUSTOMER_NAME VARCHAR2(20),
	LOAN_NUMBER VARCHAR2(20),
	CONSTRAINT BORROWER_PK PRIMARY KEY (CUSTOMER_NAME,LOAN_NUMBER),
	CONSTRAINT BORROWER_CUSTOMER_FK FOREIGN KEY (CUSTOMER_NAME) REFERENCES CUSTOMER (CUSTOMER_NAME),
	CONSTRAINT BORROWER_LOAN_FK FOREIGN KEY (LOAN_NUMBER) REFERENCES LOAN (LOAN_NUMBER)
);
