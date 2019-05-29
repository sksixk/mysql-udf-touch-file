drop function if exists touch_file;
create function touch_file returns int SONAME 'lib_touch_file.so';

