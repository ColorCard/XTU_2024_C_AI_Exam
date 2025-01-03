# 湘潭大学 - 人工智能专业 - 2024级大一C语言期末考试题库

共计**58个**题目，从头歌平台上抓取并排版，题目答案均为项目贡献参与者自做，目前**已经全部更新**完毕，有错误和出入还请谅解，欢迎各位提交 **issue** 和 **Pr**（请符合现有规范样式）！

你可以使用```Ctrl + F```来搜索你想要的题目，其中```[Mark]```标记的为我认为值得复习的一些有意思的题目，我会考虑后续加入一些注释。

觉得有用的话就留下一个 **Star⭐️** 吧！

---

## 题目 1: 输出所有大于平均值的数

**题目描述：**

输入n个整数，计算这些数的平均值，再输出所有大于平均值的数。  
例如，输入:  
     10  
     55 23 8 11 22 89 0 -1 78 186  
    输出：  
     55 89 78 186  
      
个人解答：[T1.c](Exam/T1.c)
```c
#include <stdio.h>
int main(){
        int n;
        scanf("%d",&n);
        int index=0;
        int a[100];
        for(int j=0 ; j<n; j++){
                scanf("%d",&a[j]);
                index+=a[j];
            }
        double avr=(double)index/n;
        for(int j=0 ; j<n; j++){
                if(a[j]>avr){
                        printf("%d ",a[j]);
                    }
            }
        return 0;
}
```

---

## 题目 2: 计算书费

**题目描述：**

下面是一个图书的单价表：  
计算概论 28.9元/本；数据结构与算法 32.7元/本；数字逻辑 45.6元/本；C++程序设计教程 78元/本；人工智能 35 元/本；计算机体系结构 86.2元/本；编译原理 27.8元/本；操作系统 43元/本；计算机网络 56元/本；JAVA程序设计 65元/本。  
给定每种图书购买的数量，编程计算应付的总费用。  
 **输入格式**  
输入一行，包含10个整数(大于等于0，小于等于100)，分别表示购买的《计算概论》、《数据结构与算法》、《数字逻辑》、《C++程序设计教程》、《人工智能》、《计算机体系结构》、《编译原理》、《操作系统》、《计算机网络》、《JAVA程序设计》的数量（以本为单位）。每两个整数用一个空格分开。  
  
 **输出格式**  
输出一行，包含一个浮点数f，表示应付的总费用。精确到小数点后一位。

个人解答：[T2.c](Exam/T2.c)
```c
#include <stdio.h>

int main(){
    int a[10];
    for(int i=0; i<10; i++){
        scanf("%d",&a[i]);
    }

    printf("%.1lf",a[0]*28.9+a[1]*32.7+a[2]*45.6+a[3]*78+a[4]*35+a[5]*86.2+a[6]*27.8+a[7]*43+a[8]*56+a[9]*65);

    return 0;
}
```

---

## 题目 3: 机器翻译 [Mark]

**题目描述：**

小晨的电脑上安装了一个机器翻译软件，他经常用这个软件来翻译英语文章。  
  
这个翻译软件的原理很简单，它只是从头到尾，依次将每个英文单词用对应的中文含义来替换。对于每个英文单词，软件会先在内存中查找这个单词的中文含义，如果内存中有，软件就会用它进行翻译；如果内存中没有，软件就会在外存中的词典内查找，查出单词的中文含义然后翻译，并将这个单词和译义放入内存，以备后续的查找和翻译。  
  
假设内存中有M个单元，每单元能存放一个单词和译义。每当软件将一个新单词存入内存前，如果当前内存中已存入的单词数不超过M−1，软件会将新单词存入一个未使用的内存单元；若内存中已存入M 个单词，软件会清空最早进入内存的那个单词，腾出单元来，存放新单词。  
      
假设一篇英语文章的长度为N个单词。给定这篇待译文章，翻译软件需要去外存查找多少次词典？假设在翻译开始前，内存中没有任何单词。  
  
 **输入格式**  
共2行。每行中两个数之间用一个空格隔开。第一行为两个正整数M和N，代表内存容量和文章的长度。第二行为N个非负整数，按照文章的顺序，每个数（大小不超过1000）代表一个英文单词。文章中两个单词是同一个单词，当且仅当它们对应的非负整数相同。  
  
 **输出格式**  
共1行，包含一个整数，为软件需要查词典的次数。  
如 **输入样例**  
3 7  
1 2 1 5 4 4 1  
 **输出样例**  
5

个人解答：[T3.c](Exam/T3.c)
```c
#include <stdio.h>

int judge(const int a[],int n,int m){
    for (int i = 0; i < n; ++i) {
        if(a[i]==m){
            return 1;
        }
    }
    return 0;
}

int main(){
    int M,N;
    scanf("%d %d",&M,&N);
    int b[M];

    for (int i = 0; i < M; ++i) {
        b[i]=-1;
    }

    int a[N];
    int index=0;//记录查词典的次数
    int temp=0;
    for (int i = 0; i < N; ++i) {
        scanf("%d",&a[i]);
        if(judge(b,M,a[i])==0){
            if(temp<M){
                b[temp]=a[i];
                index++;
                temp++;
            } else{
                for (int j = 0; j < M-1; ++j) {
                    b[j]=b[j+1];
                }
                b[M-1]=a[i];
                index++;
            }
        }else{
            continue;
        }
    }
    

    printf("%d\n",index);
    return 0;
}
```

---

## 题目 4: 短信计费

**题目描述：**

用手机发短信，一条短信资费为0.1元，但限定一条短信的内容在70个字以内(包括70个字）。如果你一次所发送的短信超过了70个字，则会按照每70个字一条短信的限制把它分割成多条短信发送。  
  
假设已经知道你当月所发送的短信的字数，试统计一下你当月短信的总资费。  
  
 **输入格式**  
第一行是整数n，表示当月发送短信的总次数，接着n行每行一个整数，表示每次短信的字数。  
  
 **输出格式**  
输出一行，当月短信总资费，单位为元，精确到小数点后1位。  
 **输入样例**  
10  
39  
49  
42  
61  
44  
147  
42  
72  
35  
4  
 **输出样例**  
1.3

个人解答：[T4.c](Exam/T4.c)
```c
#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);

    int index=0;
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d",&temp);
        index+=(temp+69)/70;
    }

    printf("%.1lf",index*0.1);

    return 0;
}
```

---

## 题目 5: 球弹跳高度的计算

**题目描述：**

一球从某一高度h落下(单位米，n≤1,000,000)，每次落地后反跳回原来高度的一半，再落下。编程计算气球在第10次落地时，共经过多少米? 第10次反弹多高？  
  
输出包含两行，第1行：到球第10次落地时，一共经过的米数。第2行：第10次弹跳的高度。  
  
输出结果保留小数点后4位。  
 **输入格式**  
输入一个正数h，表示球的初始高度。  
  
 **输出格式**  
第1行：到球第10次落地时，一共经过的米数。  
第2行：第10次弹跳的高度。  
如输入  
20  
输出  
59.9219  
0.0195  
  
个人解答：[T5.c](Exam/T5.c)
```c
#include <stdio.h>

int main(){
    double h;
    scanf("%lf",&h);
    double sum_height=0;
    for (int i = 0; i < 10; ++i) {
        sum_height+=h;
        h/=2;
        sum_height+=h;
    }

    printf("%.4lf\n%.4lf",sum_height-h,h);

    return 0;
}
```


---

## 题目 6: 年龄与疾病

**题目描述：**

某医院想统计一下某项疾病的获得与否与年龄是否有关，需要对以前的诊断记录进行整理，按照0-18、19-35、36-60、61以上（含61）四个年龄段统计的患病人数占总患病人数的比例。  
 **输入格式**  
共2行，第一行为过往病人的数目n（0 < n ≤ 100)，第二行为每个病人患病时的年龄。  
  
 **输出格式**  
按照0-18、19-35、36-60、61以上(含61)四个年龄段输出该段患病人数占总患病人数的比例，以百分比的形式输出，精确到小数点后两位。每个年龄段占一行，共四行。  
  
 **输入样例**  
10  
1 11 21 31 41 51 61 71 81 91  
 **输出样例**  
20.00%  
20.00%  
20.00%  
40.00%

个人解答：[T6.c](Exam/T6.c)
```c
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a = 0,b=0,c=0,d=0;
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        if(temp>=0&&temp<=18){
            a++;
        }else if(temp>=19&&temp<=35) {
            b++;
        } else if(temp>=36&&temp<=60){
            c++;
        } else{
            d++;
        }
    }

    printf("%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%\n", a*100.0/n, b*100.0/n, c*100.0/n, d*100.0/n);

    return 0;
}
```

---

## 题目 7: 骑车与走路

**题目描述：**

在清华校园里，没有自行车，上课办事会很不方便。但实际上。并非去办任何事情都是骑车快,因为骑车总要找车、开锁、停车、锁车等,这要耽误一些时间。假设找到自行车，开锁并车上自行车的时间为27秒；停车锁车的时间为23秒；步行每秒行走1.2米，骑车每秒行走3.0米。请判断走不同的距离去办事,是骑车快还是走路快。如果骑车快，输出一行"Bike"；如果走路快，输出一行"Walk"；如果一样快，输出一行"All"。  
  
 **输入格式**  
输入一行，包含一个整数，表示一次办事要行走的距离,单位为米。  
  
 **输出格式**  
输出一行,如果骑车快,输出一行"Bike";如果走路快,输出一行"Walk";如果一样快,输出一行"All"。  
  
 **输入样例**  
120  
  
 **输出样例**  
Bike

