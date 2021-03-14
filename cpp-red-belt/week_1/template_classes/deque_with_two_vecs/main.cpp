#include <iostream>
#include <vector>
#include <exception>
#include <string>

template <typename T>
class Deque {
public:
    Deque():
    size(0) {} 
    
    bool Empty() const {
        return size == 0;
    }

    size_t Size() const {
        return size;
    }

    const T& operator[](size_t index) const {
        if (index < head.size()) {
            return head[head.size() - 1 - index];
        }

        return tail[index - head.size()];
    }

    T& operator[](size_t index) {
        return const_cast<T&>(const_cast<const Deque&>(*this)[index]);
    }

    const T& At(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }

        if (index < head.size()) {
            return head[head.size() - 1 - index];
        }

        return tail[index - head.size()];
    }

    T& At(size_t index) {
        return const_cast<T&>(const_cast<const Deque&>(*this).At(index));
    }

    const T& Front() const {
        if (head.empty() && !tail.empty()) {
            return tail[0];
        }

        return head[head.size() - 1];
    }
    
    T& Front() {
        return const_cast<T&>(const_cast<const Deque&>(*this).Front());
    }

    const T& Back() const {
        if (tail.empty() && !head.empty()) {
            return head[0];
        }

         return tail[tail.size() - 1];
    }
    
    T& Back() {
        return const_cast<T&>(const_cast<const Deque&>(*this).Back());
    }

    void PushFront(const T& elm) {
        head.push_back(elm);
        size++;
    }

    void PushBack(const T& elm) {
        tail.push_back(elm);
        size++;
    }

private:
    std::vector<T> head;
    std::vector<T> tail;
    size_t size;
};

int main() {
	Deque<int> deque;
	deque.PushBack(1);
	deque.PushBack(2);
	deque.PushBack(3);
	deque.PushBack(4);
    deque.PushBack(5);
    deque.PushFront(2);
    deque.PushBack(6);
    deque.PushFront(3);
    deque.PushFront(4);
    deque.PushFront(5);
	std::cout << deque.Front() << ' ' << deque.At(1) << ' ' << deque[0]
		<< ' ' << deque.Back() << ' ' << deque.At(deque.Size() - 1) << ' ' << deque[deque.Size() - 1] << '\n';
}
