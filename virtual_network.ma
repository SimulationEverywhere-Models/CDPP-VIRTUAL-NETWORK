[Top]
components : managing_console@managing_console network2 
out : serverstates noclients 
in : fault clients1 
Link : fault fault@network2
Link : clients1 clients1@network2
Link : command3@managing_console command3@network2
Link : command1@managing_console command1@network2
Link : command2@managing_console command2@network2
Link : serverstates@managing_console serverstates
Link : noclients@managing_console noclients
Link : serverstate2@network2 serverstate2@managing_console
Link : noclients3@network2 noclients3@managing_console
Link : noclients2@network2 noclients2@managing_console
Link : serverstate1@network2 serverstate1@managing_console
Link : noclients1@network2 noclients1@managing_console
Link : serverstate3@network2 serverstate3@managing_console

[managing_console]
preparation : 00:00:10:000

[network2]
components : server1@server1 server2@server2 server3@server3 
out : noclients1 serverstate1 noclients2 serverstate2 noclients3 serverstate3 
in : fault clients1 command1 command2 command3 
Link : users31@server3 users31@server1
Link : users13@server1 users13@server3
Link : users12@server1 users12@server2
Link : users21@server2 users21@server1
Link : fault fault@server1
Link : clients1 clients1@server1
Link : command1 command1@server1
Link : command2 command2@server2
Link : command3 command3@server3
Link : noclients1@server1 noclients1
Link : serverstate1@server1 serverstate1
Link : noclients2@server2 noclients2
Link : serverstate2@server2 serverstate2
Link : noclients3@server3 noclients3
Link : serverstate3@server3 serverstate3

[server1]
preparation : 00:00:10:000

[server2]
preparation : 00:00:10:000

[server3]
preparation : 00:00:10:000