个人解答：[T7.c](Exam/T7.c)
```c
#include <stdio.h>

int main() {
    double distance;
    scanf("%lf", &distance);
    double Bike, Walk,All;

    Bike = distance / 3 + 50;
    Walk = distance / 1.2;

    if (Bike < Walk) {
        printf("Bike\n");
    } else if (Bike > Walk) {
        printf("Walk\n");
    } else {
        printf("All\n");
    }

    return 0;
}
```

---

## 题目 8: 交水费

**题目描述：**

小明家住湘潭，按照湘潭的水费政策实行阶梯水价。具体这么规定的：第一档水量：月用水量15吨以下（含15吨）；第二档水量：月用水量15吨至22吨（含22吨）；第三档水量：月用水量22吨以上。  
第一档水价2.58元/吨，第二档水价3.34元/吨，第三档水价4.09元/吨。  
请你帮小明算一下，他每个月应交的水费。水费是以分为单位的整数。  
比如用水量15吨，应交水费3870； 若用水量20吨，应交水费5540；若用水量25吨，应交水费7435。  
  
 **输入格式**  
一个大于等于0小于10000的整数，表示用水量（吨）  
 **输出格式**  
一个整数，表示应交的水费（单位：分）  
  
 **输入样例**  
24  
 **输出样例**  
7026

个人解答：[T8.c](Exam/T8.c)
```c
#include <stdio.h>

int main() {
    int water;
    scanf("%d", &water);
    double price = 0;
    if (water <= 15) {
        price = water * 2.58;
    } else if (water <= 22) {
        price = 15 * 2.58 + (water - 15) * 3.34;
    } else {
        price = 15 * 2.58 + 7 * 3.34 + (water - 22) * 4.09;
    }
    printf("%.0lf\n", price*100);
}

```

---

## 题目 9: 成绩排序 [Mark]

**题目描述：**

给定n（1≤n≤100）个学生的姓名和成绩，按照成绩从高到低排序输出。学生的姓名不会重复，如果有成绩相同的，则原来在名单中靠前的同学仍然排列在前面。  
例如有一个班的成绩如下：  
Deirdr 89  
Sheil 50  
Cynthi 63  
Rene 66  
Emm 46  
Myrn 42  
Nicol 63  
Prudenc 66  
Adel 79  
排序之后为：  
Deirdr 89  
Adel 79  
Rene 66  
Prudenc 66  
Cynthi 63  
Nicol 63  
Sheil 50  
Emm 46  
Myrn 42  
注意：Rene排在Prudenc之前，Cynthi排在Nicol之前。  
  
 **输入格式**  
第一行是一个整型数n，表示后面有n个学生的数据。从第二行到第n+1行，每行表示一个学生的数据，第一列是学生的姓名，第二列是学生的成绩（都是100以内的正整数），中间以空格分隔  
  
 **输出格式**  
排序得到的结果，每行一个学生的数据，第一列是姓名，第二列是他的成绩，中间以空格分隔。  
 **输入样例**  
6  
Jesu  76  
Ia  90  
Conno  80  
Carso  75  
Ayde  79  
Austi  78  
 **输出样例**  
Ia 90  
Conno 80  
Ayde 79  
Austi 78  
Jesu 76  
Carso 75

个人解答：[T9.c](Exam/T9.c)
```c
#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[20];
    int score;
};

typedef struct student Student;

int compare(const void *a, const void *b) {
    return ((Student *)b)->score - ((Student *)a)->score;
}//降序

int main() {
    int n;
    scanf("%d", &n);
    Student students[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
    }
    qsort(students, n, sizeof(Student), compare);

    for(int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].name, students[i].score);
    }

    return 0;
}
```

---

## 题目 10: 自由落体的时间

**题目描述：**

一个物体从高度h米（h≤100000000）的地方从静止开始自由落体，不计空气阻力，设重力加速度为9.8m/s^2，求落地所需时间（单位为秒），保留小数点后面2位数字.  
例如高度9.8米，落地时间为1.41秒  
再比如高度为100米，落地时间为4.52秒  
  
 **输入格式**  
一个浮点数，表示高度  
  
 **输出格式**  
一个浮点数，计算出来的秒数，小数点后保留两位小数  
  
 **输入样例**  
1.25  
 **输出样例**  
0.51

个人解答：[T10.c](Exam/T10.c)
```c
#include <stdio.h>
#include <math.h>

int main() {
    double height;
    double g=9.8;
    scanf("%lf", &height);
    double time = sqrt(2*height/g);
    printf("%.2lf", time);

}
```

---

## 题目 11: 苹果和虫子 [Mark]

**题目描述：**

你买了一箱n个苹果，很不幸的是买完时箱子里混进了一条虫子。虫子每x小时能吃掉一个苹果，假设虫子在吃完一个苹果之前不会吃另一个，那么经过y小时你还有多少个完整的苹果？  
 **输入格式**  
输入仅一行，包括n，x和y（均为整数）。  
  
 **输出格式**  
输出也仅一行，剩下的苹果个数。  
 **输入样例**  
10 4 9  
 **输出样例**  
7

个人解答：[T11.c](Exam/T11.c)
```c
#include <stdio.h>

int main() {
    long long n,x,y;
    scanf("%lld %lld %lld", &n, &x, &y);
    if(y>=x*n){
        printf("0");
    } else if(y%x==0){
        printf("%lld", n-(y/x));
    }else {
        printf("%lld", n-(y/x)-1);
    }

}
```

---

## 题目 12: 大象喝水

**题目描述：**

一只大象口渴了，要喝20升水才能解渴，但现在只有一个深h厘米，底面半径为r厘米的小圆桶(h和r都是整数)。问大象至少要喝多少桶水才会解渴。  
  
 **输入格式**  
输入有一行：包行两个整数，以一个空格分开，分别表示小圆桶的深h和底面半径r，单位都是厘米。  
  
 **输出格式**  
输出一行，包含一个整数，表示大象至少要喝水的桶数。  
  
 **输入样例**  
23 11  
 **输出样例**  
3

个人解答：[T12.c](Exam/T12.c)
```c
#include <stdio.h>
#include <math.h>

int main() {
    int h,r;
    scanf("%d %d",&h,&r);
    double v=3.14159*r*r*h;
    printf("%.0lf",ceil(20*1000/v));
}

```

---

## 题目 13: 不高兴的津津

**题目描述：**

津津上初中了。妈妈认为津津应该更加用功学习，所以津津除了上学之外，还要参加妈妈为她报名的各科复习班。另外每周妈妈还会送她去学习朗诵、舞蹈和钢琴。但是津津如果一天上课超过八个小时就会不高兴，而且上得越久就会越不高兴。假设津津不会因为其它事不高兴，并且她的不高兴不会持续到第二天。请你帮忙检查一下津津下周的日程安排，看看下周她会不会不高兴；如果会的话，哪天最不高兴。  
 **输入格式**  
包括七行数据，分别表示周一到周日的日程安排。每行包括两个小于10的非负整数，用空格隔开，分别表示津津在学校上课的时间和妈妈安排她上课的时间。  
  
 **输出格式**  
包括一行，这一行只包含一个数字。如果不会不高兴则输出0，如果会则输出最不高兴的是周几（用1, 2, 3, 4, 5, 6, 7分别表示周一，周二，周三，周四，周五，周六，周日）。如果有两天或两天以上不高兴的程度相当，则输出时间最靠前的一天。  
 **输入样例**  
5 3  
6 2  
7 2  
5 3  
5 4  
0 4  
0 6  
 **输出样例**  
3

@yestan1125 解答：[T13.c](Exam/T13.c)
```c
#include<stdio.h> 

int main()
{
	int i,cnt=0,time=0;
	int school[7] = {0}, mom[7] = {0};  
	for(i=0;i<7;i++){
		scanf("%d %d", &school[i], &mom[i]);
	}
	for(i=0;i<7;i++){
		if(school[i]+mom[i]>8 && school[i]+mom[i]>time){ 
			time = school[i]+mom[i];  
			cnt = i+1;  
		}
	}
	printf("%d",cnt);
	return 0;
}
```

---

## 题目 14: 矩阵中的最小元素

**题目描述：**

给定一个5X5的整数矩阵，找出其中最小的元素，输出所在的行号、列号和元素值，其中行号和列号都从0开始。  
例如，有矩阵：  
5 86 53 50 18  
25 67 79 44 68  
79 63 24 84 100  
42 30 59 47 37  
28 10 32 23 81  
其中最小元素的行号和列号都是0，值是5  
 **输入格式**  
一个5X5的矩阵，数据之间用空格隔开  
 **输出格式**  
一行，依次输出最小元素所在的行号、列号和值，中间以两个空格分隔  
 **输入样例**  
62 54 79 82 33   
88 45 91 14 58   
71 53 11 59 35   
35 37 14 46 67   
85 63 72 99 30  
 **输出样例**  
2  2  11

个人解答：[T14.c](Exam/T14.c)
```c
#include <stdio.h>

int main() {
    int a[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    int index_x=0,index_y=0;
    int min=(2^31)-1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(a[i][j] < min){
                index_x = i;
                index_y = j;
                min = a[i][j];
            }
        }
    }

    printf("%d  %d  %d", index_x, index_y, a[index_x][index_y]);//注意是两个空格！！
}
```

---

## 题目 15: 流感传染 [Mark]

**题目描述：**

有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的*矩阵，每个格点为一个房间，房间里可能住人，也可能空着。在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。请输出第m天得流感的人数。  
 **输入格式**  
第一行一个数字n，n不超过100，表示有n*n的宿舍房间。  
接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。  
接下来的一行是一个整数m，m不超过100。  
  
 **输出格式**  
