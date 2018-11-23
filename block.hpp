#ifndef LIST_H
#define LIST_H

#include <cstdlib>
#include <cassert>
#include <iosfwd>

template<class T>
class Block {
private:
    T* _block;
    size_t _size;
    size_t _ind;

    Block<T> *prevs, *nexts;
public:
    Block(size_t size, size_t ind);
    Block(Block<T>* block);
    ~Block();

    T& getElement(size_t index);

    void push_back(const T& x);
    void pop_back();

    size_t getSize() const;
    size_t getIndex() const;

    template<class K> friend class List;
};

template<class T>
Block<T>::Block(size_t size, size_t ind) : prevs(NULL), nexts(NULL) {
    _size = size;
    _block = new T[size];
    _ind = ind;
}

template<class T>
T& Block<T>::getElement(size_t index) {
    return _block[index];
}

template<class T>
Block<T>::Block(Block<T>* block) {
    _size = block->getSize();
    _ind = block->getIndex();

    _block = new T[_size];

    for (size_t i = 0; i < _ind; ++i) {
        _block[i] = block->getElement(i);
    }
}

template<class T>
void Block<T>::push_back(const T& x) {
    _block[_ind] = x;
    _ind++;
}

template<class T>
void Block<T>::pop_back() {
    _ind--;
}

template<class T>
size_t Block<T>::getSize() const {
    return _size;
}

template<class T>
size_t Block<T>::getIndex() const {
    return _ind;
}

template<class T>
Block<T>::~Block() {
    delete[] _block;
}


//////////////////////////////////////////////////////////////////////////////////////


template<class T>
class List {
private:
    static const size_t BLOCK_SIZE;
    Block<T> *_head, *_tail;
    size_t _size;

    void _push_back(Block<T>* block);
public:
    List();
    List(const List<T> &l);
    List(const T *array, const size_t n);
    ~List();

    size_t length() const;

    T& operator[](size_t index) const;
    List<T>& operator+ (const List<T>& x); ////// СДЕЛАТЬЬЬЬЬ
    List<T>& operator+= (const T& x);
    List<T>& opertor-= ();
    template <class T2> friend std::ostream &operator<<(std::ostream& out, const List<T2>& a);

    void push_back(const T& x);
    void pop_back();
    void sorti();
    void Clear();

    template<class K> friend class Block;
};

template<class T>
const size_t List<T>::BLOCK_SIZE = 5;

template<class T>
List<T>::List() {
    _head = new Block<T>(List<T>::BLOCK_SIZE, 0);
    _tail = _head;
    _size = 0;
}

template<class T>
List<T>::List(const List<T>& a) {
    Block<T> *p = a._head;

    _head = new Block<T>(p);
    _tail = _head;
    _size = a._head->getIndex();

    p = p->nexts;

    while (p != NULL) {
        _push_back(new Block<T>(p));
        p = p->nexts;
    }
}

template<class T>
List<T>::List(const T *arr, const size_t n) {
    _head = new Block<T>(List<T>::BLOCK_SIZE, 0);
    _tail = _head;
    _size = 0;

    for (size_t i = 0; i < n; i++) {
        push_back(arr[i]);
    }
}

template<class T>
List<T>& List<T>::operator+=(const T& x) {
    this->push_back(x);
    return *this;
}

template<class T>
List<T>& List<T>::operator-=() {
    this->pop_back();
    return *this;
}

template<class T>
List<T>& List<T>::operator+ (const List<T>& a) {
	for (size_t i = 0; i < a._size; i++) {
		this->push_back(a[i]);
	}	
	return *this;
}

// get element non-const
template<class T>
T& List<T>::operator[](size_t index) const {
    Block<T> *cur_block = _head;

    size_t pos = index % cur_block->getSize();
    size_t block_index = index / cur_block->getSize();

    for (int i = 0; (i != block_index && cur_block != NULL); ++i)
        cur_block = cur_block->nexts;

    assert(cur_block != NULL);
    return cur_block->getElement(pos);
}

// get size
template<class T>
size_t List<T>::length() const {
    return _size;
}

template<class T>
void List<T>::push_back(const T& x) {
    if (_tail->getSize() == _tail->getIndex()) {
        Block<T> *new_block = new Block<T>(List<T>::BLOCK_SIZE, 0);

        new_block->prevs = _tail;
        _tail->nexts = new_block;

        _tail = new_block;
    }

    _tail->push_back(x);
    _size++;
}

template<class T>
void List<T>::pop_back() {
    assert(length() != 0);

    _tail->pop_back();
    if (_tail->getIndex() == 0 && _head != _tail) {
        Block<T> *p = _tail;
        _tail = _tail->prevs;

        delete p;
    }
    _size--;
}


template<class T>
void List<T>::_push_back(Block<T> *block) {
    _tail->nexts = block;

    block->prevs = _tail;
    block->nexts = NULL;

    _tail = block;

    _size += block->getIndex();
}


template <class T>
std::ostream &operator<<(std::ostream& out, const List<T>& a) {
    for (size_t i = 0; i < a._size(); i++) {
        out << a[i] << " ";
    }
    return out;
}

template <class T>
void List<T>::Clear () {
    Block<T> *X = _head.nexts;
    while (X != &_tail) { X = X->nexts; delete X->prevs; }
    _tail = _head = &_head;
    _size = 0;
    return;
}

template<class T>
void List<T>:: sorti() {
	size_t n = _size;
	T* tmp[n];
	
	for (size_t i; i < n; i++) {
		tmp[i] = this[i];
	}
	T p;
	
    for (size_t i = 0; i < n; i++) {
    	for (size_t j = i; j < n; j++) {
    		if (tmp[j] > tmp[i]) {
    			p = tmp[i];
    			tmp[i] = tmp[j];
    			tmp[j] = p;
			}
		}
	}
	
    this->Clear();
    for (size_t i = 0; i < n; i++) {
    	this->push_back(tmp[i]);
	}
    
    return;
}

template<class T>
List<T>::~List() {
    Block<T>* nows = _head;

    while (nows != NULL) {
        Block<T>* p = nows;
        nows = nows->nexts;

        delete p;
    }
}


#endif // LIST_H
