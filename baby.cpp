//Test
/*#include <iostream>
using namespace std;
int main(){
    cout << "hello!world!";
    return 0;
}
*/

//Coins
/*
#include<iostream>
#include<iomanip>
using namespace std;
int A[7];
double value[7] = {0, 0.01, 0.05, 0.10, 0.25, 0.50, 1.0};
int wt[7] = {0, 3, 5, 2, 6, 11, 8};
double M[10][11000] = {0};
int main()
{
    int W;
    while(cin >> W)
    {
        A[0] = 0;
        for(int i = 1; i <= 6; i++)
            cin >> A[i];
        for(int w = 0; w <= W; w++)
            M[0][w] = 0;
        for(int i = 0; i <= 6; i++)
            M[i][0] = 0;
        for(int i = 1; i <= 6; i++)
        {
            for(int w = 1; w <= W; w++)
            {
                M[i][w] = 0;
                int nCount = min(A[i], w / wt[i]);
                for(int k = 0; k <= nCount; k++)
                {
                    M[i][w] = max(M[i][w], k * value[i] + M[i - 1][w - k * wt[i]]); //ע��������ȡ����M[i][w]��(k * value[i] + M[i - 1][w - k * wt[i]])�е����ֵ��������M[i - 1][w]��(k * value[i] + M[i - 1][w - k * wt[i]])�е����ֵ��
                }
            }
        }
        cout << "$" << fixed << setprecision(2) << M[6][W] << endl;
    }
    return 0;
}*/

//Travelling Salesman Problem
/*#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#define MAX 10e7
using namespace std;
int caseNum, comPathNum, cityNum;
double DP[25][1100000]; // ��¼�洢״̬
double distanceArr[25][25]; //��¼����֮���ŷʽ����

struct point{
    int x,y;
}city[25];

double getDistance(const point &a,const point &b){ // ����������֮���ŷʽ����
    return sqrt(( a.x - b.x )*( a.x - b.x ) + (a.y - b.y)*(a.y - b.y));
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> caseNum;
    while (caseNum--) {
        cin >> cityNum;
        comPathNum = 1;
        for (int i = 0; i < cityNum; i++) {
            cin >> city[i].x >> city[i].y;
        }
        for (int i = 0; i < cityNum; i++) {
            for (int j = 0; j < cityNum; j++) {
                distanceArr[i][j] = distanceArr[j][i] = getDistance(city[i], city[j]);
            }
        }
        comPathNum <<= (cityNum-1);
        for (int i = 0; i < cityNum; i++) {   // ��ʼ��״̬����
            for (int j = 0; j < comPathNum; j++) {
                DP[i][j] = MAX;
            }
        }
        for(int i = 0; i < cityNum; i++){   // ��ʼ��DP�ĵ�0����
            DP[i][0] = distanceArr[i][0];
        }
        for (int i = 1;  i < comPathNum; i ++) {
            for (int j = 1; j < cityNum; j++) {
                for (int k = 1; k < cityNum; k ++) {
                    if (1<<(k-1) & i) {
                        DP[j][i] = min(DP[j][i], distanceArr[j][k] + DP[k][i-(1<<(k-1))]);
                    }
                }
            }
        }
        double result = MAX;
        for (int i = 1; i <cityNum; i++) {  // ���ս�������յ�
            result = min(result, DP[i][comPathNum-1] + distanceArr[i][cityNum-1]);
        }
        cout << setprecision(2)<< setiosflags(ios::fixed)<< result << endl;

    }
    return 0;
}*/

