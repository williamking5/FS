#include<bits/stdc++.h>
#define maxlongint 10000000000
#define NONE 1000000
#define tot 600020
using namespace std;

long long i,j,k,m,n,st[tot],w[tot],ptb[tot],link[tot],d[tot],q[tot],v[tot],num[tot];
long long kk,pp,p,a,b;
long long beg,edd;

int main(){
	cin>>n>>m;
	memset(st,0,sizeof st);
	memset(w,0,sizeof w);
	memset(ptb,0,sizeof ptb);
	memset(link,0,sizeof link);

	for (i=1;i<=m;i++){
		cin>>a>>b>>w[i];
		if (w[i]) w[i]=-1;
		else w[i]=0;
		link[i]=st[a];
		st[a]=i;ptb[i]=b;
	}
	cin>>beg>>edd;

	memset(q,0,sizeof q);
	memset(v,0,sizeof v);

	for (i=2;i<=n;i++)
		d[i]=maxlongint;
	q[1]=beg;v[beg]=1;p=1;k=1;d[beg]=0;
	ptb[beg]++;

	while (1){
		kk=k;

		do{
			j=st[q[p]];
			while (j!=0){
				if (d[ptb[j]]>d[q[p]]+w[j]){
					d[ptb[j]]=d[q[p]]+w[j];
					if (v[ptb[j]]==0){
						kk++;
						if (kk>tot) kk=1;
                        q[kk]=ptb[j];
						v[ptb[j]]=1;
						num[ptb[j]]++;
						if (num[ptb[j]]>n){
                            cout<<"YES"<<endl   ;
                            return 0;
						}
					}
				}
				j=link[j];
			}

			v[q[p]]=0;
			p++;
			if (p>tot) p=1;
        }
		while (p!=k);

		if (kk==k) break;
		k=kk;
		p++;
		if (p>tot) p=1;
	}

	if (d[edd]<0) {
        cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;
	return 0;
}
