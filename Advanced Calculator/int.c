#include<stdio.h>
#include<string.h>

typedef struct{
    double coefficient;
    int power;
    char fucn[10];
} Term;

void IntegrateTrig(char *func, double coefficient) {
    if (strcmp(func, "sin") == 0) {
        printf("-%.1f cos(x)", coefficient);
    } else if (strcmp(func, "cos") == 0) {
        printf("%.1f sin(x)", coefficient);
    } else if (strcmp(func, "tan") == 0) {
        printf("%.1f ln|sec(x)|", coefficient);
    } else if (strcmp(func, "cot") == 0) {
        printf("-%.1f ln|csc(x)|", coefficient);
    } else if (strcmp(func, "sec") == 0) {
        printf("%.1f tan(x)", coefficient);
    } else if (strcmp(func, "csc") == 0) {
        printf("-%.1f cot(x)", coefficient);
    } else {
        printf("Unknown function\n");
    }
}

// Indefinite Integral
void IntegrateTerm(Term t){
    if (t.coefficient == 0) {
        return; // Skip terms with zero coefficient
    }
    if(t.power == -1){ // Special case of integral x^-1
        if(t.coefficient == 1){
            printf("ln|x|");
        } else {
            printf("%.2fln|x|",t.coefficient);
        }
    } else {// Power Rule
        double newCoeff = t.coefficient / (t.power + 1);
        int newPow = t.power + 1;
        if(newPow == 1){
            printf("%.2fx",newCoeff);
        } else {
            printf("%.2fx^%d",newCoeff,newPow);
        }
    }
}

void IntegratePolynomial(Term terms[], int numTerms){
    printf("\nThe integral of given polynomial is: ");
    for(int i=0; i<numTerms; i++){
        if (strcmp(terms[i].fucn, "sin") == 0 || strcmp(terms[i].fucn, "cos") == 0 || 
                strcmp(terms[i].fucn, "tan") == 0 || strcmp(terms[i].fucn, "cot") == 0 ||
                strcmp(terms[i].fucn, "sec") == 0 || strcmp(terms[i].fucn, "csc") == 0) {
                IntegrateTrig(terms[i].fucn, terms[i].coefficient);
                } else {
                    IntegrateTerm(terms[i]);
                }
        
        if(i < numTerms - 1){
            printf(" + ");
        }
    }
    printf(" + C\n");
}

// Definite Integral

// Logarithmic function
double ln(double x) {
    if (x <= 0) {
        printf("Error: Log is undefined for x <= 0.\n");
        return 0;
    }

    double result = 0.0;
    while (x > 2) {
        result += 0.693147; // Approximation of ln(2)
        x /= 2;
    }
    while (x < 0.5) {
        result -= 0.693147; // Approximation of ln(2)
        x *= 2;
    }

    // Use Taylor series for 0.5 <= x <= 2
    double term = x - 1;
    double power = term;
    for (int i = 1; i <= 10; ++i) {
        if (i % 2 == 0)
            result -= power / i;
        else
            result += power / i;
        power *= (x - 1);
    }
    return result;
}


// Power function
double power(double base, int exp) {
    double result = 1.0;
    if (exp == 0) {
        return 1.0;
    }
    int isNeg = exp < 0;
    if (isNeg) exp = -exp;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    // printf("power(%lf, %d) = %lf\n", base, exp, result);
    return isNeg ? 1.0 / result : result;
}

// Term integration
double IntegrateDefTerm(Term t, double a, double b, int *canIntegrate) {
    double result = 0.0;
    if (t.power == -1) {
        if (a == 0) {
            *canIntegrate = 0;
            printf("Warning ln(x) is undefined at x = 0.\n");
            return 0;
        } else {
            result = t.coefficient * (ln(b) - ln(a));
        }
    } else {
        double newCoeff = t.coefficient / (t.power + 1);
        int newPow = t.power + 1;
        result = newCoeff * (power(b, newPow) - power(a, newPow));
    }
    //printf("Term Coefficient: %.2f, Power: %d, Integral: %.2f\n", t.coefficient, t.power, result);
    return result;
}

// Polynomial integration
double DefIntegratePoly(Term terms[], int numTerms, double a, double b) {
    double integralVal = 0.0;
    int flag = 1;
    for (int i = 0; i < numTerms; i++) {
        integralVal += IntegrateDefTerm(terms[i], a, b, &flag);
        if (!flag) {
            return 0;
        }
        // printf("After term %d: Accumulated Integral = %.2f\n", i + 1, integralVal);
    }
    return integralVal;
}
