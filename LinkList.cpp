// LinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

typedef double ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

LinkList List_HeadInsert(LinkList& L) {         //头插法
    LNode *s; int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    cin >> x;
    while (x!= 999) {
        s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
    return L;
}

LinkList List_TailInsert(LinkList& L) {
    int x; LNode* s = new LNode; LinkList r;    //r是表尾指针
    L = new LNode;
    L->next = NULL;
    r = L;                                      //改变r->next会同样地影响到L->next，但改变r相当于把r的指向变了，并不会改变L
    cin >> x;
    while (x != 000) {
        s->data = x;
        r->next = s;
        r = r->next;
        cin >> x;
    }
    r->next = NULL;
    return L;
}

LinkList GetElem(LinkList L, int i) {           //按序号查找指针节点值
    int j = 1;
    LinkList p = L->next;
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}



int main()
{
    LinkList L;
    //List_HeadInsert(L);
    List_TailInsert(L);
    cout << L->next << endl;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
