/*
Pretty Kind , Pretty Smart.
*/
#include<stdio.h>
#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<map>
#include<list>
#include<climits>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define pii pair<int,int>
#define iin1(a) scanf("%d",&a)
#define LOOP(s,t,i) for(int i=s;i<=t;i++)
#define iin2(a,b) scanf("%d%d",&a,&b)
#define iin3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define iin4(a,b,c,d) scanf("%d%d%d",&a,&b,&c,&d)
#define pll pair<ll,ll>
typedef long long ll;

struct Node{
    int data;
    Node *next,*prev;

};

Node *newNode(int d){
    Node *n = (Node*)malloc(sizeof(Node));
    n->data=d;
    n->prev=NULL;
    n->next=NULL;
    return n;
}
Node *start,*last;
char type[20];
int main(){
	int tc,num,way=1,siz=0;
	iin1(tc);
	start=last=NULL;
	while(tc--){
        scanf("%s",type);
        if(type[0]=='t'||type[0]=='p'){
            iin1(num);
            Node *n  = newNode(num);
            if(type[0]=='t'){
                if(siz==0){
                    start=n;
                    last=start;
                    siz=1;
                    continue;
                }
                siz++;
                if(way){
                    n->next=start;
                    start->prev=n;
                    start=n;
                }
                else{
                    last->next=n;
                    n->prev=last;
                    last=n;
                }
            }
            else if(type[0]=='p'){
                if(siz==0){
                    start=n;
                    last=start;
                    siz=1;
                    continue;
                }
                siz++;
                if(way){
                    last->next=n;
                    n->prev=last;
                    last=n;
                }
                else{
                     n->next=start;
                    start->prev=n;
                    start=n;

                }
            }

        }else{

            if(type[0]=='r'){
                way=!way;
            }else if(type[0]=='f'){
                if(siz==0){
                printf("No job for Ada?\n");
                continue;
               }

                siz--;
                if(way){
                    printf("%d\n",start->data);
                    if(siz!=0){
                        start=start->next;
                        start->prev=NULL;
                    }
                }else{

                    printf("%d\n",last->data);
                   if(siz!=0){
                   last = last->prev;
                   last->next=NULL;
                   }

                }

            }else if(type[0]=='b'){
                if(siz==0){
                printf("No job for Ada?\n");
                continue;
                }
                siz--;
                if(way){
                   printf("%d\n",last->data);
                   if(siz!=0){
                   last = last->prev;
                   last->next=NULL;
                   }

                }else{
                    printf("%d\n",start->data);
                    if(siz!=0){
                        start=start->next;
                        start->prev=NULL;
                    }
                }
            }
        }
	}
return 0;}