//1020 Big Integer
/*#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char Bigint[401];
char b[401];
int divide[101];
void Divide(char *a,int i)
{
    if(i < 10)
    {
        int k = 1;
        while(*(a + k) != '\0')
        {
            int b = (*(a + k - 1) - '0') * 10 +*(a + k) - '0';
            *(a + k) = b % i + '0';
            k ++;
        }
        cout << (*(a + k - 1));
    }
    else if(10 <= i && i < 100)
    {
        int k = 2;
        while(*(a + k) != '\0')
        {
            int b = (*(a + k - 2) - '0') * 100 + (*(a + k -1) - '0') * 10 + (*(a + k) -'0');
            *(a + k) = (b % i)  % 10 + '0';
            *(a + k - 1) = (b % i) / 10 + '0';
            k ++;
        }
        if(*(a + k - 2) == '0')
            cout << *(a + k - 1);
        else cout << *(a + k - 2) << *(a + k - 1);
    }
    else if(i >= 100 && i < 1000)
    {
        int k = 3;
         while(*(a + k) != '\0')
        {
            int b = (*(a + k - 3) - '0') * 1000 + (*(a + k - 2) - '0') * 100 + (*(a + k -1) - '0') * 10 + (*(a + k) -'0');
            *(a + k) = (b % i)  % 10 + '0';
            *(a + k - 1) = ((b % i) / 10) % 10 + '0';
            *(a + k - 2) = (b % i) / 100 + '0';
            k ++;
        }
        if(*(a + k - 3) == '0')
        {
                if(*(a + k - 2) == '0')
                    cout << *(a + k - 1);
                else cout << *(a + k - 2) << *(a + k - 1);
        }
        else cout << *(a + k - 3) << *(a + k - 2) << *(a + k - 1);

    }
    else cout << a[strlen(a) - 3] << a[strlen(a) - 2] << a[strlen(a) - 1];
}
void judge()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
   {
       cin >> divide[i];
   }
    cin >> Bigint;
    cout << "(" ;
    for(int i = 0; i < n; i ++)
    {
        strcpy( b , Bigint);
        Divide(b , divide[i]);
        if(i == n - 1);
        else cout << ",";
    }
    cout << ")";
    cout << endl;

}
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n; i++ )
    {
        judge();
    }
}*/

//
//The energy
/*#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int p[101];
int N;
int dp[110][110];
void solve(){
    for(int i = 0;i < N;i ++){
        cin >> p[i];
    }
    memset(dp,0,sizeof(dp));
    int maxf = 0;
    for(int l = 2;l <= N;l ++){
        for(int i = 0;i < N;i ++){
            for(int j = 1;j < l;j ++){
                dp[i][l] = max(dp[i][l],dp[i][j] + dp[(i +j)%N][l- j] + p[i] * p[(i + l)%N] * p[(i + j)%N]);
                maxf = max(maxf,dp[i][l]);
            }
        }

    }
    cout << maxf << endl;
}


int main(){
    ios::sync_with_stdio(false);
    while(cin >> N){
        solve();

    }
    return 0;
}
*/

//1121 Tri Tiling
/*
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long LL;
LL s[31];
LL num(int a){
    if(a == 0){
        return 1;
    }
    if(a == 2){
        return 3;
    }
    if(s[a]!=0){
        return s[a];
    }
    LL sum = 0;
    sum += 3*num(a-2);
    int temp = a-2;
    while (temp>0){
        temp -= 2;
        sum += 2*num(temp);
    }
    s[a] = sum;
    return sum;
}

int main(){
    int n;
    memset(s,0,sizeof(s));
    while (cin>>n&&n!=-1){
        if(n == 0){
            cout << 1;
        }
        else if(n%2!=0){
            cout << 0;
        }
        else{
            cout << num(n);
        }
    }
    return 0;
}
*/

/*
//The shortest path1
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#define INF 500000000
#define MAX 1010

struct Edge{
    int len;
    int cost;
};
Edge edge[nmax][nmax]
int dst[nmax],spend[nmax],book[nmax],N,M;
int main(){
    while(cin >> N >> M && N !=0 && M !=0){
        int i,j,a,b;
        for(a = 1;a<=N;a++){
            for(b=1;b<=N;b++){
                edge[a][b].cost= 0;
                edge[a][b].len = INF;
            }
            edge[a][b]=0;
        }
        while(M--){
            cin >> a >> b;
            cin >> edge[a][b];
        }
        int k;
        for(k=1;k<=n;k++){
            for(a=1;i<=n;i++){
                for(b=1;b<=n;b++){
                    if(edge[b][k]< inf && edge[k][j] < inf && edge[i][j] > edge[i][k] + edge[k][j])
                         edge[i][j] = edge[i][k] + edge[k][j];
                }
        }
    }
    }


}
*/

/*
//The merge sort
#include <iostream>
#include <cstring>
using namespace std;
int Merge(int a[],int first,int last,int temp[]){
    if(first>last){
        return;
    }
    else{
        int mid;
        mid = (first + last)/2;
        Merge(a,first,mid,temp);
        Merge(a,mid+1,last,temp);
        Mergerry(a,first,mid,last,temp);
        return 0;
    }
}
*/

