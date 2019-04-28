#include <stdio.h>
#include <stdlib.h>
 
 // alphabet letters
 char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ; 
 
 /**
 * encrypt given message to cipher text with given key by Rotation Cipher
 *
 * @param message char[]
 * @param cipher char[]
 * @param key int
 */
 void encryptWithRotationCipher(char message[100],char cipher[100], int key){
	int i ;
	for(i = 0; message[i] != '\0'; i++){
		char ch = message[i];
		
		// if lower case convert to upper case
		if(ch >= 'a' && ch <= 'z')
			ch = ch - 32 ;
		
		// encrypt letter chars only and write all remaining as is
		if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			cipher[i] = ch;
		} else {
			cipher[i] = ch;
		}
	}
	cipher[i] = '\0' ;
 }
 
 /**
 * decrypt given message to plain text with given key by Rotation Cipher
 *
 * @param cipher char[]
 * @param message char[]
 * @param key int
 */
 void decryptWithRotationCipherWithKey(char cipher[100],char message[100], int key){
 	int i ;
	for(i = 0; cipher[i] != '\0'; ++i){
		char ch = cipher[i];
		
		// if lower case convert to upper case
		if(ch >= 'a' && ch <= 'z')
			ch = ch - 32 ;
		
		// decrypt letter chars only and write all remaining as is	
		if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;
			
			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}
			message[i] = ch;
		} else {
			message[i] = ch;
		}
	}
	message[i] = '\0' ;
 }
 
 /**
 * decrypt given cipher with Rotation without key
 * decrypt by 26 different keys (it's all possible cases)
 *
 * @param cipher char[]
 * @param message char[]
 */
 void decryptWithRotationCipherWithoutKey(char cipher[100],char message[100]){
 	printf("all possible plains\n") ;
 	int i ;
 	for(i = 0 ; i < 26 ; i++){
 		decryptWithRotationCipherWithKey(cipher,message,i) ;
 		printf("key= %d,  plain text = %s\n", i, message) ;
	 }
 }
 
 /**
 * encrypt given message to cipher text with given key by Substitution Cipher
 *
 * @param message char[]
 * @param cipher char[]
 * @param key char[]
 */
 void encryptWithSubstitutionCipher(char message[100],char cipher[100], char key[26]){
	int i ;
	for(i = 0; message[i] != '\0'; i++){
		char ch = message[i];
		
		// if lower case convert to upper case
		if(ch >= 'a' && ch <= 'z')
			ch = ch - 32 ;
		
		// encrypt letter chars only and write all remaining as is
		if(ch >= 'A' && ch <= 'Z'){
			int j ;
			for(j = 0 ; j < 26 ; j++)
				if(ch == alpha[j]){
					cipher[i] = key[j] ;
				}
		} else {
			cipher[i] = ch ;
		}
	}
	cipher[i] = '\0' ;
 }
 
 /**
 * decrypt given message to plain text with given key by Substitution Cipher
 *
 * @param cipher char[]
 * @param cipher message[]
 * @param key char[]
 */
 void decryptWithSubstitutionCipherWithKey(char cipher[100],char message[100], char key[26]){
 	int i ;
	for(i = 0; cipher[i] != '\0'; i++){
		char ch = cipher[i];
		
		// if lower case convert to upper case
		if(ch >= 'a' && ch <= 'z')
			ch = ch - 32 ;
		
		// decrypt letter chars only and write all remaining as is	
		if(ch >= 'A' && ch <= 'Z'){
			int j ;
			for(j = 0 ; j < 26 ; j++)
				if(ch == key[j])
					message[i] = alpha[j] ;
		} else {
			message[i] = ch;
		}
	}
	message[i] = '\0' ;
 }
 
 /**
 * decrypt given cipher with Substitution without key
 * decrypt by 10 different keys (it should be 26! different keys to find plain)
 *
 * @param cipher char[]
 * @param message char[]
 */
 void decryptWithSubstitutionCipherWithoutKey(char cipher[100],char message[100]){
 	printf("10 possible plains\n") ;
 	char keys[10][26] = {
	 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	 ,"BCDEFGHIJKLMNOPQRSTUVWXYZA"
	 ,"CDEFGHIJKLMNOPQRSTUVWXYZAB"
	 ,"DEFGHIJKLMNOPQRSTUVWXYZABC"
	 ,"EFGHIJKLMNOPQRSTUVWXYZABCD"
	 ,"FGHIJKLMNOPQRSTUVWXYZABCDE"
	 ,"GHIJKLMNOPQRSTUVWXYZABCDEF"
	 ,"HIJKLMNOPQRSTUVWXYZABCDEFG"
	 ,"IJKLMNOPQRSTUVWXYZABCDEFGH"
	 ,"JKLMNOPQRSTUVWXYZABCDEFGHI"
	 } ;
 	int i ;
 	for(i = 0 ; i < 10 ; i++){
 		decryptWithSubstitutionCipherWithKey(cipher,message,keys[i]) ;
 		printf("key= %s,  plain text = %s\n", keys[i], message) ;
	 }
 }
 
 /**
 * print user friendly menu
 */
 void printMenu(){
 	printf("\n1. Encrypt By Rotation Cipher\n");	
 	printf("2. Encrypt By Substitution Cipher\n");
 	printf("3. Decrypt By Rotation Cipher with key\n");
 	printf("4. Decrypt By Substitution Cipher with key\n");
 	printf("5. Decrypt By Rotation Cipher without key\n");
 	printf("6. Decrypt By Substitution Cipher without key\n");
 	printf("7. Exit\n-> ");
 }
 
