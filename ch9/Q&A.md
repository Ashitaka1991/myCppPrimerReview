# Q&A Chapter 9 顺序容器

1. 六种顺序容器和三种适配器？
2. C++11新增的两种容器是啥？
3. 用数量参数初始化容器时，如果元素没有默认构造函数会发生什么事情？
4. forward_list迭代器是否支持--运算？
5. 反向迭代器的++操作的效果？
6. 获取首尾迭代器的几个函数？
7. 标准库array具有固定大小，定义一个长度为10的int类型的array？
8. swap函数干啥用的？为何很快？在array上使用有何不同？
9. 应该用成员版本的swap还是非成员版本的swap？
10. insert，插入容器中的是对象值还是对象值的拷贝？
11. 怎样使用insert在同一位置反复插入？
12. emplace系列函数有几个？
13. push_back()和emplace_back()有何不同？
14. 在顺序容器中访问元素的操作有哪些？
15. `c.back()`的返回值应该赋给引用么？
16. erase()的行为是啥？
17. pop_front和pop_back返回值是什么类型？
18. forward_list操作的特殊性，怎样在这个容器上erase？
19. 在调用insert后，为何要递增迭代器两次？
20. 是否应该保存end返回的迭代器，为什么？
21. shrink_to_fit是干什么用的？
22. vector中resize和reserve有何区别？
23. string中特有的append和replace函数？
24. string中的6个不同的搜索函数分别是啥？
25. string与数值的转换函数？
26. 怎样指定基准容器定义容器适配器？