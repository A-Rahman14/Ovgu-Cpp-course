#pragma once

#include <cstdint>
#include <utility>
#include <iostream>
#include <initializer_list>
#include <cstddef>

/*
 * ToDo:
 *   * Make a template out of ForwardList. What template parameter(s) do you
 *     need?
 *   * Add data members to the classes if necessary
 *   * Implement all functions
 *   * Test your solution in main.cpp
 */

namespace a08
{
    /**
 * This class represents a linked list. It supports constant time insertion and
 * removal of elements anywhere in the list.
 */
    template <typename T>
    class ForwardList
    {
        /**
     * This internal class represents a node of the linked list holding a data
     * member and a pointer to the next element. It is in the private part of
     * the class because it is an implementation detail that is not part of the
     * class's public interface.
     */

        struct Node
        {
            /// Constructs a Node from a data value and a link to the next element.
            Node(const T &data, Node *next) : data{data}, next{next} {}

            /// A Node owns all nodes after it, so it deletes them on destruction
            ~Node()
            {
                delete next;
            }

            // void set_next(Node<T> *Node)
            // {
            //     this->next = Node;
            // }

            Node *clone() const
            {
                if (next == nullptr)
                {
                    return new Node{data, nullptr};
                }
                else
                {
                    return new Node{data, next->clone()};
                }
            }

            T data;
            Node *next;
        };

        using node = Node;
        using node_pointer = Node *;

    public:
        /**
     * This class represents an iterator on the ForwardList. It implements the
     * basic operations needed for an iterator, namely incrementation,
     * dereferencing and comparison. Note that to conform to the requirements
     * the STL has for iterators we would also have to provide some special
     * member typedefs. However, our Iterator is sufficient to work with a range
     * for loop.
     */
        using value_type = T;
        using pointer_type = T *;
        using reference_type = T &;

        class Iterator
        {
        public:
            /// Dereference the iterator. Returns a reference to the data element
            /// stored at the current position in the list. If the iterator does not
            /// point to a valid node, the behavior is undefined.
            T &operator*()
            {
                return _node->data;
            }

            /// Pre-increment (++it). Advances the iterator to the next element
            /// and returns the modified iterator. If the iterator does not
            /// point to a valid node, the behavior is undefined.
            Iterator &operator++()
            {
                if (_node)
                {
                    _node = _node->next;
                }
                //return this->node.data;

                return *this;
            }

            /// Post-increment (it++). Advances the iterator to the next element
            /// and returns a copy of the previous iterator. If the iterator does not
            /// point to a valid node, the behavior is undefined.
            Iterator operator++(int)
            {
                Iterator temp(_node);
                operator++();
                return temp;
            }

            /// Returns true if two iterators refer to the same elements in the list.
            bool operator==(const Iterator &other) const
            {
                return _node == other._node;
            }

            /// Returns true if two iterators do not refer to the same element.
            bool operator!=(const Iterator &other) const
            {
                return _node != other._node;
            }

        private:
            /// The constructor of iterator is private and ForwardList is listed
            /// as a friend. This means that only ForwardList can construct new
            /// instances of its Iterator class and users of ForwardList can not
            /// create iterators to random locations.
            friend class ForwardList<T>;
            Iterator(Node *new_node) : _node(new_node)
            {
            }

            // ToDo: Data member(s)?
            Node *_node;
        };

        /// Default constructor creates an empty list
        ForwardList()
            : head(nullptr), tail(nullptr), _size(0)
        {
        }
        /// Copy constructor performs a deep copy of the other list's Nodes
        ForwardList(const ForwardList &other)
            : head(nullptr), tail(nullptr), _size(0)
        {
            node_pointer i = nullptr;
            node_pointer temp;
            while (i != other.head)
            {
                temp = other.head;
                while (temp->next != i)
                {
                    temp = temp->next;
                }
                this->push_front(temp->data);
                i = temp;
            }

            temp = nullptr;
            i = nullptr;
        }
        /// Destructor makes sure that all Nodes are correctly destroyed
        ~ForwardList()
        {
            //clear();
            // head = nullptr;
            // tail = nullptr;
            delete head;
            _size = 0;
        }

        /// Copy assignment operator uses the copy-and-swap idiom to make a safe
        /// assignment
        ForwardList &operator=(ForwardList other)
        {
            if (this == &other)
                return *this;

            head = nullptr;
            tail = nullptr;
            _size = 0;
            swap(other);

            return *this;
        }

        /// Return an iterator to the first element of the list
        Iterator begin() const
        {
            return Iterator(this->head);
        }

        /// Return an iterator to one-past-the-end of the list. A common trick for
        /// non-contiguous containers like this to represent a one-past-the-end
        /// iterator is to return an iterator holding a nullptr internally.
        /// Dereferencing or incrementing the iterator returned by end() is undefined
        /// behavior.
        Iterator end() const
        {
            return Iterator(nullptr);
        }

        /// Add an element to the front of the list.
        void push_front(const T value) //&value
        {
            Node *p = new Node{value, this->head};
            // if (head == nullptr)
            // {
            //     this->tail = p;
            // }
            // else
            // {
            head = p;

            // }
            std::cout << "Head = " << head->data << std::endl;
            //std::cout << "Tail = " << tail->data << std::endl;
            ++_size;
            std::cout << "Size: " << _size << "\n";
        }

        /// Remove the first element of the list. Calling this function on an empty
        /// list is undefined behavior. When implementing this function, be careful
        /// to delete the one and only the one element that is removed.
        void pop_front()
        {
            if (head == nullptr)
                std::cout << "Can't pop from an empty list!!\n";
            if (_size > 0)
            {

                if (_size == 1)
                {
                    head = nullptr;
                    tail = nullptr;
                }
                else
                {
                    head = head->next;
                    std::cout << "Popped head " << head->data << "\n";
                }
                --_size;
            }
        }

        /// Get a reference to the first element of the list
        /// (const and non-const version)
        T &front()
        {
            return head->data;
        }

        const T &front() const
        {
            const T out = head->data;
            return out;
        }

        /// Return true is the list is empty
        bool empty() const
        {
            return !_size;
        }

        /// Return the number of elements stored in the list.
        std::size_t size() const
        {
            return _size;
        }

        /// Insert a new element after the one pointed to by the given Iterator.
        /// Returns an Iterator to the newly inserted element
        Iterator insert_after(Iterator pos, T value)
        {
            // 6->5->4->3
            _size++;
            Node *mid = new Node(value, pos._node->next);
            pos._node->next = mid;

            return pos._node->next; //after;
        }

        /// Swaps the contents of two ForwardLists without making any deep copies!
        /// This is a commonly implemented function that makes in possible to
        /// cheaply swap two objects of the same class, and that aids in
        /// implementing the assignment operator using the copy-and-swap idiom.
        friend void swap(ForwardList &l, ForwardList &r)
        {
            std::swap(l.head, r.head);
            std::swap(l.tail, r.tail);
            std::swap(l._size, r._size);
        }

    private:
        // ToDo: Data member(s)?
        node_pointer head, tail;
        std::size_t _size;
    };

}
//Bearbeitet bei Abdelhalim Abdelhalim, Abdelrahman Abdelhalim, Mahadik Hannan Javed und Moayad Okal