int main()
{
	
	int choice ; // variable to store user choice
	
	do{
		// print user friendly menu
		printMenu() ;
		scanf("%d", &choice);
		
		if(choice == 1){ // encrypt by rotation
			char message[100], cipher[100] ;
			int key ;
			printf("Enter a message to encrypt: ");
			scanf(" %[^\t\n]s",&message);
			printf("Enter key: ");
			scanf("%d", &key);
			encryptWithRotationCipher(message,cipher,key) ;
			printf("Cipher text is %s\n", cipher) ;
		} else if(choice == 2){ // encrypt by substitution
			char message[100], cipher[100] ;
			char key[26] ;
			printf("Enter a message to encrypt: ");
			scanf(" %[^\t\n]s", &message);
			printf("Enter key: ");
			scanf(" %[^\t\n]s", &key);
			encryptWithSubstitutionCipher(message,cipher,key) ;
			printf("Cipher text is %s\n", cipher) ;
		} else if(choice == 3){ // decrypt by rotation with key
			char message[100], plain[100] ;
			int key ;
			printf("Enter a message to decrypt: ");
			scanf(" %[^\t\n]s", &message);
			printf("Enter key: ");
			scanf("%d", &key);
			decryptWithRotationCipherWithKey(message,plain,key) ;
			printf("Plain text is %s\n", plain) ;
		} else if(choice == 4){ // decrypt by substitution with key
			char message[100], plain[100] ;
			char key[26] ;
			printf("Enter a message to decrypt: ");
			scanf(" %[^\t\n]s", &message);
			printf("Enter key: ");
			scanf(" %[^\t\n]s", &key);
			decryptWithSubstitutionCipherWithKey(message,plain,key) ;
			printf("Plain text is %s\n", plain) ;
		} else if(choice == 5){ // decrypt by rotation without key
			char message[100], plain[100] ;
			printf("Enter a message to decrypt: ");
			scanf(" %[^\t\n]s", &message);
			decryptWithRotationCipherWithoutKey(message,plain) ;
		} else if(choice == 6){ // decrypt by substitution without key
			char message[100], plain[100] ;
			printf("Enter a message to decrypt: ");
			scanf(" %[^\t\n]s", &message);
			decryptWithSubstitutionCipherWithoutKey(message,plain) ;
		} else if(choice == 7){
			// exit program
		} else {
			printf("Invalid choice. Try again\n");
		}
		
	} while(choice != 7) ;
	
	return 0;
}
