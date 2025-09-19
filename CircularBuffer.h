#pragma once
#include <vector>
#include <stdexcept>

template <typename T>
class CircularBuffer {
public:
    explicit CircularBuffer(size_t capacity)
        : buffer_(capacity), capacity_(capacity), head_(0), tail_(0), size_(0) {}

    void push_back(const T& item) {
        push(item);
    }

    T pop() {
        if (size_ == 0)
            throw std::underflow_error("Buffer is empty");
        T item = buffer_[head_];
        head_ = (head_ + 1) % capacity_;
        --size_;
        return item;
    }

    // Non-const and const versions for front()
    T& front() {
        if (size_ == 0)
            throw std::underflow_error("Buffer is empty");
        return buffer_[head_];
    }

    const T& front() const {
        if (size_ == 0)
            throw std::underflow_error("Buffer is empty");
        return buffer_[head_];
    }

    // Non-const and const versions for back()
    T& back() {
        if (size_ == 0)
            throw std::underflow_error("Buffer is empty");
        size_t idx = (tail_ == 0) ? capacity_ - 1 : tail_ - 1;
        return buffer_[idx];
    }

    const T& back() const {
        if (size_ == 0)
            throw std::underflow_error("Buffer is empty");
        size_t idx = (tail_ == 0) ? capacity_ - 1 : tail_ - 1;
        return buffer_[idx];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
    bool full() const { return size_ == capacity_; }

    // Forward iterator
    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(CircularBuffer* buffer, size_t index, size_t count)
            : buffer_(buffer), index_(index), count_(count) {}

        reference operator*() { return buffer_->buffer_[index_]; }
        pointer operator->() { return &buffer_->buffer_[index_]; }

        Iterator& operator++() {
            index_ = (index_ + 1) % buffer_->capacity_;
            ++count_;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const Iterator& other) const {
            return count_ == other.count_;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

    private:
        CircularBuffer* buffer_;
        size_t index_;
        size_t count_;
    };

    Iterator begin() {
        return Iterator(this, head_, 0);
    }

    Iterator end() {
        return Iterator(this, tail_, size_);
    }

private:
    std::vector<T> buffer_;
    size_t capacity_;
    size_t head_;
    size_t tail_;
    size_t size_;
};