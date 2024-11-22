#include <stdio.h>

int main(){
    int inputs[20];
    int count = 0;

for(int i = 0; i < 20; i++){
    printf("%d) ", i + 1);
    scanf("%d", &inputs[i]);
    if(inputs[i] < 0 || inputs[i] > 100){
        printf("Invalid...\n");
        i--;
        continue;
    } 
    if(i > 0 && inputs[i] < inputs[i-1]){
        printf("Invalid, please enter a larger number or equal to %d\n", inputs[i-1]);
        i--;
        continue;
    }
    count++;
    
    }
    double mean = 0.0;
    for(int i = 0; i < count; i++){
        mean += inputs[i];
    }
    mean /= count;

    double median;
    if (count % 2 == 0) {
        median = (inputs[count / 2 - 1] + inputs[count / 2]) / 2.0;
    } else {
        median = inputs[count / 2];
    }

    int mode = inputs[0];
    int maxCount = 1;
    for (int i = 0; i < count; i++) {
        int currentCount = 1;
        for (int j = i + 1; j < count; j++) {
            if (inputs[i] == inputs[j]) {
                currentCount++;
            }
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            mode = inputs[i];
        }
    }
    printf("\nResults:\n");
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: %d (occurs %d times)\n", mode, maxCount);
    return 0;
}
