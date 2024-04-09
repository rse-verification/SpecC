/*
    Vasya lives in a round building, whose entrances are numbered sequentially by integers from 1 to n . Entrance n and entrance 1 are adjacent. Today Vasya got bored and decided to take a walk in the yard. Vasya lives in entrance a and he decided that during his walk he will move around the house b entrances in the direction of increasing numbers (in this order entrance n should be followed by entrance 1 ). The negative value of b corresponds to moving | b | entrances in the order of decreasing numbers (in this order entrance 1 is followed by entrance n ). If b = 0 , then Vasya prefers to walk beside his entrance. Illustration for n = 6 , a = 2 , b = - 5 . Help Vasya to determine the number of the entrance, near which he will be at the end of his walk.
*/

/*@ predicate exists_amount_of_steps(integer n, integer a, integer b, integer out) =
    \exists integer x;
    (a + b + n * x) == out;
*/

/*@
    requires \valid(out);
    requires n <= 100000000;
    requires 1 <= a <= n;
    requires -100 <= b <= 100;
    assigns *out;
    ensures 1 <= *out <= n;
    ensures \exists integer x;  (a + b + n * x) >= 1 && (a + b + n * x) <= 200000 * n;
*/
void findVasyasFinalEntrance(int n, int a, int b, int *out)
{
    b = ((b % n) + n) % n;

    int c = (a + b) % n;
    if (c == 0)
    {
        *out = n;
    }
    else
    {
        *out = c;
    };
}
