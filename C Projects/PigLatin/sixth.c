#include<stdio.h>
#include<stdlib.h>
#include<string.h> 



int main(int argc, char * argv[]){
	int size = 0;
	

	

	char ** result = (char **)malloc((argc-1)*sizeof(char*));

	int count = 1;
	int curr_index = 0;
	
	while(count < argc){
		// check if first character is vowel or constant
		if(*argv[count] == 'a' || *argv[count] == 'e' || *argv[count] == 'i' || *argv[count] == 'o' || *argv[count] == 'u' || *argv[count] == 'A' || *argv[count] == 'E' || *argv[count] == 'I' || *argv[count] == 'O' || *argv[count] == 'U'){	
			// TODO call method that appends to result and adds 'yay' to the end
			// 1) Get the length of this string
			size = strlen(argv[count]);

			// 2) Allocate character array of size: size+1+3 ... 3 is for "yay"

			result[curr_index] = (char*)malloc((size+1+3)*sizeof(char));
			int i = 0;
			int total_size = size+1+3;
			for(i=0; i<total_size; ++i){
				if(i == (total_size-1)){
					result[curr_index][i] = '\0';
					continue;
				}
				if(i == size){
					result[curr_index][i] = 'y';
					result[curr_index][i+1] = 'a';
					result[curr_index][i+2] = 'y';
					i = i + 2;
					continue;
				}
				result[curr_index][i] = argv[count][i];

		
			}

			
			count++;
			curr_index ++;


		}

		// for more complex words ex: problem --> oblempray
		else{

			int size_of_original = strlen(argv[count]);
			int size_of_new_array = size_of_original + 2 + 1;
			int index_of_first_vowel = 0;
			int i;
			for(i=0; i<size_of_original; ++i){
				if(argv[count][i] == 'a' || argv[count][i] == 'e' || argv[count][i] == 'i' || argv[count][i] == 'o' || argv[count][i] == 'u' || argv[count][i] == 'A' || argv[count][i] == 'E' || argv[count][i] == 'I' || argv[count][i] == 'O' || argv[count][i] == 'U'){
					index_of_first_vowel = i;
					break;
				}
				else{
					continue;
				}
			}

		

			// allocate memory for new array
			result[curr_index] = (char *)malloc(size_of_new_array*sizeof(char));

			// start pasting starting from index_of_first_vowel
			int index_ptr_old_array = index_of_first_vowel;
			int index_new_array;
			int copy_counter = 0;
			if(index_of_first_vowel == 0){
				while(copy_counter < (size_of_new_array-3)){
					result[curr_index][copy_counter] = argv[count][copy_counter];
					copy_counter++;
				}
				result[curr_index][copy_counter] = 'a';
				copy_counter++;
				result[curr_index][copy_counter] = 'y';
				copy_counter++;
				result[curr_index][copy_counter] = '\0';
				count ++;
				curr_index ++;

				continue;
			}
			for(index_new_array=0; i<size_of_new_array; ++index_new_array){
				if(index_ptr_old_array == size_of_original){
					i = 0;
					
					while(i < index_of_first_vowel){
						result[curr_index][index_new_array] = argv[count][i];
						index_new_array++;
						i++;
					}
					result[curr_index][index_new_array] = 'a';
					index_new_array++;
					result[curr_index][index_new_array] = 'y';
					index_new_array++;
					result[curr_index][index_new_array] = '\0';
					
					

					break;

				}

				// just copy value of index_ptr_old_array into result[curr_index][index_new_array]
				else{

					result[curr_index][index_new_array] = argv[count][index_ptr_old_array];
					index_ptr_old_array ++;
				}
			}
			count ++;
			curr_index ++;
		}
	}

	int counter = 0;
	while(counter < (argc-1)){
		printf("%s", result[counter]);
		counter ++;
		if(counter != (argc-1)){
			printf(" ");
		}
	}
	printf("\n");

	return 0;


	int i = 0;

	while(i < ((int)strlen(argv[2])+1)){
		if(argv[2][i] == '\0'){
			printf("We hit it\n");
			return 0;
		}
		printf("character: %c\n", argv[2][i]);
		++i;
	}
	
}
