#include<stdio.h>
#include<math.h>

typedef struct{
    float x;
    float y;
} Point;

float CalDistance(Point p1, Point p2);
void isInRectange(Point p, float x_min, float y_min, float x_max, float y_max);

int main(){
    Point p1, p2, p;
    float x_min = 0.0, x_max = 8.0, y_min = 0.0, y_max = 5.0;
    printf("Enter two points to calculate distance\n");
    printf("Point 1\nx-coordinate: ");
    scanf("%f", &p1.x);
    printf("y-coordinate: ");
    scanf("%f", &p1.y);
    printf("\nPoint 2");
    printf("\nx-coordinate: ");
    scanf("%f", &p2.x);
    printf("y-coordinate: ");
    scanf("%f", &p2.y);

    printf("Distance between two points is: %.2f\n", CalDistance(p1, p2));
    printf("Enter a point (x, y) to check whether it lies inside rectangle or not\n");
    scanf("%f %f", &p.x, &p.y);
    isInRectange(p, x_min, y_min, x_max, y_max);

    return 0;
}
float CalDistance(Point p1, Point p2){
    float d;
    d = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
    return d;
}
void isInRectange(Point p, float x_min, float y_min, float x_max, float y_max){
    if(p.x >= x_min && p.x <= x_max && p.y >= y_min && p.y <= y_max){
        printf("The given point (%.1f, %.1f) lies inside the rectangle.\n", p.x, p.y);
    } else {
        printf("The given point (%.1f, %.1f) does not lie inside the rectangle.\n", p.x, p.y);
    }
}
