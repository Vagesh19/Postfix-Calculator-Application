# Postfix-Calculator-Application
Course Project (COL106) under Prof. Subodh Sharma [August 2023] : Designed a robust calculator app using various stack implementations, object-oriented programming principles, expression tokenization, post-fix notation evaluation, and strong error handling
# Types of Stack Implementation
stack_a : via fixed size arrays,

stack_b : via dynamic arrays,

stack_c : via linked lists
# Commands Explanation
Let’s walk through each of the command one-by-one.
1) Insert
1 {set num} {data}
This command will have 2 arguments. The set num indicates which set needs
to be operated on (if set with this number does not exist already, then create
it). ”data” indicates the data to be inserted into the set. Remember that after
the insertion of data, the set properties must hold - specifically, the set should
have unique elements in sorted order
2) Delete
2 {set num} {data}
Similar to insert. In this case, if set with this number does not exist, return
-1. One thing to note here is that - if the data to be deleted does not exist in
the set, then do nothing and just print the original size of the set.
3) Belongs To
3 {set num} {data}
Check if the element ”data” belongs to the set ”set num”. If set does not
exist, return -1. Return 1 if it belongs, else return 0.
4) Union
4 {set num1} {set num2}
Note that you need to store the result of union operation in set num1
(This means that set num2 will remain unchanged, unless set num1 is same
as set num2). Ensure that the set properties hold even after union. If either of
the sets doesn’t exist - create them.
5) Intersection
5 {set num1} {set num2}
Similar instructions as Union.
6) Size
6 {set num}
If set doesn’t exist, create and return 0.
7) Difference
7 {set num1} {set num2}
If either of the sets doesn’t exist, create it. Store the result in set num1.
(Again, don’t modify set num2)
8) Symmetric Difference
8 {set num1} {set num2}
Instructions similar to Difference.
9) Print
4 {set num}
Given the set number, print all its elements as comma-separated values. Do
*not* include any whitespaces (Just include a linebreak at the end). Should
Look Like -
1, 2, 3, 5, 7
If the set does not exist, just print a linebreak.
