# Q&A 关联容器

1. ### map是中元素，是什么类型的对象？

   + pair类型

2. ### 在set中找元素用什么方法？

   + 使用s.find(key)

3. ### 标准库使用关键字类型的 < 运算符来比较两个关键字？

   + 是的，因此关键字的类型应该支持这个运算符。或者重新传入一个比较函数。
   + `multiset<Sales_data,decltype(compareIsbn)*> bookstore(compareIsbn)`

4. ### pair定义在哪个头文件中？

   + utility

5. ### set的迭代器是否是const的？

   + 是的，因为作为键不可更改。同样，map中作为键的部分也是。

6. ### C++11新增的map添加元素的方式是什么？

   ```c++
   word_count.insert({word,1});
   ```

7. ### 如果map中以有某个键，再对其进行insert会有什么行为？返回的是什么类型？

   + 什么也不做
   + `pair<map<string,size_t>::iterator,bool>`
   + 因此如果插入没有成功，则判断ret.second是否为false

8. ### map和unordered_map是否提供了下标运算符和对应的at函数？

   + 是的。但是下标中不是索引，而是键值。`m[k] m.at(k)`

9. ### 如果map中没有要查找的元素，就不进行任何操作，应该使用什么方式？

   + 使用find，如果返回的是尾迭代器，就不做任何操作。

10. ### 怎样使用lower_bound和upper_bound找到multimap中某个键的元素的区间？

    + lower_bound()找前面的迭代器
    + upper_bound()找后面的迭代器

11. ### 无序容器的应用场景？

    + 有时不是很需要有序，并且也对保持有序的性能代价很关注，那么可以使用unordered无序容器。