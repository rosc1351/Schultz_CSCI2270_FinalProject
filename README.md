# Schultz_CSCI2270_FinalProject
# Reccomend Friends

## Structures

### Linked List

Handles File io using split()

Stores list of friends in suggestfriends()

### Graph

Stores user as nodes and friendships as edges

Includes linked list (LLString)

### Reccomender

Handels all user input:

login()

logout()

displayfriends()

countfriends()

addfriend()

removefriend()

suggestfriends()



## Further Implementation:
When suggesting friends, names are printed using a "pseudo-hardcode" method.  This is becuase the data is being stored in a singally linked list.  Converting this data to an array or doublly linked list would make sorting both easier and compulationally faster.

Friend Requests.  Currently, friends are added in one direction when added by the user.  Add a feature that queues a request for the new friend to add the user back.

General Algorithm Improvement.  In production of this project, the primary focus was functionality.  Some algoritms are not very efficient and can use revision.

Save  data.  Any new friends made durring the session is thrown out after exiting the program.  Add functionality to save the data so we can return to it at a later time.

The file format is fine if being read by a computer, but can be tough for human readers

By setting the weight of a friendship based on number of interactions, familial relationship, along with other factors, suggesting friends to the user could become more accurate.

Security.  Users do not have passwords and the database of users is unsecure!
