#include <stdio.h>

#define TAXI_CAPACITY 4
#define JEEPNEY_DISTANCE 4
#define BUS_DISTANCE 4
#define JEEPNEY_MIN_FARE 9.50
#define JEEPNEY_SUCCEEDING_FARE 0.75
#define INITIAL_VALUE 0
#define BUS_MIN_FARE 11.00
#define BUS_SUCCEEDING_FARE 0.50
#define TAXI_DISTANCE 8
#define TAXI_MIN_FARE 45.00
#define TAXI_SUCCEEDING_FARE 1.25

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
  int succeedingKm = distance - JEEPNEY_DISTANCE;

  if (succeedingKm < INITIAL_VALUE) {
    succeedingKm = INITIAL_VALUE;
  }

  double totalFare =
      (JEEPNEY_MIN_FARE + (succeedingKm * JEEPNEY_SUCCEEDING_FARE)) *
      numTravellers;
  return totalFare;
}

double calcBusFare(const int numTravellers, const int distance) {
  int succeedingKm = distance - BUS_DISTANCE;

  if (succeedingKm < INITIAL_VALUE) {
    succeedingKm = INITIAL_VALUE;
  }

  double totalFare =
      (BUS_MIN_FARE + (succeedingKm * BUS_SUCCEEDING_FARE)) * numTravellers;
  return totalFare;
}

double calcTaxiFare(const int numTravellers, const int distance) {
  int succeedingKm = distance - TAXI_DISTANCE;

  if (succeedingKm < INITIAL_VALUE) {
    succeedingKm = INITIAL_VALUE;
  }

  int numTaxis = numTravellers / TAXI_CAPACITY;

  if (numTravellers % TAXI_CAPACITY > INITIAL_VALUE) {
    numTaxis++;
  }

  double totalFare =
      (TAXI_MIN_FARE + (succeedingKm * TAXI_SUCCEEDING_FARE)) * numTaxis;
  return totalFare;
}

int main() {
  int numTravellers = getNumTravellers();
  int distance = getDistance();
  return 0;
}
