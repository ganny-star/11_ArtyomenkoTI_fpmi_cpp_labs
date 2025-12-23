#include "forward_list.h"

#include <utility>

ForwardList::ForwardList(const ForwardList& rhs) {

    Node* NewStart = nullptr;
    Node* NewEnd = nullptr;

    size_t NewSize = 0;

    try {
        for(Node* now = rhs.start_; now != nullptr; now = now -> next_) {
            Node* NewNode = new Node(now->value_);

            if(NewStart == nullptr) {
                NewStart = NewNode;
                NewEnd = NewNode;
            }
            else {
                NewEnd->next_ = NewNode;
                NewEnd = NewNode;
            }
            NewSize++;
        }
    } catch(...) {
        while(NewStart != nullptr) {
            Node* ToDel = NewStart;
            NewStart = ToDel->next_;
            delete ToDel;
        }
        throw;
    }

    start_ = NewStart;
    size_ = NewSize;

}

ForwardList::ForwardList(size_t count, int32_t value) {

    Node* NewStart = nullptr;
    Node* NewEnd = nullptr;

    size_t NewSize = 0;

    try {
        for(size_t i = 0; i < count; i++) {
            Node* NewNode = new Node(value);

            if(NewStart == nullptr) {
                NewStart = NewNode;
                NewEnd = NewNode;
            }
            else {
                NewEnd->next_ = NewNode;
                NewEnd = NewNode;
            }
            ++NewSize;
        }
    } catch(...) {
        while(NewStart != nullptr) {
            Node* ToDel = NewStart;
            NewStart = ToDel->next_;
            delete ToDel;
        }
        throw;
    }

    start_ = NewStart;
    size_ = NewSize;

}

ForwardList::ForwardList(std::initializer_list<int32_t> init) {

    Node* NewStart = nullptr;
    Node* NewEnd = nullptr;

    size_t NewSize = 0;

    try {
        for(int32_t value : init) {
            Node* NewNode = new Node(value);

            if(NewStart == nullptr) {
                NewStart = NewNode;
                NewEnd = NewNode;
            }
            else {
                NewEnd->next_ = NewNode;
                NewEnd = NewNode;
            }
            NewSize++;
        }
    } catch(...) {
        while(NewStart != nullptr) {
            Node* ToDel = NewStart;
            NewStart = ToDel->next_;
            delete ToDel;
        }
        throw;
    }

    start_ = NewStart;
    size_ = NewSize;

}

ForwardList& ForwardList::operator=(const ForwardList& rhs) {

     ForwardList temp(rhs);
     swap(temp);
     return *this;

}

ForwardList::~ForwardList() {
    Clear();
}

void ForwardList::PushFront(int32_t value) {
    Node* NewNode = new Node(value);
    NewNode -> next_ = this -> start_;
    this -> start_ = NewNode;
    size_++;
}


void ForwardList::PopFront() {
    if(start_ == nullptr) {
        throw std::out_of_range("Forward List is empty");
    }
    Node* ToDel = this -> start_;
    start_ = ToDel -> next_;
    delete ToDel;
    size_--;
}

void ForwardList::Remove(int32_t value) {
    while(start_ != nullptr && start_ -> value_ == value) {
        PopFront();
    }

    for(Node* CurNode = start_; CurNode != nullptr && CurNode->next_ != nullptr;) {
        if((CurNode->next_)->value_ == value) {
            Node* ToDel = CurNode->next_;
            CurNode->next_ = ToDel->next_;
            delete ToDel;
        size_--;
        } else {
             CurNode = CurNode->next_;
        }
    }
}

void ForwardList::Clear() {
    while(start_ != nullptr) {
        PopFront();
    }
}

bool ForwardList::FindByValue(int32_t value) {

    for(Node* CurNode = start_; CurNode != nullptr; CurNode = CurNode->next_) {
        if(CurNode->value_ == value) return true;
    }
    return false;
}

void ForwardList::Print(std::ostream& out) {

    for(Node* CurNode = start_; CurNode != nullptr; CurNode = CurNode->next_) {
        out << CurNode->value_;
        if(CurNode->next_ != nullptr) out << ' ';
    }

}

int32_t ForwardList::Front() const {
    if(start_ == nullptr) throw std::out_of_range("Forward List is empty");
    return start_->value_;
}

size_t ForwardList::Size() const {
    return size_;
}

void ForwardList::swap(ForwardList& other) noexcept {
    std::swap(start_, other.start_);
    std::swap(size_, other.size_);
}
