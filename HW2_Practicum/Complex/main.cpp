#include <iostream>
#include "Complex.h"

int main()
{
	// googled a random site to compare results with
	// https://www.varsitytutors.com/hotmath/hotmath_help/topics/operations-with-complex-numbers
	Complex add1(2, 7);
	Complex add2(3, -4);

	Complex sub1(9, 5);
	Complex sub2(4, 7);

	Complex mult1(3, 2);
	Complex mult2(5, 6);

	Complex div1(3, 2);
	Complex div2(4, -5);

	Complex result1, result2, result3, result4;

	result1 = add1 + add2;
	result2 = sub1 - sub2;
	result3 = mult1 * mult2;
	result4 = div1 / div2;

	result1.print();
	result2.print();
	result3.print();
	result4.print();

	Complex add3 = add1;
	Complex sub3 = sub1;
	Complex mult3 = mult1;
	Complex div3 = div1;

	add3 += add2;
	sub3 -= sub2;
	mult3 *= mult2;
	div3 /= div2;
	add3.print();
	sub3.print();
	mult3.print();
	div3.print();

	Complex equal1(2, 3);
	Complex equal2 = equal1;

	std::cout << (equal1 >= equal2) << (equal1 <= equal2) << (equal1 < equal2) << (equal1 > equal2)
		<< (equal1 == equal2) << (equal1 != equal2); // 1 1 0 0 1 0

	return 0;
}