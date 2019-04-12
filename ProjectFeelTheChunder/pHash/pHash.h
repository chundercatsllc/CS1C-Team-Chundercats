#ifndef __PHASH_H__
#define __PHASH_H__
#include <string>
using namespace std;

class pHash{
	private:
		string hash;						// The Hashed value.
	public:
		void saveHash(string &plainPass);	// Creates and saves a hash of the value passed in.
											// Also clears the value passed in for security purposes.
											
		bool checkHash(string &plainPass);	// Hashes value passed in and checks it against "hash". Returns true or false.
		
		pHash();							// Sets "hash" to '\0'.
		pHash(string x);					// Sets "hash" to x (x should be already hashed).
};

#endif