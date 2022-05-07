[Top]
components : server1@server1 
out : serverstate1 noclients1 users12 users13 
in : clients1 fault command1 users21 users31 
Link : command1 command1@server1
Link : clients1 clients1@server1
Link : fault fault@server1
Link : noclients1@server1 noclients1
Link : serverstate1@server1 serverstate1
Link : users12@server1 users12
Link : users21 users21@server1
Link : users13@server1 users13
Link : users31 users31@server1

[server1]
preparation : 00:00:10:000


