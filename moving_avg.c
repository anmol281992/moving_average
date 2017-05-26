// input file: anmol_text.txt
// output file: anmol_output2.txt
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    float Data;
    struct Node* Next;
    
};

struct Node* front = NULL;
struct Node* back = NULL;

// Adding elements to queue (buffer)
int enqueue(float Data)
{ 
   printf("adding to queue \n");
    
    if(front == NULL && back == NULL)
    {
        struct Node* loc = (struct Node*)malloc(sizeof(struct Node));
        loc -> Data = Data;
        loc -> Next = NULL;
        front = loc;
        back = loc; 
        
    } 
    else
    {
        struct Node* loc = (struct Node*)malloc(sizeof(struct Node));
        loc -> Data = Data;
        loc -> Next = NULL;
        front -> Next = loc;
        front = loc;
        
    }
    
    return 0;

}

// Removing elements from queue (buffer)

int dequeue()
{ 
    printf("deleting from queue \n");
    struct Node* temp;
    if(front == NULL)
    {
        printf("No element in queue");
    }
    else if(front == back)
    {
        temp = back;
        front = NULL;
        back = NULL;
        free(temp);
        
    }
    else
    {
        temp = back;
        back = back -> Next;
        free(temp);
        
     }
    return 0;
}

// Deallocation

int Deallocate()
{
    while(front == NULL && back == NULL)
    {
        dequeue();
    }
    return 0;
}

// calculating average of elements in the buffer
float average()
{
    int size = 0;
    float average = 0;
    struct Node* point;
    point = back; 
    while(point != NULL)
    {
        average = average + point -> Data;
        point = point -> Next;
        size = size +1;
    }
    average = average/size;
    return average;
    
}


// printing the queue : this I used for testing my functions
int print_queue()
{
    
    struct Node* point;
    point = back; 
    while(point != NULL)
    {
        printf("%f ",point -> Data);
        point = point -> Next;
    }
    printf("\n");
    
    return 0;
    
}

// calculate the moving average by reading numbers line wise from a file

int moving_average(const char input[],const char output[], int buffer_size)
{
int size = 0;
float data;
FILE *read_fp = fopen(input,"r");
FILE *output_fp = fopen(output,"w");
if(read_fp == NULL)
{
    printf("No data in file");
}
while(!feof(read_fp))
{
    fscanf(read_fp,"%f",&data);

    // While we read numbers from the file it adds elements to the buffer. The size of buffer is delimited by  buffer_size
    if(size < buffer_size)
    {
        enqueue(data);
        size = size+1;
        
    }
    else
    {
        dequeue();
        enqueue(data);

    }
    printf("size: %d \n", size);
    printf("queue: ");
    print_queue();
    if(front == NULL && back == NULL)
    {
        printf("No data in queue");
    }
    else if(front == back )
    {
        fprintf(output_fp,"%f \n",front -> Data);
    }
    else
    {   data = average(); // calculating average of elements in a buffer
        printf("average: %f \n ", data);
        fprintf(output_fp,"%f \n",data);
    }
    
    
}


Deallocate();
fclose(read_fp);
fclose(output_fp);
return 0;
}

int main()
{
    int buff_size;
    printf("Enter the buffer size: ");
    scanf("%d", &buff_size);
    const char input[] = "anmol_text.txt";
    const char output[] = "anmol_output2.txt" ;
    moving_average(input,output,buff_size);
    return 0;
}
