#include <bits/stdc++.h>
#define oo 2000000000
#define forinc(i,a,b) for (int i = a ; i <= b ; i ++ )
#define fordec(i,a,b) for (int i = a ; i >= b ; i -- )

using namespace std ;

struct node
{

    int val ;
    int id ;
    int typ ;

};

int n , m , s[100001] , a[100001] , b[100001] , c[100001] , nheap ,l ,pos[300001],train[300001],num[300001] ;
node heap[300001] ;
node event[300001] ;
bool invite[200001] ;

int enter()
{

    cin >> n >> m ;

    forinc(i,1,n) cin >> s[i] >> c[i] ;
    forinc(i,1,m) cin >> a[i] >> b[i] ;

    int cnt = 0 ;
    forinc(i,1,m)
    {

        cnt ++ ;
        event[cnt].val = a[i] ;
        event[cnt].typ = 1 ;
        event[cnt].id = i ;
        cnt++ ;
        event[cnt].val = b[i] ;
        event[cnt].typ = 0 ;
        event[cnt].id = i ;

    }

    forinc(i,1,n)
    {

        cnt++ ;
        event[cnt].val = s[i] ;
        event[cnt].typ = 2 ;
        event[cnt].id = i ;

    }

    l = cnt ;

}

int qs(int l , int r)
{

    if (l >= r) return 0 ;

    int i = l , j = r , mid = l+rand()%(r-l+1) ,  key = event[mid].val , key1 = event[mid].typ ;

    while (i <= j)
    {

        while ((event[i].val < key) || ((event[i].val == key) && (event[i].typ < key1)))  i++ ;
        while ((event[j].val > key) || ((event[j].val == key) && (event[j].typ > key1))) j-- ;
        if (i <= j)
        {

            swap(event[i],event[j]) ;
            i++ ; j -- ;

        }

    }

    qs(l,j) ;
    qs(i,r) ;

}

int upheap(int i)
{

    if ((i == 1) || (heap[i].val >= heap[i / 2].val)) return 0 ;

    swap(heap[i],heap[i / 2]) ;
    pos[heap[i].id] = i ;
    pos[heap[i / 2].id] = i / 2 ;

    upheap(i / 2) ;

}

int downheap(int i)
{

    int j = 2 * i ;

    if (j > nheap) return 0 ;

    if ((j < nheap) && (heap[j].val > heap[j+1].val)) j++ ;

    if (heap[i].val <= heap[j].val) return 0 ;

    swap(heap[i],heap[j]) ;

    pos[heap[i].id] = i ;
    pos[heap[j].id] = j ;

    downheap(j) ;

}

int hpush(int v , int i , int type)
{

    nheap++ ;
    heap[nheap].id = i ;
    heap[nheap].typ = type ;
    heap[nheap].val = v ;
    pos[i] = nheap ;

    upheap(nheap) ;

}

node pop ()
{

    node res = heap[1] ;
    heap[1] = heap[nheap] ;
    pos[heap[1].id] = 1 ;
    nheap-- ;
    downheap(1) ;

    return res;

}

int remove_heap(int i)
{

    heap[i].val = oo ;
    downheap(i) ;
    pop() ;

}

queue<int> st ;

int pre_process()
{

    int gap = 0  , res = 0 ;

    qs(1,l) ;

    //forinc(i,1,l) cout << event[i].typ << " " << event[i].id << " " << event[i].val << endl ;

    fordec(i,l,1)
    if (event[i].typ == 2)
    {

        gap += c[event[i].id] ;

        st.push(event[i].id) ;

        num[event[i].id] = c[event[i].id] ;

    }
    else if (event[i].typ == 0)
    {

        int ii  = event[i].id ;

        if (gap > 0)
        {

            gap-- ;

            hpush(a[ii],ii,0) ;

            invite[ii] = true ;

            num[st.front()] -- ;

            train[ii] = st.front() ;

            if (num[st.front()] == 0) st.pop() ;

        }

        else

        {

            if (a[ii] > heap[1].val)
            {


                train[ii] = train[heap[1].id] ;
                train[heap[1].id] = 0 ;

                invite[heap[1].id] = false ;
                invite[ii] = true ;
                heap[1].val = a[ii] ;
                heap[1].id = ii ;
                downheap(1) ;

            }

        }

    }
    else
    {

        int ii = event[i].id ;

        if (invite[ii])
        {

            res ++ ;

            gap ++ ;

            remove_heap(pos[ii]) ;

            int bus = train[ii] ;

            num[bus] ++ ;

            if (num[bus] == 1) st.push(bus) ;

        }

    }

    cout << res << endl ;

    forinc(i,1,m) cout << train[i] << endl ;

}

int main ()
{

    freopen("inftrain.inp" , "r" , stdin) ;
    freopen("inftrain.out" , "w" , stdout)  ;

    enter() ;
    pre_process() ;

}
