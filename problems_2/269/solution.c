
/*@
    requires \valid(out1) && \valid(out2) && \separated(out1, out2);
    requires 1 <= N <= 1000000000;
    assigns *out1, *out2;
    behavior N_less_than_3:
        assumes N < 3;
        ensures *out1 == -1 && *out2 == -1;
    behavior N_greater_than_3_and_N_odd:
        assumes N >= 3 && N % 2 != 0;
        ensures *out1 == (N * N - 1) / 2 && *out2 == (N * N  + 1) / 2;
    behavior N_greater_than_3_and_N_even:
        assumes N >= 3 && N % 2 == 0;
        ensures *out1 == (N * N) / 4 - 1 && *out2 == (N * N) / 4 + 1 ;
    complete behaviors;
    disjoint behaviors;
*/
void problem(int N, long *out1, long *out2)
{
    long n = N;
    if (n < 3)
    {
        *out1 = -1;
        *out2 = -1;
    }
    else
    {
        if (n % 2 != 0)
        {
            *out1 = (n * n - 1) / 2;
            *out2 = (n * n + 1) / 2;
        }
        else
        {
            *out1 = (n * n) / 4 - 1;
            *out2 = (n * n) / 4 + 1;
        }
    }
}
