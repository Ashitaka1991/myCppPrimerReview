# Q&A Chapter 6 Function

1. 函数中局部静态变量的效果和常用方式？生命周期和函数一样么？

2. 函数的参数是使用指针还是引用来避免大量的拷贝操作更好呢？

3. 数组可以拷贝么？

4. main函数接收参数时，参数是从argv[0]开始么？

5. 可变形参的两种形式：initializer_list和... ; 使用initializer_list的函数的实参是怎样的？

6. initializer_list和vector有何区别？

7. 有return的循环后是否应该也加一条return语句？

8. 在函数中返回临时变量，返回后为何不会被销毁？

9. 函数的返回值是const引用，那么函数的参数是不是也应该至少有个const引用？

10. 返回值为`const string&` 的函数返回`return "Empty"`可以么？

11. 返回值为`vector<string>`的函数可以返回`return {"functionX","okay"}`么？（C++11）

12. `int (*func(int i ))[10]`表示啥？

13. `auto func(int i) -> int(*)[10]`表示啥？

14. 在同一作用域中的两个函数，返回类型不同，其他都相同，是否是重载函数？

15. 顶层const的形参是否可以形成重载函数？

16. 调用重载函数的内部处理步骤？（函数匹配步骤）（类型查找发生在名字查找前？）

17. 如果在一个函数作用域中有一个函数和作用域外面的作用域的多个重载函数同名，那么在函数里还能调到函数外的重载函数么？

18. 默认实参，如果某个形参被赋予了默认值，它后面的所有形参都必须有默认值么？

19. 是否该在函数声明中指定默认实参，并将该声明放在头文件中？

20. 简单说说内联函数。

21. constexpr函数或是变量，是否是在编译阶段就确定了？

22. 预处理器定义的几个对调试有用的名字：`__func__ __FILE__ __LINE__ __TIME__ __DATE__`

23. 重载函数的指针，参数表要与其中一个重载函数精确重合？

24. 函数作为参数，应当先声明下类型：

    ```c++
    typedef bool Func(const string&, const string&);
    typedef decltype(lengthCompare) Func2;
    
    typedef bool (*FuncP)(const string&, const string&);
    typedef decltype(lengthCompare) *Func2;
    ```

25. 函数作为返回值，用后置类型声明怎么写？