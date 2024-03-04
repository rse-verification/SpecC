#include <math.h>
/*  The New Year: Meeting Friends
    There are three friend living on the straight line Ox in Lineland. The first friend lives at the point x 1 , the second friend lives at the point x 2 , and the third friend lives at the point x 3 . They plan to celebrate the New Year together, so they need to meet at one point. What is the minimum total distance they have to travel in order to meet at some point and celebrate the New Year? It's guaranteed that the optimal answer is always integer.
*/

/*@ predicate abs_value(int x, int result) =
      (x >= 0 ==> result == x) &&
      (x < 0 ==> result == -x);
  @*/

/*@
    requires \valid(out);
    requires 1 <= x1 <= 100;
    requires 1 <= x2 <= 100;
    requires 1 <= x3 <= 100;
    assigns *out;
    ensures *out == 2 * (\max(x1, \max(x2, x3)) - \min(x1, \min(x2, x3)));
    */

void problem(long x1, long x2, long x3, long *out)
{
    long max = x1;
    long min = x1;
    if (x2 > max)
        max = x2;
    if (x3 > max)
        max = x3;
    if (x2 < min)
        min = x2;
    if (x3 < min)
        min = x3;
    *out = 2 * (max - min);
}
