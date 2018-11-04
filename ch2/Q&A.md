# Q&A Chapter 2 Variable and Basic Type

1. ### 变量初始化的几种形式，复制、直接、列表初始化都是啥？

   + `int a = 10;`
   + `int b(11);`
   + `int c{12};`

2. ### extern关键字主要是干啥的？

   + 声明全局变量，告知该变量定义在别处，甚至是别的文件当中。
   + 可以多次声明，但是只能定义一次。

3. ### 引用是否可以被字面量初始化？

   + 不可以，引用类型的初始值必须是一个对象。

4. ### 定义指针后暂时没有要赋值的东西，应该用啥值代替？

   + 0
   + `nullptr`

5. ### `int *tp=0; int *&pi = tp;`，pi是什么？

   + 是一个int指针类型的应用（这种问题从内层往外层看）

6. ### const引用是否可以被字面量初始化？

   + 这个是可以的
   + `const int &r1 = 42;`

7. ### 说说constexpr这个关键字是干啥的？

   + 确定是常量表达式，在编译阶段就能确定的。
   + 如果使用const，有一些非常量的初始化情况无法在编译时确定。

8. ### const int *p 和 int *const p 有啥区别？

   + 指向只读变量的指针。
   + 指向int的只读指针。

9. ### `typedef double *p; const p cstr = 0;`，cstr是什么类型？

   + p为double*
   + cstr是double的只读指针。

10. ### 使用using给类取别名怎么用？

    + `using SI = Sales_Item;`

11. ### 使用auto有啥注意事项？

    + 使用时要初始化，并且确定能推断出类型。
    + 如果使用const只读变量初始化，会忽略顶层const。`const int ci = 10; auto b = ci;`
    + 如果是底层const，会保留。如右侧所示，取地址得到的是底层const，`auto e = &ci`

12. ### decltype是干啥用的？

    + 可以推断类型。甚至是从函数返回类型中。而不执行表达式。
    + `decltype(func()) a = 10;`
    + 这个可以识别出引用类型。如果是引用的话需要被初始化。