#include <stdio.h>
#include <math.h>

#define EPSILON_0 8.85418782e-12 // Permittivity of free space 
#define PI 3.14159

double parallel_plate_capacitance(double area, double distance);
double cylindrical_capacitance(double length, double inner_radius, double outer_radius);
double spherical_capacitance(double inner_radius, double outer_radius);

int main() {
    int choice;
    double area, distance, length, inner_radius, outer_radius, capacitance;
    while(1){
    printf("\nCapacitor Capacitance Calculator\n");
    printf("================================\n");
    printf("1. Parallel Plate Capacitor\n");
    printf("2. Cylindrical Capacitor\n");
    printf("3. Spherical Capacitor\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: // Parallel Plate Capacitor
            printf("Enter plate area (in m^2): ");
            scanf("%lf", &area);
            printf("Enter plate separation (in m): ");
            scanf("%lf", &distance);

            if (distance <= 0) {
                printf("Error: Distance must be greater than zero.\n");
                return 1;
            }

            capacitance = parallel_plate_capacitance(area, distance);
            printf("Capacitance = %.4e F\n", capacitance);
            break;

        case 2: // Cylindrical Capacitor
            printf("Enter cylinder length (in m): ");
            scanf("%lf", &length);
            printf("Enter inner radius (in m): ");
            scanf("%lf", &inner_radius);
            printf("Enter outer radius (in m): ");
            scanf("%lf", &outer_radius);

            if (inner_radius <= 0 || outer_radius <= 0 || inner_radius >= outer_radius) {
                printf("Error: Invalid radii values.\n");
                return 1;
            }

            capacitance = cylindrical_capacitance(length, inner_radius, outer_radius);
            printf("Capacitance = %.4e F\n", capacitance);
            break;

        case 3: // Spherical Capacitor
            printf("Enter inner radius (in m): ");
            scanf("%lf", &inner_radius);
            printf("Enter outer radius (in m): ");
            scanf("%lf", &outer_radius);

            if (inner_radius <= 0 || outer_radius <= 0 || inner_radius >= outer_radius) {
                printf("Error: Invalid radii values.\n");
                return 1;
            }

            capacitance = spherical_capacitance(inner_radius, outer_radius);
            printf("Capacitance = %.4e F\n", capacitance);
            break;

        case 4:
            printf("Exiting...");
            return 0;    

        default:
            printf("Invalid choice! Please run the program again.\n");
            return 1;
    }
    }
    return 0;
}

// Parallel plate capacitor
double parallel_plate_capacitance(double area, double distance) {
    return (EPSILON_0 * area) / distance;
}

// Cylindrical capacitor
double cylindrical_capacitance(double length, double inner_radius, double outer_radius) {
    return (2 * PI * EPSILON_0 * length) / log(outer_radius / inner_radius);
}

// Spherical capacitor
double spherical_capacitance(double inner_radius, double outer_radius) {
    return (4 * PI * EPSILON_0 * inner_radius * outer_radius) / (outer_radius - inner_radius);
}

