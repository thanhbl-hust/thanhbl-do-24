<h1 align="center">Command usually used</h1>

- Random command: **sudo lsof -i -P -n | grep -port**

- `ls`: lists all files in the current directory except for hidden files.

- `cd`: used to change the current working directory.

- `cat`: display content of file and many other uses.

- `cp`: create a copy of the contents of the file or directory to a destination.

- `chmod`: allows an administrator to set or modify a file's permissions.

- `chown`: chown command is used to change file ownership. It can change the ownership of both files and directories.

- `curl`: is a command-line tool and library for transferring data with URLs.

- `du -h -path-to-file`: disk usage of specified file or directory.

- `df -options`: displays information about total space and avaiable space on a file system.

- `scp`: share files between machines
    * From local to VM: scp -r -P 7222 thanhbl-key.pem adm1n@localhost:/home/adm1n/key.pem
    * From 2 VMs: scp -r -P 7222 thanhbl-key.pem adm1n@localhost:/home/adm1n/key.pem (can use key insteadof passwd).

- `cut -d: -f1 /etc/passwd | getent groups`: list users and groups.

- `systemctl -options`: actions with a service.

- `stat -path-to-file`: Detailed information about that file.

- Processed management command: [here](https://www.digitalocean.com/community/tutorials/process-management-in-linux)

<h1 align="center">Linux Documents</h1>

Linux File System

<p align="center">
  <img src="pic/linux-architecture.png" width="750" title="Linux File System architecture">
</p>

Directory in Linux:

- **/** : This is a place every single file and directory starts. Only root privileged user has access to this dir. (**/** is the root directory and **/root** is the home of root user).

- **/bin**: Contains binary executables files. All the commands which are under this directory can use by all the standard user.

- **/root**: Unlike other user, the home directory of root user is not in **/home**. Only root privileges can save files here.

- **/lib**: This folder containes all libraries. These are various files the system can use while performing tasks. It support the binaries in **/bin** and **/sbin** directories.

