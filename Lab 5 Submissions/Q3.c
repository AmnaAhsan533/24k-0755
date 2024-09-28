#include<stdio.h>
int main(){
	int key = 35;
	char original_char, encrypted_char, decrypted_char;
	
	printf("Enter a character to encrypt: ");
	scanf("%c",&original_char);
	
	encrypted_char = original_char^key;
	printf("Encrypted character: %d\n",encrypted_char);
	
	decrypted_char = encrypted_char^key;
	printf("Decrypted character: %c",decrypted_char);
	
	
	
	
	
	
	
	return 0;
}
