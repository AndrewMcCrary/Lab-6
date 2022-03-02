#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include "stacky.h"
#include "Queuey.h"

using namespace std;

int main(void) {

	// ifstream as a stack object taking strings with size of words in file  (make a .txt file with "sample text")
	// 
	// make a queue where each element is a stack, each stack is a word
	// idk how to do this!
	// 
	// fstream txt file
	//
	// output each stack inside the queue
	// >this outputs each stack-word flipped but in proper order

	ifstream input;
	input.open("sampleinput.txt");
	Queuey<stacky<char, 50>, 50> data;
	string buff;
	stacky<char, 50>* stackyBuff;

	getline(input, buff);
	stackyBuff = new stacky<char, 50>();
	for (int i = 0; i < buff.length(); i++) {
		if (isalpha(buff[i])) { // Chars
			stackyBuff->push(&buff[i]);
		}
		else if (isspace(buff[i])) {  // Spaces
			data.enqueue(stackyBuff);
			stackyBuff = new stacky<char, 50>();
			stackyBuff->push(&buff[i]);
			data.enqueue(stackyBuff);
			stackyBuff = new stacky<char, 50>();
		}
		else {  // Punctuation
			data.enqueue(stackyBuff);
			stackyBuff = new stacky<char, 50>();
			stackyBuff->push(&buff[i]);
			data.enqueue(stackyBuff);
			stackyBuff = new stacky<char, 50>();
		}
	}
	data.enqueue(stackyBuff);

	stacky<char, 50>* word;
	while (!data.isEmpty()) {
		word = data.dequeue();
		while (!word->isEmpty()) {
			cout << word->pop()[0];
		}
	}

	delete stackyBuff;
	return 0;
}
