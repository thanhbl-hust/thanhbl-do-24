# [Database Overview - Final Version]()

## [**Contents**](#contents)

- [**Database Overview**](#database-overview)
  - [What is database?](#what-is-database)
  - [Database types: Relational and Non-relational database](#database-types-relational-and-non-relational-database)
  - [(Relational) Database concepts: table, column, row, schema, index, keys, constraints..](#relational-database-concepts-table-column-row-schema-index-keys-constraints-query)

- [**Target and plan (MySQL)**](#target-and-plan)
  - [Install and configure MySQL server](#install-and-configure-mysql-server)
  - [Manage user, permissions](#manage-user-permissions)
  - [Data type, variable](#data-type-variable)
  - [Important Parameters](#important-parameters)

- [**References**](#references)

## [**Database Overview**]()
- [What is database?](#what-is-database)
- [Database types: Relational and Non-relational database](#database-types-relational-and-non-relational-database)
- [(Relational) Database concepts: table, column, row, schema, index, keys, constraints..](#relational-database-concepts-table-column-row-schema-index-keys-constraints-query)


### [What is database?]()

**So, what is a database?** 
- A database is a collection of data that represents some aspect of the real world, having a unified logical relationship, designed and containing data that serves some purposes.

- For example, a university will have a database to store information about students, teachers, courses, score... . A bank will have a database to store information about customers, accounts, transactions...

### [Database types: Relational and Non-relational database]()

Database can be classified into 2 primary types: `Relational` and `NoSQL` databases.

NoSQL databases include several different models for accessing and managing data, each suited to specific use cases. 

  - Document: a type of NoSQL database that can be used to store and query data as JSON-like documents

  - Key-value: a type of NoSQL uses a simple key-value method to store data. It stores data as a collection of key-value pairs in which a key serves as a unique identifier.

  - Wide-column: Wide Column Store is a type of NoSQL database that stores data in columns instead of rows. It is purpose-built for high scalability and high write/read speed.

  - Graph: a type of NoSQL uses mathematical graph theory to show data connections. 

<div style="text-align: center;">
  <img src="pic/types-of-nosql.png" alt="Description of image" style="max-width: 500px; width: 100%; height: auto;">
</div>


<div style="text-align: center;">
  <img src="pic/compare_databases.png" alt="Description of image" style="max-width: 500px; width: 100%; height: auto;">
</div>

### [(Relational) Database concepts: table, column, row, schema, index, keys, constraints..]()

#### Table - Column - Row

<div style="text-align: center;">
  <img src="pic/table_structure.png" alt="Description of image" style="max-width: 500px; width: 100%; height: auto;">
</div>

#### Schema

A database schema is a logical representation of data that shows how the data in a database should be stored logically. It shows how the data is organized and the relationship between the tables.

There are three main types of database schemas:

- **Conceptual database schema**: This is a high-level overview of what your database will contain, how the data will be organized and the rules the data will follow. This type of schema is created in the initial project stage.

- **Logical database schema**: This schema clearly defines all the elements within the database and any related information, such as field names, entity relationships, integrity constraints and table names.

- **Physical database schema**: A physical schema combines contextual and logical information while adding technical requirements. It contains the syntax needed to create data structures within the disk storage.

#### Index

**Indexes** are used to find row with specific columns values quickly. Without an index, MySQL must begin with the first row and then read through the entire table to find the relevant rows. The larger table, the more cost it takes. If the table has an index for the columns in question, MySQL can quickly determine the position to seek to in the middle of the data file without having to look at all the data. This is much faster than reading every row sequentially.

Most SQL indexes are stored in [B-tree](). 

<div style="text-align: center;">
  <img src="pic/index.png" alt="Description of image" style="max-width: 550px; width: 100%; height: auto;">
</div>

**B-tree indexing:**

The **B-tree**, also called balanced-tree, its nodes are sorted in a inorder traversal. This image below describe differents between b_tree and BST.

Different points from b-tree over binary tree:

<div style="text-align: center;">
  <img src="pic/tree.png" alt="Description of image" style="max-width: 550px; width: 100%; height: auto;">
</div>

  - A B-tree node can have more than 2 childs (based on B-tree order, which based on block size)

  - A B-tree node can have more than one value (not like in binary tree, has one value only), decrease height of b-tree, which makes operations fast

  - Binary Tree height can be a big number (not balanced), which can lead to 0(n) time complexity in common actions like insert, search, delete

  - B-tree is more hard to implement than BST



#### Key

In a relational database, a **Key** is defined as a column or a group of columns which are used to uniquely locate records in a table.

<div style="text-align: center;">
  <img src="pic/keys.png" alt="Description of image" style="max-width: 550px; width: 100%; height: auto;">
</div>

There are some common keys in MySQL:

  - **Primary key**: Used to identify one and only one record of a table uniquely. A table can have only one primary key. Primary key must contain UNIQUE value and it can't be NULL. The Primary key can contain a single or multiple columns.

  - **Foreign key**: Is a column (or collection of columns) in one table, that refers to the primary key in another table.

  - **Unique key**: A group of one or more columns of a table that uniquely identify a record is known as a unique key. It prevents from storing duplicate value in two records in a column. Unique key can have NULL value.

  - **Candicate key**: Keys that can uniquely identify the record so except primary key, remaining key are considered as candicate key.

  - **Super key**: A super key is a set of one or more attributes that, taken collectively, can uniquely identify a record in a table.


#### Constraints

**SQL constraints** are used to specify rules for the data in a table.

Constraints are used to limit the type of data that can go into a table. This ensures the accuracy and reliability of the data in the table. If there is any violation between the constraint and the data action, the action is aborted.

Common constraints in SQL database:

  - **NOT NULL**: Ensures that a column can't have a NULL value

  - **UNIQUE**: Ensures that all values in a column are different

  - **PRIMARY KEY**: Combination of NOT NULL and UNIQUE, used to identifies each row in a table

  - **DEFAULT**: Provides a default value for a column when no value is specified during an insert operation

## [**Target and Plan (MySQL)**]()

- [Install and configure MySQL server](#install-and-configure-mysql-server)
- [Manage user, permissions](#manage-user-permissions)
- [Data type, variable](#data-type-variable)
- [Important Parameters](#important-parameters)

### [Install and configure MySQL server]()

`Task`: **Install MySQL server: version 5.7, change configuration option:**

  - **Install MySQL Server 5.7**

Dowload MySQL Repository
 
```console
$ wget https://dev.mysql.com/get/mysql-apt-config_0.8.12-1_all.deb
$ ls
mysql-apt-config_0.8.12-1_all.deb
```
 
After MySQL package dowloaded success, install it:
 
```console
$ sudo dpkg -i mysql-apt-config_0.8.12-1_all.deb
```
 
Select `mysql-5.7` - `OK`.
 
Update the repository:
 
```console
$ sudo apt update
```
 
Import key:
 
```console
$ sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys [add_key_here]
```
 
Update one more time:
 
```console
$ sudo apt update --allow-insecure-repositories
$ sudo apt update
```
 
Check if MySQL 5.7 version repository successfully installed:
 
```console
$ sudo apt-cache policy mysql-server
mysql-server:
  Installed: (none)
  Candidate: 8.0.39-0ubuntu0.22.04.1
  Version table:
    ...       
    5.7.42-1ubuntu18.04 500
      500 http://repo.mysql.com/apt/ubuntu bionic/mysql-5.7 amd64 Packages
```
 
Install MySQL 5.7 version:
 
```console
$ sudo apt install -f mysql-client=5.7* mysql-community-server=5.7* mysql-server=5.7*
```
 
Check MySQL Server version
 
```console
$ mysql --version
mysql  Ver 14.14 Distrib 5.7.42, for Linux (x86_64) using  EditLine wrapper
```

  - **port 9306**: Add line **port = 9306** to `/etc/mysql/mysql.conf.d/mysqld.cnf` file
```sql
mysql> SHOW GLOBAL VARIABLES LIKE 'port';
+---------------+-------+
| Variable_name | Value |
+---------------+-------+
| port          | 9306  |
+---------------+-------+
1 row in set (0.00 sec)
```


  - **bind-address: private ip address**

What is **bind-address**?

  - **logs**

[Image of log files in MySQL](https://dev.mysql.com/doc/refman/8.4/en/server-logs.html)

  - **change log path: /home/database/mysql/logs**

Stop MySQL service:

```console
$ sudo systemctl stop mysql
```

Create a new directory to store log:

```console
$ sudo mkdir -p /home/database/mysql/logs
$ sudo chmod 777 /home/database/mysql/logs
```

Copy logs from default location to new location and remove old one:

```console
$ sudo rsync -avz /var/log/mysql/error.log /home/database/mysql/logs
$ sudo mv /var/log/mysql /var/log/mysql-old
```

Change log file location in config file `/etc/mysql/mysql.conf.d/mysqld.cnf`:

```
log-error = /home/database/mysql/logs/error.log
```

Fix apparmor reflect directory change:

```console
$ sudo nano /etc/apparmor.d/tunables/alias
# Add line: alias /var/log/mysql -> /home/database/mysql/logs,
$ sudo apparmor_parser -r /etc/apparmor.d/usr.sbin.mysqld   
```

Start MySQL Server again and check:

```
$ sudo systemctl start mysql
$ cat /home/database/mysql/logs/error.log
```

You can see the content of new log and old log located in new directory successfully!

  - **max connections = 100**: Add line **max_connections = 100** to `/etc/mysql/mysql.conf.d/mysqld.cnf` file

```sql
mysql> SHOW GLOBAL VARIABLES LIKE 'max_connections';
+-----------------+-------+
| Variable_name   | Value |
+-----------------+-------+
| max_connections | 100   |
+-----------------+-------+
1 row in set (0.00 sec)
```

  - **password policy**
### [Manage user, permissions]()
`Task`:
  - **Create user: admin, client**

  ```sql
mysql> CREATE USER 'admin'@'localhost' IDENTIFIED BY 'Admin@1';
mysql> GRANT SELECT, INSERT, DELETE, UPDATE on *.* TO 'admin'@'localhost' WITH GRANT OPTION;
mysql> CREATE USER 'client'@'localhost' IDENTIFIED BY 'Client@1';
mysql> GRANT SELECT on *.* TO 'client'@'localhost' WITH GRANT OPTION;
mysql> FLUSH PRIVILEGES;
```
```
mysql> SELECT USER, HOST FROM mysql.user;
+------------------+--------------+
| USER             | HOST         |
+------------------+--------------+
| admin            | localhost    |
| client           | localhost    |
| root             | localhost    |
+------------------+--------------+
8 rows in set (0.00 sec)
```
  - **Access to database via user admin, client**

Login to MySQL server:

```console
$ mysql -u admin -p
Enter password:
```
```
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 9
Server version: 8.0.39-0ubuntu0.22.04.1 (Ubuntu)
...
mysql>
```

### [Data type, variable]()

Each column in a database table is required to have a name and a data type.

In MySQL, there are **3** main data types:

  - **String**
  - **Numeric**
  - **Date and Time**

### [Important Parameters]()

- **max_connections**: 

- **max_user_connections**: 

- **max_connect_errors**:

- **wait_timeout**:

- **interactive_timeout**:

## [**References**]()

List of references:

  - [Master. Phuong Nguyen Hong]() - Database Course (SOICT - Hanoi University of Science and Technology)

  - [dev.mysql.com](https://dev.mysql.com/doc/refman/8.4/en/server-system-variables.html) - Server System Variables

  - [mongodb.com](https://www.mongodb.com/resources/compare/relational-vs-non-relational-databases) - Relational vs Non.Relational Databases

  - [learn.microsoft.com](https://learn.microsoft.com/en-us/dotnet/architecture/cloud-native/relational-vs-nosql-data) - SQL vs. NoSQL data

  - [fivetran.com](https://www.fivetran.com/learn/what-is-a-database-schema) - What is database schema?