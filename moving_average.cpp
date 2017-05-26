// input file: anmol_text.txt
// output file: anmol_output.txt
#include<iostream>
#include<fstream>
#include<deque>
#include<string>

//calculating the moving_average based on buffer size

int moving_average(std::string input,std::string output,int buffer_size)
{
    float average = 0,a;
    std::deque<int> buffer;
    std::ifstream myfile;
    std::ofstream outfile;
    
    myfile.open(input);
    outfile.open(output);
    while(myfile.eof() == 0)
    {
        //std::cout<<1<<std::endl;
        average = 0;
        // Reading the element in the file line wise
        myfile>>a;
        // Building the buffer
        if(buffer.size()<buffer_size)
        {
            buffer.push_front(a);
        }
        else
        {
            buffer.pop_back();
            buffer.push_front(a);
        }
        
        // calculating moving average by averaging all elements in the buffer
        for(int i = 0; i<buffer.size();i++)
        {
            average = average + buffer[i];
        }
        average = average/buffer.size();
        std::cout<<"buffer size: "<<buffer.size()<<std::endl;
        std::cout<<average<<std::endl;
        outfile<<average<<"\n";
        
        
    }
    
    return 0;

    
}


int main()
{
  
  
  int buffer_size;
  std::cout<<"Enter buffer size: ";
  std::cin >> buffer_size;
  moving_average("anmol_text.txt","anmol_output.txt",buffer_size);
    
  return 0;

}