输出第m天，得流感的人数。  
 **输入样例**  
5
....#
.#.@.
.#@..
#....
.....
4  
 **输出样例**  
16

个人解答：[T15.c](Exam/T15.c)
```c
#include <stdio.h>
#include <string.h>

void spread(char a[100][100], int n) {
    char temp[100][100];

    memcpy(temp, a, sizeof(temp));//复制到暂用数组

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '@') { // 如果当前房间已经得流感
                // 传染四个方向
                if (i - 1 >= 0 && a[i - 1][j] == '.') {
                    temp[i - 1][j] = '@'; // 上
                }
                if (i + 1 < n && a[i + 1][j] == '.') {
                    temp[i + 1][j] = '@'; // 下
                }
                if (j - 1 >= 0 && a[i][j - 1] == '.') {
                    temp[i][j - 1] = '@'; // 左
                }
                if (j + 1 < n && a[i][j + 1] == '.') {
                    temp[i][j + 1] = '@'; // 右
                }
            }
        }
    }

    memcpy(a, temp, sizeof(temp));//复制回来
}

int main() {
    int n;
    scanf("%d", &n);
    char a[100][100];

    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }

    int day;
    scanf("%d", &day);

    for(int k=0;k<day-1;k++){
        spread(a,n);
    }

    int count=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j]=='@'){
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}
```

---

## 题目 16: 简单排序

**题目描述：**

输入11个整数，如果第1个数为1，则将其中的第2至11个数升序排列；如果第1个数为0，则降序排列。  
 **输入格式**  
输入一行，包含11个整数，用空格符分隔。  
  
 **输出格式**  
输出1行，包含10个顺序排列的整数，用空格符分隔。  
  
 **输入样例**  
1 2 3 5 7 9 1 4 8 6 10  
 **输出样例**  
1 2 3 4 5 6 7 8 9 10  

个人解答：[T16.c](Exam/T16.c)
```c
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}//升序

int in_compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}//降序

int main() {
    int a[11];
    for (int i = 0; i < 11; ++i) {
        scanf("%d", &a[i]);
    }
    if (a[0] == 1) {
        qsort(a+1, 10, sizeof(int), compare);
    }else{
        qsort(a+1, 10, sizeof(int), in_compare);
    }

    for (int i = 1; i < 11; ++i) {
        printf("%d ", a[i]);
    }

}
```


---

## 题目 17: 求阶乘的和

**题目描述：**

给定正整数n，求不大于n（n≤13）的正整数的阶乘的和（即求1!+2!+3!+...+n!），输出阶乘的和。  
 **输入格式**  
输入有一行，包含一个正整数n（1 < n < 12）。  
  
 **输出格式**  
输出有一行：阶乘的和。  
  
 **输入样例**  
5  
 **输出样例**  
153

个人解答：[T17.c](Exam/T17.c)
```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long sum=0;
    long long index=1;
    for (int i = 1; i <= n; ++i) {
        index*=i;
        sum+=index;
    }
    printf("%lld", sum);
}
```

---

## 题目 18: 与指定数字相同的数的个数

**题目描述：**

输出一个整数序列中与指定数字相同的数的个数。输入包含2行：第1行为N和m，N表示整数序列的长度(N≤100)；m表示指定的数字；第2行为N个整数，整数之间以空格分开。输出为N个数中与m相同的数的个数。  
 **输入格式**  
第1行为N和m，表示整数序列的长度(N≤100)和指定的数字， 中间用一个空格分开；  
  
第2行为N个整数，整数之间以一个空格分开。  
  
 **输出格式**  
输出为N个数中与m相同的数的个数。  
 **输入样例**  
3 2  
2 3 2  
 **输出样例**  
2

个人解答：[T18.c](Exam/T18.c)
```c
#include <stdio.h>

int main() {
    int N,m;
    scanf("%d %d",&N,&m);

    int count=0;
    int a[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
        if(a[i]==m){
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
```

---

## 题目 19: 开关灯

**题目描述：**

假设有N盏灯(N为不大于5000的正整数)，从1到N按顺序依次编号，初始时全部处于开启状态；有M个人(M为不大于N的正整数)也从1到M依次编号。  
  
第一个人(1号)将灯全部关闭，第二个人(2号)将编号为2的倍数的灯打开，第三个人(3号)将编号为3的倍数的灯做相反处理（即将打开的灯关闭，将关闭的灯打开）。依照编号递增顺序，以后的人都和3号一样，将凡是自己编号倍数的灯做相反处理。  
  
请问：当第M个人操作之后，哪几盏灯是关闭的，按从小到大输出其编号，其间用逗号间隔。  
 **输入格式**  
输入正整数N和M，以单个空格隔开。  
  
 **输出格式**  
顺次输出关闭的灯的编号，其间用逗号间隔。  
 **输入样例**  
12  
6  
 **输出样例**  
1,4,7,8,10,11,12

个人解答：[T19.c](Exam/T19.c)
```c
#include <stdio.h>

void LED(int a[],int n,int index){
    for (int i = 0; i < n; ++i) {
        if((i+1)%index==0){
            a[i]=!a[i];
        }
    }
}

int main() {
    int N,M;
    scanf("%d %d", &N, &M);

    int a[50001];
    for (int i = 0; i < N; ++i) {
        a[i]=1;
    }

    for (int i = 1; i <= M; ++i) {
        LED(a,N,i);
    }

    int flag=0;
    for (int i = 0; i < N; ++i) {
        if(a[i]==0) {
            if(flag==0){
                printf("%d", i+1);
                flag=1;
            } else{
                printf(",%d", i+1);
            }
        }
    }

    return 0;
}
```

---

## 题目 20: 个人所得税

**题目描述：**

我国从2021年元月起，执行新的个人所得税征收办法，按纳税年度合并计算个人所得税，如全年收入不超过6万元，应缴税率0%；如超过6万元，应先减去6万元，再按照下面的超额累进税率进行计算：  
  
不超过36000元的部分,应缴税率3%；  
超过36000元至144000元的部分，应缴税率10%；  
超过144000元至300000元的部分，应缴税率20%；  
超过300000元至420000元的部分，应缴税率25%；  
超过420000元至660000元的部分，应缴税率30%；  
超过660000元至960000元的部分，应缴税率35%；  
超过960000的部分，应缴税率45%。  
  
如某人年收入50000元，应缴税款0元；  
年收入96000元，应缴税款1080元；  
年收入120000元，应缴税款3480元；  
年收入240000元，应缴税款19080元；  
年收入360000元，应缴税款43080元；  
年收入480000元，应缴税款73080元；  
年收入1200000元，应缴税款331080元。  
  
 **输入格式**  
一个正整数n（0≤n≤10,000,000），表示全年收入  
  
 **输出格式**  
一个正整数，表示应缴税款。如税款带有小数部分，则舍去小数部分。  
 **输入样例**  
66000  
 **输出样例**  
180

个人解答：[T20.c](Exam/T20.c)
```c
#include <stdio.h>

int main() {
    double n;
    scanf("%lf", &n);

    double income=n-60000;
    double tax=0;

    if(income<=0){
        tax=0;
    } else if(income<=36000){
        tax=income*0.03;
    } else if(income<=144000){
        tax=income*0.1-2520;
    } else if(income<=300000){
        tax=income*0.2-16920;
    } else if(income<=420000){
        tax=income*0.25-31920;
    } else if(income<=660000){
        tax=income*0.3-52920;
    } else if(income<=960000){
        tax=income*0.35-85920;
    } else {
        tax=income*0.45-181920;
    }

    printf("%.0lf", tax);

    return 0;
}
```

---

## 题目 21: 奇数求和

**题目描述：**

计算非负整数m到n(包括m和n)之间的所有奇数的和，其中，m 不大于 n，且n 不大于300。例如 m=3, n=12, 其和则为：3+5+7+9+11=35。  
 **输入格式**  
两个数 m 和 n，两个数以一个空格分开，其中 0 ≤ m ≤ n ≤ 300 。  
 **输出格式**  
输出一行，包含一个整数，表示m 到 n（包括m 和 n ）之间的所有奇数的和。  
 **输入样例**  
7 15  
 **输出样例**  
55

个人解答：[T21.c](Exam/T21.c)
```c
#include <stdio.h>

int main() {
    int m,n;
    scanf("%d %d", &m, &n);
    int sum=0;
    for (int i = m; i <= n; ++i) {
        if(i%2!=0){
            sum+=i;
        }
    }

    printf("%d", sum);

    return 0;
}
```

---

## 题目 22: 求小数的某一位 [Mark]

**题目描述：**

分数a/b化为小数后，小数点后第n位的数字是多少？其中0 < a < b < 100，1≤n≤10000。  
 **输入格式**  
三个正整数a，b，n，相邻两个数之间用单个空格隔开。  
 **输出格式**  
一个数字  
 **输入样例**  
1 2 1  
 **输出样例**  
5

个人解答：[T22.c](Exam/T22.c)
```c
#include <stdio.h>

int findNthDigitOfFraction(int a, int b, int n) {
    int i, result;
    a %= b;

    for (i = 0; i < n; i++) {
        a *= 10;
        result = a / b;
        a %= b;
    }

    return result;
}

int main() {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);

    int nthDigit = findNthDigitOfFraction(a, b, n);
    printf("%d", nthDigit);

    return 0;
}
```
---

## 题目 23: 判断闰年

**题目描述：**

判断某年是否是闰年。如果是闰年则输出Y，否则输出N。  
注意：能被4整除的年份不一定是闰年，比如1900不是闰年，因为它能被100整除，而不能被400整除。2000年是闰年，因为它能被400整除。1984、1988是闰年，它们都能被4整除而不能被100整除。  
  
 **输入格式**  
