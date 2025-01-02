#include<stdio.h>
#include<string.h>

typedef struct{
    double coefficient;
    int power;
    char func[10];
} DTerm;

// Function to differentiate a trigonometric term
void DiffTrigTerm(char *func, double coefficient){
    if(strcmp(func, "sin")== 0){
        printf("%.1fcos(x)", coefficient);
    } else if(strcmp(func, "cos") == 0){
        printf("-%.1fsin(x)", coefficient);
    } else if(strcmp(func, "tan") == 0){
        printf("%.1fsec^2(x)", coefficient);
    } else if(strcmp(func, "cot") == 0){
        printf("-%.1fcsc^2(x)", coefficient);
    } else if(strcmp(func, "sec") == 0){
        printf("%.1fsec(x)tan(x)", coefficient);
    } else if(strcmp(func, "cos") == 0){
        printf("-%.1fcsc(x)cot(x)", coefficient);
    } else if(strcmp(func, "ln") == 0) {
        printf("%.1f/x", coefficient);
    } else if(strcmp(func, "exp") == 0) {
        printf("%.1fexp(x)", coefficient);
    } else {
        printf("Unknown function!");
    }
}

//Polynomial
void DiffPoly(DTerm terms[], int numterms){
    int flag = 1; // if all terms are constant
    printf("The derivative of polynomial is: ");
    int first = 1; // flag to manage output
    for(int i=0; i<numterms; i++){
        if(terms[i].power == 0){
            continue; //Skip constant terms
        }
        flag = 0;
        if(strcmp(terms[i].func, "sin") == 0 || strcmp(terms[i].func, "cos") == 0 || 
                strcmp(terms[i].func, "tan") == 0 || strcmp(terms[i].func, "cot") == 0 ||
                strcmp(terms[i].func, "sec") == 0 || strcmp(terms[i].func, "csc") == 0 ||
                strcmp(terms[i].func, "ln") == 0 || strcmp(terms[i].func, "exp") == 0) {
                DiffTrigTerm(terms[i].func, terms[i].coefficient);
                } else {
                    double newCoeff = terms[i].coefficient * terms[i].power;
                    int newPow = terms[i].power - 1;
                    printf("%.1fx^%d",newCoeff, newPow);
            }  
            if (i < numterms - 1) printf(" + ");      
    }
    if(flag){
        printf("0 (Since the polynomial is a constant)\n");
    } else {
        printf("\n");
    }
}

//Product Rule
// Function to differentiate a polynomial
void DifferentiatePolynomial(DTerm poly[], int size, DTerm result[], int *resultSize) {
    *resultSize = 0;
    for (int i = 0; i < size; i++) {
        if (poly[i].power != 0) {
            result[*resultSize].coefficient = poly[i].coefficient * poly[i].power;
            result[*resultSize].power = poly[i].power - 1;
            (*resultSize)++;
        }
    }
}

// Function to multiply two polynomials
void MultiplyPolynomials(DTerm poly1[], int size1, DTerm poly2[], int size2, DTerm result[], int *resultSize) {
    *resultSize = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            result[*resultSize].coefficient = poly1[i].coefficient * poly2[j].coefficient;
            result[*resultSize].power = poly1[i].power + poly2[j].power;
            (*resultSize)++;
        }
    }
}

