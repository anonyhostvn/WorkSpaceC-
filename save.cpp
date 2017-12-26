int play(int player , int km , int kn)
{

    if (l[player][km][kn] != -1) return l[player][km][kn] ;

    int res = 0 ;

    fordec(i,km-1,0)
    if ((sum(i+1,1,km,kn) % 2 == 0) && (play(1-player,i,kn) == 0))
    {

        res = 1 ;
        break ;

    }

    if (res == 1)
    {

        l[player][km][kn] = 1 ;
        return res ;

    }

    fordec(i,kn-1,0)
    if ((sum(1,i+1,km,kn) % 2 == 0) && (play(1-player,km,i) == 0))
    {

        res = 1 ;
        break ;

    }

    l[player][km][kn] = res ;

    return res ;

}
