#include <iostream>
//#include <math.h>
// change the value below to 1 to run tests against your Complex class.
// change the value below to 0 to run tests against the built in std::complex.

#if o
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
double round(double r)
{

if ((r + 0.5) >= (int(r)+1))
	return int(r)+1;
else
	return int(r);
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
	Complex ans1(-1,43);
	Complex ans2(1.75,-.25);
	Complex ans3(9,10);
	Complex ans4(-1,-4);
	Complex ans5(-20,46);
	Complex ans6(2,.5);
	Complex ans7(8,12);
	Complex ans8(1,4);
	Complex ans9(1,4);
	
	//values
	Assert(z1.real() == 4, "real constructor");//
	Assert(z4.real() == 2, "real constructor");//
	Assert(z4.imag() == -4, "real constructor");//
	Assert(z6.imag() == -.5, "real constructor");//
	
	// math operations
	Assert((z1 * z2) == ans1, "z1 * z2"); //
	Assert((z2 * z5) == ans5, "z1 * z5"); //
	Assert((z1 / z3) == ans2, "z1 / z2"); //
	Assert((z5 / z3) == ans6, "z1 / z5"); //
	Assert((z1 + z2) == ans3, "z1 + z2"); //
	Assert((z5 + z2) == ans7, "z5 + z2"); //
	Assert((z1 - z2) == ans4, "z1 - z2"); //
	Assert((z2 - z1) == ans9, "z2 - z1"); //


	 Complex e1(2,2);
	 Complex e2(2,2);
	 Complex e3(4,4);
	 Complex e4(2,2);
	 Complex e5(2,2);
	 Complex e6(2,2);
	 Complex e7(2,2);
	 Complex e8(2,2);

	//assignment
	e1 *= Complex(2,1);
	Assert(e1 == Complex(2,6), "testing *="); //

	e2 *= Complex(1,3);
	Assert(e2 == Complex(-4,8), "testing *="); //

	e3 /= Complex(2,2);
	Assert(e3 == Complex(2,0), "testing /="); //

	e4 /= Complex(.5,.5);
	Assert(e4 == Complex(4,0), "testing /="); //
	
	e5 += Complex(3,3);
	Assert(e5 == Complex(5,5), "testing +="); //

	e6 += Complex(-1,.5);
	Assert(e6 == Complex(1,2.5), "testing +="); //

	e7 -= Complex(5,5);
	Assert(e7 == Complex(-3,-3), "testing -="); //
	
	e8 -= Complex(5,-5);
	Assert(e8 == Complex(-3,7), "testing -="); //
	
	//double val1,val2,eps;	
	
	//bool approx(val1,val2,eps)
	//{
	//return abs(val1-val2) < eps;
	//}
	
//	Assert(approx(20,norm(z4),.000001), "approx norm");
	//std::cout<<norm(z4)<<std::endl;
	Assert(round(norm(z4)) == 20, "complex norm"); //
	//std::cout<<norm(z4)<<std::endl;
	
	Assert(norm(z1) == 25, "complex norm");//
	Assert(conj(z4) == Complex(2,4), "complex conj");//
	Assert(conj(z6) == Complex(.3,.5), "complex conj");//
	return 0;
}


