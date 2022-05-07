[Top]
components : managing_console@managing_console 
out : command1 serverstate noclients command2 command3 
in : noclients1 serverstate1 noclients2 serverstate3 noclients3 serverstate2 
Link : noclients1 noclients1@managing_console
Link : serverstate1 serverstate1@managing_console
Link : command1@managing_console command1
Link : noclients@managing_console noclients
Link : serverstates@managing_console serverstate
Link : noclients2 noclients2@managing_console
Link : noclients3 noclients3@managing_console
Link : serverstate3 serverstate3@managing_console
Link : serverstate2 serverstate2@managing_console
Link : command2@managing_console command2
Link : command3@managing_console command3

[managing_console]
preparation : 00:00:10:000


