/**
 * @file Demo.cpp
 * @author Ngo Van Trung (trung2601.it@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>

// The 'Strategy' interface
class SortStrategy
{
 public:
  virtual void Sort(int* data, int size) = 0;
};

// A concrete 'Strategy' class
class QuickSort : public SortStrategy
{
 public:
  void Sort(int* data, int size) override
  {
    std::cout << "QuickSort: Sorting data using quick sort algorithm." << std::endl;
  }
};

// A concrete 'Strategy' class
class MergeSort : public SortStrategy
{
 public:
  void Sort(int* data, int size) override
  {
    std::cout << "MergeSort: Sorting data using merge sort algorithm." << std::endl;
  }
};

// The 'Context' class
class Sorter
{
 private:
  SortStrategy* sortStrategy_;

 public:
  Sorter(SortStrategy* sortStrategy) : sortStrategy_(sortStrategy) {}

  void SetSortStrategy(SortStrategy* sortStrategy)
  {
    sortStrategy_ = sortStrategy;
  }

  void Sort(int* data, int size)
  {
    sortStrategy_->Sort(data, size);
  }
};

int main()
{
  // Create the data to be sorted
  int data[] = { 3, 6, 1, 9, 2, 5 };
  int size = 6;

  // Create the 'Context' object
  Sorter sorter(new QuickSort());

  // Set the sorting algorithm to be used
  sorter.SetSortStrategy(new MergeSort());

  // Sort the data using the selected algorithm
  sorter.Sort(data, size);

  return 0;
}

