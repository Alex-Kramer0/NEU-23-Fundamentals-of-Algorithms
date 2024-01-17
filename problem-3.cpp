//  Alex Kramer - 002626673
//  EECE 7205
//  Homework 1 
//  Problem-3.cpp
//

#include <iostream>
#include <string>

using namespace std;

struct records{
    // Creates our new data type
    string name;
    int grade;
};

void flip(struct records *students, int j){
    // flips two students in list
    records temp = students[j];
    students[j] = students[j+1];
    students[j+1] = temp;
}

void sort_by_grade(struct records *students, int class_size){
    // sorts students by grade (lowest first, highest last)
    for (int i = 0; i < (class_size - 1); i++){
        for (int j = 0; j < (class_size - i - 1); j++){
            if (students[j].grade >= students[j+1].grade){
                flip(students, j);
            }  
        }  
    }
}

void calc_average(struct records *students, int class_size){
    // calculates the class average
    double total = 0.0;
    // adds all class grades up
    for (int i = 0; i < class_size; i++){
        total += students[i].grade; 
    }
    // divides total by class size to find the average
    total = (total / class_size);
    cout << "Class Average: " << total << "\n";
}

void calc_median(struct records *students, int class_size){
    // calculates the class median
    // sorts the records
    sort_by_grade(students, class_size);

    // find the mid point index
    int mid = (class_size / 2);


    if ((class_size % 2) == 0){
        // if the list is even 
        float avg = (students[mid].grade + students[mid - 1].grade) / 2;
        cout << "Class Median: " << avg << "\n";
    }
    else{
        // if the list is odd
        cout << "Class Median: " << students[mid- 1].grade << "\n";
    }

}

void top_students(struct records *students, int class_size){
    // prints the top two students

    // sorts the records
    sort_by_grade(students, class_size);
    int index = class_size;

    cout << "Top Two Students: \n";
    cout << "Names: " << students[index-1].name << "   " << students[index - 2].name << "\n";
    cout << "Grades: " << students[index-1].grade << "   " << students[index - 2].grade << "\n";
}

void bottom_students(struct records *students, int class_size){
    // prints the bottom two students

    // sorts the records
    sort_by_grade(students, class_size);
    int index = class_size;

    cout << "Bottom Two Students: \n";
    cout << "Names: " << students[0].name << "   " << students[1].name << "\n";
    cout << "Grades: " << students[0].grade << "   " << students[1].grade << "\n";
}


int main(){
    int class_size;
    
    cout<<"What is the class size? ";  
    cin>> class_size;  
    cout<<"\n";
    cout << "The class size is: " << class_size << "\n";

    // create class records DMA
    records* students = new records[class_size];

    for (int i = 0; i < class_size; i++){
        cout << "Enter the name of the student: ";
        cin >> students[i].name;

        cout << "Enter the grade of the student: ";
        cin >> students[i].grade;
    }

    cout << "Class Records: \n";
    for (int i = 0; i < class_size; i++){
        cout << "Name: " << students[i].name << ", Grade: " << students[i].grade << "\n";
    }
    
    calc_average(students, class_size);
    calc_median(students, class_size);
    
    top_students(students, class_size);
    bottom_students(students, class_size);


    cout << "Class Records Sorted: \n";
    for (int i = 0; i < class_size; i++){
        cout << "Name: " << students[i].name << ", Grade: " << students[i].grade << "\n";
    }
    delete[] students;

    return 0;
    
}