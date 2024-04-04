/*
    There are three friend living on the straight line Ox in Lineland. The first friend lives at the point x 1 , the second friend lives at the point x 2 , and the third friend lives at the point x 3 . They plan to celebrate the New Year together, so they need to meet at one point. What is the minimum total distance they have to travel in order to meet at some point and celebrate the New Year? It's guaranteed that the optimal answer is always integer.
*/

/*@ predicate IsValidSolution(long x1, long x2, long x3, long result) =
    \exists long point;
    0 <= point &&
    \abs(point - x1) + \abs(point - x2) + \abs(point - x3) == result;
*/

/*@ predicate ExistsSmallerSolution(long x1, long x2, long x3, long result) =
    \exists long smaller_solution;
    IsValidSolution(x1, x2, x3, smaller_solution) &&
    smaller_solution < result;
*/

/*@
    requires \valid(out);
    requires 1 <= x1 <= 100;
    requires 1 <= x2 <= 100;
    requires 1 <= x3 <= 100;
    requires \exists int result; IsValidSolution(x1, x2, x3, result);
    assigns *out;
    ensures IsValidSolution(x1, x2, x3, *out);
    ensures !ExistsSmallerSolution(x1, x2, x3, *out);
*/
void calculateOptimalMeetingPointDistance(int x1, int x2, int x3, int *out);
