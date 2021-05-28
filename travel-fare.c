#include <stdio.h>

typedef enum { JEEPNEY = 1, BUS, TAXI, UBER } ModeTransport;

int getNumTravellers(void) {
  int numTravellers;

  printf("Enter Number of People: ");
  scanf("%d", &numTravellers);

  return numTravellers;
}

int getDistance(void) {
  int distance;

  printf("Enter Distance to Travel: ");
  scanf("%d", &distance);

  return distance;
}

int main() {
  int numTravellers = getNumTravellers();
  int distance = getDistance();
  return 0;
}
