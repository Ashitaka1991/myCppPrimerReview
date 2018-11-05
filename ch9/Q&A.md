# Q&A Chapter 9 顺序容器

1. ### 六种顺序容器和三种适配器？

   + `string vector deque list forward_list array`
   + `stack queue priority_queue`

2. ### C++11新增的两种容器是啥？

   + `forward_list array`

3. ### 用数量参数初始化容器时，如果元素没有默认构造函数会发生什么事情？

   + 这种初始化形式，是要依赖元素类型的默认构造函数的，如果没有默认构造函数会出错。

4. ### forward_list迭代器是否支持--运算？

   + 不支持，forward单向的，只能++不能--。

5. ### 反向迭代器的++操作的效果？

   + 相当于从后往前推进。

6. ### 获取首尾迭代器的几个函数？

   + `begin() cbegin() rbegin() crbegin()`
   + `end() cend() rend() crend()`

7. ### 标准库array具有固定大小，定义一个长度为10的int类型的array？

   ```c++
   array<int,10> a = {1,2,3,4,5}
   ```

8. ### 标准库类型的array是否允许赋值？有什么要求？

   + 标准库array允许赋值
   + 要求元素类型和个数都要匹配，个数不匹配是不可以的。

9. ### swap函数干啥用的？为何很快？在array上使用有何不同？

   + swap交换两个容器中的元素
   + 因为不涉及到元素的拷贝，只是将两个容器中的数据结构进行替换。
   + 一般来说swap不会导致指向容器的迭代器、引用和指针失效。但是对于array、string是可能会失效的。

10. ### 应该用成员版本的swap还是非成员版本的swap？

    + 推荐使用非成员版本的swap，这样更通用一些。

11. ### insert，插入容器中的是对象值还是对象值的拷贝？

    + 拷贝。需要有内存区域的对象。如果不是专门保存指向对象的指针，都是需要拷贝的。

12. ### 怎样使用insert在同一位置反复插入？

    ```c++
    iter = v.insert(iter,value);
    ```

    + 返回的是插入元素的第一个的迭代器。

13. ### emplace系列函数有几个？

    + `emplace_front() emplace_back() emplace()`

14. ### push_back()和emplace_back()有何不同？

    + push_back()是传入对象，然后会创建该对象的副本，保存到容器中的这个副本。
    + emplace_back()传入的是用于创建对象的构造函数的参数。这样可以省去上述的拷贝过程。（如果构造函数有多个参数，那依此列出即可）

15. ### 在顺序容器中访问元素的操作有哪些？

    + `back() front() [idx] at(idx)`

16. ### `c.back()`的返回值应该赋给引用么？

    + 如果要对其进行操作，那么应该赋值给引用，否则只是该元素的一个副本。

17. ### erase()的行为是啥？

    + 删除指定元素后，返回删除元素后面的元素的迭代器，有可能是尾迭代器。

18. ### pop_front和pop_back返回值是什么类型？

    + 返回void，因此不能用他们获得元素值。需要先使用别的方式获取。

19. ### forward_list操作的特殊性，怎样在这个容器上erase？

    + 使用双迭代器模式
    + forward_list提供`before_begin() cbefore_begin()`用于获取前置迭代器。
    + 使用当前迭代器查找，使用前置迭代器配合`erase_after()`删除元素并将返回值给当前迭代器。
    + 比较合理的搭配，在一些其他问题上也可以使用。

20. ### 在调用insert后，为何要递增迭代器两次？

    + 跳过插入的元素和当前元素指向下一个元素。（这种情况要使用动态获取end()尾迭代器，时时都在失效）

21. ### 是否应该保存end返回的迭代器，为什么？

    + 不应该，对容器容量有影响的操作都会使它失效。

22. ### shrink_to_fit是干什么用的？

    + 推荐容器将不需要的预先申请的容量释放调。

23. ### vector中resize和reserve有何区别？

    + resize()是调整容器中的元素的数量，并且可以进行新元素的初始化和旧元素的删除。
    + reserve()是调整vector中内存容量的方法，不体现在元素数量上。而且如果调整的内存小于当前元素需要的内存，不会采纳这个函数的设置。

24. ### string中特有的append和replace函数？

    + 向后添加字符串。
    + 替换指定区间的字符子串。

25. ### string中的6个不同的搜索函数分别是啥？

    + `find() rfind() find_first_of() find_last_of() find_first_not_of() find_last_not_of()`

26. ### string与数值的转换函数？

    + 新标准新增了多个转换函数
    + `to_string(val) stoi(str) stod(str)`

27. ### 怎样指定基准容器定义容器适配器？

    ```c++
    stack<string,vector<string>> str_stk;
    ```
