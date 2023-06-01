#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>

namespace ariel {

    class MagicalContainer {
    private:
        std::vector<int> elements;
        std::vector<int> sortedCollection;


    public:
        void addElement(int element);
        void removeElement(int element);
        int size() const;
        std::vector<int> getCollection() const;

        std::vector<int>::const_iterator begin() const;
        std::vector<int>::const_iterator end() const;
        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
    };

    class MagicalContainer::AscendingIterator {
    private:
        MagicalContainer& container;
        std::vector<int> sortedCollection;
        size_t current;

    public:
        AscendingIterator(MagicalContainer& cont);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator();
        AscendingIterator& operator=(const AscendingIterator& other);
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        AscendingIterator& operator++();
        std::vector<int>::const_iterator begin() const;
        std::vector<int>::const_iterator end() const;
     
    
    };

    class MagicalContainer::SideCrossIterator {
    private:
        MagicalContainer& container;
        std::vector<int> sortedCollection;

        
        size_t currentFromStart;
        size_t currentFromEnd;

    public:
        SideCrossIterator(MagicalContainer& cont);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator();
        SideCrossIterator& operator=(const SideCrossIterator& other);
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        SideCrossIterator& operator++();
        std::vector<int>::const_iterator begin() const;
        std::vector<int>::const_iterator end() const;

    };

    class MagicalContainer::PrimeIterator {
    private:
        MagicalContainer& container;
        size_t current;
        std::vector<int> sortedCollection;

        bool isPrime(int num);

    public:
        PrimeIterator(MagicalContainer& cont);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator();
        PrimeIterator& operator=(const PrimeIterator& other);
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        int& operator*() const;
        PrimeIterator& operator++();
        std::vector<int>::const_iterator begin() const;
        std::vector<int>::const_iterator end() const;
    };

}

#endif /* MAGICALCONTAINER_HPP */
