#include <stdio.h>

#define TAXI_CAPACITY 4

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

double calcJeepneyFare(const int numTravellers, const int distance) {
  int succeedingKm = distance - 4;

  if (succeedingKm < 0) {
    succeedingKm = 0;
  }

  double totalFare = (9.50 + (succeedingKm * 0.75)) * numTravellers;
  return totalFare;
}

double calcBusFare(const int numTravellers, const int distance) {
  int succeedingKm = distance - 4;

  if (succeedingKm < 0) {
    succeedingKm = 0;
  }

  double totalFare = (11.00 + (succeedingKm * 0.50)) * numTravellers;
  return totalFare;
}

double calcTaxiFare(const int numTravellers, const int distance) {
  int succeedingKm = distance - 8;

  if (succeedingKm < 0) {
    succeedingKm = 0;
  }

  int numTaxis = numTravellers / TAXI_CAPACITY;

  if (numTravellers % TAXI_CAPACITY > 0) {
    numTaxis++;
  }

  double totalFare = (45.00 + (succeedingKm * 1.25)) * numTaxis;
  return totalFare;
}

int main() {
  int numTravellers = getNumTravellers();
  int distance = getDistance();
  return 0;
}
