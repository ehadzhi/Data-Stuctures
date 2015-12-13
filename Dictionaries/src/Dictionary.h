/*
 * Dictionary.h
 * Dictionary ADT
 *  Created on: Dec 13, 2015
 *      Author: erolh
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

// The Dictionary abstract class.
template<typename Key, typename Elem>
class Dictionary {
private:
	void operator =(const Dictionary&) {
	}
	Dictionary(const Dictionary&) {
	}
public:
	Dictionary() {
	}
	virtual ~Dictionary() {
	}

	// Reinitialize dictionary
	virtual void clear() = 0;

	// Insert into the dictionary.
	virtual void insert(const Key& k, const Elem& elem) = 0;

	// Remove some record with key "k" and return it in "e".
	// Return true if such exists, false otherwise.
	// If multiple records match "k", remove an arbitrary one.
	virtual bool remove(const Key& k, Elem& e) = 0;

	// Remove and return an arbitrary record from dictionary.
	virtual Elem removeAny() = 0;

	// Return a copy in elem of some record matching key.
	// Return true if such exists, false otherwise. If
	// multiple records match key, return an arbitrary one.
	virtual bool find(const Key& key, Elem& elem) const = 0;

	// Return the number of records in the dictionary.
	virtual int size() = 0;
};
#endif /* DICTIONARY_H_ */
