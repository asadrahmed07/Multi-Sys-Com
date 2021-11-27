# Multi-Sys-Com (MSC) 

This is a pseudo software implementation of Modern Day messaging app such as Whatsapp .
Here i have tried to solve those fundamental real-life problem statements that a system can face while communicating with other systems.

How My program works

Do the following steps :
1: Open eui.c and prc.c in two different terminals.
2: run both executables ./a.out
3: You will notice a menu With asking for your choice .
4: After Entering choice.. Before pressing 1 for continue .Go to prc.c terminal and press 1 .
5: It will show your choice then insert or modify or delete from there then .
6: Before pressing 1 for continuing for next round Come back to eui.c and press 1 .
7: If you have inserted a record into the Dbfile then it will show you the last intserted file as the output Step 1 will repeat.
8: as There are also instructions in the program which will help you to navigate.



my database is stored like this if you insert these files and then choose to view database 
you will get this as a output.
-------------------------------------------

121	sys1
122	sys2
123	sys3
124	sys4

-------------------------------------------


Problems i solved :
-----------------
1.  As in my previous submition there was no prc.c . I have made prc.c , eui2prc.txt , prc2eui.txt and tried to communicate between them through files.

2.  My second challenge was to make prc.c to run and receive infinitely so i did that by putting in a loop
    and then i made a condition that i want to continue or not.

3.  As im still solving some issues and but im able to communicate eui and prc through files ONLY.

4.  Database Display is a tough one if want to put database into prc2eui.txt and then show in eui.c But i solve this problem through making a function which will     directly read the database from dbfile and showcase it.

5.  AS inserting a record is working perfectly.
6.  Afer insertion i have tried several other features like:

 =>  Search by portNumber 
 =>  Search by System Name
 =>  Modify record

Issues i have been facing :
=============================
 1}  For some reason these operation works only for the lastest entry that was last entered. and not for the rest of 
     of the database im still solving that issue.
 2}  There is small problem in file handling where the prc.c read the input from the eui2prc.txt that actions cannot be stored permanently.
 
