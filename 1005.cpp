#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10000+5;
int ax[maxn],ay[maxn];
int bx[maxn],by[maxn];
int cy[maxn],c[maxn];
int main(void)
{
    int x,y;
    bool q=false;
    memset(ax,0,sizeof(ax));
    memset(bx,0,sizeof(bx));
    memset(ay,0,sizeof(ay));
    memset(by,0,sizeof(by));
    bool f=true;
    int n=0,m=0;
    while(scanf("%d%d",&x,&y))
    {
        if(x==0 && y==-1)
            break;
        ax[n]=x;
        ay[n++]=y;
    }
    while(scanf("%d%d",&x,&y))
    {
        if(x==0 && y==-1)
            break;
        bx[m]=x;
        by[m++]=y;
    }
    for(int i=0; i<n; i++)
    {
        if(ax[i]==0)
            continue;
        if(ax[i]!=1 && (f || ax[i]<0))
        {
            if(ax[i]==-1 && ay[i]!=0)
                printf("-");
            else
                printf("%d",ax[i]);
        }
        else
        {
            if(ax[i]==1)
            {
                if(f)
                {
                    if(ay[i]==0)
                        printf("1");
                }
                else
                {
                    if(ay[i]==0)
                        printf("+1");
                    else
                        printf("+");
                }
            }
            else if(ax[i]!=1 && !f)
                printf("+%d", ax[i]);
        }
        if(ay[i]==1)
            printf("X");
        else if(ay[i]!=0)
            printf("X^%d", ay[i]);
        f=false;
    }
    printf("\n");
    f=true;
    for(int i=0; i<m; i++)
    {
        if(bx[i]==0)
            continue;
        if(bx[i]!=1 && (f || bx[i]<0))
        {
            if(bx[i]==-1 && by[i]!=0)
                printf("-");
            else
                printf("%d",bx[i]);
        }
        else
        {
            if(bx[i]==1)
            {
                if(f)
                {
                    if(by[i]==0)
                        printf("1");
                }
                else
                {
                    if(by[i]==0)
                        printf("+1");
                    else
                        printf("+");
                }
            }
            else if(bx[i]!=1 && !f)
                printf("+%d", bx[i]);
        }
        if(by[i]==1)
            printf("X");
        else if(by[i]!=0)
            printf("X^%d", by[i]);
        f=false;
    }
    printf("\n");
    f=true;
    int len=0;
    memset(c,0,sizeof(c));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            x=ax[i]*bx[j];
            y=ay[i]+by[j];
            cy[len++]=y;
            c[y]+=x;
            //  printf("%d %d\n",x,y );
        }
    sort(cy,cy+len);
    len=unique(cy,cy+len)-cy;
    for(int i=len-1; i>=0; i--)
    {
        if(c[cy[i]]==0)
            continue;
        if(c[cy[i]]!=1 && (f || c[cy[i]]<0))
        {
            if(c[cy[i]]==-1 && cy[i]!=0)
                printf("-");
            else
                printf("%d",c[cy[i]]);
        }
        else
        {
            if(c[cy[i]]==1)
            {
                if(f)
                {
                    if(cy[i]==0)
                        printf("1");
                }
                else
                {
                    if(cy[i]==0)
                        printf("+1");
                    else
                        printf("+");
                }
            }
            else if(c[cy[i]]!=1 && !f)
                printf("+%d", c[cy[i]]);
        }
        if(cy[i]==1)
            printf("X");
        else if(cy[i]!=0)
            printf("X^%d", cy[i]);
        f=false;
        q=true;
    }
    if(q)
        printf("\n");
    else
        printf("0\n");
}