# Implementation 1


## Function add():

### Time complexity: 
The time complexity is O(n), because each time we add a element, we iterate through the list, and insert the node at the end.

### Space complexity:
The space complexity is O(1), because we only create a new node and a pointer.



## Function check():

### Time complexity: 
The time complexity is O(n) (n = the amount of strings in the list), because we have to iterate through the list, verifying if the string in each node, is the one which we are finding

### Space complexity:
The space complexity is O(1), because we only create a pointer to iterate through the list.



# Implementation 2


## Function add():

### Time complexity: 
The time complexity is O(n) (n = the amount of strings in the list), because each time we add a element, we have to iterate through the list until we find a element bigger (in terms of strings) than the element we are adding, and the worst possible case, is when the string we are adding, is the biggest in the list, in that case, we will have to iterate every element in the list 

### Space complexity:
The space complexity is O(1), because we only create a new node and a pointer to iterate the list.


## Function check():

### Time complexity: 
The time complexity is O(n) (n = the amount of strings in the list), because we have to iterate through the list, verifying if the string in each node, is the one which we are finding

### Space complexity:
The space complexity is O(1), because we only create a pointer to iterate through the list.



# Implementation 3


## Function add():

### Time complexity: 
The time complexity is O(n) (n = the amount of characters in the string), because each time we add a element, we have to iterate through the string verifying if each character from left to right, is already created or we have to create them, and at he end, assigning true to a boolean variable that tell us where is the end of the string

### Space complexity:
The space complexity is O(n) (n = the amount of characters in the string), because we need a node for each character, so in the worst case, where the node for the first character is NULL, we have to create a node, for each character in the string 


## Function check():

### Time complexity: 
The time complexity is O(n) (n = the amount of chars in the string), because we have to iterate through each node, verifying if the node for the next chararacter is not null until we reach the final character;

### Space complexity:
The space complexity is O(1), because we only create a pointer to iterate through the list.