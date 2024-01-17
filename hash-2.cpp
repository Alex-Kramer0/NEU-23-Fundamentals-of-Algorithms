// Alex Kramer 
// Homework 3
// Problem 2 
// Hash Tables

#include <cstddef>
#include <iostream>
#include <random>
using namespace std;

size_t gen_date(mt19937 &mt) { // taking in the name of the random generator 

  // telling the random generator the range and the type of distribution we want 
  uniform_int_distribution<int> day_dist(1, 27); 
  uniform_int_distribution<int> month_dist(1, 12);
  uniform_int_distribution<int> year_dist(1, 4);   

  // calling the random generator
  int day = day_dist(mt);
  int month = month_dist(mt);
  int year = year_dist(mt);

  // format date
  return (month * 1000) + (day *100) + year; 

}

void zero(int a[], int const SIZE){
  // looping through the array and setting each element to zero 
  for (size_t i = 0; i < SIZE; i++){
      a[i]=0;
  }
}

void collision_count(int arr[], int dates[],int const SIZE) {
    // counts the collsions
	for (int i = 0; i < 1000; i++) {
		int index = dates[i] % SIZE;
		arr[index] += 1;
	}
}

int get_min(int arr[], int const SIZE){
  // get the minimum from in the array
  int min = 100000000;
  for (size_t i=0; i <SIZE; i++){
      if (arr[i] < min){
          min = arr[i];
      }
  }
  return min;
}

int get_max(int arr[], int const SIZE) {
  int max = 0;
  for (size_t i = 0; i < SIZE; i++) {
    if (arr[i] > max) { max = arr[i];}
  }
  return max;
}

void print_arr(int arr[], int const SIZE) {
  for (size_t i = 0; i < SIZE; i++) {
    cout << arr[i] << '\n';
  }
}

double get_mean(int arr[], int const SIZE){
  // adds all elemets up, and divides by size 
  int total = 0;

  for (size_t i=0; i < SIZE; i++){
      total += arr[i];
  }
  return total / static_cast<double>(SIZE); 
  // static cast converts the variables to a double when compiling
}

double get_var(int arr[], int const SIZE) {                  
  double ss = 0;                                             
  double mean = get_mean(arr, SIZE);             
  for (size_t i; i < SIZE; i++){                        
    ss += static_cast<double>(arr[i]-mean) * (arr[i] - mean);
  }                                                          
    return ss / SIZE;                                        
}    

int main(){
  // getting a seed for random generator
  random_device rd;  
  // initializing
  mt19937 mt(rd());
  // what distribution is the random num coming from 
  uniform_int_distribution<int> dist(0, 100); 

  // print dates 
  cout << gen_date(mt) << '\n';

  // create arrays & zeroing them out
  int arr1[97];
  zero(arr1,97);
  int arr2[98];
  zero(arr2,98);
  int arr3[100];
  zero(arr3,100);

  // randomly generate our 1000 dates
  int rand_dates[1000];
  for (size_t i = 0; i < 1000; i++){
      rand_dates[i] =gen_date(mt);
  }

  // filling up the array with the number of items that goes in each spot 
  collision_count(arr1, rand_dates, 97);
  collision_count(arr2, rand_dates, 98);
  collision_count(arr3, rand_dates, 100);

  // print the minimum for each array
  cout << "MIN\n";
  cout << "arr1 min: "<< get_min(arr1,97) << '\n';
  cout << "arr2 min: "<< get_min(arr2,98) << '\n';
  cout << "arr3 min: "<< get_min(arr3,100) << '\n';
  // we get the min of 0 for size 100, because we are moding by 100 in our hash function
  // so we get this really crazy bias when doing the hash, this is a bad hash function 

  cout << "Max\n";
  cout << "arr1 max: "<< get_max(arr1,97) << '\n';
  cout << "arr2 max: "<< get_max(arr2,98) << '\n';
  cout << "arr3 max: "<< get_max(arr3,100) << '\n';
  // first two similar, and the last one is massive because we are moding by 100 which is giving us
  // this crazy bias we saw when getting the min
  // think about how the table looks for this one when writing up the report

  
  cout << "Mean\n";
  cout << "arr1 Mean: "<< get_mean(arr1,97) << '\n';
  cout << "arr2 Mean: "<< get_mean(arr2,98) << '\n';
  cout << "arr3 Mean: "<< get_mean(arr3,100) << '\n';

  cout << "Var\n";
  cout << "arr1 var: "<< get_var(arr1,97) << '\n';
  cout << "arr2 var: "<< get_var(arr2,98) << '\n';
  cout << "arr3 var: "<< get_var(arr3,100) << '\n';
  // third array has higher variance because it has more outliers,
  // we want amore consistent variance thats lower, because we want all of our buckets to be used




  /// the size should decrease the collision rate but since our hash table is moding by just 100,
  /// because the hash function is too simple we are not decreasing collsion rate the bigger the table rate,
  /// our issue is the hash function is bad 

}