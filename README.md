# Schultz_CSCI2270_FinalProject
# Reccomend Friends

## Project Summary

The Friend reccomendation system stores data about friends and anylizes relationships to suggest users that the current user might know.

## Dependencies and System Requirements

Uses only standard libraries or functions defined in project files.

System Requirements:

    Compile and Run C++ files

## Structures

### Linked List

Handles File IO using split()

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

## Suggestfriends() Algorithm

### Current Implementaiton

Suggestfriends() works by finding the most common friends of friends.  Because the suggested user is only 1 node away from the user, the likelyhood of the user actually knowing the suggested user is high, however the algorithm is reliant on already having a network of friends.  New users will not find this algorithm helpful.

### Alternatives

If the weight of the edge connecting 2 nodes is inversely proportional to the strength of the friendship (based on number of interactions, family relationships, etc), Dijkstra's algorithm to improve the suggestfriends() algorithm.  This method can quantify the likelyhood of ANY 2 users knowing each other based on the distance between them.

## File IO Format

[user1],[user2],[user3]...

[user1],[friend1],[friend2]...

[user2],[friend1]...

...


## Future Implementation:

### Data Structures/Efficiency

In production of this project, the primary focus was functionality.  Some algoritms are not very efficient and can use revision and better data structures for the specific task.

### Friend Requests

Currently, friends are added in one direction when added by the user (the graph is directional).
Add a feature that queues a request for the new friend to add the user back.

### Save

Any new friends made durring the session is thrown out after exiting the program.  Add functionality to save the data so we can return to it at a later time.

### File Format
The file format is fine if being read by a computer, but can be tough for human readers

### Security

Security.  Users do not have passwords and the database of users is unsecure!


# Example Input

    File.txt //Filename

    1 //Login

    Donald Trump //Username

    3 //Display Friends

    2 //Suggest Friends

    0 //Exit list

    1 //Add Friend

    Barack Obama

    2 //Suggest Friends

    4 //Count Friends

    5 //Remove Friend

    Russia

    4 //Count Friends

    6 //Log out

    2 //Quit

