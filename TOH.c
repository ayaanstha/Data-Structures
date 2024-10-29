#include <stdio.h>
void toh(int n,char s,char t,char d){
    if (n == 1) {
        printf("Move %d disk from %c to %c\n",n,s,d);
        return;
    }
    else{

    toh(n-1,s,d,t);
    printf("Move %d disk from %c to %c\n", n,s,d);
    toh(n - 1,t,s,d);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    toh(n, 'a', 'c', 'b');
    return 0;
}
