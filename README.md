# FTPserver.DoS_LREDES
Socket Application to provocate DoS of a local FTP server, with bash scripts for ports and ips scanning.

### Compiling Port Scanner and DoS Code
````
$gcc portscan.c -o portscan
$gcc DoS.c -o DoS
````

### Set
```
$chmod +x pingtest.sh
```

### Exec Scans
````
$./pingtest.sh 192.168.0
$./parseurl.sh cefetmg.br
$./portscan "192.168.1.1"
````

### Prep Server
```
$service vsftpd restart
```

### Run DoS
````
x, y: host IP
$./DoS 192.168.x.y

```` 

### Test Connection 
````
x, y: guest IP
$ftp 192.168.x.y
````

#### Resources for FTP server set up
https://linuxtiwary.com/2019/02/16/how-to-configure-ftp-server-on-kali-linux/
