/*
 * You will slowly build up and test the implementations of the classes
 * described in include/uni/tripos.h
 *
 * You should try to make each function compile and work without errors during
 * execution, uncommenting more functions as you implement more functionality
 * from the tripos.h classes. You should add the function implementations in
 * src/tripos.cpp
 *
 * Your first task is to get main to compile and run with the code between the
 * "first part begin" and "first part end" markers uncommented.
 *
 * Afterwards, you need to uncomment the task_two() function and the section in
 * main between the next set of markers, and then get that to work.
 *
 * Finally, you uncomment the init_tripos() function and the call to it from
 * main, and at that point your implementation should be close to complete.
 *
 * However, the code in the functions you uncomment is not always fully
 * correct, and at each step you need to identify and fix any problems it might
 * have, and report (by adding a written comment) on why you have made the
 * changes. The main function itself should not be changed beyond the
 * uncommenting of sections until init_tripos() works correctly.
 */
#include "uni/tripos.h"
#include <chrono>
#include <iostream>
#include <memory>

using namespace uni;
using namespace std;

vector<Subject *> task_one() {
  vector<Subject *> subjects;

  Subject *ccds =
      new Subject("Concurrent and Distributed Systems", "David Greaves", 16, 4);
  Subject *cd = new Subject("Computer Design", "Simon Moore", 16, 5);
  Subject ds = Subject("Data Science", "Damon Wischik", 16, 4);
  Subject alg = Subject("Algorithms", "Frank Stajano", 24, 6);
  Subject bio = Subject("Bioinformatics", "Pietro Lio", 12, 3);

  subjects.push_back(ccds);
  subjects.push_back(cd);
  subjects.push_back(&ds);
  subjects.push_back(&alg);
  subjects.push_back(&bio);

  return subjects;
}

/* unique_ptr<Tripos> task_two(AcademicPlan*& IB) {
    auto subjects = task_one();
    auto tripos = unique_ptr<Tripos>{new Tripos()};
 
    AcademicPlan part_IA = AcademicPlan(1);
    AcademicPlan* part_IB = new AcademicPlan(2);
    IB = part_IB;
    AcademicPlan* part_II = new AcademicPlan(3);
    tripos->add_academic_plan(&part_IA);
    tripos->add_academic_plan(part_IB);
    tripos->add_academic_plan(part_II);
 
    return tripos;
  }  */

/* unique_ptr<Tripos> init_tripos() {
    auto tripos = unique_ptr<Tripos>{new Tripos()};
  
    Subject *ccds =
        new Subject("Concurrent and Distributed Systems", "David Greaves", 16, 4);
    Subject *cd = new Subject("Computer Design", "Simon Moore", 16, 5);
    Subject ds = Subject("Data Science", "Damon Wischik", 16, 4);
    Subject alg = Subject("Algorithms", "Frank Stajano", 24, 6);
    Subject bio = Subject("Bioinformatics", "Pietro Lio", 12, 3);
  
    AcademicPlan part_IA = AcademicPlan(1);
    AcademicPlan *part_IB = new AcademicPlan(2);
    AcademicPlan *part_II = new AcademicPlan(3);
    tripos->add_academic_plan(&part_IA);
    tripos->add_academic_plan(part_IB);
    tripos->add_academic_plan(part_II);
  
    part_IA.add_subject(alg);
    part_IB->add_subject(*ccds);
    part_IB->add_subject(*cd);
    part_IB->add_subject(ds);
    part_II->add_subject(bio);
  
    const chrono::time_point<chrono::system_clock> now =
        chrono::system_clock::now();
  
    Student s1 = Student("John Doe", 1);
    s1.add_supervision(alg, chrono::system_clock::to_time_t(now - 72h));
    s1.add_supervision(alg, chrono::system_clock::to_time_t(now - 360h));
    s1.add_supervision(alg, chrono::system_clock::to_time_t(now));
    Student s2 = Student("Jim Dole", 2);
    Student s3 = Student("Nim Sole", 3);
  
    tripos->add_student(s1);
    tripos->add_student(s2);
    tripos->add_student(s3);
  
    return tripos;
  } */

int main(int argc, char **argv) {
  // first part begin
  auto subjects = task_one();
  for (auto it = begin(subjects); it != end(subjects); ++it) {
    cout << (*it)->name << endl;
  }
  // first part end

  // second part begin
  /* AcademicPlan* second_year = NULL;
     auto tri_part = task_two(second_year);
     auto part_IB = tri_part->get_plan(2);
     if(part_IB == second_year) {
       cout<<"Success!"<<endl;
     } else {
       cout<<"Failure, you need to fix the program so that it prints
     Success!"<<endl;
     } 
  */
  // second part end

  // third part begin
  /* unique_ptr<Tripos> t = init_tripos(); */
  // third part end

  return 0;
}
