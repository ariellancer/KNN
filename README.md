# ass_4
Advanced programming project. The fourth exercise in the course, we were asked to implement a server that runs the KNN algorithm for several clients at the same time according to the number of neighbors and the distance calculation method provided by the client (as we will explain later there is a default value that the client can choose to change). The "flow" of the program is as follows: the server is initialized at the beginning of the program with the port number of the client. Now the server will send the menu to the client and the user can choose an option from the menu.
Option 1: The user will enter a path to his local CSV file, the client will send the contents of the file to the server (the file is the "classified" vectors). The server will then send back to the client that the UPLOAD is complete. Then the process will repeat for a path to the unclassified vector file.
Option 2: The server will send the current classifier parameter values which are the K parameter value and the current distance metric. The customer can now choose to change the K value and the distance metric or leave it unchanged.
Option 3: The server will run the algorithm on the CSV files uploaded earlier.
Option 4: The server will return the list of classifications.
Option 5: The behavior will be similar to that of option 4, except that instead of printing the results, the user will enter a path to create the file locally and there the client will save the results (the writing process reads in a separate THREAD).
Option 8: The interaction between the server and the client will end.
In any of the options, entering an invalid value or requesting an action before its time will result in an error acknowledgment being printed.

We implemented the program according to the Command design template.

# files: 
client, server


# What it does:
The program knows for each client to receive two files, "classified" and "unclassified".
Run the KNN algorithms for the unclassified file to classify them.
And according to the customer's choice, Print the classification for him or write them to a file

# Arguments:
server-We make sure that the path of the file is valid and that the port is a valid port.
client-We make sure that the IP is valid and is the Ip of the server and that the port is a valid port and the right 
port.

# Input:
As I detailed above
After connecting, the server sends the client a menu, the client prints it on the screen
And in each of the options it waits for a different input
1: Path to the classified file and then to the unclassified file.
2: A positive integer for K and a valid distance metric.
3, 4, 5, 8: no input.


# How to compile:
Open a terminal type 'make' in the command line, witch will compile the project.


In order to clean the exe and o files type 'make clean' in command line.

# How to run:
Open two terminals, on one of the terminals run the server with the command "./server.out port". after that on the second terminal run the client with the
command "./client.out IP port"-were the IP is the IP of the computer where the server is on, and the port is the number 
of port which the server is listening on. Then the client is waiting for an input from the user.
