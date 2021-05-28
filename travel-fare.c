#include <math.h>
#include <stdio.h>

#define TAXI_CAPACITY 4
#define JEEPNEY_DISTANCE 4
#define BUS_DISTANCE 4
#define JEEPNEY_MIN_FARE 9.50
#define JEEPNEY_SUCCEEDING_FARE 0.75
#define BUS_MIN_FARE 11.00
#define BUS_SUCCEEDING_FARE 0.50
#define TAXI_DISTANCE 8
#define TAXI_MIN_FARE 45.00
#define TAXI_SUCCEEDING_FARE 1.25
#define UBER_DISTANCE 10
#define UBER_CAPACITY 4
#define UBER_MIN_FARE 43.00
#define UBER_SUCCEEDING_FARE 1.75

typedef enum { JEEPNEY = 1, BUS, TAXI, UBER } ModeTransport;

int getNumTravellers(void) {
  int numTravellers;

  printf("Number of People Travelling Together: ");
  scanf("%d", &numTravellers);

  return numTravellers;
}

int getDistance(void) {
  int distance;

  printf("Distance to Destination (km): ");
  scanf("%d", &distance);

  return distance;
}

double calcJeepneyFare(const int numTravellers, const int distance) {
  int succeedingKm = distance - JEEPNEY_DISTANCE;

  if (succeedingKm < 0) {
    succeedingKm = 0;
  }

  double totalFare =
      (JEEPNEY_MIN_FARE + (succeedingKm * JEEPNEY_SUCCEEDING_FARE)) *
      numTravellers;
  return totalFare;
}

double calcBusFare(const int numTravellers, const int distance) {
  int succeedingKm = distance - BUS_DISTANCE;

  if (succeedingKm < 0) {
    succeedingKm = 0;
  }

  double totalFare =
      (BUS_MIN_FARE + (succeedingKm * BUS_SUCCEEDING_FARE)) * numTravellers;
  return totalFare;
}

double calcTaxiFare(const int numTravellers, const int distance) {
  int succeedingKm = distance - TAXI_DISTANCE;

  if (succeedingKm < 0) {
    succeedingKm = 0;
  }

  int numTaxis = ceil((float)numTravellers / TAXI_CAPACITY);

  double totalFare =
      (TAXI_MIN_FARE + (succeedingKm * TAXI_SUCCEEDING_FARE)) * numTaxis;
  return totalFare;
}

double calcUberFare(const int numTravellers, const int distance) {
  int succeedingKm = distance - UBER_DISTANCE;

  if (succeedingKm < 0) {
    succeedingKm = 0;
  }

  int numUbers = ceil((float)numTravellers / UBER_CAPACITY);

  double totalFare =
      (UBER_MIN_FARE + (succeedingKm * UBER_SUCCEEDING_FARE)) * numUbers;
  return totalFare;
}

void calcCheapestModeTransport(double* fare,
                               ModeTransport* modeTransport,
                               const int numTravellers,
                               const int distance) {
  *fare = calcJeepneyFare(numTravellers, distance);
  *modeTransport = JEEPNEY;
  double busFare = calcBusFare(numTravellers, distance);

  if (busFare < *fare) {
    *fare = busFare;
    *modeTransport = BUS;
  }

  double taxiFare = calcTaxiFare(numTravellers, distance);

  if (taxiFare < *fare) {
    *fare = taxiFare;
    *modeTransport = TAXI;
  }

  double uberFare = calcUberFare(numTravellers, distance);

  if (uberFare < *fare) {
    *fare = uberFare;
    *modeTransport = UBER;
  }
}

void displayResults(const int numTravellers,
                    const int distance,
                    const ModeTransport modeTransport,
                    const double fare) {
  printf("The cheapest transport option for %d people travelling %d km is by ",
         numTravellers, distance);
  switch (modeTransport) {
    case JEEPNEY:
      puts("JEEP");
      break;
    case BUS:
      puts("BUS");
      break;
    case TAXI:
      puts("TAXI");
      break;
    case UBER:
      puts("UBER");
      break;
  }

  printf("\nThe Total Fare is %.2lf\n", fare);
  printf("Each will pay %.2lf\n", fare / numTravellers);
}

int main() {
  int numTravellers = getNumTravellers();
  int distance = getDistance();
  double fare;
  ModeTransport modeTransport;
  calcCheapestModeTransport(&fare, &modeTransport, numTravellers, distance);
  displayResults(numTravellers, distance, modeTransport, fare);

  return 0;
}
