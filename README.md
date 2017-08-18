# check_for_writers
Linux command line utility to check if a file is open for writing

### INSTALLATION

```$ make  
$ sudo make install   
```


Note that this will configure the program with CAP_LEASE, so that it can be used to check files that are not owned by the user (as long as the file is readable).


### EXAMPLE USAGE
```$ touch myfile.txt  
$ check_for_writers myfile.txt && echo "OK"  
OK  
$ cat >myfile.txt &  
[1] 4285  
$ check_for_writers myfile.txt && echo "OK"  
myfile.txt: currently open for writing  
```
