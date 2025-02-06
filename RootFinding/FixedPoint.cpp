#include "RootFinding.hpp"
using namespace std;

void RootFinding::fixedPointIteration()
{
    double x0 = findInitialGuess(); // Initial guess
    cout << fixed << setprecision(4);
    cout << "Iter |    x        |   f(x)     |   Diff  \n";
    cout << "--------------------------------------------\n";

    double x_new;
   

    double g_prime = fabs(dg(x0));
    cout << "Derivative of g(x) at x0: " << g_prime << endl;


    if (g_prime >= 1) {
        cout << "Convergence condition not met: |g'(x)| >= 1. The method may not converge." << endl;
        return;
    }

    do
	 {
		  x_new = g(x0);
		  cout<<"Iteration-"<< step<<":\t x1 = "<< setw(10)<< x_new<<" and f(x1) = "<< setw(10)<< f(x_new)<< endl;

		  step = step + 1;

          g_prime = fabs(dg(x0));

		   if (g_prime >= 1){
            cout << "Convergence condition violated: |g'(x)| >= 1 at iteration " << step << endl;
            cout << "Not convergent." << endl;
            exit(0); // Terminate if convergence fails
        }

		  x0 = x_new;

	 }while( fabs(f(x_new)) > tol);

    cout << "--------------------------------------------\n";
    cout << "Fixed Point Approximation: " << x_new << " (after " << step << " iterations)\n";
}
