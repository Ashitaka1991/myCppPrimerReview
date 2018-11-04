# Q&A Chapter 4 Expression

1. ### `int *p=nullptr; decltype(*p)`是什么类型？

   + *p是左值，返回的是int&引用类型。

2. ### `f()+g()*h()+j()`这个表达式中，函数执行的顺序是啥？

   + 未明确定义的，所以不能依赖于他们的调用顺序。

3. ### 赋值运算符满足右结合律？

   + 是的。

4. ### 递增递减运算符，前置版本和后置版本有啥不同？你用哪个？

   + 后置版本会先产生一个副本。尽量使用前置版本。

5. ### `(beg+1) = toupper(*beg)`可行么？

   + 不可行，是未定义的。

6. ### `cout << (grade<60) ? "fail" : "pass"`输出的是什么？

   + 会输出true或false

7. ### 位操作见bitset

8. ### sizeof的两种使用形式？

   + sizeof(a)
   + sizeof a

9. ### sizeof运算符是否需要一个具体的对象？

   + 不需要

10. ### sizeof作用于指针？

    + 得到的是指针所占内存空间的大小。

11. ### sizeof作用域string或vector对象？

    + 只返回该类型固定部分的大小，不返回我们动态添加进去的大小。

12. ### 逗号运算符的一个使用场景？

    + for语句最后的子语句要对多个变量进行处理时。

13. ### int类型和unsigned int类型一起运算会转成哪个？

    + 会转换成unsigned类型。

14. ### 说说static_cast,const_cast和reinterpret_cast的内容？

    + 常规的类型转换。
    + 将const去掉
    + 对内存在较低层的重新解释`int *ip; char *pc = reinterpret_cast<char*>(ip)`

15. ### 老式的类型转换是什么样的？为何不建议使用？

    + 老式是在变量前加括号中间包含类型。`int a = 10; (double)a = 11.1`
    + 因为这种方式包含了上述三种cast的用法，很难判断具体是哪一种。