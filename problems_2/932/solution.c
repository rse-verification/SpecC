/*  A. Exams
    One day the Codeforces round author sat exams. He had n exams and he needed to get an integer from 2 to 5 for each exam. He will have to re-sit each failed exam, i.e. the exam that gets mark 2 . The author would need to spend too much time and effort to make the sum of his marks strictly more than k . That could have spoilt the Codeforces round. On the other hand, if the sum of his marks is strictly less than k , the author's mum won't be pleased at all. The Codeforces authors are very smart and they always get the mark they choose themselves. Also, the Codeforces authors just hate re-sitting exams. Help the author and find the minimum number of exams he will have to re-sit if he passes the exams in the way that makes the sum of marks for all n exams equal exactly k . */

/*@
    requires \valid(out);
    requires    1 <= n <= 50;
    requires    1 <= k <= 250;
    requires    2 * n <= k <= 5 * n;
    assigns *out;
    behavior count_less_equal_0:
        assumes (3 * n - k) <= 0;
        ensures *out == 0;
    behavior count_greater_0:
        assumes (3 * n - k) > 0;
        ensures *out == (3 * n - k);
*/
void problem(int n, int k, int *out)
{
    if (3 * n - k <= 0)
    {
        *out = 0;
    }
    else
    {
        *out = 3 * n - k;
    }
}