// Function to combine like terms in a polynomial
void CombineLikeTerms(DTerm result[], int *size) {
    // Sort terms by power in descending order 
    for (int i = 0; i < *size - 1; i++) {
        for (int j = 0; j < *size - i - 1; j++) {
            if (result[j].power < result[j + 1].power) {
                DTerm temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
     // Combine terms with the same power
    int newSize = 0;
    for (int i = 0; i < *size; i++) {
        if (i > 0 && result[i].power == result[newSize - 1].power) {
            result[newSize - 1].coefficient += result[i].coefficient;
        } else {
            result[newSize++] = result[i];
        }
    }
    *size = newSize; 
}

// Function to apply the product rule
void ProductRule(DTerm u[], int sizeU, DTerm v[], int sizeV) {
    DTerm du[100], dv[100], du_v[100], u_dv[100], combined[200];
    int sizeDU, sizeDV, sizeDUV, sizeUDV, combinedSize;

    // Differentiate u(x) and v(x)
    DifferentiatePolynomial(u, sizeU, du, &sizeDU);
    DifferentiatePolynomial(v, sizeV, dv, &sizeDV);

    printf("u'(x): ");
    for (int i = 0; i < sizeDU; i++) {
        printf("%.1fx^%d", du[i].coefficient, du[i].power);
        if (i < sizeDU - 1) printf(" + ");
    }
    printf("\n");

    printf("v'(x): ");
    for (int i = 0; i < sizeDV; i++) {
        printf("%.1fx^%d", dv[i].coefficient, dv[i].power);
        if (i < sizeDV - 1) printf(" + ");
    }
    printf("\n");

    // Calculate u'(x)v(x) and u(x)v'(x)
    MultiplyPolynomials(du, sizeDU, v, sizeV, du_v, &sizeDUV);
    MultiplyPolynomials(u, sizeU, dv, sizeDV, u_dv, &sizeUDV);

    printf("u'(x)v(x): ");
    for (int i = 0; i < sizeDUV; i++) {
        printf("%.1fx^%d", du_v[i].coefficient, du_v[i].power);
        if (i < sizeDUV - 1) printf(" + ");
    }
    printf("\n");

    printf("u(x)v'(x): ");
    for (int i = 0; i < sizeUDV; i++) {
        printf("%.1fx^%d", u_dv[i].coefficient, u_dv[i].power);
        if (i < sizeUDV - 1) printf(" + ");
    }
    printf("\n");

    // Combine both results
    combinedSize = 0;
    for (int i = 0; i < sizeDUV; i++) {
        combined[combinedSize++] = du_v[i];
    }
    for (int i = 0; i < sizeUDV; i++) {
        combined[combinedSize++] = u_dv[i];
    }

    // Combine like terms in the final result
    CombineLikeTerms(combined, &combinedSize);

    // Display the result
    printf("The derivative of the product is:\n");
    for (int i = 0; i < combinedSize; i++) {
        printf("%.1fx^%d", combined[i].coefficient, combined[i].power);
        if (i < combinedSize - 1) printf(" + ");
    }
    printf("\n");
}

// Function to apply the quotient rule
void QuotientRule(DTerm u[], int sizeU, DTerm v[], int sizeV) {
    DTerm du[100], dv[100], du_v[100], u_dv[100], numerator[200], denominator[100];
    int sizeDU, sizeDV, sizeDUV, sizeUDV, numSize, denomSize;

    // Differentiate u(x) and v(x)
    DifferentiatePolynomial(u, sizeU, du, &sizeDU);
    DifferentiatePolynomial(v, sizeV, dv, &sizeDV);
    
    printf("u'(x): ");
    for (int i = 0; i < sizeDU; i++) {
        printf("%.1fx^%d", du[i].coefficient, du[i].power);
        if (i < sizeDU - 1) printf(" + ");
    }
    printf("\n");

    printf("v'(x): ");
    for (int i = 0; i < sizeDV; i++) {
        printf("%.1fx^%d", dv[i].coefficient, dv[i].power);
        if (i < sizeDV - 1) printf(" + ");
    }
    printf("\n");

    // Calculate u'(x)v(x) and u(x)v'(x)
    MultiplyPolynomials(du, sizeDU, v, sizeV, du_v, &sizeDUV);
    MultiplyPolynomials(u, sizeU, dv, sizeDV, u_dv, &sizeUDV);

    printf("u'(x)v(x): ");
    for (int i = 0; i < sizeDUV; i++) {
        printf("%.1fx^%d", du_v[i].coefficient, du_v[i].power);
        if (i < sizeDUV - 1) printf(" + ");
    }
    printf("\n");

    printf("u(x)v'(x): ");
    for (int i = 0; i < sizeUDV; i++) {
        printf("%.1fx^%d", u_dv[i].coefficient, u_dv[i].power);
        if (i < sizeUDV - 1) printf(" + ");
    }
    printf("\n");

    // Subtract u(x)v'(x) from u'(x)v(x)
    numSize = 0;
    for (int i = 0; i < sizeDUV; i++) {
        numerator[numSize++] = du_v[i];
    }
    for (int i = 0; i < sizeUDV; i++) {
        // Subtract the second part from the numerator
        numerator[numSize].coefficient = -u_dv[i].coefficient;
        numerator[numSize].power = u_dv[i].power;
        numSize++;
    }

    // Combine like terms in the numerator
    CombineLikeTerms(numerator, &numSize);

    // Square the denominator v(x)
    MultiplyPolynomials(v, sizeV, v, sizeV, denominator, &denomSize);

    // Display the numerator and denominator
    printf("Numerator: ");
    for (int i = 0; i < numSize; i++) {
        if(numerator[i].coefficient != 0){
            printf("%.1fx^%d", numerator[i].coefficient, numerator[i].power);
        if (i < numSize - 1) printf(" + ");
        }
        else printf("0");
    }
    printf("\n");

    printf("Denominator: ");
    for (int i = 0; i < denomSize; i++) {
        printf("%.1fx^%d", denominator[i].coefficient, denominator[i].power);
        if (i < denomSize - 1) printf(" + ");
    }
    printf("\n");

    // Final expression: numerator / denominator
    printf("The derivative of the quotient is:\n");
    for (int i = 0; i < numSize; i++) {
        if(numerator[i].coefficient != 0){
            printf("%.1fx^%d", numerator[i].coefficient, numerator[i].power);
        if (i < numSize - 1) printf(" + ");
        } else printf("0");
        
    }
    printf(" / ");
    for (int i = 0; i < denomSize; i++) {
        printf("%.1fx^%d", denominator[i].coefficient, denominator[i].power);
        if (i < denomSize - 1) printf(" + ");
    }
    printf("\n");
}