输入只有一行，包含一个整数a(0 ≤ a ≤10000)。  
 **输出格式**  
一行，如果公元a年是闰年输出Y，否则输出N。  
 **输入样例**  
2006  
 **输出样例**  
N

个人解答：[T23.c](Exam/T23.c)
```c
#include <stdio.h>

int main() {
    int year;
    scanf("%d", &year);

    if(year%4==0 && year%100!=0 || year%400==0){
        printf("Y");
    } else{
        printf("N");
    }
    return 0;
}
```

---

## 题目 24: 判断一个数能否同时被3和5整除

**题目描述：**

判断一个数n 能否同时被3和5整除，如果能同时被3和5整除输出YES，否则输出NO。  
例如当n=30，输出：YES   当n=81，输出：NO  
 **输入格式**  
输入一行，包含一个整数n。（ -1,000,000 ≤n ≤ 1,000,000）  
 **输出格式**  
输出一行，如果能同时被3和5整除输出YES，否则输出NO。

个人解答：[T24.c](Exam/T24.c)
```c
#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    if(n%3==0&&n%5==0){
        printf("YES");
    } else{
        printf("NO");
    }
    return 0;
}
```

---

## 题目 25: 字符三角形

**题目描述：**

给定一个字符，用它构造一个底边长5个字符，高3个字符的等腰字符三角形。  
 **输入格式**  
只有一行，就是一个字符。  
 **输出格式**  
三行，每行都是由输入的字符组成，字符个数分别是1、3、5。  
 **输入样例**  
*  
 **输出样例**  
```
  *  
 ***  
*****
```

个人解答：[T25.c](Exam/T25.c)
```c
#include <stdio.h>

int main() {
    char a;
    scanf("%c", &a);

    printf("  %c\n %c%c%c\n%c%c%c%c%c\n", a, a, a, a, a, a, a, a, a);
}
```

---

## 题目 26: 判断能否被3，5，7整除

**题目描述：**

给定一个整数，判断它能否被3，5，7整除，并输出以下信息：  
  
   1、能同时被3，5，7整除（直接输出3 5 7，每个数中间一个空格）；  
   2、只能被其中两个数整除（输出两个数，小的在前，大的在后。例如：3 5或者 3 7或者5 7，中间用空格分隔）；  
   3、只能被其中一个数整除（输出这个除数）；  
   4、不能被任何数整除，输出小写字符‘n’，不包括单引号。  
     
 **输入格式**  
输入一行，包括一个整数。  
 **输出格式**  
输出一行，按照描述要求给出整数被3，5，7整除的情况。  
  
 **输入样例**  
195  
 **输出样例**（疑似出错）
3   5   7

个人解答：[T26.c](Exam/T26.c)
```c
// 这是文件 T26.c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int count=0;
    if(n%3==0) {
        count++;
        printf("3 ");
    }
    if(n%5==0){
        count++;
        printf("5 ");
    }
    if(n%7==0) {
        count++;
        printf("7 ");
    }

    if(count==0){
        printf("n");
    }

    return 0;
}
```

---

## 题目 27: 打印ASCII码

**题目描述：**

输入一个除空格以外的可见字符（可以用键盘输入的字符），输出其ASCII码。  
 **输入格式**  
一个除空格以外的可见字符。  
 **输出格式**  
一个十进制整数，即该字符的ASCII码。  
 **输入样例**  
A  
 **输出样例**  
65

个人解答：[T27.c](Exam/T27.c)
```c
#include <stdio.h>

int main() {
    char n;
    scanf("%c", &n);
    printf("%d", n);
    return 0;
}
```

---

## 题目 28: 计算分数的浮点数值

**题目描述：**

两个整数a和b分别作为分子和分母，既分数a/b，求它的浮点数值(双精度浮点数，保留小数点后9位)。  
 **输入格式**  
输入仅一行，包括两个整数a和b。  
  
 **输出格式**  
输出也仅一行，分数 a/b 的浮点数值（双精度浮点数，保留小数点后9位）。  
  
 **输入样例**  
5 7  
 **输出样例**  
0.714285714

个人解答：[T28.c](Exam/T28.c)
```c
#include <stdio.h>

int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    double c=(double)a/b;
    printf("%.9lf", c);
    return 0;
}
```


---

## 题目 29: 对齐输出

**题目描述：**

读入三个整数，按每个整数占8个字符的宽度，右对齐输出它们。  
 **输入格式**  
只有一行，按照格式要求依次输入三个整数，之间以一个空格分开。  
  
 **输出格式**  
只有一行，三个整数，即输入三个整数。  
  
 **输入样例**  
123456789 0 -1  
 **输出样例**  
`123456789        0       -1`

个人解答：[T29.c](Exam/T29.c)
```c
#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%8d %8d %8d", a, b, c);//%-8d是左对齐
    return 0;
}
```

---

## 题目 30: 合法C标识符

**题目描述：**

给定一个不包含空白符的字符串，请判断是否是C语言合法的标识符号(注：题目保证这些字符串一定不是C语言的保留字)。  
  
C语言标识符要求：  
1.非保留字；2.只包含字母、数字及下划线（“_”）。3.不以数字开头。  
 **输入格式**  
一行，包含一个字符串，字符串中不包含任何空白字符，且长度不大于20。  
  
 **输出格式**  
一行，如果它是C语言的合法标识符，则输出yes，否则输出no。  
 **输入样例**  
RKPEGX9R;TWyYcp  
 **输出样例**  
no

个人解答：[T30.c](Exam/T30.c)
```c
#include <stdio.h>
#include <string.h>

int main() {
    char a[100];
    scanf("%s", a);

    if(strlen(a)>20) {
        printf("no");
        return 0;
    }

    if(a[0] >= '0' && a[0] <= '9') {
        printf("no");
        return 0;
    }

    for (int i = 0; a[i] != '\0'; i++) {
        if((a[i]<'z'&&a[i]>'a')|| (a[i]<'Z'&&a[i]>'A')|| a[i]=='_'|| (a[i]>='0'&&a[i]<='9')) {
            continue;
        } else{
            printf("no");
            return 0;
        }
    }

    printf("yes");

    return 0;
}
```

---

## 题目 31: 最大最小值

**题目描述：**

给定n个整数，求出其中的最大值和最小值  
比如给定9个整数： 12 45 62 35 74 11 96 32，最大值是96，最小值是11  
再比如给定10个整数：14 52 63 69 58 47 10 5 99 88，最大值是99，最小值是5  
再比如给定12个整数：15 25 84 74 96 2 30 14 25 18 55 33，最大值是96，最小值是2  
 **输入格式**  
两行。第一行是一个正整数n（2≤n≤10,000），表示后续的整数个数。第二行是n个正整数，中间以1个空格分隔。  
 **输出格式**  
两个整数值，第一个是最大值，第二个是最小值，中间以2个空格分隔  
  
 **输入样例**  
15  
12  32  69  84  71  20  35  31  25  29  68  36  48  47  9  
 **输出样例**  
84  9

个人解答：[T31.c](Exam/T31.c)
```c
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return -(*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[10000];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare);

    printf("%d  %d", a[0], a[n-1]);

    return 0;
}
```

---

## 题目 32: 幂的末尾 [Mark]

**题目描述：**

a^b的末3位数是多少？  
 **输入格式**  
两个正整数a，b。1≤a≤100，1≤b≤10000。  
 **输出格式**  
从高位到低位输出幂的末三位数字，中间无分隔符。若幂本身不足三位，在前面补零。  
  
 **输入样例**  
7 2011  
 **输出样例**  
743

个人解答：[T32.c](Exam/T32.c)
```c
#include <stdio.h>

int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    int index= 1;
    for (int i = 0; i < b; ++i) {
        index*=a;
        index%=1000;
    }

    printf("%03d", index);

    return 0;
}
```

---

## 题目 33: 求一元二次方程

**题目描述：**

求一元二次方程“ax^2+bx+c=0”的根，其中a不等于0。结果要求精确到小数点后5位。  
若两个实根相等，则输出形式为：“x1=x2=XXX.XXXXX”；  
若两个实根不等，需满足根小者在前的原则，中间用分号隔开，输出形式为：“x1=XX.XXXXX;x2=XX.XXXXX"；  
若无实根输出“No answer!”。  
 **输入格式**  
输入一行，包含三个浮点数a, b, c（它们之间以一个空格分开），分别表示方程a的系数。  
 **输出格式**  
输出一行，表示方程的解。  
所有输出部分要求精确到小数点后5位，数字、符号之间没有空格。  
  
 **输入样例**  
-15.97 19.69 12.02  
 **输出样例**  
x1=-0.44781;x2=1.68075

个人解答：[T33.c](Exam/T33.c)
```c
#include <stdio.h>
#include <math.h>

int main() {
    double a,b,c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double delta=b*b-4*a*c;
    if(delta<0){
        printf("No answer!");
    } else if(delta==0){
        double x1=-b/(2*a);
        printf("%.2lf", x1);
    } else{
        double x1=(-b+sqrt(delta))/(2*a);
        double x2=(-b-sqrt(delta))/(2*a);
        if(x1>x2){
            double temp=x1;
            x1=x2;
            x2=temp;
        }
        printf("%.2lf %.2lf", x1, x2);
    }

    return 0;
```


---

## 题目 34: 有一门课不及格的学生

**题目描述：**

给出一名学生的语文和数学成绩，判断他是否恰好有一门课不及格(成绩小于60分)。若该生恰好有一门课不及格，输出1；否则输出0。  
 **输入格式**  
一行，包含两个在0到100之间的整数，分别是该生的语文成绩和数学成绩。  
 **输出格式**  
