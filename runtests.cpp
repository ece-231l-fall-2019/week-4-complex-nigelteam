#include <iostream>

// change the value below to 1 to run tests against your Complex class.
// change the value below to 0 to run tests against the built in std::complex.

#if 0
#include "Complex.h"
#else
#include <complex>
typedef std::complex<double> Complex;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	//constructors
	Complex z1(4, 3);
	Complex z2(5, 7);
	Complex z3(2,2);
	Complex z4(2,-4);
	Complex z5(3,5);
	Complex z6(.3,-.5);
	Complex ans1(20,21);
	Complex ans2(.8,.42);
	Complex ans3(9,10);
	Complex ans4(-1,-4);
	Complex ans5(15,35);
	Complex ans6((4/3),(3/5));
	Complex ans7(8,12);
	Complex ans8(1,4);
	
	//values
	Assert(z1.real() == 4, "real constructor");//
	Assert(z4.real() == 2, "real constructor");//
	Assert(z4.imag() == -4, "real constructor");//
	Assert(z6.imag() == -.5, "real constructor");//
	
	// math operations
	Assert((z1 * z2) == ans1, "z1 * z2"); //
	Assert((z2 * z5) == ans5, "z1 * z5"); //
	Assert((z1 / z2) == ans2, "z1 / z2"); //
	Assert((z1 / z5) == ans6, "z1 / z2"); //
	Assert((z1 + z2) == ans3, "z1 + z2"); //
	Assert((z5 + z2) == ans7, "z1 + z2"); //
	Assert((z1 - z2) == ans4, "z1 - z2"); //
	Assert((z2 - z1) == ans4, "z1 - z2"); //
	



	//assignment
	z3 *= Complex(2,2);
	Assert(z3 == Complex(4,4), "testing *="); //

	//z3 *= Complex(2,2);
	//Assert(z3 == Complex(4,4), "testing *="); //

	z3 /= Complex(.5,.5);
	Assert(z3 == Complex(4,4), "testing /="); //

	//z3 /= Complex(.5,.5);
	//Assert(z3 == Complex(4,4), "testing /="); //
	
	z3 += Complex(3,3);
	Assert(z3 == Complex(5,5), "testing +="); //not working

	//z3 += Complex(3,3);
	//Assert(z3 == Complex(5,5), "testing +="); //not working
	
	z3 -= Complex(5,5);
	Assert(z3 == Complex(-3,-3), "testing -="); //
	
	//z3 -= Complex(5,5);
	//Assert(z3 == Complex(-3,-3), "testing -="); //
		
	Assert(norm(z4) == 20, "complex norm"); //
	Assert(norm(z1) == 25, "complex norm");//
	Assert(conj(z4) == Complex(2,4), "complex conj");//
	Assert(conj(z6) == Complex(.3,.5), "complex conj");//
	return 0;
}


