#include <iterator>
#include <memory>

template <class Node, class T>
class Iterator {

public: 
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    //using pointer_type = T*;
    //using reference_type = T&;

    Iterator() = default;
    Iterator(Node* ptr) : node(ptr) {}

    Node* get() const {
        return node;
    }

    T& operator*() const {
        return node->data;
    }

    T* operator->() {
        return &node->data;
    }

    Iterator& operator++() {
        node = node->next.get(); 
        return *this;
    } 

    Iterator operator++(int) {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const Iterator &other) {
        return node == other.node;
    }
    bool operator!=(const Iterator &other) { 
        return node != other.node;
    } 
    
private: 
    Node* node;
};