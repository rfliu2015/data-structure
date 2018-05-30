#include "./header.hpp"
using namespace std;

typedef double ElemType;

void del_min(SqList& l, ElemType& value)
{
    if(l.length <= 0) {
        cerr << "Error!\n";
        exit(-1);
    }
    value = l[0];
    int pos = 0;
    for(unsigned i = 1; i < l.length; i++) {
        if(l[i] < value) {
            pos = i;
            value = l[i];
        }
    }
    l[pos] = l[l.length - 1];
    l.length--;

}

void reverse(SqList& l)
{
    ElemType e;
    for(unsigned i = 0; i < l.length / 2; i++) {
        e = l[i];
        l[i] = l[l.length - 1 - i];
        l[l.length - 1 - i] = e;
    }
}

void del_value_x1(SqList& l, ElemType x)
{
    unsigned i = 0, j = 0;
    for(; i < l.length; i++) {
        if(l[i] == x) {
            continue;
        } else {
            l[j++] = l[i];
        }
    }

    l.length = j;
}

void del_value_x2(SqList& l, ElemType x)
{
    unsigned i = 0, j = 0;
    for(; i < l.length; i++) {
        if(l[i] != x) {
            l[i - j] = l[i];
        } else {
            j++;
        }
    }

    l.length -= j;
}

//not原地新建表
void del_between_st(SqList& l, ElemType s, ElemType t)
{
    unsigned i, j;
    for(i = 0; i < l.length && l[i] < s; i++);
    for(j = i; j < l.length && l[j] <= t; j++);

    while(j < l.length) {
        l[i++] = l[j++];
    }

    l.length = i;
}

void del_repeat_value(SqList& l)
{
    unsigned i = 0, j = 0;
    for(j = 1; j < l.length; j++) {
        if(l[j] == l[i]) {
            continue;
        } else {
            l[i + 1] = l[j];
            i++;
        }
    }

    l.length = i + 1;
}

void test_del_min()
{
    double a[10] {18, 24, 53, 2, 4, 5, 6,  10, 6, 4};
    SqList s(a, 10);
    cout << s.length << endl;

    for(unsigned i = 0; i < s.length; i++) {
        cout << s[i] << "\t";
    }
    cout << endl;

    double b;
    del_min(s, b);

    cout << s.length << endl;
    cout << endl;
    for(unsigned i = 0; i < s.length; i++) {
        cout << s[i] << "\t";
    }
    cout << endl;

}

void test_reverse()
{
    double a[10] {18, 24, 53, 2, 4, 5, 6, 10, 6, 4};
    SqList s(a, 10);
    cout << s.length << endl;


    for(unsigned i = 0; i < s.length; i++) {
        cout << s[i] << "\t";
    }
    cout << endl;

    reverse(s);

    for(unsigned i = 0; i < s.length; i++) {
        cout << s[i] << "\t";
    }
    cout << endl;
}

void test_del_value_x1()
{
    double a[10] {18, 24, 53, 2, 4, 5, 6, 10, 6, 4};
    SqList s(a, 10);
    cout << s.length << endl;
    s.print();

    del_value_x1(s, 6);
    cout << s.length << endl;

    s.print();
}

void test_del_value_x2()
{
    double a[10] {18, 24, 53, 2, 4, 5, 6, 10, 6, 4};
    SqList s(a, 10);
    cout << s.length << endl;
    s.print();

    del_value_x2(s, 6);
    cout << s.length << endl;

}

void test_del_b_st()
{
    double a[10] {1, 2, 3, 5, 6, 7, 43, 332, 333, 388};
    SqList s(a, 10);
    cout << s.length << endl;
    s.print();

    del_between_st(s, 3, 50);
    cout << s.length << endl;
    s.print();

}

void test_del_repeat_value()
{
    double a[] {1, 1, 2, 2, 3, 3, 5, 5, 5, 5, 6, 7, 43, 43, 43 , 332, 333, 388};
    SqList s(a, sizeof(a) / sizeof(a[0]));

    cout << s.length << endl;
    s.print();

    del_repeat_value(s);

    cout << s.length << endl;
    s.print();
}

int main()
{
    /* test_del_value_x2(); */
    /* test_del_b_st(); */
    test_del_repeat_value();
    return 0;
}
