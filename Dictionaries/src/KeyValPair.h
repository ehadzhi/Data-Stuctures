/*
 * KeyValPair.h
 *
 *  Created on: Dec 13, 2015
 *      Author: erolh
 */

#ifndef KEYVALPAIR_H_
#define KEYVALPAIR_H_

template<typename Key, typename Elem>
class KeyValPair {
	Key key;
	Elem elem;
public:
	KeyValPair() {
	}
	KeyValPair(Key key, Elem elem) :
			key(key), elem(elem) {
	}

	KeyValPair(const KeyValPair<Key, Elem>& otherPair) :
			KeyValPair(otherPair.key, otherPair.elem) {
	}

	KeyValPair& operator=(const KeyValPair<Key, Elem>& otherPair) {
		if (this != &otherPair) {
			this->elem = otherPair.elem;
			this->key = otherPair.key;
		}
		return *this;
	}

	Elem getElem() const {
		return elem;
	}

	Key getKey() const {
		return key;
	}

	void setKey(Key key) {
		this->key = key;
	}
};

#endif /* KEYVALPAIR_H_ */
