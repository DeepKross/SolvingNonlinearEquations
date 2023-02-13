#include <iostream>
#include <cmath>
//#include <iomanip>

using namespace std;

class equation{
public:
    int a; // Ax^3
    int b; // Bx^2
    int c; // Cx
    int d; // D
};

equation setParams(){
    equation eq;
    cout << "This Program can solve nonlinear equations (Ax^3 + Bx^2 + Cx + D = 0) using 3 methods." << endl;
    cout << "Enter 4 parameters A, B, C, D" <<endl;
    cout << "A: ";
    cin >> eq.a;
    cout << "B: ";
    cin >> eq.b;
    cout << "C: ";
    cin >> eq.c;
    cout << "D: ";
    cin >> eq.d;
    return eq;
}

double setPrecision(){
    double eps;
    cout << "Choose precision (epsylon)." << endl;
    cout << "Precision: "; cin >> eps;
    return eps;
}

double value( equation eq, double x){
    double res = (eq.a * x*x*x) + ( eq.b * x*x) + ( eq.c * x) + eq.d;
    return res;
}

double deravative(equation eq, double x){
    double res = (3 * eq.a * x * x) + (2 * eq.b * x) + (eq.c);
    return res;
}

void bisection(equation eq, double eps) {
    //entering endpoints
    double xl, xr;
    cout << "Enter left and right segment limits." << endl;
    cout << "left x: "; cin >> xl;
    cout << "right x: "; cin >> xr;

    // Counting the num of iterations
    int nMAX = log2( (xr-xl) / eps);
    cout << nMAX << endl;

    cout << "1iteration: " << xl << " " << xr << " "  << endl;

    double midpt;
    for(int i = 0; i < nMAX; i++){
        //setting midpoint
        midpt = (xr+xl) / 2.0;
        double result = value(eq,midpt);
        if(result < 0){
            xl = midpt;
        }
        else if(result > 0) {
            xr = midpt;
        }
        cout << i+2 << "iteration: " << xl << " " << xr << endl;
    }
    cout << "Root for the polynomial is " << midpt << endl;
}

void newthon(equation eq, double eps){
    double x;
    cout << "Insert initial x: "; cin >> x;

    int i = 2;
    cout << "1iteration: " << x << " " << value(eq, x) << endl;
    while(abs(value(eq, x)) > eps){
        x -= value(eq, x) / deravative(eq, x);
        cout << i << "iteration: " << x << " " << value(eq, x) << endl;
        i++;
    }
}

int main() {
    while(true){
        equation eq = setParams();

        double eps = setPrecision();

        int method;
        cout << "Choose method for solving your nonlinear equation. Enter [1] for bisection method. Enter [2] for "
                "Newthon method and [3] for simple iteration method: "; cin >> method;
        if(method == 1){
            bisection(eq,eps);
        }
        else if(method == 2){
            newthon(eq,eps);
        }
    }
    return 0;
}
