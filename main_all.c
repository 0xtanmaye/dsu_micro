#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT 1
#define FLOAT 2 
#define CHAR 3
#define LIMIT 200

#define lx

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

void *create_array(int format, int size)
{
	int ele_size;
	if(format==INT)
		ele_size=4;
	else if(format==FLOAT)
		ele_size=4;
	else if(format==CHAR)
		ele_size=1;

    void *ptr=calloc(size, ele_size);
    return ptr;
}

int read_array(int format, void *arrayptr, int size)
{
	int i;

	if(format==INT)
    {
        int *array=(int *)arrayptr;
		for(i=0;i<size;i++)
		{
			scanf("%d", &array[i]);
		}
    }
    else if(format==FLOAT)
    {
        float *array=(float *)arrayptr;
		for(i=0;i<size;i++)
		{
			scanf("%f", &array[i]);
		}
    }
    else if(format==CHAR)
    {
        char *array=(char *)array;
		for(i=0;i<size;i++)
		{
			scanf(" %c", &array[i]);
		}
    }
	return i;
}

int get_datatype()
{
    char datatype[6];
	do
	{
		printf("\nEnter the type of data you want to store(int or float or char):");
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
			printf("\nSetting array size=%d\n", size);
		else
			printf("\nSize beyond Limit(1-200), please enter a valid size!\n");
	} while(size>200 || size<1);

	return size;
}

int linear_search(int format, int size, void *arr_ptr, void *search_ele)
{
	int flag=0;
    if(format==INT)
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
    }
    else if(format==FLOAT)
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
    }
    else if(format==CHAR)
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
    }
	return flag;
}
int binary_search(int format, int size, void *arrayptr, void *search_ele)
{
    if(format==INT)
    {
        int *array=(int *)arr_ptr;
        int search=*((int *)search_ele);
		int mid, lowr, highr, flag=0;

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
		
		return flag;
    }
    else if(format==FLOAT)
    {
        float *array=(float *)arr_ptr;
        float search=*((float *)search_ele);
		int mid, lowr, highr, flag=0;

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

		return flag;
    }
    else if(format==CHAR)
    {
		char *array=(char *)arr_ptr;
        char search=*((char *)search_ele);
    	int mid, lowr, highr, flag=0;

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
			
		return flag;
	}
}
int main()
{

    int main_choice, sub_choice;
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n\n");
    printf("                                   Implement all types of Data Structures\n\n");
    printf("                                              Made by NEXUS\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n\n");
    printf("1] Searching Techniques\n");
    printf("2] Sorting Techniques\n");
    printf("3] Linear Data Structures\n");
    printf("4] Non-Linear Data Structures\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("Choice: ");
    scanf("%d",&main_choice);
	clear_screen();
    switch (main_choice)
    {
        case 1:
            printf("  Searching Techniques\n\n");
            printf("0: Linear Search Implementation\n");
            printf("1: Binary Search Implementation\n");
            printf("2: Return to main menu");
            printf("Choice: ");
            scanf("%d",&sub_choice);
            switch(sub_choice)
            {
                case 0:
                    int arr_datatype=get_datatype();
					int arr_size=get_size();
					void *arr_ptr=create_array(arr_datatype, arr_size);
					printf("Enter the %d elements:\n", arr_size);
					clean_stdin();
					int ele_read=read_array(arr_datatype, arr_ptr, arr_size);
					printf("\n%d Elements read\n", ele_read);
					printf("\nEnter the element you want to search:");
					if(arr_datatype==INT)
					{
						int search_ele;
						clean_stdin();
						scanf("%d", &search_ele);
						linear_search(arr_datatype, arr_size, arr_ptr, &search_ele);
					}
					else if(arr_datatype==FLOAT)
					{
						float search_ele;
						clean_stdin();
						scanf("%f", &search_ele);
						linear_search(arr_datatype, arr_size, arr_ptr, &search_ele);
					}
					else if(arr_datatype==CHAR)
					{
						char search_ele;
						clean_stdin();
						scanf("%c", &search_ele);
						linear_search(arr_datatype, arr_size, arr_ptr, &search_ele);
					}
					break;
				case 1:
					
            break;
        case 2:
            printf("  Sorting Techniques\n");
            printf("1: Bubble Sort\n");
            printf("2: Insertion Sort\n");
            printf("3: Selection Sort\n");
            printf("4: Radix Sort\n");
            printf("5: Quick Sort\n");
            break;
        case 3:
            printf("  Linear Data Structures\n");
            printf("1: Array\n");
            printf("2: Stack\n");
            printf("3: Queue\n");
            printf("4: Linked List\n");
            printf("5: Quick Sort\n");
            break;
        case 4:
            printf("  Non-Linear Data Structures\n");
            printf("1: Tree\n");
            printf("2: Graph\n");
            break;
    }
    return 0;
}