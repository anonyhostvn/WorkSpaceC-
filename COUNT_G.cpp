
int num_G(int x) {
    int res = 1;
    for (int i = 2 ; i <= (int) sqrt(x) ; i ++ ) if (x % i == 0) {
        int cnt = 0 ;
        while (x % i == 0) cnt ++ , x /= i ;
        res *= (cnt + 1) ;
    }
    if (x > 1) res *= 2 ;
    return res ;
}

