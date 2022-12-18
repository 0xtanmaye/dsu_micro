#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT 1
#define FLOAT 2 
#define CHAR 3
#define LIMIT 200
#define ASC 123
#define DESC 321
#define VERBOSE 1
#define NVERBOSE 0

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
				scanf(" %d", &array[i]);
			}
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arrayptr;
			for(i=0;i<size;i++)
			{
				scanf(" %f", &array[i]);
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)array;
			for(i=0;i<size;i++)
			{
				scanf(" %c", &array[i]);
			}
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
				scanf("%f\t", array[i]);
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)array;
			for(i=0;i<size;i++)
			{
				scanf("%c\t", array[i]);
			}
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

void bubble_sort(int format, int size, void *arr_ptr, int order, int verbose)
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
				for(i=size-1;i>0;i--)
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
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=size-1;i>0;i--)
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
			int i, j;
			float temp;
			if(order==ASC)
			{	
				for(i=size-1;i>0;i--)
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
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=size-1;i>0;i--)
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
			char temp;
			if(order==ASC)
			{	
				for(i=size-1;i>0;i--)
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
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=size-1;i>0;i--)
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
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
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
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
		}
	}
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

int binary_search(int format, int size, void *arr_ptr, void *search_ele)
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
	printf("\nEnter the element you want to search:");
	if(arr_datatype==INT)
	{
		int search_ele;
		clean_stdin();
		scanf("%d", &search_ele);
		binary_search(arr_datatype, arr_size, arr_ptr, &search_ele);
	}
	else if(arr_datatype==FLOAT)
	{
		float search_ele;
		clean_stdin();
		scanf("%f", &search_ele);
		binary_search(arr_datatype, arr_size, arr_ptr, &search_ele);
	}
	else if(arr_datatype==CHAR)
	{
		char search_ele;
		clean_stdin();
		scanf("%c", &search_ele);
		binary_search(arr_datatype, arr_size, arr_ptr, &search_ele);
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
			} while(sub_choice!=2);
			clear_screen();
			break;
        case 2:
			do
			{	
				clear_screen();
            	printf("  Sorting Techniques\n");
            	printf("1: Bubble Sort\n");
            	printf("2: Insertion Sort\n");
            	printf("3: Selection Sort\n");
            	printf("4: Radix Sort\n");
            	printf("5: Quick Sort\n");
				printf("6: Return to main menu\n\n");
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
			} while(sub_choice!=2);
			clear_screen();
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