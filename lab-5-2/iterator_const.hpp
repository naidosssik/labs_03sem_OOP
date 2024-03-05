#include <iterator>
#include <memory>

template <class Node, class T>
class ConstIterator {
    
public: 
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = const T;
    using pointer_type = const T*;
    using reference_type = const T&;

    ConstIterator() = default;
    ConstIterator(Node* ptr) : node(ptr) {}

    Node* get() const {
        return node;
    }

    reference_type operator*() const {
        return node->value;
    }

    pointer_type operator->() {
        return &node->value;
    }

    ConstIterator& operator++() {
        node = node->next.get(); 
        return *this;
    } 

    ConstIterator operator++(int) {
        ConstIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const ConstIterator &other) {
        return node == other.node;
    }
    bool operator!=(const ConstIterator &other) { 
        return node != other.node;
    } 

private: 
    const Node* node;
};