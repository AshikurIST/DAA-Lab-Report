#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity);

int main() {
   float weight[20], profit[20], capacity;
   int num, i, j;
   float perUnit[20], temp;

   printf("--Fractional knapsack-- \n");
   printf("\nEnter the no. of objects:- ");
   scanf("%d", &num);

   printf("\nEnter the weights and profits of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f %f", &weight[i], &profit[i]);
   }

   printf("\nEnter the capacity of knapsack:- ");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++) {
      perUnit[i] = profit[i] / weight[i];
   }

   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (perUnit[i] < perUnit[j]) {
            // Swap perUnit
            temp = perUnit[j];
            perUnit[j] = perUnit[i];
            perUnit[i] = temp;

            // Swap weight
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            // Swap profit
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }

   knapsack(num, weight, profit, capacity);
   return 0;
}

void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], tp = 0;
   int i, j, u;
   u = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }

   if (i < n){
      x[i] = u / weight[i];
      tp = tp + (x[i] * profit[i]);
      printf("\nMaximum profit is: %f", tp);
   }
}
