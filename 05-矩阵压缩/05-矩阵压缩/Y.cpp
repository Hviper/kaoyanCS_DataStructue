#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 100010;

int n, m;

int w[N];//记录一下权重

struct node {
    int l, r;//左右区间

    int sum;//总和
}tr[N * 4];//记得开 4 倍空间

void push_up(int u)//利用它的两个儿子来算一下它的当前节点信息
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;//左儿子 u<<1 ,右儿子 u<<1|1  
}

void build(int u, int l, int r)/*第一个参数，当前节点编号，第二个参数，左边界，第三个参数，右边界*/
{
    if (l == r)tr[u] = { l,r,w[r] };//如果当前已经是叶节点了，那我们就直接赋值就可以了
    else//否则的话，说明当前区间长度至少是 2 对吧，那么我们需要把当前区间分为左右两个区间，那先要找边界点
    {
        tr[u] = { l,r };//这里记得赋值一下左右边界的初值

        int mid = l + r >> 1;//边界的话直接去计算一下 l + r 的下取整

        build(u << 1, l, mid);//先递归一下左儿子

        build(u << 1 | 1, mid + 1, r);//然后递归一下右儿子

        push_up(u);//做完两个儿子之后的话呢 push_up 一遍u 啊，更新一下当前节点信息
    }
}

int query(int u, int l, int r)//查询的过程是从根结点开始往下找对应的一个区间
{
    if (l <= tr[u].l && tr[u].r <= r)return tr[u].sum;//如果当前区间已经完全被包含了，那么我们直接返回它的值就可以了
    //否则的话我们需要去递归来算
    int mid = tr[u].l + tr[u].r >> 1;//计算一下我们 当前 区间的中点是多少
    //先判断一下和左边有没有交集

    int sum = 0;//用 sum 来表示一下我们的总和

    if (mid >= l)sum += query(u << 1, l, r);//看一下我们当前区间的中点和左边有没有交集
    if (r >= mid + 1)//看一下我们当前区间的中点和右边有没有交集
        sum += query(u << 1 | 1, l, r);

    return sum;

}

void modify(int u, int x, int v)//第一个参数也就是当前节点的编号,第二个参数是要修改的位置，第三个参数是要修改的值
{
    if (tr[u].l == tr[u].r)tr[u].sum += v; //如果当前已经是叶节点了，那我们就直接让他的总和加上 v 就可以了
    //否则
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        //看一下 x 是在左半边还是在右半边
        if (x <= mid)modify(u << 1, x, v);//如果是在左半边，那就找左儿子
        else modify(u << 1 | 1, x, v);//如果在右半边，那就找右儿子

        //更新完之后当前节点的信息就要发生变化对吧，那么我们就需要 pushup 一遍

        push_up(u);
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)scanf("%d", &w[i]);

    build(1, 1, n);/*第一个参数是根节点的下标，根节点是一号点，然后初始区间是 1 到 n */

    //后面的话就是一些修改操作了

    while (m--) {
        int k, a, b;

        scanf("%d%d%d", &k, &a, &b);

        if (!k)printf("%d\n", query(1, a, b));//求和的时候，也是传三个参数，第一个的话是根节点的编号 ，第二个的话是我们查询的区间 
        //第一个参数也就是当前节点的编号
        else
            modify(1, a, b);//第一个参数是根节点的下标,第二个参数是要修改的位置，第三个参数是要修改的值

    }

    return 0;
}