若该生恰好有一门课不及格，输出1；否则输出0。  
 **输入样例**  
50 80  
 **输出样例**  
1

个人解答：[T34.c](Exam/T34.c)
```c
#include <stdio.h>

int main() {
    int chinese,math;
    scanf("%d %d", &chinese, &math);

    if(chinese>=60&&math>=60){
        printf("0");
    } else if(chinese>=60||math>=60){
        printf("1");
    } else{
        printf("0");
    }
    return 0;
}
```


---

## 题目 35: 奇偶数判断

**题目描述：**

给定一个整数，判断该数是奇数还是偶数。如果n是奇数，输出odd；如果n是偶数，输出even。  
 **输入格式**  
输入仅一行，一个大于零的正整数n。  
 **输出格式**  
输出仅一行，如果n是奇数，输出odd;如果n是偶数，输出even。  
 **输入样例**  
5  
 **输出样例**  
odd

个人解答：[T35.c](Exam/T35.c)
```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n%2==0){
        printf("even");
    } else{
        printf("odd");
    }
    return 0;
}
```

---

## 题目 36: 收集瓶盖赢大奖

**题目描述：**

某饮料公司最近推出了一个“收集瓶盖赢大奖”的活动：如果你拥有10个印有“幸运”、或20个印有“鼓励”的瓶盖，就可以兑换一个神秘大奖。现分别给出你拥有的印有“幸运”和“鼓励”的瓶盖数，判断是否可以去兑换大奖。若可以兑换大奖，输出1，否则输出0。  
 **输入格式**  
一行，包含两个整数，分别是印有“幸运”和“鼓励”的瓶盖数，用一个空格隔开。  
 **输出格式**  
一行。若可以兑换大奖，输出1，否则输出0。  
 **输入样例**  
11 19  
 **输出样例**  
1

个人解答：[T36.c](Exam/T36.c)
```c
#include <stdio.h>

int main() {
    int lucky,encourage;
    scanf("%d %d", &lucky, &encourage);

    if(lucky>=10||encourage>=20){
        printf("1");
    } else{
        printf("0");
    }
    return 0;
}
```

---

## 题目 37: 奖学金 [Mark]

**题目描述：**

某小学最近得到了一笔赞助，打算拿出其中一部分为学习成绩优秀的前5名学生发奖学金。期末，每个学生都有3门课的成绩:语文、数学、英语。先按总分从高到低排序，如果两个同学总分相同，再按语文成绩从高到低排序，如果两个同学总分和语文成绩都相同，那么规定学号小的同学排在前面，这样，每个学生的排序是唯一确定的。  
  
任务：先根据输入的3门课的成绩计算总分，然后按上述规则排序，最后按排名顺序输出前五名名学生的学号和总分。注意，在前5名同学中，每个人的奖学金都不相同，因此，你必须严格按上述规则排序。例如，在某个正确答案中，如果前两行的输出数据(每行输出两个数:学号、总分) 是:  
7 279  
5 279  
这两行数据的含义是:总分最高的两个同学的学号依次是7号、5号。这两名同学的总分都是 279 (总分等于输入的语文、数学、英语三科成绩之和) ，但学号为7的学生语文成绩更高一些。如果你的前两名的输出数据是:  
5 279  
7 279  
则按输出错误处理，不能得分。  
  
 **输入格式**  
包含n+1行:  
  
第1行为一个正整数n（小于300），表示该校参加评选的学生人数。  
第2到n+1行，每行有3个用空格隔开的数字，每个数字都在0到100之间。第j行的3个数字依次表示学号为 j-1 的学生的语文、数学、英语的成绩。每个学生的学号按照输入顺序编号为1~n (恰好是输入数据的行号减1)。  
 **输出格式**  
共有5行，每行是两个用空格隔开的正整数，依次表示前5名学生的学号和总分。  
  
 **输入样例**  
6  
90 67 80  
87 66 91  
78 89 91  
88 99 77  
67 89 64  
78 89 98  
 **输出样例**  
6   265  
4   264  
3   258  
2   244  
1   237

个人解答：[T37.c](Exam/T37.c)
```c
#include <stdio.h>
#include <stdlib.h>

struct student{
    int id;
    int chinese;
    int math;
    int english;
};

typedef struct student Student;

int compare(const void *a, const void *b) {
    if (((Student *)b)->chinese+((Student *)b)->math+((Student *)b)->english != ((Student *)a)->chinese+((Student *)a)->math+((Student *)a)->english) {
        return ((Student *)b)->chinese+((Student *)b)->math+((Student *)b)->english - ((Student *)a)->chinese+((Student *)a)->math+((Student *)a)->english;
    } else if (((Student *)b)->chinese != ((Student *)a)->chinese) {
        return ((Student *)b)->chinese - ((Student *)a)->chinese;
    } else {
        return ((Student *)a)->id - ((Student *)b)->id;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Student students[n];
    for (int i = 0; i < n; ++i) {
        students[i].id=i+1;
        scanf("%d %d %d",  &students[i].chinese, &students[i].math, &students[i].english);
    }

    qsort(students, n, sizeof(Student), compare);

    for (int i = 0; i < 5; ++i) {
        printf("%d  %d\n", students[i].id, students[i].chinese+students[i].math+students[i].english);
    }
    return 0;
}
```

---

## 题目 38: 谁拿了最多奖学金 [Mark]

**题目描述：**

某校的惯例是在每学期的期末考试之后发放奖学金。发放的奖学金共有五种，获取的条件各自不同：  
1) 院士奖学金，每人8000元，期末平均成绩高于80分（>80），并且在本学期内发表1篇或1篇以上论文的学生均可获得；  
2) 五四奖学金，每人4000元，期末平均成绩高于85分（>85），并且班级评议成绩高于80分（>80）的学生均可获得；  
3) 成绩优秀奖，每人2000元，期末平均成绩高于90分（>90）的学生均可获得；  
4) 西部奖学金，每人1000元，期末平均成绩高于85分（>85）的西部省份学生均可获得；  
5) 班级贡献奖，每人850元，班级评议成绩高于80分（>80）的学生干部均可获得；  
只要符合条件就可以得奖，每项奖学金的获奖人数没有限制，每名学生也可以同时获得多项奖学金。例如姚林的期末平均成绩是87分，班级评议成绩82分，同时他还是一位学生干部，那么他可以同时获得五四奖学金和班级贡献奖，奖金总数是4850元。  
  
现在给出若干学生的相关数据，请计算哪些同学获得的奖金总数最高（假设总有同学能满足获得奖学金的条件）。  
 **输入格式**  
输入的第一行是一个整数N（1 <= N <= 100），表示学生的总数。  
接下来的N行每行是一位学生的数据，从左向右依次是姓名，期末平均成绩，班级评议成绩，是否是学生干部，是否是西部省份学生，以及发表的论文数。  
姓名是由大小写英文字母组成的长度不超过20的字符串（不含空格）；期末平均成绩和班级评议成绩都是0到100之间的整数（包括0和100）；是否是学生干部和是否是西部省份学生分别用一个字符表示，Y表示是，N表示不是；发表的论文数是0到10的整数（包括0和10）。  
每两个相邻数据项之间用一个空格分隔。  
 **输出格式**  
输出包括三行，第一行是获得最多奖金的学生的姓名，第二行是这名学生获得的奖金总数。  
如果有两位或两位以上的学生获得的奖金最多，输出他们之中在输入文件中出现最早的学生的姓名。  
第三行是这N个学生获得的奖学金的总数。  
  
 **输入样例**  
4  
YaoLin 87 82 Y N 0  
ChenRuiyi 88 78 N Y 1  
LiXin 92 88 N N 0  
ZhangQin 83 87 Y N 1  
  
 **输出样例**  
ChenRuiyi  
9000  
28700

个人解答：[T38.c](Exam/T38.c)
```c
#include <stdio.h>


struct student{
    char name[20];
    int end_socre;
    int class_socre;
    int section1;
    int section2;
    int article;
    int sum;
};

int main() {
    int N;
    scanf("%d", &N);
    struct student students[N];
    for (int i = 0; i < N; ++i) {
        scanf("%s %d %d", students[i].name, &students[i].end_socre, &students[i].class_socre);
        getchar();
        if(getchar()=='Y'){
            students[i].section1=1;
        } else{
            students[i].section1=0;
        }
        getchar();
        if(getchar()=='Y'){
            students[i].section2=1;
        } else{
            students[i].section2=0;
        }
        scanf("%d", &students[i].article);
    }

    for (int i = 0; i < N; ++i) {
        students[i].sum=0;
        if(students[i].end_socre>80&&students[i].article>=1){
            students[i].sum+=8000;
        }
        if(students[i].end_socre>85&&students[i].class_socre>80){
            students[i].sum+=4000;
        }
        if(students[i].end_socre>90){
            students[i].sum+=2000;
        }
        if(students[i].end_socre>85&&students[i].section2==1){
            students[i].sum+=1000;
        }
        if(students[i].class_socre>80&&students[i].section1==1){
            students[i].sum+=850;
        }

    }

    int max=0;
    int index=0;
    for (int i = 0; i < N; ++i) {
        if(students[i].sum>max){
            max=students[i].sum;
            index=i;
        }
    }

    int sum=0;
    for (int i = 0; i < N; ++i) {
        sum+=students[i].sum;
    }

    printf("%s\n%d\n%d\n", students[index].name, students[index].sum, sum);


    return 0;
}
```

---

## 题目 39: 查找高频词 [Mark]

**题目描述：**

