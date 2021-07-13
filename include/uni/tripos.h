/*
 * Some parts of this code are intentionally written with problems for
 * students to explore and correct as part of a supervision.
 */

#ifndef _UNI_H_
#define _UNI_H_

#include <chrono>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace uni {

enum struct DegreeClass { First, UpperSecond, LowerSecond, Third, Unclassed };

class Student;

struct Subject {
  std::string name;
  std::string lecturer;
  unsigned int nr_lectures;
  unsigned int needed_supervisions;

  Subject(std::string name, std::string lecturer, unsigned int nr_lectures,
          unsigned int needed_supervisions)
      : name(name), lecturer(lecturer), nr_lectures(nr_lectures),
        needed_supervisions(needed_supervisions){};
};

class AcademicPlan {
private:
  unsigned short int for_uni_year;
  std::vector<Subject> subjects;

public:
  AcademicPlan(unsigned short int year);
  void add_subject(Subject s);

  Subject get_subject(std::string name);
  const std::shared_ptr<Subject> &get_subject_ptr(std::string name);
};

class Tripos {
private:
  AcademicPlan *year_academic_plan[3];
  std::vector<Student> students;

public:
  Tripos();
  bool add_academic_plan(AcademicPlan* a);
  void add_student(Student s);

  AcademicPlan* get_plan(unsigned int year);
};

class Supervision {
private:
  std::time_t timestamp;
  std::optional<DegreeClass> eval;
  std::weak_ptr<Subject> subject;

public:
  Supervision(Subject &s,
              std::time_t start_time);
  void add_eval(DegreeClass eval);
};

class Student {
private:
  std::string name;
  unsigned short in_uni_year;
  DegreeClass year_degree_class[3];
  std::vector<Supervision> supervisions;
  std::map<int, unsigned short> year_subject_scores[3];

public:
  Student(std::string name, unsigned short in_year);
  void add_supervision(Subject &subj, std::time_t timestamp);
};

} // namespace uni

#endif
