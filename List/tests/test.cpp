#include "gtest/gtest.h"
#include "Stud.h"

//Test of constructor using google tests
TEST(Student, Constructor) {
    vector<int> grades = { 5, 9, 10 };  
    Stud student("Ieva", "Prev", grades, 9);

    EXPECT_EQ(student.getName(), "Ieva");        
    EXPECT_EQ(student.getLastName(), "Prev");    
    EXPECT_EQ(student.ND, grades);  
    EXPECT_EQ(student.egz, 9);   
}
//Test of getters and setters for name and last name, using google tests
TEST(Student, GettersAndSetters) {

    Stud student;
    student.setName("Alice");
    student.setLastName("Smith");
    EXPECT_EQ(student.getName(), "Alice");
    EXPECT_EQ(student.getLastName(), "Smith");
}

//Test of the copy constructor, using google tests
TEST(Student, CopyConstructor) {
    vector<int> grades = { 5, 9, 10 };
    Stud obj1("Ieva", "Prev", grades, 9);
    Stud obj2(obj1);

    EXPECT_EQ(obj2.getName(), obj1.getName());
    EXPECT_EQ(obj2.getLastName(), obj1.getLastName());
    EXPECT_EQ(obj2.ND, obj1.ND);
    EXPECT_EQ(obj2.egz, obj1.egz);
    EXPECT_EQ(obj2.vid, obj1.vid);
    EXPECT_EQ(obj2.med, obj1.med);
}
