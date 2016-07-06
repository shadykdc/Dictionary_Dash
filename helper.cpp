//helper.cpp
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include "errors.h"

using namespace std;

/* GLOBAL VARIABLES */
unordered_map<string, int> dictionary;	// dictionary stored as a hash table
unordered_map<string, int> visited;	// hash table of words visited during shortest_path()
const int ALPHA_SIZE = 26;
const char alphabet[ALPHA_SIZE] = {'a','b','c','d','e','f','g','h','i','j','k',
								   'l','m','n','o','p','q','r','s','t','u','v',
								   'w','x','y','z'};


/* HELPER FUNCTIONS */
bool word_in_dictionary(string word){
	unordered_map<string, int>::const_iterator it = dictionary.find(word);
	if (it == dictionary.end()){
		return false;
	}
	return true;
}


bool visited_word(string word){
	unordered_map<string, int>::const_iterator it = visited.find(word);
	if (it == visited.end()){
		return false;
	}
	return true;
}


void import_dictionary(istream &in_stream){
	string word;
	unordered_map<string, int>::hasher fn = dictionary.hash_function();
	
	while (in_stream >> word){
		if (!word_in_dictionary(word)){
			pair<string, int> new_item (word, fn(word));
			dictionary.insert(dictionary.begin(), new_item);
    	}
	}
	return;
}


int shortest_path(string first_word, string second_word){
    
	/*	each pair (node) contains a string (a word in the dictionary) and an
		integer (distance from first_word to that word) */
	pair<string,int> current_node (first_word, 0);
	    
	int length = -1;	
	string new_word;
	queue< pair<string,int> > q;
	q.push(current_node);
	  
	unordered_map<string, int>::hasher fn = visited.hash_function();
	pair<string, int> first_item (first_word, fn(first_word));
	visited.insert(dictionary.begin(), first_item);
    
    /* breadth-first-search */
	while(!q.empty()){
		current_node = q.front();
	    if (current_node.first == second_word){
	        length = current_node.second;
	        return length;
	    }
	    for (int i = 0; i < (int)current_node.first.length(); i++){
	      	for (int j = 0; j < ALPHA_SIZE; j++){
		        new_word = current_node.first;
		        new_word[i] = alphabet[j];
		        if (new_word == current_node.first){
		           	continue;
		        }
		        if (word_in_dictionary(new_word) && !visited_word(new_word)){
		         	pair<string,int> new_node (new_word, current_node.second+1);
		           	pair<string, int> visited_item (new_word, fn(new_word));
					visited.insert(dictionary.begin(), visited_item);
		           	q.push(new_node);
			    }
			}
		}
        q.pop();
    }
    return length;
}


int check_input_file(string first_word, string second_word){
	
	for (int i = 0; i < (int)first_word.length(); i++){
		if (!islower(first_word[i])){
			cerr << first_word << " contains invalid characters." << endl;
			return WORD_IS_NOT_VALID;
		}
	}
    	
	for (int i = 0; i < (int)second_word.length(); i++){
		if (!islower(second_word[i])){
			cerr << second_word << " contains invalid characters." << endl;
			return WORD_IS_NOT_VALID;
		}
	}
	
	if (!word_in_dictionary(first_word)){
		cerr << first_word << " is not in the provided dictionary." << endl;
		return WORD_IS_NOT_IN_DICTIONARY;
	}
    	
	if (!word_in_dictionary(second_word)){
		cerr << second_word << " is not in the provided dictionary." << endl;
		return WORD_IS_NOT_IN_DICTIONARY;
	}
    	
	if (first_word.length() != second_word.length()){
		cerr << first_word << " and " << second_word << " are not the same length." << endl;
		return WORDS_ARE_NOT_THE_SAME_LENGTH;
	}

	return NO_ERROR;
}