给定一个由英文字符、数字、空格和英文标点符号组成的字符串，长度不超过5000，请将其切分为单词，**要求去掉所有的非英文字母**，然后将**单词全部转换成小写**，然后统计每一个词出现的次数，输出频次最高的那个词以及它出现的次数。如果有多个词的频次相同，则输出按字典序排列在最前面的那个。  
  
例如给定字符串：String input = "1 fish 2 fish red fish blue fish";  
频次最高的单词是fish，它出现了4次。  
  
再比如给定字符串：If the digit is less than 10, then '0' + digit is returned. Otherwise, the value 'a' + digit - 10 is returned.  
频次最高的单词是digit和is，都出现了3次。但是digit的字典序在is前面，所以应该输出digit和3。  
  
 **输入格式**  
一个长度不超过2000的字符串，只有末尾有回车符。  
  
 **输出格式**  
输出一行，首先是频次最高的那个单词，然后是它出现的次数，中间用空格分隔  
  
 **输入样例**  
A character may be part of a Unicode identifier if and only if one of the following statements is true.  
 **输出样例**  
a  2

个人解答：[T39.c](Exam/T39.c)
```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 2000

typedef struct {
    char word[50];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;
    if (wordA->count != wordB->count) {
        return wordB->count - wordA->count;  // 按频次降序排序
    }
    return strcmp(wordA->word, wordB->word);  // 频次相同按字典序升序
}

void processInput(char *input, WordCount *wordCounts, int *size) {
    char word[50];
    int len = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            word[len++] = tolower(input[i]);
        } else if (len > 0) {
            word[len] = '\0';
            len = 0;

            // 查找是否已存在
            int found = 0;
            for (int j = 0; j < *size; j++) {
                if (strcmp(wordCounts[j].word, word) == 0) {
                    wordCounts[j].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(wordCounts[*size].word, word);
                wordCounts[*size].count = 1;
                (*size)++;
            }
        }
    }
    if (len > 0) {  // 处理最后一个单词
        word[len] = '\0';
        int found = 0;
        for (int j = 0; j < *size; j++) {
            if (strcmp(wordCounts[j].word, word) == 0) {
                wordCounts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(wordCounts[*size].word, word);
            wordCounts[*size].count = 1;
            (*size)++;
        }
    }
}

int main() {
    char input[MAX_LEN];
    WordCount wordCounts[1000];
    int size = 0;

    // 输入字符串
    fgets(input, MAX_LEN, stdin);

    // 处理输入
    processInput(input, wordCounts, &size);

    // 排序
    qsort(wordCounts, size, sizeof(WordCount), compare);

    // 输出结果
    printf("%s %d\n", wordCounts[0].word, wordCounts[0].count);

    return 0;
}
```

---

## 题目 40: 最高的分数

**题目描述：**

老师讲授的《计算概论》这门课期中考试刚刚结束，他想知道考试中取得的最高分数。因为人数比较多，他觉得这件事情交给计算机来做比较方便。你能帮老师解决这个问题吗？  
例如有成绩：68 61 25 54 84 96 34，最高分数96  
又比如有成绩：59 90 92 93 94 91，最高分数94  
  
一共有两行，第一行为整数n（1 ≤ n ≤100），表示参加这次考试的人数。第二行是这n个学生的成绩，相邻两个数之间用空格隔开。所有成绩均为0到100之间的整数。  
  
 **输出格式**  
输出一个整数，即最高的成绩。  
 **输入样例**  
5   
85 78 90 99 60  
 **输出样例**  
99

个人解答：[T40.c](Exam/T40.c)
```c
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
    return -(*(int *)a-*(int *)b);
}//降序

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    qsort(a,n, sizeof(int),compare);

    printf("%d", a[0]);
    return 0;
}
```

---

## 题目 41: 高考志愿排序 [Mark]

**题目描述：**

我国的高考志愿投档是严格按照高考分数从高到低的顺序排列，排列的规则如下：首先按照总分降序排列；当总分相同时，再按照语文分数降序排序；当语文分数也相同时，再按照数学分数降序排序；当数学分数也相同时，再按照英语分数降序排序。所有分数都相同时，再按照录入的顺序排列。这样，每个考生的位序都是唯一的。  
现在给定n（10≤n≤1000）个人的有关信息，按照上述规则排序之后，输出最前面的m（1≤m≤n）个人的序号。  
例如有10个人的成绩（每一行依次是语、数、外成绩；学生的序号从1开始，就是他所在的行数）如下：  
73 76 78  
74 77 77  
71 79 79  
75 74 77  
71 72 70  
71 75 79  
79 74 73  
73 75 74  
73 70 79  
77 79 70  
正确的排序结果如下：  
3 2 1 7 10 4 6 8 9 5  
  
再比如有10个考生的成绩如下：  
66 60 63  
61 63 60  
63 65 60  
69 60 60  
64 68 69  
68 62 63  
63 67 67  
69 68 61  
65 60 65  
62 65 65  
排序结果如下：  
5 8 7 6 10 9 4 1 3 2  
  
 **输入格式**  
第一行是两个整数n和m，表示后续有n个考生的信息，要求输出m个考生的序号。从第2行到n+1行，每行一个考生的信息，依次是：语文分、数学分、英语分。 注意：学生的序号从1开始计数，就是它所在的行号减一  
  
 **输出格式**  
输出m个整数，表示排序后的前m个考生的序号，整数之间用空格分隔。  
 **输入样例**  
10  5  
  73  71  72  
  68  70  63  
  74  78  63  
  73  66  68  
  61  61  61  
  63  79  79  
  70  71  76  
  69  61  61  
  71  62  66  
  78  69  64  
  **输出样例**  
 6   7   1   3   10

个人解答：[T41.c](Exam/T41.c)
```c
#include <stdio.h>
#include <stdlib.h>

struct student{
    int id;
    int chinese;
    int math;
    int english;
};

typedef struct student Student;

int compare(const void*a,const void*b){
    Student *studentA=(Student*)a;
    Student *studentB=(Student*)b;
    
    if(studentA->chinese+studentA->math+studentA->english!=studentB->chinese+studentB->math+studentB->english){
        return studentB->chinese+studentB->math+studentB->english-studentA->chinese-studentA->math-studentA->english;
    }
    if(studentA->chinese!=studentB->chinese){
        return studentB->chinese-studentA->chinese;
    }
    if(studentA->math!=studentB->math){
        return studentB->math-studentA->math;
    }
    if(studentA->english!=studentB->english){
        return studentB->english-studentA->english;
    }

    return studentA->id-studentB->id;
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    Student students[n];
    for (int i = 0; i < n; ++i) {
        students[i].id=i+1;
        scanf("%d %d %d",  &students[i].chinese, &students[i].math, &students[i].english);
    }

    qsort(students,n, sizeof(Student),compare);
    for (int i = 0; i < m; ++i) {
        printf("%d ", students[i].id);
    }

    return 0;
}
```

---

## 题目 42: 地球人口承载力估计 [Mark]

**题目描述：**

假设地球上的新生资源按恒定速度增长。照此测算，地球上现有资源加上新生资源可供x亿人生活a年，或供y亿人生活b年。  
为了能够实现可持续发展，避免资源枯竭，地球最多能够养活多少亿人？  
  
 **输入格式**  
输入只有一行，包括四个正整数x，a，y，b，两个整数之间用单个空格隔开。x > y，a < b，ax < by，各整数均不大于10000。  
  
 **输出格式**  
一个实数z，表示地球最多养活z亿人，结果保留小数点后两位。  
  
 **输入样例**
110 90 90 210  
 **输出样例**  
75.00

个人解答：[T42.c](Exam/T42.c)
```c
#include <stdio.h>

int main() {
    int x,a,y,b;
    scanf("%d %d %d %d", &x, &a, &y, &b);
    double z;
    // 可以从这里来思考，其中使得m*z=k即可：total= x*a*(m*x-k) = y*b*(m*y-k)
    z = (double)(y*b-a*x)/(b-a);
    printf("%.2f", z);

    return 0;
}
```

---

## 题目 43: 甲流病人初筛

**题目描述：**

目前正是甲流盛行时期，为了更好地进行分流治疗，医院在挂号时要求对病人的体温和咳嗽情况进行检查，对于体温超过37.5度（含等于37.5度）并且咳嗽的病人初步判定为甲流病人（初筛）。现需要统计某天前来挂号就诊的病人中有多少人被初筛为甲流病人。  
  
 **输入格式**  
第一行是某天前来挂号就诊的病人数n。(n小于200)  
  
其后有n行，每行是病人的信息，包括三个信息：姓名（字符串，不含空格，最多8个字符）、体温（float）、是否咳嗽（整数，1表示咳嗽，0表示不咳嗽）。每行三个信息之间以一个空格分开。  
  
 **输出格式**  
按输入顺序依次输出所有被筛选为甲流的病人的姓名，每个名字占一行。之后再输出一行，表示被筛选为甲流的病人数量。  
  
 **输入样例**  
5  
Zhang 38.3 0  
Li 37.5 1  
Wang 37.1 1  
Zhao 39.0 1  
Liu 38.2 1  
 **输出样例**  
Li  
Zhao  
Liu  
3

个人解答：[T43.c](Exam/T43.c)
```c
#include <stdio.h>

struct patient{
    char name[20];
    double temperature;
    int cough;
};

typedef struct patient Patient;

int main() {
    int n;
    scanf("%d", &n);
    Patient patients[n];
    int index=0;
    for (int i = 0; i < n; ++i) {
        scanf("%s %lf %d", patients[i].name, &patients[i].temperature, &patients[i].cough);
        if(patients[i].temperature>=37.5&&patients[i].cough==1){
            printf("%s\n", patients[i].name);
            index++;
        }
    }
    printf("%d", index);
    return 0;
}
```

