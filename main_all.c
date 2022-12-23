#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lx

#define INT 1
#define FLOAT 2 
#define CHAR 3
#define LIMIT 200
#define ASC 123
#define DESC 321
#define VERBOSE 1
#define NVERBOSE 0
#define BUBBLE 100
#define SELECTION 101
#define INSERTION 102

void clean_stdin(void)
{
    int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void clear_screen()
{
    #ifdef lx
	system("clear");
    #else
	system("cls");
    #endif
}

void pause_screen()
{
	clean_stdin();
	printf("\nPress enter to continue\n");
	getchar();
}

void *create_array(int format, int size)
{
	int ele_size;
	switch(format)
	{
		case INT:
			ele_size=4;
			break;
		case FLOAT:
			ele_size=4;
			break;
		case CHAR:
			ele_size=1;
			break;
	}
    void *ptr=calloc(size, ele_size);
    return ptr;
}

int read_array(int format, void *arrayptr, int size)
{
	int i;
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arrayptr;
			for(i=0;i<size;i++)
			{
				scanf("%d", &array[i]);
			}
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arrayptr;
			for(i=0;i<size;i++)
			{
				scanf("%f", &array[i]);
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)arrayptr;
			for(i=0;i<size;i++)
			{
				scanf(" %c", &array[i]);
			}
			break;
		}
	}
	return i;
}

int display_array(int format, void *arrayptr, int size)
{
	int i;
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arrayptr;
			for(i=0;i<size;i++)
			{
				printf("%d\t", array[i]);
			}
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arrayptr;
			for(i=0;i<size;i++)
			{
				printf("%f\t", array[i]);
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)arrayptr;
			for(i=0;i<size;i++)
			{
				printf("%c\t", array[i]);
			}
			break;
		}
	}
	return i;
}

int get_datatype()
{
    char datatype[6];
	do
	{
		printf("Enter the type of data you want to store(int or float or char):");
    	scanf(" %s", datatype);
    	if(strcmp(datatype, "int")==0)
			return INT;
    	else if(strcmp(datatype, "float")==0)
			return FLOAT;
		else if(strcmp(datatype, "char")==0)
			return CHAR;
		else 
			printf("Enter a valid datatype!\n");
	} while(1);
}

int get_size()
{
	int size;
	do
	{
		printf("Enter array size(valid size:1-200):");
		scanf("%d", &size);
		if(size<=LIMIT && size>0)
			printf("\nSetting array size=%d", size);
		else
			printf("\nSize beyond Limit(1-200), please enter a valid size!\n");
	} while(size>200 || size<1);

	return size;
}

int get_order()
{
	char ch;
	do
	{
		printf("Enter Order for Sort(a - Ascending Order/d - Descending Order)? ");
		scanf(" %c", &ch);
		if(ch=='a' || ch=='A')
		{
			printf("Selected Ascending Order");
			return ASC;
		}
		else if(ch=='d' || ch=='D')
		{
			printf("Selected Descending Order");
			return DESC;
		}
		else
		{
			printf("Please a enter valid choice(A/D)!\n");
		}
	} while(ch!='a' || ch!='A' || ch!='d' || ch!='D');
}

int get_verbose()
{
	char ch;
	do
	{
		printf("Do you want to see the output after every iteration(y/n)? ");
		scanf(" %c", &ch);
		if(ch=='y')
		{
			printf("Verbose ON");
			return VERBOSE;
		}
		else if(ch=='n')
		{
			printf("Verbose OFF");
			return NVERBOSE;
		}
		else
		{
			printf("Please a enter valid choice(y/n)!\n");
		}
	} while (ch!='y' || ch!='n');		
}

int push(int format, void *stack_ptr, int *top_ptr, void *val)
{
	switch(format)
	{
		case INT:
		{
			int *stack=(int *)stack_ptr;
			int val=*((int *)val);
		}
		case FLOAT:
		{
			float *stack=(float *)stack_ptr;
			float val=*((float *)val);
		}
		case CHAR:
		{
			char *stack=(char *)stack_ptr;
		 	char val=*((char *)val);
		}
	}
		

	if(top==SIZE-1)
	{
		return;
	}
	else
	{
		top++;
		stack[top]=val;
		return stack[top];
	}
}

int pop(int format, void *stack_ptr, int *top_ptr, void *val)
{
	switch(format)
	{
		case INT:
		{
			int *stack=(int *)stack_ptr;
			int val=*((int *)val);
		}
		case FLOAT:
		{
			float *stack=(float *)stack_ptr;
			float val=*((float *)val);
		}
		case CHAR:
		{
			char *stack=(char *)stack_ptr;
		 	char val=*((char *)val);
		}
	}
}

