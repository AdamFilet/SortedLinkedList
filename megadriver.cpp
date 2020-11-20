#include <iostream> // cout, endl
#include <iomanip>  // setw
#include <cstdlib>  // atoi
#include "List.h"
#include "PRNG.h"

namespace {

// generate random _numbers between low and high 
int RandomInt(unsigned low, unsigned high)
{
  int _number = static_cast<int>(CS170::Utils::rand() % (high - low + 1) + low);
  return _number;
}

void TestAdd(void)
{
  std::cout << "\n******************** TestAdd ********************\n";

  List list1;
  List list2; 
  const int _numbers[] = {
                         12, 34, 21, 56, 38, 94, 23, 22, 
                         67, 56, 88, 19, 59, 10, 17
                        };
  size_t size = sizeof(_numbers) / sizeof(*_numbers);

    // Create two lists
  for (size_t i = 0; i < size; i++)
  {
    list1.AddToEnd(_numbers[i]);
    list2.AddToFront(_numbers[i]);

    std::cout << "List1 (" << std::setw(2) << list1.Count() << " nodes): ";
    std::cout << list1 << std::endl;
    std::cout << "List2 (" << std::setw(2) << list2.Count() << " nodes): ";
    std::cout << list2 << std::endl;
    std::cout << std::endl;
  }
}

void TestFind(void)
{
  std::cout << "\n******************** TestFind ********************\n";

  List list1;
  const int _numbers[] = {
                         22, 23, 38, 94, 56, 34, 
                         67, 56, 88, 19, 10, 59
                        };
  size_t size = sizeof(_numbers) / sizeof(*_numbers);
  for (size_t i = 0; i < size; i++)
    list1.AddToEnd(_numbers[i]);

  std::cout << "List1 (" << std::setw(2) << list1.Count() << " nodes): ";
  std::cout << list1 << std::endl;

    // Find an existing value
  int value = 56;
  Node *node = list1.FindItem(value);
  if (node)
    std::cout << "Value: " << node->_number << " was found.\n";
  else
    std::cout << "Value: " << value << " was not found.\n";

  value = 22;
  node = list1.FindItem(value);
  if (node)
    std::cout << "Value: " << node->_number << " was found.\n";
  else
    std::cout << "Value: " << value << " was not found.\n";

  value = 59;
  node = list1.FindItem(value);
  if (node)
    std::cout << "Value: " << node->_number << " was found.\n";
  else
    std::cout << "Value: " << value << " was not found.\n";

    // Find a non-existant value
  value = 123;
  node = list1.FindItem(value);
  if (node)
    std::cout << "Value: " << node->_number << " was found.\n";
  else
    std::cout << "Value: " << value << " was not found.\n";

  std::cout << "List1 (" << std::setw(2) << list1.Count() << " nodes): ";
  std::cout << list1 << std::endl;
}

void TestDelete1(void)
{
  std::cout << "\n******************** TestDelete1 ********************\n";

  List list1;
  const int _numbers[] = {
                         22, 23, 38, 94, 56, 34, 
                         67, 56, 88, 19, 10, 59
                        };
  size_t size = sizeof(_numbers) / sizeof(*_numbers);
  for (size_t i = 0; i < size; i++)
    list1.AddToEnd(_numbers[i]);

  std::cout << "List1 (" << std::setw(2) << list1.Count() << " nodes): ";
  std::cout << list1 << std::endl;

  list1.Delete(56);
  std::cout << "Deleting: 56 (" << std::setw(2) << list1.Count() << " nodes): ";
  std::cout << list1 << std::endl;

  list1.Delete(22);
  std::cout << "Deleting: 22 (" << std::setw(2) << list1.Count() << " nodes): ";
  std::cout << list1 << std::endl;

  list1.Delete(59);
  std::cout << "Deleting: 59 (" << std::setw(2) << list1.Count() << " nodes): ";
  std::cout << list1 << std::endl;

  list1.Delete(99);
  std::cout << "Deleting: 99 (" << std::setw(2) << list1.Count() << " nodes): ";
  std::cout << list1 << std::endl;

  {
    const int _numbers[] = {
                           23, 38, 94, 34, 
                           67, 56, 88, 19, 10
                          };
    size_t size = sizeof(_numbers) / sizeof(*_numbers);
    for (size_t i = 0; i < size; i++)
    {
      list1.Delete(_numbers[i]);
      std::cout << "Deleting: " << _numbers[i] << " (" << std::setw(2) 
                << list1.Count() << " nodes): ";
      std::cout << list1 << std::endl;
    }
    list1.Delete(99);
    std::cout << "Deleting: 99 (" << std::setw(2) << list1.Count() << " nodes): ";
    std::cout << list1 << std::endl;
  }
}

void TestDelete2(void)
{
  std::cout << "\n******************** TestDelete1 ********************\n";

  List list1;
  const int _numbers1[] = {
                         22, 23, 38, 94, 56, 34, 
                         67, 56, 88, 19, 10, 59
                        };
  size_t size1 = sizeof(_numbers1) / sizeof(*_numbers1);
  for (size_t i = 0; i < size1; i++)
    list1.AddToEnd(_numbers1[i]);

  List list2;
  const int _numbers2[] = {
                         94, 23, 56, 22, 56, 19, 
                         67, 38, 34, 59
                        };
  size_t size2 = sizeof(_numbers2) / sizeof(*_numbers2);
  for (size_t i = 0; i < size2; i++)
    list2.AddToEnd(_numbers2[i]);

  std::cout << "List1 (" << std::setw(2) << list1.Count() << " nodes): ";
  std::cout << list1 << std::endl;
  std::cout << "List2 (" << std::setw(2) << list2.Count() << " nodes): ";
  std::cout << list2 << std::endl;

  list1.Delete(list2);
  std::cout << "List1 after deleting list2 (" << std::setw(2) << list1.Count() << " nodes): ";
  std::cout << list1 << std::endl;
  std::cout << "List2 (" << std::setw(2) << list2.Count() << " nodes): ";
  std::cout << list2 << std::endl;
}

void TestConcat(void)
{
  std::cout << "\n******************** TestConcat ********************\n";

  List list1;
  List list2; 
  const int _numbers1[] = {12, 34, 21, 56, 38, 94, 23};
  const int _numbers2[] = {67, 56, 88, 19, 59, 10, 17};

  size_t size1 = sizeof(_numbers1) / sizeof(*_numbers1);
  size_t size2 = sizeof(_numbers2) / sizeof(*_numbers2);

  for (size_t i = 0; i < size1; i++)
    list1.AddToEnd(_numbers1[i]);

  for (size_t i = 0; i < size2; i++)
    list2.AddToEnd(_numbers2[i]);

  std::cout << "List1 (" << std::setw(2) << list1.Count() << " nodes): ";
  std::cout << list1 << std::endl;
  std::cout << "List2 (" << std::setw(2) << list2.Count() << " nodes): ";
  std::cout << list2 << std::endl;

  std::cout << "Adding both lists (" << std::setw(2) << list1.Count() << " nodes): ";
  list1.Concat(list2);
}

void TestInsert1(void)
{
  std::cout << "\n******************** TestInsert1 ********************\n";

  List list1;
  const int _numbers[] = {
                         12, 34, 21, 56, 38, 94, 23, 22, 
                         67, 56, 88, 19, 59, 10, 17
                        };
  for (int i = 0; i < 5; i++)
  {
    list1.AddToEnd(_numbers[i]);
    std::cout << "List1 (" << std::setw(2) << list1.Count() << " nodes): ";
    std::cout << list1 << std::endl;
    std::cout << std::endl;
  }

  std::cout << "Inserting... 91 at position 3\n";
  list1.Insert(91, 3);
  std::cout << list1 << std::endl;
  std::cout << "Inserting... 92 at position 0\n";
  list1.Insert(92, 0);
  std::cout << list1 << std::endl;
  std::cout << "Inserting... 93 at position 7\n";
  list1.Insert(93, 7);
  std::cout << list1 << std::endl;
  std::cout << "Inserting... 94 at position 9\n";
  list1.Insert(94, 9);
  std::cout << list1 << std::endl;
}

void TestInsert2(void)
{
  std::cout << "\n******************** TestInsert2 ********************\n";

  List list1;
  const int _numbers[] = {
                         12, 34, 21, 56, 38, 94, 23, 22, 
                         67, 56, 88, 19, 59, 10, 17
                        };
  size_t size = sizeof(_numbers) / sizeof(*_numbers);

  for (size_t i = 0; i < size; i++)
  {
    list1.Insert(_numbers[i]);

    std::cout << "List1 (" << std::setw(2) << list1.Count() << " nodes) ";
    std::cout << "Inserting " << std::setw(2) << _numbers[i] << ": ";
    std::cout << list1 << std::endl;
  }
}

void TestMerge(const int _numbers1[], const int _numbers2[], size_t size1, size_t size2)
{
  List list1;
  List list2;

  for (size_t i = 0; i < size1; i++)
    list1.Insert(_numbers1[i]);
 
  for (size_t i = 0; i < size2; i++)
    list2.Insert(_numbers2[i]);

  std::cout << "List1 (" << std::setw(2) << list1.Count() << " nodes): ";
  std::cout << list1 << std::endl;
  std::cout << "List2 (" << std::setw(2) << list2.Count() << " nodes): ";
  std::cout << list2 << std::endl;

  std::cout << "Merge list2 into list1:\n";
  list1.Merge(list2);
  std::cout << "List1 (" << std::setw(2) << list1.Count() << " nodes): ";
  std::cout << list1 << std::endl;
  std::cout << "List2 (" << std::setw(2) << list2.Count() << " nodes): ";
  std::cout << list2 << std::endl;
}

void TestMerge1(void)
{
  std::cout << "\n******************** TestMerge1 ********************\n";

  const int _numbers1[] = {12, 70, 21};
  const int _numbers2[] = {67, 23, 88};
                        
  size_t size1 = sizeof(_numbers1) / sizeof(*_numbers1);
  size_t size2 = sizeof(_numbers2) / sizeof(*_numbers2);

  TestMerge(_numbers1, _numbers2, size1, size2);
}

void TestMerge2(void)
{
  std::cout << "\n******************** TestMerge2 ********************\n";

  const int _numbers1[] = {12, 34, 21, 56, 38, 94, 27, 22};
  const int _numbers2[] = {67, 23, 88, 19, 59, 10, 17, 30};
                        
  size_t size1 = sizeof(_numbers1) / sizeof(*_numbers1);
  size_t size2 = sizeof(_numbers2) / sizeof(*_numbers2);

  TestMerge(_numbers1, _numbers2, size1, size2);
}

void TestMerge3(void)
{
  std::cout << "\n******************** TestMerge3 ********************\n";

  const int _numbers1[] = {12, 34, 21, 56};
  const int _numbers2[] = {67, 23, 88, 19, 59, 10, 17, 30};
                        
  size_t size1 = sizeof(_numbers1) / sizeof(*_numbers1);
  size_t size2 = sizeof(_numbers2) / sizeof(*_numbers2);

  TestMerge(_numbers1, _numbers2, size1, size2);
}

void TestMerge4(void)
{
  std::cout << "\n******************** TestMerge4 ********************\n";

  const int _numbers1[] = {12, 34, 21, 56, 38, 94, 27, 22};
  const int _numbers2[] = {67, 23, 88};
                        
  size_t size1 = sizeof(_numbers1) / sizeof(*_numbers1);
  size_t size2 = sizeof(_numbers2) / sizeof(*_numbers2);

  TestMerge(_numbers1, _numbers2, size1, size2);
}

void TestMerge5(void)
{
  std::cout << "\n******************** TestMerge5 ********************\n";

  const int _numbers1[] = {12, 34, 21, 56, 38, 94, 27, 22};
  const int _numbers2[] = {0};
                        
  size_t size1 = sizeof(_numbers1) / sizeof(*_numbers1);

  TestMerge(_numbers1, _numbers2, size1, 0);
}

void TestMerge6(void)
{
  std::cout << "\n******************** TestMerge6 ********************\n";

  const int _numbers1[] = {0};
  const int _numbers2[] = {67, 23, 88, 19, 59, 10, 17, 30};
                        
  size_t size2 = sizeof(_numbers2) / sizeof(*_numbers2);

  TestMerge(_numbers1, _numbers2, 0, size2);
}

void TestMerge7(void)
{
  std::cout << "\n******************** TestMerge7 ********************\n";

  const int _numbers1[] = {12, 34, 12, 56, 12, 12, 27, 22};
  const int _numbers2[] = {12, 12, 88, 12, 59, 12, 17, 12};
                        
  size_t size1 = sizeof(_numbers1) / sizeof(*_numbers1);
  size_t size2 = sizeof(_numbers2) / sizeof(*_numbers2);

  TestMerge(_numbers1, _numbers2, size1, size2);
}

void TestMerge8(void)
{
  std::cout << "\n******************** TestMerge8 ********************\n";

  const int _numbers1[] = {12, 70, 21, 55, 56, 20, 21, 12, 12, 8, 43};
                        
  size_t size1 = sizeof(_numbers1) / sizeof(*_numbers1);

  std::cout << "Merging a list into itself...\n";
  TestMerge(_numbers1, _numbers1, size1, size1);
}

void TestStress1(void)
{
  std::cout << "\n******************** TestStress1 ********************\n";

  CS170::Utils::srand(1, 2);
  int size = 20000;
  unsigned low = 1, high = 20;
  List list;
  for (int i = 0; i < size; i++)
    list.AddToFront(RandomInt(low, high));

  std::cout << list << std::endl;
  for (int i = 0; i < size + 1500; i++)
  {
    int item = RandomInt(low, high);
    list.Delete(item);
    //std::cout << std::endl;
    //std::cout << list << std::endl;
  }
  std::cout << std::endl;
  std::cout << list << std::endl;
  std::cout << "Items in the list: " << list.Count() << std::endl;
  std::cout << std::endl;
}

} // end namespace

