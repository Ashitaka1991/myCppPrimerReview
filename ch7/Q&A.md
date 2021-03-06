# Q&A Chapter 7 类

1. ### 在类的成员函数中，this是以怎样的形式定义的？

   + 会隐式定义为this指针

2. ### 在成员函数内部，我们是否可以直接使用调用该函数的对象成员？为什么？

   + 可以，在作用域中。

3. ### 成员函数参数列表后面跟着的const关键字是什么作用？

   + 是指定隐式的this指针指向的是const对象。

4. ### 常量对象及其指针和引用，只能调用常量成员函数么？

   + 是的。（不能将const对象赋给非const的this指针）

5. ### 类的成员函数，为何定义在后面的函数也可以使用前面的函数？

   + 会先进行名字解析。

6. ### 构造函数是否有返回类型？是否可以声明成const？

   + 不可以，不可以。声明成const就不能对成员变量进行处理了。

7. ### 合成默认构造函数工作步骤？

   + 先以类内初始值进行初始化。
   + 没有的进行默认初始化

8. ### 何时编译器会自动生成默认构造函数？

   + 没有提供任何构造函数时

9. ### =default的作用，为何会产生这种用法？

   + 指明默认构造函数。

10. ### 如果么有出现在构造函数初始值列表中给的成员，会怎样被初始化？

    + 先查找类内初始值
    + 如果没有，进行默认初始化。

11. ### struct和class的区别

    + 默认访问标记，struct为public

12. ### 友元是否是类的成员？

    + 不是，只是声明权限。

13. ### 是否可以在类中定义其他类型的别名？举个例子？

    + 可以的，可以用typedef或者using

14. ### 隐式inline和显式inline的方式各是什么样子的？

    + 在类内直接定义函数可以隐式声明。
    + 使用inline时显示声明。

15. ### 加入什么关键词可以使const函数改变数据成员？

    + mutable，在成员变量前加m也是这个意思。

16. ### C++11中两种提供类内初始值的方式？

    + 在声明成员变量时使用=赋值形式
    + 

17. ### 设计良好的C++代码中，是否应当有很多实现具体操作的私有函数，这些函数在公有函数接口中调用？

    + 是的。

18. ### 简单说明下前向声明和不完全类型。

    + 有时在类中需要依赖别的类声明变量或是其他。但是该类还没有明确定义出来。
    + 此时可以容易class声明的不完全类型进行前向声明，此时可以用这个类进行对引用类型进行声明。

19. ### 友元的关系是否具有传递性？

    + 不具有。

20. ### 怎样令一个类的成员函数称为另一个类的友元？

    + friend className::funcName（）

21. ### 在类外部定义成员函数时为何要使用类作用域？

    + 因为类有作用域，得指明在类的作用域中才可以在类作用域中有效。

22. ### 成员的初始化工作是在构造函数体执行之前么？

    + 是的。如果最先作用的时初始化列表，接着是默认初始化未在列表中的变量。
    + 这个过程完成之后才是执行构造函数体中的内容。

23. ### 如果成员是const或是引用，是否必须在初始化列表中进行初始化？

    + 是的，在这里是初始化效果。如果在构造函数体中执行，就变成赋值操作了。这对const或是引用是不可行的。

24. ### 是否应该将初始化列表中的变量顺序和成员声明的顺序保持一致？

    + 是的。

25. ### 如果一个构造函数的所有参数都有默认实参，则它实际上是否定义了默认构造函数？

    + 是的。

26. ### 解释下委托构造函数？

    + 调用某个构造函数后，它会调用其他构造函数，有点类似初始化列表。

27. ### 默认构造函数的作用？什么情况下会失效？

    + 如果定义了有其他参数的构造函数，而没有显式定义没有参数的构造函数。

28. ### 只有一个实参的构造函数的重要作用是什么？它与隐式类类型转换有关？

    + 用来复制，以及隐式转换。

29. ### 类类型转换是否可以多步转换？

    + 不可以，只可以用直接声明的类型进行一次转换。

30. ### explicit的作用？是否只针对一个参数的构造函数使用？

    + 针对一个参数的构造函数，说明该构造函数只能显式调用。避免发生不必要的隐式转换。

31. ### 在声明和定义中都要使用这个关键词么？

    + 只允许在声明中使用。

32. ### 字面值常量类的构造函数可以是constexpr？

    + 可以，用于构造字面值常量类。

33. ### 类的静态成员函数中是否有this？是否可以声明成const的？是否可以用类的对象来访问？

    + 不可以；都没有this了，也就不可以用const声明this了；可以。

34. ### static关键字在声明和定义时是否可以重复？

    + 内外都可以，但是只能声明一次。

35. ### 类的静态成员是否应该在类内进行初始化？

    + 可以，但是类外也要声明一下。

36. ### 类内初始化了static成员，类外定义是否还可以赋值？

    + 赋值就不管用了。就跟static关键字一样，只能用在一处。

37. ### 静态成员可否作为默认实参？

    1. 可以。可以用它来解决一些魔数问题。

38. ### 静态成员是否可以是不完全类型？

    + 是可以的。