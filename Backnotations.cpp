#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include <gtest/gtest.h>

using namespace std;

TEST ("global", "tnode") {

struct Tnode
{
  string Key;
  Tnode* left;
  Tnode* right;
  Tnode()
  {
  left=right=0;
  }
};

Tnode tnode;

ASSERT_EQ(tnode, tnode);
}

TEST ("global", "Tree") {

class TREE
{
private:
  Tnode* Tree;
public:
  TREE() {Tree=NULL;}
  Tnode** GetTree () {return &Tree;} //Получение вершины дерева.
  void BuildTree(string, Tnode**);
  int Height (Tnode **);
  void Vyvod (Tnode** );
};
//построение бинарного дерева
void TREE::BuildTree(string x, Tnode **p)
{
  int size = x.size();
  for(int i=0;i<size;i++)
  {
    if(*p==NULL)
  {
    *p=new(Tnode);
    (**p).Key = x[size-i-1];
    (**p).left = NULL; (**p).right = NULL; 
  }
  else
  {     
    Tnode* temp =new(Tnode);          
    if((**p).right == NULL)
    {
    (*temp).Key = x[size-i-1];
    (*temp).left = NULL; (*temp).right = NULL;
    (**p).right = temp;
    }
    else
    {
      if((**p).left == NULL)
    {
      (*temp).Key = x[size-i-1];
      (*temp).left = NULL; (*temp).right = NULL;
      (**p).left = temp;  
    }
    else
    {
      *p=(**p).left;
    }
    }
   }
 }
}
 
int TREE::Height (Tnode **w)
//Определение высоты бинарного дерева.
//*w - указатель на корень дерева.
{
  int h1,h2;
  if  (*w==NULL) return (-1);
  else
  {
    h1 = Height (&((**w).left));
    h2 = Height (&((**w).right));
    if  (h1>h2) return (1 + h1);
    else  return (1 + h2);
  }
}
 
void TREE::Vyvod (Tnode **w)
//Изображение дерева *w на экране дисплея
//          (рекурсивный алгоритм).
//*w - указатель на корень дерева.
{   
  if  (*w!=NULL)
  { 
    Vyvod (&((**w).left));
    cout<<(**w).Key<<" ";
    Vyvod (&((**w).right)); 
  }
}
struct act
{
  char op1[7];
  char zn[3];
  char op2[7];
};

Tree tree;

ASSERT_EQ (tree, tree);
}

