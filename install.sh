#!/bin/bash

echo "Compiling the MySQL UDF"
make

if test $? -ne 0; then
	echo "ERROR: You need libmysqlclient development software installed "
	echo "to be able to compile this UDF, on Debian/Ubuntu just run:"
	echo "apt-get install libmysqlclient15-dev"
	exit 1
else
	echo "MySQL UDF compiled successfully"
fi

echo -e "\nPlease provide your MySQL root password"

/usr/local/mysql/bin/mysql -u root -p mysql < lib_touch_file.sql

if test $? -ne 0; then
	echo "ERROR: unable to install the UDF"
	exit 1
else
	echo "MySQL UDF installed successfully"
fi
