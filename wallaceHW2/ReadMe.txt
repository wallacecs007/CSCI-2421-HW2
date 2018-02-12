========================================================================
    Data Structures Homework 2: ArrayBags
========================================================================
Programmer: Chase Wallace

Class: 2421

Worked on: 2/6/2018, 2/7/2018, 2/8/2018

IDE's: Atom, VisualStudios

Compile Status: Compiles and runs on visual studios, also compiles
and runs on CSEGrid

========================================================================

Program Description: Was given a .cpp and .h that include the data
structure "ArrayBags." The goal of this assignment was to overload
and create functions for the + and - operators. In this event, I
overloaded the + operator to add two array bags together and then
eliminate the duplicates.
Then I took the - operator and overloaded it to find take away any
numbers that are in common from the first array to the second array
and display the remaining from the first array.

And while this next one was not required, I overloaded the <<
operator to print out the contents of the ArrayBags in order seperated
by spaces.

=========================================================================

When programming this I encounted a few issues, during which I managed
to solve majority on my own, but I went to stack overflow for one
occassion. This was for the String Stream (SS) operator which allowed me
to seperate a string at every space. I used this as I was having
issues seperating the line once I used getline. Using SS I managed
to break up the two lines in the file into two seperate strings
and then those strings into individual items to push into the arraybags.

https://stackoverflow.com/questions/29441675/splitting-strings-separately-by-line-and-by-blank-space-using-getline