#include <iostream>
#include <cmath>

using namespace std;

int main()
{

        void  calculateSdeviation(double anarr[], int quantity); //Function declaration
          int countt;
         cout<<" Calculating Standard Deviation when given a number of values \n Take note that the formula for calculating standard deviation is the square root of the variance \n \n Enter the number(quantity) of values you wish to calculate,eg:5 \n";
         cin>>countt;
         cout<<endl;
         double myarray[countt];
         cout<<" Enter the integer values \n";
         for( int i=0;i<countt;i++)
           cin>>myarray[i];
         cout<<" The values you entered are "<<endl;
         for( int i=0;i<countt;i++)
            cout<<myarray[i]<<" ";
            cout<<endl;
        calculateSdeviation(myarray,countt); //Function call



return 0;
}
     //Function definition
  void calculateSdeviation(double anarr[], int quantity)
     {
           int i;
           double sum=0;
           double sumdeviation=0;
           //Arrays declaration to hold the deviations from the mean and the squared deviations
           double deviation[quantity];
           double sqrdeviation[quantity];
           //For loop to calculate the sum of the given values and divide by the quantity
         for( i=0;i<quantity;i++)
            sum+=anarr[i];
         double mean=sum/quantity;
         cout<<" The mean of the numbers you inputed is "<<mean<<endl;

         cout<<" The deviations from the mean are "<<endl;
         //For loop to square the deviations and find the sum of the squared deviations.
         for( i=0;i<quantity;i++){
            deviation[i]= anarr[i]- mean;
            cout<<deviation[i]<<" ";
            sqrdeviation[i]= deviation[i]*deviation[i];
            sumdeviation+=sqrdeviation[i];
         }
         cout<<endl;
         double variance = sumdeviation/quantity;
         cout<<" The standard deviation is "<< sqrt(variance);
}

 /* double sum =0, myarray[5], deviation[5], count = sizeof(myarray)/sizeof(myarray[0]),sqrdeviation[5];
    int i;
  cout<<"Please input five integers \n";
       for(i=0;i<5;i++)
        cin>>myarray[i];
     cout<<"The numbers you inputed are "<<endl;
          for(i=0;i<5;i++)
        cout<<myarray[i]<<" ";
         for(i=0;i<5;i++)
        sum+=myarray[i];
        double mean= sum/count;
        cout<<endl;
        cout<<"The sum of the numbers are "<<sum<<endl;
        cout<<"The mean of the numbers is "<<mean<<endl;
            for(i=0;i<5;i++)
           deviation[i]=myarray[i]-mean;
           cout<<"The deviations from the mean are "<<endl;
           for(i=0;i<5;i++)
            cout<<deviation[i]<<" ";
            for(i=0;i<5;i++)
            sqrdeviation[i]= deviation[i]*deviation[i];
            cout<<endl;
            cout<<"The squared of the deviations are "<<endl;
            for(i=0;i<5;i++)
                cout<<sqrdeviation[i]<<" ";
            cout<<"\n";
        int sumdeviation=0;
        for(i=0;i<5;i++)
        sumdeviation+=sqrdeviation[i];
        cout<<"The sum of deviations are "<<sumdeviation<<endl;
        cout<<"The variance is "<<sumdeviation/count<<" therefore the standard deviation is "<<sqrt(sumdeviation/count)<<endl;
*/