---

## 题目 44: 人口增长

**题目描述：**

我国现有x亿人口，按照每年0.1%的增长速度，n年后将有多少人？计算结果保留小数点后四位输出。  
 **输入格式**  
一行，包含两个整数x和n，分别是人口基数和年数，以单个空格分隔。  
  
 **输出格式**  
输出最后的人口数，以亿为单位，保留到小数点后四位。1≤x≤100,1≤n≤100。  
  
 **输入样例**  
13 10  
 **输出样例**  
13.1306

个人解答：[T44.c](Exam/T44.c)
```c
#include <stdio.h>

int main() {
    double x,n;
    scanf("%lf %lf", &x, &n);

    for (int i = 0; i < n; ++i) {
        x= x+x*0.1/100;
    }
    printf("%.4f", x);
    return 0;
}
```

---

## 题目 45: 出租车计费

**题目描述：**

某市的出租车计费标准如下：起步里程小于等于3km时，起步费13元；超过起步里程小于等于15km以内的部分，单价为2.3元/km。超过15km的部分，单价加收50%的费用。给定一个正整数距离s（s≤1000），求应付的费用，结果保留两位小数。  
例如，当s=3时，费用为13.00元；当s=5时，费用为17.60元；当s=18时，费用为50.95元  
  
 **输入格式**  
一个正整数s，表示里程  
 **输出格式**  
一个浮点数，表示计算出来的车费，保留小数点后面两位  
  
 **输入样例**  
4  
 **输出样例**  
15.30

个人解答：[T45.c](Exam/T45.c)
```c
#include <stdio.h>

int main() {
    int s;
    scanf("%d", &s);
    double cost;
    if(s<=3){
        cost=13;
    } else if(s<=15){
        cost=13+(s-3)*2.3;
    } else{
        cost=13+12*2.3+(s-15)*3.45;
    }

    printf("%.2f", cost);
    return 0;
}
```

---

## 题目 46: 加密的病历单 [Mark]

**题目描述：**

小英是药学专业大三的学生，暑假期间获得了去医院药房实习的机会。  
   
  
在药房实习期间，小英扎实的专业基础获得了医生的一致好评，得知小英在计算概论中取得过好成绩后，主任又额外交给她一项任务，解密抗战时期被加密过的一些伤员的名单。  
  
经过研究，小英发现了如下加密规律(括号中是一个“原文 -> 密文”的例子)  
   
  
1.原文中所有的字符都在字母表中被循环左移了三个位置（dec -> abz）  
2.逆序存储（abcd -> dcba ）  
3.大小写反转（abXY -> ABxy）  
比如密文是：abfnlbm  
解密之后得到的原文是：PEOQIED  
  
 **输入格式**  
一个加密的字符串。(长度小于150且只包含大小写字母)  
 **输出格式**  
输出解密后的字符串。  
  
 **输入样例**  
GSOOWFASOq  
  
 **输出样例**  
Trvdizrrvj  
提示  
注意：要求从密文得到原文

个人解答：[T46.c](Exam/T46.c)
```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void reverse_string(char* str) {
    if (str == NULL) return;

    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}//双指针法反转字符串

int main() {
    char a[200];
    fgets(a, 200, stdin);
    for (int i = 0; i < strlen(a); ++i) {
        if(islower(a[i])){
            a[i]=toupper(a[i]);
        } else if(isupper(a[i])){
            a[i]=tolower(a[i]);
        }
        if(a[i]>='a'&&a[i]<='z'){
            a[i]=(a[i]+3-'a')%26+'a';
        } else if(a[i]>='A'&&a[i]<='Z'){
            a[i]=(a[i]+3-'A')%26+'A';
        }
    }

    reverse_string(a);

    puts(a);

    return 0;
}
```

---

## 题目 47: 切分单词并排序 [Mark]

**题目描述：**

给定一个由英文字符、数字、空格和英文标点符号组成的字符串，长度不超过2000，请将其切分为单词，要求去掉所有的非英文字母，然后将单词全部转换成小写，再按照字典序升序排列，每个单词之间用空格分隔。  
  
