#include<stdio.h>
#include<string.h>

int BinaryToDecimal(int number);
int DecimalToBinary(int number); 
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char hexNum[]);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(char hexNum[]);

int main(){
    int choice, number;
    char hexNum[20];

    do {
        printf("\n--- Conversion Menu ---\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                printf("Decimal equivalent: %d\n", BinaryToDecimal(number));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Binary equivalent: %d\n", DecimalToBinary(number));
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Hexadecimal equivalent: ");
                DecimalToHexadecimal(number);
                break;
            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNum);
                printf("Decimal equivalent: ");
                HexadecimalToDecimal(hexNum);
                break;
            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                printf("Hexadecimal equivalent: ");
                BinaryToHexadecimal(number);
                break;
            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNum);
                printf("Binary equivalent: ");
                HexadecimalToBinary(hexNum);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

int BinaryToDecimal(int number){
    int base=1, decimal=0, rem;
    while(number>0){
    rem = number % 10;
    decimal += rem*base;
    base *= 2;
    number /= 10;
    }
    return decimal;
}
int DecimalToBinary(int number){
    int base=1, binary=0;
    if (number < 0) {
        printf("Negative numbers cannot be converted to binary.\n");
        return -1; // Indicate an error
    }
    while(number>0){
        binary += (number%2)*base;
        number /= 2;
        base *=10;
    }
    return binary;
} 
void DecimalToHexadecimal(int number){
    char hex[20];
    int i=0;
    if(number==0){
        printf("0\n");
        return;
    }
    while(number != 0){
        int rem = number % 16;
        hex[i++]= (rem<10)? (rem+'0') : (rem - 10 +'A');
        number /= 16;
    }
    for(int j=i-1; j>=0; j--){
        printf("%c",hex[j]);
    }
    printf("\n");

}

void HexadecimalToDecimal(char hexNum[]){
    int decimal = 0, base=1;
    int len = strlen(hexNum);
    for(int i=len-1; i>=0; i--){
        if(hexNum[i]>='0' && hexNum[i]<='9'){
            decimal += (hexNum[i]-0) * base;
        }
        else if(hexNum[i]>= 'A' && hexNum[i]<= 'F'){
            decimal += (hexNum[i]-'A'+10) * base;
        }
        else if(hexNum[i]>='a' && hexNum[i]<='f'){
            decimal += (hexNum[i]-'a'+10) * base;
        }
        else {
            printf("Invalid Input\n");
            return;
        }
        base *= 16;
    }
    printf("%d\n",decimal);
}
void BinaryToHexadecimal(int number){
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
    return;
}

void HexadecimalToBinary(char hexNum[]){
    int decimal = 0, base=1;
    int len = strlen(hexNum);
    for(int i=len-1; i>=0; i--){
        if(hexNum[i]>=0 && hexNum[i]<=9){
            decimal += (hexNum[i]-0) * base;
        }
        if(hexNum[i]>= 'A' && hexNum[i]<= 'F'){
            decimal += (hexNum[i]-'A'+10) * base;
        }
        if(hexNum[i]>='a' && hexNum[i]<='f'){
            decimal += (hexNum[i]-'a'+10) * base;
        }
        base *= 16;
    }
    printf("%d\n",DecimalToBinary(decimal));
}
