/*  A. Vasya the Hipster
    One day Vasya the Hipster decided to count how many socks he had. It turned out that he had a red socks and b blue socks. According to the latest fashion, hipsters should wear the socks of different colors: a red one on the left foot, a blue one on the right foot. Every day Vasya puts on new socks in the morning and throws them away before going to bed as he doesn't want to wash them. Vasya wonders, what is the maximum number of days when he can dress fashionable and wear different socks, and after that, for how many days he can then wear the same socks until he either runs out of socks or cannot make a single pair from the socks he's got. Can you help him?
*/

/* Computation of the maximal number of days when hhe can dress fashionable and wear different socks */
/*@
    requires a >= 0 &&  a<= 1;
    requires b >= 0 &&  b <= 100;
    assigns \nothing;
    behavior has_more_red:
        assumes a > b;
        ensures \result == b;
    behavior has_more_blue:
        assumes b > a;
        ensures \result == a;
    behavior equal_socks:
        assumes a == b;
        ensures \result == a;
*/
int maximum_days_socks(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else if (b > a)
    {
        return a;
    }
    else
    {
        return a;
    }
}

/* Computation of the maximal number of days where he can wear the same socks until he either uns out of socks or cannot make a single pair from the socks he has got*/
/*@
    requires a >= 0 &&  a<= 1;
    requires b >= 0 &&  b <= 100;
    assigns \nothing;
    behavior has_more_red:
        assumes a > b;
        ensures \result == (a - b) / 2;
    behavior has_more_blue:
        assumes b > a;
        ensures \result == (b - a) / 2;
    behavior equal_socks:
        assumes a == b;
        ensures \result == 0;
*/
int days_remaining_sock(int a, int b)
{
    if (a > b)
    {
        return (a - b) / 2;
    }
    else if (b > a)
    {
        return (b - a) / 2;
    }
    else
    {
        return 0;
    }
}