- **/home**: Home directory for all users (except root). The folders create like /home/usr1, /home/usr2 (**/etc/skel** holds holds copies of various initialization and other files that may be copied to the new user's home directory when new user added). 

- **/sbin**: (The 's' here present for *System*) Same as */bin*, but the command mostly used by systems administrators for system maintenanc or troubleshooting purpose (like reboot).

- **/mnt**: You can find all the mounted devices like USB, external HDD, disk...

Questions about Linux?

0. Export in virtual box?

1. Tại sao dùng liveserver mà không dùng bản Desktop?
	- chủ yếu làm việc với server (command line)

2. RAM required? min 1GB, suggest > 3GB (https://ubuntu.com/server/docs/system-requirements)

3. Options in Virtual Box?

4. Dynamic Allocate and Fixed physical hard disk?

	- Dynamic (phải giới hạn cho chuẩn): sử dụng không gian tối ưu, threshold fixed size. Xóa thì không tự động giải phóng
	- Fixed: không vượt đc

5. How many type of tty does Ubuntu have (6)? Why is that?

6. Network config in Virtual Box? (NAT để thiếu IP (only trong ra ngoài))

7. NAT, Hostonly, Bridge NW, overlay NW. (LOOPBACK, enp0ps3, enp0ps8)

8. LVM - how to set up disk (phân vùng ổ nhớ trong Linux, WD) computer management - storage - disk management

9. Why is empty directory is 4KB?

10. File System in Linux?

11. What is visudo, sudoers file?

12. ufw, how to deny all ssh to a server?

13. Log in ubuntu?

14. Hardware UUID?

15. Why private IP always start with (172, 198, 10)?
## <h1>Content</h1>

| No. | Task                       | Status   | Notes |
|-----|-----------------------------------------------------------------------------|-------|--------|
|  1  | Install successfully a virtual machines (VMs) Ubuntu on Vbox                                                                                         | <span style="color: green"> Complete </span> |   |
|  2  | With firstly user is "adm1n"                                                                                                                        | <span style="color: green"> Complete </span> |   |
|  [3](#3)  | Use Vi and Nano to compose a paragraph at least 15 lines, fast go to an line, fast find a string in the paragraph and create a text file                                                                                                                                                        | <span style="color: green"> Complete </span>  |   |
|  [4](#4)  | Grant owner full permission, other read-only                                                                                                        | <span style="color: green"> Complete </span>  |   |
|  [5](#5)  | Change file owner                                                                                                                                   | <span style="color: green"> Complete </span>  |   |
|  [6](#6)  | Find files that size are larger 20 MB                                                                                                               | <span style="color: green"> Complete </span>  |   |
|  [7](#7)  | Write a bash file to create a text file with name is "<hhmmss>-<DDMMYYYY>.<username>.log", run bash in 1 minute, create 1 file each 5 seconds.      | <span style="color: green"> Complete </span>  |   |
|  8  | What are the directories in the / file?                                                                                                             | <span style="color: blue"> Processing.. </span>  |   |
|  [9](#9)  | Config "adm1n" to be able to use "root" privileges without password.                                                                                | <span style="color: green"> Complete </span>  |   |
|  [10](#10) | Setup password policy at least 8 characters, complexity required, password expiration on both                                                       | <span style="color: green"> Complete </span>  |   |
|  11 | Create user "d3v", group "d3v0p5" on both                                                                                                           | <span style="color: green"> Complete </span>  |   |
|  [12](#12) | Configure newly created users so that they do not have the right to switch to other users.                                                          | <span style="color: green"> Complete </span>  |   |
|  [13](#13) | Disable SSH to "adm1n" user.                                                                                                                        | <span style="color: green"> Complete </span>  |   |
|  [14](#14) | List VM names so they can be referred to by name.                                                                                                   | <span style="color: green"> Complete </span>  |   |
|  15 | Clone the above virtual machine into 4 machines A, B, C, D.                                                                                         | <span style="color: green"> Complete </span>  |   |
|  16 | Change SSH port on VMs A, B, C, D to 7222, 6222, 5222, 4222 respectively.                                                                           | <span style="color: green"> Complete </span>  |   |
|  17 | Setup SSH client using SuperPuTTY or mRemoteNG from host to each VM.                                                                                | <span style="color: green"> Complete </span>  |   |
|  [18](#18) | Configure VMs so they can connect to each other, copy files between them via "VM's name" and "d3v" user with key pair.                              | <span style="color: green"> Complete </span>  |   |
|  19 | Install Tomcat server on machine A by using package, configure it as a service with "d3v" user                                                      | <span style="color: green"> Complete </span>  |   |
|  [20](#20) | Install MySQL 8.0 on machine B, configure it to be accessible from both internal and external sources.                                              | <span style="color: green"> Complete </span>  |   |
|  21 | Use command to display process information/kill process, run background process                                                                     | <span style="color: green"> Complete </span>  |   |
|  [22](#22) | Write a bash file using loop to print CPU, RAM, DISK information every 20 secs                                                                      | <span style="color: green"> Complete </span>  |   |
|  [23](#23) | Write a program to check tomcat server every 2 minutes, if it down then start it                                                                                     | <span style="color: green"> Complete </span>  |   |
|  [24](#24) | Find process that run on port 3306, kill it then start it again                                                                                     | <span style="color: blue"> Processing.. </span>  |   |
|  [25](#25) | Setup log rotate for tomcat server                                                                                                                  | <span style="color: green"> Complete </span>  |   |
|  [26](#26) | Setup a job to run periodically to backup MySQL data every day                                                                                      | <span style="color: green"> Complete </span>  |   |
|  [27](#27) | Configure Tomcat in A so that it can use MySQL in B                                                                                                 | <span style="color: green"> Complete </span>  |   |
|  [28](#28) | Set up Nginx/php on machine C and D to connect to Mysql, show simple to-do item list web page                                                       | <span style="color: green"> Complete </span>  |   |


<h1>Doing task</h1>


Add home for an user:

```console
$ cp /etc/skel /home/adm1n
$ chown adm1n /home/adm1n
$ usermod adm1n -s /bin/bash
$ source .bashrc
```

## 3.  
[Back to content](#content)

**Use Vi and Nano to compose a paragraph at least 15 lines, fast go to an line, fast find a string in the paragraph and create a text file**

Shortcut in nano editor:

  - Processing....

## 4. 
[Back to content](#content)

**Grant owner full permission, other read-only**

```console
thanh-bl@thanh-bl:~$ sudo chmod 744 <your-file>
```

## 5. 
[Back to content](#content)

**Change file owner**

```console
thanh-bl@thanh-bl:~$ sudo chown -R username:group directory
```

If you only want to change user or group owner of file:

User:
```console
thanh-bl@thanh-bl:~$ sudo chown -R username directory
```

Group
```console
thanh-bl@thanh-bl:~$ sudo chown -R :group directory
```
## 6.
[Back to content](#content) 

**Find files that size are larger 20 MB**

```console
thanh-bl@thanh-bl:~$ sudo find <find-in-this-part> -type f -size +20M
```

## 7.
[Back to content](#content)

Write a bash file to create a text file with name is "-..log", run bash in 1 minute, create 1 file each 5 seconds.

Create a bash script with content below:

```bash
#!/bin/bash
# Get the username
USERNAME="thanh_bl"
# Function to create a log file
create_log_file() {
    TIMESTAMP=$(date +"%H%M%S - %d%m%Y")
    FILENAME="${TIMESTAMP}.${USERNAME}.log"

    # Create the file
    touch "$FILENAME"
    echo "File $FILENAME created."
}
# Run the loop for 1 minute (12 iterations, as each iteration is 5 seconds)
for i in {1..12}; do
    create_log_file
    sleep 5
done
```
Remember to update rule to file and run:

```console
root@vma:~ ls
backupSQL.sh  clean.sh  create-log.sh  getCPU.sh  log-tomcat.sh  snap  tomcat.sh
root@vma:~ ./create-log.sh
File 142735 - 22082024.thanh_bl.log created.
File 142740 - 22082024.thanh_bl.log created.
File 142745 - 22082024.thanh_bl.log created.
^C
root@vma:~ ls
'142735 - 22082024.thanh_bl.log'  '142745 - 22082024.thanh_bl.log'   clean.sh        getCPU.sh       snap
'142740 - 22082024.thanh_bl.log'   backupSQL.sh                      create-log.sh   log-tomcat.sh   tomcat.sh
```


## 9. 
[Back to content](#content) 

**Config "adm1n" to be able to use "root" privileges without password.**

adm1n@vma:/$ sudo visudo

Add line *adm1n   ALL=(ALL:ALL) NOPASSWD:ALL*

`Remember to add in the end of file`
## 10. 
[Back to content](#content)

**Setup password policy at least 8 characters, complexity required, password expiration on both**

Config parameters in **/etc/pam.d/common_password** 

```
.... pam_pwquality.so retry=3 minlen=6 minclass=1
```

Use **chage -username** for expiration password.

Use parameter like **ucredit**, **lcredit**, and **ocredit** for password complexity.

## 12. 
[Back to content](#content)

**Configure newly created users so that they do not have the right to switch to other users.**

First, we add 2 new users:
```console
root@thanh-bl:/ adduser user1
root@thanh-bl:/ adduser user2
```
Add a group name **admin_members**:
```console
root@thanh-bl:/ groupadd admin_members
```
Add user1 and user2 to this group:
root@thanh-bl:/ groupadd admin_members
```console
root@thanh-bl:/ usermod -aG admin_members user1
root@thanh-bl:/ usermod -aG admin_members user2
```
And run this command in final
```console
root@thanh-bl:/ dpkg-statoverride --update --add root adminmembers 4750 /bin/su
```
Final result:
```console
root@thanh-bl:/home/thanh-bl su user1
user1@thanh-bl:/home/thanh-bl$ su user2
Password:
user2@thanh-bl:/home/thanh-bl$ su user1
Password:
user1@thanh-bl:/home/thanh-bl$ su thanh-bl
Password:
thanh-bl@thanh-bl:~$ su user1
bash: /usr/bin/su: Permission denied
```

## 13. 
[Back to content](#content)

**Disable ssh to "adm1n" user**

In 10.0.2.4, config in **/etc/ssh/sshd_conf**, add line *DenyUsers adm1n*.
After that, we cant ssh to this user from other machine.

Remember restart sshd service:

```
adm1n@vma:/home/thanh-bl$ sudo systemctl restart sshd
```

In 10.0.2.6, we try: 

```console
root@thanh-bl:/home/thanh-bl ssh adm1n@10.0.2.4 -p7222
adm1n@10.0.2.4's password:
Permission denied, please try again.
```

Comment the line *DenyUsers adm1n* in 10.0.2.4 then try again:
```console
root@thanh-bl:/home/thanh-bl ssh adm1n@10.0.2.4 -p7222
adm1n@10.0.2.4's password:
Welcome to Ubuntu 22.04.4 LTS (GNU/Linux 5.15.0-118-generic x86_64)
....
....
$ whoami
adm1n
```

## 14. 
[Back to content](#content)

**List VM names so they can be referred to by name.**

Config in file **/etc/hosts**.

We add line *10.0.2.4 VM_A*.

Instead of using command *ssh adm1n@10.0.2.4*, we use *ssh adm1n@VM_A*.

## 18. 
[Back to content](#content)

**Configure VMs so they can connect to each other, copy files between them via "VM's name" and "d3v" user with key pair.**

Example i will try to ssh from user *d3v 10.0.2.4* to user *d3v 10.0.2.6*

First i will generate a key and use *scp* to share to *d3v 10.0.2.6*

```console
d3v@thanh-bl:~$ ssh-keygen -t rsa
Generating public/private rsa key pair.
Enter file in which to save the key (/home/d3v/.ssh/id_rsa):
Created directory '/home/d3v/.ssh'.
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /home/d3v/.ssh/id_rsa
Your public key has been saved in /home/d3v/.ssh/id_rsa.pub
The key fingerprint is:
SHA256:oXWfvBB/xKjmp3qwLUy60pXevSZ7GdkVArAdPesomes d3v@thanh-bl
The key's randomart image is:
+---[RSA 3072]----+
|         ..oo    |
|          o .* . |
|        o.o.. * .|
|       o o * +  .|
|      . S.* Bo.. |
|        =* oo+.  |
|     . * =+.oo   |
|    . o =.=o=    |
|     ...oEo=..   |
+----[SHA256]-----+
```

```console
d3v@thanh-bl:~/.ssh$ scp -P 6222 id_rsa.pub d3v@VM_B:/home/d3v/.ssh/authorized_keys
d3v@10.0.2.6's password:
id_rsa.pub                                                         100%  566   800.8KB/s   00:00

d3v@thanh-bl:~/.ssh$ ssh -i id_rsa d3v@VM_B -p6222
Welcome to Ubuntu 22.04.4 LTS (GNU/Linux 5.15.0-118-generic x86_64)
```

## 20. 
[Back to content](#content)

**Install MySQL 8.0 on machine B, configure it to be accessible from both internal and external sources.**

User list:

- 192.168.56.102: sammy password && sammy11 password1@P
- 192.168.56.103: sammy Password1@


Install mysql-client in *VM_A 10.0.2.4* and mysql-server in *VM_B 10.0.2.6*
```console
$ sudo apt install mysql-client
```
```console
$ sudo apt install mysql-server
```
In mysql-server machine:

```sql
thanh-bl@vmb:~$ sudo mysql
mysql> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sys                |
| todoweb            |
+--------------------+
5 rows in set (0.00 sec)
```



```console
$ sudo nano /etc/mysql/mysql.conf.d/mysqld.cnf
    # change bind-address: 127.0.0.1 to 0.0.0.0
$ sudo systemctl restart mysql
$ sudo mysql
```

```sql
mysql> CREATE USER 'sammy'@'10.0.2.4' IDENTIFIED BY 'password';

mysql> GRANT CREATE, ALTER, DROP, INSERT, UPDATE, DELETE, SELECT, REFERENCES, RELOAD on *.* TO 'sammy'@'<tomcat_server_ip>' WITH GRANT OPTION;

mysql> FLUSH PRIVILEGES;
```

```console
$ sudo ufw allow 10.0.2.4 to any port 3306
$ sudo ufw allow 3306
```

In mysql-client machine:
```console
$ mysql -u sammy -h 10.0.2.6 -p
Enter password:
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 11
Server version: 8.0.39-0ubuntu0.22.04.1 (Ubuntu)
```
External access success!

Same, create a user "sammy1" with host is "localhost" for internal access!

## 22.
[Back to content](#content)

Write a bash file using loop to print CPU, RAM, DISK information every 20 secs

Create a bash script with content below:

```bash
#!/bin/bash
get_system_info() {
  echo "---------------------------------------"
  echo "Timestamp: $(date)"
  echo "CPU Usage:"
  top -bn1 | grep "Cpu(s)" | \
    sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | \
    awk '{print "CPU Load: " 100 - $1"%"}'
  echo "RAM Usage:"
  free -h | awk '/^Mem/ {print "Used: "$3" / Total: "$2" | Free: "$4}'
  echo "DISK Usage:"
  df -h | awk '$NF=="/"{printf "Disk Usage: %s / %s (%s)\n", $3,$2,$5}'
  echo "---------------------------------------"
}
while true; do
    get_system_info
    sleep 20
done
```

Remember to update rule to file and run:

```console
$ ./getCPU.sh
Timestamp: Thu Aug 22 03:51:44 PM +07 2024
CPU Usage:
CPU Load: 12.5%
RAM Usage:
Used: 348Mi / Total: 3.8Gi | Free: 3.1Gi
DISK Usage:
Disk Usage: 4.2G / 9.8G (45%)
```

## 23. 
[Back to content](#content)

Write a program to check tomcat server every 2 minutes, if it down then start it

Create a bash script with content below:

```bash
#!/bin/bash
TOMCAT_SERVICE_NAME="tomcat"
check_tomcat() {
  if systemctl is-active --quiet "$TOMCAT_SERVICE_NAME"; then
    echo "$(date): TOMCAT is running."
  else
    echo "$(date): TOMCAT is down. Attempting to start..."
    systemctl start "$TOMCAT_SERVICE_NAME"
    if systemctl is-active --quiet "$TOMCAT_SERVICE_NAME"; then
      echo "$(date): TOMCAT started successfully."
    else
      echo "$(date): Failed to start TOMCAT."
    fi
  fi
}
while true; do
  check_tomcat
  sleep 5
done
```

Remember to update rule to file and run:

```console
$ ls
backupSQL.sh  clean.sh  getCPU.sh  log-tomcat.sh  snap  tomcat.sh
$ chmod 744 log-tomcat.sh
$ ./log-tomcat.sh
Thu Aug 22 02:21:57 PM +07 2024: TOMCAT is running.
Thu Aug 22 02:22:02 PM +07 2024: TOMCAT is running.
Thu Aug 22 02:22:07 PM +07 2024: TOMCAT is running.
Thu Aug 22 02:22:12 PM +07 2024: TOMCAT is down. Attempting to start...
Thu Aug 22 02:22:12 PM +07 2024: TOMCAT started successfully.
Thu Aug 22 02:22:17 PM +07 2024: TOMCAT is running.
```

## 24. 
[Back to content](#content) 

Find process that run on port 3306, kill it then start it again

List all process:

```console
$ ps -e
```

Get PID of process running on port 3306:

```console
$ sudo lsof -t -i:3306
```

## 25. 
[Back to content](#content)

**Setup log rotate for tomcat server**

What is **logrotate**?

`LogRotate is a tool on the Linux operating system used to manage log files. It helps process and store log files automatically, helping to avoid log files that are too large and clog the system. LogRotate provides a number of configuration options to manage log files such as deleting old log files, compressing outdated log files, determining the frequency of log file processing and the maximum size of log files before processing.`

Create a new logrotate for tomcat:

```console
$ nano /etc/logrotate.d/tomcat
```
Config file like below:

```bash
/home/d3v/tomcat/logs/catalina.out { (/home/d3v/tomcat/logs/catalina.out: link to tomcat log file)
    copytruncate
    daily
    rotate 7
    compress
    missingok
    size 1M
}
```

Move to tomcat log folder:

```console
$ cd /home/d3v/tomcat/logs
```

Manually logrotate by command:

```console
$ sudo logrotate -f /etc/logrotate.d/tomcat
```

After this, you better see the log file is clean:
```console
$ cat catalina.out
$ 
```

Rotate 7 means you'll keep maximum 7 compress log file.
Example for rotate mannual by hand 5 times, you'll see 5 compress file.
```console
$ sudo logrotate -f /etc/logrotate.d/tomcat
$ sudo logrotate -f /etc/logrotate.d/tomcat
$ sudo logrotate -f /etc/logrotate.d/tomcat
$ sudo logrotate -f /etc/logrotate.d/tomcat
$ sudo logrotate -f /etc/logrotate.d/tomcat
$ ls
catalina.out.1.gz  catalina.out.3.gz  catalina.out.5.gz 
catalina.out   catalina.out.2.gz  catalina.out.4.gz
```

If the number of logfile > threshold, the oldest one'll be deleted (the one with biggest ID)?

Easy way to understand how logrotate numbered compress file?

<p align="center">
  <img src="pic/logrt.png" width="1050" title="Linux File System architecture">
</p>

For better to find logrotate in the pass, using `dateext` or `dateformat -%Y-%m-%d_%H-%M-%S` to logrotate file. After that, the compress files be like:

```console
root@vma:/home/d3v/tomcat/logs# ls
catalina.out  catalina.out-2024-08-27_11-21-16.gz  catalina.out-2024-08-27_11-21-17.gz
```

## 26. 
[Back to content](#content) 

**Setup a job to run periodically to backup MySQL data every day**

In vmb, create a database name "todoweb"

Grant priviliges to user *sammy* (We created in vma in task "internal and external" access to mySQL).

```sql
mysql> CREATE DATABASE todoweb;
Query OK, 1 row affected (0.01 sec)
```

```sql
GRANT ALL PRIVILEGES ON todoweb.* TO 'sammy'@'10.0.2.4';
```


Create a bash script with content below:

```bash
USER="sammy"
PASSWORD="password"
HOST="10.0.2.6" #//database_host_ip(machine installed sql-server);
DB_NAME="todoweb" #//database_name;

#backup destination;

BACKUP_DIR="/backup_SQL"
DATE=$(date +\%H:\%M:\%S-at-%y_\%m_\%d)
BACKUP_FILE="$BACKUP_DIR/${DB_NAME}_$DATE.sql"

#create backup;
mysqldump -u $USER -p$PASSWORD -h $HOST $DB_NAME > $BACKUP_FILE --no-tablespaces
```

Test bashscript:

```console
$ ./backupSQL.sh
mysqldump: [Warning] Using a password on the command line interface can be insecure.
$ ls /backup_SQL/
todoweb_12-33-27.sql
```
Back up success!

Config to backup SQL every 1 mins, i'll use crontab:

**What is crontab?**

`Linux Crontab is a powerful utility that is used for Scheduling and Automating Tasks in Unix-like operating systems.`


```console
$ crontab -e
```
Add this line to file and save: **/1 * * * * ~/backupSQL.sh* (in backup machine)

Folder backup after 5 mins:

```console
$ ls
todoweb_10:53:01-at-24_08_23.sql  todoweb_10:56:01-at-24_08_23.sql
todoweb_10:54:01-at-24_08_23.sql  todoweb_10:57:01-at-24_08_23.sql
todoweb_10:55:01-at-24_08_23.sql
```

You can cat each SQL backup file and update SQL Database like add more content to database same time to see if we backup right or not.

## 27. 
[Back to content](#content)

`Do exactly what doc said`: [link here](https://yooloo.tistory.com/171)

Configure Tomcat in A so that it can use MySQL in B

Dowload JDBC (Java Database Connectivity)

```console
$ wget https://downloads.mysql.com/archives/get/p/3/file/mysql-connector-java_8.0.28-1debian10_all.deb
```

```console
$ dpkg -x mysql-connector-java_8.0.28-1debian10_all.deb mysql_jdbc
```

Move JDBC jar file (**its in mysql_jdbc/usr/share/java, dont move all mysql_jdbc to /tomcat/lib**) to libraries folder of tomcat server:

```console
$ sudo mv mysql-connector-java-8.0.28.jar /home/d3v/tomcat/lib
```

Create a file in /home/d3v/tomcat/webapps/ROOT name `mysql.jsp` with content below:

```jsp
<%@ page import="java.sql.*" %>
<%@ page contentType="text/html;charset=utf-8" %>
<%
  String DB_URL = "jdbc:mysql://10.0.2.6:3306/todoweb";
  String DB_USER = "sammy11";
  String DB_PASSWORD= "password1@P";
  Connection conn;
  Statement stmt;
  try {
    Class.forName("com.mysql.jdbc.Driver");
    conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD);
    stmt = conn.createStatement();
    conn.close();
    out.println("MySQL Connection Success!");
  }
  catch(Exception e){
    out.println(e);
  }
%>
```

<p align="center">
  <img src="pic/tomcat-config.png" width="650" title="Linux File System architecture">
</p>

Final result:

```console
$ curl localhost:8989/mysql.jsp
MySQL Connection Success!
```

## 28. 
[Back to content](#content)

**Set up Nginx/php on machine C and D to connect to Mysql, show simple to-do item list web page**

`Same as tomcat, do exactly what docs said:` [link here](https://www.digitalocean.com/community/tutorials/how-to-install-linux-nginx-mysql-php-lemp-stack-on-ubuntu#step-5-testing-php-with-nginx)

Config parameters in todo_list.php file:

```php
<?php
$user = "example_user";   
$password = "password";         
$database = "example_database";  
$table = "todo_list";                      

try {
  $db = new PDO("mysql:host=<mysql_server_ip>;dbname=$database", $user, $password);
  echo "<h2>TODO</h2><ol>"; 
  foreach($db->query("SELECT content FROM $table") as $row) {
    echo "<li>" . $row['content'] . "</li>";
  }
  echo "</ol>";
}catch (PDOException $e){
  print "Error!: " . $e->getMessage() . "<br/>";
  die();
}
```

Result:
```console
$ curl localhost/todo_list.php
<h2>TODO</h2><ol><li>My first important item</li><li>My first important item</li><li>My first important item</li><li>My first important item</li><li>Last thing</li></ol>
```