/*
 *字符串的朴素匹配
 通过每一个字母对应着主串
 进行一次的进行比较，知道
 其中的一个串的所有字母都匹配成功
#include <iostream>
#include <cstdio>
#include <malloc.h>
#include <cstring>
using namespace std;
int index(char *a, char *b)
{
	int tarindex = 0;
	while(a[tarindex] != '\0')
	{
			int tarlen = tarindex;
			int patlen;
			for(patlen = 0; b[patlen] != 0; patlen++)
			{
					if(a[tarlen++] != b[patlen])
					{
						break;
					}
			}
			if(b[patlen] == '\0')
			{
				return tarindex;
			}
			tarindex++;
	}
	return -1;
}
int main()
{
	char *a;
	char *b;
	a = (char*)malloc(sizeof(char));
	b = (char*)malloc(sizeof(char));
	gets(a);
	gets(b);
	cout<<index(a, b) + 1<<endl;
	return 0;
}
*/
/*
#include<iostream>
#include<vector>
#include<string>
#include <cstdio>
#include <malloc.h>
#include <cstring>
using namespace std;
int BFmatch(string &S,string &P){
    int i,j;
    i=0;
    while(i<S.size()){
        j=0;
        while(j<P.size()&&S[i]==P[j]){
            i++;
            j++;
        }
        if(j=P.size()){
            i = i - P.size();
        }
        else{
            return i - j +1;
        }
    }
    return -1;
}
int main(){
	char *S;
	char *P;
	S = (char*)malloc(sizeof(char));
	P = (char*)malloc(sizeof(char));
	gets(S);
	gets(P);
	cout<<BFmatch(&S,&P)<<endl;
	return 0;

}
*/
/*
#include <iostream>
#include <vector>
using namespace std;
static bool flag[100];
static int parent1[100],parent2[100];
//将输入的一组数变成数组
void getParent(int* a,int num){
    for(int i = 0; i <num; i ++){
        cin >> a[i];
    }
}
//获取子个体
void getOffspring(const int *p1,const int *p2,int begin,int end,int len,int* result){
    int i,j;
    //子个体从p1个体中获取从begin到end的一段序列
    for(i = begin; i <= end; i ++){
        flag[p1[i]] = true;
        result[i] = p1[i];
    }
    //子个体剩下的内容从p2个体中顺序获得
    for(i = 0,j = 0; i < len;i++ ){
        if(!flag[p2[i]]){
            if(j == begin) j = end +1;
            result[j] = p2[i];
            j ++;
        }
        else{
            flag[p2[i]] = false;
        }
    }
}
//输出子个体
void printVecInt(int *result,int len){
    for(int i = 0; i < len-1; i++){
        cout << result[i] << " ";
    }
    cout << result[len-1] << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int Num;
    while(cin >> Num){
        if(Num == 0)break;
        int startPos,endPos;
        getParent(parent1, Num); //将输入的一组数转为数组
        getParent(parent2, Num);
        int offSpring1[100] ={0}, offSpring2[100]={0};
        cin >> startPos >> endPos;
        getOffspring(parent1, parent2, startPos, endPos,Num,offSpring1); //获取第一种情况的子个体
        getOffspring(parent2, parent1, startPos, endPos,Num,offSpring2); //获取第二种情况的子个体
        printVecInt(offSpring1,Num);
        printVecInt(offSpring2,Num);
    }
    return 0;
}
*/
//2.4.1
//2.4.6.8....2n
/*
#include<stdio.h>

int main(){
    int i,n;
    scanf("%d",&n);
    for(i=2;i<=(2*n);i=i+2){//change
        printf("%d\n",i);//change
    }
    return 0;
}
*/
//2.4.2
//The trap of float(0.1 can't use in the computer binary)
/*
#include <stdio.h>
int main(){
    double i;
    for(i=0;i!=10;i+=0.5)
        printf("%.11f\n",i);
    return 0;
}
*/

//2.4.3 64 bit integer
/*
#include<stdio.h>
int main(){
    int n,i,k;
    k=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(n%i==0){
            k++;
        }
    }
    printf("%d",k);
}

//2.4.6
//2-1 digit
#include <stdio.h>
int main(){
    int i;
    float n;
    scanf("f",&n);
    for(i=1;i<=9;){
        if(n<1){
            n=n/10;
            i++;
        }
        else{
            break;
        }
    printf("%d",i);
    }
}


//iomonip
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int x;
    cin >> x;
    cout << setiosflags(ios::left)<< setbase(8)<< x << endl;
}
*/

/*
常量引用：const int &p = i;
常量指针：const int *p
指针常量：int* const p
*/


