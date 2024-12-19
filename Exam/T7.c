//
// Created by colorcard on 24-12-19.
//

#include <stdio.h>

int main() {
    double distance;
    scanf("%lf", &distance);
    double Bike, Walk,All;

    Bike = distance / 3 + 50;
    Walk = distance / 1.2;

    if (Bike < Walk) {
        printf("Bike\n");
    } else if (Bike > Walk) {
        printf("Walk\n");
    } else {
        printf("All\n");
    }

    return 0;
}
