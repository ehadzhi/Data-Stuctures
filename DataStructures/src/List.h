/*
 * List.h
 *
 *  Created on: Dec 7, 2015
 *      Author: erolh
 */

#ifndef LIST_H_
#define LIST_H_

template<typename Elem>
class List {							// List ADT
public:
	List() {}
	//List(const List&) {}
	//void operator=(const List&) {}
	virtual ~List() {}

	virtual void clear() =0;			// Remove all elements
	virtual bool insert(const Elem&) =0;// Insert in current position. True if successful
	virtual bool append(const Elem&) =0;// Insert at end. True if successful
	virtual Elem remove() =0;			// Remove and return current element

	virtual void moveToStart() =0;		// Current position set
	virtual void moveToEnd() =0;		//
	virtual void moveToPos(int pos) =0;	//
	virtual void next() =0;				// Current position increment, if last no change
	virtual void prev() =0;				// Pos decrement, if first no change

	virtual Elem getValue() const =0;	// Return value of current position element

	virtual int length() const =0;		// Number of elements
	virtual int lengthBefore() const =0;// Number of elements before current
	virtual int lengthAfter() const =0;	// Number of elements after current + 1
};

#endif /* LIST_H_ */
