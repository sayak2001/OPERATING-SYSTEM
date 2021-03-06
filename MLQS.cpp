#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC(T) while(1)
#define REP(i,total) for (ll i=0;i<total;i++)
#define REP2(i,total) for( ; i < total ; i++)
#define s1(q,w) sort(S.begin(),S.end());
#define s2() selectionSort();
#define s3() executeInRR();
#define s4() executeInSRTF();
#define s6() displayProcess();
typedef long long int ll;
typedef char c;
ll total;
ll rem;
ll cputime = 0;
ll i,j;
struct Process
{
	ll id;
	ll arrivaltime;
	ll bursttime;
	c terminated;
	ll rt;
	ll ct;
	ll tat;
	ll wt;
};
struct  Process p[3201];

void displayProcess(){
	ll i;
	printf("Queue\tArrival time \tbrust time\tcomplection time\tturn around time\twaiting time\n");
	REP(i,total)
	//for loop
	{
		printf("%d\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].id, p[i].arrivaltime, p[i].bursttime, p[i].ct, p[i].tat, p[i].wt);
		
	}
}

void executeInRR()
{
	ll i;
	REP(i,total)
	//for loop
	{
		if(p[i].rt <= 2)
		{
			cputime += p[i].rt;
			p[i].rt = 0;
			p[i].terminated = 'y';
			p[i].ct = cputime;
			p[i].tat = p[i].ct - p[i].arrivaltime;
			p[i].wt = p[i].tat - p[i].bursttime;
			rem --;
		}
		else
		{
			p[i].rt -= 2;
			cputime += 2;
		}
	}
}
ll minBurstTime()
{
	ll i = 0;
	ll pos = -1;
	while( i < total)
	{
		if(p[i].terminated != 'y'){
			pos = i;
			break;
		}
		i++;
	}
	REP2(i,total)
	//for loop
	{
		if(p[i].terminated != 'y' && p[i].bursttime < p[pos].bursttime)
			pos = i;
	}
	return pos;
}

void executeInSRTF(){
	ll index;
	ll T=1;
	//TC(T) simple
	while(1)
	{
		index = minBurstTime();
		if(index == -1)
			break;
		if(p[index].arrivaltime > cputime)
		{
			cputime = p[index].arrivaltime;
		}
		cputime += p[index].rt;				
		p[index].rt = 0;
		p[index].terminated = 'y';
		p[index].ct = cputime;
		p[index].tat = p[index].ct - p[index].arrivaltime;
		p[index].wt = p[index].tat - p[index].bursttime;
	}	
	
}

void selectionSort(){
	struct Process temp;
	ll pos;
	ll i,j;
	//for loop
	REP(i,total)
	{
		pos = i;
		for( j = i ; j < total ; j++)
		{
			if(p[j].arrivaltime < p[pos].arrivaltime)
				pos = j;
		}
		temp = p[pos];
		p[pos] = p[i];
		p[i] = temp;
	}                       
	cputime += p[0].arrivaltime;
}

int main()
{
	FIO
    printf("Enter number of Processes : ");
	scanf("%d", &total);
	rem = total - 1;
	ll i;
	//for( i = 0 ; i < total ; i++)
	REP(i,total)
	{
		printf("Process %d\n", i+1);
		printf("Queue : " );
		scanf("%d", &p[i].id);
		printf("Arrival time : " );
		scanf("%d", &p[i].arrivaltime);
		printf("Burst time : ");
		scanf("%d", &p[i].bursttime);
		p[i].terminated = 'n';
		p[i].rt = p[i].bursttime;
	}
	s2();
	
	s3();
	s4();	
	s6();		
	printf("\n\nMADE BY Sayak Bhowmick");
}
