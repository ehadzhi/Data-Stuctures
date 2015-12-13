/*
 * UALDictionary.h
 *	UALD - Unsorted array-based list dictionary
 *  Created on: Dec 13, 2015
 *      Author: erolh
 */

#ifndef UALDICTIONARY_H_
#define UALDICTIONARY_H_

#include"KeyValPair.h"
#include"AList.h"

template<typename Key, typename Elem>
class UALDictionary {
	AList<KeyValPair<Key, Elem>>* list;
public:
	UALDictionary();
	~UALDictionary();
	void clear();
	void insert(const Key& k, const Elem& elem);
	bool remove(const Key& k, Elem& e);
	Elem removeAny();
	bool find(const Key& key, Elem& elem) const;
	int size();
};

template<typename Key, typename Elem>
inline UALDictionary<Key, Elem>::UALDictionary() {
	list = new AList<KeyValPair<Key, Elem>>();
}

template<typename Key, typename Elem>
inline UALDictionary<Key, Elem>::~UALDictionary() {
	delete list;
}

template<typename Key, typename Elem>
inline void UALDictionary<Key, Elem>::clear() {
	list->clear();
}

template<typename Key, typename Elem>
inline void UALDictionary<Key, Elem>::insert(const Key& k, const Elem& elem) {
	list->append(KeyValPair<Key, Elem>(k, elem));
}

template<typename Key, typename Elem>
inline bool UALDictionary<Key, Elem>::remove(const Key& key, Elem& elem) {
	if( find(key,elem)){
		KeyValPair<Key,Elem> temp = list->getValue();
		elem = temp.getElem();
		list->remove();
		return true;
	}
	return false;
}

template<typename Key, typename Elem>
inline Elem UALDictionary<Key, Elem>::removeAny() {
	list->moveToEnd();
	KeyValPair<Key, Elem> temp = list->getValue();
	Elem tempEl = temp.getElem();
	list->remove();
	return tempEl;
}

template<typename Key, typename Elem>
inline bool UALDictionary<Key, Elem>::find(const Key& key, Elem& elem) const {
	list->moveToStart();

	KeyValPair<Key, Elem> temp;
	while (list->lengthAfter() > 0) {
		temp = list->getValue();
		if (temp.getKey() == key) {
			elem = temp.getElem();
			return true;
		}
		list->next();
	}
	return false;
}

template<typename Key, typename Elem>
inline int UALDictionary<Key, Elem>::size() {
	return list->length();
}

#endif /* UALDICTIONARY_H_ */
