1.
-C помощью оператора .
Colors.blue = 5;
-C помощью списка инициализаторов 
Colors memberOfStruct{1,2,3};
-C помощью задания значений по умолчанию в самой структуре: 
int blue = 5;
-C помощью конструктора 
Colors(int _green = 2): green(_green) {};

2.
Для того, что задать значение по дефолту.

3.
---

4.
Если заведомо известен объем выделяемой памяти под конкретные значения полей структуры.

5.
Например, при операторах switch-case-default удобно использовать перечисление. При задании целого числа одному из элементов перечисления, то следующий будет на единицу выше и тд. 
