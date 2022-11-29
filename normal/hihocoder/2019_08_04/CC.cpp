#include <stdio.h>
#include <string.h>
#define SIGMA_SIZE 26
#define MAXN 200050
int len;
struct SAM{
    struct SNode{
        int step;
        int next[SIGMA_SIZE];
        int fail;
    }node[MAXN<<1];
    int scnt, end;
    SAM() : scnt(0){}
    void init(){
        scnt = 0;
        end = newNode(0);
    }
    int newNode(int step){
        node[scnt].step = step; node[scnt].fail=-1;
        memset(node[scnt].next, -1, sizeof(node[0].next));
        return scnt++;
    }
    void insert(char c){
        int x = c-'a';
        int p = end;
        int np = newNode(node[p].step+1);
        while(p>=0 && node[p].next[x] == -1)
            node[p].next[x] = np, p = node[p].fail;
        if(p == -1)
            node[np].fail = 0;
        else{
            int q = node[p].next[x];
            if(node[p].step+1 == node[q].step)
                node[np].fail = q;
            else{
                int nq = newNode(node[p].step+1);
                memcpy(node[nq].next, node[q].next, sizeof(node[0].next));
                node[nq].fail = node[q].fail;
                node[q].fail = nq;
                node[np].fail = nq;
                while(p>=0 && node[p].next[x] == q)
                    node[p].next[x] = nq, p = node[p].fail;
            }
        }
        //ans += node[np].step - node[node[np].fail].step;
        end = np;
    }
    void build(char *s){
        int len = strlen(s);
        init();
        for(int i=0; i<len; i++)
            insert(s[i]);
    }
    int work(){
        int p = 0;
        for(int i=0; i<len; i++){
            for(int j=0; j<26; j++)
                if(node[p].next[j] != -1){
                    p = node[p].next[j];
                    break;
                }
        }
        return node[p].step-len;
    }
};
char buf[200050];
SAM sam;
int main()
{
    scanf ( "%s", buf );
    len = strlen(buf);
    memcpy(buf+len, buf, len);
    buf[len<<1] = '\0';
    sam.build(buf);
    int p = sam.work();
    buf[p+len] = '\0';
    printf("%s\n", buf+p);
    return 0;
}