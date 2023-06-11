#include "MagicalContainer.hpp"
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;
namespace ariel
{

    void MagicalContainer::addElement(int element)
    {
        auto it = std::upper_bound(elements.begin(), elements.end(), element);
        elements.insert(it, element);
    }

    void MagicalContainer::removeElement(int element)
    {
        if (std::find(elements.begin(), elements.end(), element) == elements.end())
        {
            throw std::runtime_error("Element does not exist in the container");
        }

        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    }

    int MagicalContainer::size() const
    {
        return elements.size();
    }

    std::vector<int> &MagicalContainer::getCollection()
    {
        return elements;
    }

    void MagicalContainer::set_collection(std::vector<int> new_collection)
    {
        elements = new_collection;
    }

    std::vector<int>::const_iterator MagicalContainer::begin()
    {
        return elements.begin();
    }

    std::vector<int>::const_iterator MagicalContainer::end()
    {
        return elements.end();
    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont) : container(cont), current(0)
    {
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), current(other.current) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    vector<int> &MagicalContainer::AscendingIterator::get_container()
    {
        return container.getCollection();
    }

    int MagicalContainer::AscendingIterator::get_current()
    {
        return current;
    }

    bool MagicalContainer::AscendingIterator::operator=(AscendingIterator &other)
    {
        if (this != &other)
        {
            throw std::runtime_error("Cannot assign to this iterator");
        }
        return true;
    }

    int MagicalContainer::AscendingIterator::operator*()
    {
        return this->get_container().begin()[current];
    }

    bool MagicalContainer::AscendingIterator::operator==(AscendingIterator &other)
    {
        return (this->get_current() == other.current);
    }

    bool operator==(MagicalContainer::AscendingIterator &other, vector<int>::const_iterator it)
    {

        if (other.get_container().begin() == other.get_container().end())
        {
            return true;
        }
        return other.get_container().begin()[other.get_current()] == it[0];
    }

    bool operator!=(MagicalContainer::AscendingIterator &other, vector<int>::const_iterator it)
    {
        return !(other == it);
    }

    bool MagicalContainer::AscendingIterator::operator!=(AscendingIterator &other)
    {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(AscendingIterator &other)
    {
        return this->get_current() > other.get_current();
    }

    bool MagicalContainer::AscendingIterator::operator<(AscendingIterator &other)
    {
        return this->get_current() < other.get_current();
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (this->get_current() == this->get_container().size())
        {
            throw std::runtime_error("Out of range");
        }

        ++current;
        return *this;
    }

    vector<int>::const_iterator MagicalContainer::AscendingIterator::begin()
    {

        return this->get_container().begin();
    }

    vector<int>::const_iterator MagicalContainer::AscendingIterator::end()
    {
        return this->get_container().end();
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &cont) : container(cont)
    {

        vector<int> temp = container.getCollection();
        vector<int> sortedCollection;

        std::sort(temp.rbegin(), temp.rend());

        for (unsigned long i = 0; i < temp.size() / 2; i++)
        {
            sortedCollection.push_back(temp[size_t(temp.size() - 1 - i)]);
             sortedCollection.push_back(temp[size_t(i)]);
        }
        if (container.size() % 2 != 0)
        {
            sortedCollection.push_back(temp[size_t(container.size() / 2)]);
        }
        container.set_collection(sortedCollection);
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    vector<int> &MagicalContainer::SideCrossIterator::get_container()
    {
        return container.getCollection();
    }

    int MagicalContainer::SideCrossIterator::get_current()
    {
        return current;
    }



    bool MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &other)
    {
        if (this != &other)
        {
            throw std::runtime_error("Cannot assign to this iterator");
        }
        return true;
    }

    int MagicalContainer::SideCrossIterator::operator*()
    {
        return this->get_container().begin()[current];
    }

    bool MagicalContainer::SideCrossIterator::operator==(SideCrossIterator &other)
    {
        return (this->get_current() == other.current);
    }

    bool operator==(MagicalContainer::SideCrossIterator &other, vector<int>::const_iterator it)
    {

        if (other.get_container().begin() == other.get_container().end())
        {
            return true;
        }
        return other.get_container().begin()[other.get_current()] == it[0];
    }

    bool operator!=(MagicalContainer::SideCrossIterator &other, vector<int>::const_iterator it)
    {
        return !(other == it);
    }

    bool MagicalContainer::SideCrossIterator::operator!=(SideCrossIterator &other)
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(SideCrossIterator &other)
    {
        return this->get_current() > other.get_current();
    }

    bool MagicalContainer::SideCrossIterator::operator<(SideCrossIterator &other)
    {
        return this->get_current() < other.get_current();
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (this->get_current() == this->get_container().size())
        {
            throw std::runtime_error("Out of range");
        }
        ++current;
        return *this;
    }

    std::vector<int>::const_iterator MagicalContainer::SideCrossIterator::begin()
    {
        return this->get_container().begin();
    }

    std::vector<int>::const_iterator MagicalContainer::SideCrossIterator::end()
    {
        return this->get_container().end();
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont) : container(cont), current(0)
    {

        sortedCollection = container.getCollection();
        // std::sort(sortedCollection.begin(), sortedCollection.end());
        sortedCollection.erase(std::remove_if(sortedCollection.begin(), sortedCollection.end(), [](int num)
                                              {
                                                  if (num < 2)
                                                  {
                                                      return true; // Exclude numbers less than 2 (not prime)
                                                  }
                                                  for (int i = 2; i <= std::sqrt(num); ++i)
                                                  {
                                                      if (num % i == 0)
                                                      {
                                                          return true; // Exclude numbers divisible by any other number (not prime)
                                                      }
                                                  }
                                                  return false; // Include prime numbers
                                              }),
                               sortedCollection.end());
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), current(other.current) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    vector<int> &MagicalContainer::PrimeIterator::get_container()
    {
        return sortedCollection;
    }

    int MagicalContainer::PrimeIterator::get_current()
    {
        return current;
    }

    bool MagicalContainer::PrimeIterator::operator=(PrimeIterator &other)
    {
        if (this != &other)
        {
            throw std::runtime_error("Cannot assign to this iterator");
        }
        return true;
    }

    int MagicalContainer::PrimeIterator::operator*()
    {
        return this->get_container().begin()[current];
    }

    bool MagicalContainer::PrimeIterator::operator==(PrimeIterator &other)
    {
        return this->get_current() == other.current;
    }

    bool operator==(MagicalContainer::PrimeIterator &other, vector<int>::const_iterator it)
    {

        if (other.get_container().begin() == other.get_container().end())
        {
            return true;
        }
        return other.get_container().begin()[other.get_current()] == it[0];
    }

    bool operator!=(MagicalContainer::PrimeIterator &other, vector<int>::const_iterator it)
    {
        return !(other == it);
    }

    bool MagicalContainer::PrimeIterator::operator!=(PrimeIterator &other)
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(PrimeIterator &other)
    {
        return this->get_current() > other.get_current();
    }

    bool MagicalContainer::PrimeIterator::operator<(PrimeIterator &other)
    {
        return this->get_current() < other.get_current();
    }

 
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (this->get_current() == this->get_container().size())
        {
            throw std::runtime_error("Out of range");
        }
        ++current;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::isPrime(int num)
    {
        if (num < 2)
        {
            return false;
        }
        for (int i = 2; i <= std::sqrt(num); ++i)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    std::vector<int>::const_iterator MagicalContainer::PrimeIterator::begin()
    {
        return this->get_container().begin();
    }

    std::vector<int>::const_iterator MagicalContainer::PrimeIterator::end()
    {
        return this->get_container().end();
    }
}