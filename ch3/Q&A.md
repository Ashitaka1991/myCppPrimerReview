# Q&A Chapter 3 string, vector and array

## string

1. using声明是否应该放在头文件中？为什么？
2. `string s1; string s2(s1); string s3=s1;`，s2和s3的初始化方式有何不同？
3. 将cin中的内容依此读入string用什么方式？将cin中的各行依此读入string用什么方式？
4. 为什么`s.size() < n` ，n不要为int类型？
5. 使用C++11标准的**范围for语句**遍历s中的字符。将小写字符变成大写。（使用cctype同文件中定义的toupper（））
6. 随机访问string中的字符。

## vector

1. vector可以容纳引用么？为什么？
2. `vector<T> v1={a,b,c...}`这种列表初始化方式可以么？
3. `vector<string> v2{10,"hi"}`是什么效果？
4. 在范围for语句中，是否可以改变其遍历序列的大小？为什么？
5. `vector<int>::size_type`和`vector::size_type`哪个是对的？

## iterator

1. 获取容器v的首尾迭代器的两个函数是什么？写一个迭代的例子。
2. 获取容器v的const首尾迭代器的函数是什么？
3. 如果容器中的对象是const的，返回的迭代器是什么类型的?
4. `*it.empty()`是什么意思？
5. 使用迭代器的循环体，可否向迭代器所属的容器添加元素？为什么？
6. 迭代器是否支持`>=`？
7. 迭代器的算术运算支持加法么？

## array

1. 是否可以用auto定义数组类型？
2. 是否存在引用的数组？
3. `char a[] = "C++"`这种初始化形式是否可用？
4. `int (*Parray)[10]`和`int (&arrRef)[10]`中，Parray和arrRef指的是什么？
5. 使用范围for语句遍历数组。
6. `int ia[]={0,1,2,3,4}; auto ia1(ia); decltype(ia) ia2 = {1,2,3,4,5}`，ia1和ia2有何区别？
7. 数组的类似迭代器的用法是什么？
8. 内置下标的索引值是什么类型？`int k = p[-2]；`合法么？
9. `cstring`头文件里的常用函数`strcmp`是干啥的？
10. string类型的变量怎样提供C风格字符串？是什么类型的？会一直有效么？
11. 使用for语句处理多维数组有啥建议？