void PassByConst(List &list1, const List &list2)
{
  list1.Concat(list2);
  list2.Count();
  list2.FindItem(10);
  list1.Delete(list2);
  std::cout << list2 << std::endl;
}

void TestConst(void)
{
  std::cout << "\n******************** TestConst ********************\n";

  List list1;
  List list2; 
  const int _numbers[] = {
                         12, 34, 21, 56, 38, 94, 23, 22, 
                         67, 56, 88, 19, 59, 10, 17
                        };
  size_t size = sizeof(_numbers) / sizeof(*_numbers);

    // Create two lists
  for (size_t i = 0; i < size; i++)
  {
    list1.AddToEnd(_numbers[i]);
    list2.AddToFront(_numbers[i]);
  }
  PassByConst(list1, list2);
}

int main(int argc, char **argv)
{
  size_t test_num = 0;
  if (argc > 1)
    test_num = static_cast<size_t>(std::atoi(argv[1]));

  typedef void (*Test)(void);
  Test Tests[] =  {
                    TestAdd,         //  1 
                    TestFind,        //  2
                    TestInsert1,     //  3
                    TestInsert2,     //  4
                    TestConcat,      //  5
                    TestDelete1,     //  6
                    TestDelete2,     //  7
                    TestMerge1,      //  8
                    TestMerge2,      //  9
                    TestMerge3,      // 10
                    TestMerge4,      // 11
                    TestMerge5,      // 12
                    TestMerge6,      // 13
                    TestMerge7,      // 14
                    TestMerge8,      // 15
                    TestStress1,     // 16
                  };

  size_t num = sizeof(Tests) / sizeof(*Tests);
  if (test_num == 0)
  {
    for (size_t i = 0; i < num - 1; i++)
      Tests[i]();
  }
  else if (test_num > 0 && test_num <= num)
    Tests[test_num - 1]();

  return 0;
}
