//
// Created by weiheling on 2019/6/18.
//

#ifndef ALGORITHMS_STUDENT_H
#define ALGORITHMS_STUDENT_H

#include <iostream>
using namespace std;
struct Student {
    string name;
    int score;

    bool operator<(const Student& otherStudent){
        return score!=otherStudent.score ?
        score > otherStudent.score : name > otherStudent.name;
    }

/**
 * 对"<<"运算符的重载。
一般我们用的"<<"只能输出整型、实型等普通类型。
要想输出类类型，则必须对"<<"进行重载，其中一个参数为类类型对象。
为了方便对对象内部数据的操作，设置为friend友元函数。
为了能达到cout<<对象<<对象<<endl;的连续输出对象的效果，设置返回类型为引用。
参数：第一个为输出流对象。第二个为要输出的对象（为了防止产生临时对象、提高程序的效率，将参数设置为引用类型，但引用类型又能改变实参的值，所以设置为const）。
 */
 friend ostream& operator<<(ostream &os, const Student student){
     os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
 }
};
#endif //ALGORITHMS_STUDENT_H