例如有文本：Python was created in 1990 by Guido at Centrum (CWI, see http://www.cwi.nl) in the Netherlands.  
  
处理完成之后得到以下单词序列：  
at by centrum created cwi cwi guido http in in netherlands nl python see the was www  

  
 **输入格式**  
一行字符串，含有英文字符、数字、空格和英文标点符号  
 **输出格式**  
处理后的单词序列，单词之间用空格隔开  
  
 **输入样例**  
The Python Software Foundation (PSF, see https://www.python.org/psf/) was formed.  
 **输出样例**  
formed   foundation   https   org   psf   psf   python   python   see   software   the   was   www

个人解答：[T47.c](Exam/T47.c)
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 200

struct word {
    char word[50];
};

typedef struct word Word;

int compare(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

void processInput(char *input, Word *wordCount, int *size) {
    char word[50];
    int len=0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            word[len++] = tolower(input[i]);
        } else if (len > 0) {
            word[len] = '\0';
            len = 0;

            strcpy(wordCount[*size].word, word);
            (*size)++;

        }
    }
    // 处理最后一个单词
    if (len > 0) {
        word[len] = '\0';
        strcpy(wordCount[*size].word, word);
        (*size)++;
    }
}

int main() {
    char input[MAX_LEN];
    Word wordCount[1000];
    int size = 0;

    fgets(input, MAX_LEN, stdin);

    processInput(input, wordCount, &size);

    qsort(wordCount, size, sizeof(Word), compare);

    for (int i = 0; i < size; i++) {
        printf("%s ", wordCount[i].word);
    }
    return 0;
}

```

---

## 题目 48: 单词处理 [Mark]

**题目描述：**

给定一个由英文字符、数字、空格和英文标点符号组成的字符串，长度不超过2000，请将其切分为单词，要求去掉所有的非英文字母，每行输出一个单词。  
例如有文本：Python was created in 1990 by Guido van Rossum at Stichting Mathematisch Centrum (CWI, see http://www.cwi.nl) in the Netherlands.  
处理完成之后得到以下单词：  
  
Python  
was  
created  
in  
by  
Guido  
van  
Rossum  
at  
Stichting  
Mathematisch  
Centrum  
CWI  
see  
http  
www  
cwi  
nl  
in  
the  
Netherlands  
  
 **输入格式**  
一行字符串  
  
 **输出格式**  
若干行，每行一个处理后的单词  
  
 **输入样例**  
SyntaxError: cannot assign to literal  
 **输出样例**  
SyntaxError  
cannot  
assign  
to  
literal

个人解答：[T48.c](Exam/T48.c)
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 200

struct word {
    char word[50];
};

typedef struct word Word;


void processInput(char *input, Word *wordCount, int *size) {
    char word[50];
    int len=0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            word[len++] = input[i];
        } else if (len > 0) {
            word[len] = '\0';
            len = 0;

            strcpy(wordCount[*size].word, word);
            (*size)++;

        }
    }
    // 处理最后一个单词
    if (len > 0) {
        word[len] = '\0';
        strcpy(wordCount[*size].word, word);
        (*size)++;
    }
}

int main() {
    char input[MAX_LEN];
    Word wordCount[1000];
    int size = 0;

    fgets(input, MAX_LEN, stdin);

    processInput(input, wordCount, &size);


    for (int i = 0; i < size; i++) {
        printf("%s\n", wordCount[i].word);
    }
    return 0;
}
```

---

## 题目 49: 猴子吃桃 [Mark]

**题目描述：**

猴子第一天摘下若干个仙桃，当即吃了一半，还不过瘾，又多吃了一个。第二天早上又将剩下的仙桃吃掉一半，又多吃一个。以后每天早上都吃了前一天剩下的一半零一个。到第N天早上想再吃时，见只剩下一个仙桃。求第一天共摘多少仙桃。  
输入： N   
输出： 仙桃总数

个人解答：[T49.c](Exam/T49.c)
```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum=1;
    for (int i = 0; i < n-1; ++i) {
        sum=(sum+1)*2;
    }
    printf("%d", sum);
    return 0;
}
```

---

## 题目 50: 猴子选大王

**题目描述：**

编写一个函数 king，实现猴子选大王的功能，输出 N（数据由平台提供，已获取，直接使用即可） 只猴子中谁是猴子大王的。具体要求如下：  
1. 让 N 只候选猴子围成一圈（最多 100 只猴子），从某位置起顺序编号为 1-N 号；  
2. 从第 1 号开始报数，每轮从 1 报到 3 ，凡报到 3 的猴子即退出圈子，接着又从紧邻的下一只猴子开始同样的报数；  
3. 如此不断循环，最后剩下的一只猴子就选为猴王。  
  
测试举例  
输入：5  
输出：4号猴子是大王。

个人解答：[T50.c](Exam/T50.c)
```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[100];
    for (int i = 0; i < n; ++i) {
        a[i]=1;
    }
    int count=0;
    int index=0;
    int num=0;
    while(count<n-1){
        if(a[index]==1){
            num++;
            if(num==3){
                a[index]=0;
                count++;
                num=0;
            }
        }
        index++;
        if(index==n){
            index=0;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(a[i]==1){
            printf("%d号猴子是大王。", i+1);
        }
    }
    return 0;
}
```

---

## 题目 51: 根据自己的年龄和生肖计算别人的生肖

**题目描述：**

小明总喜欢问别人的年龄，然后根据自己的年龄和生肖计算别人的生肖，编写函数shengxiao帮助小明完成该功能。注：十二生肖的顺序是：猪、狗、鸡、猴、羊、马、蛇、龙、兔、虎、牛、鼠，即如果小明8岁属猪，则如果小张9岁就属狗，小王12岁属羊。  
样例输入：8 1 9  
样例输出：2

个人解答：[T51.c](Exam/T51.c)
```c
#include <stdio.h>

int main(void){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    int e;
    e = ((b+c-a)%12+12)%12;
    if(e == 0){
        printf("12");
    }
    else{
        printf("%d",e);
    }
    
}
```

---

## 题目 52: 猴子吃桃问题

**题目描述：**

题目：猴子吃桃问题：猴子摘下若干个桃子，第一天吃了桃子的一半多一个，以后每天吃了前一天剩下的一半多一个，到第n天吃以前发现只剩下一个桃子，要求编写函数GetNumber(int n)求出猴子共摘了几个桃子。  
样例输入：5  
样例输出：46

@yestan1125 解答：[T52.c](Exam/T52.c)
```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum = 1; 

    for (int i = n - 1; i >= 1; i--) {
        sum = (sum + 1) * 2;  // 根据每天吃桃的规律倒推前一天桃子的数量
    }

    printf("%d\n", sum);

    return 0;
}
```

---

## 题目 53: 兔子吃胡萝卜问题

**题目描述：**

### 任务描述  
  
兔子第一天挖出若干个胡萝卜，当即吃了一半，不过瘾，又多吃了一个。第二天早上又将剩下的胡萝卜吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下的一半零一个。到第10天早上想再吃时，见只剩下n个胡萝卜了。求第一天共摘了多少个胡萝卜。  
  
输入：第10天剩下的胡萝卜数  
输出：第1天总共摘的胡萝卜数  
  
输入实例：1  
输出实例：1534 

@yestan1125 解答：[T53.c](Exam/T53.c)
```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum = n;
    for (int i = 9; i >= 1; i--) {
        sum = (sum + 1) * 2;
    }
    printf("%d\n", sum);
    return 0;
}
```

  
  
---

---

## 题目 54: 鸡兔同笼问题

**题目描述：**

题目：在一笼子里，鸡和兔的个数共m只，脚有n只，编写函数myChicken来计算鸡和兔各多少只？计算结果存放在参数c（鸡的只数）和r（兔的只数）中。  
  
样例输入：100 300  
  
样例输出：  
共有50只鸡  
共有50只兔

@yestan1125 解答：[T54.c](Exam/T54.c)
```c
#include <stdio.h>

void Chicken(int m, int n, int *c, int *r) {
    *c = (4 * m - n) / 2;
    *r = m - *c;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int chicken, rabbit;
    Chicken(m, n, &chicken, &rabbit);
    printf("共有%d只鸡\n", chicken);
    printf("共有%d只兔\n", rabbit);
    return 0;
}
```

---

## 题目 55: 猴子选大王（二） [Mark]

**题目描述：**

n只猴子围成一圈，从1到n顺序编号。从第q只猴子开始，从1到m报数，凡报到m的猴子退出竞选，下一次又从退出的那只猴子的下一只开始从1到m报数，直至剩下的最后一只为大王。请问最后哪只猴子被选为大王。如果最后没有猴子剩下，则输出none  
例如给定【7 4 3】，应输出：4。再给定【10 3 6】，应输出：9。给定【3 1 1】，应输出none  
提示：输出的字符串none全是小写  
 **输入格式**  
输入三个正整数n，m，q，分别表示猴子的数量n，报数的尾数m，从第q个猴子开始报数，中间用空格分隔，题目保证：1≤m≤n≤999，1≤q≤n≤999  
  
 **输出格式**  
输出最后选为大王的猴子编号，如果最后没有猴子剩下则输出：none  
  
 **输入样例**  
7 4 3  
 **输出样例**  
4

个人解答：[T55.c](Exam/T55.c)
```c
#include <stdio.h>

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    // 特殊情况处理：如果 m=1，所有猴子都会被淘汰
    if (m == 1) {
        printf("none\n");
        return 0;
    }

    int monkeys[1000] = {0};
    for (int i = 1; i <= n; i++) {
        monkeys[i] = 1;
    }

    int count = n;      // 记录当前剩余的猴子数量
    int position = q;   // 当前报数位置
    int number = 1;     // 当前报的数

    while (count > 1) {
        if (monkeys[position] == 1) {
            if (number == m) {
                monkeys[position] = 0;
                count--;
                number = 1;
            } else {
                number++;
            }
        }
        
        position++;
        if (position > n) {
            position = 1;
        }
    }
    
    if (count == 1) {
        for (int i = 1; i <= n; i++) {
            if (monkeys[i] == 1) {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    
    printf("none\n");
    return 0;
}
```



---

## 题目 56: 重复选课的学生 [Mark]

**题目描述：**

学校开放了两门选修课，规定每位同学只能选择其中一门。但是有些同学不遵守规定，同时选择了两门课程，现在选课名单汇总出来了，请你根据名单将同时选择了两门课程的同学挑选出来，并按照字典顺序升序排列。  
例如，选择了A课程的同学有：Christia Natha Elija Ale Loga Jame Gabrie，选择了B课程的同学有：Joh Natha Elija Ale Rya Hayde，重复选课的同学是：Ale Elija Natha  
又比如，选择了A课程的同学有：Thoma Camero Col Austi Jesu，选择了B课程的同学有：Thoma Brya Lia Austi Trista，重复选课的同学是：Austi Thoma  
  
 **输入格式**  
输入数据一共有4行。第一行是一个正整数m（1≤m≤100）表示选择A课程的同学数目，第二行是所有选择A课程的同学姓名，中间以空格分隔。第三行是一个正整数n（1≤n≤100）表示选择B课程的同学数目，第四行是所有择B课程的同学姓名，中间以空格分隔。  
  
 **输出格式**  
一行，所有重复选课的同学姓名，中间以空格分隔，按照字典顺序升序排列  
  
 **输入样例**  
6  
Thoma Austi Lia Sea Trista Brya   
7  
Brya Camero Austi Lia Hunte Trista Jesu   
 **输出样例**  
Austi Brya Lia Trista

@yestan1125 解答：[T56.c](Exam/T56.c)
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 100

// 冒泡排序函数，用于对字符串数组按照字典序排序
int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int m, n;
    scanf("%d", &m);
    char studentsA[MAX_STUDENTS][MAX_NAME_LENGTH];
    for (int i = 0; i < m; i++) {
        scanf("%s", studentsA[i]);
    }

    scanf("%d", &n);
    char studentsB[MAX_STUDENTS][MAX_NAME_LENGTH];
    for (int i = 0; i < n; i++) {
        scanf("%s", studentsB[i]);
    }

    // 找出重复选课的同学，使用一个临时数组来记录重复的同学
    char duplicates[MAX_STUDENTS][MAX_NAME_LENGTH];
    int duplicateCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(studentsA[i], studentsB[j]) == 0) {
                strcpy(duplicates[duplicateCount], studentsA[i]);
                duplicateCount++;
            }
        }
    }

    // 对重复选课的同学数组进行排序
    qsort(duplicates, duplicateCount, sizeof(duplicates[0]), compare);

    // 输出重复选课的同学姓名
    for (int i = 0; i < duplicateCount; i++) {
        if (i!= 0) {
            printf(" ");
        }
        printf("%s", duplicates[i]);
    }
    printf("\n");

    return 0;
}
```

---

## 题目 57: 密码翻译

**题目描述：**

在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密，简单的加密算法虽然不足以完全避免情报被破译，但仍然能防止情报被轻易的识别。我们给出一种最简的的加密方法，对给定的一个字符串，把其中从a-y，A-Y的字母用其后继字母替代，把z和Z用a和A替代，其他非字母字符不变，则可得到一个简单的加密字符串。  
  
 **输入格式**  
输入一行，包含一个字符串，长度小于80个字符。  
  
 **输出格式**  
输出每行字符串的加密字符串。  
  
 **输入样例**  
Hello! How are you!  
 **输出样例**  
Ifmmp! Ipx bsf zpv!  
  
提示  
由于windows和linux下面的换行符不同，所以读入一行字符推荐使用fgets或者gets函数；尽量避免使用getchar读入，后者需要自行解决跨平台问题。

@yestan1125 解答：[T57.c](Exam%2FT57.c)
```C
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[80];
    fgets(str, 80, stdin);  

    for (int i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {  
            if (str[i] == 'z') {
                str[i] = 'a';
            } else if (str[i] == 'Z') {
                str[i] = 'A';
            } else {
                str[i]++;  
            }
        }
    }
    printf("%s", str);

    return 0;
}
```

---

## 题目 58: 计算邮资

**题目描述：**

根据邮件的重量和用户是否选择加急计算邮费。计算规则：重量在1000克以内(包括1000克), 基本费8元。超过1000克的部分，每500克加收超重费4元，不足500克部分按500克计算；如果用户选择加急，多收5元。  
  
 **输入格式**  
输入一行，包含整数和一个字符，以一个空格分开，分别表示重量（单位为克）和是否加急。如果字符是y，说明选择加急；如果字符是n，说明不加急。  
  
 **输出格式**  
输出一行，包含一个整数，表示邮费。  
  
 **输入样例**  
1200 y  
 **输出样例**  
17

@yestan1125 解答：[T58.c](Exam%2FT58.c)
```C
#include <stdio.h>

int main() {
    int weight;  
    char urgent;  
    scanf("%d %c", &weight, &urgent);

    int fee = 8;  
    if (weight > 1000) {
        
        int extra = weight - 1000;
        fee += (extra + 499) / 500 * 4;
    }
    if (urgent == 'y') {
        fee += 5;  
    }

    printf("%d\n", fee);

    return 0;
}
```

---
