#include "MagicalContainer.hpp"
#include <algorithm>
//include math.h for sqrt function
#include <math.h>

namespace ariel {

    void MagicalContainer::addElement(int element) {
        elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element) {
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    }

    int MagicalContainer::size() const {
        return elements.size();
    }

    std::vector<int> MagicalContainer::getCollection() const {
        return elements;
    }

    std::vector<int>::const_iterator MagicalContainer::begin() const {
    return sortedCollection.begin();
    }

    std::vector<int>::const_iterator MagicalContainer::end() const {
        return sortedCollection.end();
    }
     
    

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont) : container(cont), current(0) {
        sortedCollection = container.getCollection();
        std::sort(sortedCollection.begin(), sortedCollection.end());
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) : container(other.container), sortedCollection(other.sortedCollection), current(other.current) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        if (this != &other) {
            container = other.container;
            sortedCollection = other.sortedCollection;
            current = other.current;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return true;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        ++current;
        return *this;
    }

    std::vector<int>::const_iterator MagicalContainer::AscendingIterator::begin() const {
        return sortedCollection.begin();
    }

    std::vector<int>::const_iterator MagicalContainer::AscendingIterator::end() const {
        return sortedCollection.end();
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont) : container(cont), currentFromStart(0), currentFromEnd(size_t(cont.size() - 1)) {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : container(other.container), currentFromStart(other.currentFromStart), currentFromEnd(other.currentFromEnd) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        if (this != &other) {
            container = other.container;
            currentFromStart = other.currentFromStart;
            currentFromEnd = other.currentFromEnd;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return currentFromStart > other.currentFromStart;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return currentFromStart < other.currentFromStart;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        ++currentFromStart;
        --currentFromEnd;
        return *this;
    }

    std::vector<int> ::const_iterator MagicalContainer::SideCrossIterator::begin() const{
        return sortedCollection.begin();
    }

    std::vector<int> ::const_iterator MagicalContainer::SideCrossIterator::end() const{
        return sortedCollection.end();
    }


    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont) : container(cont), current(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) : container(other.container), current(other.current) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        if (this != &other) {
            container = other.container;
            current = other.current;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return current > other.current;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return current < other.current;
    }

    // int& MagicalContainer::PrimeIterator::operator*() const {
    //     return container.getCollection()[current];
    // }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        ++current;
        while (current < container.size() && !isPrime(container.getCollection()[current])) {
            ++current;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i <= std::sqrt(num); ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    std::vector<int> ::const_iterator MagicalContainer::PrimeIterator::begin() const{
        return sortedCollection.begin();
    }

    std::vector<int> ::const_iterator MagicalContainer::PrimeIterator::end() const{
        return sortedCollection.end();
    }
}
