#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>

namespace ariel
{

    class MagicalContainer
    {
    private:
        std::vector<int> elements;

    public:
        void addElement(int element);
        void removeElement(int element);
        int size() const;
        std::vector<int> &getCollection();
        void set_collection(std::vector<int> new_collection);

        std::vector<int>::const_iterator begin();
        std::vector<int>::const_iterator end();

        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
    };

    class MagicalContainer::AscendingIterator
    {
    private:
        MagicalContainer container;
        int current = 0;

    public:
        AscendingIterator(MagicalContainer &cont);
        AscendingIterator(const AscendingIterator &other);
        ~AscendingIterator();

        bool operator=(AscendingIterator &other);
        bool operator==(AscendingIterator &other);
        friend bool operator==(AscendingIterator &other, std::vector<int>::const_iterator it);
        bool operator!=(AscendingIterator &other);
        friend bool operator!=(AscendingIterator &other, std::vector<int>::const_iterator it);
        bool operator>(AscendingIterator &other);
        std::vector<int> &get_container();
        int get_current();
        int operator*();
        bool operator<(AscendingIterator &other);
        AscendingIterator &operator++();
        std::vector<int>::const_iterator begin();
        std::vector<int>::const_iterator end();
    };

    class MagicalContainer::SideCrossIterator
    {
    private:
        MagicalContainer &container;
        int current = 0;

    public:
        SideCrossIterator(MagicalContainer &cont);
        SideCrossIterator(const SideCrossIterator &other);
        ~SideCrossIterator();

        std::vector<int> &get_container();
        int get_current();
        bool operator=(SideCrossIterator &other);
        bool operator==(SideCrossIterator &other);
        friend bool operator==(SideCrossIterator &other, std::vector<int>::const_iterator it);
        int operator*();
        bool operator!=(SideCrossIterator &other);
        friend bool operator!=(SideCrossIterator &other, std::vector<int>::const_iterator it);
        bool operator>(SideCrossIterator &other);
        bool operator<(SideCrossIterator &other);
        SideCrossIterator &operator++();
        std::vector<int>::const_iterator begin();
        std::vector<int>::const_iterator end();
    };

    class MagicalContainer::PrimeIterator
    {
    private:
        MagicalContainer &container;
        int current = 0;
        std::vector<int> sortedCollection;
        bool isPrime(int num);

    public:
        PrimeIterator(MagicalContainer &cont);
        PrimeIterator(const PrimeIterator &other);
        ~PrimeIterator();

        std::vector<int> &get_container();
        int get_current();
        bool operator=(PrimeIterator &other);
        bool operator==(PrimeIterator &other);
        friend bool operator==(PrimeIterator &other, std::vector<int>::const_iterator it);
        friend bool operator!=(PrimeIterator &other, std::vector<int>::const_iterator it);
        bool operator!=(PrimeIterator &other);
        bool operator>(PrimeIterator &other);
        bool operator<(PrimeIterator &other);
        int operator*();
        PrimeIterator &operator++();
        std::vector<int>::const_iterator begin();
        std::vector<int>::const_iterator end();
    };

}

#endif /* MAGICALCONTAINER_HPP */
