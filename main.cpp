//main.cpp
#include <fstream>
#include <iostream>
#include <string>
#include "errors.h"
#include "helper.h"

using namespace std;

int main(int argc, char **argv){
    
    string first_word, second_word;
    ifstream in_stream;
    	
    if (argv[1] != NULL){
    	in_stream.open(argv[1]);
    }
    else {
    	cerr << endl << "User has not provided an input file argument." << endl;
    	cerr << "Try typing ./dictionary_dash test0.txt" << endl << endl;
    	return NO_INPUT_FILE;
    }
    
    in_stream >> first_word >> second_word;
    
    if (first_word.empty()){
    		cerr << "Input file is blank." << endl;
    		return NO_INPUT_FILE;
    }
    
    import_dictionary(in_stream);
    in_stream.close();
    
    int error = check_input_file(first_word, second_word);
    if (error > 0){
    		return error;
    }
    
    int length = shortest_path(first_word, second_word);
    
    if (length != -1){
        cout << "The shortest distance from " << first_word << " to " <<
        second_word << " is " << length << " word(s)." << endl;
    }
    else {
        cout << "No path was found between " << first_word << " and "
        << second_word << " using this dictionary." << endl;
    }
    
    return NO_ERROR;
}