void bubble_sort(int format, int size, void *arr_ptr, int order, int verbose)
{
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arr_ptr;
			int i, j, k;
			int temp;
			if(order==ASC)
			{	
				for(i=size-1,k=1;i>0;i--,k++)
				{
					for(j=0;j<i;j++)
					{
						if(array[j]>array[j+1])
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", k);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=size-1,k=1;i>0;i--,k++)
				{
					for(j=0;j<i;j++)
					{
						if(array[j]<array[j+1])
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", k);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arr_ptr;
			int i, j, k;
			float temp;
			if(order==ASC)
			{	
				for(i=size-1,k=1;i>0;i--,k++)
				{
					for(j=0;j<i;j++)
					{
						if(array[j]>array[j+1])
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", k);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=size-1,k=1;i>0;i--,k++)
				{
					for(j=0;j<i;j++)
					{
						if(array[j]<array[j+1])
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", k);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)arr_ptr;
			int i, j, k;
			char temp;
			if(order==ASC)
			{	
				for(i=size-1, k=1;i>0;i--, k++)
				{
					for(j=0;j<i;j++)
					{
						if(array[j]>array[j+1])
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", k);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=size-1,k=1;i>0;i--,k++)
				{
					for(j=0;j<i;j++)
					{
						if(array[j]<array[j+1])
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", k);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
	}
}

void insertion_sort(int format, int size, void *arr_ptr, int order, int verbose)
{
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arr_ptr;
			int i, j;
			int key;
			if(order==ASC)
			{
				for(i=1;i<size;i++)
				{
					key=array[i];
					j=i-1;
			
					while(j>=0 && array[j]>key)
					{
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=key;
					if(verbose)
					{
						printf("Iteration %d: ", i);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=1;i<size;i++)
				{
					key=array[i];
					j=i-1;
			
					while(j>=0 && array[j]<key)
					{
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=key;
					if(verbose)
					{
						printf("Iteration %d: ", i);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arr_ptr;
			int i,j;
			float key;
			if(order==ASC)
			{
				for(i=1;i<size;i++)
				{
					key=array[i];
					j=i-1;
			
					while(j>=0 && array[j]>key)
					{
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=key;
					if(verbose)
					{
						printf("Iteration %d: ", i);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=1;i<size;i++)
				{
					key=array[i];
					j=i-1;
			
					while(j>=0 && array[j]<key)
					{
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=key;
					if(verbose)
					{
						printf("Iteration %d: ", i);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)arr_ptr;
			int i, j;
			char key;
			if(order==ASC)
			{
				for(i=1;i<size;i++)
				{
					key=array[i];
					j=i-1;
			
					while(j>=0 && array[j]>key)
					{
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=key;
					if(verbose)
					{
						printf("Iteration %d: ", i);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=1;i<size;i++)
				{
					key=array[i];
					j=i-1;
			
					while(j>=0 && array[j]<key)
					{
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=key;
					if(verbose)
					{
						printf("Iteration %d: ", i);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
	}
}

void selection_sort(int format, int size, void *arr_ptr, int order, int verbose)
{
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arr_ptr;
			int i, j;
			int temp;
			if(order==ASC)
			{
				for(i=0;i<size;i++)
				{
					for(j=i+1;j<size;j++)
					{
						if(array[i]>array[j])
						{
							temp=array[i];
							array[i]=array[j];
							array[j]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", i+1);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=0;i<size;i++)
				{
					for(j=i+1;j<size;j++)
					{
						if(array[i]<array[j])
						{
							temp=array[i];
							array[i]=array[j];
							array[j]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", i+1);
						display_array(format, array, size);
						printf("\n");
					}
					
				}
			}
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arr_ptr;
			int i,j;
			float temp;
			if(order==ASC)
			{
				for(i=0;i<size;i++)
				{
					for(j=i+1;j<size;j++)
					{
						if(array[i]>array[j])
						{
							temp=array[i];
							array[i]=array[j];
							array[j]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", i+1);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=0;i<size;i++)
				{
					for(j=i+1;j<size;j++)
					{
						if(array[i]<array[j])
						{
							temp=array[i];
							array[i]=array[j];
							array[j]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", i+1);
						display_array(format, array, size);
						printf("\n");
					}
					
				}
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)arr_ptr;
			int i,j;
			char temp;
			if(order==ASC)
			{
				for(i=0;i<size;i++)
				{
					for(j=i+1;j<size;j++)
					{
						if(array[i]>array[j])
						{
							temp=array[i];
							array[i]=array[j];
							array[j]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", i+1);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=0;i<size;i++)
				{
					for(j=i+1;j<size;j++)
					{
						if(array[i]<array[j])
						{
							temp=array[i];
							array[i]=array[j];
							array[j]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", i+1);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
	}
}

int linear_search(int format, int size, void *arr_ptr, void *search_ele)
{
	int flag=0;
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arr_ptr;
			int search=*((int *)search_ele);
			for(int i=0;i<size;i++)
			{
				if(array[i]==search)
				{
					printf("Element found at position %d\n", i+1);
					flag++;
				}
			}
			if(flag==0)
			{
				printf("Element not found\n");
			}
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arr_ptr;
			float search=*((float *)search_ele);
			for(int i=0;i<size;i++)
			{
				if(array[i]==search)
				{
					printf("Element found at position %d\n", i+1);
					flag++;
				}
			}
			if(flag==0)
			{
				printf("Element not found\n");
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)arr_ptr;
			char search=*((char *)search_ele);
			for(int i=0;i<size;i++)
			{
				if(array[i]==search)
				{
					printf("Element found at position %d\n", i+1);
					flag++;
				}
			}
			if(flag==0)
			{
				printf("Element not found\n");
			}
			break;
		}
	}
	return flag;
}

int binary_search(int format, int size, void *arr_ptr, void *search_ele)
{
	int flag=0;
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arr_ptr;
			int search=*((int *)search_ele);
			int mid, lowr, highr, flag=0;
			//sorting the array before binary search
			insertion_sort(format, size, array, ASC, NVERBOSE);

			lowr=0;
			highr=size-1;
			while(lowr<=highr)
			{
				mid=(lowr+highr)/2;
				if(search==array[mid])
				{
					printf("Element found at position %d\n", mid+1);
					flag++;
					break;
				}
				else if(search>array[mid])
				{
					lowr=mid+1;
				}
				else if(search<array[mid])
				{
					highr=mid-1;
				}
			}
			if(flag==0)
				printf("Element not found\n");
			
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arr_ptr;
			float search=*((float *)search_ele);
			int mid, lowr, highr, flag=0;
			//sorting the array before binary search
			insertion_sort(format, size, array, ASC, NVERBOSE);

			lowr=0;
			highr=size-1;
			while(lowr<=highr)
			{
				mid=(lowr+highr)/2;
				if(search==array[mid])
				{
					printf("Element found at position %d\n", mid+1);
					flag++;
					break;
				}
				else if(search>array[mid])
				{
					lowr=mid+1;
				}
				else if(search<array[mid])
				{
					highr=mid-1;
				}
			}
			if(flag==0)
				printf("Element not found\n");

			break;
		}
		case CHAR:
		{
			char *array=(char *)arr_ptr;
			char search=*((char *)search_ele);
			int mid, lowr, highr, flag=0;
			//sorting the array before binary search
			insertion_sort(format, size, array, ASC, NVERBOSE);

			lowr=0;
			highr=size-1;
			while(lowr<=highr)
			{
				mid=(lowr+highr)/2;
				if(search==array[mid])
				{
					printf("Element found at position %d\n", mid+1);
					flag++;
					break;
				}
				else if(search>array[mid])
				{
					lowr=mid+1;
				}
				else if(search<array[mid])
				{
					highr=mid-1;
				}
			}
			if(flag==0)
				printf("Element not found\n");
				
			break;
		}
	}
	return flag;
}

void create_and_LS()
{
	printf("Linear Search \n\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	int arr_datatype=get_datatype();
	int arr_size=get_size();
	void *arr_ptr=create_array(arr_datatype, arr_size);
	printf("\nEnter the %d elements:\n", arr_size);
	clean_stdin();
	int ele_read=read_array(arr_datatype, arr_ptr, arr_size);
	printf("\n%d Elements read\n\n", ele_read);
	display_array(arr_datatype, arr_ptr, arr_size);
	printf("\n\nEnter the element you want to search:");
	switch(arr_datatype)
	{
		case INT:
		{
			int search_ele;
			clean_stdin();
			scanf("%d", &search_ele);
			linear_search(arr_datatype, arr_size, arr_ptr, &search_ele);
			break;
		}
		case FLOAT:
		{
			float search_ele;
			clean_stdin();
			scanf("%f", &search_ele);
			linear_search(arr_datatype, arr_size, arr_ptr, &search_ele);
			break;
		}
		case CHAR:
		{
			char search_ele;
			clean_stdin();
			scanf("%c", &search_ele);
			linear_search(arr_datatype, arr_size, arr_ptr, &search_ele);
			break;
		}
	}
}

void create_and_BS()
{
	printf("Binary Search \n\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	int arr_datatype=get_datatype();
	int arr_size=get_size();
	void *arr_ptr=create_array(arr_datatype, arr_size);
	printf("\nEnter the %d elements:\n", arr_size);
	clean_stdin();
	int ele_read=read_array(arr_datatype, arr_ptr, arr_size);
	printf("\n%d Elements read\n", ele_read);
	//sorting the array before binary search
	insertion_sort(arr_datatype, arr_size, arr_ptr, ASC, NVERBOSE);
	printf("\nArray Elements: (Note: The array elements are Sorted before Binary Search)\n");
	display_array(arr_datatype, arr_ptr, arr_size);
	printf("\n\nEnter the element you want to search:");
	switch(arr_datatype)
	{
		case INT:
		{
			int search_ele;
			clean_stdin();
			scanf("%d", &search_ele);
			binary_search(arr_datatype, arr_size, arr_ptr, &search_ele);
			break;
		}
		case FLOAT:
		{
			float search_ele;
			clean_stdin();
			scanf("%f", &search_ele);
			binary_search(arr_datatype, arr_size, arr_ptr, &search_ele);
			break;
		}
		case CHAR:
		{
			char search_ele;
			clean_stdin();
			scanf("%c", &search_ele);
			binary_search(arr_datatype, arr_size, arr_ptr, &search_ele);
			break;
		}
	}
}

void create_and_sort(int sortmethod)
{
	int arr_datatype=get_datatype();
	int arr_size=get_size();
	void *arr_ptr=create_array(arr_datatype, arr_size);
	printf("\nEnter the %d elements:\n", arr_size);
	clean_stdin();
	int ele_read=read_array(arr_datatype, arr_ptr, arr_size);
	printf("\n%d Elements read\n\n", ele_read);
	display_array(arr_datatype, arr_ptr, arr_size);
	printf("\n\n");
	int order=get_order();
	printf("\n");
	int verbose=get_verbose();
	printf("\n\n");
	switch(sortmethod)
	{
		case BUBBLE:
			bubble_sort(arr_datatype, arr_size, arr_ptr, order, verbose);
			printf("\nArray after Bubble Sort:\n");
			break;
		case SELECTION:
			selection_sort(arr_datatype, arr_size, arr_ptr, order, verbose);
			printf("\nArray after Selection Sort:\n");
			break;
		case INSERTION:
			insertion_sort(arr_datatype, arr_size, arr_ptr, order, verbose);
			printf("\nArray after Insertion Sort:\n");
			break;
	}
	display_array(arr_datatype, arr_ptr, arr_size);
	printf("\n");
}
int main()
{
	int main_choice, sub_choice;
	do
	{
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("-----------------------------------------------------------------------------------------------------------------\n\n");
		printf("                                   Implement all types of Data Structures\n\n");
		printf("                                              Made by NEXUS\n");
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("-----------------------------------------------------------------------------------------------------------------\n\n");
		printf("1] Searching Techniques\n");
		printf("2] Sorting Techniques\n");
		printf("3] Linear Data Structures\n");
		printf("4] Non-Linear Data Structures\n");
		printf("5] Exit\n\n");
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Choice: ");
		scanf("%d",&main_choice);
		clear_screen();
		switch (main_choice)
		{
			case 1:
				do
				{	
					clear_screen();
					printf("  Searching Techniques\n\n");
					printf("1: Linear Search Implementation\n");
					printf("2: Binary Search Implementation\n");
					printf("3: Return to main menu\n\n");
					printf("Choice: ");
					scanf("%d",&sub_choice);
					switch(sub_choice)
					{
						case 1:
							//Linear Search
							clear_screen();
							create_and_LS();
							pause_screen();
							break;
						case 2:
							//Binary Search
							clear_screen();
							create_and_BS();
							pause_screen();
							break;
						case 3:
							printf("\nReturning to Main Menu\n\n");
							break;
					}
				} while(sub_choice!=3);
				clear_screen();
				break;
			case 2:
				do
				{	
					clear_screen();
					printf("  Sorting Techniques\n");
					printf("1: Bubble Sort\n");
					printf("2: Selection Sort\n");
					printf("3: Insertion Sort\n");
					//printf("4: Radix Sort\n");
					//printf("5: Quick Sort\n");
					printf("4: Return to main menu\n\n");
					printf("Choice: ");
					scanf("%d",&sub_choice);
					switch(sub_choice)
					{
						case 1:
							//Bubble sort
							clear_screen();
							create_and_sort(BUBBLE);
							pause_screen();
							break;
						case 2:
							//Selection Search
							clear_screen();
							create_and_sort(SELECTION);
							pause_screen();
							break;
						case 3:
							//Insertion Search
							clear_screen();
							create_and_sort(INSERTION);
							pause_screen();
							break;
						case 4:
							printf("\nReturning to Main Menu\n\n");
							break;
					}
				} while(sub_choice!=4);
				clear_screen();
				break;
			case 3:
				printf("  Linear Data Structures\n");
				printf("1: Array\n");
				printf("2: Stack\n");
				printf("3: Queue\n");
				printf("4: Linked List\n");
				break;
			case 4:
				printf("  Non-Linear Data Structures\n");
				printf("1: Tree\n");
				printf("2: Graph\n");
				break;
			case 5:
				printf("  Exiting\n");
				break;
		}
	} while(main_choice!=5);
    return 0;
}