TEST ("global", "global_main") {

int main()
{
char a[100],*ans;
int b[100],i=0,max=0,d=0;
act p[50];
while (i<=99)
{
  b[i]=0;
  i=i+1;
}
printf("\n Введите выражение: ");
scanf("%s",&a);
i=0;
while (a[i]!='\0')
  {
  if (a[i]=='(')
  {
    d=d+1;
    if (d>max) max=d;
  }
    if (a[i]==')') d=d-1;
    i=i+1;
  }
int e=max,l=1;
while (e>=0)
  {
  i=0;
  d=0;
  while (a[i]!='\0')
  {
  if (a[i]=='(') d=d+1;
  if (a[i]==')') d=d-1;
  if ((d==e)&&((a[i]=='*')||(a[i]=='/')))
  {
  b[i]=l;
  l=l+1;
  }
  i=i+1;
  }
  i=0;
  d=0;
  while (a[i]!='\0')
  {
    if (a[i]=='(') d=d+1;
    if (a[i]==')') d=d-1;
    if ((d==e)&&((a[i]=='+')||(a[i]=='-')))
  {
    b[i]=l;
    l=l+1;
  }
    i=i+1;
  }
    i=0;
    d=0;
    while (a[i]!='\0')
    {
      if (a[i]=='(') d=d+1;
      if (a[i]==')') d=d-1;
      if ((d==e)&&((a[i]=='>')||(a[i]=='<')||((a[i]=='=')&&(a[i+1]=='='))||((a[i]=='>')&&(a[i+1]=='='))||((a[i]=='<')&&(a[i+1]=='='))))
      {
        b[i]=l;
        l=l+1;
      }
        i=i+1;
      }
  i=0;
  d=0;
  while (a[i]!='\0')
  {
  if (a[i]=='(') d=d+1;
  if (a[i]==')') d=d-1;
  if ((d==e)&&(((a[i]=='&')&&(a[i+1]=='&'))||((a[i]=='|')&&(a[i+1]=='|'))))
  {
    b[i]=l;
    l=l+1;
  }
    i=i+1;
  }
    e=e-1;
  }
  l=l-1;
//  p=((act*)malloc(l));
  int t=0,z;
  d=1;
  while (d<=l)
  {
    i=0;
    z=0;
    while (b[i]!=d) i=i+1;
    max=i-1;
    while ((a[max]=='\1')||(a[max]==')')||(a[max]=='('))
      {
        max=max-1;
        z=1;
      }
    if ((max>0)&&(z==0))
      {
        while (((a[max-1]>=65)&&(a[max-1]<=122))||((a[max-1]>=48)&&(a[max-1]<=57)))
          {
            max=max-1;
            if (max==0) break;
          }
      }
    if (z==0)
      {
        e=max;
        while (((a[max]>=65)&&(a[max]<=122))||((a[max]>=48)&&(a[max]<=57)))
          {
            p[t].op1[max-e]=a[max];
            a[max]='\1';
            max=max+1;
          }
        p[t].op1[max-e]='\0';
      }
    else
      {
        p[t].op1[0]=a[max];
        a[max]='\1';
        p[t].op1[1]='\0';
      }
    z=0;
    max=i+1;
    if ((a[max]=='=')||(a[max]=='&')||(a[max]=='|')) max=max+1;
    while ((a[max]=='\1')||(a[max]=='(')||(a[max]==')'))
      {
        max=max+1;
        z=1;
      }
    if (z==0)
      {
        e=max;
        while (((a[max]>=65)&&(a[max]<=122))||((a[max]>=48)&&(a[max]<=57)))
          {
           p[t].op2[max-e]=a[max];
           a[max]='\1';
           max=max+1;
          }
        p[t].op2[max-e]='\0';
      }
    else
      {
        p[t].op2[0]=a[max];
        a[max]='\1';
        p[t].op2[1]='\0';
      }
    p[t].zn[0]=a[i];
    a[i]=t+2;
    if ((a[i+1]=='=')||(a[i+1]=='&')||(a[i+1]=='|'))
      {
        p[t].zn[1]=a[i+1];
        a[i+1]='\1';
        p[t].zn[2]='\0';
      }
    else
      {
        p[t].zn[1]='\0';
      }
    t=t+1;
    d=d+1;
  }
ans=((char*)malloc(l*50));
if (ans==0) {printf("\n Ошибка!!!");exit(0);}
d=0;
while (d<=l-1)
  {
    i=0;
    if (p[d].op1[0]<48)
      {
        while (ans[(p[d].op1[0]-2)*50+i]!='\0')
          {
            ans[d*50+i]=ans[(p[d].op1[0]-2)*50+i];
            i=i+1;
          }
      }
    else
      {
         while (p[d].op1[i]!='\0')
          {
            ans[d*50+i]=p[d].op1[i];
            i=i+1;
          }
      }
    //ans[d*50+i]=' ';
    //i=i+1;
    e=0;
    if (p[d].op2[0]<48)
      {
        while (ans[(p[d].op2[0]-2)*50+e]!='\0')
          {
            ans[d*50+i]=ans[(p[d].op2[0]-2)*50+e];
            i=i+1;
            e=e+1;
         }
      }
    else
      {
        while (p[d].op2[e]!='\0')
          {
            ans[d*50+i]=p[d].op2[e];
            e=e+1;
            i=i+1;
          }
      }
    //ans[d*50+i]='';
    //i=i+1;
    e=0;
    while (p[d].zn[e]!='\0')
      {
        ans[d*50+i]=p[d].zn[e];
        e=e+1;
        i=i+1;
      }
    ans[d*50+i]='\0';
    d=d+1;
  }
printf("\n ОПЗ: ");
i=0;
ofstream strm("input.txt");
while (ans[(l-1)*50+i]!='\0')
  {
    printf("%c",ans[(l-1)*50+i]);
     strm<<ans[(l-1)*50+i];
    i=i+1;
  }
strm.close();
char zz[3];
TREE A;
string x;
ifstream strm1("input.txt");
getline(strm1, x); 
A.BuildTree(x, A.GetTree());
A.Vyvod (A.GetTree());
strm1.close();

  return 0;
}
}