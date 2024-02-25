#include <stdio.h>

void knapsack(int n, int weight[], int cost[], int capacity);

int main() {
   int weight[20], cost[20], capacity;
   int num, i;

   printf("--0/1 Knapsack-- \n");
   printf("\nEnter the no. of elements: ");
   scanf("%d", &num);

   printf("\nEnter the weights and costs of each element:\n");
   for (i = 0; i < num; i++) {
      scanf("%d %d", &weight[i], &cost[i]);
   }

   printf("\nEnter the capacity of knapsack: ");
   scanf("%d", &capacity);

   knapsack(num, weight, cost, capacity);
   return 0;
}

void knapsack(int n, int weight[], int cost[], int capacity) {
   int i, j;
   int dp[20][20];

   for (i = 0; i <= n; i++) {
      for (j = 0; j <= capacity; j++) {
         if (i == 0 || j == 0)
            dp[i][j] = 0;
         else if (weight[i - 1] <= j)
            dp[i][j] = (cost[i - 1] + dp[i - 1][j - weight[i - 1]]) > dp[i - 1][j]
                           ? (cost[i - 1] + dp[i - 1][j - weight[i - 1]])
                           : dp[i - 1][j];
         else
            dp[i][j] = dp[i - 1][j];
      }
   }

   printf("\nOptimal Solution (Maximum Cost): %d", dp[n][capacity]);

   // Finding the selected elements
   printf("\nSelected Elements: ");
   i = n;
   j = capacity;
   while (i > 0 && j > 0) {
      if (dp[i][j] != dp[i - 1][j]) {
         printf("%d ", i);
         j = j - weight[i - 1];
         i--;
      } else {
         i--;
      }
   }
}
