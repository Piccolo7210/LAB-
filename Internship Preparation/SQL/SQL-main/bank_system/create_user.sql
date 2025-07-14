--@D:\sql\bank_system\create_user.sql
connect system

create user bank identified by bank;

alter user bank identified by bank account unlock;

-- grant create session to bank;
grant dba to bank;

connect bank;
