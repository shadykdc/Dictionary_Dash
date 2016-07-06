//helper.h
#ifndef HELPER_H
#define HELPER_H

using namespace std;

bool word_in_dictionary(string word);
/* returns true if the word is in the dictionary provided */

bool visited_word(string word);
/* returns true if a word has already been visited during shortest_path() */

int import_dictionary(istream &in_stream);
/* imports the dictionary from &in_stream and adds each word to a hashtable */

int shortest_path(string first_word, string second_word);
/* a breadth-first-search function that returns the number of individual letter 
changes required to get from first_word to second_word with only valid words in
between; returns -1 if there is no such path. */

int check_input_file(string first_word, string second_word);
/* checks if the input file is valid */

#endif
