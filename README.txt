README: Dictionary Dash
Author: Kathryn (Katie) Shea
Date:	July 5, 2016

Input: two words and a dictionary.

Output: number of single letter modifications needed to go from the first word
to the second word. Single letter modifications can only be made if the new
word is also a word in the dictionary.


How to run this program:
1. Unzip the folder.
2. Navigate to the executable location in the folder on the command line.
3. Type in: ./dictionary_dash [INPUT_FILE]

The following INPUT_FILEs are already available:
test0.txt
test1.txt
test2.txt
test3.txt
test4.txt
test5.txt
test6.txt
test7.txt
test8.txt
test9.txt


Additional input files can be created and should be formatted as follows:
first_word
second_word

dictionary_word_1
dictionary_word_2
...



How did you approach solving this problem?

When finding the shortest path between two objects, a breadth first search is often the simplest way to do so effectively so that’s what I’ve implemented using a queue of pairs where each pair contains a word and the distance from the start to that word. The dictionary was stored as a hash table so that look up time is, on average, constant. Another hash table was used to know which words have already been visited.


How did you check that your solution is correct?

I attempted to create as many different test cases as possible including various invalid input files as well as testing for words that don’t exist in the given dictionary. I tested empty dictionaries and dictionaries with up to (only) 500 words. I tried to break the program. Please let me know if you break it and under what conditions it breaks. I’d be curious to know how big the dictionary can get before something happens.


Specify any assumptions that you have made.

I tried my best to account for most exceptions. The problem states that the words will all be the same length and lowercase but even if they’re not I’ve put some error codes in for those cases. I suppose my code assumes the input file is in the above format but it would still run you just wouldn’t get the result you might expect I guess.

