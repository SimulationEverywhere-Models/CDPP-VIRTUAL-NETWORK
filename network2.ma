[Top]
components : server1@server1 server2@server2 server3@server3 
out : noclients1 serverstate1 noclients3 serverstate3 noclients2 serverstate2 
in : clients1 fault command1 command3 command2 
Link : users31@server3 users31@server1
Link : users21@server2 users21@server1
Link : users12@server1 users12@server2
Link : users13@server1 users13@server3
Link : clients1 clients1@server1
Link : fault fault@server1
Link : command1 command1@server1
Link : command3 command3@server3
Link : command2 command2@server2
Link : noclients1@server1 noclients1
Link : serverstate1@server1 serverstate1
Link : noclients3@server3 noclients3
Link : serverstate3@server3 serverstate3
Link : noclients2@server2 noclients2
Link : serverstate2@server2 serverstate2

[server1]
preparation : 00:00:10:000

[server2]
preparation : 00:00:10:000

[server3]
preparation : 00:00:10:000


