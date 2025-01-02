#include<stdio.h>
#include<stdlib.h>
//module for integration
#include "int.c"
//module for differentiation
#include "diff.c"

int main(){
    printf("\n--- Advanced Calculator ---\n");
    while(1){
    printf("\nMenu\n");
    printf("1. Differentiation\n");
    printf("2. Integration\n");
    printf("3. Exit\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);
        switch(choice){
            case 1: // Differentiation
            int diffexit = 0, diffchoice;
            int sizeU, sizeV;
            DTerm *u = NULL, *v = NULL;
            printf("\n--- Differentiation ---\n");
            while(!diffexit){
                printf("\n1. Polynomial and Transcedental\n");
                printf("2. Product Rule\n");
                printf("3. Quotient Rule\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d",&diffchoice);
                switch(diffchoice){
                    case 1: // Polynomial
                    int numterms;
                    printf("Enter number of terms in the polynomial: ");
                    scanf("%d",&numterms);
                    DTerm *poly = (DTerm*)malloc(numterms * sizeof(DTerm));
                    if(poly == NULL){
                        printf("Memory allocation failed!\n");
                    }
                    char ch;
                    printf("Enter the terms of the polynomial (coefficient and power):\n");
                    for (int i = 0; i < numterms; i++) {
                    printf("Term %d:\n", i + 1);
                    printf("Expression (e.g. sin, cos, x, exp, ln): ");
                    scanf("%s",poly[i].func);
                    printf("Coefficient: ");
                    scanf("%lf", &poly[i].coefficient);
                    printf("Power (only 1 for sin, cos, exp, ln): ");
                    scanf("%d", &poly[i].power);
                    // printf("Is there any trig func? (y/n)");
                    // scanf(" %c",&ch);
                    // if(ch == 'y' || ch == 'Y'){
                    //     printf("Func: ");
                    //     scanf("%s",poly[i].func);
                    //    }
                    }
                    DiffPoly(poly, numterms);
                    free(poly);
                    break;
                    case 2: // Product Rule                    
                    printf("Enter the number of terms in the first polynomial (u(x)): ");
                    scanf("%d",&sizeU);
                    u = (DTerm*)malloc(sizeU * sizeof(DTerm));
                    if(u == NULL){
                        printf("Memory allocation failed!\n");
                        return 1;
                    }
                    printf("Enter the terms of u(x) (coefficient and power):\n");
                    for (int i = 0; i < sizeU; i++) {
                            printf("Term %d\n", i + 1);
                            printf("Coefficient: ");
                            scanf("%lf", &u[i].coefficient);
                            printf("Power: ");
                            scanf("%d", &u[i].power);
                        }
                    printf("Enter the number of terms in the second polynomial (v(x)): ");
                    scanf("%d", &sizeV);
                    v = (DTerm *)malloc(sizeV * sizeof(DTerm));
                    if (v == NULL) {
                        printf("Memory allocation failed!\n");
                        free(u);
                        return 1;
                    }
                    printf("Enter the terms of v(x) (coefficient and power):\n");
                    for (int i = 0; i < sizeV; i++) {
                        printf("Term %d\n", i + 1);
                        printf("Coefficient: ");
                        scanf("%lf", &v[i].coefficient);
                        printf("Power: ");
                        scanf("%d", &v[i].power);
                     }
                       ProductRule(u, sizeU, v, sizeV);
                    free(u);
                    free(v);
                    break;
                    case 3: // Quotient Rule                  
                    printf("Enter the number of terms in the first polynomial (u(x)): ");
                    scanf("%d", &sizeU);
                    u = (DTerm*)malloc(sizeU * sizeof(DTerm));
                    if(u == NULL){
                        printf("Memory allocation failed!\n");
                        return 1;
                    }
                    printf("Enter the terms of u(x) (coefficient and power):\n");
                    for (int i = 0; i < sizeU; i++) {
                        printf("Term %d\n", i + 1);
                         printf("Coefficient: ");
                        scanf("%lf", &u[i].coefficient);
                        printf("Power: ");
                        scanf("%d", &u[i].power);
                    }

                    printf("Enter the number of terms in the second polynomial (v(x)): ");
                    scanf("%d", &sizeV);
                    v = (DTerm *)malloc(sizeV * sizeof(DTerm));
                    if (v == NULL) {
                        printf("Memory allocation failed!\n");
                        free(u);
                        return 1;
                    }
                    printf("Enter the terms of v(x) (coefficient and power):\n");
                    for (int i = 0; i < sizeV; i++) {
                        printf("Term %d\n", i + 1);
                        printf("Coefficient: ");
                        scanf("%lf", &v[i].coefficient);
                        printf("Power: ");
                        scanf("%d", &v[i].power);
                     }

                    // Apply the quotient rule
                    QuotientRule(u, sizeU, v, sizeV);
                    free(u);
                    free(v);
                    break;
                    case 4:
                    printf("Exiting Differentiation Menu\n");
                    diffexit = 1;
                    break;
                    default:
                    printf("Invalid choice!");
                    break;
                } 
            }
            break;
            case 2: // Integration
            int intchoice, intexit = 0;
            printf("\n--- Integration ---\n");
            while(!intexit){
                printf("\n1. Definite Integral\n");
                printf("2. Indefinite Integral\n");
                printf("3. Exit\n");
                printf("Enter your choice: ");
                scanf("%d",&intchoice);
                switch(intchoice){
                    case 1: // Definite Integrals
                    printf("\n--- Definite Integrals ---\n");
                    int defchoice, defexit =0;
                    while(!defexit){
                        printf("\n1. Polynomial\n");
                        printf("2. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d",&defchoice);
                        switch(defchoice){
                            case 1:
                            int numTerms;
                            printf("Enter the number of terms in the polynomial: ");
                            scanf("%d",&numTerms);
                            Term *poly = (Term*)malloc(numTerms * sizeof(Term));
                            if (poly == NULL) {
                                printf("Memory allocation failed!\n");
                                return 1;
                               }
                            printf("Enter the terms of the polynomial (coefficient and power):\n");
                            for (int i = 0; i < numTerms; i++) {
                                printf("Term %d\n", i + 1);
                                printf("Coefficient: ");
                                scanf("%lf", &poly[i].coefficient);
                                printf("Power: ");
                                scanf("%d", &poly[i].power);
                            }
                            double a, b;
                            printf("Enter the lower limit (a): ");
                            scanf("%lf", &a);
                            printf("Enter the upper limit (b): ");
                            scanf("%lf", &b);
                            double result = DefIntegratePoly(poly, numTerms, a, b);
                            if (result == 0) {
                                printf("Integration could not be performed due to the special case of x^-1 at x = 0.\n");
                            } else {
                           // Printing the result of the definite integral
                            printf("The definite integral of the polynomial from %.2f to %.2f is: %.2f\n", a, b, result);
                            }
                            free(poly);
                            break;
                            case 2:
                            printf("Exiting definite Integral Menu.\n");
                            defexit = 1;
                            break;
                            default:
                            printf("Invalid choice!");
                            break;
                        }
                    }
                    break;
                    case 2: // Indefinite Integrals
                    printf("\n--- Indefinite Integrals ---\n");
                    int indchoice;
                    int indexit = 0;
                    while(!indexit){
                        printf("\n1. Polynomial\n");
                        printf("2. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d",&indchoice);
                        switch(indchoice){
                            case 1:
                            int numTerms;
                            printf("Enter the number of terms in the polynomial: ");
                            scanf("%d",&numTerms);
                            Term *poly = (Term*)malloc(numTerms * sizeof(Term));
                            if(poly == NULL){
                                printf("Memory Allocation failed!");
                                return 1;
                            }
                            printf("Enter the terms of polynomial (coefficient and power):\n");
                            for(int i=0; i<numTerms; i++){
                                printf("Term %d\n", i+1);
                                printf("Expression (e.g. sin, cos, x, exp, ln): ");
                                scanf("%s",poly[i].fucn);
                                printf("Coefficient: ");
                                scanf("%lf",&poly[i].coefficient);
                                printf("Power (only 1 for sin, cos, exp, ln): ");
                                scanf("%d",&poly[i].power);                    
                            }
                            IntegratePolynomial(poly, numTerms);
                                free(poly);
                            break;
                            case 2:
                            printf("Exiting Indefinite Integral Menu.\n");
                            indexit = 1;
                            break;
                            default:
                            printf("Invalid choice!");
                            break;

                        }
                    }
                    break;
                    case 3:
                    printf("Exiting Integral Menu.\n");
                    intexit = 1;
                    break;
                    default:
                    printf("Invalid choice!");
                    break;
                }
            }
            break;
            case 3:
            printf("Exiting Menu...Thank you for using!\n");
            return 0;
            break;
            default:
            printf("Invalid Choice!\n");
            break;
        }
    }

    return 0;
}